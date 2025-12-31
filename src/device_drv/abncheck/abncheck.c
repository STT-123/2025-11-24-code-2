#include <time.h>
#include <features.h>
#include "interface/log/log.h"
#include "interface/bms/bms_analysis.h"
#include "device_drv/abncheck/abncheck.h"
#include "device_drv/bcu_deal/bcu_deal.h"
#include "device_drv/bmu_deal/bmu_deal.h"
#include "device_drv/modbustcp_pro/modbustcp_pro.h"
#include "interface/globalVariable.h"
#include "interface/setting/ip_setting.h"
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"

#define _POSIX_C_SOURCE 199309L
#define RECOVER_REPORT_TIME 5000
#define FAULT_REPORT_TIME 3000
#define RECOVER_KM_DEFAULT_STATE 0 // 恢复接触器默认状态
#define RECOVER_KM_ACTION_STATE 1  // 恢复接触器动作状态

int PHY_RECOVER = 0;
int PHY_ERROR = 0;
uint8_t ECUState = 0;
int RECOVER = 0;
int ERROR = 0;

ecu_fault_t ecu_fault ={0};
ecu_fault_t ecu_fault_last = {0};
static int g_bcu_can_ready = 0;
static int g_bmu_can_ready = 0;
/*----------------------*/
struct timespec lasttimes ;
struct timespec lastCheckTick = {0};
time_t g_last_bcu_rx_time = 0;
/*--------------*/
static const fault_mapping_t fault_map_4H[] = {
    {23, EMERGENCY_STOP},//BCU急停
};

static const fault_mapping_t fault_map_3H[] = {
    {8, PCS_STOP},//外部急停(充电打桩)
    {9, ISO_SWITCH_FAULT},//隔开开关故障
    {10,DOOR_OPEN},//门禁故障
};

static const fault_mapping_t fault_map_2H[] = {
    {6, INSIDE_NTC_FAULT},//内部温度故障
    {7, OUTSIDE_COM_FAULT},//外部温度故障
};


void log_eror_csv(void)
{
	unsigned char log_flag = 0;
	static unsigned int BCU_FaultInfoLv1_LAST = 0;
	static unsigned int BCU_FaultInfoLv2_LAST = 0;
	static unsigned int BCU_FaultInfoLv3_LAST = 0;
	static unsigned int BCU_FaultInfoLv4_LAST = 0;
	static unsigned short BCU_SystemWorkMode_LAST = 0;

	if (ecu_fault_last.emcu_fault0 != ecu_fault.emcu_fault0)
	{
		log_flag = 1;
		ecu_fault_last.emcu_fault0 = ecu_fault.emcu_fault0;
	}
	if (ecu_fault_last.emcu_fault1 != ecu_fault.emcu_fault1)
	{
		log_flag = 1;
		ecu_fault_last.emcu_fault1 = ecu_fault.emcu_fault1;
	}
	if (ecu_fault_last.emcu_fault2 != ecu_fault.emcu_fault2)
	{
		log_flag = 1;
		ecu_fault_last.emcu_fault2 = ecu_fault.emcu_fault2;
	}

	if (ecu_fault_last.emcu_fault_state != ecu_fault.emcu_fault_state)
	{
		log_flag = 1;
		ecu_fault_last.emcu_fault_state = ecu_fault.emcu_fault_state;
	}
	if (BCU_SystemWorkMode_LAST != get_BCU_SystemWorkModeValue())
	{
		log_flag = 1;
		BCU_SystemWorkMode_LAST = get_BCU_SystemWorkModeValue();
	}

	if (BCU_FaultInfoLv1_LAST != get_BCU_FaultInfoLv1Value())
	{
		log_flag = 1;
		BCU_FaultInfoLv1_LAST = get_BCU_FaultInfoLv1Value();
	}

	if (BCU_FaultInfoLv2_LAST != get_BCU_FaultInfoLv2Value())
	{
		log_flag = 1;
		BCU_FaultInfoLv2_LAST = get_BCU_FaultInfoLv2Value();
	}

	if (BCU_FaultInfoLv3_LAST != get_BCU_FaultInfoLv3Value())
	{
		log_flag = 1;
		BCU_FaultInfoLv3_LAST = get_BCU_FaultInfoLv3Value();
	}

	if (BCU_FaultInfoLv4_LAST != get_BCU_FaultInfoLv4Value())
	{
		log_flag = 1;
		BCU_FaultInfoLv4_LAST = get_BCU_FaultInfoLv4Value();
	}

	if (log_flag == 1)
	{
		LOG_CSV("[LOG_CSV] = %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x",
			ecu_fault.emcu_fault0,
			ecu_fault.emcu_fault1,
			ecu_fault.emcu_fault2,
			ecu_fault.emcu_fault3,
			get_BCU_FaultInfoLv1Value(),
			get_BCU_FaultInfoLv2Value(),
			get_BCU_FaultInfoLv3Value(),
			get_BCU_FaultInfoLv4Value(),
			get_BCU_SOCValue(),
			get_BCU_SystemWorkModeValue());
	}
}


