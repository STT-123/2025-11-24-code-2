#include "ocpp_send.h"
#include "update_firmware.h"
#include "get_diagnostics.h"

extern struct lws *global_wsi;
extern pthread_mutex_t wsi_lock;
extern int g_ocppupload_flag;
extern int g_ocppdownload_flag;
extern volatile int send_thread_should_run;
extern volatile int connection_is_active;
void update_bat_data(sqlite3 *db)
{
    tBatData data = {0};
    tBatData data_be = {0};
    uint16_t DAq_version[15] = {0};

    data.usAirState =1;

    // for(int i = 0; i < 15; i++){
    //     get_modbus_reg_val(0x5000 +i, &DAq_version[i]);
    // }


    memcpy(data.usSingleBatVal, get_BCU_usSingleBatVal(), sizeof(data.usSingleBatVal));
    memcpy(data.usSingleBatTemp, get_BCU_usSingleBatTemp(), sizeof(data.usSingleBatTemp));
    for (int i = 0; i < 3; i++)
    {
        printf("data.usSingleBatTemp[%d] = %d\r\n",i,data.usSingleBatTemp[i]);
    }
    

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
#if 0
    data.iDcPower = get_BCU_iDcPower();
    data.ullPosEleQuantity = get_BCU_ullPosEleQuantity();
    data.ullNegEleQuantity = get_BCU_ullNegEleQuantity();
    data.usAirState = get_BCU_usAirState();
    data.usAirPumpState = get_BCU_usAirPumpState();
    data.usAirCompressorSta = get_BCU_usAirCompressorSta();

    int faultCode = get_BCU_uiAirErrorfaultCode();
    data.uiAirErrorLv1 = 0;
    data.uiAirErrorLv2 = 0;
    data.uiAirErrorLv3 = 0;

    // Lv1 错误判断
    if (faultCode == 1)
    {
        data.uiAirErrorLv1 |= (1U << 1);   
    }
    if (faultCode == 3)
    {
        data.uiAirErrorLv1 |= (1U << 3);    
    }
    if (faultCode == 28)
    {
        data.uiAirErrorLv1 |= (1U << 28);
    }

    // Lv2 错误判断
    if (faultCode == 4 || faultCode == 5 ||
        (faultCode >= 8 && faultCode <= 17) ||
        (faultCode >= 20 && faultCode <= 22) ||
        faultCode == 25 || faultCode == 29 ||
        faultCode == 30 || faultCode == 31)
    {
        data.uiAirErrorLv2 |= (1U << faultCode);      
    }

    // Lv3 错误判断
    if (faultCode == 18 || faultCode == 19 ||
        faultCode == 23 || faultCode == 24 ||
        faultCode == 26 || faultCode == 27)
    {
        data.uiAirErrorLv3 |= (1U << faultCode);
    }

    data.usTempInside = get_usTempInside();
    data.usTempOutside = get_usTempOutside();
    data.usHumidityInside = 0;

    data.usBmuH2MaxConcentration = get_usBmuH2MaxConcentration();
  
    data.usBmuH2MinConcentration = 0;
    data.usBmuCOMaxConcentration = get_usBmuCOMaxConcentration();

    data.usBmuCOMinConcentration = 0;
    data.usBmuPressureMax = get_usBmuPressureMax();

    data.usBmuPressureMin = 0;
    data.usBmuLightMax = get_usBmuLightMax();
    data.usBmuLightMin = 0;
    data.usBmuH2MaxIndex = get_usBmuH2MaxIndex();
    data.usBmuCOMaxIndex = get_usBmuCOMaxIndex();
    data.usBmuCOMinIndex = 0;
    data.usBmuPressureMaxIndex = get_usBmuPressureMaxIndex();
    data.usBmuPressureMinIndex = 0;
    data.usBmuLightMaxIndex = get_usBmuLightMaxIndex();
    data.usBmuLightMinIndex = 0;

    data.usAirEnergyMode = get_usAirEnergyMode();

    data.usAirInletPressure = get_usAirInletPressure();

    data.usAirCoolSetTemp = get_usAirCoolSetTemp() * 10;
    data.usAirHeatSetTemp = get_usAirHeatSetTemp() * 10;
    data.usAirOutWaterTemp = get_usAirOutWaterTemp() * 10;

    data.usAirReturnWaterTemp = get_usAirReturnWaterTemp() * 10;


    data.usBatMaxVoltCellIndex = get_usBatMaxVoltCellIndex();
    data.usBatMinVoltCellIndex = get_usBatMinVoltCellIndex();
    data.usBatMaxTempCellIndex = get_usBatMaxTempCellIndex();
    data.usBatMinTempCellIndex = get_usBatMinTempCellIndex();
    data.usBatCellVoltMax = get_usBatCellVoltMax();
    data.usBatCellVoltMin = get_usBatCellVoltMin();

    data.usBatMaxTempCellVolt = 0;
    data.usBatMinTempCellVolt = 0;
    data.usBatCellTempMax = get_usBatCellTempMax();
    data.usBatCellTempMin =get_usBatCellTempMin();
    data.usBatMaxVoltCellTemp = get_usBatMaxVoltCellTempe();
    data.usBatMinVoltCellTemp = get_usBatMinVoltCellTemp();

    struct tm utc_timeinfo;
    utc_timeinfo.tm_year = get_BCU_TimeYearValue() + 100; // BCU年是如24，tm_year从1900起
    utc_timeinfo.tm_mon = get_BCU_TimeMonthValue() - 1;   // BCU月是1~12，tm_mon是0~11
    utc_timeinfo.tm_mday = get_BCU_TimeDayValue();
    utc_timeinfo.tm_hour = get_BCU_TimeHourValue() - 8;
    utc_timeinfo.tm_min = get_BCU_TimeMinuteValue();
    utc_timeinfo.tm_sec = get_BCU_TimeSencondValue();
    utc_timeinfo.tm_isdst = -1;
    time_t t = mktime(&utc_timeinfo);
    data.uiTimeStamp = (unsigned int)t;
#endif
    data.uiTimeStamp = (unsigned int)time(NULL);
    convert_tBatData_to_big_endian(&data_be, &data);
    insert_data(db, &data_be);

    // printf("data.usSingleBatTemp[0] = %d\r\n",data.usSingleBatTemp[0]);
    // printf("data.usSingleBatTemp[0] = %d\r\n",data.usSingleBatTemp[1]);
    // printf("data.usSingleBatTemp[0] = %d\r\n",data.usSingleBatTemp[2]);
}
void update_bat_data1(sqlite3 *db) {
    tBatData data = {0};
    tBatData data_be = {0};

    data.usAirState =1;

    for(int i=0;i<240;i++)
    {
        data.usSingleBatVal[i] =30 + (rand() % 40);
    }

    data.uiTimeStamp = (unsigned int)time(NULL);


    convert_tBatData_to_big_endian(&data_be,&data);
    insert_data(db, &data_be);
    printf("data.usSingleBatVal[0] = %d\r\n",data.usSingleBatVal[0]);
    printf("data.usSingleBatVal[0] = %d\r\n",data.usSingleBatVal[1]);
    printf("data.usSingleBatVal[0] = %d\r\n",data.usSingleBatVal[2]);
    
}
/*
*websocket_send_thread 线程
*该线程专门用来给ocpp服务端发送数据
*心跳、电池数据等
*/
void *websocket_send_thread(void *arg)
{
    int heartcounter = 0;
    int dbcounter = 0;
    int boot_sent = 0;
    sqlite3 *db = NULL;
    init_db(&db);
 
    while(1)
    {
        send_ocpp_message(build_heartbeat());

        sleep(1);
        update_bat_data1(db);   //更1S存一次新电池数据

        printf("heartcounter =%d...\n", heartcounter);
        if (++heartcounter >= 60) {//每60S发送60条数据
            heartcounter = 0;
            int ids[REPORT_COUNT];
            int count = 0;

            send_ocpp_message(compress_detail_data(db, ids, &count));
            // 调试用的
            struct json_object *json = compress_detail_data(db, ids, &count);
            if (json) {
                if (send_ocpp_message(json)) {
                    delete_data_by_ids(db, ids, count);
                }
            }
            
        }
    }

    return 0;
}