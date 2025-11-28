/*
 * File: CANFDRcvFcn_BCU.h
 *
 * Code generated for Simulink model 'CANFDRcvFcn_BCU'.
 *
 * Model version                  : 5.102
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Nov 28 16:29:16 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef CANFDRcvFcn_BCU_h_
#define CANFDRcvFcn_BCU_h_
#ifndef CANFDRcvFcn_BCU_COMMON_INCLUDES_
#define CANFDRcvFcn_BCU_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "can_fd_message.h"
#endif                                 /* CANFDRcvFcn_BCU_COMMON_INCLUDES_ */

#include "CANFDRcvFcn_BCU_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "modbustcp_task.h"

/* Block signals (default storage) */
typedef struct {
  uint32_T CANFDUnpack2_o3;            /* '<S1>/CAN FD Unpack2' */
  real32_T CANFDUnpack1_o2;            /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o3;            /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o4;            /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o5;            /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o17;           /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o22;           /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o23;           /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o24;           /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o25;           /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o26;           /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack1_o27;           /* '<S1>/CAN FD Unpack1' */
  real32_T CANFDUnpack3_o6;            /* '<S1>/CAN FD Unpack3' */
  real32_T CANFDUnpack3_o7;            /* '<S1>/CAN FD Unpack3' */
  real32_T CANFDUnpack3_o8;            /* '<S1>/CAN FD Unpack3' */
  real32_T CANFDUnpack3_o9;            /* '<S1>/CAN FD Unpack3' */
  real32_T CANFDUnpack3_o10;           /* '<S1>/CAN FD Unpack3' */
  real32_T CANFDUnpack3_o11;           /* '<S1>/CAN FD Unpack3' */
  real32_T CANFDUnpack3_o27;           /* '<S1>/CAN FD Unpack3' */
  real32_T CANFDUnpack3_o30;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack1_o18;           /* '<S1>/CAN FD Unpack1' */
  uint16_T CANFDUnpack1_o19;           /* '<S1>/CAN FD Unpack1' */
  uint16_T CANFDUnpack1_o20;           /* '<S1>/CAN FD Unpack1' */
  uint16_T CANFDUnpack1_o21;           /* '<S1>/CAN FD Unpack1' */
  uint16_T BCU_Curr2_H;                /* '<S1>/U32_to_Folat_Curr' */
  uint16_T BCU_Curr2_L;                /* '<S1>/U32_to_Folat_Curr' */
  uint16_T CANFDUnpack3_o1;            /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o2;            /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o3;            /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o4;            /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o5;            /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o12;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o13;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o14;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o15;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o16;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o17;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o18;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o25;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o28;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o31;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o32;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o34;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o35;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o38;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o39;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o40;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o41;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack3_o42;           /* '<S1>/CAN FD Unpack3' */
  uint16_T CANFDUnpack_o16;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o17;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o18;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o19;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o20;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o21;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o22;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o23;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o24;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o25;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o26;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o27;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o28;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o29;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o30;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o31;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o32;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o33;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o34;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o35;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o36;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o37;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack_o38;            /* '<S1>/CAN FD Unpack' */
  uint16_T CANFDUnpack2_o7;            /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o8;            /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o9;            /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o16;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o17;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o18;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o23;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o28;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o29;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o31;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o33;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o34;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o36;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o37;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o38;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o41;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o42;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o43;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o44;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o45;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack2_o46;           /* '<S1>/CAN FD Unpack2' */
  uint16_T CANFDUnpack5_o1;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o2;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o3;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o4;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o5;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o6;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o7;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o8;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o9;            /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o10;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o11;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o12;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o13;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o14;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o15;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o16;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o17;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o18;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o19;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o20;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o21;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o22;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o23;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o24;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o25;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o26;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o27;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o28;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o29;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CANFDUnpack5_o30;           /* '<S1>/CAN FD Unpack5' */
  uint16_T CFunction11;                /* '<S5>/C Function11' */
  uint16_T BCU_RealtimePower_H;        /* '<S1>/U32_to_F32_Power' */
  uint16_T BCU_RealtimePower_L;        /* '<S1>/U32_to_F32_Power' */
  uint16_T BCU_V4_L;                   /* '<S1>/U32_to_F32_V3' */
  uint16_T BCU_V4_H;                   /* '<S1>/U32_to_F32_V3' */
  int16_T CANFDUnpack3_o24;            /* '<S1>/CAN FD Unpack3' */
  int16_T CANFDUnpack3_o26;            /* '<S1>/CAN FD Unpack3' */
  int16_T CANFDUnpack3_o29;            /* '<S1>/CAN FD Unpack3' */
  int16_T CANFDUnpack3_o33;            /* '<S1>/CAN FD Unpack3' */
  int16_T CANFDUnpack3_o36;            /* '<S1>/CAN FD Unpack3' */
  int16_T CANFDUnpack3_o43;            /* '<S1>/CAN FD Unpack3' */
  int16_T CANFDUnpack3_o44;            /* '<S1>/CAN FD Unpack3' */
  int16_T CANFDUnpack3_o45;            /* '<S1>/CAN FD Unpack3' */
  int16_T CANFDUnpack_o1;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o2;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o3;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o4;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o5;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o6;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o7;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o8;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o9;              /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o10;             /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o11;             /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o12;             /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o13;             /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o14;             /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack_o15;             /* '<S1>/CAN FD Unpack' */
  int16_T CANFDUnpack2_o4;             /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o5;             /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o6;             /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o10;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o11;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o12;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o13;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o19;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o20;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o24;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o25;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack2_o26;            /* '<S1>/CAN FD Unpack2' */
  int16_T CANFDUnpack4_o1;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o2;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o3;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o4;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o5;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o6;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o7;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o8;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o9;             /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o10;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o11;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o12;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o13;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o14;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o15;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o16;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o17;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o18;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o19;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o20;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o21;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o22;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o23;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o24;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o25;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o26;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o27;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o28;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o29;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o30;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o31;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o32;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o33;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o34;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o35;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o36;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o37;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o38;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o39;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o40;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o41;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o42;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o43;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o44;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o45;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o46;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o47;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o48;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o49;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o50;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o51;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o52;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o53;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o54;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o55;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o56;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o57;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o58;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o59;            /* '<S1>/CAN FD Unpack4' */
  int16_T CANFDUnpack4_o60;            /* '<S1>/CAN FD Unpack4' */
  uint8_T CANFDUnpack1_o14;            /* '<S1>/CAN FD Unpack1' */
  uint8_T CANFDUnpack1_o15;            /* '<S1>/CAN FD Unpack1' */
  uint8_T CANFDUnpack1_o16;            /* '<S1>/CAN FD Unpack1' */
  uint8_T CANFDUnpack3_o19;            /* '<S1>/CAN FD Unpack3' */
  uint8_T CANFDUnpack3_o20;            /* '<S1>/CAN FD Unpack3' */
  uint8_T CANFDUnpack3_o21;            /* '<S1>/CAN FD Unpack3' */
  uint8_T CANFDUnpack3_o22;            /* '<S1>/CAN FD Unpack3' */
  uint8_T CANFDUnpack3_o23;            /* '<S1>/CAN FD Unpack3' */
  uint8_T CANFDUnpack3_o37;            /* '<S1>/CAN FD Unpack3' */
  uint8_T CANFDUnpack2_o1;             /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o2;             /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o14;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o15;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o21;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o22;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o27;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o30;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o32;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o35;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o39;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack2_o40;            /* '<S1>/CAN FD Unpack2' */
  uint8_T CANFDUnpack4_o61;            /* '<S1>/CAN FD Unpack4' */
  uint8_T CANFDUnpack5_o31;            /* '<S1>/CAN FD Unpack5' */
} B_CANFDRcvFcn_BCU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T U32_to_Folat_Curr_float_value;/* '<S1>/U32_to_Folat_Curr' */
  real32_T U32_to_F32_Power_float_value;/* '<S1>/U32_to_F32_Power' */
  real32_T U32_to_F32_V3_float_value;  /* '<S1>/U32_to_F32_V3' */
  uint32_T U32_to_Folat_Curr_float_bits;/* '<S1>/U32_to_Folat_Curr' */
  uint32_T U32_to_F32_Power_float_bits;/* '<S1>/U32_to_F32_Power' */
  uint32_T U32_to_F32_V3_float_bits;   /* '<S1>/U32_to_F32_V3' */
  int_T CANFDUnpack1_ModeSignalID;     /* '<S1>/CAN FD Unpack1' */
  int_T CANFDUnpack1_StatusPortID;     /* '<S1>/CAN FD Unpack1' */
  int_T CANFDUnpack3_ModeSignalID;     /* '<S1>/CAN FD Unpack3' */
  int_T CANFDUnpack3_StatusPortID;     /* '<S1>/CAN FD Unpack3' */
  int_T CANFDUnpack_ModeSignalID;      /* '<S1>/CAN FD Unpack' */
  int_T CANFDUnpack_StatusPortID;      /* '<S1>/CAN FD Unpack' */
  int_T CANFDUnpack2_ModeSignalID;     /* '<S1>/CAN FD Unpack2' */
  int_T CANFDUnpack2_StatusPortID;     /* '<S1>/CAN FD Unpack2' */
  int_T CANFDUnpack4_ModeSignalID;     /* '<S1>/CAN FD Unpack4' */
  int_T CANFDUnpack4_StatusPortID;     /* '<S1>/CAN FD Unpack4' */
  int_T CANFDUnpack5_ModeSignalID;     /* '<S1>/CAN FD Unpack5' */
  int_T CANFDUnpack5_StatusPortID;     /* '<S1>/CAN FD Unpack5' */
  uint16_T tmp[240];                   /* '<S4>/MATLAB Function2' */
  uint16_T tmp_a[120];                 /* '<S3>/MATLAB Function' */
  uint8_T U32_to_Folat_Curr_byteA;     /* '<S1>/U32_to_Folat_Curr' */
  uint8_T U32_to_Folat_Curr_byteB;     /* '<S1>/U32_to_Folat_Curr' */
  uint8_T U32_to_Folat_Curr_byteC;     /* '<S1>/U32_to_Folat_Curr' */
  uint8_T U32_to_Folat_Curr_byteD;     /* '<S1>/U32_to_Folat_Curr' */
  uint8_T U32_to_F32_Power_byteA;      /* '<S1>/U32_to_F32_Power' */
  uint8_T U32_to_F32_Power_byteB;      /* '<S1>/U32_to_F32_Power' */
  uint8_T U32_to_F32_Power_byteC;      /* '<S1>/U32_to_F32_Power' */
  uint8_T U32_to_F32_Power_byteD;      /* '<S1>/U32_to_F32_Power' */
  uint8_T U32_to_F32_V3_byteA;         /* '<S1>/U32_to_F32_V3' */
  uint8_T U32_to_F32_V3_byteB;         /* '<S1>/U32_to_F32_V3' */
  uint8_T U32_to_F32_V3_byteC;         /* '<S1>/U32_to_F32_V3' */
  uint8_T U32_to_F32_V3_byteD;         /* '<S1>/U32_to_F32_V3' */
} DW_CANFDRcvFcn_BCU_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T DataTypeConversion27;/* '<S5>/Data Type Conversion27' */
  const boolean_T DataTypeConversion28;/* '<S5>/Data Type Conversion28' */
  const boolean_T DataTypeConversion29;/* '<S5>/Data Type Conversion29' */
  const boolean_T DataTypeConversion30;/* '<S5>/Data Type Conversion30' */
  const boolean_T DataTypeConversion38;/* '<S5>/Data Type Conversion38' */
} ConstB_CANFDRcvFcn_BCU_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: index_Value
   * Referenced by: '<Root>/index'
   */
  uint32_T index_Value[126];

  /* Computed Parameter: portDimensions_Value
   * Referenced by: '<Root>/portDimensions'
   */
  uint32_T portDimensions_Value[126];
} ConstP_CANFDRcvFcn_BCU_T;

