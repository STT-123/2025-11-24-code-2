#ifndef __C_BMSANALYSIS_H__
#define __C_BMSANALYSIS_H__

#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <linux/can/error.h>
#include <linux/can.h>
#include <stdint.h>
#include "bms_simulink/rtwtypes.h"
#include "bms_simulink/CANFDRcvFcn_BCU_types.h"
#include "bms_simulink/CANRcvFcn_BMU_types.h"
#include "interface/bms/bms_simulink/can_fd_message.h"
#include "interface/bms/bms_simulink/can_message.h"
#define BMS_POWER_ON 0x01
#define BMS_POWER_OFF 0x02
#define BMS_POWER_URGENCY_OFF 0x04
#define BMS_POWER_UPDATING 0x05
#define BMS_POWER_DEFAULT 0x00

// 定义缓冲区大小
#define DATA_BUFFER_SIZE 10


// CAN数据帧缓冲区结构
// 改进的缓冲区结构（保持顺序）
typedef struct {
    CAN_FD_MESSAGE frames[DATA_BUFFER_SIZE];  // 存储帧数据
    int start;                // 最老数据的起始位置
    int end;                  // 最新数据的结束位置（下一个写入位置）
    int count;                // 实际存储的帧数
    int is_full;              // 缓冲区是否已满
} CanDataBuffer;


// 变化后缓冲区（专门存储变化后的10帧）
typedef struct {
    CAN_FD_MESSAGE frames[DATA_BUFFER_SIZE];
    int count;
    int is_collecting;  // 是否正在收集
    int collected_count; // 已收集的帧数
} PostChangeBuffer;

// 1. 在Log_Bcu_Data函数外部定义指令跟踪结构
typedef struct {
    int is_cmd_tracking;           // 是否正在跟踪指令
    int pre_frames_collected;      // 已收集的指令前帧数
    CAN_FD_MESSAGE pre_frames[DATA_BUFFER_SIZE];  // 指令前数据
    int post_frames_collected;     // 已收集的指令后帧数
    CAN_FD_MESSAGE post_frames[DATA_BUFFER_SIZE]; // 指令后数据
} CommandTracking;



void Set_BCU_Voltage(float voltage);

void Set_BCU_Current(float current);

void Set_BCU_Power(int32_t power_watt);

void Set_BCU_PositiveEnergy(float energy_wh);

void Set_BCU_NegativeEnergy(float energy_wh);

void set_OTA_XCPConnect(uint8_T value);
uint8_T get_OTA_XCPConnect(void);

void set_TCU_ACMuteSet(uint8_T value);
uint8_T get_TCU_ACMuteSet(void);

void set_TCU_BCUEINSet(uint32_T value);
uint32_T get_TCU_BCUEINSet(void);

void set_TCU_ChargerWorkSts(uint8_T value);
uint8_T get_TCU_ChargerWorkSts(void);

// void set_TCU_ClearFault(real_T value);
// real_T get_TCU_ClearFault(void);

void set_TCU_ECOMode(uint8_T value);
uint8_T get_TCU_ECOMode(void);

// void set_TCU_GetTime(real_T value);
// real_T get_TCU_GetTime(void);

void set_TCU_LifeCounter(uint8_T value);
uint8_T get_TCU_LifeCounter(void);

void set_TCU_PowerUpCmd(uint8_T value);
uint8_T get_TCU_PowerUpCmd(void);

void set_TCU_TimeCalFlg(uint8_T value);
uint8_T get_TCU_TimeCalFlg(void);

void set_TCU_TimeDay(uint8_T value);
uint8_T get_TCU_TimeDay(void);

void set_TCU_TimeHour(uint8_T value);
uint8_T get_TCU_TimeHour(void);

void set_TCU_TimeMinute(uint8_T value);
uint8_T get_TCU_TimeMinute(void);

void set_TCU_TimeMonth(uint8_T value);
uint8_T get_TCU_TimeMonth(void);

void set_TCU_TimeSecond(uint8_T value);
uint8_T get_TCU_TimeSecond(void);

void set_TCU_TimeWeek(uint8_T value);
uint8_T get_TCU_TimeWeek(void);

