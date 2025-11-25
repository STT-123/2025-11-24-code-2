#ifndef _OTA_FUN_H
#define _OTA_FUN_H 
#include <string.h>
#include <pthread.h>
#include "interface/globalVariable.h"


 #define XMODEMISTTRANFERINGFILE 0x0001  // XMODEM正在传输文件
#define XMODEMNORMALTERMINATION 0x0002  // XMODEM正常终止（传输成功）
#define XMODEMOUTTIMETERMINATION 0x0004 // XMODEM超时终止
#define XMODEMABORTTERMINATION 0x0006   // XMODEM异常中止
//以上4个未使用
#define FILEISDECRYPTIIONING 0x0008		// 文件正在解密中
#define FILEDECRYPTIONNORMALTERMINATION 0x0010  // 文件解密正常完成

#define OTASTARTRUNNING 0x0080 		// OTA开始运行
#define OTAIDLE 0x0000				// OTA空闲状态
#define OTASUCCESS 0x0100			// OTA升级成功
#define OTAFAILED 0x0200			// OTA升级失败

#define OTAFILENAMEMAXLENGTH 128
#define MAX_FILE_COUNT 20

typedef enum
{
	ECU = 1,
	BCU,
	BMU,
	AC,
	ACP,
	DCDC
} OTADEVICETYPE;


typedef struct
{
	_Atomic unsigned char OTAFileType;
	char OTAFilename[OTAFILENAMEMAXLENGTH];//其他ota文件名
	char OTAUdsSblFilename[MAX_FILE_COUNT][OTAFILENAMEMAXLENGTH];//专门给AC使用的
	char OTAUdsFilename[MAX_FILE_COUNT][OTAFILENAMEMAXLENGTH];//专门给AC使用的
	_Atomic unsigned int deviceID;//原子操作
	_Atomic unsigned char deviceType;
	_Atomic unsigned char OTAStart;
	_Atomic unsigned char multDeviceOTA;
	_Atomic unsigned char multDeviceOTANum;
	_Atomic unsigned char UpDating;
} OTAObject;

extern OTAObject g_otactrl;

// ============ 原子变量的 get/set 函数实现 ============

// deviceID 操作
 unsigned int get_ota_deviceID(void);
 void set_ota_deviceID(unsigned int value);

// deviceType 操作  
 unsigned char get_ota_deviceType(void);
 void set_ota_deviceType(unsigned char value);

// OTAStart 操作
 unsigned char get_ota_OTAStart(void);
 void set_ota_OTAStart(unsigned char value);

// multDeviceOTA 操作
 unsigned char get_ota_multDeviceOTA(void);
 void set_ota_multDeviceOTA(unsigned char value);

// multDeviceOTANum 操作
 unsigned char get_ota_multDeviceOTANum(void);
 void set_ota_multDeviceOTANum(unsigned char value);

// UpDating 操作
 unsigned char get_ota_UpDating(void);
 void set_ota_UpDating(unsigned char value);

// OTAFileType 操作
 unsigned char get_ota_UpDating(void);
 void set_ota_UpDating(unsigned char value);

// OTAFileType 操作
 unsigned char get_ota_OTAFileType(void);
 void set_ota_OTAFileType(unsigned char value);

// ============ 非原子变量的 get/set 函数 ============
// OTAFilename 操作
 const char* get_ota_OTAFilename(void);
 void set_ota_OTAFilename(const char* filename);

// OTAUdsSblFilename 操作
 const char* get_ota_OTAUdsSblFilename(int index);
 void set_ota_OTAUdsSblFilename(int index, const char* filename);

// OTAUdsFilename 操作
 const char* get_ota_OTAUdsFilename(int index);
 void set_ota_OTAUdsFilename(int index, const char* filename);

#endif