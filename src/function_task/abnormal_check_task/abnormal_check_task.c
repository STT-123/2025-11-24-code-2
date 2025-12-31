#include "abnormal_check_task.h"
#include "device_drv/abncheck/abncheck.h"
#include "interface/bms/bms_analysis.h"
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"
#include <pthread.h>
#include "interface/log/log.h"
#include "ip_setting.h"
pthread_t AnormalDetectionTask_TASKHandle = 0;


void *AbnormalDetection(void *arg)
{
    /**
     * 目前检测的故障只有、CAN0通道、SD卡
    */
    while (1)
    {
        /* code */
        check_bcu_rx_timeout();//CAN0 通道检测
        PHYlinktate(); //网口物理连接检测 
        get_BCU_FaultInfo(get_BCU_FaultInfoLv4Value(),get_BCU_FaultInfoLv3Value(),get_BCU_FaultInfoLv2Value());
        ECUfault_process(); // 各种故障检测
        can_monitor_fun();//CAN 通道 通道检测
        log_eror_csv();  //存储
        // 1. 简单测试是否能ping通百度
        // int result = can_ping_host("ocpp.xcharger.net", 5);
        // if (result == 1) {
        //     printf("可以ping通百度\n");
        // } else if (result == 0) {
        //     printf("无法ping通百度\n");
        // } else {
        //     printf("ping测试执行错误\n");
        // }
        check_and_fix_ip(MODBUS_ETH_NUM);//检测ip地址是否被修改并自动更正
        usleep(1000 * 1000);
    }
}


void abnormalDetectionTaskCreate(void)
{
    int ret;
    do
    {
        ret = pthread_create(&AnormalDetectionTask_TASKHandle, NULL, AbnormalDetection, NULL);
        if (ret != 0)
        {
            LOG("[Check] Failed to create AnormalDetectionTask thread : %s", strerror(ret));
            sleep(1);
        }
        else
        {
            LOG("[Check] AnormaletectionTask thread created successfully.\r\n");
        }
    } while (ret != 0);
}