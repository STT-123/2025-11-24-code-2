#ifndef OCPP_MESSAGES_H
#define OCPP_MESSAGES_H
#include <json-c/json.h>
#include <zstd.h>
#include <libwebsockets.h>
#include "batdata.h"
#include "sqlite_storage.h"


typedef enum
{
	Uploading,
    Uploaded,
    UploadFailed
} OCPP_UPLOAD_STATUS;

typedef enum
{
	Downloading,
    Downloaded,
    DownloadFailed,
    Installing,
    Installed,
    InstallFailed
} OCPP_Download_STATUS;

#pragma pack(push, 1)
typedef struct {
    unsigned short usDataStyle;      /* 数据格式版本号（2字节），固定为1，用于指定后面数据的协议版本*/
    unsigned short usPackCount;      /* Pack数量（2字节），目前为15个Pack*/
    unsigned short usVoltCount;      /* 电池电压数量（2字节），目前为240个电池电压（15个Pack，每个16个）*/
    unsigned short usTempCount;      /* 电池温度数量（2字节），目前为120个采集点（15个Pack，每个8个）*/
    unsigned int   uiArrayLength;    /* 数组长度（4字节），最大255，无数据则为0*/
} tDetailHead;
#pragma pack(pop)

#define HEARTBEAT_ID                        "1915669379150258177"
#define BOOTNOTIFICATION_ID                 "1915669379150258176"
#define STATUSNOTIFICATION_ID               "1915669379150258178"
#define DIAGNOSTICSSTATUSNOTIFICATION_ID    "1915669379150258179"
#define FIRMWARESTATUSNOTIFICATION_ID       "1915669379150258180"

struct json_object *build_boot_notification();
struct json_object *build_heartbeat();
struct json_object *DiagnosticsStatusNotification(OCPP_UPLOAD_STATUS Status);
struct json_object *compress_detail_data(sqlite3 *db, int *out_ids, int *out_id_count);
struct json_object *FirmwareStatusNotification(OCPP_Download_STATUS Status) ;

int process_ocpp_message(struct lws *wsi, const char *message);
int send_ocpp_message(json_object *msg);
void handle_ChangeConfiguration(struct lws *wsi, json_object *json);

#endif