int CheckSinglePHYStatus(const char *ifname)
{
	FILE *fp;
	char line[512];
	char devname[32];
	net_stats_t stats = {0};
	static net_stats_t last_stats[2] = {0}; // 简单缓存上次统计
	static int initialized = 0;

	fp = fopen("/proc/net/dev", "r");
	if (!fp)
	{
		perror("fopen /proc/net/dev failed");
		return 0; // 没有
	}

	// 跳过前两行标题
	fgets(line, sizeof(line), fp);
	fgets(line, sizeof(line), fp);

	while (fgets(line, sizeof(line), fp))
	{
		// 解析接口统计信息
		if (sscanf(line, "%31[^:]: %llu %llu %*u %*u %*u %*u %*u %*u %llu %llu",
				   devname, &stats.rx_bytes, &stats.rx_packets,
				   &stats.tx_bytes, &stats.tx_packets) >= 4)
		{

			// 去除接口名末尾的空格
			char *p = devname;
			while (*p == ' ')
				p++;

			if (strcmp(p, ifname) == 0)
			{
				fclose(fp);

				// 检查是否有数据活动
				int has_traffic = 0;

				if (initialized)
				{
					// 比较当前统计和上次统计
					net_stats_t *last = &last_stats[strcmp(ifname, "eth0") == 0 ? 0 : 1];
					if (stats.rx_bytes > last->rx_bytes ||
						stats.tx_bytes > last->tx_bytes ||
						stats.rx_packets > last->rx_packets ||
						stats.tx_packets > last->tx_packets)
					{
						has_traffic = 1;
					}
				}

				// 更新缓存
				net_stats_t *last = &last_stats[strcmp(ifname, "eth0") == 0 ? 0 : 1];
				*last = stats;
				initialized = 1;

				return has_traffic;
			}
		}
	}

	fclose(fp);
	return 0; // 接口未找到
}

