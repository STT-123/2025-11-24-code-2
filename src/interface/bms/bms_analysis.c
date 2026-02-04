#include <arpa/inet.h> // htonl
#include <byteswap.h>  // bswap_16, bswap_32
#include "bms_analysis.h"
#include "interface/modbus/modbus_defines.h"
#include "interface/bms/bms_simulink/CANSendFcn.h"
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"
#include "interface/log/log.h"
#include <stdatomic.h>
#include <pthread.h>  // 必须包含这个头文件

extern CAN_FD_MESSAGE_BUS CANSendMsg;    
static atomic_int log_interrupt_count = ATOMIC_VAR_INIT(0);  


static CommandTracking cmd_track = {0};
static pthread_mutex_t cmd_mutex = PTHREAD_MUTEX_INITIALIZER;

// 全局缓冲区实例
static CanDataBuffer can_data_buffer = {0};
static PostChangeBuffer post_change_buffer = {0};


// 初始化缓冲区
void init_can_buffer(void) {
    memset(&can_data_buffer, 0, sizeof(can_data_buffer));
    can_data_buffer.start = 0;
    can_data_buffer.end = 0;
    can_data_buffer.count = 0;
    can_data_buffer.is_full = 0;
    
    memset(&post_change_buffer, 0, sizeof(post_change_buffer));
    post_change_buffer.count = 0;
    post_change_buffer.is_collecting = 0;
    post_change_buffer.collected_count = 0;
    
    memset(&cmd_track, 0, sizeof(cmd_track));
}


// 向缓冲区添加新帧数据
// 改进的缓冲区添加函数（保持顺序）
static void add_to_can_buffer(const CAN_FD_MESSAGE *msg) {
    if (!msg) return;
    
    // 复制帧数据到缓冲区
    memcpy(&can_data_buffer.frames[can_data_buffer.end], msg, sizeof(CAN_FD_MESSAGE));
    
    // 更新结束位置
    can_data_buffer.end = (can_data_buffer.end + 1) % DATA_BUFFER_SIZE;
    
    if (can_data_buffer.is_full) {
        // 缓冲区已满，覆盖最老的数据
        can_data_buffer.start = (can_data_buffer.start + 1) % DATA_BUFFER_SIZE;
    } else {
        // 缓冲区未满，增加计数
        can_data_buffer.count++;
        if (can_data_buffer.count >= DATA_BUFFER_SIZE) {
            can_data_buffer.is_full = 1;
        }
    }
}

// 2 按顺序获取缓冲区中的第i帧（0=最老，count-1=最新）
static CAN_FD_MESSAGE* get_buffer_frame(int i) {
    if (i < 0 || i >= can_data_buffer.count) {
        return NULL;
    }
    
    int idx = (can_data_buffer.start + i) % DATA_BUFFER_SIZE;
    return &can_data_buffer.frames[idx];
}


// 获取最新的N帧数据（从新到旧）
static void get_latest_frames(CAN_FD_MESSAGE *output, int n) {
    if (n <= 0 || n > DATA_BUFFER_SIZE) return;
    
    for (int i = 0; i < n; i++) {
        // 从最新的开始获取（索引倒序）
        int buffer_idx = (can_data_buffer.start + can_data_buffer.count - 1 - i) % DATA_BUFFER_SIZE;
        if (buffer_idx < 0) buffer_idx += DATA_BUFFER_SIZE;
        
        if (i < can_data_buffer.count) {
            memcpy(&output[i], &can_data_buffer.frames[buffer_idx], sizeof(CAN_FD_MESSAGE));
        }
    }
}

// ==================== 指令跟踪函数 ====================

// 开始指令跟踪
static void start_command_tracking(void)
{
    pthread_mutex_lock(&cmd_mutex);
    
    // 如果已经在跟踪，先完成之前的
    if (cmd_track.is_cmd_tracking) {
        LOG("[CMD] Previous command tracking still active, completing it\n");
        complete_command_tracking_internal();
    }
    
    // 开始新的指令跟踪
    cmd_track.is_cmd_tracking = 1;
    cmd_track.post_frames_collected = 0;
    
    // 保存指令前的10帧数据
    save_pre_command_frames();
    
    LOG("[CMD] Started command tracking\n");
    
    pthread_mutex_unlock(&cmd_mutex);
}

