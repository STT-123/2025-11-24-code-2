#include "ota_fun.h"

OTAObject g_otactrl ={0};
// 互斥锁保护非原子变量
pthread_mutex_t ota_mutex = PTHREAD_MUTEX_INITIALIZER;//多读一写适合读写锁

 unsigned int get_ota_deviceID(void) {
    return atomic_load(&g_otactrl.deviceID);
}

 void set_ota_deviceID(unsigned int value) {
    atomic_store(&g_otactrl.deviceID, value);
}

 unsigned char get_ota_deviceType(void) {
    return atomic_load(&g_otactrl.deviceType);
}

 void set_ota_deviceType(unsigned char value) {
    atomic_store(&g_otactrl.deviceType, value);
}

 unsigned char get_ota_OTAStart(void) {
    return atomic_load(&g_otactrl.OTAStart);
}

 void set_ota_OTAStart(unsigned char value) {
    atomic_store(&g_otactrl.OTAStart, value);
}

 unsigned char get_ota_multDeviceOTA(void) {
    return atomic_load(&g_otactrl.multDeviceOTA);
}

 void set_ota_multDeviceOTA(unsigned char value) {
    atomic_store(&g_otactrl.multDeviceOTA, value);
}

 unsigned char get_ota_multDeviceOTANum(void) {
    return atomic_load(&g_otactrl.multDeviceOTANum);
}

 void set_ota_multDeviceOTANum(unsigned char value) {
    atomic_store(&g_otactrl.multDeviceOTANum, value);
}

 unsigned char get_ota_UpDating(void) {
    return atomic_load(&g_otactrl.UpDating);
}

 void set_ota_UpDating(unsigned char value) {
    atomic_store(&g_otactrl.UpDating, value);
}

inline unsigned char get_ota_OTAFileType(void) {
    return atomic_load(&g_otactrl.OTAFileType);
}

inline void set_ota_OTAFileType(unsigned char value) {
    atomic_store(&g_otactrl.OTAFileType, value);
}

// ============ 非原子变量的 get/set 函数实现 ============

 const char* get_ota_OTAFilename(void) {
    pthread_mutex_lock(&ota_mutex);
    const char* result = g_otactrl.OTAFilename;
    pthread_mutex_unlock(&ota_mutex);
    return result;
}

 void set_ota_OTAFilename(const char* filename) {
    pthread_mutex_lock(&ota_mutex);
    if (filename) {
        strncpy(g_otactrl.OTAFilename, filename, OTAFILENAMEMAXLENGTH - 1);
        g_otactrl.OTAFilename[OTAFILENAMEMAXLENGTH - 1] = '\0';
    } else {
        g_otactrl.OTAFilename[0] = '\0';
    }
    pthread_mutex_unlock(&ota_mutex);
}

 const char* get_ota_OTAUdsSblFilename(int index) {
    pthread_mutex_lock(&ota_mutex);
    const char* result = NULL;
    if (index >= 0 && index < MAX_FILE_COUNT) {
        result = g_otactrl.OTAUdsSblFilename[index];
    }
    pthread_mutex_unlock(&ota_mutex);
    return result;
}

 void set_ota_OTAUdsSblFilename(int index, const char* filename) {
    pthread_mutex_lock(&ota_mutex);
    if (index >= 0 && index < MAX_FILE_COUNT && filename) {
        strncpy(g_otactrl.OTAUdsSblFilename[index], filename, OTAFILENAMEMAXLENGTH - 1);
        g_otactrl.OTAUdsSblFilename[index][OTAFILENAMEMAXLENGTH - 1] = '\0';
    }
    pthread_mutex_unlock(&ota_mutex);
}

 const char* get_ota_OTAUdsFilename(int index) {
    pthread_mutex_lock(&ota_mutex);
    const char* result = NULL;
    if (index >= 0 && index < MAX_FILE_COUNT) {
        result = g_otactrl.OTAUdsFilename[index];
    }
    pthread_mutex_unlock(&ota_mutex);
    return result;
}

 void set_ota_OTAUdsFilename(int index, const char* filename) {
    pthread_mutex_lock(&ota_mutex);
    if (index >= 0 && index < MAX_FILE_COUNT && filename) {
        strncpy(g_otactrl.OTAUdsFilename[index], filename, OTAFILENAMEMAXLENGTH - 1);
        g_otactrl.OTAUdsFilename[index][OTAFILENAMEMAXLENGTH - 1] = '\0';
    }
    pthread_mutex_unlock(&ota_mutex);
}