void PHYlinktate()
{
	static struct timespec lastCheckTick = {0};
	clock_gettime(CLOCK_MONOTONIC, &lastCheckTick); // 记录lastCheckTick初始时间
	static int PHY_RECOVER_FLAG = 0;
	static int PHY_ERROR_FLAG = 0;

	int eth1_status = 0;

	// 检查eth1
	eth1_status = CheckSinglePHYStatus(NET_ETH_1);//检测网线是否物理连接上

	// LOG("TTTTTTTTTTTTTTTTT eth0_status = %d,  eth1_status=%d ", eth0_status, eth1_status);
	// eth1_status = 1;

	if (eth1_status) // 连接
	{
		if (PHY_RECOVER_FLAG == 1)
		{
			if (GetTimeDifference_ms(lastCheckTick) >= RECOVER_REPORT_TIME)
			{
				set_emcu_fault(PHY_LINK_FAULT, SET_RECOVER);
				PHY_ERROR_FLAG = 0;
			}
		}
		else
		{
			clock_gettime(CLOCK_MONOTONIC, &lastCheckTick);
			PHY_RECOVER_FLAG = 1;
			PHY_ERROR_FLAG = 0;
		}
	}
	else // 未连接就报故障
	{
		if (PHY_ERROR_FLAG == 1)
		{
			if (GetTimeDifference_ms(lastCheckTick) >= FAULT_REPORT_TIME)
			{
				set_emcu_fault(PHY_LINK_FAULT, SET_ERROR);
				PHY_RECOVER_FLAG = 0;
			}
		}
		else
		{
			clock_gettime(CLOCK_MONOTONIC, &lastCheckTick);
			PHY_ERROR_FLAG = 1;
			PHY_RECOVER_FLAG = 0;
		}
	}
}


void ECUfault_process()
{
	int temp = 0;
	set_modbus_reg_val(MDBUS_ADDR_BECU_FAULT0, ecu_fault.emcu_fault0);
	set_modbus_reg_val(MDBUS_ADDR_BECU_FAULT1, ecu_fault.emcu_fault1);
	set_modbus_reg_val(MDBUS_ADDR_BECU_FAULT2, ecu_fault.emcu_fault2);
	set_modbus_reg_val(MDBUS_ADDR_BECU_FAULT3, ecu_fault.emcu_fault3);

	// printf("MDBUS_ADDR_BECU_FAULT0 = 0x%x\r\n",ecu_fault.emcu_fault0);
	// printf("MDBUS_ADDR_BECU_FAULT0 = 0x%x\r\n",ecu_fault.emcu_fault1);
	// printf("MDBUS_ADDR_BECU_FAULT0 = 0x%x\r\n",ecu_fault.emcu_fault2);
	// printf("MDBUS_ADDR_BECU_FAULT0 = 0x%x\r\n",ecu_fault.emcu_fault3);

	// get_modbus_reg_val(MDBUS_ADDR_BECU_FAULT0, &temp);
	// printf("MDBUS_ADDR_BECU_FAULT0 = 0x%x\r\n",temp);
	// get_modbus_reg_val(MDBUS_ADDR_BECU_FAULT1, &temp);
	// printf("MDBUS_ADDR_BECU_FAULT1 = 0x%x\r\n",temp);
	// get_modbus_reg_val(MDBUS_ADDR_BECU_FAULT2, &temp);
	// printf("MDBUS_ADDR_BECU_FAULT2 = 0x%x\r\n",temp);
	// get_modbus_reg_val(MDBUS_ADDR_BECU_FAULT3, &temp);
	// printf("MDBUS_ADDR_BECU_FAULT3 = 0x%x\r\n",temp);
}


/********************************************************************************
 *
 * 输入参数：
 *                      unsigned int parameter   参数 //詳見fault_intaface.h
 *                      unsigned char status        分机的状态 1 0
 * 			无
 * 输出参数：无
 ********************************************************************************/
void set_emcu_fault(unsigned char parameter, unsigned char status)
{

	unsigned char byte_num = (parameter & 0xf0) >> 4; // 高4位字节号
	unsigned short bit_num = (parameter & 0x0F);	  //  低4位bit位

	switch (byte_num)
	{
	case 0:
		if (status)
		{
			ecu_fault.emcu_fault0 &= ~(1 << bit_num);
		}
		else
		{
			ecu_fault.emcu_fault0 |= (1 << bit_num);
		}
		break;
	case 1:
		if (status)
		{
			ecu_fault.emcu_fault1 &= ~(1 << bit_num);
		}
		else
		{
			ecu_fault.emcu_fault1 |= (1 << bit_num);
		}
		break;
	case 2:
		if (status)
		{
			ecu_fault.emcu_fault2 &= ~(1 << bit_num);
		}
		else
		{
			ecu_fault.emcu_fault2 |= (1 << bit_num);
			
		}
		break;
	case 3:
		if (status)
		{
			ecu_fault.emcu_fault3 &= ~(1 << bit_num);
		}
		else
		{
			ecu_fault.emcu_fault3 |= (1 << bit_num);
		}
		break;
	default:
		break;
	}
	if (ecu_fault.emcu_fault0 + ecu_fault.emcu_fault1 + ecu_fault.emcu_fault2)
	{
		ecu_fault.emcu_fault_state = 1;
	}
	else
	{
		ecu_fault.emcu_fault_state = 0;
	}
}

