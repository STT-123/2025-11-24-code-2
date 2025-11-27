#include "bcu_deal.h"
#include "interface/log/log.h"
#include "interface/epoll/myepoll.h"
#include "device_drv/abncheck/abncheck.h"
#include "device_drv/bmu_deal/bmu_deal.h"
static int BCU_CAN_FD = -1;
queue_t Queue_BCURevData;
queue_t Queue_BCURevData_FD;
/*======================================静态函数==================================================*/
my_event_data_t bcuCanEventData = {
.fd = -1,  // 无效的文件描述符
.pin = -1, // 无效的引脚
.fun_handle = NULL,
.call_back = NULL
};

extern my_event_data_t bmuCanEventData ;
static pthread_mutex_t can_recover_mutex = PTHREAD_MUTEX_INITIALIZER; //恢复锁，当需要can复位的时候，避免两个任务都复位

static int Drv_bcu_resetcan_device(const char *can_name)
{
    int canState = 0;
    HAL_can_get_state(can_name, &canState);
    if (canState != 0) {
        LOG("[BCU]%s ERROR status is %0x\r\n", can_name, canState);
        HAL_can_closeEx(&BCU_CAN_FD);
        if (can_ifconfig_init(BCU_CAN_DEVICE_NAME, BCU_CAN_BITRATE) == false){
            LOG("[BCU]can_ifconfig_init 失败\n");
            return false;
        }

        while (can_band_init(BCU_CAN_DEVICE_NAME, &BCU_CAN_FD) == false) {
            sleep(1);
        }
    }
    return 0;
}

static void bcu_can_epoll_msg_transmit(void *arg)
{
    struct canfd_frame can_rev ;
    CAN_MESSAGE can_send ;

    memset(&can_rev, 0, sizeof(struct canfd_frame));
    memset(&can_send, 0, sizeof(CAN_MESSAGE));

    if(BCU_CAN_FD <0){
        return;
    }
    int frame_type = HAL_canfd_read(BCU_CAN_FD, &can_rev, 1);

    time(&g_last_bcu_rx_time);
    
    if (frame_type == 1)//1表示CAN 数据-8
    {
        Convert_canfd_frame_to_CAN_MESSAGE(&can_rev, &can_send);

        if (((get_TCU_PowerUpCmd()) == BMS_POWER_UPDATING) && (can_send.ID == 0x30C1600 || can_send.ID == 0x61B || can_send.ID == 0x1CB010E4))
        {
            if (queue_post(&Queue_BCURevData, &can_send, sizeof(CAN_MESSAGE)) != 0)
            {   
                queue_destroy(&Queue_BCURevData);
                queue_init(&Queue_BCURevData);
            }
            else{
            }
        }
        else if ((get_TCU_PowerUpCmd()) != BMS_POWER_UPDATING && can_send.ID != 0x18FFC13A && can_send.ID != 0x18FFC13B && can_send.ID != 0x18FFC13C && can_send.ID != 0x18FAE6E1 && can_send.ID != 0x18FD7BE1 && can_send.ID != 0X18FA78F1 && can_send.ID != 0x18FFC13D && can_send.ID != 0x18FA78F5 && can_send.ID != 0x18FAE6E2)
        {
            if (queue_post(&Queue_BCURevData, &can_send, sizeof(CAN_MESSAGE)) != 0)
            {             
                queue_destroy(&Queue_BCURevData);
                queue_init(&Queue_BCURevData);
            }
            else{
            }
        }
    }
    else if (frame_type == 2)//2表示CAN FD数据-64
    {
        //往can fd队列方数据，但是数据满了,在升级过程在，不再从canfd队列取数据了，此时fd满了
        if (queue_post(&Queue_BCURevData_FD, (unsigned char *)&can_rev, sizeof(can_rev)) != 0)
        {
            queue_destroy(&Queue_BCURevData_FD);
            queue_init(&Queue_BCURevData_FD);
        }
        else{
        }
    }
    else if(frame_type < 0)
    {
        if (errno == EBADF) 
        {
            LOG("[BCU] CAN fd is bad, triggering recovery...\n");
            Drv_can_auto_recover(BCU_CAN_DEVICE_NAME, BCU_CAN_BITRATE, 
                               &BCU_CAN_FD, bcu_can_epoll_msg_transmit);
        }
    }
}


