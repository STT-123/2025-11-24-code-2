#ifndef __OCPP_COMMUNICATION_TASK_H__
#define __OCPP_COMMUNICATION_TASK_H__ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <libwebsockets.h>
#include <time.h>
#include <stdatomic.h>
#include <json-c/json.h>
#include "interface/log/log.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "device_drv/ocpp_protocol/ocpp_send/ocpp_send.h"
#include "device_drv/ocpp_protocol/ocpp_message/message_queue.h"
#include "device_drv/ocpp_protocol/ocpp_message/ocpp_messages.h"

// 写状态保存结构（绑定到 user 或用静态变量）
typedef struct
{
    struct json_object *msg;
    const char *text;
    size_t total_len;
    size_t sent_pos;
} send_state_t;


static void handle_writeable(struct lws *wsi);
static int callback_ws(struct lws *wsi, enum lws_callback_reasons reason,void *user, void *in, size_t len);
void *ocppCommunicationTask(void *arg);
void ocppCommunicationTaskCreate(void);
#endif