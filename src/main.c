#include <time.h>
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"
#include "interface/globalVariable.h"
#include "interface/log/log.h"
#include "interface/epoll/myepoll.h"
#include "interface/setting/ip_setting.h"
#include "device_drv/bcu_deal/bcu_deal.h"
#include "device_drv/bmu_deal/bmu_deal.h"
#include "device_drv/modbustcp_pro/modbustcp_pro.h"
#include "function_task/bcu_task/bcu_task.h"
#include "function_task/bmu_task/bmu_task.h"
#include "function_task/ota_task/otaupgrad_task.h"
#include "function_task/xmodem_task/xmodem_task.h"
#include "function_task/abnormal_check_task/abnormal_check_task.h"
#include "device_drv/abncheck/abncheck.h"
extern ecu_fault_t ecu_fault ;
static void printf_version(void)
{
    char compile_date[12] = {0}, compile_time[20] = {0};
    sprintf(compile_date, "%s", __DATE__);
    sprintf(compile_time, "%s", __TIME__);
    LOG("========================================================= \n");
    LOG("[VERSION] BAT ECU_EU START RUN!!!. \n");
    LOG("[VERSION] Software compilation time %s--%s. \n", compile_date, compile_time);
    LOG("========================================================= \n");
}


void crash_handler(int sig) {
    void *array[20];
    size_t size;
    char **strings;
    // 区分信号类型
    if (sig == SIGINT || sig == SIGTERM) {
        // 正常退出信号
        LOG("The program is exiting... (signal: %d)\n", sig);
        
        if (sig == SIGINT) {
            LOG("reason: Ctrl+C User interruption\n");
        } else {
            LOG("reason: Termination signal\n");
        }
        
        // 清理资源
        // close_all_connections();
        
        exit(0);  // 正常退出码
    }
    else {
        // 真正的崩溃信号
        LOG("\n!!! Program crash !!!\n");
        LOG("Collapse signal: %d\n", sig);
        LOG("Possible reasons: ");
        
        switch(sig) {
            case SIGSEGV: LOG("Segmentation fault ((null pointer/memory out of bounds))\n"); break;
            case SIGABRT: LOG("program suspension (assert/abort调call\n"); break;
            case SIGBUS:  LOG("Bus error (Memory alignment issue)\n"); break;
            case SIGFPE:  LOG("Arithmetic exception (excluding zero, etc.)\n"); break;
            case SIGILL:  LOG("illegal instruction\n"); break;
            default:      LOG("Unknown error\n"); break;
        }
        
        // 获取堆栈跟踪
        // 获取堆栈跟踪
        LOG("Collapse Stack Tracking:\n");
        size = backtrace(array, 20);
        strings = backtrace_symbols(array, size);
        
        if (strings != NULL) {
            for (size_t i = 0; i < size; i++) {
                LOG("%s\n", strings[i]);
            }
            free(strings);
        }
        
        LOG("Debugging suggestions:\n");
        LOG("1.Use address information to locate questions\n");
        LOG("2.Check the code near 0x404198\n");
        
        // 同时打印到 stderr（为了即时查看）
        fprintf(stderr, "\nThe detailed information of the program crash has been recorded in the log\n");
        exit(1);  // 异常退出码
    }
}

void setup_crash_handler() {
    signal(SIGSEGV, crash_handler);  // 段错误
    signal(SIGABRT, crash_handler);  // 中止
    signal(SIGBUS, crash_handler);   // 总线错误
    signal(SIGFPE, crash_handler);   // 浮点异常
    signal(SIGILL, crash_handler);   // 非法指令
    signal(SIGTERM, crash_handler);  // 终止信号
    signal(SIGINT, crash_handler);   // Ctrl+C中断信号 ← 添加这一行！
}


int main(int argc, char **argv)
{
    setup_crash_handler();
    /*=================硬件接口初始化部分================*/
    printf_version();//初始打印
    log_init();// 日志初始化
    settings_Init();// 判断本机IP 如果不存在 默认使用110
    my_epoll_Init(); // 初始化epoll环境
   
    // /*=================任务初始化部分================*/
    bcu_DealTaskCreate();
    bmu_DealTaskCreate();
    modbusTcpServerTaskCreate();//moduTCP服务
    ota_Upgrade_TaskCreate();//代码升级任务
    xmodemCommTaskCreatee();//监听OTA 存储升级文件Xmodem协议
    SDCardDataSaveTaskCreate(); // SD卡写任务
    abnormalDetectionTaskCreate(); // 异常监测任务
    ocppCommunicationTaskCreate(); //ocpp通信任务
    // FtpServiceThreadCreate();
    
    while (1)
    {
        sleep(1);
        // printf("get_BCUFD() = %d\r\n",get_BCU_CAN_FD());
         printf("main printf sleep(1) \r\n");
        // printf("Mobud[1122] = %x\r\n",modbusBuff[0x462]);//ota上载寄存器判断
        // printf("Mobud[0x463] = %x\r\n",modbusBuff[0x463]);//ota上载寄存器判断
        // printf("Mobud[0x6063] = %x\r\n",modbusBuff[0x6063-0x3000]);//ota上载寄存器判断
        // printf("Mobud[0x3464] = %x\r\n",modbusBuff[0x3464-0x3000]);//ota上载寄存器判断
        // printf("Mobud[0x3465] = %x\r\n",modbusBuff[0x3465-0x3000]);//ota上载寄存器判断,这是浮点数
    }
}