/*======================================外部函数==================================================*/
bool bcu_Init(void)
{


    queue_init(&Queue_BCURevData);    // 用于接收消息后存入
    queue_init(&Queue_BCURevData_FD); // 用于接收消息后存入
#if testcan
    if(Drv_can_bind_interface(BCU_CAN_DEVICE_NAME, BCU_CAN_BITRATE ,&BCU_CAN_FD,bcu_can_epoll_msg_transmit))
    {
        LOG("[BCU]%s initial bind failed\n", BCU_CAN_DEVICE_NAME);
        return false;
    }
#else

    struct epoll_event ev;

    if (can_ifconfig_init(BCU_CAN_DEVICE_NAME, BCU_CAN_BITRATE) == false)
    {
        LOG("[BCU]%s can_ifconfig_init 失败\n", BCU_CAN_DEVICE_NAME);
        return false;
    }

    while (can_band_init(BCU_CAN_DEVICE_NAME, &BCU_CAN_FD) == false)
    {
        LOG("[BCU]%s can_band_init 失败，重试中...\n", BCU_CAN_DEVICE_NAME);
        sleep(1);
    }
    
    bcuCanEventData.fd = BCU_CAN_FD;
    bcuCanEventData.fun_handle = (void *)bcu_can_epoll_msg_transmit; // 回调函数
    ev.events = EPOLLIN;
    ev.data.ptr = (void *)&bcuCanEventData;
    if (-1 == my_epoll_addtast(bcuCanEventData.fd, &ev))
    {
        LOG("[BCU]%s add epoll failed \n", BCU_CAN_DEVICE_NAME);
        return false;
    }
#endif
    return true;
}


int Drv_bcu_can_send(CAN_MESSAGE *pFrame)
{
    struct can_frame can_frame;
    int retryCount = 0;
    const int maxRetries = 5;

    Convert_CAN_MESSAGE_to_can_frame(pFrame, &can_frame);
    while (retryCount < maxRetries)
    {
        if(BCU_CAN_FD <0){
            return;
        }
        if (HAL_can_write(BCU_CAN_FD, &can_frame))
        {
            return 0;
        }

        retryCount++;
    }
    if (retryCount >= maxRetries)//软件层面发送失败，系统的can底层有问题了
    {
        LOG("[BCU]%s retryCount error\r\n", BCU_CAN_DEVICE_NAME);
        Drv_can_auto_recover(BCU_CAN_DEVICE_NAME, BCU_CAN_BITRATE,&BCU_CAN_FD, bcu_can_epoll_msg_transmit);
        // Drv_bcu_resetcan_device(BCU_CAN_DEVICE_NAME);
    }

    return -1;
}

int Drv_bcu_canfd_send(CAN_FD_MESSAGE_BUS *pFrame)
{
    struct canfd_frame canfd_frame;
    int retryCount = 0;
    const int maxRetries = 5;
    Drv_write_to_active_buffer(&pFrame, 0); // 0709添加
    ConvertBusToCANFD(pFrame, &canfd_frame);

    while (retryCount < maxRetries)
    {
        if(BCU_CAN_FD <0){
            return;
        }
        if (HAL_canfd_write(BCU_CAN_FD, &canfd_frame))
        {
            return 0;
        }
        retryCount++;
    }
    if (retryCount >= maxRetries)
    {
        LOG("[BCUFD]%s retryCount error\r\n", BCU_CAN_DEVICE_NAME);
        Drv_can_auto_recover(BCU_CAN_DEVICE_NAME, BCU_CAN_BITRATE,&BCU_CAN_FD, bcu_can_epoll_msg_transmit);
        // Drv_bcu_resetcan_device(BCU_CAN_DEVICE_NAME);
    }
    return -1;
}

// 消息解析
bool Drv_BMS_Analysis(unsigned char can_flag)
{
    bool state = false;
    state = BMSAnalysis(can_flag);
    return state;
}



int bcu_can_check_state(void)
{ 
    printf("bcu_can_check_state in Drv_can_auto_recover\r\n");
    return Drv_can_auto_recover(BCU_CAN_DEVICE_NAME, BCU_CAN_BITRATE,
                           &BCU_CAN_FD, bcu_can_epoll_msg_transmit);
}


/**
 * @brief 重新绑定CAN接口（包含epoll管理）
 * @param can_name CAN设备名
 * @param bitrate CAN比特率
 * @param can_fd_ptr 指向CAN文件描述符的指针
 * @param callback CAN消息回调函数
 * @return 成功返回0，失败返回-1
 */
