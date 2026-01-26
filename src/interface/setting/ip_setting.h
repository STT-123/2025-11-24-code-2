#ifndef __IP_SETTING_H
#define __IP_SETTING_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include "stdbool.h"
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h> // stat()
#include <sys/socket.h>
#include <sys/ioctl.h>
// #include <linux/if.h>     
#include <net/if.h>          // 这个头文件包含 struct ifreq 的定义
#include <arpa/inet.h> // for inet_ntoa etc.
#include <netinet/in.h>
#include <errno.h>
#include "interface/log/log.h"

#define MODBUS_ETH_NUM  "eth1"
#define IP_ADDRESS  	"192.168.1.110"
#define CONFIG_FILE_PATH "setting.conf"
typedef struct
{
	uint8_t flag;
	uint32_t ip;

} Setting_t;
extern Setting_t g_ipsetting;

void settings_Init();
void save_ip_to_conffile(uint16_t address, uint16_t data);
void set_system_time_from_bcu(void);
int set_ip_address(const char *if_name, const char *ip_addr);
int load_setting_from_file(const char *filepath, Setting_t *ipsetting);
#endif