#include "get_diagnostics.h"
#include "interface/log/log.h"

int g_ocppupload_flag = 0;


struct json_object *DiagnosticsStatusNotification(OCPP_UPLOAD_STATUS Status){

    // 
    char DiagnosticsStatus[100];

    switch (Status)
    {
        case UploadFailed:
            strcpy(DiagnosticsStatus,"UploadFailed");
            break;
        case Uploaded:
            strcpy(DiagnosticsStatus,"Uploaded");
            break;
        case Uploading:
            strcpy(DiagnosticsStatus,"Uploading");
            break;
        default:
            break;
    }

    struct json_object *payload = json_object_new_object();
    json_object_object_add(payload, "status", json_object_new_string(DiagnosticsStatus)); // 通常 0 表示整机状态

    // 构建最外层的数组消息
    struct json_object *msg = json_object_new_array();
    json_object_array_add(msg, json_object_new_int(2));  // 消息类型 CALL = 2
    json_object_array_add(msg, json_object_new_string(DIAGNOSTICSSTATUSNOTIFICATION_ID)); // 消息 ID，应唯一
    json_object_array_add(msg, json_object_new_string("DiagnosticsStatusNotification"));
    json_object_array_add(msg, payload);  // 参数对象

    return msg;
}

// 处理诊断状态通知
void handle_diagnostics_status_notification(struct lws *wsi, json_object *json) {
    json_object *payload = json_object_array_get_idx(json, 3);
    json_object *status_obj = json_object_object_get(payload, "status");
    const char *status = json_object_get_string(status_obj);
    
    LOG("Received diagnostic status notification: %s\n", status);
    
    json_object *response = json_object_new_array();
    json_object_array_add(response, json_object_new_int(3));
    
    json_object *msg_id_obj = json_object_array_get_idx(json, 1);
    json_object_array_add(response, msg_id_obj);
    
    json_object *response_payload = json_object_new_object();
    json_object_array_add(response, response_payload);
    
    send_ocpp_message(response); /*消息队列存放json对象指针，发送后统一调用 json_object_put释放*/;
}

// 
static int upload_progress_callback(void *clientp,
                                    curl_off_t dltotal,
                                    curl_off_t dlnow,
                                    curl_off_t ultotal,
                                    curl_off_t ulnow) {
    static int last_percent = -1;
    if (ultotal > 0) {
        int percent = (int)(ulnow * 100 / ultotal);
        if (percent != last_percent) {
            printf("Upload progress: %d%%\r\n", percent);
            fflush(stdout);
            last_percent = percent;
        }
    }
    return 0;  // 返回非0表示中断上传
}
static size_t write_response(void *buffer, size_t size, size_t nmemb, void *userp) {
    size_t total = size * nmemb;
    printf("Server response : %.*s\n", (int)total, (char*)buffer);
    return total;
}

