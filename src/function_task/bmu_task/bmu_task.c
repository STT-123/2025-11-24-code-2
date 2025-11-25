#define _GNU_SOURCE
#include "bmu_task.h"
#include "device_drv/bmu_deal/bmu_deal.h"
#include "interface/log/log.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"
#include "function_task/sd_task/sd_task.h"
#include "device_drv/ota_upgrade/ota_fun.h"


pthread_t BMURecvDel_TASKHandle = 0;
void *bmu_DealTask(void *arg)
{
    int err = 0;
    CAN_MESSAGE canrev_frame;

    LOG("bmu_DealTask is running\n");
    bmu_Init(); // ecu 和 bmu通信can初始化（打开can口 绑定回调）
    while (1)
    {
        if ((g_ota_flag == OTAIDLE || g_ota_flag == OTAFAILED || g_otactrl.deviceType == AC))
        {

            // 等待信号，有信号则有消息来，处理以后加进消息接收中
            if (queue_pend(&Queue_BMURevData, (unsigned char *)&canrev_frame, &err) == 0)
            {
                if ((g_ota_flag == OTAIDLE || g_ota_flag == OTAFAILED))
                {
                    //printf("[CANRcvFcn] Receive CAN Message\r\n");
                    memcpy(&CANMsg, &canrev_frame, sizeof(CAN_MESSAGE));
                    CANRcvFcn_BMU_step();
                    memset(&canrev_frame, 0, sizeof(canrev_frame));
                }
            }
        }

        // printf("queue_pend return err = %d\r\n", err);
        usleep(10 * 1000);
    }
}

void bmu_DealTaskCreate(void)
{
    int ret;
    do
    {
        ret = pthread_create(&BMURecvDel_TASKHandle, NULL, bmu_DealTask, NULL);
        if (ret != 0)
        {
            LOG("Failed to create BMU_DealTask thread : %s", strerror(ret));
            sleep(1);
        }
        else
        {
            LOG("BMU_DealTask thread created successfully.\r\n");
        }
    } while (ret != 0);
}