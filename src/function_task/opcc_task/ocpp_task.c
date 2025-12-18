#include "ocpp_task.h"
#include <pthread.h>


pthread_t ws_thread = 0;
static const char *ocpp_url = "wss://ocpp.xcharger.net:7274/ocpp";
static const char *ocpp_id = "C8A215DPWUDYDTAWLL";
static send_state_t send_state = {0}; // 线程安全时应加锁访问
static struct lws_protocols protocols[] = {
    {"ocpp1.6", callback_ws, 0, 2048},
    {NULL, NULL, 0, 0}
};

extern struct lws *global_wsi ;
extern pthread_mutex_t wsi_lock;

volatile int send_thread_should_run = 1;
volatile int connection_is_active = 0;

static void handle_writeable(struct lws *wsi)
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

    // printf("send: %s\n", send_state.text);
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
        handle_writeable(wsi);
        break;
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
        pthread_mutex_lock(&wsi_lock);
        if (global_wsi == wsi) {
            global_wsi = NULL;
        }
        pthread_mutex_unlock(&wsi_lock);
        LOG("[Ocpp]Connection  LWS_CALLBACK_CLIENT_CONNECTION_ERROR");
        break;
    case LWS_CALLBACK_CLIENT_CLOSED:
        lwsl_err("WebSocket closed, reason: %s\n", in ? (char *)in : "Unknown reason");
        LOG("[Ocpp]Connection  LWS_CALLBACK_CLIENT_CLOSED");
        pthread_mutex_lock(&wsi_lock);
        if (global_wsi == wsi) {
            global_wsi = NULL;
        }
        pthread_mutex_unlock(&wsi_lock);
        break;
    default:
        break;
    }
    return 0;
}
#if 0
void *ocppCommunicationTask(void *arg)
{
    LOG("[Ocpp] OCPP communication task started\n");
    
    int connection_timeout = 30;      // 连接超时30秒
    int reconnect_delay = 5;          // 重连等待5秒
    pthread_t ws_send_thread = 0;
    int send_thread_running = 0;
    struct lws_context *context = NULL;
    struct lws_context_creation_info info = {0}; 

    info.port = CONTEXT_PORT_NO_LISTEN;
    info.protocols = protocols;
    info.options |= LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT; 
    context = lws_create_context(&info);

    pthread_create(&ws_send_thread, NULL, websocket_send_thread, context);
            
    while (1) 
    { 
        struct lws_client_connect_info ccinfo = {0};
        ccinfo.context = context;

        ccinfo.address = "ocpp.xcharger.net";
        ccinfo.port = 7274;
        ccinfo.path = "/ocpp/C8A215DPWUDYDTAWLL";

        ccinfo.host = ccinfo.address;
        ccinfo.origin = ccinfo.address;
        ccinfo.protocol = protocols[0].name;

        ccinfo.ssl_connection = LCCSCF_USE_SSL |
                        LCCSCF_ALLOW_SELFSIGNED |
                        LCCSCF_SKIP_SERVER_CERT_HOSTNAME_CHECK |
                        LCCSCF_ALLOW_EXPIRED|
                        LCCSCF_ALLOW_INSECURE;    //LCCSCF_ALLOW_INSECURE 客户端跳过ssl校验

        struct lws *wsi = lws_client_connect_via_info(&ccinfo);
        if (!wsi) {
            fprintf(stderr, "WebSocket connection failed, retrying...\n");
        }

        while (lws_service(context, 1000) >= 0);

        sleep(5); // 自动重连等待
    }

    lws_context_destroy(context);
    return NULL;
}
#else
void *ocppCommunicationTask(void *arg)
{
    LOG("[Ocpp] OCPP communication task started\n");
    
    int connection_timeout = 30;      // 连接超时30秒
    int reconnect_delay = 5;          // 重连等待5秒
    pthread_t ws_send_thread = 0;
    int send_thread_running = 0;
    struct lws_context *context = NULL;
    
    // 无限重试循环
    while (1) 
    {
        LOG("[Ocpp] Starting new connection cycle\n");
        
        // 1. 创建 WebSocket 上下文
        struct lws_context_creation_info info = {0};
        info.port = CONTEXT_PORT_NO_LISTEN;
        info.protocols = protocols;
        info.options = LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;
        info.timeout_secs = 10;
        info.keepalive_timeout = 5;
        
        context = lws_create_context(&info);
        if (!context) {
            LOG("[Ocpp] Failed to create WebSocket context\n");
            sleep(reconnect_delay);
            continue;
        }
        
        LOG("libwebsockets version: %s\n", lws_get_library_version());
        LOG("json-c version: %s\n", JSON_C_VERSION);
        
        // 2. 启动发送线程（如果还没启动）
        if (!send_thread_running) {
            send_thread_should_run = 1;
            if (pthread_create(&ws_send_thread, NULL, websocket_send_thread, context) == 0) {
                send_thread_running = 1;
                LOG("[Ocpp] Send thread created successfully\n");
            } else {
                LOG("[Ocpp] Failed to create send thread\n");
                lws_context_destroy(context);
                sleep(reconnect_delay);
                continue;
            }
        }
        
        // 3. 连接尝试循环
        int connection_attempt = 0;
        int max_attempts = 3;
        
        while (connection_attempt < max_attempts) 
        {
            connection_attempt++;
            LOG("[Ocpp] Connection attempt %d/%d\n", connection_attempt, max_attempts);
            
            // 建立连接
            struct lws_client_connect_info ccinfo = {0};
            ccinfo.context = context;
            ccinfo.address = "ocpp.xcharger.net";
            ccinfo.port = 7274;
            ccinfo.path = "/ocpp/C8A215DPWUDYDTAWLL";
            ccinfo.host = ccinfo.address;
            ccinfo.origin = ccinfo.address;
            ccinfo.protocol = protocols[0].name;
            ccinfo.ssl_connection = LCCSCF_USE_SSL |
                                    LCCSCF_ALLOW_SELFSIGNED |
                                    LCCSCF_SKIP_SERVER_CERT_HOSTNAME_CHECK |
                                    LCCSCF_ALLOW_EXPIRED |
                                    LCCSCF_ALLOW_INSECURE;
            
            struct lws *wsi = lws_client_connect_via_info(&ccinfo);
            if (!wsi) {
                LOG("[Ocpp] WebSocket connection failed\n");
                sleep(reconnect_delay);
                continue;
            }
            
            // 4. 等待连接建立
            int connected = 0;
            time_t connect_start = time(NULL);
            
            for (int i = 0; i < connection_timeout * 10; i++) 
            {
                lws_service(context, 100);  // 100ms超时
                
                pthread_mutex_lock(&wsi_lock);
                connected = (global_wsi != NULL);
                pthread_mutex_unlock(&wsi_lock);
                
                if (connected) {
                    LOG("[Ocpp] WebSocket connected successfully\n");
                    connection_is_active = 1;  // 通知发送线程
                    break;
                }
                
                if (time(NULL) - connect_start > connection_timeout) {
                    LOG("[Ocpp] Connection timeout after %d seconds\n", connection_timeout);
                    break;
                }
            }
            
            // 5. 处理连接结果
            if (!connected) 
            {
                LOG("[Ocpp] Connection failed\n");
                
                // 清理引用
                pthread_mutex_lock(&wsi_lock);
                if (global_wsi != NULL) {
                    global_wsi = NULL;
                }
                pthread_mutex_unlock(&wsi_lock);
                
                connection_is_active = 0;  // 通知发送线程
                sleep(reconnect_delay);
                continue;  // 尝试下一次连接
            }
            
            // 6. 连接成功，进入服务循环
            LOG("[Ocpp] Entering main service loop\n");
            int loop_count = 0;
            
            while (1) 
            {
                int ret = lws_service(context, 1000);  // 1秒超时
                
                // 检查连接状态
                pthread_mutex_lock(&wsi_lock);
                int still_connected = (global_wsi != NULL);
                pthread_mutex_unlock(&wsi_lock);
                
                if (!still_connected) {
                    LOG("[Ocpp] Connection lost in service loop\n");
                    connection_is_active = 0;  // 通知发送线程
                    break;
                }
                
                if (ret < 0) {
                    LOG("[Ocpp] lws_service returned error: %d\n", ret);
                    connection_is_active = 0;
                    break;
                }
                
                // 心跳日志
                loop_count++;
                if (loop_count % 30 == 0) {  // 每30秒
                    LOG("[Ocpp] Service loop active (30s)\n");
                }
            }
            
            // 7. 连接断开，准备重连
            LOG("[Ocpp] Preparing to reconnect...\n");
            
            // 清理引用
            pthread_mutex_lock(&wsi_lock);
            global_wsi = NULL;
            pthread_mutex_unlock(&wsi_lock);
            
            connection_is_active = 0;
            sleep(reconnect_delay);
            
            // 跳出内层循环，重新连接
            break;
        }
        
        // 8. 清理当前上下文
        LOG("[Ocpp] Cleaning up WebSocket context\n");
        if (context) {
            lws_context_destroy(context);
            context = NULL;
        }
        
        // 9. 如果连接尝试失败，暂停发送线程
        if (connection_attempt >= max_attempts) {
            LOG("[Ocpp] Max connection attempts reached, pausing send thread\n");
            connection_is_active = 0;
            
            // 短暂停止发送线程
            int pause_time = reconnect_delay * 2;
            LOG("[Ocpp] Pausing for %d seconds before retry\n", pause_time);
            sleep(pause_time);
        }
        
        LOG("[Ocpp] Connection cycle complete\n");
    }
    
    // 清理（理论上不会执行到这里）
    LOG("[Ocpp] Cleaning up before exit\n");
    
    // 停止发送线程
    send_thread_should_run = 0;
    if (send_thread_running) {
        pthread_join(ws_send_thread, NULL);
        LOG("[Ocpp] Send thread joined\n");
    }
    
    if (context) {
        lws_context_destroy(context);
    }
    
    return NULL;
}
#endif
void ocppCommunicationTaskCreate(void)
{
    int ret;
    do {
        ret = pthread_create(&ws_thread, NULL, ocppCommunicationTask, NULL);
        if (ret != 0) {
            LOG("[Ocpp] Failed to create ocppCommunicationTask : %s",strerror(ret));
            sleep(1); 
        }
        else
        {
            LOG("[Ocpp] ocppCommunicationTask created successfully.\r\n");
        }
    } while (ret != 0);
}