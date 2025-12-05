
#include "updownfile.h"
#include "./ocpp_app_update.h"
#include "interface/globalVariable.h"
#include "device_drv/sd_store/sd_store.h"
#include "interface/log/log.h"
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    FILE *fp = (FILE *)userp;
    size_t written = fwrite(contents, size, nmemb, fp);
    if (written != nmemb) {
        fprintf(stderr, "写入文件失败\n");
    }
    return realsize;
}

#define MAX_PATH_LENGTH 256
// 下载文件（支持HTTP/HTTPS和FTP）
// 参数: url - 文件下载地址
int download_file(const char *url,const char *filetype) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char download_filename[MAX_PATH_LENGTH];
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl init failed\n");
        return -1;
    }
    snprintf(download_filename, MAX_PATH_LENGTH, "%s/%s", USB_MOUNT_POINT, filetype);
    LOG("Download File...........: %s\n", download_filename);
    fp = fopen(download_filename, "wb");
    if (!fp) {
        fprintf(stderr, "can't open file %s\n", download_filename);
        curl_easy_cleanup(curl);
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 300L);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Download File Failed: %s\n", curl_easy_strerror(res));
        LOG("Download File Failed\r\n");
        fclose(fp);
        curl_easy_cleanup(curl);
        return -1;
    }

    fclose(fp);
    curl_easy_cleanup(curl);
    LOG("Download File. Success: %s\n", download_filename);
    // get_check_upgarde_file_type(DOWNLOAD_FILENAME,filetype);
    upgarde_file_type(download_filename,filetype);
    return 0;
}


/*
//这个也可以用，但是文件大了怕内存不够,采用下边方法流式传输
int ocpp_upload_file(const char *url) {
    CURL *curl;
    CURLcode res;
    FILE *hd_src;
    struct stat file_info;
    char *file_data = NULL;

    if (stat(UPLOAD_FILE_PATH, &file_info) != 0) {
        perror("stat failed");
        return -1;
    }

    hd_src = fopen(UPLOAD_FILE_PATH, "rb");
    if (!hd_src) {
        perror("fopen failed");
        return -2;
    }

    // 读取整个文件到内存中
    file_data = malloc(file_info.st_size);
    if (!file_data) {
        fclose(hd_src);
        return -3;
    }
    fread(file_data, 1, file_info.st_size, hd_src);
    fclose(hd_src);

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        free(file_data);
        return -4;
    }

    // 设置 POST 上传
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, file_data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)file_info.st_size);

    // 设置 HTTP 头
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // 设置超时
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60L);

    // 执行上传
    res = curl_easy_perform(curl);
    printf("\n");

    // 清理资源
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    free(file_data);

    if (res != CURLE_OK) {
        fprintf(stderr, "上传失败: %s\n", curl_easy_strerror(res));
        return -5;
    }

    printf("上传成功: %s\n", UPLOAD_FILE_PATH);
    return 0;
}*/


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
            printf("\r上传进度: %d%%", percent);
            fflush(stdout);
            last_percent = percent;
        }
    }
    return 0;  // 返回非0表示中断上传
}

int ocpp_upload_file(const char *url) {
    CURL *curl;
    CURLcode res;
    FILE *hd_src;
    struct stat file_info;

    // === 新增：删除已存在的压缩文件 ===
    if (access(UPLOAD_FILE_PATH, F_OK) == 0) {
        printf("删除旧的压缩文件: %s\n", UPLOAD_FILE_PATH);
        if (remove(UPLOAD_FILE_PATH) != 0) {
            perror("删除旧文件失败");
            // 可以继续尝试，不直接返回
        }
    }
    // int result = system("bzip2 -k app_project.log");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "bzip2 -k %s", LOG_FILE_PATH);
    int result = system(cmd);


    if (result == 0) {
        printf("Compression succeeded.\n");
    } else {
        printf("Compression failed.\n");
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
    // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);// 不验证证书
    // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);// 不验证主机名

    // 设置 HTTP Header
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // 打开进度显示
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, upload_progress_callback);

    // 设置超时
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60L);

    res = curl_easy_perform(curl);  // 执行curl操作（这会阻塞直到完成或超时）
    printf("\n");// 换行，因为进度显示用了\r

    // 清理资源
    curl_slist_free_all(headers); // 释放HTTP头
    curl_easy_cleanup(curl);// 清理curl句柄
    curl_global_cleanup();//全局清理
    fclose(hd_src);// 关闭文件

    if (res != CURLE_OK) {
        fprintf(stderr, "上传失败: %s\n", curl_easy_strerror(res));
        LOG("上传失败: %s\n", UPLOAD_FILE_PATH);
        return -4;
    }

    LOG("上传成功: %s\n", UPLOAD_FILE_PATH);
    return 0;
}
