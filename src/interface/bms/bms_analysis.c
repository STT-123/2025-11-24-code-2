#include <arpa/inet.h> // htonl
#include <byteswap.h>  // bswap_16, bswap_32
#include "bms_analysis.h"
#include "interface/modbus/modbus_defines.h"
#include "interface/bms/bms_simulink/CANSendFcn.h"
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"


void my_modbus_set_float_badc(float f, uint16_t *dest)
{
    uint32_t i;

    memcpy(&i, &f, sizeof(uint32_t));
    i = htonl(i);
    dest[0] = (uint16_t)bswap_16(i >> 16);
    dest[1] = (uint16_t)bswap_16(i & 0xFFFF);
}

/**
 * 将标准 can_frame 转换为 CAN_FD_MESSAGE_BUS
 * 由于Matlab的输入只有一个CAN_FD_MESSAGE_BUS类型的，所以只能这么转换
 */
void ConvertCANToBus(const struct can_frame *frame, CAN_FD_MESSAGE_BUS *msg)
{
    if (!frame || !msg){
        printf("eeee Raw can_id      : 0x%08lX\n", frame->can_id);
        return;

    }
    msg->Extended = 1;
    msg->Remote = 0;
    msg->Error = 0;
    msg->Length = frame->can_dlc;
    // printf("Raw can_id      : 0x%08lX\n", frame->can_id);
    // printf("Extended    : %d\n", (frame->can_id & CAN_EFF_FLAG) ? 1 : 0);
    // printf(" frame->can_id : %08lX\r\n", frame->can_id);
    msg->ID = frame->can_id; // 取 29 位
    // printf(" msg->ID  : %08lX\r\n", msg->ID );
    msg->Timestamp = 0;

    memcpy(msg->Data, frame->data, frame->can_dlc);
}

void ConvertCANFDToBus(struct canfd_frame *frame, CAN_FD_MESSAGE_BUS *msg)
{
    if (!frame || !msg)
        return;
    
    msg->ID = frame->can_id & CAN_EFF_MASK;// 提取 ID，去掉扩展/远程/错误标志位
    msg->ProtocolMode = 1; // 1 表示 CAN FD
    msg->Extended = 1;
    msg->Remote = 0;
    msg->Error = 0;
    msg->BRS = 0;
    msg->ESI = 0;
    msg->Length = frame->len;
    msg->DLC = frame->len;
    msg->Reserved = 0;
    msg->Timestamp = 0;
    memcpy(msg->Data, frame->data, frame->len);
}

void ConvertBusToCANFD(const CAN_FD_MESSAGE_BUS *msg, struct canfd_frame *frame)
{
    if (!msg || !frame)
        return;

    // 清空目标结构体
    memset(frame, 0, sizeof(*frame));

    // 设置 CAN ID 和标志位
    frame->can_id = msg->ID;
    // 添加扩展帧标志（EFF）
    if (msg->Extended)
    {
        frame->can_id |= CAN_EFF_FLAG;
    }

    // 添加远程帧标志（RTR）
    if (msg->Remote)
    {
        frame->can_id |= CAN_RTR_FLAG;
    }

    // 添加错误帧标志（ERR）
    if (msg->Error)
    {
        frame->can_id |= CAN_ERR_FLAG;
    }

    // 设置数据长度
    frame->len = msg->Length;// 设置 CAN FD 特有标志（BRS 和 ESI）
    
    frame->flags = 0;
    if (msg->BRS)
    {
        frame->flags |= CANFD_BRS;
    }
    if (msg->ESI)
    {
        frame->flags |= CANFD_ESI;// canfd 的错误帧状态
    }
    memcpy(frame->data, msg->Data, msg->Length);

}

void Convert_CAN_MESSAGE_to_can_frame(const CAN_MESSAGE *msg, struct can_frame *frame)
{

    memset(frame, 0, sizeof(struct can_frame));

    frame->can_id = msg->ID;

    if (msg->Extended)
    {
        frame->can_id |= CAN_EFF_FLAG;
    }

    if (msg->Remote)
    {
        frame->can_id |= CAN_RTR_FLAG;
    }

    if (msg->Error)
    {
        frame->can_id |= CAN_ERR_FLAG;
    }

    if (msg->Length <= 8)
    {
        frame->can_dlc = msg->Length;
    }
    else
    {
        frame->can_dlc = 8;
    }

    memcpy(frame->data, msg->Data, frame->can_dlc);
}

