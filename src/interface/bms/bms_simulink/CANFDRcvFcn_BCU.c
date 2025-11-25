/*
 * File: CANFDRcvFcn_BCU.c
 *
 * Code generated for Simulink model 'CANFDRcvFcn_BCU'.
 *
 * Model version                  : 5.38
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Nov 25 09:51:43 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CANFDRcvFcn_BCU.h"
#include <math.h>
#include <string.h>
#include "CANFDRcvFcn_BCU_types.h"
#include "rtwtypes.h"
#include "CANFDRcvFcn_BCU_private.h"

/* Exported block signals */
CAN_FD_MESSAGE_BUS CANFDRcvMsg;        /* '<Root>/CANFDRcvMsg' */

/* Block signals (default storage) */
B_CANFDRcvFcn_BCU_T CANFDRcvFcn_BCU_B;

/* Block states (default storage) */
DW_CANFDRcvFcn_BCU_T CANFDRcvFcn_BCU_DW;

/* Real-time model */
static RT_MODEL_CANFDRcvFcn_BCU_T CANFDRcvFcn_BCU_M_;
RT_MODEL_CANFDRcvFcn_BCU_T *const CANFDRcvFcn_BCU_M = &CANFDRcvFcn_BCU_M_;

/* Exported data definition */

/* Definition for custom storage class: Default */
uint32_T BCU_FaultInfoLv1H;            /* '<S1>/CAN FD Unpack1' */
uint32_T BCU_FaultInfoLv1L;            /* '<S1>/CAN FD Unpack1' */
uint32_T BCU_FaultInfoLv2H;            /* '<S1>/CAN FD Unpack1' */
uint32_T BCU_FaultInfoLv2L;            /* '<S1>/CAN FD Unpack1' */
uint32_T BCU_FaultInfoLv3H;            /* '<S1>/CAN FD Unpack1' */
uint32_T BCU_FaultInfoLv3L;            /* '<S1>/CAN FD Unpack1' */
uint32_T BCU_FaultInfoLv4H;            /* '<S1>/CAN FD Unpack1' */
uint32_T BCU_FaultInfoLv4L;            /* '<S1>/CAN FD Unpack1' */
uint16_T BCU_SOC;                      /* '<S1>/Data Type Conversion35' */
uint16_T BCU_SystemStatus;             /* '<S6>/Constant' */
uint16_T BCU_SystemWorkMode;           /* '<S1>/CAN FD Unpack1' */
uint8_T BCU_TimeDay;                   /* '<S1>/CAN FD Unpack' */
uint8_T BCU_TimeHour;                  /* '<S1>/CAN FD Unpack' */
uint8_T BCU_TimeMinute;                /* '<S1>/CAN FD Unpack' */
uint8_T BCU_TimeMonth;                 /* '<S1>/CAN FD Unpack' */
uint8_T BCU_TimeSencond;               /* '<S1>/CAN FD Unpack' */
uint8_T BCU_TimeWeek;                  /* '<S1>/CAN FD Unpack' */
uint8_T BCU_TimeYear;                  /* '<S1>/CAN FD Unpack' */

