#include "ws_client.h"
#include "message_queue.h"
#include <libwebsockets.h>
#include <string.h>
#include <unistd.h>
#include <json-c/json.h>
#include "ocpp_messages.h"
#include <stdio.h>
#include "project.h"
#include "interface/log/log.h"
#include <stdatomic.h>


static const char *ocpp_url = "wss://ocpp.xcharger.net:7274/ocpp";
static const char *ocpp_id = "C8A215DPWUDYDTAWLL";
// 保存当前连接 wsi
static struct lws *global_wsi = NULL;
static pthread_mutex_t wsi_lock = PTHREAD_MUTEX_INITIALIZER;
void handle_writeable(struct lws *wsi);

// 全局标志：0=未连接/失败，1=已连接
static _Atomic(conn_state_t) g_ocpp_conn_state = CONN_STATE_IDLE;

// 外部调用函数，请求触发写事件
void websocket_request_write(void)
{
    pthread_mutex_lock(&wsi_lock);
    if (global_wsi)
    {
        lws_callback_on_writable(global_wsi);
    }
    pthread_mutex_unlock(&wsi_lock);
}

static int callback_ws(struct lws *wsi, enum lws_callback_reasons reason,
                       void *user, void *in, size_t len)
{
    switch (reason)
    {
    case LWS_CALLBACK_CLIENT_ESTABLISHED:
        pthread_mutex_lock(&wsi_lock);
        global_wsi = wsi;
        pthread_mutex_unlock(&wsi_lock);
        lwsl_user("WebSocket connected\n");
        atomic_store(&g_ocpp_conn_state, CONN_STATE_CONNECTED);
        lws_callback_on_writable(wsi);
        break;
    case LWS_CALLBACK_CLIENT_WRITEABLE:
    {
        handle_writeable(wsi);
        break;
    }
    case LWS_CALLBACK_CLIENT_RECEIVE:
        // printf("Received: %.*s\n", (int)len, (char *)in);
        process_ocpp_message(wsi, (char *)in);
        break;
    case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
        if (in)
        {          
            lwsl_err("WebSocket connection error: %s\n", (char *)in);// 打印出连接错误的具体信息
        }
        else
        {
            lwsl_err("WebSocket connection error: Unknown error\n");
        }
        atomic_store(&g_ocpp_conn_state, CONN_STATE_FAILED);
        break;
    case LWS_CALLBACK_CLIENT_CLOSED:
        lwsl_err("WebSocket closed, reason: %s\n", in ? (char *)in : "Unknown reason");
        atomic_store(&g_ocpp_conn_state, CONN_STATE_FAILED);
        break;
    default:
        break;
    }
    return 0;
}

static struct lws_protocols protocols[] = {
    {"ocpp1.6", callback_ws, 0, 2048},
    {NULL, NULL, 0, 0}};

void *ocppCommunicationTask(void *arg)
{
    struct lws_context_creation_info info = {0};
    struct lws_context *context;

    info.port = CONTEXT_PORT_NO_LISTEN;// 不监听端口（客户端模式）
    info.protocols = protocols;// 注册协议处理
    info.options |= LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;// SSL 初始化


    context = lws_create_context(&info);// 创建 WebSocket 上下文
    printf("libwebsockets version: %s\n", lws_get_library_version());
    printf("json-c version: %s\n", JSON_C_VERSION);

    while (1)
    {
        struct lws_client_connect_info ccinfo = {0};
        ccinfo.context = context;

        ccinfo.address = "ocpp.xcharger.net";// 服务器地址localhost
        // ccinfo.address = "localhost";// 服务器地址

        ccinfo.port = 7274;// 服务器端口
        ccinfo.path = "/ocpp/C8A215DPWUDYDTAWLL";// OCPP 端点路径

        ccinfo.host = ccinfo.address;
        ccinfo.origin = ccinfo.address;
        ccinfo.protocol = protocols[0].name;// 使用 "ocpp1.6" 协议

        //启用 SSL/TLS 加密连接
        //允许接受自签名证书（self-signed certificate）
        //跳过对服务器证书中 Common Name (CN) 或 Subject Alternative Name (SAN) 的主机名验证
        //允许使用已过期的 SSL 证书
        //完全跳过 SSL 安全校验
        ccinfo.ssl_connection = LCCSCF_USE_SSL |
                                LCCSCF_ALLOW_SELFSIGNED |
                                LCCSCF_SKIP_SERVER_CERT_HOSTNAME_CHECK |
                                LCCSCF_ALLOW_EXPIRED |
                                LCCSCF_ALLOW_INSECURE; // LCCSCF_ALLOW_INSECURE 客户端跳过ssl校验.正是环境看看要不要把这些宽松的连接取消


        struct lws *wsi = lws_client_connect_via_info(&ccinfo);//建立连接
        if (!wsi)
        {
            LOG("[Ocpp]Connection failed. Retrying in 5 seconds...");
            sleep(5);
            continue;  //  关键：跳过 service 循环
        }

        // 等待结果（最多 15 秒，避免无限等待）
        atomic_store(&g_ocpp_conn_state, CONN_STATE_CONNECTING);
        bool connected = false;

        for (int i = 0; i < 15; i++) {
            if (lws_service(context, 1000) < 0) {
                atomic_store(&g_ocpp_conn_state, CONN_STATE_FAILED);
                break;
            }

            conn_state_t state = atomic_load(&g_ocpp_conn_state);
            if (state == CONN_STATE_CONNECTED) {
                connected = true;
                break;
            }
            if (state == CONN_STATE_FAILED) {
                break;
            }
            // 否则继续等待（状态仍是 CONNECTING）
        }

        if (!connected) {
            LOG("[Ocpp]Connection failed or timed out.");
            sleep(5);
            continue;
        }

        LOG("[Ocpp]Connected! Entering main communication loop.");

        // 主循环：只要连接未断开，就持续服务
        while (atomic_load(&g_ocpp_conn_state) == CONN_STATE_CONNECTED) {
            if (lws_service(context, 1000) < 0) {
                break;
            }
        }

        LOG("[Ocpp]Disconnected. Reconnecting in 5 seconds...");
        sleep(5);
    }

    lws_context_destroy(context);

    return NULL;
}