void Convert_canfd_frame_to_CAN_MESSAGE(const struct canfd_frame *frame, CAN_MESSAGE *msg)
{
    memset(msg, 0, sizeof(CAN_MESSAGE));
    msg->ID = frame->can_id & CAN_EFF_MASK;// 提取 CAN ID

    msg->Extended = 1;
    msg->Remote = 0;
    msg->Error = 0;

    msg->Length = (frame->len > 8) ? 8 : frame->len;

    msg->Timestamp = 0;

    // 拷贝数据
    memcpy(msg->Data, frame->data, msg->Length);
}

void Convert_canfd_frame_to_can_fram(const struct canfd_frame *frame, struct can_frame *msg)
{
    memset(msg, 0, sizeof(struct can_frame));
    msg->can_id = frame->can_id & CAN_EFF_MASK;// 提取 CAN ID

    msg->__res0 = 0;
    msg->__pad = 0;
    msg->__res1 = 0;

    msg->can_dlc = (frame->len > 8) ? 8 : frame->len;

    // 拷贝数据
    memcpy(msg->data, frame->data, msg->can_dlc);
}

void Convert_can_frame_to_CAN_MESSAGE(const struct can_frame *frame, CAN_MESSAGE *msg)
{
    memset(msg, 0, sizeof(CAN_MESSAGE)); 
    msg->ID = frame->can_id & CAN_EFF_MASK;// 提取 ID，去掉扩展/远程/错误标志位

    msg->Extended = 1;
    msg->Remote = 0;
    msg->Error = 0;

    // 数据长度控制在 0~8 之间
    if (frame->can_dlc <= 8)
    {
        msg->Length = frame->can_dlc;
    }
    else
    {
        msg->Length = 8;
    }

    memcpy(msg->Data, frame->data, frame->can_dlc);

#ifndef TIMESTAMP_NOT_REQUIRED
    // 如果定义了时间戳字段，初始化为 0.0（无实际来源）
    msg->Timestamp = 0.0;
#endif
}



void Set_BCU_Voltage(float voltage)
{
    uint16_t temp[2] = {0};
    // printf("voltage: %f\n", voltage);
    float adjusted_voltage = voltage;
    my_modbus_set_float_badc(adjusted_voltage, temp);
    set_modbus_reg_val(MDBUS_ADDR_DC_VOL, temp[0]);
    set_modbus_reg_val(MDBUS_ADDR_DC_VOL + 1, temp[1]);
}

void Set_BCU_Current(float current)
{
    uint16_t temp[2] = {0};
    // printf("current: %f\n", current);
    float adjusted_current = current;
    my_modbus_set_float_badc(adjusted_current, temp);
    set_modbus_reg_val(MDBUS_ADDR_DC_CUR, temp[0]);
    set_modbus_reg_val(MDBUS_ADDR_DC_CUR + 1, temp[1]);
}

void Set_BCU_Power(int32_t power_watt)
{
    // float power_kw = (float)power_watt / 1000.0f;
    // printf("power_watt: %f\n", power_watt);
    uint16_t temp[2] = {0};
    my_modbus_set_float_badc(power_watt, temp);
    set_modbus_reg_val(MDBUS_ADDR_DC_POW, temp[0]);
    set_modbus_reg_val(MDBUS_ADDR_DC_POW + 1, temp[1]);
}

void Set_BCU_PositiveEnergy(float energy_wh)
{
    uint32_t energy_mwh = energy_wh * 1000;
    // printf("energy_mwh: %d\n", energy_mwh);
    set_modbus_reg_val(MDBUS_ADDR_P_ENERGY, energy_mwh & 0xFFFF);
    set_modbus_reg_val(MDBUS_ADDR_P_ENERGY + 1, energy_mwh >> 16);
}

void Set_BCU_NegativeEnergy(float energy_wh)
{
    uint32_t energy_mwh = energy_wh * 1000;
    // printf("energy_mwh: %d\n", energy_mwh);
    set_modbus_reg_val(MDBUS_ADDR_N_ENERGY, energy_mwh & 0xFFFF);
    set_modbus_reg_val(MDBUS_ADDR_N_ENERGY + 1, energy_mwh >> 16);
}