/**
 * 检测BCU的通信是否超时函数
*/
void check_bcu_rx_timeout(void)
{
	static bool can0_fault_reported = false;
	time_t current_time;
	time(&current_time);
	double diff = difftime(current_time, g_last_bcu_rx_time);

	if (diff >= 5.0)
	{
		if (!can0_fault_reported)
		{
			set_emcu_fault(BMS_COM_FAULT, SET_ERROR);
			can0_fault_reported = true;
			LOG("CAN0 TimeoutCheck warning\n");
		}
	}
	else
	{
		if (can0_fault_reported)
		{
			set_emcu_fault(BMS_COM_FAULT, SET_RECOVER);
			can0_fault_reported = false;
			LOG("CAN0 TimeoutCheckv normal\n");
		}
	}
}

/**
 * 检测CAN 是否异常函数
*/
int can_monitor_fun(void) {
	int bcu_can_state = check_can_state(BCU_CAN_DEVICE_NAME);//检测到LOWER_UP，则g_bcu_can_ready为1。
	if (bcu_can_state == 0 && g_bcu_can_ready == 1) {
		LOG("[Check] can2 abnormal, restarting...\n");
		restart_can_interface(BCU_CAN_DEVICE_NAME);
		
	}
	g_bcu_can_ready = bcu_can_state;

	// 检查 can3
	int bmu_can_state = check_can_state(BMU_CAN_DEVICE_NAME);
	if (bmu_can_state == 0 && g_bmu_can_ready == 1) {
		LOG("[Check] can3 abnormal, restarting...\n");
		restart_can_interface(BMU_CAN_DEVICE_NAME);
	}
	g_bmu_can_ready = bmu_can_state;
}

// 重启CAN接口
static void restart_can_interface(const char* can_if) {
    LOG("[Check] Restarting %s...\n", can_if);
    char cmd[128];
    
    snprintf(cmd, sizeof(cmd), "sudo /bin/ip link set %s down", can_if);
    system(cmd);
    usleep(100000);
    
    snprintf(cmd, sizeof(cmd), "sudo /bin/ip link set %s up", can_if);
    system(cmd);
    usleep(500000);
}

// 检查单个CAN接口状态
int check_can_state(const char* can_if) {
    char command[128];
    snprintf(command, sizeof(command), 
             "/bin/ip link show %s 2>/dev/null | grep -q 'LOWER_UP'", can_if);
    return (system(command) == 0);
}