// 写状态保存结构（绑定到 user 或用静态变量）
typedef struct
{
    struct json_object *msg;
    const char *text;
    size_t total_len;
    size_t sent_pos;
} send_state_t;

static send_state_t send_state = {0}; // 线程安全时应加锁访问


void handle_writeable(struct lws *wsi)
{

    static unsigned char buf[LWS_PRE + 2048];

    if (!send_state.msg)
    {
        send_state.msg = dequeue_message();
        if (!send_state.msg)
        {            
            return;
        }
        // 尝试访问对象类型（安全操作）
        enum json_type type = json_object_get_type(send_state.msg);

#if (BUILD_X86)
        send_state.text = json_object_to_json_string(send_state.msg);
#else
        send_state.text = json_object_to_json_string_ext(send_state.msg, JSON_C_TO_STRING_NOSLASHESCAPE);
#endif
        send_state.total_len = strlen(send_state.text);
        send_state.sent_pos = 0;
    }
    size_t remaining = send_state.total_len - send_state.sent_pos;
    size_t chunk_size = remaining > 2048 ? 2048 : remaining;

    memcpy(&buf[LWS_PRE], send_state.text + send_state.sent_pos, chunk_size);

    int flags = 0;
    if (send_state.sent_pos == 0 && remaining > 2048)
    {
        flags = LWS_WRITE_TEXT | LWS_WRITE_NO_FIN; // 第一个帧，且不是最后
    }
    else if (remaining > 2048)
    {
        flags = LWS_WRITE_CONTINUATION | LWS_WRITE_NO_FIN; // 中间帧
    }
    else if (send_state.sent_pos == 0)
    {
        flags = LWS_WRITE_TEXT; // 一次发完（小消息）
    }
    else
    {
        flags = LWS_WRITE_CONTINUATION; // 最后一帧
    }

    int n = lws_write(wsi, &buf[LWS_PRE], chunk_size, flags);
    if (n < 0)
    {
        fprintf(stderr, "[ERROR] lws_write failed on msg=%p\n", (void*)send_state.msg);
        json_object_put(send_state.msg);
        memset(&send_state, 0, sizeof(send_state));
        return;
    }

    send_state.sent_pos += n;

    if (send_state.sent_pos < send_state.total_len)
    {
        lws_callback_on_writable(wsi);
        return;
    }

    // 完成发送
    json_object_put(send_state.msg);
    memset(&send_state, 0, sizeof(send_state));

    // 准备下一条
    // lws_callback_on_writable(wsi);
    //立即尝试取下一条消息，避免依赖外部触发
    struct json_object *next_msg = dequeue_message();
    if (next_msg) {
        send_state.msg = next_msg;
        // 重新进入发送流程（下一次 writable 回调会处理）
        lws_callback_on_writable(wsi);
    } else {
        // 队列空了，等待下次 enqueue 时由外部触发
        // 或者什么都不做
    }
}
