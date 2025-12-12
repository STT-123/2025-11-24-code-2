#include "ota_ecu_update.h"
#include "interface/globalVariable.h"
#include "interface/log/log.h"
#include "interface/ini/ini.h"
#include "interface/bms/bms_analysis.h"
#include "interface/modbus/modbus_defines.h"
#include "device_drv/xmodem/xmodemdata.h"
#include "device_drv/ota_upgrade/ota_fun.h"
#include "device_drv/sd_store/sd_store.h"

#define APP_PATH  "/opt/xcharge"  

ECUStatus ecustatus = {0};


static UpgradeInfo max_upgrade = {0};  // 全局保存最大者
static int global_max_index = -1;      // 当前最大 X

// 从 "upgrade123" 提取数字 123，失败返回 -1
static int extract_index(const char* section) {
    if (strncmp(section, "upgrade", 7) != 0) {
        return -1;
    }
    const char* p = section + 7;
    if (*p == '\0') return -1; // 没有数字

    // 检查剩余部分是否全为数字
    for (const char* q = p; *q; q++) {
        if (!isdigit((unsigned char)*q)) {
            return -1;
        }
    }

    return atoi(p);
}

// 回调函数：只保留 index 最大的 upgrade
static int handler(void* user, const char* section, const char* name,
                   const char* value) {
    (void)user;

    int idx = extract_index(section);
    if (idx < 0) {
        return 1; // 忽略非 upgradeX 的 section
    }

    // 如果当前 section 的 index 更大，就重置结构体
    if (idx > global_max_index) {
        memset(&max_upgrade, 0, sizeof(max_upgrade));
        strncpy(max_upgrade.section, section, sizeof(max_upgrade.section) - 1);
        max_upgrade.index = idx;
        global_max_index = idx;
    }

    // 只处理当前最大 index 的字段（避免旧数据污染）
    if (idx != global_max_index) {
        return 1;
    }

    #define MATCH(s) strcmp(name, s) == 0
    if (MATCH("old_version")) {
        strncpy(max_upgrade.old_version, value, sizeof(max_upgrade.old_version) - 1);
    } else if (MATCH("new_version")) {
        strncpy(max_upgrade.new_version, value, sizeof(max_upgrade.new_version) - 1);
    } else if (MATCH("upgrade_file")) {
        strncpy(max_upgrade.upgrade_file, value, sizeof(max_upgrade.upgrade_file) - 1);
    } else if (MATCH("md5sum")) {
        strncpy(max_upgrade.md5sum, value, sizeof(max_upgrade.md5sum) - 1);
    }
    #undef MATCH

    return 1;
}

