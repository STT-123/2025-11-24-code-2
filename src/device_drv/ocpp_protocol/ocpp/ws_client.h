#ifndef WS_CLIENT_H
#define WS_CLIENT_H

typedef enum {
    CONN_STATE_IDLE = 0,      // 初始状态
    CONN_STATE_CONNECTING,    // 正在连接
    CONN_STATE_CONNECTED,     // 成功
    CONN_STATE_FAILED         // 明确失败
} conn_state_t;


void *ocppCommunicationTask(void *arg);

// 外部请求 WebSocket 可写
void websocket_request_write(void);
#endif