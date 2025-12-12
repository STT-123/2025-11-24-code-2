
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdatomic.h>
#include <json-c/json.h>
#include <libwebsockets.h>

#include "project.h"
#include "ws_client.h"
#include "message_queue.h"
#include "ocpp_messages.h"
#include "interface/log/log.h"
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"

static const char *ocpp_url = "wss://ocpp.xcharger.net:7274/ocpp";
static const char *ocpp_id = "C8A215DPWUDYDTAWLL";
// 保存当前连接 wsi
static struct lws *global_wsi = NULL;
static pthread_mutex_t wsi_lock = PTHREAD_MUTEX_INITIALIZER;
void handle_writeable(struct lws *wsi);
int g_curl_running = 0;//数据上传可写入标志位，避免一直给消息队列写数据

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
        lws_callback_on_writable(wsi);
        break;
    case LWS_CALLBACK_CLIENT_WRITEABLE:
    {
        handle_writeable(wsi);
        break;
    }
    case LWS_CALLBACK_CLIENT_RECEIVE:
        printf("Received: %.*s\n", (int)len, (char *)in);
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
        LOG("[Ocpp]Connection  LWS_CALLBACK_CLIENT_CONNECTION_ERROR");
        break;
    case LWS_CALLBACK_CLIENT_CLOSED:
        lwsl_err("WebSocket closed, reason: %s\n", in ? (char *)in : "Unknown reason");
        LOG("[Ocpp]Connection  LWS_CALLBACK_CLIENT_CLOSED");
        break;
    default:
        break;
    }
    return 0;
}

static struct lws_protocols protocols[] = {
    {"ocpp1.6", callback_ws, 0, 2048},
    {NULL, NULL, 0, 0}};

void update_bat_data(sqlite3 *db)
{
    tBatData data = {0};
    tBatData data_be = {0};
    uint16_t DAq_version[15] = {0};

    data.usAirState =1;

    for(int i = 0; i < 15; i++){
        get_modbus_reg_val(0x5000 +i, &DAq_version[i]);
    }

    memcpy(data.usSingleBatVal, get_BCU_usSingleBatVal(), sizeof(data.usSingleBatVal));
    memcpy(data.usSingleBatTemp, get_BCU_usSingleBatTemp(), sizeof(data.usSingleBatTemp));

    for(int i = 0; i < 15; i++)
    {
        if(DAq_version[i] != 0)
        {
            uint32_T* p_o1 = &CANRcvFcn_BMU_B.ux180110E16_o1 + (i * 2);      // 每次跳过2个uint32_T
            uint32_T* p_o2 = &CANRcvFcn_BMU_B.ux180110E16_o2 + (i * 2);      // 每次跳过2个uint32_T
        
            data.uiBmuErrorNum[i] = *p_o1;
            data.uiBmuExErrorNum[i] = *p_o2;
        }else{
            data.uiBmuErrorNum[i] = 65535;
            data.uiBmuExErrorNum[i] = 65535;
        }
    }

    data.uiTimeStamp = (unsigned int)time(NULL);
    convert_tBatData_to_big_endian(&data_be, &data);
    insert_data(db, &data_be);
}

/*
*websocket_send_thread 线程
*该线程专门用来给ocpp服务端发送数据
*心跳、电池数据等
*/
void *websocket_send_thread(void *arg)
{
    int counter = 60;
    sqlite3 *db =NULL;
    int ret = init_db(&db);
    if (ret <= 0) {
        LOG("[Ocpp]init db error");
        return NULL;
    }
    LOG("[Ocpp] Database initialized successfully");

    send_ocpp_message(build_boot_notification());

    while(1)
    {
        sleep(1);

        if(g_curl_running == 0){
            // 每1秒发送心跳
            send_ocpp_message(build_heartbeat());

            update_bat_data(db); // 更新电池数据
            printf("counter =%d...\n", counter);
            if (++counter >= 10) {
                counter = 0;
                int ids[REPORT_COUNT];
                int count = 0;

                send_ocpp_message(compress_detail_data(db, ids, &count));
                //调试用的
                struct json_object *json = compress_detail_data(db, ids, &count);
                if (json) {
                    if (send_ocpp_message(json)) {
                        delete_data_by_ids(db, ids, count);
                    }
                }
            
            }
        }
        
    }
    // 清理（虽然这个代码可能永远不会执行）
    if (db) {
        sqlite3_close(db);
    }
    return NULL;

}
void *ocppCommunicationTask(void *arg)
{
    struct lws_context_creation_info info = {0};
    struct lws_context *context;
    int connection_timeout = 30;  // 连接超时30秒
    int reconnect_delay = 5;      // 重连等待5秒


    info.port = CONTEXT_PORT_NO_LISTEN;// 不监听端口（客户端模式）
    info.protocols = protocols;// 注册协议处理
    info.options |= LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;// SSL 初始化


    context = lws_create_context(&info);// 创建 WebSocket 上下文
    printf("libwebsockets version: %s\n", lws_get_library_version());
    printf("json-c version: %s\n", JSON_C_VERSION);

    pthread_t ws_send_thread;
    pthread_create(&ws_send_thread, NULL, websocket_send_thread, NULL);    //新建一个线程专门发数据

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
        if (!wsi) {
            fprintf(stderr, "WebSocket connection failed, retrying...\n");
        }


        int connected = 0;
        time_t connect_start = time(NULL);
        // 有限次数的服务循环，避免无限阻塞
        for (int i = 0; i < connection_timeout * 10; i++) {  // 每秒10次检查
            lws_service(context, 100);  // 100ms超时
            
            // 检查是否连接成功
            pthread_mutex_lock(&wsi_lock);
            if (global_wsi != NULL) {
                connected = 1;
            }
            pthread_mutex_unlock(&wsi_lock);
            
            if (connected) {
                LOG("[Ocpp] WebSocket connected successfully\n");
                break;
            }
            
            // 检查是否超时
            if (time(NULL) - connect_start > connection_timeout) {
                LOG("[Ocpp] Connection timeout after %d seconds\n", connection_timeout);
                break;
            }
        }

        if (!connected) {
            LOG("[Ocpp] Connection failed or timeout, cleaning up...\n");
            // 强制关闭连接
            if (wsi) {
                lws_close_reason(wsi, LWS_CLOSE_STATUS_NOSTATUS, NULL, 0);
            }
            
            LOG("[Ocpp] Will retry in %d seconds...\n", reconnect_delay);
            sleep(reconnect_delay);
            continue;
        }
        int loop_count = 0;
        // 连接成功，进入正常服务循环
        LOG("[Ocpp] Entering main service loop\n");
        while (1) {
            int ret = lws_service(context, 1000);
            
            // 检查连接是否仍然有效
            pthread_mutex_lock(&wsi_lock);
            int still_connected = (global_wsi != NULL);
            pthread_mutex_unlock(&wsi_lock);
            
            if (!still_connected) {
                LOG("[Ocpp] Connection lost, will reconnect\n");
                break;
            }
            
            if (ret < 0) {
                LOG("[Ocpp] lws_service returned error: %d\n", ret);
                break;
            }

            // 每隔10秒打印一次保持活动的状态
            loop_count++;
            if (loop_count % 10 == 0) {
                LOG("[Ocpp] Main service loop still running...\n");
            }
        }
        sleep(reconnect_delay);
        // while (lws_service(context, 1000) >= 0);
        // LOG("[Ocpp] Reconnection\r\n");
        // sleep(5); // 自动重连等待
    }

    lws_context_destroy(context);
    pthread_join(ws_send_thread, NULL);
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

    printf("send: %s\n", send_state.text);
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