int compute_file_md5(const char *filepath, char *out_md5) {
    char cmd[512];
    FILE *fp;
    snprintf(cmd, sizeof(cmd), "md5sum \"%s\" | cut -d' ' -f1", filepath);
    fp = popen(cmd, "r");
    if (!fp) return -1;

    if (fgets(out_md5, 33, fp) == NULL) {
        pclose(fp);
        return -1;
    }

    // 去掉换行符
    out_md5[strcspn(out_md5, "\n")] = 0;
    pclose(fp);
    return 0;
}
// 修改 find_ota_files_simple 函数
int find_ota_files_simple(const char *extract_dir, char *conf_path, size_t conf_len, 
                         char *deb_path, size_t deb_len) {
    FILE *fp;
    char cmd[1024];
    
    // 查找 .conf 文件
    snprintf(cmd, sizeof(cmd), "find \"%s\" -type f \\( -name \"*.conf\" -o -name \"*.CONF\" \\) 2>/dev/null", 
             extract_dir);
    
    LOG("[OTA] Running command: %s\n", cmd);
    fp = popen(cmd, "r");
    if (fp) {
        int found = 0;
        char line[1024];
        while (fgets(line, sizeof(line), fp)) {
            line[strcspn(line, "\n")] = '\0';
            LOG("[OTA] Found conf candidate: %s\n", line);
            if (!found) {
                strncpy(conf_path, line, conf_len - 1);
                conf_path[conf_len - 1] = '\0';
                found = 1;
            }
        }
        pclose(fp);
        if (!found) {
            LOG("[OTA] No conf file found\n");
        }
    } else {
        LOG("[OTA] Failed to execute find command\n");
    }
    
    // 查找 .deb 文件
    snprintf(cmd, sizeof(cmd), "find \"%s\" -type f \\( -name \"*.deb\" -o -name \"*.DEB\" \\) 2>/dev/null", 
             extract_dir);
    
    LOG("[OTA] Running command: %s\n", cmd);
    fp = popen(cmd, "r");
    if (fp) {
        int found = 0;
        char line[1024];
        while (fgets(line, sizeof(line), fp)) {
            line[strcspn(line, "\n")] = '\0';
            LOG("[OTA] Found deb candidate: %s\n", line);
            if (!found) {
                strncpy(deb_path, line, deb_len - 1);
                deb_path[deb_len - 1] = '\0';
                found = 1;
            }
        }
        pclose(fp);
        if (!found) {
            LOG("[OTA] No deb file found\n");
        }
    } else {
        LOG("[OTA] Failed to execute find command\n");
    }
    
    LOG("[OTA] Final conf_path: %s\n", conf_path);
    LOG("[OTA] Final deb_path: %s\n", deb_path);
    LOG("[OTA] conf_path valid: %d, deb_path valid: %d\n", 
         (strlen(conf_path) > 0), (strlen(deb_path) > 0));
    
    return (strlen(conf_path) > 0 && strlen(deb_path) > 0);
}
void ECU_OTA(void)
{
    LOG("[OTA] ECU_OTA start!, get_ota_OTAStart():%d\r\n", get_ota_OTAStart());
    if (!get_ota_OTAStart()) return;

    char sd_source_file[512] = {'\0'};//SD的路径
    memset(&ecustatus, 0, sizeof(ECUStatus));//异常状态
    LOG("[OTA] get_ota_deviceType() : %d \r\n", get_ota_deviceType());
    LOG("[OTA] can id 0x%x device ota start!\r\n", get_ota_deviceID());
    set_modbus_reg_val(OTASTATUSREGADDR, OTASTARTRUNNING);
    
    if( (get_ota_deviceID() == 0) && (get_ota_deviceType() == ECU))
    {
        set_modbus_reg_val(OTAPPROGRESSREGADDR, 10); // 进度10%
        
        // 步骤1: 检查SD卡的文件是否存在
        if(ecustatus.ErrorReg == 0)
        {
            
            snprintf(sd_source_file, sizeof(sd_source_file), "%s/%s", USB_MOUNT_POINT, get_ota_OTAFilename());
            
            LOG("Source file path: %s\n", sd_source_file);

            // 检查源文件是否存在
            if (access(sd_source_file, F_OK) != 0) {
                printf("OTA source file does not exist: %s\n", sd_source_file);
                ecustatus.ErrorReg |= 1 << 2;
                goto celanup;
            }         
        }

        set_modbus_reg_val(OTAPPROGRESSREGADDR, 40); // 进度40%
        /**==============================*/

        // 步骤2: 在tmp创建临时文件夹
        char extract_dir[512] = {0};
        snprintf(extract_dir, sizeof(extract_dir), "/tmp/ota_extract_%d", (int)getpid());
        if (mkdir(extract_dir, 0755) != 0 && errno != EEXIST) {
            LOG("[OTA] Failed to create extract dir: %s\n", extract_dir);
            ecustatus.ErrorReg |= 1 << 3; // 自定义错误位，比如 bit3 表示解压失败
            goto celanup;
        }

        // 步骤3: 将SD 卡的文件解压到tmp内
        char tar_cmd[512] = {0};
        snprintf(tar_cmd, sizeof(tar_cmd), "tar -xf \"%s\" -C \"%s\"", sd_source_file, extract_dir);

        LOG("[OTA] Executing tar command: %s\n", tar_cmd);
        int ret = system(tar_cmd);
        if (ret != 0) {
            LOG("[OTA] Tar extraction failed!\n");
            ecustatus.ErrorReg |= 1 << 3;
            goto celanup;
        }

        // 步骤4: 在解压后的文件夹查找文件名为 XC_ECU_Vxxx.conf和 XC_ECU_Vxxx.deb,压缩文件和解压文件名必须相同
        char base_name[256] = {0};
        char *dot = strrchr(get_ota_OTAFilename(), '.');
        if (dot && strcmp(dot, ".tar") == 0) {
            strncpy(base_name, get_ota_OTAFilename(), dot - get_ota_OTAFilename());
        } else {
            strcpy(base_name, get_ota_OTAFilename()); // fallback
        }

        // 步骤5: 检查conf和deb文件是否存在
        char conf_path[512] = {0};
        char deb_path[512] = {0};

        if (!find_ota_files_simple(extract_dir, conf_path, sizeof(conf_path), 
                                deb_path, sizeof(deb_path))) {
            LOG("[OTA] Could not find required files in extracted archive\n");
            
            // 列出所有文件用于调试
            char ls_cmd[1024];
            snprintf(ls_cmd, sizeof(ls_cmd), "find \"%s\" -type f | sort", extract_dir);
            LOG("[OTA] All files in extract dir:\n");
            system(ls_cmd);
            
            ecustatus.ErrorReg |= 1 << 4;
            goto celanup;
        }


        LOG("[OTA] Found conf: %s\n", conf_path);
        LOG("[OTA] Found deb: %s\n", deb_path);

        // 步骤6: 解析conf文件,赋值给max_upgrade
        int err = ini_parse(conf_path, handler, NULL);
        if (err < 0) {
            LOG("无法读取配置文件 'upgrade.conf'\n");
            ecustatus.ErrorReg |= 1 << 5; // 配置文件异常
            goto celanup;
        } else if (err > 0) {
            LOG("配置文件第 %d 行有错误\n", err);
            ecustatus.ErrorReg |= 1 << 5; // 配置文件异常
            goto celanup;
        }

        if (global_max_index == -1) {
            LOG("未找到任何 upgradeX 配置\n");
            ecustatus.ErrorReg |= 1 << 5; // 配置文件异常
            goto celanup;
        }

        // 步骤7: 直接复制ecu文件到/var目录
        if(ecustatus.ErrorReg == 0)
        {
            // 1. 获取文件路径
            char target_file[512] = {'\0'};           
            snprintf(target_file, sizeof(target_file), "/var/%s", max_upgrade.upgrade_file); // 直接使用原文件名

            LOG("[OTA] Copying from: %s\n", deb_path);
            LOG("[OTA] Copying to: %s\n", target_file);
       
            // 2. 计算MD5值
            char computed_md5[33] = {0}; // 32 hex + '\0'
            if (compute_file_md5(deb_path, computed_md5) != 0) {
                LOG("[OTA] Failed to compute MD5 for %s\n", deb_path);
                ecustatus.ErrorReg |= 1 << 7; // MD5 计算失败
                goto celanup;
            }

            // 3. 比较 MD5（转为小写再比较，因为 md5sum 工具输出小写，但配置可能大写）
            char expected_md5[33] = {0};
            strncpy(expected_md5, max_upgrade.md5sum, 32);
            expected_md5[32] = '\0';
            for (int i = 0; expected_md5[i]; i++) {
                expected_md5[i] = tolower((unsigned char)expected_md5[i]);
            }
            for (int i = 0; computed_md5[i]; i++) {
                computed_md5[i] = tolower((unsigned char)computed_md5[i]);
            }

            if (strcmp(computed_md5, expected_md5) != 0) {
                LOG("[OTA] MD5 mismatch!\n");
                ecustatus.ErrorReg |= 1 << 8; // MD5 校验失败
                goto celanup;
            }
            // 4. 比较通过,复制文件到/var
            LOG("[OTA] MD5 verification passed.\n");
            char cp_cmd[512];
            memset(cp_cmd, 0, sizeof(cp_cmd));
            snprintf(cp_cmd, sizeof(cp_cmd), "cp \"%s\" \"%s\"", deb_path, target_file);
            LOG("[OTA] Copy command: %s\n", cp_cmd);
            
            int ret = system(cp_cmd);
            if (ret == 0) {
                LOG("[OTA] File copy to /var successful: %s\n", deb_path);
            } else {
                LOG("[OTA] File copy to /var failed\n");
                ecustatus.ErrorReg |= 1 << 2;
                goto celanup;
            }
        }

        set_modbus_reg_val(OTAPPROGRESSREGADDR, 70); // 进度70%
        
        // 步骤8: 完成操作
        if(ecustatus.ErrorReg == 0)
        {
            set_modbus_reg_val(OTAPPROGRESSREGADDR, 100); // 进度100%   
            // 完成OTA清理工作
            FinshhECUOtaAndCleanup();
            // 确保数据写入磁盘
            system("sync");
            // sleep(5);
            // system("reboot");
            // 不需要重启，直接完成
            LOG("[OTA] OTA process completed successfully\n");
        }else{
            LOG("[OTA] can id 0x%x device ota failed, error register val 0x%x!\r\n", get_ota_deviceID(), ecustatus.ErrorReg);
            set_modbus_reg_val(OTASTATUSREGADDR, OTAFAILED); 
        }
    }
    else
    {
        LOG("[OTA] get_ota_deviceID() = 0x%x, get_ota_deviceType() = %d\r\n",get_ota_deviceID(),get_ota_deviceType());
        ecustatus.ErrorReg = 1;
        ecustatus.ErrorDeviceID = get_ota_deviceID();
    }
celanup:
    set_modbus_reg_val(OTASTATUSREGADDR, OTAFAILED);
    return;
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


