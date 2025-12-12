#define _GNU_SOURCE
#include "function_task/bcu_task/bcu_task.h"
#include "device_drv/bcu_deal/bcu_deal.h"
#include "interface/log/log.h"
#include "interface/bms/bms_analysis.h"
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/modbus/modbus_defines.h"
#include "device_drv/sd_store/sd_store.h"
#include "function_task/sd_task/sd_task.h"
#include "device_drv/ota_upgrade/ota_fun.h"

pthread_t BCURecDel_TASKHandle = 0;
extern uint8_t modbusBuffInitFlag ;//保证modbusBuff空间分配好了,bcu才能使用,不然bcu操作空指针会段错误
extern struct timespec start_tick;
void *bcu_DealTask(void *arg)
{
    struct canfd_frame canrev_frame = {0};
    CANFD_MESSAGE can_msg_buf ={0};
    LOG("Func_thread_can0_dealwith is running\n");
    unsigned int call_count = 0;
    int len = 0;
    int bms_analysis_done = 0;
    clock_gettime(CLOCK_MONOTONIC, &start_tick); // 记录线程开始时间
    bcu_Init();// ecu 和 bcu通信can初始化（打开can口 绑定回调）

    while (1)
    {
        // usleep(200*1000);

        if ((get_ota_OTAStart() == 0) || (g_otactrl.deviceType == AC))
        {
            if (call_count == 0) {
                CANFDSendFcn_BCU_step();
            }
            call_count = (call_count + 1) % 25;

            if (queue_pend(&Queue_BCURevData_FD, (unsigned char *)&canrev_frame, &len) == 0)
            {
                
                if ((canrev_frame.len > 8))
                {
                    canrev_frame.can_id &= CAN_EFF_MASK;
                    if(1 == modbusBuffInitFlag){
                        ConvertCANFDToBus(&canrev_frame, &CANFDRcvMsg);
                        CANFDRcvFcn_BCU_step();           
                        ConvertCANFDToBus(&canrev_frame, &can_msg_buf);
                        Drv_write_to_active_buffer(&can_msg_buf, 1);
                    }
                    
                }
                memset(&canrev_frame, 0, sizeof(canrev_frame));
            }
            else
            {
                // 仅在初始化后10秒执行一次
                if (!bms_analysis_done)
                {

                    if(GetTimeDifference_ms(start_tick) >= 10000){
                        CANFDRcvFcn_BCU_step();
                        CANFDSendFcn_BCU_step();
                        bms_analysis_done = 1;
                        LOG("Drv_BMS_Analysis executed after 10s delay\r\n");
                    }
                }
            }
        }

        usleep(2 * 1000); // 临时添加测试
    }
}


void bcu_DealTaskCreate(void)
{
    int ret;
    do
    {
        ret = pthread_create(&BCURecDel_TASKHandle, NULL, bcu_DealTask, NULL);
        if (ret != 0)
        {
            LOG("Failed to create BCU_DealTask thread : %s", strerror(ret));
            sleep(1);
        }
        else
        {
            LOG("BCU_DealTask thread created successfully.\r\n");
        }
    } while (ret != 0);
}