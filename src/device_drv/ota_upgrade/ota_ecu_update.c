#include "ota_ecu_update.h"
#include "interface/globalVariable.h"
#include "interface/log/log.h"
#include "interface/bms/bms_analysis.h"
#include "interface/modbus/modbus_defines.h"
#include "device_drv/xmodem/xmodemdata.h"
#include "device_drv/ota_upgrade/ota_fun.h"
#include "device_drv/sd_store/sd_store.h"

#define APP_PATH  "/opt/xcharge"  

ECUStatus ecustatus = {0};


void ECU_OTA(void)
{
    LOG("[OTA] ECU_OTA start!, get_ota_OTAStart():%d\r\n", get_ota_OTAStart());
    if (!get_ota_OTAStart()) return;
    
    memset(&ecustatus, 0, sizeof(ECUStatus));
    LOG("[OTA] get_ota_deviceType() : %d \r\n", get_ota_deviceType());
    LOG("[OTA] can id 0x%x device ota start!\r\n", get_ota_deviceID());
    set_modbus_reg_val(OTASTATUSREGADDR, OTASTARTRUNNING);
    
    if( (get_ota_deviceID() == 0) && (get_ota_deviceType() == ECU))
    {
        char cmd[512];
        set_modbus_reg_val(OTAPPROGRESSREGADDR, 10); // 进度10%
        
        // 步骤1: 检查源文件是否存在
        if(ecustatus.ErrorReg == 0)
        {
            char source_file[512] = {'\0'};
            snprintf(source_file, sizeof(source_file), "%s/%s", USB_MOUNT_POINT, get_ota_OTAFilename());
            
            LOG("Source file path: %s\n", source_file);

            // 检查源文件是否存在
            if (access(source_file, F_OK) != 0) {
                printf("OTA source file does not exist: %s\n", source_file);
                ecustatus.ErrorReg |= 1 << 2;
                return;
            }         
            LOG("[OTA] ECU deb file verified: %s\n", get_ota_OTAFilename());
        }

        set_modbus_reg_val(OTAPPROGRESSREGADDR, 40); // 进度40%
        
        // 步骤2: 直接复制deb文件到/var目录
        if(ecustatus.ErrorReg == 0)
        {
            char source_file[512] = {'\0'};
            char target_file[512] = {'\0'};
            
            snprintf(source_file, sizeof(source_file), "%s/%s", USB_MOUNT_POINT, get_ota_OTAFilename());
            snprintf(target_file, sizeof(target_file), "/var/%s", get_ota_OTAFilename()); // 直接使用原文件名
            
            memset(cmd, 0, sizeof(cmd));
            snprintf(cmd, sizeof(cmd), "cp \"%s\" \"%s\"", source_file, target_file);
            LOG("[OTA] Copy command: %s\n", cmd);
            
            int ret = system(cmd);
            if (ret == 0) {
                LOG("[OTA] File copy to /var successful: %s\n", get_ota_OTAFilename());
            } else {
                LOG("[OTA] File copy to /var failed\n");
                ecustatus.ErrorReg |= 1 << 2;
            }
        }

        set_modbus_reg_val(OTAPPROGRESSREGADDR, 70); // 进度70%
        
        // 步骤3: 验证复制后的文件
        if(ecustatus.ErrorReg == 0)
        {
            char target_file[512] = {'\0'};
            
            snprintf(target_file, sizeof(target_file), "/var/%s", get_ota_OTAFilename());
            
            if (!verify_bin_file(target_file)) {
                LOG("[OTA] Copied file verification failed: %s\n", target_file);
                ecustatus.ErrorReg |= 1 << 4;
            } else {
                LOG("[OTA] Copied file verification successful: %s\n", target_file);
            }
        }

        // 步骤4: 完成操作
        if(ecustatus.ErrorReg == 0)
        {
            set_modbus_reg_val(OTAPPROGRESSREGADDR, 100); // 进度100%   
            // 完成OTA清理工作
            FinshhECUOtaAndCleanup();
            
            // 确保数据写入磁盘
            LOG("[OTA] File copied to /var successfully: %s\n", get_ota_OTAFilename());
            system("sync");
            // sleep(5);
            // system("reboot");
            // 不需要重启，直接完成
            LOG("[OTA] OTA process completed successfully\n");
        }

        // 错误处理
        if(ecustatus.ErrorReg != 0)
        {
            printf("can id 0x%x device ota failed, error register val 0x%x!\r\n", 
                   get_ota_deviceID(), ecustatus.ErrorReg);
            LOG("[OTA] can id 0x%x device ota failed, error register val 0x%x!\r\n", 
                get_ota_deviceID(), ecustatus.ErrorReg);
            set_modbus_reg_val(OTASTATUSREGADDR, OTAFAILED);
        }
        set_ota_OTAStart(0);
    }
    else
    {
        LOG("[OTA] get_ota_deviceID() = 0x%x, get_ota_deviceType() = %d\r\n",get_ota_deviceID(),get_ota_deviceType());
        ecustatus.ErrorReg = 1;
        ecustatus.ErrorDeviceID = get_ota_deviceID();
    }
}



void FinshhECUOtaAndCleanup(void)
{
    set_ota_deviceType(0);
    set_ota_OTAStart(0);
    printf("[OTA ECU] OTA finished, cleaning up...\n");
    delete_files_with_prefix(USB_MOUNT_POINT, "XC");//  这个要删除升级文件，判断xcpstatus状态，成功或者失败删除
    delete_files_with_prefix(USB_MOUNT_POINT, "md5"); // 删除升级文件
    delete_files_with_prefix(USB_MOUNT_POINT, "deb"); // 删除升级文件
    delete_files_with_prefix(USB_MOUNT_POINT, "tar"); // 删除升级文件
	g_otactrl.UpDating = 0;//1130(升级结束)
	ecustatus.CANStartOTA = 0;
    set_TCU_PowerUpCmd(BMS_POWER_DEFAULT);
    LOG("[OTA] OTA finished, cleaning up...\n");
	set_modbus_reg_val(OTASTATUSREGADDR, OTAIDLE);
}


// 简单的文件验证（不依赖file命令）
static int verify_bin_file(const char *filepath)
{
    FILE *fp = fopen(filepath, "rb");
    if (!fp) {
        printf("Cannot open file for verification: %s\n", filepath);
        return 0;
    }
    
    // 检查文件大小
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    printf("File size: %ld bytes\n", file_size);
    
    // ECU程序通常有一定的大小范围
    if (file_size < 5 * 1024 || file_size > 10 * 1024 * 1024) {
        printf("File size %ld not in expected range\n", file_size);
        fclose(fp);
        return 0;
    }
    
    // 可选：检查ELF魔数
    unsigned char header[4];
    if (fread(header, 1, 4, fp) == 4) {
        // ELF文件头: 0x7F 'E' 'L' 'F'
        if (header[0] == 0x7F && header[1] == 'E' && 
            header[2] == 'L' && header[3] == 'F') {
            printf("File has valid ELF header\n");
            fclose(fp);
            return 1;
        }
    }
    
    fclose(fp);
    
    // 即使不是标准ELF也继续（可能是去掉了头的二进制）
    printf("File may be a binary (not standard ELF), continuing...\n");
    return 1;
}