// 保存指令前的10帧数据
static void save_pre_command_frames(void)
{
    cmd_track.pre_frames_collected = 0;
    
    // 获取最新的10帧作为指令前数据
    get_latest_frames(cmd_track.pre_frames, DATA_BUFFER_SIZE);
    
    // 计算实际获取的帧数
    cmd_track.pre_frames_collected = can_data_buffer.count < DATA_BUFFER_SIZE ? 
                                     can_data_buffer.count : DATA_BUFFER_SIZE;
    
    LOG("[CMD] Saved %d pre-command frames\n", cmd_track.pre_frames_collected);
}

// 完成指令跟踪并打印结果
static void complete_command_tracking_internal(void)
{
    if (!cmd_track.is_cmd_tracking) {
        return;
    }
    
    // 打印指令前后的完整数据
    LOG("[CMD] ===== COMMAND TRACKING RESULTS =====\r");
    LOG("[CMD] Pre-frames: %d, Post-frames: %d\r", 
        cmd_track.pre_frames_collected, cmd_track.post_frames_collected);
    
    // 打印指令前数据（从旧到新）
    if (cmd_track.pre_frames_collected > 0) {
        LOG("[CMD] ----- BEFORE COMMAND (%d frames) -----\n", cmd_track.pre_frames_collected);
        for (int i = cmd_track.pre_frames_collected - 1; i >= 0; i--) {
            CAN_FD_MESSAGE *frame = &cmd_track.pre_frames[i];
            char data_str[512] = {0};
            int offset = 0;
            
            for (int j = 0; j < frame->DLC; j++) {
                offset += snprintf(data_str + offset, sizeof(data_str) - offset,
                                "%02X%s", frame->Data[j], (j < frame->DLC - 1) ? " " : "");
            }
            
            LOG("[CMD] Pre-Frame %d: ID=0x%08X, Data=%s\r", 
                cmd_track.pre_frames_collected - i, frame->ID, data_str);
        }
    }
    
    // 打印指令后数据（从旧到新）
    if (cmd_track.post_frames_collected > 0) {
        LOG("[CMD] ----- AFTER COMMAND (%d frames) -----\n", cmd_track.post_frames_collected);
        for (int i = 0; i < cmd_track.post_frames_collected; i++) {
            CAN_FD_MESSAGE *frame = &cmd_track.post_frames[i];
            char data_str[512] = {0};
            int offset = 0;
            
            for (int j = 0; j < frame->DLC; j++) {
                offset += snprintf(data_str + offset, sizeof(data_str) - offset,
                                "%02X%s", frame->Data[j], (j < frame->DLC - 1) ? " " : "");
            }
            
            LOG("[CMD] Post-Frame %d: ID=0x%08X, Data=%s\r", i+1, frame->ID, data_str);
        }
    }
    
    LOG("[CMD] ===========================================\n");
    
    // 重置跟踪状态
    memset(&cmd_track, 0, sizeof(cmd_track));
}


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
        LOG("[BMS] eeee Raw can_id      : 0x%08lX\n", frame->can_id);
        return;
    }

    msg->ID = frame->can_id & CAN_EFF_MASK; // 取 29 位
    msg->Extended = 1;
    msg->Remote = 0;
    msg->Error = 0;
    msg->Length = frame->can_dlc;
    
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

void set_OTA_XCPConnect(uint8_T value) { OTA_XCPConnect = value; }
uint8_T get_OTA_XCPConnect(void) { return OTA_XCPConnect; }

void set_TCU_ACMuteSet(uint8_T value) { TCU_ACMuteSet = value; }
uint8_T get_TCU_ACMuteSet(void) { return TCU_ACMuteSet; }

void set_TCU_BCUEINSet(uint32_T value) { TCU_BCUEINSet = value; }
uint32_T get_TCU_BCUEINSet(void) { return TCU_BCUEINSet; }

void set_TCU_ChargerWorkSts(uint8_T value) { TCU_ChargerWorkSts = value; }
uint8_T get_TCU_ChargerWorkSts(void) { return TCU_ChargerWorkSts; }


