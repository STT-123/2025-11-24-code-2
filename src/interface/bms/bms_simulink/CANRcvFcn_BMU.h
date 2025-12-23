/*
 * File: CANRcvFcn_BMU.h
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

#ifndef CANRcvFcn_BMU_h_
#define CANRcvFcn_BMU_h_
#ifndef CANRcvFcn_BMU_COMMON_INCLUDES_
#define CANRcvFcn_BMU_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "can_message.h"
#endif                                 /* CANRcvFcn_BMU_COMMON_INCLUDES_ */

#include "CANRcvFcn_BMU_types.h"

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
  uint32_T ux180110E16_o1;             /* '<S2>/0x180110E16' */
  uint32_T ux180110E16_o2;             /* '<S2>/0x180110E16' */
  uint32_T ux180110E17_o1;             /* '<S2>/0x180110E17' */
  uint32_T ux180110E17_o2;             /* '<S2>/0x180110E17' */
  uint32_T ux180110E18_o1;             /* '<S2>/0x180110E18' */
  uint32_T ux180110E18_o2;             /* '<S2>/0x180110E18' */
  uint32_T ux180110E19_o1;             /* '<S2>/0x180110E19' */
  uint32_T ux180110E19_o2;             /* '<S2>/0x180110E19' */
  uint32_T ux180110E20_o1;             /* '<S2>/0x180110E20' */
  uint32_T ux180110E20_o2;             /* '<S2>/0x180110E20' */
  uint32_T ux180110E21_o1;             /* '<S2>/0x180110E21' */
  uint32_T ux180110E21_o2;             /* '<S2>/0x180110E21' */
  uint32_T ux180110E22_o1;             /* '<S2>/0x180110E22' */
  uint32_T ux180110E22_o2;             /* '<S2>/0x180110E22' */
  uint32_T ux180110E23_o1;             /* '<S2>/0x180110E23' */
  uint32_T ux180110E23_o2;             /* '<S2>/0x180110E23' */
  uint32_T ux180110E24_o1;             /* '<S2>/0x180110E24' */
  uint32_T ux180110E24_o2;             /* '<S2>/0x180110E24' */
  uint32_T ux180110E25_o1;             /* '<S2>/0x180110E25' */
  uint32_T ux180110E25_o2;             /* '<S2>/0x180110E25' */
  uint32_T ux180110E26_o1;             /* '<S2>/0x180110E26' */
  uint32_T ux180110E26_o2;             /* '<S2>/0x180110E26' */
  uint32_T ux180110E27_o1;             /* '<S2>/0x180110E27' */
  uint32_T ux180110E27_o2;             /* '<S2>/0x180110E27' */
  uint32_T ux180110E28_o1;             /* '<S2>/0x180110E28' */
  uint32_T ux180110E28_o2;             /* '<S2>/0x180110E28' */
  uint32_T ux180110E29_o1;             /* '<S2>/0x180110E29' */
  uint32_T ux180110E29_o2;             /* '<S2>/0x180110E29' */
  uint32_T ux180110E30_o1;             /* '<S2>/0x180110E30' */
  uint32_T ux180110E30_o2;             /* '<S2>/0x180110E30' */
  uint8_T ux180110E4_o1;               /* '<S2>/0x180110E4' */
  uint8_T ux180110E4_o2;               /* '<S2>/0x180110E4' */
  uint8_T ux180110E2_o1;               /* '<S2>/0x180110E2' */
  uint8_T ux180110E2_o2;               /* '<S2>/0x180110E2' */
  uint8_T ux180110E1_o1;               /* '<S2>/0x180110E1' */
  uint8_T ux180110E1_o2;               /* '<S2>/0x180110E1' */
  uint8_T ux180110E5_o1;               /* '<S2>/0x180110E5' */
  uint8_T ux180110E5_o2;               /* '<S2>/0x180110E5' */
  uint8_T ux180110E3_o1;               /* '<S2>/0x180110E3' */
  uint8_T ux180110E3_o2;               /* '<S2>/0x180110E3' */
  uint8_T ux180110E7_o1;               /* '<S2>/0x180110E7' */
  uint8_T ux180110E7_o2;               /* '<S2>/0x180110E7' */
  uint8_T ux180110E6_o1;               /* '<S2>/0x180110E6' */
  uint8_T ux180110E6_o2;               /* '<S2>/0x180110E6' */
  uint8_T ux180110E9_o1;               /* '<S2>/0x180110E9' */
  uint8_T ux180110E9_o2;               /* '<S2>/0x180110E9' */
  uint8_T ux180110E8_o1;               /* '<S2>/0x180110E8' */
  uint8_T ux180110E8_o2;               /* '<S2>/0x180110E8' */
  uint8_T ux180110E11_o1;              /* '<S2>/0x180110E11' */
  uint8_T ux180110E11_o2;              /* '<S2>/0x180110E11' */
  uint8_T ux180110E10_o1;              /* '<S2>/0x180110E10' */
  uint8_T ux180110E10_o2;              /* '<S2>/0x180110E10' */
  uint8_T ux180110E13_o1;              /* '<S2>/0x180110E13' */
  uint8_T ux180110E13_o2;              /* '<S2>/0x180110E13' */
  uint8_T ux180110E12_o1;              /* '<S2>/0x180110E12' */
  uint8_T ux180110E12_o2;              /* '<S2>/0x180110E12' */
  uint8_T ux180110E15_o1;              /* '<S2>/0x180110E15' */
  uint8_T ux180110E15_o2;              /* '<S2>/0x180110E15' */
  uint8_T ux180110E14_o1;              /* '<S2>/0x180110E14' */
  uint8_T ux180110E14_o2;              /* '<S2>/0x180110E14' */
} B_CANRcvFcn_BMU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int_T ux180110E4_ModeSignalID;       /* '<S2>/0x180110E4' */
  int_T ux180110E4_StatusPortID;       /* '<S2>/0x180110E4' */
  int_T ux180110E2_ModeSignalID;       /* '<S2>/0x180110E2' */
  int_T ux180110E2_StatusPortID;       /* '<S2>/0x180110E2' */
  int_T ux180110E1_ModeSignalID;       /* '<S2>/0x180110E1' */
  int_T ux180110E1_StatusPortID;       /* '<S2>/0x180110E1' */
  int_T ux180110E5_ModeSignalID;       /* '<S2>/0x180110E5' */
  int_T ux180110E5_StatusPortID;       /* '<S2>/0x180110E5' */
  int_T ux180110E3_ModeSignalID;       /* '<S2>/0x180110E3' */
  int_T ux180110E3_StatusPortID;       /* '<S2>/0x180110E3' */
  int_T ux180110E7_ModeSignalID;       /* '<S2>/0x180110E7' */
  int_T ux180110E7_StatusPortID;       /* '<S2>/0x180110E7' */
  int_T ux180110E6_ModeSignalID;       /* '<S2>/0x180110E6' */
  int_T ux180110E6_StatusPortID;       /* '<S2>/0x180110E6' */
  int_T ux180110E9_ModeSignalID;       /* '<S2>/0x180110E9' */
  int_T ux180110E9_StatusPortID;       /* '<S2>/0x180110E9' */
  int_T ux180110E8_ModeSignalID;       /* '<S2>/0x180110E8' */
  int_T ux180110E8_StatusPortID;       /* '<S2>/0x180110E8' */
  int_T ux180110E11_ModeSignalID;      /* '<S2>/0x180110E11' */
  int_T ux180110E11_StatusPortID;      /* '<S2>/0x180110E11' */
  int_T ux180110E10_ModeSignalID;      /* '<S2>/0x180110E10' */
  int_T ux180110E10_StatusPortID;      /* '<S2>/0x180110E10' */
  int_T ux180110E13_ModeSignalID;      /* '<S2>/0x180110E13' */
  int_T ux180110E13_StatusPortID;      /* '<S2>/0x180110E13' */
  int_T ux180110E12_ModeSignalID;      /* '<S2>/0x180110E12' */
  int_T ux180110E12_StatusPortID;      /* '<S2>/0x180110E12' */
  int_T ux180110E15_ModeSignalID;      /* '<S2>/0x180110E15' */
  int_T ux180110E15_StatusPortID;      /* '<S2>/0x180110E15' */
  int_T ux180110E14_ModeSignalID;      /* '<S2>/0x180110E14' */
  int_T ux180110E14_StatusPortID;      /* '<S2>/0x180110E14' */
  int_T ux180110E16_ModeSignalID;      /* '<S2>/0x180110E16' */
  int_T ux180110E16_StatusPortID;      /* '<S2>/0x180110E16' */
  int_T ux180110E17_ModeSignalID;      /* '<S2>/0x180110E17' */
  int_T ux180110E17_StatusPortID;      /* '<S2>/0x180110E17' */
  int_T ux180110E18_ModeSignalID;      /* '<S2>/0x180110E18' */
  int_T ux180110E18_StatusPortID;      /* '<S2>/0x180110E18' */
  int_T ux180110E19_ModeSignalID;      /* '<S2>/0x180110E19' */
  int_T ux180110E19_StatusPortID;      /* '<S2>/0x180110E19' */
  int_T ux180110E20_ModeSignalID;      /* '<S2>/0x180110E20' */
  int_T ux180110E20_StatusPortID;      /* '<S2>/0x180110E20' */
  int_T ux180110E21_ModeSignalID;      /* '<S2>/0x180110E21' */
  int_T ux180110E21_StatusPortID;      /* '<S2>/0x180110E21' */
  int_T ux180110E22_ModeSignalID;      /* '<S2>/0x180110E22' */
  int_T ux180110E22_StatusPortID;      /* '<S2>/0x180110E22' */
  int_T ux180110E23_ModeSignalID;      /* '<S2>/0x180110E23' */
  int_T ux180110E23_StatusPortID;      /* '<S2>/0x180110E23' */
  int_T ux180110E24_ModeSignalID;      /* '<S2>/0x180110E24' */
  int_T ux180110E24_StatusPortID;      /* '<S2>/0x180110E24' */
  int_T ux180110E25_ModeSignalID;      /* '<S2>/0x180110E25' */
  int_T ux180110E25_StatusPortID;      /* '<S2>/0x180110E25' */
  int_T ux180110E26_ModeSignalID;      /* '<S2>/0x180110E26' */
  int_T ux180110E26_StatusPortID;      /* '<S2>/0x180110E26' */
  int_T ux180110E27_ModeSignalID;      /* '<S2>/0x180110E27' */
  int_T ux180110E27_StatusPortID;      /* '<S2>/0x180110E27' */
  int_T ux180110E28_ModeSignalID;      /* '<S2>/0x180110E28' */
  int_T ux180110E28_StatusPortID;      /* '<S2>/0x180110E28' */
  int_T ux180110E29_ModeSignalID;      /* '<S2>/0x180110E29' */
  int_T ux180110E29_StatusPortID;      /* '<S2>/0x180110E29' */
  int_T ux180110E30_ModeSignalID;      /* '<S2>/0x180110E30' */
  int_T ux180110E30_StatusPortID;      /* '<S2>/0x180110E30' */
} DW_CANRcvFcn_BMU_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: index_Value
   * Referenced by: '<Root>/index'
   */
  uint32_T index_Value[75];
} ConstP_CANRcvFcn_BMU_T;