int Drv_can_bind_interface(const char *can_name, int bitrate, int *can_fd_ptr,
                           void (*callback)(void))
{
    LOG("[CAN]Rebinding %s interface...\n", can_name);

    // 1. 清理旧的epoll注册和文件描述符
    if (*can_fd_ptr > 0) 
    {
        struct epoll_event ev;
        my_epoll_deltast(*can_fd_ptr, &ev); // 从epoll中删除
        HAL_can_closeEx(can_fd_ptr);        // 关闭旧的CAN socket
        *can_fd_ptr = -1;
        LOG("[CAN]%s old resources cleaned\n", can_name);
    }

    // 2. 重启物理CAN接口,重新初始化CAN配置

    if (can_ifconfig_init(can_name, bitrate) == false) {
        LOG("[CAN]%s can_ifconfig_init failed\n", can_name);
        return -1;
    }

    // 3. 重新绑定CAN设备
    int retry_count = 0;
    const int max_retry = 5;
    
    while (can_band_init(can_name, can_fd_ptr) == false) {
        retry_count++;
        if (retry_count >= max_retry) {
            LOG("[CAN]%s can_band_init failed after %d retries\n", 
                can_name, max_retry);
            return -1;
        }
        LOG("[CAN]%s can_band_init failed, retrying %d/%d...\n", 
            can_name, retry_count, max_retry);
        sleep(1);
    }

    LOG("[CAN]%s rebound successfully, new fd: %d\n", can_name, *can_fd_ptr);


    // 4. 重新注册到epoll
    struct epoll_event ev;
    ev.events = EPOLLIN;


    if(can_name == BCU_CAN_DEVICE_NAME){
        bcuCanEventData.fd = *can_fd_ptr;  // 设置新的文件描述符
        bcuCanEventData.fun_handle = (void *)callback;  // 使用传入的回调函数
	    ev.data.ptr = (void *)&bcuCanEventData;
    }else if(can_name == BMU_CAN_DEVICE_NAME){
        bmuCanEventData.fd = *can_fd_ptr;  // 设置新的文件描述符
        bmuCanEventData.fun_handle = (void *)callback;  // 使用传入的回调函数
        ev.data.ptr = (void *)&bmuCanEventData;
    }

    if (-1 == my_epoll_addtast(*can_fd_ptr, &ev)) {
        LOG("[CAN]%s re-add to epoll failed\n", can_name);// 即使epoll注册失败，也不完全算失败，因为CAN已经重新绑定了     
        return -2;
    }

    LOG("[CAN]%s fully recovered and re-registered to epoll\n", can_name);
    return 0;
}



/**
 * @brief 检测并自动恢复CAN接口状态
 * @param can_name CAN设备名（如 "can2"）
 * @param bitrate CAN比特率
 * @param can_fd_ptr 指向CAN文件描述符的指针
 * @param callback CAN消息回调函数
 * @return 成功返回0，失败返回-1
 */
int Drv_can_auto_recover(const char *can_name, int bitrate, int *can_fd_ptr, 
                        void (*callback)(void))
{
    if (can_name == NULL || can_fd_ptr == NULL) {
        return -1;
    }

    // 加锁 - 确保同一时间只有一个任务执行恢复操作
    if (pthread_mutex_lock(&can_recover_mutex) != 0) {
        LOG("[CAN]%s Failed to acquire lock\n", can_name);
        return -1;
    }

    bool need_rebind = false;
    int canState = 0;
    int ret = -1;

    // 1. 检查物理链路状态
    if (!check_can_state(can_name)) 
    {
        LOG("[CAN]%s physical link is DOWN, need rebind\n", can_name);
        need_rebind = true;
    }
    // 2. 检查CAN控制器状态
    // else if (HAL_can_get_state(can_name, &canState) == 0) 
    // {
    //     if (canState != 0) 
    //     {
    //         /**  canState
    //          *  case 0x00: printf("状态: ERROR_ACTIVE (正常)\n"); break;
    //             case 0x01: printf("状态: ERROR_WARNING (警告)\n"); break;
    //             case 0x02: printf("状态: ERROR_PASSIVE (错误被动)\n"); break;//拔掉can总线0x02，不排除其他错误也会造成这个
    //             case 0x03: printf("状态: BUS_OFF (总线关闭)\n"); break;
    //             case 0x04: printf("状态: STOPPED (停止)\n"); break;
    //             case 0x05: printf("状态: SLEEPING (睡眠)\n"); break;
    //         */
    //         LOG("[CAN]%s controller state is abnormal: 0x%02X, need rebind\n", can_name, canState);
    //         need_rebind = true;
    //     } 
    //     else 
    //     {
    //         ret = 0;
    //         goto unlock; // 使用goto确保锁被释放
    //     }
    // }
    else 
    {
        LOG("[CAN]%s physical link is UP, not need rebind\n", can_name);
        ret = 0;
        goto unlock; // 使用goto确保锁被释放
        // 获取状态失败，也需要重新绑定
        // LOG("[CAN]%s failed to get controller state, need rebind\n", can_name);
        // need_rebind = true;
    }

    // 如果需要重新绑定
    if (need_rebind) 
    {
        ret = Drv_can_bind_interface(can_name, bitrate, can_fd_ptr, callback);
    }
unlock:
    // 确保锁被释放
    pthread_mutex_unlock(&can_recover_mutex);
    return ret;
}

int get_BCU_CAN_FD(void){
    return BCU_CAN_FD;
}