void set_TCU_ECOMode(uint8_T value) { TCU_ECOMode = value; }
uint8_T get_TCU_ECOMode(void) { return TCU_ECOMode; }


void set_TCU_LifeCounter(uint8_T value) { TCU_LifeCounter = value; }
uint8_T get_TCU_LifeCounter(void) { return TCU_LifeCounter; }

void set_TCU_PowerUpCmd(uint8_T value) { TCU_PowerUpCmd = value; }
uint8_T get_TCU_PowerUpCmd(void) { return TCU_PowerUpCmd; }

void set_TCU_TimeCalFlg(uint8_T value) { TCU_TimeCalFlg = value; }
uint8_T get_TCU_TimeCalFlg(void) { return TCU_TimeCalFlg; }

void set_TCU_TimeDay(uint8_T value) { TCU_TimeDay = value; }
uint8_T get_TCU_TimeDay(void) { return TCU_TimeDay; }

void set_TCU_TimeHour(uint8_T value) { TCU_TimeHour = value; }
uint8_T get_TCU_TimeHour(void) { return TCU_TimeHour; }

void set_TCU_TimeMinute(uint8_T value) { TCU_TimeMinute = value; }
uint8_T get_TCU_TimeMinute(void) { return TCU_TimeMinute; }

void set_TCU_TimeMonth(uint8_T value) { TCU_TimeMonth = value; }
uint8_T get_TCU_TimeMonth(void) { return TCU_TimeMonth; }

void set_TCU_TimeSecond(uint8_T value) { TCU_TimeSecond = value; }
uint8_T get_TCU_TimeSecond(void) { return TCU_TimeSecond; }

void set_TCU_TimeWeek(uint8_T value) { TCU_TimeWeek = value; }
uint8_T get_TCU_TimeWeek(void) { return TCU_TimeWeek; }

void set_TCU_TimeYear(uint8_T value) { TCU_TimeYear = value; }
uint8_T get_TCU_TimeYear(void) { return TCU_TimeYear; }

void set_TCU_FcnStopSet(uint8_T value) { TCU_FcnStopSet = value; }
uint8_T get_TCU_FcnStopSet(void) { return TCU_FcnStopSet; }

void set_TCU_HighVoltType(uint8_T value) { TCU_HighVoltType = value; }
uint8_T get_TCU_HighVoltType(void) { return TCU_HighVoltType; }

void set_TCU_HighVoltValue(uint16_T value) { TCU_HighVoltValue = value; }
uint16_T get_TCU_HighVoltValue(void) { return TCU_HighVoltValue; }


uint8_T get_BCU_TimeYearValue(void) { return BCU_TimeYear; }
uint8_T get_BCU_TimeMonthValue(void) { return BCU_TimeMonth; }
uint8_T get_BCU_TimeDayValue(void) { return BCU_TimeDay; }
uint8_T get_BCU_TimeHourValue(void) { return BCU_TimeHour; }
uint8_T get_BCU_TimeMinuteValue(void) { return BCU_TimeMinute; }
uint8_T get_BCU_TimeSencondValue(void) { return BCU_TimeSencond; }



uint32_T get_BCU_FaultInfoLv1Value(void) { return BCU_FaultInfoLv1; }
uint32_T get_BCU_FaultInfoLv2Value(void) { return BCU_FaultInfoLv2; }
uint32_T get_BCU_FaultInfoLv3Value(void) { return BCU_FaultInfoLv3; }
uint32_T get_BCU_FaultInfoLv4Value(void) { return BCU_FaultInfoLv4; }
uint16_T get_BCU_SOCValue(void) { return BCU_SOC; }
uint16_T get_BCU_SystemWorkModeValue(void) { return BCU_SystemWorkMode; }


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
    get_modbus_reg_val(MDBUS_ENESAV_STA, &value);
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

