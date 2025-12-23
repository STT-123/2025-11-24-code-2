/*
 * File: CANRcvFcn_BMU_types.h
 *
 * Code generated for Simulink model 'CANRcvFcn_BMU'.
 *
 * Model version                  : 5.11
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Dec 22 13:30:31 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef CANRcvFcn_BMU_types_h_
#define CANRcvFcn_BMU_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} CAN_MESSAGE_BUS;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_CANRcvFcn_BMU_T RT_MODEL_CANRcvFcn_BMU_T;

#endif                                 /* CANRcvFcn_BMU_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