void set_TCU_TimeYear(uint8_T value);
uint8_T get_TCU_TimeYear(void);

void set_TCU_FcnStopSet(uint8_T value) ;
void set_TCU_HighVoltType(uint8_T value) ;
void set_TCU_HighVoltValue(uint16_T value) ;

uint8_T get_BCU_TimeYearValue(void) ;
uint8_T get_BCU_TimeMonthValue(void) ;
uint8_T get_BCU_TimeDayValue(void) ;
uint8_T get_BCU_TimeHourValue(void) ;
uint8_T get_BCU_TimeMinuteValue(void) ;
uint8_T get_BCU_TimeSencondValue(void) ;

uint32_T get_BCU_FaultInfoLv1Value(void) ;
uint32_T get_BCU_FaultInfoLv2Value(void) ;
uint32_T get_BCU_FaultInfoLv3Value(void) ;
uint32_T get_BCU_FaultInfoLv4Value(void) ;
uint16_T get_BCU_SOCValue(void) ;
uint16_T get_BCU_SystemWorkModeValue(void) ;

void ConvertCANFDToBus(struct canfd_frame *frame, CAN_FD_MESSAGE_BUS *msg);
void ConvertCANToBus(const struct can_frame *frame, CAN_FD_MESSAGE_BUS *msg);

void ConvertBusToCANFD(const CAN_FD_MESSAGE_BUS *msg, struct canfd_frame *frame);
void Convert_CAN_MESSAGE_to_can_frame(const CAN_MESSAGE *msg, struct can_frame *frame);
void Convert_canfd_frame_to_CAN_MESSAGE(const struct canfd_frame *frame, CAN_MESSAGE *msg);
void Convert_can_frame_to_CAN_MESSAGE(const struct can_frame *frame, CAN_MESSAGE *msg);

void Convert_canfd_frame_to_can_fram(const struct canfd_frame *frame, struct can_frame *msg);

uint16_T *get_BCU_usSingleBatVal(void) ;
uint16_T *get_BCU_usSingleBatTemp(void) ;
uint16_T *get_BMU_DAq_version(void);
uint32_T get_BMU_DAqX_FaultCode1_at(int idx);
uint32_T get_BMU_DAqX_FaultCode2_at(int idx);
int32_T get_BCU_iDcPower(void);
unsigned long long get_BCU_ullPosEleQuantity(void) ;
unsigned long long get_BCU_ullNegEleQuantity(void) ;

uint16_T get_BCU_usAirState(void);
uint16_T get_BCU_usAirPumpState(void);
uint16_T get_BCU_usAirCompressorSt(void);
uint16_T get_BCU_uiAirErrorfaultCode(void);

uint16_T get_usBmuH2MaxConcentration(void);
uint16_T get_usBmuCOMaxConcentration(void);
uint16_T get_usBmuPressureMax(void);
uint16_T get_usBmuLightMax(void);
uint16_T get_usBmuH2MaxIndex(void);
uint16_T get_usBmuCOMaxIndex(void);
uint16_T get_usBmuPressureMaxIndex(void);
uint16_T get_usBmuLightMaxIndex(void);
uint16_T get_usAirEnergyMode(void);

uint16_T get_usAirInletPressure();
uint16_T get_usAirCoolSetTemp();
uint16_T get_usAirOutWaterTemp();
uint16_T get_usAirReturnWaterTemp();

uint16_T get_usBatMaxVoltCellIndex();
uint16_T get_usBatMinVoltCellIndex();
uint16_T get_usBatMaxTempCellIndex();
uint16_T get_usBatMinTempCellIndex();
uint16_T get_usBatCellVoltMax();
uint16_T get_usBatCellVoltMin();
uint16_T get_usBatCellTempMax();
uint16_T get_usBatCellTempMin();
void Log_TCU_Data(void);
void Log_Bcu_Data(const CAN_FD_MESSAGE *msg);
/*========================================*/
void init_can_buffer(void);
static void add_to_can_buffer(const CAN_FD_MESSAGE *msg);
static void start_command_tracking(void);
static void save_pre_command_frames(void);
static void complete_command_tracking_internal(void);

#endif