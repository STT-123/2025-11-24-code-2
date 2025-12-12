#include "ocpp_sqlite3.h"
#include <time.h>
#include "interface/bms/bms_simulink/CANFDRcvFcn_BCU.h"
#include "interface/bms/bms_simulink/CANRcvFcn_BMU.h"
#include "device_drv/ocpp_protocol/ocpp/batdata.h"
#include "device_drv/ocpp_protocol/ocpp/project.h"
#include "device_drv/ocpp_protocol/ocpp/message_queue.h"
#include "device_drv/ocpp_protocol/ocpp/sqlite_storage.h"
#include "device_drv/ocpp_protocol/ocpp/ocpp_messages.h"
/*------以上暂时为ocpp调试使用-----------*/
struct tm utc_timeinfo;

// ✅ 每秒更新一次数据（可由外部线程或主循环调用）
// void update_bat_data(sqlite3 *db)
// {
    // tBatData data = {0};
    // tBatData data_be = {0};
    // uint16_t DAq_version[15] = {0};

    // for(int i = 0; i < 15; i++){
    //     get_modbus_reg_val(0x5000 +i, &DAq_version[i]);
    // }

    // memcpy(data.usSingleBatVal, get_BCU_usSingleBatVal(), sizeof(data.usSingleBatVal));
    // memcpy(data.usSingleBatTemp, get_BCU_usSingleBatTemp(), sizeof(data.usSingleBatTemp));

    // for(int i = 0; i < 15; i++)
    // {
    //     if(DAq_version[i] != 0)
    //     {
    //         uint32_T* p_o1 = &CANRcvFcn_BMU_B.ux180110E16_o1 + (i * 2);      // 每次跳过2个uint32_T
    //         uint32_T* p_o2 = &CANRcvFcn_BMU_B.ux180110E16_o2 + (i * 2);      // 每次跳过2个uint32_T
        
    //         data.uiBmuErrorNum[i] = *p_o1;
    //         data.uiBmuExErrorNum[i] = *p_o2;
    //     }else{
    //         data.uiBmuErrorNum[i] = 65535;
    //         data.uiBmuExErrorNum[i] = 65535;
    //     }
    // }

    // data.iDcPower = CANRcvFcn_B.CANFDUnpack3_o7;
    // // data.iDcPower = 100;
    // // printf("iDcPower = %d\n",data.iDcPower);
    // data.ullPosEleQuantity = CANRcvFcn_B.CANFDUnpack3_o5;
    // // printf("ullPosEleQuantity = %llu\n",data.ullPosEleQuantity);
    // data.ullNegEleQuantity = CANRcvFcn_B.CANFDUnpack3_o2;
    // // printf("ullNegEleQuantity = %llu\n",data.ullNegEleQuantity);

    // data.usAirState = CANRcvFcn_B.CANFDUnpack3_o20;
    // // printf("usAirState = %d\n",data.usAirState);
    // data.usAirPumpState = CANRcvFcn_B.CANFDUnpack3_o24;
    // // printf("usAirPumpState = %d\n",data.usAirPumpState);
    // data.usAirCompressorSta = CANRcvFcn_B.CANFDUnpack3_o21;

    // int faultCode = CANRcvFcn_B.CANFDUnpack3_o33;
    // data.uiAirErrorLv1 = 0;
    // data.uiAirErrorLv2 = 0;
    // data.uiAirErrorLv3 = 0;

    // // Lv1 错误判断
    // if (faultCode == 1)
    // {
    //     data.uiAirErrorLv1 |= (1U << 1);
    //     // printf("Air Error Lv1: %d -> bit1\n", faultCode);
    // }
    // if (faultCode == 3)
    // {
    //     data.uiAirErrorLv1 |= (1U << 3);
    //     // printf("Air Error Lv1: %d -> bit3\n", faultCode);
    // }
    // if (faultCode == 28)
    // {
    //     data.uiAirErrorLv1 |= (1U << 28);
    //     // printf("Air Error Lv1: %d -> bit28\n", faultCode);
    // }

    // // Lv2 错误判断
    // if (faultCode == 4 || faultCode == 5 ||
    //     (faultCode >= 8 && faultCode <= 17) ||
    //     (faultCode >= 20 && faultCode <= 22) ||
    //     faultCode == 25 || faultCode == 29 ||
    //     faultCode == 30 || faultCode == 31)
    // {

    //     data.uiAirErrorLv2 |= (1U << faultCode);
    //     // printf("Air Error Lv2: %d -> bit%d\n", faultCode, faultCode);
    // }

    // // Lv3 错误判断
    // if (faultCode == 18 || faultCode == 19 ||
    //     faultCode == 23 || faultCode == 24 ||
    //     faultCode == 26 || faultCode == 27)
    // {

    //     data.uiAirErrorLv3 |= (1U << faultCode);
    //     // printf("Air Error Lv3: %d -> bit%d\n", faultCode, faultCode);
    // }

    // data.usTempInside = CANRcvFcn_B.CANFDUnpack3_o34;
    // data.usTempOutside = CANRcvFcn_B.CANFDUnpack3_o36;
    // data.usHumidityInside = 0;

    // data.usBmuH2MaxConcentration = CANRcvFcn_B.CANFDUnpack_o34;
    // // printf("data.usBmuH2MaxConcentration :%d\r\n",data.usBmuH2MaxConcentration);
    // data.usBmuH2MinConcentration = 0;
    // data.usBmuCOMaxConcentration = CANRcvFcn_B.CANFDUnpack_o32;
    // // printf("data.usBmuCOMaxConcentration :%d\r\n",data.usBmuCOMaxConcentration);
    // data.usBmuCOMinConcentration = 0;
    // data.usBmuPressureMax = CANRcvFcn_B.CANFDUnpack_o38;
    // // printf("data.usBmuPressureMax :%d\r\n",data.usBmuPressureMax);
    // data.usBmuPressureMin = 0;
    // data.usBmuLightMax = CANRcvFcn_B.CANFDUnpack_o36;
    // data.usBmuLightMin = 0;
    // data.usBmuH2MaxIndex = CANRcvFcn_B.CANFDUnpack_o33;
    // data.usBmuCOMaxIndex = CANRcvFcn_B.CANFDUnpack_o31;
    // data.usBmuCOMinIndex = 0;
    // data.usBmuPressureMaxIndex = CANRcvFcn_B.CANFDUnpack_o37;
    // data.usBmuPressureMinIndex = 0;
    // data.usBmuLightMaxIndex = CANRcvFcn_B.CANFDUnpack_o35;
    // data.usBmuLightMinIndex = 0;

    // data.usAirEnergyMode = CANRcvFcn_B.CANFDUnpack3_o17;
    // // data.usAirEnergyMode = 1;
    // // printf("data.usAirEnergyMode :%d\r\n",data.usAirEnergyMode);
    // data.usAirInletPressure = CANRcvFcn_B.CANFDUnpack3_o18;
    // data.usAirCoolSetTemp = CANRcvFcn_B.CANFDUnpack3_o15 * 10;
    // data.usAirHeatSetTemp = CANRcvFcn_B.CANFDUnpack3_o27 * 10;
    // data.usAirOutWaterTemp = CANRcvFcn_B.CANFDUnpack3_o36 * 10;
    // // printf("data.usAirOutWaterTemp :%d\r\n",data.usAirOutWaterTemp);
    // data.usAirReturnWaterTemp = CANRcvFcn_B.CANFDUnpack3_o34 * 10;
    // // printf("data.usAirReturnWaterTemp :%d\r\n",data.usAirReturnWaterTemp);

    // data.usBatMaxVoltCellIndex = CANRcvFcn_B.CANFDUnpack2_o42;
    // data.usBatMinVoltCellIndex = CANRcvFcn_B.CANFDUnpack2_o44;
    // data.usBatMaxTempCellIndex = CANRcvFcn_B.CANFDUnpack2_o14;
    // data.usBatMinTempCellIndex = CANRcvFcn_B.CANFDUnpack2_o21;
    // data.usBatCellVoltMax = CANRcvFcn_B.CANFDUnpack2_o37;
    // data.usBatCellVoltMin = CANRcvFcn_B.CANFDUnpack2_o41;
    // // data.usBatMaxTempCellVolt =CANRcvFcn_B.CANFDUnpack2_o43;
    // // data.usBatMinTempCellVolt =CANRcvFcn_B.CANFDUnpack2_o45;
    // data.usBatMaxTempCellVolt = 0;
    // data.usBatMinTempCellVolt = 0;
    // data.usBatCellTempMax = CANRcvFcn_B.CANFDUnpack2_o19;
    // data.usBatCellTempMin = CANRcvFcn_B.CANFDUnpack2_o24;
    // data.usBatMaxVoltCellTemp = CANRcvFcn_B.CANFDUnpack2_o3;
    // data.usBatMinVoltCellTemp = CANRcvFcn_B.CANFDUnpack2_o4;