int is_can_healthy(const char* can_if) {
    char cmd[256];
    char result[512];
    FILE *fp;
    
    // 检查接口是否存在且UP
    snprintf(cmd, sizeof(cmd), 
             "/bin/ip link show %s 2>/dev/null | grep 'state UP' > /dev/null && "
             "/bin/ip link show %s 2>/dev/null | grep 'LOWER_UP' > /dev/null", 
             can_if, can_if);
    if (system(cmd) != 0) {
        LOG("[CAN] %s: Interface not up\n", can_if);
        // return 0;
    }
    
    // 检查是否有严重错误状态
    snprintf(cmd, sizeof(cmd),
             "/bin/ip -details link show %s 2>/dev/null | "
             "grep -q -E 'BUS-OFF|ERROR-PASSIVE'",
             can_if);
    if (system(cmd) == 0) {
        LOG("[CAN] %s: BUS-OFF or ERROR-PASSIVE\n", can_if);
        return 0;
    }
    
    // 检查错误计数器
    snprintf(cmd, sizeof(cmd),
             "/bin/ip -details link show %s 2>/dev/null | "
             "grep 'berr-counter' | awk '{print $4}'",
             can_if);
    
    fp = popen(cmd, "r");
    if (fp) {
        if (fgets(result, sizeof(result), fp)) {
            int tx_errors = atoi(result);
            if (tx_errors > 95) {  // 接近错误被动阈值
                LOG("[CAN] %s: TX errors too high (%d)\n", can_if, tx_errors);
                pclose(fp);
                return 0;
            }
        }
        pclose(fp);
    }
    
    // 检查是否启用了FD模式（可选）
    snprintf(cmd, sizeof(cmd),
             "/bin/ip -details link show %s 2>/dev/null | "
             "grep -q ' fd '",
             can_if);
    if (system(cmd) != 0) {
        LOG("[CAN] %s: FD mode not enabled\n", can_if);
        // 根据你的需求决定是否返回0
    }
    
    return 1;  // 健康
}
// 主业务判断函数
int is_bcu_can_ready(void) {
    return g_bcu_can_ready;
}
int is_bmu_can_ready(void) {
    return g_bmu_can_ready;
}


void get_BCU_FaultInfo(uint32_T faultValue_4H, uint32_T faultValue_3H,uint32_T faultValue_2H)
{
    unsigned int i = 0;
    //故障映射，新增故障只需要更改fault_map_4H
	// printf("faultValue_4H = %x\n", faultValue_4H);
    // printf("faultValue_3H = %x\n", faultValue_3H);
    // printf("faultValue_2H = %x\n", faultValue_2H);
    for ( i = 0; i < sizeof(fault_map_4H)/sizeof(fault_map_4H[0]); i++) 
    {
        if (faultValue_4H & (1UL << fault_map_4H[i].bit_position))
        {
            set_emcu_fault(fault_map_4H[i].fault_type, SET_ERROR);
        } 
        else 
        {
            set_emcu_fault(fault_map_4H[i].fault_type, SET_RECOVER);
        }
    }
    //故障映射，新增故障只需要更改fault_map_3H
    for ( i = 0; i < sizeof(fault_map_3H)/sizeof(fault_map_3H[0]); i++) 
    {
        if (faultValue_3H & (1UL << fault_map_3H[i].bit_position))
        {
            set_emcu_fault(fault_map_3H[i].fault_type, SET_ERROR);
        } 
        else 
        {
            set_emcu_fault(fault_map_3H[i].fault_type, SET_RECOVER);
        }
    }
    
    //故障映射，新增故障只需要更改fault_map_2H
    for ( i = 0; i < sizeof(fault_map_2H)/sizeof(fault_map_2H[0]); i++) 
    {
        if (faultValue_2H & (1UL << fault_map_2H[i].bit_position))
        {
            set_emcu_fault(fault_map_2H[i].fault_type, SET_ERROR);
        } 
        else 
        {
            set_emcu_fault(fault_map_2H[i].fault_type, SET_RECOVER);
        }
    }
}
/**
 * @brief 检测是否能ping通指定主机
 * @param hostname 主机名或IP地址
 * @param timeout_sec 超时时间（秒）
 * @return 1: 可ping通, 0: 不可ping通, -1: 执行错误
 */