void set_OTA_XCPConnect(real_T value) { OTA_XCPConnect = value; }
real_T get_OTA_XCPConnect(void) { return OTA_XCPConnect; }

void set_TCU_ACMuteSet(real_T value) { TCU_ACMuteSet = value; }
real_T get_TCU_ACMuteSet(void) { return TCU_ACMuteSet; }

void set_TCU_BCUEINSet(real_T value) { TCU_BCUEINSet = value; }
real_T get_TCU_BCUEINSet(void) { return TCU_BCUEINSet; }

void set_TCU_ChargerWorkSts(real_T value) { TCU_ChargerWorkSts = value; }
real_T get_TCU_ChargerWorkSts(void) { return TCU_ChargerWorkSts; }


void set_TCU_ECOMode(real_T value) { TCU_ECOMode = value; }
real_T get_TCU_ECOMode(void) { return TCU_ECOMode; }


void set_TCU_LifeCounter(real_T value) { TCU_LifeCounter = value; }
real_T get_TCU_LifeCounter(void) { return TCU_LifeCounter; }

void set_TCU_PowerUpCmd(real_T value) { TCU_PowerUpCmd = value; }
real_T get_TCU_PowerUpCmd(void) { return TCU_PowerUpCmd; }

void set_TCU_TimeCalFlg(real_T value) { TCU_TimeCalFlg = value; }
real_T get_TCU_TimeCalFlg(void) { return TCU_TimeCalFlg; }

void set_TCU_TimeDay(real_T value) { TCU_TimeDay = value; }
real_T get_TCU_TimeDay(void) { return TCU_TimeDay; }

void set_TCU_TimeHour(real_T value) { TCU_TimeHour = value; }
real_T get_TCU_TimeHour(void) { return TCU_TimeHour; }

void set_TCU_TimeMinute(real_T value) { TCU_TimeMinute = value; }
real_T get_TCU_TimeMinute(void) { return TCU_TimeMinute; }

void set_TCU_TimeMonth(real_T value) { TCU_TimeMonth = value; }
real_T get_TCU_TimeMonth(void) { return TCU_TimeMonth; }

void set_TCU_TimeSecond(real_T value) { TCU_TimeSecond = value; }
real_T get_TCU_TimeSecond(void) { return TCU_TimeSecond; }

void set_TCU_TimeWeek(real_T value) { TCU_TimeWeek = value; }
real_T get_TCU_TimeWeek(void) { return TCU_TimeWeek; }

void set_TCU_TimeYear(real_T value) { TCU_TimeYear = value; }
real_T get_TCU_TimeYear(void) { return TCU_TimeYear; }

void set_TCU_FcnStopSet(real_T value) { TCU_FcnStopSet = value; }
real_T get_TCU_FcnStopSet(void) { return TCU_FcnStopSet; }

void set_TCU_HighVoltType(real_T value) { TCU_HighVoltType = value; }
real_T get_TCU_HighVoltType(void) { return TCU_HighVoltType; }

void set_TCU_HighVoltValue(real_T value) { TCU_HighVoltValue = value; }
real_T get_TCU_HighVoltValue(void) { return TCU_HighVoltValue; }


real_T get_BCU_TimeYearValue(void) { return BCU_TimeYear; }
real_T get_BCU_TimeMonthValue(void) { return BCU_TimeMonth; }
real_T get_BCU_TimeDayValue(void) { return BCU_TimeDay; }
real_T get_BCU_TimeHourValue(void) { return BCU_TimeHour; }
real_T get_BCU_TimeMinuteValue(void) { return BCU_TimeMinute; }
real_T get_BCU_TimeSencondValue(void) { return BCU_TimeSencond; }



real_T get_BCU_FaultInfoLv1Value(void) { return BCU_FaultInfoLv1; }
real_T get_BCU_FaultInfoLv2Value(void) { return BCU_FaultInfoLv2; }
real_T get_BCU_FaultInfoLv3Value(void) { return BCU_FaultInfoLv3; }
real_T get_BCU_FaultInfoLv4Value(void) { return BCU_FaultInfoLv4; }
real_T get_BCU_SOCValue(void) { return BCU_SOC; }
real_T get_BCU_SystemWorkModeValue(void) { return BCU_SystemWorkMode; }