//     utc_timeinfo.tm_year = get_BCU_TimeYearValue() + 100; // BCU年是如24，tm_year从1900起
//     utc_timeinfo.tm_mon = get_BCU_TimeMonthValue() - 1;   // BCU月是1~12，tm_mon是0~11
//     utc_timeinfo.tm_mday = get_BCU_TimeDayValue();
//     utc_timeinfo.tm_hour = get_BCU_TimeHourValue() - 8;
//     utc_timeinfo.tm_min = get_BCU_TimeMinuteValue();
//     utc_timeinfo.tm_sec = get_BCU_TimeSencondValue();
//     utc_timeinfo.tm_isdst = -1;

//     // utc_timeinfo.tm_hour -= 8;
//     time_t t = mktime(&utc_timeinfo);
//     data.uiTimeStamp = (unsigned int)t;
//     // printf("utc_timeinfo.tm_year: %d\n",utc_timeinfo.tm_year);
//     // printf("utc_timeinfo.tm_mon: %d\n",utc_timeinfo.tm_mon);
//     // printf("utc_timeinfo.tm_mday: %d\n",utc_timeinfo.tm_mday);
//     // printf("utc_timeinfo.tm_hour: %d\n",utc_timeinfo.tm_hour);
//     // printf("utc_timeinfo.tm_min: %d\n",utc_timeinfo.tm_min);
//     // printf("utc_timeinfo.tm_sec: %d\n",utc_timeinfo.tm_sec);
//     // printf("timestamp: %u\n", data.uiTimeStamp);
//     /////////////////////////////////////////////////////////

//     convert_tBatData_to_big_endian(&data_be, &data);
//     insert_data(db, &data_be);
// }