int can_ping_host(const char *hostname, int timeout_sec) {
    if (!hostname || strlen(hostname) == 0) {
        fprintf(stderr, "Error: Invalid hostname\n");
        return -1;
    }
    
    char cmd[256];
    // 使用-c参数指定ping次数，-W参数指定超时时间
    snprintf(cmd, sizeof(cmd), "ping -c 1 -W %d %s > /dev/null 2>&1", 
             timeout_sec, hostname);
    
    LOG("[Network] Testing connectivity to %s...\n", hostname);
    
    int ret = system(cmd);
    
    if (ret == 0) {
        LOG("[Network] %s is reachable\n", hostname);
        return 1;
    } else {
        LOG("[Network] %s is NOT reachable (exit code: %d)\n", hostname, WEXITSTATUS(ret));
        return 0;
    }
}
int check_and_fix_ip(const char *if_name)
{
	unsigned char expected_ip[16] = IP_ADDRESS;//

    char command[256];
    FILE *fp;
    char buffer[1024];
    char current_ip[16] = {0};
    int need_fix = 1;
    
    //LOG("[IP自动修复] 检查接口 %s 的IP状态\n", if_name);
    
    // 检测当前IP
    snprintf(command, sizeof(command), 
             "ip -4 addr show %s 2>/dev/null | grep -oE '([0-9]{1,3}\\.){3}[0-9]{1,3}/' | head -1 | sed 's|/||'", 
             if_name);
    
    fp = popen(command, "r");
    if (fp != NULL) {
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
            char *trimmed = buffer;
            while (*trimmed == ' ') trimmed++;
            
            if (strlen(trimmed) > 0) {
                strncpy(current_ip, trimmed, sizeof(current_ip) - 1);
                
                if (strcmp(current_ip, expected_ip) == 0) {
                    need_fix = 0;
                }
            }
        }
        pclose(fp);
    }
    
    // 如果需要修复
    if (need_fix) {

		// 打印当前不正确的IP
		if (strlen(current_ip) > 0) {
			LOG("[IP] The current IP address is incorrect: %s, Expected IP: %s\n", current_ip, expected_ip);
		} else {
			LOG("[IP] Current IP not detected, expected IP: %s\n", expected_ip);
		}
        LOG("[IP] IP incorrect, start modifying...\n");

        if (g_ipsetting.flag == 1 && g_ipsetting.ip != 0)// 创建modbus服务端
		{
			sprintf(expected_ip, "%d.%d.%d.%d", (g_ipsetting.ip >> 24) & 0xFF, (g_ipsetting.ip >> 16) & 0xFF, (g_ipsetting.ip >> 8) & 0xFF, g_ipsetting.ip & 0xFF);
		}

        // 调用set_ip_address函数修改IP
        int ret = set_ip_address(if_name, expected_ip);
        if (ret == 0) {
            LOG("[IP] IP modification successful\n");
            
            // 修改后验证
            sleep(2);
            memset(current_ip, 0, sizeof(current_ip));
            snprintf(command, sizeof(command), 
                     "ip -4 addr show %s 2>/dev/null | grep -oE '([0-9]{1,3}\\.){3}[0-9]{1,3}/' | head -1 | sed 's|/||'", 
                     if_name);
            
            fp = popen(command, "r");
            if (fp != NULL && fgets(buffer, sizeof(buffer), fp) != NULL) {
                buffer[strcspn(buffer, "\n")] = 0;
                char *trimmed = buffer;
                while (*trimmed == ' ') trimmed++;
                
                if (strlen(trimmed) > 0) {
                    strncpy(current_ip, trimmed, sizeof(current_ip) - 1);
                    if (strcmp(current_ip, expected_ip) == 0) {
                        LOG("[IP] Verified successfully after modification\n");
                        return 0;
                    } else {
                        LOG("[IP] Verification failed after modification. Current IP address: %s\n", current_ip);
                        return -1;
                    }
                }
            }
            pclose(fp);
            
            LOG("[IP] Modified successfully but unable to verify\n");
            return 0;
        } else {
            LOG("[IP] IP modification failed\n");
            return -1;
        }
    }
    
    return 0; // IP正确，无需修改
}