/* Real-time Model Data Structure */
struct tag_RTM_CANRcvFcn_BMU_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_CANRcvFcn_BMU_T CANRcvFcn_BMU_B;

/* Block states (default storage) */
extern DW_CANRcvFcn_BMU_T CANRcvFcn_BMU_DW;

/* Constant parameters (default storage) */
extern const ConstP_CANRcvFcn_BMU_T CANRcvFcn_BMU_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CAN_MESSAGE_BUS CANMsg;         /* '<Root>/CANMsg' */

/* Model entry point functions */
extern void CANRcvFcn_BMU_initialize(void);
extern void CANRcvFcn_BMU_step(void);
extern void CANRcvFcn_BMU_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CANRcvFcn_BMU_T *const CANRcvFcn_BMU_M;

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern uint32_T DAqX_FaultCode1[15];   /* '<S2>/Data Type Conversion2' */
extern uint32_T DAqX_FaultCode2[15];   /* '<S2>/Data Type Conversion' */
extern uint16_T DAq_version[15];       /* '<S2>/Data Type Conversion1' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display1' : Unused code path elimination
 */

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
 * '<Root>' : 'CANRcvFcn_BMU'
 * '<S1>'   : 'CANRcvFcn_BMU/Chart1'
 * '<S2>'   : 'CANRcvFcn_BMU/Daq_Info'
 * '<S3>'   : 'CANRcvFcn_BMU/Daq_Info/Write Measurement1'
 * '<S4>'   : 'CANRcvFcn_BMU/Daq_Info/Write Measurement76'
 * '<S5>'   : 'CANRcvFcn_BMU/Daq_Info/Write Measurement80'
 */
#endif                                 /* CANRcvFcn_BMU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
