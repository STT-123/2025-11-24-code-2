#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H
#include <stdbool.h>
#include <json-c/json.h>


#define MAX_JSON_SIZE (100 * 1024)  // 100KB限制
void websocket_request_write(void);
bool enqueue_message(struct json_object *msg);
struct json_object *dequeue_message();

#endif