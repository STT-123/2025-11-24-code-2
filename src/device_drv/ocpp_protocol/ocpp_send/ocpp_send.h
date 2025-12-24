#ifndef __OCPP_SEND_H__
#define __OCPP_SEND_H__
#include <sqlite3.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"
#include "batdata.h"
#include "ocpp_messages.h"
#include "interface/log/log.h"

void update_bat_data(sqlite3 *db);
// void update_bat_data(void);
void *websocket_send_thread(void *arg);
#endif