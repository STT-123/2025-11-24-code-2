/*
 * File: CANRcvFcn_BMU.c
 *
 * Code generated for Simulink model 'CANRcvFcn_BMU'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Nov 25 09:50:30 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CANRcvFcn_BMU.h"
#include "CANRcvFcn_BMU_types.h"
#include "rtwtypes.h"
#include "CANRcvFcn_BMU_private.h"

/* Exported block signals */
CAN_MESSAGE_BUS CANMsg;                /* '<Root>/CANMsg' */

/* Block signals (default storage) */
B_CANRcvFcn_BMU_T CANRcvFcn_BMU_B;

/* Block states (default storage) */
DW_CANRcvFcn_BMU_T CANRcvFcn_BMU_DW;

/* Real-time model */
static RT_MODEL_CANRcvFcn_BMU_T CANRcvFcn_BMU_M_;
RT_MODEL_CANRcvFcn_BMU_T *const CANRcvFcn_BMU_M = &CANRcvFcn_BMU_M_;

/* Model step function */
void CANRcvFcn_BMU_step(void)
{
  uint32_T data_index;
  uint32_T port_index;
  uint32_T port_len;
  uint32_T qY;
  uint16_T rtb_TmpSignalConversionAtSFunct[75];

  /* S-Function (scanunpack): '<S2>/0x180110E4' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E4' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D1 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E4_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E4_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E2' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E2' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D2 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E2_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E2_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E1' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E1' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D3 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E1_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E1_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E5' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E5' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D4 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E5_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E5_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E3' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E3' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D5 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E3_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E3_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E7' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E7' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D6 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E7_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E7_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E6' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E6' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D7 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E6_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E6_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E9' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E9' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D8 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E9_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E9_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E8' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E8' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510D9 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E8_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E8_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E11' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E11' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510DA == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E11_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E11_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E10' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E10' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510DB == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E10_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E10_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E13' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E13' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510DC == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E13_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E13_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E12' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E12' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510DD == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E12_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E12_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E15' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E15' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510DE == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E15_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E15_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E14' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E14' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180510DF == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint8_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[1]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E14_o1 = result;
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
                  tempValue = tempValue | (uint8_T)(CANMsg.Data[0]);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint8_T) (unpackedValue);
            }

            {
              uint8_T result = (uint8_T) outValue;
              CANRcvFcn_BMU_B.ux180110E14_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E16' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E16' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D1 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E16_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E16_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E17' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E17' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D2 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E17_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E17_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E18' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E18' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D3 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E18_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E18_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E19' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E19' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D4 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E19_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E19_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E20' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E20' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D5 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E20_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E20_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E21' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E21' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D6 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E21_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E21_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E22' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E22' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D7 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E22_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E22_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E23' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E23' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D8 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E23_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E23_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E24' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E24' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410D9 == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E24_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E24_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E25' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E25' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410DA == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E25_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E25_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E26' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E26' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410DB == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E26_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E26_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E27' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E27' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410DC == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E27_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E27_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E28' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E28' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410DD == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E28_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E28_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E29' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E29' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410DE == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E29_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E29_o2 = result;
            }
          }
        }
      }
    }
  }

  /* S-Function (scanunpack): '<S2>/0x180110E30' incorporates:
   *  Inport: '<Root>/CANMsg'
   */
  {
    /* S-Function (scanunpack): '<S2>/0x180110E30' */
    if ((8 == CANMsg.Length) && (CANMsg.ID != INVALID_CAN_ID) ) {
      if ((0x180410DF == CANMsg.ID) && (1U == CANMsg.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[3]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[2]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[1]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[0]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E30_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------*/
          {
            uint32_T outValue = 0;

            {
              uint32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);

                {
                  tempValue = tempValue | (uint32_T)(CANMsg.Data[7]);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[6]) <<
                    8);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[5]) <<
                    16);
                  tempValue = tempValue | (uint32_T)((uint32_T)(CANMsg.Data[4]) <<
                    24);
                }

                unpackedValue = tempValue;
              }

              outValue = (uint32_T) (unpackedValue);
            }

            {
              uint32_T result = (uint32_T) outValue;
              CANRcvFcn_BMU_B.ux180110E30_o2 = result;
            }
          }
        }
      }
    }
  }

  /* SignalConversion generated from: '<S1>/ SFunction ' incorporates:
   *  CFunction: '<S2>/C Function1'
   *  CFunction: '<S2>/C Function10'
   *  CFunction: '<S2>/C Function11'
   *  CFunction: '<S2>/C Function12'
   *  CFunction: '<S2>/C Function13'
   *  CFunction: '<S2>/C Function14'
   *  CFunction: '<S2>/C Function15'
   *  CFunction: '<S2>/C Function16'
   *  CFunction: '<S2>/C Function17'
   *  CFunction: '<S2>/C Function18'
   *  CFunction: '<S2>/C Function19'
   *  CFunction: '<S2>/C Function2'
   *  CFunction: '<S2>/C Function20'
   *  CFunction: '<S2>/C Function21'
   *  CFunction: '<S2>/C Function22'
   *  CFunction: '<S2>/C Function23'
   *  CFunction: '<S2>/C Function24'
   *  CFunction: '<S2>/C Function25'
   *  CFunction: '<S2>/C Function26'
   *  CFunction: '<S2>/C Function27'
   *  CFunction: '<S2>/C Function28'
   *  CFunction: '<S2>/C Function29'
   *  CFunction: '<S2>/C Function3'
   *  CFunction: '<S2>/C Function30'
   *  CFunction: '<S2>/C Function31'
   *  CFunction: '<S2>/C Function32'
   *  CFunction: '<S2>/C Function33'
   *  CFunction: '<S2>/C Function34'
   *  CFunction: '<S2>/C Function35'
   *  CFunction: '<S2>/C Function36'
   *  CFunction: '<S2>/C Function37'
   *  CFunction: '<S2>/C Function38'
   *  CFunction: '<S2>/C Function39'
   *  CFunction: '<S2>/C Function4'
   *  CFunction: '<S2>/C Function40'
   *  CFunction: '<S2>/C Function41'
   *  CFunction: '<S2>/C Function42'
   *  CFunction: '<S2>/C Function43'
   *  CFunction: '<S2>/C Function44'
   *  CFunction: '<S2>/C Function45'
   *  CFunction: '<S2>/C Function5'
   *  CFunction: '<S2>/C Function6'
   *  CFunction: '<S2>/C Function7'
   *  CFunction: '<S2>/C Function8'
   *  CFunction: '<S2>/C Function9'
   *  Chart: '<Root>/Chart1'
   */
  rtb_TmpSignalConversionAtSFunct[0] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E4_o2 << 8) | CANRcvFcn_BMU_B.ux180110E4_o1);
  rtb_TmpSignalConversionAtSFunct[1] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E2_o2 << 8) | CANRcvFcn_BMU_B.ux180110E2_o1);
  rtb_TmpSignalConversionAtSFunct[2] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E1_o2 << 8) | CANRcvFcn_BMU_B.ux180110E1_o1);
  rtb_TmpSignalConversionAtSFunct[3] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E5_o2 << 8) | CANRcvFcn_BMU_B.ux180110E5_o1);
  rtb_TmpSignalConversionAtSFunct[4] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E3_o2 << 8) | CANRcvFcn_BMU_B.ux180110E3_o1);
  rtb_TmpSignalConversionAtSFunct[5] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E7_o2 << 8) | CANRcvFcn_BMU_B.ux180110E7_o1);
  rtb_TmpSignalConversionAtSFunct[6] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E6_o2 << 8) | CANRcvFcn_BMU_B.ux180110E6_o1);
  rtb_TmpSignalConversionAtSFunct[7] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E9_o2 << 8) | CANRcvFcn_BMU_B.ux180110E9_o1);
  rtb_TmpSignalConversionAtSFunct[8] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E8_o2 << 8) | CANRcvFcn_BMU_B.ux180110E8_o1);
  rtb_TmpSignalConversionAtSFunct[9] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E11_o2 << 8) | CANRcvFcn_BMU_B.ux180110E11_o1);
  rtb_TmpSignalConversionAtSFunct[10] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E10_o2 << 8) | CANRcvFcn_BMU_B.ux180110E10_o1);
  rtb_TmpSignalConversionAtSFunct[11] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E13_o2 << 8) | CANRcvFcn_BMU_B.ux180110E13_o1);
  rtb_TmpSignalConversionAtSFunct[12] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E12_o2 << 8) | CANRcvFcn_BMU_B.ux180110E12_o1);
  rtb_TmpSignalConversionAtSFunct[13] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E15_o2 << 8) | CANRcvFcn_BMU_B.ux180110E15_o1);
  rtb_TmpSignalConversionAtSFunct[14] = (uint16_T)((uint32_T)
    (CANRcvFcn_BMU_B.ux180110E14_o2 << 8) | CANRcvFcn_BMU_B.ux180110E14_o1);
  rtb_TmpSignalConversionAtSFunct[15] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E16_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[16] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E16_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[17] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E16_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[18] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E16_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[19] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E17_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[20] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E17_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[21] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E17_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[22] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E17_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[23] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E18_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[24] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E18_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[25] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E18_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[26] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E18_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[27] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E19_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[28] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E19_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[29] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E19_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[30] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E19_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[31] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E20_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[32] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E20_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[33] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E20_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[34] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E20_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[35] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E21_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[36] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E21_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[37] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E21_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[38] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E21_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[39] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E22_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[40] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E22_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[41] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E22_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[42] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E22_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[43] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E23_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[44] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E23_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[45] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E23_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[46] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E23_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[47] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E24_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[48] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E24_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[49] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E24_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[50] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E24_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[51] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E25_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[52] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E25_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[53] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E25_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[54] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E25_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[55] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E26_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[56] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E26_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[57] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E26_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[58] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E26_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[59] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E27_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[60] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E27_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[61] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E27_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[62] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E27_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[63] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E28_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[64] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E28_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[65] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E28_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[66] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E28_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[67] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E29_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[68] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E29_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[69] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E29_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[70] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E29_o2 & 65535U);
  rtb_TmpSignalConversionAtSFunct[71] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E30_o1 >> 16);
  rtb_TmpSignalConversionAtSFunct[72] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E30_o1 & 65535U);
  rtb_TmpSignalConversionAtSFunct[73] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E30_o2 >> 16);
  rtb_TmpSignalConversionAtSFunct[74] = (uint16_T)
    (CANRcvFcn_BMU_B.ux180110E30_o2 & 65535U);

  /* Chart: '<Root>/Chart1' incorporates:
   *  Constant: '<Root>/index'
   *  Outport: '<Root>/modbusBuff'
   */
  data_index = 0U;
  port_index = 0U;
  port_len = sizeof(uint32_T);
  if (port_len == 0U) {
    port_len = MAX_uint32_T;

    /* Divide by zero handler */
  } else {
    port_len = sizeof(uint32_T [75]) / port_len;
  }

  while (port_index < port_len) {
    modbusBuff[CANRcvFcn_BMU_ConstP.index_Value[port_index]] =
      rtb_TmpSignalConversionAtSFunct[data_index];
    qY = data_index + /*MW:OvSatOk*/ 1U;
    if (data_index + 1U < data_index) {
      qY = MAX_uint32_T;
    }

    data_index = qY;
    port_index++;
  }
}

/* Model initialize function */
void CANRcvFcn_BMU_initialize(void)
{
  /* Start for S-Function (scanunpack): '<S2>/0x180110E4' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E4 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E2' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E2 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E1' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E1 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E5' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E5 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E3' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E3 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E7' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E7 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E6' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E6 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E9' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E9 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E8' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E8 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E11' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E11 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E10' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E10 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E13' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E13 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E12' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E12 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E15' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E15 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E14' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E14 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E16' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E16 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E17' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E17 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E18' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E18 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E19' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E19 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E20' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E20 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E21' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E21 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E22' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E22 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E23' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E23 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E24' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E24 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E25' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E25 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E26' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E26 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E27' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E27 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E28' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E28 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E29' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E29 -----------------*/

  /* Start for S-Function (scanunpack): '<S2>/0x180110E30' incorporates:
   *  Inport: '<Root>/CANMsg'
   */

  /*-----------S-Function Block: <S2>/0x180110E30 -----------------*/
}

/* Model terminate function */
void CANRcvFcn_BMU_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
