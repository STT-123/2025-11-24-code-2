#include "bmu_deal.h"
#include "interface/epoll/myepoll.h"
#include "device_drv/bcu_deal/bcu_deal.h"
static int BMU_CAN_FD = -1;
queue_t Queue_BMURevData; // 分机消息队列，用于epoll接收数据存入，防止处理不过来所以用队列，内部使用
my_event_data_t bmuCanEventData = {
    .fd = -1,  // 无效的文件描述符
    .pin = -1, // 无效的引脚
    .fun_handle = NULL,
    .call_back = NULL
};


static void bmu_can_epoll_msg_transmit(void *arg)
{
    struct can_frame can_rev;
    memset(&can_rev, 0, sizeof(struct can_frame));

    if(BMU_CAN_FD < 0){
        return;
    }

    if (HAL_can_read(BMU_CAN_FD, &can_rev, 1) > 0) 
    {
        // for (int i = 0; i < 8; i++)
        // {
        //     printf("d[%d] = 0x%x  ",i,can_rev.data[i]);
        // }
        // printf("\r\n");

        // 在OTA 的过程中，可以根据CAN ID进行过滤放在消息队列中，避免在OTA浪费计算
        if (queue_post(&Queue_BMURevData, (unsigned char *)&can_rev, sizeof(can_rev)) != 0)
        {
            queue_destroy(&Queue_BMURevData);
            queue_init(&Queue_BMURevData);
        }
    }
}

// 初始化
bool bmu_Init(void)
{
    struct epoll_event ev;
    queue_init(&Queue_BMURevData); // 用于接收消息后存入
#if testcan
    if(Drv_can_bind_interface(BMU_CAN_DEVICE_NAME, BMU_CAN_BITRATE ,&BMU_CAN_FD,bmu_can_epoll_msg_transmit))
    {
        LOG("[BCU]%s initial bind failed\n", BMU_CAN_DEVICE_NAME);
        return false;
    }
#else
    if (can_ifconfig_init(BMU_CAN_DEVICE_NAME, BMU_CAN_BITRATE) == false)
    {
        LOG("[BMU] %s can_ifconfig_init 失败\n", BMU_CAN_DEVICE_NAME);
        return false;
    }

    while (can_band_init(BMU_CAN_DEVICE_NAME, &BMU_CAN_FD) == false)
    {
        LOG("[BMU]%s can_band_init 失败，重试中...\n", BMU_CAN_DEVICE_NAME);
        sleep(1);
    }

    bmuCanEventData.fd = BMU_CAN_FD;
    bmuCanEventData.fun_handle = (void *)bmu_can_epoll_msg_transmit;
    ev.events = EPOLLIN;
    ev.data.ptr = (void *)&bmuCanEventData;
    if (-1 == my_epoll_addtast(bmuCanEventData.fd, &ev))
    {
        LOG("[BMU]%s add epoll failed \n", BMU_CAN_DEVICE_NAME);
        return false;
    }
#endif
    return true;
}

// 发送can报文
int Drv_bmu_can_send(CAN_MESSAGE *pFrame)
{
    struct can_frame can_frame;
    int retryCount = 0;
    const int maxRetries = 3;
    Convert_CAN_MESSAGE_to_can_frame(pFrame, &can_frame);
    while (retryCount < maxRetries)
    {
        if (HAL_can_write(BMU_CAN_FD, &can_frame))
        {
            return 0;
        }
        retryCount++;
        usleep(100);
    }
    if (retryCount >= maxRetries)
    {
        LOG("[BMU] Drv_can_auto_recover... Drv_bmu_can_send\r\n");
        Drv_can_auto_recover(BMU_CAN_DEVICE_NAME, BMU_CAN_BITRATE,&BMU_CAN_FD, bmu_can_epoll_msg_transmit);
    }
    return -1;
}

// 发送canfd报文
int Drv_bmu_canfd_send(struct canfd_frame *cansend_data)
{
    int retryCount = 0;
    const int maxRetries = 3;

    while (retryCount < maxRetries)
    {
        if (HAL_canfd_write(BMU_CAN_FD, &cansend_data))
        {
            return 0;
        }

        retryCount++;
        usleep(100);
    }
    if (retryCount >= maxRetries)
    {
        LOG("[BMU] Drv_can_auto_recover... Drv_bmu_canfd_send\r\n");
        Drv_can_auto_recover(BMU_CAN_DEVICE_NAME, BMU_CAN_BITRATE,&BMU_CAN_FD, bmu_can_epoll_msg_transmit);
    }
    return -1;
}
int bmu_can_check_state(void)
{ 
    return Drv_can_auto_recover(BMU_CAN_DEVICE_NAME, BMU_CAN_BITRATE,
                           &BMU_CAN_FD, bmu_can_epoll_msg_transmit);
}