uint16_T *get_BCU_usSingleBatVal(void) {
    return (uint16_T *)&usSingleBatVal[0];
}
uint16_T *get_BCU_usSingleBatTemp(void) {
    return (uint16_T *)&usSingleBatTemp[0];
}

uint16_T *get_BMU_DAq_version(void){
    return (uint16_T *)&DAq_version[0];
}

uint32_T get_BMU_DAqX_FaultCode1_at(int idx) {
    return DAqX_FaultCode1[idx];
}
uint32_T get_BMU_DAqX_FaultCode2_at(int idx) {
    return DAqX_FaultCode2[idx];
}

int32_T get_BCU_iDcPower(void) {

    return (int)BCU_RealtimePower;  /* 返回 */
}
unsigned long long get_BCU_ullPosEleQuantity(void) {

    return (unsigned long long)BCU_EngryAccumulateDisChrg;  /* 返回 */
}
unsigned long long get_BCU_ullNegEleQuantity(void) {
    return (unsigned long long)BCU_EngryAccumulateChrg;  /* 返回 */
}
uint16_T get_BCU_usAirState(void) {
    return Chiller_ModeFb;  /* 返回 */
}
uint16_T get_BCU_usAirPumpState(void) {
    return Chiller_PumpStatus;  /* 返回 */
}
uint16_T get_BCU_usAirCompressorSta(void) {
    return Chiller_CompressorStatus;  /* 返回 */
}
uint16_T get_BCU_uiAirErrorfaultCode(void){
    return Chiller_Fault;  /* xxxxxxxxxxx 待定*/
}

uint16_T get_usBmuH2MaxConcentration(){
    return BCU_FasH2MaxValue;  /* xxxxxxxxxxx 待定*/
}
uint16_T get_usBmuCOMaxConcentration(){
    return BCU_FasCOMaxValue;  /* xxxxxxxxxxx 待定*/
}
uint16_T get_usBmuPressureMax(){
    return BCU_FasPressMaxValue;  /* xxxxxxxxxxx 待定*/
}
uint16_T get_usBmuLightMax(){
    return BCU_FasLightMaxValue;  /* xxxxxxxxxxx 待定*/
}
uint16_T get_usBmuH2MaxIndex(){
    return BCU_FasLightMaxValue;  /* xxxxxxxxxxx 待定*/
}
uint16_T get_usBmuCOMaxIndex(){
    return BCU_FasCOMaxIdx;  /* xxxxxxxxxxx 待定*/
}
uint16_T get_usBmuPressureMaxIndex(){
    return BCU_FasPressMaxIdx;  /* xxxxxxxxxxx 待定*/
}

uint16_T get_usBmuLightMaxIndex(){
    return BCU_FasLightMaxIdx;  /* xxxxxxxxxxx 待定*/
}

uint16_T get_usAirEnergyMode(){
    uint16_t value = 0;  // 分配实际内存
    get_modbus_reg_val(0x3418, &value);
    return value;  /* xxxxxxxxxxx 待定*/
}

uint16_T get_usAirInletPressure(){
    return Chiller_InletPressure;  /* xxxxxxxxxxx 待定*/
}

uint16_T get_usAirCoolSetTemp(){
    return ThermCtrl_ACWarmGoal;
}


uint16_T get_usAirOutWaterTemp(){
    return Chiller_TempOutlet;
}

uint16_T  get_usAirReturnWaterTemp(){
    return Chiller_TempInlet;
}


uint16_T get_usBatMaxVoltCellIndex(){
    return BCU_VoltMaxIdx;
}
uint16_T get_usBatMinVoltCellIndex(){
    return BCU_VoltMinIdx;
}
uint16_T  get_usBatMaxTempCellIndex(){
    return BCU_TempMaxIdx;
}
uint16_T  get_usBatMinTempCellIndex(){
    return BCU_TempMinIdx;
}

uint16_T get_usBatCellVoltMax(){
    return BCU_VoltMaxCellValue;
}
uint16_T get_usBatCellVoltMin(){
    return BCU_VoltMinCellValue;
}

uint16_T get_usBatCellTempMax(){
    return BCU_TempMaxValue;
}
uint16_T get_usBatCellTempMin(){
    return BCU_VoltMinCellValue;
}
