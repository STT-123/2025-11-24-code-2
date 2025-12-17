#ifndef __UPDATE_FIRMWARE_H__
#define __UPDATE_FIRMWARE_H__
#include <zstd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <curl/curl.h>
#include <json-c/json.h>
#include <json-c/json_object.h>
#include <libwebsockets.h>
#include "message_queue.h"
#include "interface/log/log.h"

#define MAX_PATH_LENGTH 256
typedef enum
{
	Downloading,
    Downloaded,
    DownloadFailed,
    Installing,
    Installed,
    InstallFailed
} OCPP_Download_STATUS;


void* firmware_download_worker(void* arg);
const char* extract_after_xc(const char* url);
int download_file(const char *url,const char *filetype);
void handle_update_firmware(struct lws *wsi, json_object *json);
struct json_object *FirmwareStatusNotification(OCPP_Download_STATUS Status) ;
void handle_firmware_status_notification(struct lws *wsi, json_object *json);
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);
#endif