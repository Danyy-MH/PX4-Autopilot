//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FxTESO.cpp
//
// Code generated for Simulink model 'FxTESO'.
//
// Model version                  : 1.35
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:18 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FxTESO.h"
#include "rtwtypes.h"
#include "FxTESO_private.h"
#include <string.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_powd_snf.h"

P_FxTESO_T FxTESO_P = {
  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Memory'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<Root>/Constant6'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<Root>/Gain5'

  0.5,

  // Expression: [0; 0; -9.81; 0; 0; 0]
  //  Referenced by: '<Root>/Memory2'

  { 0.0, 0.0, -9.81, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<Root>/Constant7'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<Root>/Gain6'

  0.5,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator1'

  0.002,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<Root>/Constant2'

  2.0,

  // Expression: 1/3
  //  Referenced by: '<Root>/Gain3'

  0.33333333333333331,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Memory1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<Root>/Constant4'

  2.0,

  // Expression: 1/3
  //  Referenced by: '<Root>/Gain4'

  0.33333333333333331,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.002,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator2_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator2'

  0.002,

  // Expression: [0; 0; -9.81; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator2'

  { 0.0, 0.0, -9.81, 0.0, 0.0, 0.0 },

  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<Root>/Constant'

  { 1.0, 0.0, 0.0, 0.0 }
};

// System initialize for referenced model: 'FxTESO'
void FxTESO_Init(DW_FxTESO_f_T *localDW)
{
  for (int32_T i = 0; i < 6; i++) {
    // InitializeConditions for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput[i] = FxTESO_P.Memory_InitialCondition[i];

    // InitializeConditions for Memory: '<Root>/Memory2'
    localDW->Memory2_PreviousInput[i] = FxTESO_P.Memory2_InitialCondition[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' 
    localDW->DiscreteTimeIntegrator1_DSTATE[i] =
      FxTESO_P.DiscreteTimeIntegrator1_IC[i];

    // InitializeConditions for Memory: '<Root>/Memory1'
    localDW->Memory1_PreviousInput[i] = FxTESO_P.Memory1_InitialCondition[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE[i] =
      FxTESO_P.DiscreteTimeIntegrator_IC[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' 
    localDW->DiscreteTimeIntegrator2_DSTATE[i] =
      FxTESO_P.DiscreteTimeIntegrator2_IC[i];
  }
}

// Output and update for referenced model: 'FxTESO'
void FxTESO(const real_T rtu_pos[3], const real_T rtu_att[3], const real_T
            rtu_PX4Params_MCg_MCData[5], const real_T
            rtu_PX4Params_FxTQESOg_eps_4[6], const real_T
            rtu_PX4Params_FxTQESOg_mu_1[6], const real_T
            rtu_PX4Params_FxTQESOg_mu_2[6], const real_T
            rtu_PX4Params_FxTQESOg_mu_3[6], const real_T
            rtu_PX4Params_FxTQESOg_alpha_q[6], const real_T
            rtu_PX4Params_FxTQESOg_beta_q[6], const real_T rtu_Fu_Fu[6], real_T
            rty_state_hat_pos_hat[6], real_T rty_state_hat_pos_dot_hat[6],
            real_T rty_state_hat_pos_ddot_hat[6], real_T rty_state_hat_e_hat[6],
            real_T rty_state_hat_q_hat[4], real_T rty_state_hat_q_tilde[4],
            B_FxTESO_c_T *localB, DW_FxTESO_f_T *localDW)
{
  int32_T a;
  int32_T c_j;
  int32_T i;
  int32_T jA;
  int32_T jj;
  int32_T kAcol;
  int32_T n;
  int8_T ipiv[6];
  int8_T p[6];
  int8_T ipiv_0;
  boolean_T tmp;

  // MATLAB Function: '<Root>/MATLAB Function1'
  localB->A[0] = rtu_PX4Params_MCg_MCData[0];
  localB->A[6] = 0.0;
  localB->A[12] = 0.0;
  localB->A[18] = 0.0;
  localB->A[24] = 0.0;
  localB->A[30] = 0.0;
  localB->A[1] = 0.0;
  localB->A[7] = rtu_PX4Params_MCg_MCData[0];
  localB->A[13] = 0.0;
  localB->A[19] = 0.0;
  localB->A[25] = 0.0;
  localB->A[31] = 0.0;
  localB->A[2] = 0.0;
  localB->A[8] = 0.0;
  localB->A[14] = rtu_PX4Params_MCg_MCData[0];
  localB->A[20] = 0.0;
  localB->A[26] = 0.0;
  localB->A[32] = 0.0;
  localB->A[3] = 0.0;
  localB->A[9] = 0.0;
  localB->A[15] = 0.0;
  localB->A[21] = rtu_PX4Params_MCg_MCData[1];
  localB->A[27] = 0.0;
  localB->A[33] = 0.0;
  localB->A[4] = 0.0;
  localB->A[10] = 0.0;
  localB->A[16] = 0.0;
  localB->A[22] = 0.0;
  localB->A[28] = rtu_PX4Params_MCg_MCData[2];
  localB->A[34] = 0.0;
  localB->A[5] = 0.0;
  localB->A[11] = 0.0;
  localB->A[17] = 0.0;
  localB->A[23] = 0.0;
  localB->A[29] = 0.0;
  localB->A[35] = rtu_PX4Params_MCg_MCData[3];
  memset(&localB->M[0], 0, 36U * sizeof(real_T));
  for (c_j = 0; c_j < 6; c_j++) {
    ipiv[c_j] = static_cast<int8_T>(c_j + 1);
  }

  for (c_j = 0; c_j < 5; c_j++) {
    jj = c_j * 7;
    n = 5 - c_j;
    a = 0;
    localB->smax = fabs(localB->A[jj]);
    for (i = 2; i <= n + 1; i++) {
      localB->s = fabs(localB->A[(jj + i) - 1]);
      if (localB->s > localB->smax) {
        a = i - 1;
        localB->smax = localB->s;
      }
    }

    if (localB->A[jj + a] != 0.0) {
      if (a != 0) {
        n = c_j + a;
        ipiv[c_j] = static_cast<int8_T>(n + 1);
        for (i = 0; i < 6; i++) {
          a = i * 6 + c_j;
          localB->smax = localB->A[a];
          jA = i * 6 + n;
          localB->A[a] = localB->A[jA];
          localB->A[jA] = localB->smax;
        }
      }

      n = (jj - c_j) + 6;
      for (i = jj + 2; i <= n; i++) {
        localB->A[i - 1] /= localB->A[jj];
      }
    }

    a = 4 - c_j;
    jA = jj + 8;
    for (i = 0; i <= a; i++) {
      localB->kt_e_tmp_tmp = localB->A[(i * 6 + jj) + 6];
      if (localB->kt_e_tmp_tmp != 0.0) {
        kAcol = (jA - c_j) + 4;
        for (n = jA; n <= kAcol; n++) {
          localB->A[n - 1] += localB->A[((jj + n) - jA) + 1] *
            -localB->kt_e_tmp_tmp;
        }
      }

      jA += 6;
    }
  }

  for (c_j = 0; c_j < 6; c_j++) {
    p[c_j] = static_cast<int8_T>(c_j + 1);
  }

  for (c_j = 0; c_j < 5; c_j++) {
    ipiv_0 = ipiv[c_j];
    if (ipiv_0 > c_j + 1) {
      i = p[ipiv_0 - 1];
      p[ipiv_0 - 1] = p[c_j];
      p[c_j] = static_cast<int8_T>(i);
    }
  }

  for (n = 0; n < 6; n++) {
    a = (p[n] - 1) * 6;
    localB->M[n + a] = 1.0;
    for (jj = n + 1; jj < 7; jj++) {
      c_j = (a + jj) - 1;
      if (localB->M[c_j] != 0.0) {
        for (i = jj + 1; i < 7; i++) {
          jA = (a + i) - 1;
          localB->M[jA] -= localB->A[((jj - 1) * 6 + i) - 1] * localB->M[c_j];
        }
      }
    }
  }

  for (i = 0; i < 6; i++) {
    jA = 6 * i;
    for (n = 5; n >= 0; n--) {
      kAcol = 6 * n;
      c_j = n + jA;
      localB->kt_e_tmp_tmp = localB->M[c_j];
      if (localB->kt_e_tmp_tmp != 0.0) {
        localB->M[c_j] = localB->kt_e_tmp_tmp / localB->A[n + kAcol];
        for (jj = 0; jj < n; jj++) {
          a = jj + jA;
          localB->M[a] -= localB->A[jj + kAcol] * localB->M[c_j];
        }
      }
    }

    // Memory: '<Root>/Memory'
    rty_state_hat_pos_hat[i] = localDW->Memory_PreviousInput[i];
  }

  // End of MATLAB Function: '<Root>/MATLAB Function1'

  // Sum: '<Root>/Sum8'
  rty_state_hat_e_hat[0] = rtu_pos[0] - rty_state_hat_pos_hat[0];
  rty_state_hat_e_hat[3] = rtu_att[0] - rty_state_hat_pos_hat[3];
  rty_state_hat_e_hat[1] = rtu_pos[1] - rty_state_hat_pos_hat[1];
  rty_state_hat_e_hat[4] = rtu_att[1] - rty_state_hat_pos_hat[4];
  rty_state_hat_e_hat[2] = rtu_pos[2] - rty_state_hat_pos_hat[2];
  rty_state_hat_e_hat[5] = rtu_att[2] - rty_state_hat_pos_hat[5];

  // Constant: '<Root>/Constant'
  rty_state_hat_q_tilde[0] = FxTESO_P.Constant_Value[0];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant'

  rty_state_hat_q_hat[0] = FxTESO_P.Constant_Value[0];

  // Constant: '<Root>/Constant'
  rty_state_hat_q_tilde[1] = FxTESO_P.Constant_Value[1];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant'

  rty_state_hat_q_hat[1] = FxTESO_P.Constant_Value[1];

  // Constant: '<Root>/Constant'
  rty_state_hat_q_tilde[2] = FxTESO_P.Constant_Value[2];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant'

  rty_state_hat_q_hat[2] = FxTESO_P.Constant_Value[2];

  // Constant: '<Root>/Constant'
  rty_state_hat_q_tilde[3] = FxTESO_P.Constant_Value[3];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant'

  rty_state_hat_q_hat[3] = FxTESO_P.Constant_Value[3];
  for (i = 0; i < 6; i++) {
    // Memory: '<Root>/Memory2'
    localB->Memory2_PreviousInput = localDW->Memory2_PreviousInput[i];
    rty_state_hat_pos_ddot_hat[i] = localB->Memory2_PreviousInput;

    // Sum: '<Root>/Sum11' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    localB->kt_e_tmp_tmp = 0.0;
    for (c_j = 0; c_j < 6; c_j++) {
      localB->kt_e_tmp_tmp += localB->M[6 * c_j + i] * rtu_Fu_Fu[c_j];
    }

    // Signum: '<Root>/Sign5' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    localB->rty_state_hat_e_hat = rty_state_hat_e_hat[i];

    // Sum: '<Root>/Sum9' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    localB->smax = rtu_PX4Params_FxTQESOg_alpha_q[i];

    // Sum: '<Root>/Sum10' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    localB->s = rtu_PX4Params_FxTQESOg_beta_q[i];

    // Signum: '<Root>/Sign5' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign6'
    //   Signum: '<Root>/Sign7'

    tmp = rtIsNaN(localB->rty_state_hat_e_hat);
    if (tmp) {
      localB->d = (rtNaN);
    } else if (localB->rty_state_hat_e_hat < 0.0) {
      localB->d = -1.0;
    } else {
      localB->d = (localB->rty_state_hat_e_hat > 0.0);
    }

    // Abs: '<Root>/Abs6' incorporates:
    //   Abs: '<Root>/Abs4'
    //   Abs: '<Root>/Abs5'
    //   Abs: '<Root>/Abs7'
    //   Abs: '<Root>/Abs8'
    //   Abs: '<Root>/Abs9'

    localB->kt_tmp_tmp = fabs(localB->rty_state_hat_e_hat);

    // Sum: '<Root>/Sum11' incorporates:
    //   Product: '<Root>/Matrix Multiply'
    //   Product: '<Root>/Product8'
    //   Product: '<Root>/Product9'
    //   Signum: '<Root>/Sign5'

    localB->kt_tmp_tmp_m = rtu_PX4Params_FxTQESOg_mu_2[i] * localB->d;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
    //   Abs: '<Root>/Abs6'
    //   Constant: '<Root>/Constant6'
    //   Constant: '<Root>/Constant7'
    //   Gain: '<Root>/Gain5'
    //   Gain: '<Root>/Gain6'
    //   Math: '<Root>/Power5'
    //   Math: '<Root>/Power6'
    //   Memory: '<Root>/Memory2'
    //   Product: '<Root>/Product8'
    //   Product: '<Root>/Product9'
    //   Sum: '<Root>/Sum10'
    //   Sum: '<Root>/Sum11'
    //   Sum: '<Root>/Sum9'

    localB->kt_tmp_tmp_m = (((rt_powd_snf(localB->kt_tmp_tmp, (localB->smax +
      FxTESO_P.Constant6_Value) * FxTESO_P.Gain5_Gain) * localB->kt_tmp_tmp_m +
      localB->Memory2_PreviousInput) + localB->kt_e_tmp_tmp) + rt_powd_snf
      (localB->kt_tmp_tmp, (localB->s + FxTESO_P.Constant7_Value) *
       FxTESO_P.Gain6_Gain) * localB->kt_tmp_tmp_m) *
      FxTESO_P.DiscreteTimeIntegrator1_gainval;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
    localB->kt = localDW->DiscreteTimeIntegrator1_DSTATE[i] +
      localB->kt_tmp_tmp_m;

    // Memory: '<Root>/Memory1'
    localB->Memory2_PreviousInput = localDW->Memory1_PreviousInput[i];
    rty_state_hat_pos_dot_hat[i] = localB->Memory2_PreviousInput;

    // Signum: '<Root>/Sign3' incorporates:
    //   Signum: '<Root>/Sign4'

    if (tmp) {
      localB->kt_e_tmp_tmp = (rtNaN);
    } else if (localB->rty_state_hat_e_hat < 0.0) {
      localB->kt_e_tmp_tmp = -1.0;
    } else {
      localB->kt_e_tmp_tmp = (localB->rty_state_hat_e_hat > 0.0);
    }

    // Product: '<Root>/Product6' incorporates:
    //   Product: '<Root>/Product7'
    //   Signum: '<Root>/Sign3'

    localB->kt_e_tmp_tmp *= rtu_PX4Params_FxTQESOg_mu_1[i];

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
    //   Constant: '<Root>/Constant2'
    //   Constant: '<Root>/Constant4'
    //   Gain: '<Root>/Gain3'
    //   Gain: '<Root>/Gain4'
    //   Math: '<Root>/Power3'
    //   Math: '<Root>/Power4'
    //   Product: '<Root>/Product6'
    //   Product: '<Root>/Product7'
    //   Sum: '<Root>/Sum5'
    //   Sum: '<Root>/Sum6'
    //   Sum: '<Root>/Sum7'

    localB->kt_e_tmp = ((rt_powd_snf(localB->kt_tmp_tmp, (localB->smax +
      FxTESO_P.Constant2_Value) * FxTESO_P.Gain3_Gain) * localB->kt_e_tmp_tmp +
                         localB->Memory2_PreviousInput) + rt_powd_snf
                        (localB->kt_tmp_tmp, (localB->s +
      FxTESO_P.Constant4_Value) * FxTESO_P.Gain4_Gain) * localB->kt_e_tmp_tmp) *
      FxTESO_P.DiscreteTimeIntegrator_gainval;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localB->Memory_PreviousInput = localDW->DiscreteTimeIntegrator_DSTATE[i] +
      localB->kt_e_tmp;
    localDW->Memory_PreviousInput[i] = localB->Memory_PreviousInput;

    // Signum: '<Root>/Sign7' incorporates:
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    if (tmp) {
      localB->kt_e_tmp_tmp = (rtNaN);
      localB->d = (rtNaN);
    } else if (localB->rty_state_hat_e_hat < 0.0) {
      localB->kt_e_tmp_tmp = -1.0;
      localB->d = -1.0;
    } else {
      localB->kt_e_tmp_tmp = (localB->rty_state_hat_e_hat > 0.0);
      localB->d = localB->kt_e_tmp_tmp;
    }

    // Product: '<Root>/Product11' incorporates:
    //   Product: '<Root>/Product12'
    //   Signum: '<Root>/Sign7'

    localB->rty_state_hat_e_hat = rtu_PX4Params_FxTQESOg_mu_3[i] *
      localB->kt_e_tmp_tmp;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
    //   Math: '<Root>/Power7'
    //   Math: '<Root>/Power8'
    //   Product: '<Root>/Product11'
    //   Product: '<Root>/Product12'
    //   Product: '<Root>/Product13'
    //   Signum: '<Root>/Sign9'
    //   Sum: '<Root>/Sum13'

    localB->smax = ((localB->rty_state_hat_e_hat * rt_powd_snf
                     (localB->kt_tmp_tmp, localB->smax) +
                     localB->rty_state_hat_e_hat * rt_powd_snf
                     (localB->kt_tmp_tmp, localB->s)) +
                    rtu_PX4Params_FxTQESOg_eps_4[i] * localB->d) *
      FxTESO_P.DiscreteTimeIntegrator2_gainval;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
    localB->Memory2_PreviousInput = localDW->DiscreteTimeIntegrator2_DSTATE[i] +
      localB->smax;
    localDW->Memory2_PreviousInput[i] = localB->Memory2_PreviousInput;

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
    localDW->DiscreteTimeIntegrator1_DSTATE[i] = localB->kt +
      localB->kt_tmp_tmp_m;

    // Update for Memory: '<Root>/Memory1' incorporates:
    //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'

    localDW->Memory1_PreviousInput[i] = localB->kt;

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localDW->DiscreteTimeIntegrator_DSTATE[i] = localB->Memory_PreviousInput +
      localB->kt_e_tmp;

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
    localDW->DiscreteTimeIntegrator2_DSTATE[i] = localB->Memory2_PreviousInput +
      localB->smax;
  }
}

// Model initialize function
void FxTESO_initialize(const char_T **rt_errorStatus, RT_MODEL_FxTESO_T *const
  FxTESO_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  FxTESO_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_FxTESO_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_FxTESO_T::setErrorStatusPointer(const char_T** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_FxTESO_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_FxTESO_T::setErrorStatus(const char_T* const aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
