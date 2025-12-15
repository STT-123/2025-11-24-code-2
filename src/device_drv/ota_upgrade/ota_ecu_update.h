#ifndef __C_OTAAPPUPDATE_H
#define __C_OTAAPPUPDATE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include "device_drv/ota_upgrade/ota_fun.h"


/*==========================*/
#define BUF_SIZE 256

typedef struct {
    char section[64];
    int index;               // 从 upgradeX 提取的数字 X
    char old_version[32];
    char new_version[32];
    char upgrade_file[128];
    char md5sum[64];
} UpgradeInfo;
 typedef struct
 {
     unsigned int XCPCMDRpeatTimes;
     unsigned int xcpstatus;
     unsigned int XCPCMDOuttimeTime;
     unsigned int XCPCMDOuttimeTimes;
     unsigned char DeviceConnectedFlag;
     unsigned char XCPQUERYCMDResponseFlag;
     unsigned char DeviceCanProgramFlag;
     unsigned char XCPCMDResponseFlag;
     unsigned char DeviceProgramOkFlag;
     unsigned char CANStartOTA;
     unsigned int ErrorReg;
     unsigned int ErrorDeviceID;
 
 } ECUStatus;
 
extern ECUStatus ecustatus;
void ECU_OTA(void);
void FinshhECUOtaAndCleanup(void);

#endif