static void my_Log_TCU_Data(void)
{
    char data_str[256] = {0};
    int offset = 0;

    for (int i = 0; i < 64; i++) {
        offset += snprintf(data_str + offset, sizeof(data_str) - offset,
                          "%02X%s", CANSendMsg.Data[i], (i < 64 - 1) ? " " : "");
    }
    LOG("[RECORD] TCU_Data : %s\n", data_str);
}
// 2. 修改后的 Log_TCU_Data 函数
void Log_TCU_Data(void)
{
    my_Log_TCU_Data();
    start_command_tracking();// 开始指令跟踪
}


// 主要的数据记录函数
void Log_Bcu_Data(const CAN_FD_MESSAGE *msg)
{
    unsigned char log_flag = 0;
    static unsigned int BCU_FaultInfoLv1_LAST = 0;
    static unsigned int BCU_FaultInfoLv2_LAST = 0;
    static unsigned int BCU_FaultInfoLv3_LAST = 0;
    static unsigned int BCU_FaultInfoLv4_LAST = 0;
    static unsigned short BCU_SystemWorkMode_LAST = 0;
    
    // 状态变化相关变量
    static int buffer_before_count = 0;
    static int collecting_post_change = 0;
    static int post_change_collected = 0;
    static CAN_FD_MESSAGE buffer_before_change[DATA_BUFFER_SIZE] = {0};
    static CAN_FD_MESSAGE post_change_frames[DATA_BUFFER_SIZE] = {0};
    
    if (!msg) return;
    
    // 只处理关心的ID
    if (msg->ID == 0x180110E4) {
        // 0. 将新帧添加到循环缓冲区
        add_to_can_buffer(msg);
        
        // 1. 检查是否正在跟踪指令（高优先级）
        if (cmd_track.is_cmd_tracking) {
            // 收集指令后的数据
            if (cmd_track.post_frames_collected < DATA_BUFFER_SIZE) {
                memcpy(&cmd_track.post_frames[cmd_track.post_frames_collected],
                       msg, sizeof(CAN_FD_MESSAGE));
                cmd_track.post_frames_collected++;
                
                // LOG("[CMD] Collected %d/%d post-command frames\r",
                //     cmd_track.post_frames_collected, DATA_BUFFER_SIZE);
                
                // 收集完成后打印结果
                if (cmd_track.post_frames_collected >= DATA_BUFFER_SIZE) {
                    pthread_mutex_lock(&cmd_mutex);
                    complete_command_tracking_internal();
                    pthread_mutex_unlock(&cmd_mutex);
                }
            }
            // 指令跟踪期间，不处理状态变化
            return;
        }
        
        // 2. 如果正在收集状态变化后的数据
        if (collecting_post_change) {
            if (post_change_collected < DATA_BUFFER_SIZE) {
                memcpy(&post_change_frames[post_change_collected], 
                       msg, sizeof(CAN_FD_MESSAGE));
                post_change_collected++;
                
                // 收集完成
                if (post_change_collected >= DATA_BUFFER_SIZE) {
                    LOG("[RECORD] ==== AFTER CHANGE (collected %d frames) ====\n", 
                        post_change_collected);
                    
                    for (int i = 0; i < post_change_collected; i++) {
                        CAN_FD_MESSAGE *frame = &post_change_frames[i];
                        char data_str[512] = {0};
                        int offset = 0;
                        
                        for (int j = 0; j < frame->DLC; j++) {
                            offset += snprintf(data_str + offset, sizeof(data_str) - offset, 
                                            "%02X%s", frame->Data[j], (j < frame->DLC - 1) ? " " : "");
                        }
                        
                        LOG("[RECORD] Frame %d: ID=0x%08X, Data=%s\r", i+1, frame->ID, data_str);
                    }
                    LOG("[RECORD] =======================================\r");
                    
                    // 重置收集状态
                    collecting_post_change = 0;
                    post_change_collected = 0;
                }
            }
            return;
        }
        
        // 3. 检查状态变化
        unsigned short current_workmode = get_BCU_SystemWorkModeValue();
        unsigned int current_fault_lv1 = get_BCU_FaultInfoLv1Value();
        unsigned int current_fault_lv2 = get_BCU_FaultInfoLv2Value();
        unsigned int current_fault_lv3 = get_BCU_FaultInfoLv3Value();
        unsigned int current_fault_lv4 = get_BCU_FaultInfoLv4Value();
        
        if (BCU_SystemWorkMode_LAST != current_workmode) {
            LOG("[RECORD] SystemWorkMode: %d -> %d \r", BCU_SystemWorkMode_LAST, current_workmode);
            log_flag = 1;
        }
        if (BCU_FaultInfoLv1_LAST != current_fault_lv1) {
            LOG("[RECORD] FaultInfoLv1: [0x%x] -> [0x%x] \r", BCU_FaultInfoLv1_LAST, current_fault_lv1);
            log_flag = 1;
        }  
        if (BCU_FaultInfoLv2_LAST != current_fault_lv2) {
            LOG("[RECORD] FaultInfoLv2: [0x%x] -> [0x%x] \r", BCU_FaultInfoLv2_LAST, current_fault_lv2);
            log_flag = 1;
        }
        if (BCU_FaultInfoLv3_LAST != current_fault_lv3) {
            LOG("[RECORD] FaultInfoLv3: [0x%x] -> [0x%x] \r", BCU_FaultInfoLv3_LAST, current_fault_lv3);
            log_flag = 1;
        }
        if (BCU_FaultInfoLv4_LAST != current_fault_lv4) {
            LOG("[RECORD] FaultInfoLv4: [0x%x] -> [0x%x] \r", BCU_FaultInfoLv4_LAST, current_fault_lv4);
            log_flag = 1;
        }
        
        // 4. 如果检测到状态变化
        if (log_flag) {
 
            // 保存变化前的数据（最新的9帧）
            buffer_before_count = 0;
            
            // 获取最新的9帧作为变化前数据
            int frames_to_get = (can_data_buffer.count < (DATA_BUFFER_SIZE - 1)) ? 
                               can_data_buffer.count : (DATA_BUFFER_SIZE - 1);
            
            get_latest_frames(buffer_before_change, frames_to_get);
            buffer_before_count = frames_to_get;
            
            // 打印变化前的数据
            if (buffer_before_count > 0) {
                LOG("[RECORD] ==== BEFORE CHANGE (saved %d frames) ====\r", buffer_before_count);
                my_Log_TCU_Data();
                // 从旧到新打印（buffer_before_change中是最新的在索引0）
                for (int i = buffer_before_count - 1; i >= 0; i--) {
                    CAN_FD_MESSAGE *frame = &buffer_before_change[i];
                    char data_str[512] = {0};
                    int offset = 0;
                    
                    for (int j = 0; j < frame->DLC; j++) {
                        offset += snprintf(data_str + offset, sizeof(data_str) - offset,
                                        "%02X%s", frame->Data[j], (j < frame->DLC - 1) ? " " : "");
                    }
                    
                    LOG("[RECORD] Frame %d: ID=0x%08X, Data=%s\r", 
                        buffer_before_count - i, frame->ID, data_str);
                }
                LOG("[RECORD] =========================================\n");
            }
            
            // 开始收集变化后的数据
            collecting_post_change = 1;
            post_change_collected = 0;
            
            // 当前帧作为变化后的第1帧
            memcpy(&post_change_frames[post_change_collected], 
                   msg, sizeof(CAN_FD_MESSAGE));
            post_change_collected++;
            
            LOG("[RECORD] Starting to collect %d frames after change...\n", DATA_BUFFER_SIZE);
            
            // 更新LAST值
            BCU_SystemWorkMode_LAST = current_workmode;
            BCU_FaultInfoLv1_LAST = current_fault_lv1;
            BCU_FaultInfoLv2_LAST = current_fault_lv2;
            BCU_FaultInfoLv3_LAST = current_fault_lv3;
            BCU_FaultInfoLv4_LAST = current_fault_lv4;
            
            return;
        }
        
        // 5. 更新LAST值（如果没有变化）
        BCU_SystemWorkMode_LAST = current_workmode;
        BCU_FaultInfoLv1_LAST = current_fault_lv1;
        BCU_FaultInfoLv2_LAST = current_fault_lv2;
        BCU_FaultInfoLv3_LAST = current_fault_lv3;
        BCU_FaultInfoLv4_LAST = current_fault_lv4;
    }
}