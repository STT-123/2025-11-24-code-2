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


int main(int argc, char **argv)
{
    /*=================硬件接口初始化部分================*/
    printf_version();//初始打印
    log_init();// 日志初始化
    settings_Init();// 判断本机IP 如果不存在 默认使用110
    my_epoll_Init(); // 初始化epoll环境
   
    // // /*=================任务初始化部分================*/
    bcu_DealTaskCreate();
    bmu_DealTaskCreate();
    modbusTcpServerTaskCreate();//moduTCP服务
    ota_Upgrade_TaskCreate();//代码升级任务

    xmodemCommTaskCreatee();//监听OTA 存储升级文件Xmodem协议
    SDCardDataSaveTaskCreate(); // SD卡写任务
    abnormalDetectionTaskCreate(); // 异常监测任务
    //ocppCommunicationTaskCreate(); //ocpp通信任务
    //FtpServiceThreadCreate();

    int ret = 0;

    while (1)
    {
        sleep(1);
        // printf("get_BCUFD() = %d\r\n",get_BCU_CAN_FD());
        // //  printf("ret =, Mobud[0x1012] = \r\n");
        // // printf("Mobud[1122] = %x\r\n",modbusBuff[0x462]);//ota上载寄存器判断
        // // printf("Mobud[0x463] = %x\r\n",modbusBuff[0x463]);//ota上载寄存器判断
        // // printf("Mobud[0x6063] = %x\r\n",modbusBuff[0x6063-0x3000]);//ota上载寄存器判断
        // printf("Mobud[0x3464] = %x\r\n",modbusBuff[0x3464-0x3000]);//ota上载寄存器判断
        // printf("Mobud[0x3465] = %x\r\n",modbusBuff[0x3465-0x3000]);//ota上载寄存器判断,这是浮点数
    }
}

