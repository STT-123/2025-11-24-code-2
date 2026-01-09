#include <time.h>
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"
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
#include "ocpp_send.h"
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
    
    // 区分信号类型
    if (sig == SIGINT || sig == SIGTERM) {
        // 正常退出信号
        printf("\n程序正在退出... (信号: %d)\n", sig);
        
        if (sig == SIGINT) {
            printf("原因: Ctrl+C 用户中断\n");
        } else {
            printf("原因: 终止信号\n");
        }
        
        // 清理资源
        // close_all_connections();
        
        exit(0);  // 正常退出码
    }
    else {
        // 真正的崩溃信号
        fprintf(stderr, "\n\n!!! 程序崩溃 !!!\n");
        fprintf(stderr, "崩溃信号: %d\n", sig);
        fprintf(stderr, "可能原因: ");
        LOG("!!! 崩溃 !!!\r\n");
        switch(sig) {
            case SIGSEGV: fprintf(stderr, "段错误 (空指针/内存越界)\n"); break;
            case SIGABRT: fprintf(stderr, "程序中止 (assert/abort调用)\n"); break;
            case SIGBUS:  fprintf(stderr, "总线错误 (内存对齐问题)\n"); break;
            case SIGFPE:  fprintf(stderr, "算术异常 (除零等)\n"); break;
            case SIGILL:  fprintf(stderr, "非法指令\n"); break;
            default:      fprintf(stderr, "未知错误\n"); break;
        }
        
        // 获取堆栈跟踪
        fprintf(stderr, "\n崩溃堆栈跟踪:\n");
        size = backtrace(array, 20);
        backtrace_symbols_fd(array, size, STDERR_FILENO);
        
        fprintf(stderr, "\n调试建议:\n");
        fprintf(stderr, "1. 使用地址信息定位问题\n");
        fprintf(stderr, "2. 检查 0x404198 附近的代码\n");
        
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
    
    printf("Crash handler installed\n");
}

int main(int argc, char **argv)
{
    setup_crash_handler();
    /*=================硬件接口初始化部分================*/
    printf_version();//初始打印
    log_init();// 日志初始化
    settings_Init();// 判断本机IP 如果不存在 默认使用110
    my_epoll_Init(); // 初始化epoll环境
   
    /*=================任务初始化部分================*/
    bcu_DealTaskCreate();
    bmu_DealTaskCreate();
    modbusTcpServerTaskCreate();//moduTCP服务
    ota_Upgrade_TaskCreate();//代码升级任务
    xmodemCommTaskCreatee();//监听OTA 存储升级文件Xmodem协议
    SDCardDataSaveTaskCreate(); // SD卡写任务
    abnormalDetectionTaskCreate(); // 异常监测任务
    // ocppCommunicationTaskCreate(); //ocpp通信任务
    FtpServiceThreadCreate();
     int index1 = 0;
    /*teste*/

    while (1)
    {
        // can_do_stop("can2");
        // printf("DAqX_FaultCode1 = %d\r\n", DAqX_FaultCode1[0]);//一级故障
        // printf("data.get_usBatMaxTempCellIndex = %ld\n", get_usBatMaxTempCellIndex());
        // printf("data. get_usBatCellTempMax( = %d\n",  get_usBatCellTempMax());
        // printf("data. get_usBatMinTempCellIndex( = %d\n",  get_usBatMinTempCellIndex());
        // printf("data.get_usBatCellTempMin = %ld\n", get_usBatCellTempMin());

        // printf("data. get_usBatMaxVoltCellIndex( = %d\n",  get_usBatMaxVoltCellIndex());
        // printf("data.get_usBatCellVoltMax = %ld\n", get_usBatCellVoltMax());
        // printf("data.get_usBatMinVoltCellIndex = %ld\n", get_usBatMinVoltCellIndex());
        // printf("data.get_usBatCellVoltMin = %ld\n", get_usBatCellVoltMin());
        sleep(1);
        // printf("get_BCUFD() = %d\r\n",get_BCU_CAN_FD());
        // printf("main printf sleep(1) \r\n");
        // index1 = 0x4B5C - 0x3000;
        // printf("Mobud[0x4B5C] = %x\r\n",modbusBuff[index1]);//ota上载寄存器判断
        // index1 = 0x4B5D - 0x3000;
        // printf("Mobud[0x4B5D] = %x\r\n",modbusBuff[index1]);//ota上载寄存器判断
        // printf("BCU_SystemWorkMode = %x\r\n",BCU_SystemWorkMode);//ota上载寄存器判断
        // printf("BCU_FaultInfoLv1 = %x\r\n",BCU_FaultInfoLv1);//ota上载寄存器判断
        // printf("BCU_FaultInfoLv2 = %x\r\n",BCU_FaultInfoLv2);//ota上载寄存器判断    
    }
}