int ocpp_upload_file(const char *url) {
    CURL *curl;
    CURLcode res;
    FILE *hd_src;
    struct stat file_info;
    char error_buffer[CURL_ERROR_SIZE] = {0};  // 存储详细错误信息
    // === 新增：删除已存在的压缩文件 ===
    if (access(UPLOAD_FILE_PATH, F_OK) == 0) {
        LOG("Delete old compressed files: %s\n", UPLOAD_FILE_PATH);
        if (remove(UPLOAD_FILE_PATH) != 0) {
            LOG("Failed to delete old files\n");
        }
    }

    char cmd[256];
    snprintf(cmd, sizeof(cmd), "bzip2 -k %s", LOG_FILE_PATH);
    int result = system(cmd);


    if (result == 0) {
        LOG("Compression succeeded.\n");
    } else {
        LOG("Compression failed.\n");
        // 这里可以检查具体错误
        if (WIFEXITED(result)) {
            printf("压缩命令退出码: %d\n", WEXITSTATUS(result));
        }
    }

    if (stat(UPLOAD_FILE_PATH, &file_info) != 0) {
        perror("stat failed");
        return -1;
    }

    hd_src = fopen(UPLOAD_FILE_PATH, "rb");
    if (!hd_src) {
        perror("fopen failed");
        return -2;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        fclose(hd_src);
        return -3;
    }

    // 使用 POST 方法
    curl_easy_setopt(curl, CURLOPT_URL, url);//设置目标URL
    curl_easy_setopt(curl, CURLOPT_POST, 1L);  // 使用POST方法
    curl_easy_setopt(curl, CURLOPT_READDATA, hd_src);    // 设置要上传的文件
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)file_info.st_size);// 设置文件大小

    // 设置读取函数（可省略，使用默认 fread 即可）
    // curl_easy_setopt(curl, CURLOPT_READFUNCTION, my_read_callback);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);  // 启用详细输出

    // === 新增调试：设置HTTP响应回调 ===
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response);

    // 设置 HTTP Header
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // 打开进度显示
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, upload_progress_callback);

   
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 180); // 设置超时,60s不稳定

    LOG("Start uploading to: %s\n", url);
  
    res = curl_easy_perform(curl);  // 执行curl操作（这会阻塞直到完成或超时）

    LOG("\n");// 换行，因为进度显示用了\r

    // === 新增调试：获取HTTP状态码 ===
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    LOG("HTTP status code: %ld\n", http_code);

    // 清理资源
    curl_slist_free_all(headers); // 释放HTTP头
    curl_easy_cleanup(curl);// 清理curl句柄
    curl_global_cleanup();//全局清理
    fclose(hd_src);// 关闭文件

    if (res != CURLE_OK) {
        LOG("Upload failed! error code: %d\n", res);
        LOG("Error description: %s\n", curl_easy_strerror(res));
        if (strlen(error_buffer) > 0) {
            LOG("Detailed Error: %s\n", error_buffer);
        }
        LOG("file path: %s\n", UPLOAD_FILE_PATH);
        LOG("file size: %ld bytes\n", (long)file_info.st_size);
        LOG("Upload failed: %s\n", UPLOAD_FILE_PATH);
        return -4;
    }

    LOG("Upload success: %s\n", UPLOAD_FILE_PATH);
    return 0;
}

void* diagnostics_upload_worker(void* arg) {
    char *url = (char*)arg;
    g_ocppupload_flag = 1;
    int success = ocpp_upload_file(url); // 阻塞上传
    g_ocppupload_flag = 0;
    sleep(1);
    if(0 == success)
    {
        if (remove(UPLOAD_FILE_PATH) == 0) {
            LOG("file  %s delete success\n", UPLOAD_FILE_PATH);
        } else {
            perror("Failed to delete file");
        }
        send_ocpp_message(DiagnosticsStatusNotification(Uploaded));
    }
    else{
        send_ocpp_message(DiagnosticsStatusNotification(UploadFailed));
    }
    free(url);
    return NULL;
}
// 处理获取诊断信息请求
void handle_get_diagnostics(struct lws *wsi, json_object *json) {

    if (!json_object_is_type(json, json_type_array)) {
        printf("Invalid message: not a JSON array.\n");
        return;
    }

    json_object *msg_id = json_object_array_get_idx(json, 1);
    json_object *payload = json_object_array_get_idx(json, 3);

    if (!msg_id || !json_object_is_type(msg_id, json_type_string) ||
        !payload || !json_object_is_type(payload, json_type_object)) {
        printf("Invalid GetDiagnostics message structure.\n");
        return;
    }

    const char *message_id = json_object_get_string(msg_id);

    // Step 1: 立即发送 CALLRESULT 响应
    json_object *ack = json_object_new_array();
    json_object_array_add(ack, json_object_new_int(3));  // CALLRESULT
    json_object_array_add(ack, json_object_new_string(message_id));
    
    // payload: 可返回 fileName（选填），我们这里返回固定 diagnostic-id
    json_object *ack_payload = json_object_new_object();
    json_object_object_add(ack_payload, "fileName", json_object_new_string("app_project.log.bz2"));
    json_object_array_add(ack, ack_payload);

    send_ocpp_message(ack);

    // Step 2: 获取 location 字段
    json_object *location_obj = NULL;
    json_object_object_get_ex(payload, "location", &location_obj);

    if (!location_obj || !json_object_is_type(location_obj, json_type_string)) {
        printf("No valid location provided in GetDiagnostics.\n");
        return;
    }

    const char *upload_url = json_object_get_string(location_obj);

    // Step 2: 启动异步上传（不要阻塞！）
    char *url_copy = strdup(upload_url); // 避免悬空指针
    pthread_t tid;
    if (pthread_create(&tid, NULL, diagnostics_upload_worker, url_copy) == 0) {
        pthread_detach(tid);
    } else {
        perror("Failed to start upload thread");
        send_ocpp_message(DiagnosticsStatusNotification(UploadFailed));
        free(url_copy);
    }

}