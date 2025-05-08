//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FxTDiffSim.cpp
//
// Code generated for Simulink model 'FxTDiffSim'.
//
// Model version                  : 1.31
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:11 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FxTDiffSim.h"
#include "rtwtypes.h"
#include "FxTDiffSim_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rt_powd_snf.h"

P_FxTDiffSim_T FxTDiffSim_P = {
  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Memory1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Memory2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.002,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<Root>/Constant2'

  1.0,

  // Expression: 2
  //  Referenced by: '<Root>/Gain'

  2.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant3'

  1.0,

  // Expression: 2
  //  Referenced by: '<Root>/Gain1'

  2.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator1'

  0.002,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0;0;0;0]
  //  Referenced by: '<Root>/Constant'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(4, 1)
  //  Referenced by: '<Root>/Constant1'

  { 0.0, 0.0, 0.0, 0.0 }
};

// System initialize for referenced model: 'FxTDiffSim'
void FxTDiffSim_Init(DW_FxTDiffSim_f_T *localDW)
{
  for (int32_T i = 0; i < 6; i++) {
    // InitializeConditions for Memory: '<Root>/Memory1'
    localDW->Memory1_PreviousInput[i] = FxTDiffSim_P.Memory1_InitialCondition[i];

    // InitializeConditions for Memory: '<Root>/Memory2'
    localDW->Memory2_PreviousInput[i] = FxTDiffSim_P.Memory2_InitialCondition[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE[i] =
      FxTDiffSim_P.DiscreteTimeIntegrator_IC[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' 
    localDW->DiscreteTimeIntegrator1_DSTATE[i] =
      FxTDiffSim_P.DiscreteTimeIntegrator1_IC[i];
  }
}

// Output and update for referenced model: 'FxTDiffSim'
void FxTDiffSim(const real_T rtu_pos[3], const real_T rtu_att[3], const real_T
                rtu_PX4Params_FxTDiffg_G1[6], const real_T
                rtu_PX4Params_FxTDiffg_G2[6], const real_T
                rtu_PX4Params_FxTDiffg_lam1[6], const real_T
                rtu_PX4Params_FxTDiffg_vrho1[6], real_T rty_state_hat_pos_hat[6],
                real_T rty_state_hat_pos_dot_hat[6], real_T
                rty_state_hat_pos_ddot_hat[6], real_T rty_state_hat_e_hat[6],
                real_T rty_state_hat_q_hat[4], real_T rty_state_hat_q_tilde[4],
                B_FxTDiffSim_c_T *localB, DW_FxTDiffSim_f_T *localDW)
{
  real_T Memory1_PreviousInput;
  real_T Memory2_PreviousInput;
  real_T gamma_hat_1_tmp_tmp;
  real_T gamma_hat_1_tmp_tmp_0;
  real_T tmp;
  int32_T i;
  boolean_T tmp_0;

  // Memory: '<Root>/Memory1'
  for (i = 0; i < 6; i++) {
    rty_state_hat_pos_hat[i] = localDW->Memory1_PreviousInput[i];
  }

  // End of Memory: '<Root>/Memory1'

  // Sum: '<Root>/Sum1'
  rty_state_hat_e_hat[0] = rtu_pos[0] - rty_state_hat_pos_hat[0];
  rty_state_hat_e_hat[3] = rtu_att[0] - rty_state_hat_pos_hat[3];
  rty_state_hat_e_hat[1] = rtu_pos[1] - rty_state_hat_pos_hat[1];
  rty_state_hat_e_hat[4] = rtu_att[1] - rty_state_hat_pos_hat[4];
  rty_state_hat_e_hat[2] = rtu_pos[2] - rty_state_hat_pos_hat[2];
  rty_state_hat_e_hat[5] = rtu_att[2] - rty_state_hat_pos_hat[5];

  // Constant: '<Root>/Constant1'
  rty_state_hat_q_tilde[0] = FxTDiffSim_P.Constant1_Value[0];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant1'

  rty_state_hat_q_hat[0] = FxTDiffSim_P.Constant1_Value[0];

  // Constant: '<Root>/Constant1'
  rty_state_hat_q_tilde[1] = FxTDiffSim_P.Constant1_Value[1];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant1'

  rty_state_hat_q_hat[1] = FxTDiffSim_P.Constant1_Value[1];

  // Constant: '<Root>/Constant1'
  rty_state_hat_q_tilde[2] = FxTDiffSim_P.Constant1_Value[2];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant1'

  rty_state_hat_q_hat[2] = FxTDiffSim_P.Constant1_Value[2];

  // Constant: '<Root>/Constant1'
  rty_state_hat_q_tilde[3] = FxTDiffSim_P.Constant1_Value[3];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant1'

  rty_state_hat_q_hat[3] = FxTDiffSim_P.Constant1_Value[3];
  for (i = 0; i < 6; i++) {
    // Memory: '<Root>/Memory2'
    Memory2_PreviousInput = localDW->Memory2_PreviousInput[i];
    rty_state_hat_pos_dot_hat[i] = Memory2_PreviousInput;

    // Signum: '<Root>/Sign' incorporates:
    //   Product: '<Root>/Product3'

    localB->rty_state_hat_e_hat = rty_state_hat_e_hat[i];

    // Math: '<Root>/Power' incorporates:
    //   Product: '<Root>/Product3'

    localB->rtu_PX4Params_FxTDiffg_lam1 = rtu_PX4Params_FxTDiffg_lam1[i];

    // Math: '<Root>/Power1' incorporates:
    //   Product: '<Root>/Product3'

    localB->rtu_PX4Params_FxTDiffg_vrho1 = rtu_PX4Params_FxTDiffg_vrho1[i];

    // Signum: '<Root>/Sign' incorporates:
    //   Signum: '<Root>/Sign1'
    //   Signum: '<Root>/Sign2'

    tmp_0 = rtIsNaN(localB->rty_state_hat_e_hat);
    if (tmp_0) {
      tmp = (rtNaN);
    } else if (localB->rty_state_hat_e_hat < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (localB->rty_state_hat_e_hat > 0.0);
    }

    // Product: '<Root>/Product3' incorporates:
    //   Product: '<Root>/Product4'
    //   Signum: '<Root>/Sign'

    gamma_hat_1_tmp_tmp = rtu_PX4Params_FxTDiffg_G1[i] * tmp;

    // Abs: '<Root>/Abs' incorporates:
    //   Abs: '<Root>/Abs1'
    //   Abs: '<Root>/Abs2'
    //   Abs: '<Root>/Abs3'

    gamma_hat_1_tmp_tmp_0 = fabs(localB->rty_state_hat_e_hat);

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
    //   Abs: '<Root>/Abs'
    //   Math: '<Root>/Power'
    //   Math: '<Root>/Power1'
    //   Memory: '<Root>/Memory2'
    //   Product: '<Root>/Product3'
    //   Product: '<Root>/Product4'
    //   Sum: '<Root>/Sum3'

    gamma_hat_1_tmp_tmp = ((gamma_hat_1_tmp_tmp * rt_powd_snf
      (gamma_hat_1_tmp_tmp_0, localB->rtu_PX4Params_FxTDiffg_lam1) +
      Memory2_PreviousInput) + gamma_hat_1_tmp_tmp * rt_powd_snf
      (gamma_hat_1_tmp_tmp_0, localB->rtu_PX4Params_FxTDiffg_vrho1)) *
      FxTDiffSim_P.DiscreteTimeIntegrator_gainval;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    Memory1_PreviousInput = localDW->DiscreteTimeIntegrator_DSTATE[i] +
      gamma_hat_1_tmp_tmp;
    localDW->Memory1_PreviousInput[i] = Memory1_PreviousInput;

    // Signum: '<Root>/Sign2' incorporates:
    //   Signum: '<Root>/Sign3'

    if (tmp_0) {
      tmp = (rtNaN);
    } else if (localB->rty_state_hat_e_hat < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (localB->rty_state_hat_e_hat > 0.0);
    }

    // Product: '<Root>/Product5' incorporates:
    //   Product: '<Root>/Product6'
    //   Signum: '<Root>/Sign2'

    Memory2_PreviousInput = rtu_PX4Params_FxTDiffg_G2[i] * tmp;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
    //   Constant: '<Root>/Constant2'
    //   Constant: '<Root>/Constant3'
    //   Gain: '<Root>/Gain'
    //   Gain: '<Root>/Gain1'
    //   Math: '<Root>/Power2'
    //   Math: '<Root>/Power3'
    //   Product: '<Root>/Product5'
    //   Product: '<Root>/Product6'
    //   Sum: '<Root>/Sum'
    //   Sum: '<Root>/Sum2'
    //   Sum: '<Root>/Sum4'

    localB->rtu_PX4Params_FxTDiffg_lam1 = (rt_powd_snf(gamma_hat_1_tmp_tmp_0,
      FxTDiffSim_P.Gain_Gain * localB->rtu_PX4Params_FxTDiffg_lam1 -
      FxTDiffSim_P.Constant2_Value) * Memory2_PreviousInput + rt_powd_snf
      (gamma_hat_1_tmp_tmp_0, FxTDiffSim_P.Gain1_Gain *
       localB->rtu_PX4Params_FxTDiffg_vrho1 - FxTDiffSim_P.Constant3_Value) *
      Memory2_PreviousInput) * FxTDiffSim_P.DiscreteTimeIntegrator1_gainval;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
    Memory2_PreviousInput = localDW->DiscreteTimeIntegrator1_DSTATE[i] +
      localB->rtu_PX4Params_FxTDiffg_lam1;
    localDW->Memory2_PreviousInput[i] = Memory2_PreviousInput;

    // Constant: '<Root>/Constant'
    rty_state_hat_pos_ddot_hat[i] = FxTDiffSim_P.Constant_Value[i];

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localDW->DiscreteTimeIntegrator_DSTATE[i] = Memory1_PreviousInput +
      gamma_hat_1_tmp_tmp;

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
    localDW->DiscreteTimeIntegrator1_DSTATE[i] = Memory2_PreviousInput +
      localB->rtu_PX4Params_FxTDiffg_lam1;
  }
}

// Model initialize function
void FxTDiffSim_initialize(const char_T **rt_errorStatus, RT_MODEL_FxTDiffSim_T *
  const FxTDiffSim_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  FxTDiffSim_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_FxTDiffSim_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_FxTDiffSim_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_FxTDiffSim_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_FxTDiffSim_T::setErrorStatus(const char_T* const aErrorStatus)
  const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