/* Real-time Model Data Structure */
struct tag_RTM_CANFDRcvFcn_BCU_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_CANFDRcvFcn_BCU_T CANFDRcvFcn_BCU_B;

/* Block states (default storage) */
extern DW_CANFDRcvFcn_BCU_T CANFDRcvFcn_BCU_DW;
extern const ConstB_CANFDRcvFcn_BCU_T CANFDRcvFcn_BCU_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_CANFDRcvFcn_BCU_T CANFDRcvFcn_BCU_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CAN_FD_MESSAGE_BUS CANFDRcvMsg; /* '<Root>/CANFDRcvMsg' */

/* Model entry point functions */
extern void CANFDRcvFcn_BCU_initialize(void);
extern void CANFDRcvFcn_BCU_step(void);
extern void CANFDRcvFcn_BCU_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CANFDRcvFcn_BCU_T *const CANFDRcvFcn_BCU_M;

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern uint32_T BCU_FaultInfoLv1H;     /* '<S1>/CAN FD Unpack1' */
extern uint32_T BCU_FaultInfoLv1L;     /* '<S1>/CAN FD Unpack1' */
extern uint32_T BCU_FaultInfoLv2H;     /* '<S1>/CAN FD Unpack1' */
extern uint32_T BCU_FaultInfoLv2L;     /* '<S1>/CAN FD Unpack1' */
extern uint32_T BCU_FaultInfoLv3H;     /* '<S1>/CAN FD Unpack1' */
extern uint32_T BCU_FaultInfoLv3L;     /* '<S1>/CAN FD Unpack1' */
extern uint32_T BCU_FaultInfoLv4H;     /* '<S1>/CAN FD Unpack1' */
extern uint32_T BCU_FaultInfoLv4L;     /* '<S1>/CAN FD Unpack1' */
extern uint16_T BCU_SOC;               /* '<S1>/Data Type Conversion35' */
extern uint16_T BCU_SystemWorkMode;    /* '<S1>/CAN FD Unpack1' */
extern uint8_T BCU_TimeDay;            /* '<S1>/CAN FD Unpack' */
extern uint8_T BCU_TimeHour;           /* '<S1>/CAN FD Unpack' */
extern uint8_T BCU_TimeMinute;         /* '<S1>/CAN FD Unpack' */
extern uint8_T BCU_TimeMonth;          /* '<S1>/CAN FD Unpack' */
extern uint8_T BCU_TimeSencond;        /* '<S1>/CAN FD Unpack' */
extern uint8_T BCU_TimeWeek;           /* '<S1>/CAN FD Unpack' */
extern uint8_T BCU_TimeYear;           /* '<S1>/CAN FD Unpack' */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CANFDRcvFcn_BCU'
 * '<S1>'   : 'CANFDRcvFcn_BCU/BCU_Info'
 * '<S2>'   : 'CANFDRcvFcn_BCU/Chart1'
 * '<S3>'   : 'CANFDRcvFcn_BCU/BCU_Info/AssginTemp'
 * '<S4>'   : 'CANFDRcvFcn_BCU/BCU_Info/AssginVolt'
 * '<S5>'   : 'CANFDRcvFcn_BCU/BCU_Info/GetChillerFault'
 * '<S6>'   : 'CANFDRcvFcn_BCU/BCU_Info/Subsystem'
 * '<S7>'   : 'CANFDRcvFcn_BCU/BCU_Info/Subsystem1'
 * '<S8>'   : 'CANFDRcvFcn_BCU/BCU_Info/Subsystem2'
 * '<S9>'   : 'CANFDRcvFcn_BCU/BCU_Info/Subsystem3'
 * '<S10>'  : 'CANFDRcvFcn_BCU/BCU_Info/Subsystem4'
 * '<S11>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement'
 * '<S12>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement10'
 * '<S13>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement11'
 * '<S14>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement12'
 * '<S15>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement13'
 * '<S16>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement14'
 * '<S17>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement15'
 * '<S18>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement16'
 * '<S19>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement17'
 * '<S20>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement2'
 * '<S21>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement3'
 * '<S22>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement4'
 * '<S23>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement5'
 * '<S24>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement6'
 * '<S25>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement7'
 * '<S26>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement8'
 * '<S27>'  : 'CANFDRcvFcn_BCU/BCU_Info/Write Measurement9'
 * '<S28>'  : 'CANFDRcvFcn_BCU/BCU_Info/doSomething'
 * '<S29>'  : 'CANFDRcvFcn_BCU/BCU_Info/AssginTemp/MATLAB Function'
 * '<S30>'  : 'CANFDRcvFcn_BCU/BCU_Info/AssginVolt/MATLAB Function2'
 */
#endif                                 /* CANFDRcvFcn_BCU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