/* Model step function */
void CANFDRcvFcn_BCU_step(void)
{
  int32_T tmp;
  real32_T u;
  real32_T v;
  uint32_T data_index;
  uint32_T port_index;
  uint32_T port_len;
  uint32_T q0;
  uint32_T qY;
  uint16_T rtb_TmpSignalConversionAtSFunct[517];
  uint16_T rtb_TmpSignalConversionAtSFun_a[60];
  uint16_T rtb_TmpSignalConversionAtSFu_kh[30];
  uint16_T CFunction1_o1;
  uint16_T CFunction1_o2;
  uint16_T CFunction_o1;
  uint16_T CFunction_o2;
  uint16_T b;
  uint16_T c;
  uint16_T i;
  uint16_T rtb_DataTypeConversion29;
  uint8_T b_0;
  uint8_T i_0;
  uint8_T rtb_Saturation2;

  {
    /* S-Function (scanfdunpack): '<S1>/CAN FD Unpack1' */
    if ((64 == CANFDRcvMsg.Length) && (CANFDRcvMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180110E4== CANFDRcvMsg.ID) && (1U == CANFDRcvMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[6]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              BCU_SystemWorkMode = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[15]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[14]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = (result * 0.1F) + -3200.0F;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[17]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[16]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = (result * 0.1F) + -3200.0F;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[5]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[4]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[31]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[30]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[29]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[28]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              BCU_FaultInfoLv1H = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[27]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[26]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[25]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[24]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              BCU_FaultInfoLv1L = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[39]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[38]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[37]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[36]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              BCU_FaultInfoLv2H = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[35]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[34]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[33]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[32]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              BCU_FaultInfoLv2L = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[47]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[46]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[45]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[44]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              BCU_FaultInfoLv3H = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[43]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[42]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[41]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[40]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              BCU_FaultInfoLv3L = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[55]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[54]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[53]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[52]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              BCU_FaultInfoLv4H = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[51]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[50]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[49]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[48]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              BCU_FaultInfoLv4L = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[7]) & (uint8_T)(0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o14 = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)(CANFDRcvMsg.Data[7])
                    & (uint8_T)(0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o15 = result;
            }
          }

          /* --------------- START Unpacking signal 15 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[7]) & (uint8_T)(0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o16 = result;
            }
          }

          /* --------------- START Unpacking signal 16 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[59]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[58]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o17 = result;
            }
          }

          /* --------------- START Unpacking signal 17 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[61]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[60]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o18 = result;
            }
          }

          /* --------------- START Unpacking signal 18 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[63]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[62]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o19 = result;
            }
          }

          /* --------------- START Unpacking signal 19 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[57]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[56]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o20 = result;
            }
          }

          /* --------------- START Unpacking signal 20 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[7]) & (uint8_T)(0xC0U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o21 = result;
            }
          }

          /* --------------- START Unpacking signal 21 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[23]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[22]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o22 = result;
            }
          }

          /* --------------- START Unpacking signal 22 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[21]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[20]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o23 = result;
            }
          }

          /* --------------- START Unpacking signal 23 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[19]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[18]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o24 = result;
            }
          }

          /* --------------- START Unpacking signal 24 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack1_o25 = result;
            }
          }
        }
      }
    }
  }

  {
    /* S-Function (scanfdunpack): '<S1>/CAN FD Unpack3' */
    if ((64 == CANFDRcvMsg.Length) && (CANFDRcvMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180310E4== CANFDRcvMsg.ID) && (1U == CANFDRcvMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[39]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[38]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[51]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[50]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[49]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[48]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[47]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[46]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[33]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[32]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[45]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[44]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[43]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[42]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[41]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[40]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[37]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[36]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[35]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[34]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o7 = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[21]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[20]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o8 = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[23]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[22]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o9 = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[25]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[24]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o10 = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[26]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o11 = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[29]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[28]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o12 = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[31]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[30]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o13 = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[19]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o14 = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------*/
          {
            int32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[54]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[53]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[52]) << 16);
                }

                unpackedValue = tempValue;
              }

              outValue = (int32_T) (unpackedValue);
            }

            {
              int32_T result = (int32_T) outValue;
              result = result + -8388608;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o15 = result;
            }
          }

          /* --------------- START Unpacking signal 15 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)(CANFDRcvMsg.Data
                    [27]) & (uint8_T)(0x3U));
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o16 = result;
            }
          }

          /* --------------- START Unpacking signal 16 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[27]) & (uint8_T)(0x30U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o17 = result;
            }
          }

          /* --------------- START Unpacking signal 17 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[27]) & (uint8_T)(0xCU)) >> 2);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o18 = result;
            }
          }

          /* --------------- START Unpacking signal 18 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[56]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o19 = result;
            }
          }

          /* --------------- START Unpacking signal 19 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[55]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o20 = result;
            }
          }

          /* --------------- START Unpacking signal 20 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[4]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o21 = result;
            }
          }

          /* --------------- START Unpacking signal 21 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[7]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o22 = result;
            }
          }

          /* --------------- START Unpacking signal 22 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[13]) & (uint8_T)(0x40U)) >> 6);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o23 = result;
            }
          }

          /* --------------- START Unpacking signal 23 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[11]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o24 = result;
            }
          }

          /* --------------- START Unpacking signal 24 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[9]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[8]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o25 = result;
            }
          }

          /* --------------- START Unpacking signal 25 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[6]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o26 = result;
            }
          }

          /* --------------- START Unpacking signal 26 ------------------*/
          {
            real32_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[12]);
                }

                unpackedValue = tempValue;
              }

              outValue = (real32_T) (unpackedValue);
            }

            {
              real32_T result = (real32_T) outValue;
              result = result * 0.1F;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o27 = result;
            }
          }

          /* --------------- START Unpacking signal 27 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[15]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o28 = result;
            }
          }

          /* --------------- START Unpacking signal 28 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[16]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o29 = result;
            }
          }

          /* --------------- START Unpacking signal 29 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[13]) & (uint8_T)(0x20U)) >> 5);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o30 = result;
            }
          }

          /* --------------- START Unpacking signal 30 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[13]) & (uint8_T)(0x80U)) >> 7);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o31 = result;
            }
          }

          /* --------------- START Unpacking signal 31 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[13]) & (uint8_T)(0x10U)) >> 4);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o32 = result;
            }
          }

          /* --------------- START Unpacking signal 32 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[5]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o33 = result;
            }
          }

          /* --------------- START Unpacking signal 33 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[14]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o34 = result;
            }
          }

          /* --------------- START Unpacking signal 34 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[17]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o35 = result;
            }
          }

          /* --------------- START Unpacking signal 35 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[18]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o36 = result;
            }
          }

          /* --------------- START Unpacking signal 36 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (CANFDRcvMsg.Data[13]) & (uint8_T)(0x8U)) >> 3);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o37 = result;
            }
          }

          /* --------------- START Unpacking signal 37 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[10]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o38 = result;
            }
          }

          /* --------------- START Unpacking signal 38 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[3]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o39 = result;
            }
          }

          /* --------------- START Unpacking signal 39 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o40 = result;
            }
          }

          /* --------------- START Unpacking signal 40 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[2]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o41 = result;
            }
          }

          /* --------------- START Unpacking signal 41 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack3_o42 = result;
            }
          }
        }
      }
    }
  }

  u = 1000.0F * CANFDRcvFcn_BCU_B.CANFDUnpack3_o2;
  if (u < 4.2949673E+9F) {
    if (u >= 0.0F) {
      data_index = (uint32_T)u;
    } else {
      data_index = 0U;
    }
  } else {
    data_index = MAX_uint32_T;
  }

  CFunction_o1 = (uint16_T)(data_index >> 16);
  CFunction_o2 = (uint16_T)(data_index & 65535U);
  u = 1000.0F * CANFDRcvFcn_BCU_B.CANFDUnpack3_o5;
  if (u < 4.2949673E+9F) {
    if (u >= 0.0F) {
      data_index = (uint32_T)u;
    } else {
      data_index = 0U;
    }
  } else {
    data_index = MAX_uint32_T;
  }

  CFunction1_o1 = (uint16_T)(data_index >> 16);
  CFunction1_o2 = (uint16_T)(data_index & 65535U);

  {
    /* S-Function (scanfdunpack): '<S1>/CAN FD Unpack' */
    if ((64 == CANFDRcvMsg.Length) && (CANFDRcvMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410E4== CANFDRcvMsg.ID) && (1U == CANFDRcvMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[30]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[31]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[32]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[33]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[34]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[35]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[36]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o7 = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[37]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o8 = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[38]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o9 = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[39]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o10 = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[40]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o11 = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[41]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o12 = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[42]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o13 = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[43]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o14 = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[44]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o15 = result;
            }
          }

          /* --------------- START Unpacking signal 15 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[1]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[0]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o16 = result;
            }
          }

          /* --------------- START Unpacking signal 16 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[3]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[2]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o17 = result;
            }
          }

          /* --------------- START Unpacking signal 17 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[5]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[4]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o18 = result;
            }
          }

          /* --------------- START Unpacking signal 18 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[7]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[6]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o19 = result;
            }
          }

          /* --------------- START Unpacking signal 19 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[9]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[8]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o20 = result;
            }
          }

          /* --------------- START Unpacking signal 20 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[11]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[10]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o21 = result;
            }
          }

          /* --------------- START Unpacking signal 21 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[13]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[12]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o22 = result;
            }
          }

          /* --------------- START Unpacking signal 22 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[15]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[14]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o23 = result;
            }
          }

          /* --------------- START Unpacking signal 23 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[17]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[16]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o24 = result;
            }
          }

          /* --------------- START Unpacking signal 24 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[19]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[18]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o25 = result;
            }
          }

          /* --------------- START Unpacking signal 25 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[21]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[20]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o26 = result;
            }
          }

          /* --------------- START Unpacking signal 26 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[23]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[22]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o27 = result;
            }
          }

          /* --------------- START Unpacking signal 27 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[25]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[24]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o28 = result;
            }
          }

          /* --------------- START Unpacking signal 28 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[27]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[26]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o29 = result;
            }
          }

          /* --------------- START Unpacking signal 29 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[29]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[28]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o30 = result;
            }
          }

          /* --------------- START Unpacking signal 30 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[56]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o31 = result;
            }
          }

          /* --------------- START Unpacking signal 31 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[55]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[54]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o32 = result;
            }
          }

          /* --------------- START Unpacking signal 32 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[53]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o33 = result;
            }
          }

          /* --------------- START Unpacking signal 33 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[52]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[51]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o34 = result;
            }
          }

          /* --------------- START Unpacking signal 34 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[47]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o35 = result;
            }
          }

          /* --------------- START Unpacking signal 35 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[46]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[45]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o36 = result;
            }
          }

          /* --------------- START Unpacking signal 36 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[50]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o37 = result;
            }
          }

          /* --------------- START Unpacking signal 37 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[49]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[48]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack_o38 = result;
            }
          }

          /* --------------- START Unpacking signal 38 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[57]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              BCU_TimeWeek = result;
            }
          }

          /* --------------- START Unpacking signal 39 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[60]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              BCU_TimeDay = result;
            }
          }

          /* --------------- START Unpacking signal 40 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[61]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              BCU_TimeHour = result;
            }
          }

          /* --------------- START Unpacking signal 41 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[62]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              BCU_TimeMinute = result;
            }
          }

          /* --------------- START Unpacking signal 42 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[59]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              BCU_TimeMonth = result;
            }
          }

          /* --------------- START Unpacking signal 43 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[63]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              BCU_TimeSencond = result;
            }
          }

          /* --------------- START Unpacking signal 44 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[58]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              BCU_TimeYear = result;
            }
          }
        }
      }
    }
  }

  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack3_o7), 4.2949673E+9F);
  data_index = u < 0.0F ? (uint32_T)-(int32_T)(uint32_T)-u : (uint32_T)u;
  u = 0.00999999F * (real32_T)CANFDRcvFcn_BCU_B.CANFDUnpack1_o18;
  if (u >= 0.5F) {
    tmp = (int32_T)floorf(u + 0.5F);
  } else {
    tmp = 0;
  }

  BCU_SOC = (uint16_T)fmodf((real32_T)tmp, 65536.0F);

  {
    /* S-Function (scanfdunpack): '<S1>/CAN FD Unpack2' */
    if ((64 == CANFDRcvMsg.Length) && (CANFDRcvMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180210E4== CANFDRcvMsg.ID) && (1U == CANFDRcvMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANFDRcvMsg.Data[5]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[4]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[3]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (CANFDRcvMsg.Data[2]) << 24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[21]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[22]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[7]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[10]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o7 = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[9]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o8 = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[11]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o9 = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[6]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o10 = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[20]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o11 = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[18]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o12 = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[19]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o13 = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[17]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o14 = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[16]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o15 = result;
            }
          }

          /* --------------- START Unpacking signal 15 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[29]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o16 = result;
            }
          }

          /* --------------- START Unpacking signal 16 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[28]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o17 = result;
            }
          }

          /* --------------- START Unpacking signal 17 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[27]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o18 = result;
            }
          }

          /* --------------- START Unpacking signal 18 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[25]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o19 = result;
            }
          }

          /* --------------- START Unpacking signal 19 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[15]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o20 = result;
            }
          }

          /* --------------- START Unpacking signal 20 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[14]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o21 = result;
            }
          }

          /* --------------- START Unpacking signal 21 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[13]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o22 = result;
            }
          }

          /* --------------- START Unpacking signal 22 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[26]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o23 = result;
            }
          }

          /* --------------- START Unpacking signal 23 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[24]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o24 = result;
            }
          }

          /* --------------- START Unpacking signal 24 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[12]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o25 = result;
            }
          }

          /* --------------- START Unpacking signal 25 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[23]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o26 = result;
            }
          }

          /* --------------- START Unpacking signal 26 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[36]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o27 = result;
            }
          }

          /* --------------- START Unpacking signal 27 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[33]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[32]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o28 = result;
            }
          }

          /* --------------- START Unpacking signal 28 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[37]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o29 = result;
            }
          }

          /* --------------- START Unpacking signal 29 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[35]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o30 = result;
            }
          }

          /* --------------- START Unpacking signal 30 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[31]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[30]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o31 = result;
            }
          }

          /* --------------- START Unpacking signal 31 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[38]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o32 = result;
            }
          }

          /* --------------- START Unpacking signal 32 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[46]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o33 = result;
            }
          }

          /* --------------- START Unpacking signal 33 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[49]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[48]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o34 = result;
            }
          }

          /* --------------- START Unpacking signal 34 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[39]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o35 = result;
            }
          }

          /* --------------- START Unpacking signal 35 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[47]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o36 = result;
            }
          }

          /* --------------- START Unpacking signal 36 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[52]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[51]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o37 = result;
            }
          }

          /* --------------- START Unpacking signal 37 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[41]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[40]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o38 = result;
            }
          }

          /* --------------- START Unpacking signal 38 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[42]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o39 = result;
            }
          }

          /* --------------- START Unpacking signal 39 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[43]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o40 = result;
            }
          }

          /* --------------- START Unpacking signal 40 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[50]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o41 = result;
            }
          }

          /* --------------- START Unpacking signal 41 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[45]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[44]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o42 = result;
            }
          }

          /* --------------- START Unpacking signal 42 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[53]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o43 = result;
            }
          }

          /* --------------- START Unpacking signal 43 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[55]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[54]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o44 = result;
            }
          }

          /* --------------- START Unpacking signal 44 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[56]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o45 = result;
            }
          }

          /* --------------- START Unpacking signal 45 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[58]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[57]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack2_o46 = result;
            }
          }
        }
      }
    }
  }

  u = 10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack1_o24;
  v = fabsf(u);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      u = floorf(u + 0.5F);
    } else {
      u = 0.0F;
    }
  }

  u = fmodf(u, 65536.0F);
  rtb_DataTypeConversion29 = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-u : (int32_T)(uint16_T)u);

  {
    /* S-Function (scanfdunpack): '<S1>/CAN FD Unpack4' */
    if ((64 == CANFDRcvMsg.Length) && (CANFDRcvMsg.ID != INVALID_CAN_ID) ) {
      if ((0x1B0110E4== CANFDRcvMsg.ID) && (1U == CANFDRcvMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[2]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[3]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[4]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[5]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[6]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[7]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o7 = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[8]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o8 = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[9]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o9 = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[10]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o10 = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[11]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o11 = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[12]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o12 = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[13]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o13 = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[14]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o14 = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[15]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o15 = result;
            }
          }

          /* --------------- START Unpacking signal 15 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[16]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o16 = result;
            }
          }

          /* --------------- START Unpacking signal 16 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[17]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o17 = result;
            }
          }

          /* --------------- START Unpacking signal 17 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[18]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o18 = result;
            }
          }

          /* --------------- START Unpacking signal 18 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[19]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o19 = result;
            }
          }

          /* --------------- START Unpacking signal 19 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[20]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o20 = result;
            }
          }

          /* --------------- START Unpacking signal 20 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[21]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o21 = result;
            }
          }

          /* --------------- START Unpacking signal 21 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[22]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o22 = result;
            }
          }

          /* --------------- START Unpacking signal 22 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[23]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o23 = result;
            }
          }

          /* --------------- START Unpacking signal 23 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[24]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o24 = result;
            }
          }

          /* --------------- START Unpacking signal 24 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[25]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o25 = result;
            }
          }

          /* --------------- START Unpacking signal 25 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[26]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o26 = result;
            }
          }

          /* --------------- START Unpacking signal 26 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[27]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o27 = result;
            }
          }

          /* --------------- START Unpacking signal 27 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[28]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o28 = result;
            }
          }

          /* --------------- START Unpacking signal 28 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[29]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o29 = result;
            }
          }

          /* --------------- START Unpacking signal 29 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[30]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o30 = result;
            }
          }

          /* --------------- START Unpacking signal 30 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[31]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o31 = result;
            }
          }

          /* --------------- START Unpacking signal 31 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[32]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o32 = result;
            }
          }

          /* --------------- START Unpacking signal 32 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[33]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o33 = result;
            }
          }

          /* --------------- START Unpacking signal 33 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[34]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o34 = result;
            }
          }

          /* --------------- START Unpacking signal 34 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[35]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o35 = result;
            }
          }

          /* --------------- START Unpacking signal 35 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[36]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o36 = result;
            }
          }

          /* --------------- START Unpacking signal 36 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[37]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o37 = result;
            }
          }

          /* --------------- START Unpacking signal 37 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[38]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o38 = result;
            }
          }

          /* --------------- START Unpacking signal 38 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[39]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o39 = result;
            }
          }

          /* --------------- START Unpacking signal 39 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[40]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o40 = result;
            }
          }

          /* --------------- START Unpacking signal 40 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[41]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o41 = result;
            }
          }

          /* --------------- START Unpacking signal 41 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[42]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o42 = result;
            }
          }

          /* --------------- START Unpacking signal 42 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[43]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o43 = result;
            }
          }

          /* --------------- START Unpacking signal 43 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[44]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o44 = result;
            }
          }

          /* --------------- START Unpacking signal 44 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[45]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o45 = result;
            }
          }

          /* --------------- START Unpacking signal 45 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[46]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o46 = result;
            }
          }

          /* --------------- START Unpacking signal 46 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[47]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o47 = result;
            }
          }

          /* --------------- START Unpacking signal 47 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[48]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o48 = result;
            }
          }

          /* --------------- START Unpacking signal 48 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[49]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o49 = result;
            }
          }

          /* --------------- START Unpacking signal 49 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[50]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o50 = result;
            }
          }

          /* --------------- START Unpacking signal 50 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[51]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o51 = result;
            }
          }

          /* --------------- START Unpacking signal 51 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[52]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o52 = result;
            }
          }

          /* --------------- START Unpacking signal 52 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[53]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o53 = result;
            }
          }

          /* --------------- START Unpacking signal 53 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[54]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o54 = result;
            }
          }

          /* --------------- START Unpacking signal 54 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[55]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o55 = result;
            }
          }

          /* --------------- START Unpacking signal 55 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[56]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o56 = result;
            }
          }

          /* --------------- START Unpacking signal 56 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[57]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o57 = result;
            }
          }

          /* --------------- START Unpacking signal 57 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[58]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o58 = result;
            }
          }

          /* --------------- START Unpacking signal 58 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[59]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o59 = result;
            }
          }

          /* --------------- START Unpacking signal 59 ------------------*/
          {
            int16_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[60]);
                }

                unpackedValue = tempValue;
              }

              outValue = (int16_T) (unpackedValue);
            }

            {
              int16_T result = (int16_T) outValue;
              result = result + -40;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o60 = result;
            }
          }

          /* --------------- START Unpacking signal 60 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack4_o61 = result;
            }
          }
        }
      }
    }
  }

  if ((uint8_T)(CANFDRcvFcn_BCU_B.CANFDUnpack4_o61 - 1) <= 1) {
    port_index = (uint8_T)(CANFDRcvFcn_BCU_B.CANFDUnpack4_o61 - 1);
  } else {
    port_index = 1U;
  }

  rtb_TmpSignalConversionAtSFun_a[0] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o1;
  rtb_TmpSignalConversionAtSFun_a[1] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o2;
  rtb_TmpSignalConversionAtSFun_a[2] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o3;
  rtb_TmpSignalConversionAtSFun_a[3] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o4;
  rtb_TmpSignalConversionAtSFun_a[4] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o5;
  rtb_TmpSignalConversionAtSFun_a[5] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o6;
  rtb_TmpSignalConversionAtSFun_a[6] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o7;
  rtb_TmpSignalConversionAtSFun_a[7] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o8;
  rtb_TmpSignalConversionAtSFun_a[8] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o9;
  rtb_TmpSignalConversionAtSFun_a[9] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o10;
  rtb_TmpSignalConversionAtSFun_a[10] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o11;
  rtb_TmpSignalConversionAtSFun_a[11] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o12;
  rtb_TmpSignalConversionAtSFun_a[12] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o13;
  rtb_TmpSignalConversionAtSFun_a[13] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o14;
  rtb_TmpSignalConversionAtSFun_a[14] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o15;
  rtb_TmpSignalConversionAtSFun_a[15] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o16;
  rtb_TmpSignalConversionAtSFun_a[16] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o17;
  rtb_TmpSignalConversionAtSFun_a[17] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o18;
  rtb_TmpSignalConversionAtSFun_a[18] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o19;
  rtb_TmpSignalConversionAtSFun_a[19] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o20;
  rtb_TmpSignalConversionAtSFun_a[20] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o21;
  rtb_TmpSignalConversionAtSFun_a[21] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o22;
  rtb_TmpSignalConversionAtSFun_a[22] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o23;
  rtb_TmpSignalConversionAtSFun_a[23] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o24;
  rtb_TmpSignalConversionAtSFun_a[24] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o25;
  rtb_TmpSignalConversionAtSFun_a[25] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o26;
  rtb_TmpSignalConversionAtSFun_a[26] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o27;
  rtb_TmpSignalConversionAtSFun_a[27] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o28;
  rtb_TmpSignalConversionAtSFun_a[28] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o29;
  rtb_TmpSignalConversionAtSFun_a[29] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o30;
  rtb_TmpSignalConversionAtSFun_a[30] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o31;
  rtb_TmpSignalConversionAtSFun_a[31] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o32;
  rtb_TmpSignalConversionAtSFun_a[32] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o33;
  rtb_TmpSignalConversionAtSFun_a[33] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o34;
  rtb_TmpSignalConversionAtSFun_a[34] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o35;
  rtb_TmpSignalConversionAtSFun_a[35] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o36;
  rtb_TmpSignalConversionAtSFun_a[36] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o37;
  rtb_TmpSignalConversionAtSFun_a[37] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o38;
  rtb_TmpSignalConversionAtSFun_a[38] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o39;
  rtb_TmpSignalConversionAtSFun_a[39] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o40;
  rtb_TmpSignalConversionAtSFun_a[40] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o41;
  rtb_TmpSignalConversionAtSFun_a[41] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o42;
  rtb_TmpSignalConversionAtSFun_a[42] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o43;
  rtb_TmpSignalConversionAtSFun_a[43] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o44;
  rtb_TmpSignalConversionAtSFun_a[44] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o45;
  rtb_TmpSignalConversionAtSFun_a[45] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o46;
  rtb_TmpSignalConversionAtSFun_a[46] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o47;
  rtb_TmpSignalConversionAtSFun_a[47] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o48;
  rtb_TmpSignalConversionAtSFun_a[48] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o49;
  rtb_TmpSignalConversionAtSFun_a[49] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o50;
  rtb_TmpSignalConversionAtSFun_a[50] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o51;
  rtb_TmpSignalConversionAtSFun_a[51] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o52;
  rtb_TmpSignalConversionAtSFun_a[52] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o53;
  rtb_TmpSignalConversionAtSFun_a[53] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o54;
  rtb_TmpSignalConversionAtSFun_a[54] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o55;
  rtb_TmpSignalConversionAtSFun_a[55] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o56;
  rtb_TmpSignalConversionAtSFun_a[56] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o57;
  rtb_TmpSignalConversionAtSFun_a[57] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o58;
  rtb_TmpSignalConversionAtSFun_a[58] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o59;
  rtb_TmpSignalConversionAtSFun_a[59] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack4_o60;
  if ((uint8_T)(CANFDRcvFcn_BCU_B.CANFDUnpack4_o61 - 1) <= 1) {
    port_len = (uint8_T)(CANFDRcvFcn_BCU_B.CANFDUnpack4_o61 - 1);
  } else {
    port_len = 1U;
  }

  port_len = port_len * 60U + 1U;
  b = (uint16_T)(port_index * 60U + 1U);
  c = (uint16_T)(port_index * 60U + 60U);
  for (i = b; i <= c; i++) {
    CANFDRcvFcn_BCU_DW.tmp_a[i - 1] = rtb_TmpSignalConversionAtSFun_a[i -
      (int32_T)port_len];
  }

  {
    /* S-Function (scanfdunpack): '<S1>/CAN FD Unpack5' */
    if ((64 == CANFDRcvMsg.Length) && (CANFDRcvMsg.ID != INVALID_CAN_ID) ) {
      if ((0x1A0110E4== CANFDRcvMsg.ID) && (1U == CANFDRcvMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[2]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[1]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[4]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[3]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[6]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[5]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[8]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[7]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[10]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[9]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[12]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[11]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[14]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[13]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o7 = result;
            }
          }

          /* --------------- START Unpacking signal 7 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[16]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[15]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o8 = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[18]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[17]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o9 = result;
            }
          }

          /* --------------- START Unpacking signal 9 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[20]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[19]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o10 = result;
            }
          }

          /* --------------- START Unpacking signal 10 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[22]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[21]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o11 = result;
            }
          }

          /* --------------- START Unpacking signal 11 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[24]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[23]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o12 = result;
            }
          }

          /* --------------- START Unpacking signal 12 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[26]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[25]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o13 = result;
            }
          }

          /* --------------- START Unpacking signal 13 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[28]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[27]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o14 = result;
            }
          }

          /* --------------- START Unpacking signal 14 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[30]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[29]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o15 = result;
            }
          }

          /* --------------- START Unpacking signal 15 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[32]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[31]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o16 = result;
            }
          }

          /* --------------- START Unpacking signal 16 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[34]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[33]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o17 = result;
            }
          }

          /* --------------- START Unpacking signal 17 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[36]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[35]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o18 = result;
            }
          }

          /* --------------- START Unpacking signal 18 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[38]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[37]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o19 = result;
            }
          }

          /* --------------- START Unpacking signal 19 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[40]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[39]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o20 = result;
            }
          }

          /* --------------- START Unpacking signal 20 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[42]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[41]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o21 = result;
            }
          }

          /* --------------- START Unpacking signal 21 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[44]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[43]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o22 = result;
            }
          }

          /* --------------- START Unpacking signal 22 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[46]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[45]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o23 = result;
            }
          }

          /* --------------- START Unpacking signal 23 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[48]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[47]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o24 = result;
            }
          }

          /* --------------- START Unpacking signal 24 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[50]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[49]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o25 = result;
            }
          }

          /* --------------- START Unpacking signal 25 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[52]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[51]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o26 = result;
            }
          }

          /* --------------- START Unpacking signal 26 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[54]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[53]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o27 = result;
            }
          }

          /* --------------- START Unpacking signal 27 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[56]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[55]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o28 = result;
            }
          }

          /* --------------- START Unpacking signal 28 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[58]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[57]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o29 = result;
            }
          }

          /* --------------- START Unpacking signal 29 ------------------*/
          {
            uint16_T outValue = 0;

            {
              uint16_T unpackedValue = 0;

              {
                uint16_T tempValue = (uint16_T) (0);

                {
                  tempValue = tempValue | (uint16_T)(CANFDRcvMsg.Data[60]);
                  tempValue = tempValue | (uint16_T)((uint16_T)
                    (CANFDRcvMsg.Data[59]) << 8);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint16_T) (unpackedValue);
            }

            {
              uint16_T result = (uint16_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o30 = result;
            }
          }

          /* --------------- START Unpacking signal 30 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANFDRcvMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANFDRcvFcn_BCU_B.CANFDUnpack5_o31 = result;
            }
          }
        }
      }
    }
  }

  if ((uint8_T)(CANFDRcvFcn_BCU_B.CANFDUnpack5_o31 - 1) <= 7) {
    rtb_Saturation2 = (uint8_T)(CANFDRcvFcn_BCU_B.CANFDUnpack5_o31 - 1);
  } else {
    rtb_Saturation2 = 7U;
  }

  rtb_TmpSignalConversionAtSFu_kh[0] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o1) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[1] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o2) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[2] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o3) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[3] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o4) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[4] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o5) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[5] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o6) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[6] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o7) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[7] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o8) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[8] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o9) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[9] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o10) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[10] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o11) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[11] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o12) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[12] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o13) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[13] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o14) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[14] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o15) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[15] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o16) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[16] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o17) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[17] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o18) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[18] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o19) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[19] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o20) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[20] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o21) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[21] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o22) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[22] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o23) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[23] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o24) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[24] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o25) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[25] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o26) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[26] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o27) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[27] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o28) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[28] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o29) >> 19);
  rtb_TmpSignalConversionAtSFu_kh[29] = (uint16_T)((52429U *
    CANFDRcvFcn_BCU_B.CANFDUnpack5_o30) >> 19);
  port_len = rtb_Saturation2 * 30U + 1U;
  b_0 = (uint8_T)((uint8_T)(rtb_Saturation2 * 30) + 1);
  rtb_Saturation2 = (uint8_T)((uint8_T)(rtb_Saturation2 * 30) + 30);
  for (i_0 = b_0; i_0 <= rtb_Saturation2; i_0++) {
    CANFDRcvFcn_BCU_DW.tmp[i_0 - 1] = rtb_TmpSignalConversionAtSFu_kh[i_0 -
      (uint8_T)port_len];
  }

  CANFDRcvFcn_BCU_B.CFunction11 = (uint16_T)((CANFDRcvFcn_BCU_B.CFunction11 &
    4294967294U) | CANFDRcvFcn_BCU_ConstB.DataTypeConversion27);
  CANFDRcvFcn_BCU_B.CFunction11 = (uint16_T)((CANFDRcvFcn_BCU_B.CFunction11 &
    4294967293U) | (uint32_T)(CANFDRcvFcn_BCU_ConstB.DataTypeConversion28 << 1));
  CANFDRcvFcn_BCU_B.CFunction11 = (uint16_T)((CANFDRcvFcn_BCU_B.CFunction11 &
    4294967291U) | (uint32_T)(CANFDRcvFcn_BCU_ConstB.DataTypeConversion29 << 2));
  CANFDRcvFcn_BCU_B.CFunction11 = (uint16_T)((CANFDRcvFcn_BCU_B.CFunction11 &
    4294967287U) | (uint32_T)(CANFDRcvFcn_BCU_ConstB.DataTypeConversion30 << 3));
  CANFDRcvFcn_BCU_B.CFunction11 = (uint16_T)((CANFDRcvFcn_BCU_B.CFunction11 &
    4294967279U) | (uint32_T)((CANFDRcvFcn_BCU_B.CANFDUnpack3_o31 != 0) << 4));
  CANFDRcvFcn_BCU_B.CFunction11 = (uint16_T)((CANFDRcvFcn_BCU_B.CFunction11 &
    4294967263U) | (uint32_T)(CANFDRcvFcn_BCU_ConstB.DataTypeConversion38 << 5));
  CANFDRcvFcn_BCU_DW.U32_to_F32_float_value = (uint32_T)rtb_DataTypeConversion29
    /10.0f;                            // 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚规潪顒勬晸閺傘倖瀚归柨鐔告灮閹凤拷

  // 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�1闁跨喐鏋婚幏铚傚▏闁跨喐鏋婚幏锟� memcpy闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹烽攱瀵氶柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归悮鎿冨墾閹风柉鎮曢柨鐔告灮閹风兘鏁撻敓锟�
  memcpy(&CANFDRcvFcn_BCU_DW.U32_to_F32_float_bits,
         &CANFDRcvFcn_BCU_DW.U32_to_F32_float_value, sizeof(float));

  // 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2闁跨喐鏋婚幏椋庢纯闁跨喐鏋婚幏閿嬪瘹闁跨喐鏋婚幏鐤祮闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸鏉堝啴娼婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閻氭搩鍓ㄩ幏鐑芥晸閺傘倖瀚归拃宥夋晸閺傘倖瀚归柨鐕傛嫹
  // float_bits = *(uint32_t *)&float_value;

  // 闁跨喐鏋婚幏宄板絿闁跨喕顢滈懞鍌︾秶閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閿燂拷 DCBA闁跨喐鏋婚幏锟�
  CANFDRcvFcn_BCU_DW.U32_to_F32_byteD =
    (CANFDRcvFcn_BCU_DW.U32_to_F32_float_bits >> 24) & 0xFF;// 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔峰建瑜濋幏椋庣剨闁跨噦鎷�
  CANFDRcvFcn_BCU_DW.U32_to_F32_byteC =
    (CANFDRcvFcn_BCU_DW.U32_to_F32_float_bits >> 16) & 0xFF;
  CANFDRcvFcn_BCU_DW.U32_to_F32_byteB =
    (CANFDRcvFcn_BCU_DW.U32_to_F32_float_bits >> 8) & 0xFF;
  CANFDRcvFcn_BCU_DW.U32_to_F32_byteA = CANFDRcvFcn_BCU_DW.U32_to_F32_float_bits
    & 0xFF;                            // 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔峰建瑜濋幏椋庣剨闁跨噦鎷�

  // 闁跨喐鏋婚幏鐑芥憵闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐕傛嫹 16 娴ｅ秹鏁撴笟銉ㄦ彧閹风兘鏁撻弬銈嗗
  CANFDRcvFcn_BCU_B.BCU_V4_L = (CANFDRcvFcn_BCU_DW.U32_to_F32_byteD << 8) |
    CANFDRcvFcn_BCU_DW.U32_to_F32_byteC;// DC 闁跨喍鑼庢潏鐐闁跨喐鏋婚幏锟�
  CANFDRcvFcn_BCU_B.BCU_V4_H = (CANFDRcvFcn_BCU_DW.U32_to_F32_byteB << 8) |
    CANFDRcvFcn_BCU_DW.U32_to_F32_byteA;// BA 闁跨喍鑼庢潏鐐闁跨喐鏋婚幏锟�
  u = 10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack1_o3;
  v = fabsf(u);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      u = floorf(u + 0.5F);
    } else {
      u = 0.0F;
    }
  }

  u = fmodf(u, 4.2949673E+9F);
  CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_float_value = (u < 0.0F ? -(int32_T)
    (uint32_T)-u : (int32_T)(uint32_T)u)/10.0f;// 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚规潪顒勬晸閺傘倖瀚归柨鐔告灮閹凤拷

  // 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�1闁跨喐鏋婚幏铚傚▏闁跨喐鏋婚幏锟� memcpy闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹烽攱瀵氶柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归悮鎿冨墾閹风柉鎮曢柨鐔告灮閹风兘鏁撻敓锟�
  memcpy(&CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_float_bits,
         &CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_float_value, sizeof(float));

  // 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�2闁跨喐鏋婚幏椋庢纯闁跨喐鏋婚幏閿嬪瘹闁跨喐鏋婚幏鐤祮闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸鏉堝啴娼婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閻氭搩鍓ㄩ幏鐑芥晸閺傘倖瀚归拃宥夋晸閺傘倖瀚归柨鐕傛嫹
  // float_bits = *(uint32_t *)&float_value;

  // 闁跨喐鏋婚幏宄板絿闁跨喕顢滈懞鍌︾秶閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閿燂拷 DCBA闁跨喐鏋婚幏锟�
  CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_byteD =
    (CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_float_bits >> 24) & 0xFF;// 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔峰建瑜濋幏椋庣剨闁跨噦鎷�
  CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_byteC =
    (CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_float_bits >> 16) & 0xFF;
  CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_byteB =
    (CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_float_bits >> 8) & 0xFF;
  CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_byteA =
    CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_float_bits & 0xFF;// 闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔峰建瑜濋幏椋庣剨闁跨噦鎷�

  // 闁跨喐鏋婚幏鐑芥憵闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐕傛嫹 16 娴ｅ秹鏁撴笟銉ㄦ彧閹风兘鏁撻弬銈嗗
  CANFDRcvFcn_BCU_B.BCU_Curr2_L = (CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_byteD <<
    8) | CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_byteC;// DC 闁跨喍鑼庢潏鐐闁跨喐鏋婚幏锟�
  CANFDRcvFcn_BCU_B.BCU_Curr2_H = (CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_byteB <<
    8) | CANFDRcvFcn_BCU_DW.U32_to_Folat_Curr_byteA;// BA 闁跨喍鑼庢潏鐐闁跨喐鏋婚幏锟�
  rtb_TmpSignalConversionAtSFunct[0] = BCU_SystemWorkMode;
  rtb_TmpSignalConversionAtSFunct[1] = 0U;
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack1_o4), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[2] = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack1_o5), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[3] = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  rtb_TmpSignalConversionAtSFunct[4] = (uint16_T)((uint32_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack1_o14 << 2) |
    CANFDRcvFcn_BCU_B.CANFDUnpack1_o15 | (uint32_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack1_o16 << 4));
  rtb_TmpSignalConversionAtSFunct[5] = BCU_SystemStatus;
  rtb_TmpSignalConversionAtSFunct[6] = 0U;
  rtb_TmpSignalConversionAtSFunct[7] = 0U;
  rtb_TmpSignalConversionAtSFunct[8] = 0U;
  rtb_TmpSignalConversionAtSFunct[9] = CFunction_o1;
  rtb_TmpSignalConversionAtSFunct[10] = CFunction_o2;
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack3_o3), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[11] = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  rtb_TmpSignalConversionAtSFunct[12] = CFunction1_o1;
  rtb_TmpSignalConversionAtSFunct[13] = CFunction1_o2;
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack3_o6), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[14] = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  rtb_TmpSignalConversionAtSFunct[15] = CANFDRcvFcn_BCU_B.CANFDUnpack_o16;
  rtb_TmpSignalConversionAtSFunct[16] = CANFDRcvFcn_BCU_B.CANFDUnpack_o17;
  rtb_TmpSignalConversionAtSFunct[17] = CANFDRcvFcn_BCU_B.CANFDUnpack_o18;
  rtb_TmpSignalConversionAtSFunct[18] = CANFDRcvFcn_BCU_B.CANFDUnpack_o19;
  rtb_TmpSignalConversionAtSFunct[19] = CANFDRcvFcn_BCU_B.CANFDUnpack_o20;
  rtb_TmpSignalConversionAtSFunct[20] = CANFDRcvFcn_BCU_B.CANFDUnpack_o21;
  rtb_TmpSignalConversionAtSFunct[21] = CANFDRcvFcn_BCU_B.CANFDUnpack_o22;
  rtb_TmpSignalConversionAtSFunct[22] = CANFDRcvFcn_BCU_B.CANFDUnpack_o23;
  rtb_TmpSignalConversionAtSFunct[23] = CANFDRcvFcn_BCU_B.CANFDUnpack_o24;
  rtb_TmpSignalConversionAtSFunct[24] = CANFDRcvFcn_BCU_B.CANFDUnpack_o25;
  rtb_TmpSignalConversionAtSFunct[25] = CANFDRcvFcn_BCU_B.CANFDUnpack_o26;
  rtb_TmpSignalConversionAtSFunct[26] = CANFDRcvFcn_BCU_B.CANFDUnpack_o27;
  rtb_TmpSignalConversionAtSFunct[27] = CANFDRcvFcn_BCU_B.CANFDUnpack_o28;
  rtb_TmpSignalConversionAtSFunct[28] = CANFDRcvFcn_BCU_B.CANFDUnpack_o29;
  rtb_TmpSignalConversionAtSFunct[29] = CANFDRcvFcn_BCU_B.CANFDUnpack_o30;
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack3_o4), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[30] = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  rtb_TmpSignalConversionAtSFunct[31] = (uint16_T)(data_index & 65535U);
  rtb_TmpSignalConversionAtSFunct[32] = (uint16_T)(data_index >> 16);
  rtb_TmpSignalConversionAtSFunct[33] = CANFDRcvFcn_BCU_B.CANFDUnpack_o31;
  rtb_TmpSignalConversionAtSFunct[34] = CANFDRcvFcn_BCU_B.CANFDUnpack_o32;
  rtb_TmpSignalConversionAtSFunct[35] = CANFDRcvFcn_BCU_B.CANFDUnpack_o33;
  rtb_TmpSignalConversionAtSFunct[36] = CANFDRcvFcn_BCU_B.CANFDUnpack_o34;
  rtb_TmpSignalConversionAtSFunct[37] = CANFDRcvFcn_BCU_B.CANFDUnpack_o35;
  rtb_TmpSignalConversionAtSFunct[38] = CANFDRcvFcn_BCU_B.CANFDUnpack_o36;
  rtb_TmpSignalConversionAtSFunct[39] = CANFDRcvFcn_BCU_B.CANFDUnpack_o37;
  rtb_TmpSignalConversionAtSFunct[40] = CANFDRcvFcn_BCU_B.CANFDUnpack_o38;
  rtb_TmpSignalConversionAtSFunct[41] = (uint16_T)(BCU_FaultInfoLv1H >> 16);
  rtb_TmpSignalConversionAtSFunct[42] = (uint16_T)(BCU_FaultInfoLv1H & 65535U);
  rtb_TmpSignalConversionAtSFunct[43] = (uint16_T)(BCU_FaultInfoLv1L >> 16);
  rtb_TmpSignalConversionAtSFunct[44] = (uint16_T)(BCU_FaultInfoLv1L & 65535U);
  rtb_TmpSignalConversionAtSFunct[45] = (uint16_T)(BCU_FaultInfoLv2H >> 16);
  rtb_TmpSignalConversionAtSFunct[46] = (uint16_T)(BCU_FaultInfoLv2H & 65535U);
  rtb_TmpSignalConversionAtSFunct[47] = (uint16_T)(BCU_FaultInfoLv2L >> 16);
  rtb_TmpSignalConversionAtSFunct[48] = (uint16_T)(BCU_FaultInfoLv2L & 65535U);
  rtb_TmpSignalConversionAtSFunct[49] = (uint16_T)(BCU_FaultInfoLv3H >> 16);
  rtb_TmpSignalConversionAtSFunct[50] = (uint16_T)(BCU_FaultInfoLv3H & 65535U);
  rtb_TmpSignalConversionAtSFunct[51] = (uint16_T)(BCU_FaultInfoLv3L >> 16);
  rtb_TmpSignalConversionAtSFunct[52] = (uint16_T)(BCU_FaultInfoLv3L & 65535U);
  rtb_TmpSignalConversionAtSFunct[53] = (uint16_T)(BCU_FaultInfoLv4H >> 16);
  rtb_TmpSignalConversionAtSFunct[54] = (uint16_T)(BCU_FaultInfoLv4H & 65535U);
  rtb_TmpSignalConversionAtSFunct[55] = (uint16_T)(BCU_FaultInfoLv4L >> 16);
  rtb_TmpSignalConversionAtSFunct[56] = CANFDRcvFcn_BCU_B.CANFDUnpack3_o10;
  rtb_TmpSignalConversionAtSFunct[57] = CANFDRcvFcn_BCU_B.CANFDUnpack3_o8;
  rtb_TmpSignalConversionAtSFunct[58] = CANFDRcvFcn_BCU_B.CANFDUnpack3_o9;
  rtb_TmpSignalConversionAtSFunct[59] = BCU_SOC;
  u = 0.00999999F * (real32_T)CANFDRcvFcn_BCU_B.CANFDUnpack1_o20;
  if (u >= 0.5F) {
    tmp = (int32_T)floorf(u + 0.5F);
  } else {
    tmp = 0;
  }

  rtb_TmpSignalConversionAtSFunct[60] = (uint16_T)fmodf((real32_T)tmp, 65536.0F);
  rtb_TmpSignalConversionAtSFunct[61] = (uint16_T)
    ((CANFDRcvFcn_BCU_B.CANFDUnpack2_o1 << 8) +
     CANFDRcvFcn_BCU_B.CANFDUnpack2_o2);
  rtb_TmpSignalConversionAtSFunct[62] = 0U;
  rtb_TmpSignalConversionAtSFunct[63] = (uint16_T)((uint16_T)((uint16_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack2_o7 - 1) << 4) +
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o8);
  rtb_TmpSignalConversionAtSFunct[64] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o6;
  rtb_TmpSignalConversionAtSFunct[65] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o9;
  rtb_TmpSignalConversionAtSFunct[66] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o10;
  rtb_TmpSignalConversionAtSFunct[67] = 0U;
  if (CANFDRcvFcn_BCU_B.CANFDUnpack2_o14 > 16) {
    b_0 = 16U;
  } else if (CANFDRcvFcn_BCU_B.CANFDUnpack2_o14 < 1) {
    b_0 = 1U;
  } else {
    b_0 = CANFDRcvFcn_BCU_B.CANFDUnpack2_o14;
  }

  rtb_TmpSignalConversionAtSFunct[68] = (uint16_T)((int32_T)((uint32_T)((b_0 - 1)
    << 7) + ((uint32_T)CANFDRcvFcn_BCU_B.CANFDUnpack2_o15 << 3)) >> 3);
  rtb_TmpSignalConversionAtSFunct[69] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o20;
  if (CANFDRcvFcn_BCU_B.CANFDUnpack2_o21 > 16) {
    b_0 = 16U;
  } else if (CANFDRcvFcn_BCU_B.CANFDUnpack2_o21 < 1) {
    b_0 = 1U;
  } else {
    b_0 = CANFDRcvFcn_BCU_B.CANFDUnpack2_o21;
  }

  rtb_TmpSignalConversionAtSFunct[70] = (uint16_T)((int32_T)((uint32_T)((b_0 - 1)
    << 7) + ((uint32_T)CANFDRcvFcn_BCU_B.CANFDUnpack2_o22 << 3)) >> 3);
  rtb_TmpSignalConversionAtSFunct[71] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o25;
  rtb_TmpSignalConversionAtSFunct[72] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o16;
  rtb_TmpSignalConversionAtSFunct[73] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o17;
  rtb_TmpSignalConversionAtSFunct[74] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o18;
  rtb_TmpSignalConversionAtSFunct[75] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o19;
  rtb_TmpSignalConversionAtSFunct[76] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o23;
  rtb_TmpSignalConversionAtSFunct[77] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o24;
  rtb_TmpSignalConversionAtSFunct[78] =
    CANFDRcvFcn_BCU_ConstB.DataTypeConversion67;
  rtb_TmpSignalConversionAtSFunct[79] = 0U;
  rtb_TmpSignalConversionAtSFunct[80] =
    CANFDRcvFcn_BCU_ConstB.DataTypeConversion68;
  rtb_TmpSignalConversionAtSFunct[81] = 0U;
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack1_o2), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[82] = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  u = 10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack1_o22;
  v = fabsf(u);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      u = floorf(u + 0.5F);
    } else {
      u = 0.0F;
    }
  }

  u = fmodf(u, 65536.0F);
  rtb_TmpSignalConversionAtSFunct[83] = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  u = 10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack1_o23;
  v = fabsf(u);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      u = floorf(u + 0.5F);
    } else {
      u = 0.0F;
    }
  }

  u = fmodf(u, 65536.0F);
  rtb_TmpSignalConversionAtSFunct[84] = (uint16_T)(u < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  rtb_TmpSignalConversionAtSFunct[85] = rtb_DataTypeConversion29;
  rtb_TmpSignalConversionAtSFunct[86] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o28;
  rtb_TmpSignalConversionAtSFunct[87] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o31;
  rtb_TmpSignalConversionAtSFunct[88] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o29;
  rtb_TmpSignalConversionAtSFunct[89] = 0U;
  if (CANFDRcvFcn_BCU_B.CANFDUnpack2_o27 > 16) {
    b_0 = 16U;
  } else if (CANFDRcvFcn_BCU_B.CANFDUnpack2_o27 < 1) {
    b_0 = 1U;
  } else {
    b_0 = CANFDRcvFcn_BCU_B.CANFDUnpack2_o27;
  }

  rtb_TmpSignalConversionAtSFunct[90] = (uint16_T)((int32_T)((uint32_T)((b_0 - 1)
    << 7) + ((uint32_T)CANFDRcvFcn_BCU_B.CANFDUnpack2_o30 << 3)) >> 3);
  rtb_TmpSignalConversionAtSFunct[91] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o38;
  rtb_TmpSignalConversionAtSFunct[92] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o42;
  rtb_TmpSignalConversionAtSFunct[93] = (uint16_T)((int32_T)((uint32_T)((uint8_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack2_o39 - 1) << 7) + ((uint32_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o40 << 3)) >> 3);
  rtb_TmpSignalConversionAtSFunct[94] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o33;
  rtb_TmpSignalConversionAtSFunct[95] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o34;
  rtb_TmpSignalConversionAtSFunct[96] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o36;
  rtb_TmpSignalConversionAtSFunct[97] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o37;
  rtb_TmpSignalConversionAtSFunct[98] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o41;
  rtb_TmpSignalConversionAtSFunct[99] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o43;
  rtb_TmpSignalConversionAtSFunct[100] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o44;
  rtb_TmpSignalConversionAtSFunct[101] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o45;
  rtb_TmpSignalConversionAtSFunct[102] = CANFDRcvFcn_BCU_B.CANFDUnpack2_o46;
  rtb_TmpSignalConversionAtSFunct[103] = (uint16_T)(BCU_FaultInfoLv4L & 65535U);
  memcpy(&rtb_TmpSignalConversionAtSFunct[104], &CANFDRcvFcn_BCU_DW.tmp_a[0],
         120U * sizeof(uint16_T));
  memcpy(&rtb_TmpSignalConversionAtSFunct[224], &CANFDRcvFcn_BCU_DW.tmp[0], 240U
         * sizeof(uint16_T));
  rtb_TmpSignalConversionAtSFunct[464] = (uint16_T)((int32_T)((uint32_T)
    ((uint8_T)(CANFDRcvFcn_BCU_B.CANFDUnpack2_o32 - 1) << 7) + ((uint32_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o35 << 3)) >> 3);
  rtb_TmpSignalConversionAtSFunct[465] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o21;
  rtb_TmpSignalConversionAtSFunct[466] = CANFDRcvFcn_BCU_B.CANFDUnpack3_o22;
  rtb_TmpSignalConversionAtSFunct[467] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o33;
  rtb_TmpSignalConversionAtSFunct[468] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o26;
  rtb_TmpSignalConversionAtSFunct[469] = CANFDRcvFcn_BCU_B.CANFDUnpack3_o39;
  rtb_TmpSignalConversionAtSFunct[470] = (uint16_T)(10 *
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o40);
  rtb_TmpSignalConversionAtSFunct[471] = (uint16_T)(10 *
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o41);
  rtb_TmpSignalConversionAtSFunct[472] = (uint16_T)(10 *
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o42);
  u = 0.00999999F * (real32_T)CANFDRcvFcn_BCU_B.CANFDUnpack1_o17;
  if (u >= 0.5F) {
    tmp = (int32_T)floorf(u + 0.5F);
  } else {
    tmp = 0;
  }

  rtb_TmpSignalConversionAtSFunct[473] = (uint16_T)fmodf((real32_T)tmp, 65536.0F);
  rtb_TmpSignalConversionAtSFunct[474] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o23;
  rtb_TmpSignalConversionAtSFunct[475] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o30;
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack3_o24), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[476] = (uint16_T)(u < 0.0F ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack3_o27), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[477] = (uint16_T)(u < 0.0F ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  rtb_TmpSignalConversionAtSFunct[478] = CANFDRcvFcn_BCU_B.CFunction11;
  rtb_TmpSignalConversionAtSFunct[479] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o12;
  rtb_TmpSignalConversionAtSFunct[480] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o13;
  rtb_TmpSignalConversionAtSFunct[481] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack2_o11;
  u = fmodf(floorf(10.0F * CANFDRcvFcn_BCU_B.CANFDUnpack1_o25), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[482] = (uint16_T)(u < 0.0F ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  rtb_TmpSignalConversionAtSFunct[483] =
    CANFDRcvFcn_BCU_ConstB.DataTypeConversion65;
  rtb_TmpSignalConversionAtSFunct[484] = CANFDRcvFcn_BCU_B.CANFDUnpack3_o25;
  rtb_TmpSignalConversionAtSFunct[485] = (uint16_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack2_o3 >> 16);
  rtb_TmpSignalConversionAtSFunct[486] = (uint16_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack2_o3 & 65535U);
  u = fmodf(floorf(CANFDRcvFcn_BCU_B.CANFDUnpack1_o21), 65536.0F);
  rtb_TmpSignalConversionAtSFunct[487] = (uint16_T)(u < 0.0F ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-u : (int32_T)(uint16_T)u);
  rtb_TmpSignalConversionAtSFunct[488] =
    CANFDRcvFcn_BCU_ConstB.DataTypeConversion72;
  rtb_TmpSignalConversionAtSFunct[489] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o1;
  rtb_TmpSignalConversionAtSFunct[490] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o2;
  rtb_TmpSignalConversionAtSFunct[491] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o3;
  rtb_TmpSignalConversionAtSFunct[492] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o4;
  rtb_TmpSignalConversionAtSFunct[493] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o5;
  rtb_TmpSignalConversionAtSFunct[494] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o6;
  rtb_TmpSignalConversionAtSFunct[495] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o7;
  rtb_TmpSignalConversionAtSFunct[496] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o8;
  rtb_TmpSignalConversionAtSFunct[497] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o9;
  rtb_TmpSignalConversionAtSFunct[498] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o10;
  rtb_TmpSignalConversionAtSFunct[499] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o11;
  rtb_TmpSignalConversionAtSFunct[500] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o12;
  rtb_TmpSignalConversionAtSFunct[501] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o13;
  rtb_TmpSignalConversionAtSFunct[502] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o14;
  rtb_TmpSignalConversionAtSFunct[503] = (uint16_T)
    CANFDRcvFcn_BCU_B.CANFDUnpack_o15;
  rtb_TmpSignalConversionAtSFunct[504] = (uint16_T)((uint32_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack3_o28 << 8) |
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o29);
  rtb_TmpSignalConversionAtSFunct[505] = (uint16_T)((uint32_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack3_o35 << 8) |
    CANFDRcvFcn_BCU_B.CANFDUnpack3_o36);
  rtb_TmpSignalConversionAtSFunct[506] = CANFDRcvFcn_BCU_B.CANFDUnpack3_o34;
  rtb_TmpSignalConversionAtSFunct[507] = (uint16_T)((uint32_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack3_o15 - 8388608) >> 16);
  rtb_TmpSignalConversionAtSFunct[508] = (uint16_T)((uint32_T)
    (CANFDRcvFcn_BCU_B.CANFDUnpack3_o15 - 8388608) & 65535U);
  rtb_TmpSignalConversionAtSFunct[509] = CANFDRcvFcn_BCU_B.BCU_V4_H;
  rtb_TmpSignalConversionAtSFunct[510] = CANFDRcvFcn_BCU_B.BCU_V4_L;
  rtb_TmpSignalConversionAtSFunct[511] = CFunction_o1;
  rtb_TmpSignalConversionAtSFunct[512] = CFunction_o2;
  rtb_TmpSignalConversionAtSFunct[513] = CFunction1_o1;
  rtb_TmpSignalConversionAtSFunct[514] = CFunction1_o2;
  rtb_TmpSignalConversionAtSFunct[515] = CANFDRcvFcn_BCU_B.BCU_Curr2_H;
  rtb_TmpSignalConversionAtSFunct[516] = CANFDRcvFcn_BCU_B.BCU_Curr2_L;
  data_index = 0U;
  port_index = 0U;
  port_len = sizeof(uint32_T);
  if (port_len == 0U) {
    port_len = MAX_uint32_T;

    /* Divide by zero handler */
  } else {
    port_len = sizeof(uint32_T [131]) / port_len;
  }
#if 1
// 闁革负鍔岄幆濠囨偝椤栨艾顤呮繛锝堫嚙婵拷

  while (port_index < port_len) 
  {
    if (CANFDRcvFcn_BCU_ConstP.portDimensions_Value[port_index] == 1U) 
    {           
      modbusBuff[CANFDRcvFcn_BCU_ConstP.index_Value[port_index]] =
        rtb_TmpSignalConversionAtSFunct[data_index];
      // if(data_index == 515){
      //   printf("515modbusBuff[%d] = %d\r\n",CANFDRcvFcn_BCU_ConstP.index_Value[port_index],modbusBuff[CANFDRcvFcn_BCU_ConstP.index_Value[port_index]]);
      // }
      //       if(data_index == 516){
      //   printf("516modbusBuff[%d] = %d\r\n",CANFDRcvFcn_BCU_ConstP.index_Value[port_index],modbusBuff[CANFDRcvFcn_BCU_ConstP.index_Value[port_index]]);
      // }
      qY = data_index + 1U;
      if (data_index + 1U < data_index) {
        qY = MAX_uint32_T;
      }

      data_index = qY;
    } else {
      i = 0U;
      while (i < CANFDRcvFcn_BCU_ConstP.portDimensions_Value[port_index]) {
        q0 = CANFDRcvFcn_BCU_ConstP.index_Value[port_index];
        qY = q0 + i;
        if (qY < q0) {
          qY = MAX_uint32_T;
        }

        modbusBuff[qY] = rtb_TmpSignalConversionAtSFunct[data_index];
        qY = data_index + 1U;
        if (data_index + 1U < data_index) {
          qY = MAX_uint32_T;
        }

        data_index = qY;
        tmp = i + 1;
        if (i + 1 > 65535) {
          tmp = 65535;
        }

        i = (uint16_T)tmp;
      }
    }

    port_index++;
  }
  #endif
}

/* Model initialize function */
void CANFDRcvFcn_BCU_initialize(void)
{
  /*-----------S-Function Block: <S1>/CAN FD Unpack1 -----------------*/

  /*-----------S-Function Block: <S1>/CAN FD Unpack3 -----------------*/

  /*-----------S-Function Block: <S1>/CAN FD Unpack -----------------*/

  /*-----------S-Function Block: <S1>/CAN FD Unpack2 -----------------*/

  /*-----------S-Function Block: <S1>/CAN FD Unpack4 -----------------*/

  /*-----------S-Function Block: <S1>/CAN FD Unpack5 -----------------*/
}

/* Model terminate function */
void CANFDRcvFcn_BCU_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
