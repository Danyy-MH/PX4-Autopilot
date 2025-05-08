//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: asgsm_obs.cpp
//
// Code generated for Simulink model 'asgsm_obs'.
//
// Model version                  : 1.20
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:41 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "asgsm_obs.h"
#include "rtwtypes.h"
#include "asgsm_obs_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_powd_snf.h"

P_asgsm_obs_T asgsm_obs_P = {
  // Expression: -1
  //  Referenced by: '<Root>/Gain5'

  -1.0,

  // Expression: 2
  //  Referenced by: '<Root>/Constant2'

  2.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant3'

  1.0,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Memory'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.002,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<Root>/Gain3'

  2.0,

  // Expression: 2
  //  Referenced by: '<Root>/Gain'

  2.0,

  // Expression: [5; 5; 40; 0.5; 0.5; 0.5]
  //  Referenced by: '<Root>/Saturation'

  { 5.0, 5.0, 40.0, 0.5, 0.5, 0.5 },

  // Expression: [-5; -5; 0; -0.5; -0.5; -0.5]
  //  Referenced by: '<Root>/Saturation'

  { -5.0, -5.0, 0.0, -0.5, -0.5, -0.5 }
};

// System initialize for referenced model: 'asgsm_obs'
void asgsm_obs_Init(DW_asgsm_obs_f_T *localDW)
{
  for (int32_T i = 0; i < 6; i++) {
    // InitializeConditions for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput[i] = asgsm_obs_P.Memory_InitialCondition[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE[i] =
      asgsm_obs_P.DiscreteTimeIntegrator_IC[i];
  }
}

// Output and update for referenced model: 'asgsm_obs'
void asgsm_obs(const real_T rtu_qd_qd[6], const real_T rtu_qd_qd_dot[6], const
               real_T rtu_q_pos_hat[6], const real_T rtu_q_pos_dot_hat[6], const
               real_T rtu_q_pos_ddot_hat[6], const real_T
               rtu_PX4Params_ASGSMg_zeta1[6], const real_T
               rtu_PX4Params_ASGSMg_zeta2[6], const real_T
               rtu_PX4Params_ASGSMg_lambda1[6], const real_T
               rtu_PX4Params_ASGSMg_lambda2[6], const real_T
               rtu_PX4Params_ASGSMg_alpha_u[6], const real_T
               rtu_PX4Params_ASGSMg_beta_u[6], const real_T
               rtu_PX4Params_ASGSMg_epsilon_u[6], const real_T
               rtu_PX4Params_MCg_MCData[5], real_T rty_u_Fu[6], real_T rty_u_e[6],
               real_T rty_u_sigma[6], real_T rty_u_kt[6], B_asgsm_obs_c_T
               *localB, DW_asgsm_obs_f_T *localDW)
{
  real_T rty_u_kt_0;
  real_T rty_u_sigma_tmp;
  real_T tmp;
  real_T tmp_0;
  real_T u1;
  int32_T i;
  int32_T i_0;

  // MATLAB Function: '<Root>/constantFunctions'
  localB->rtu_PX4Params_MCg_MCData[0] = rtu_PX4Params_MCg_MCData[0];
  localB->rtu_PX4Params_MCg_MCData[6] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[12] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[18] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[24] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[30] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[1] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[7] = rtu_PX4Params_MCg_MCData[0];
  localB->rtu_PX4Params_MCg_MCData[13] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[19] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[25] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[31] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[2] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[8] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[14] = rtu_PX4Params_MCg_MCData[0];
  localB->rtu_PX4Params_MCg_MCData[20] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[26] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[32] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[3] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[9] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[15] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[21] = rtu_PX4Params_MCg_MCData[1];
  localB->rtu_PX4Params_MCg_MCData[27] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[33] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[4] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[10] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[16] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[22] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[28] = rtu_PX4Params_MCg_MCData[2];
  localB->rtu_PX4Params_MCg_MCData[34] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[5] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[11] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[17] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[23] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[29] = 0.0;
  localB->rtu_PX4Params_MCg_MCData[35] = rtu_PX4Params_MCg_MCData[3];
  for (i = 0; i < 6; i++) {
    // Sum: '<Root>/Sum19'
    localB->rtb_e_dot_m = rtu_qd_qd_dot[i] - rtu_q_pos_dot_hat[i];

    // Sum: '<Root>/Sum17'
    localB->rty_u_e = rtu_qd_qd[i] - rtu_q_pos_hat[i];
    rty_u_e[i] = localB->rty_u_e;

    // Abs: '<Root>/Abs1' incorporates:
    //   Abs: '<Root>/Abs6'
    //   Sum: '<Root>/Sum19'

    u1 = fabs(localB->rtb_e_dot_m);

    // Signum: '<Root>/Sign2' incorporates:
    //   Sum: '<Root>/Sum19'

    if (!rtIsNaN(localB->rtb_e_dot_m)) {
      if (localB->rtb_e_dot_m < 0.0) {
        // Signum: '<Root>/Sign6'
        localB->rtb_e_dot_m = -1.0;
      } else {
        // Signum: '<Root>/Sign6'
        localB->rtb_e_dot_m = (localB->rtb_e_dot_m > 0.0);
      }
    }

    // Product: '<Root>/Product11'
    localB->rtu_PX4Params_ASGSMg_zeta1 = rtu_PX4Params_ASGSMg_zeta1[i];

    // Math: '<Root>/Power' incorporates:
    //   Product: '<Root>/Product11'

    localB->rtu_PX4Params_ASGSMg_lambda1 = rtu_PX4Params_ASGSMg_lambda1[i];

    // Product: '<Root>/Product12' incorporates:
    //   Product: '<Root>/Product11'

    localB->rtu_PX4Params_ASGSMg_zeta2 = rtu_PX4Params_ASGSMg_zeta2[i];

    // Math: '<Root>/Power1' incorporates:
    //   Product: '<Root>/Product11'

    localB->rtu_PX4Params_ASGSMg_lambda2 = rtu_PX4Params_ASGSMg_lambda2[i];

    // Signum: '<Root>/Sign1'
    if (rtIsNaN(localB->rty_u_e)) {
      tmp_0 = (rtNaN);
    } else if (localB->rty_u_e < 0.0) {
      tmp_0 = -1.0;
    } else {
      tmp_0 = (localB->rty_u_e > 0.0);
    }

    // Abs: '<Root>/Abs' incorporates:
    //   Abs: '<Root>/Abs7'

    rty_u_sigma_tmp = fabs(localB->rty_u_e);

    // Sum: '<Root>/Sum18' incorporates:
    //   Abs: '<Root>/Abs'
    //   Abs: '<Root>/Abs1'
    //   Math: '<Root>/Power'
    //   Math: '<Root>/Power1'
    //   Product: '<Root>/Product11'
    //   Product: '<Root>/Product12'
    //   Signum: '<Root>/Sign1'
    //   Signum: '<Root>/Sign2'

    localB->rty_u_e = (localB->rtu_PX4Params_ASGSMg_zeta1 * rt_powd_snf
                       (rty_u_sigma_tmp, localB->rtu_PX4Params_ASGSMg_lambda1) *
                       tmp_0 + localB->rty_u_e) +
      localB->rtu_PX4Params_ASGSMg_zeta2 * rt_powd_snf(u1,
      localB->rtu_PX4Params_ASGSMg_lambda2) * localB->rtb_e_dot_m;
    rty_u_sigma[i] = localB->rty_u_e;

    // Sqrt: '<Root>/Sqrt2' incorporates:
    //   Abs: '<Root>/Abs2'
    //   Sqrt: '<Root>/Sqrt4'

    tmp_0 = sqrt(fabs(localB->rty_u_e));

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
    //   Memory: '<Root>/Memory'
    //   Product: '<Root>/Product16'
    //   Sqrt: '<Root>/Sqrt1'
    //   Sqrt: '<Root>/Sqrt2'
    //   Sum: '<Root>/Sum20'

    tmp = (sqrt(rtu_PX4Params_ASGSMg_alpha_u[i]) * tmp_0 -
           localDW->Memory_PreviousInput[i]) *
      asgsm_obs_P.DiscreteTimeIntegrator_gainval;
    localB->dv[i] = tmp;
    rty_u_kt_0 = localDW->DiscreteTimeIntegrator_DSTATE[i] + tmp;
    rty_u_kt[i] = rty_u_kt_0;

    // Signum: '<Root>/Sign4'
    if (rtIsNaN(localB->rty_u_e)) {
      tmp = (rtNaN);
    } else if (localB->rty_u_e < 0.0) {
      tmp = -1.0;
    } else {
      tmp = (localB->rty_u_e > 0.0);
    }

    // Sum: '<Root>/Sum23' incorporates:
    //   Abs: '<Root>/Abs6'
    //   Constant: '<Root>/Constant2'
    //   Constant: '<Root>/Constant3'
    //   Gain: '<Root>/Gain'
    //   Gain: '<Root>/Gain3'
    //   Gain: '<Root>/Gain5'
    //   Math: '<Root>/Power4'
    //   Math: '<Root>/Power5'
    //   Product: '<Root>/Divide3'
    //   Product: '<Root>/Product'
    //   Product: '<Root>/Product1'
    //   Product: '<Root>/Product2'
    //   Product: '<Root>/Product31'
    //   Product: '<Root>/Product32'
    //   Product: '<Root>/Product33'
    //   Product: '<Root>/Product34'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign6'
    //   Sum: '<Root>/Sum'
    //   Sum: '<Root>/Sum1'
    //   Sum: '<Root>/Sum26'
    //   Sum: '<Root>/Sum28'

    localB->dv1[i] = (rt_powd_snf(u1, asgsm_obs_P.Constant2_Value -
      localB->rtu_PX4Params_ASGSMg_lambda2) * localB->rtb_e_dot_m /
                      (localB->rtu_PX4Params_ASGSMg_lambda2 *
                       localB->rtu_PX4Params_ASGSMg_zeta2) *
                      (localB->rtu_PX4Params_ASGSMg_lambda1 *
                       localB->rtu_PX4Params_ASGSMg_zeta1 * rt_powd_snf
                       (rty_u_sigma_tmp, localB->rtu_PX4Params_ASGSMg_lambda1 -
                        asgsm_obs_P.Constant3_Value) +
                       asgsm_obs_P.Constant3_Value) + asgsm_obs_P.Gain5_Gain *
                      rtu_q_pos_ddot_hat[i]) - ((0.0 - asgsm_obs_P.Gain3_Gain *
      rty_u_kt_0 * tmp_0 * tmp) - asgsm_obs_P.Gain_Gain * localB->rty_u_e *
      rty_u_kt_0 * rtu_PX4Params_ASGSMg_epsilon_u[i]);
  }

  for (i = 0; i < 6; i++) {
    // Product: '<Root>/Product29'
    localB->rtb_e_dot_m = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      localB->rtb_e_dot_m += localB->rtu_PX4Params_MCg_MCData[6 * i_0 + i] *
        localB->dv1[i_0];
    }

    // Saturate: '<Root>/Saturation' incorporates:
    //   Product: '<Root>/Product29'

    u1 = asgsm_obs_P.Saturation_LowerSat[i];
    localB->rtu_PX4Params_ASGSMg_zeta1 = asgsm_obs_P.Saturation_UpperSat[i];
    if (localB->rtb_e_dot_m > localB->rtu_PX4Params_ASGSMg_zeta1) {
      rty_u_Fu[i] = localB->rtu_PX4Params_ASGSMg_zeta1;
    } else if (localB->rtb_e_dot_m < u1) {
      rty_u_Fu[i] = u1;
    } else {
      rty_u_Fu[i] = localB->rtb_e_dot_m;
    }

    // End of Saturate: '<Root>/Saturation'

    // Product: '<Root>/Product3'
    rty_u_kt_0 = rty_u_kt[i];

    // Update for Memory: '<Root>/Memory' incorporates:
    //   Product: '<Root>/Product17'
    //   Product: '<Root>/Product3'
    //   Sqrt: '<Root>/Sqrt'

    localDW->Memory_PreviousInput[i] = rty_u_kt_0 * rty_u_kt_0 * sqrt
      (rtu_PX4Params_ASGSMg_beta_u[i]);

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localDW->DiscreteTimeIntegrator_DSTATE[i] = rty_u_kt_0 + localB->dv[i];
  }
}

// Model initialize function
void asgsm_obs_initialize(const char_T **rt_errorStatus, RT_MODEL_asgsm_obs_T *
  const asgsm_obs_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  asgsm_obs_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_asgsm_obs_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_asgsm_obs_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_asgsm_obs_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_asgsm_obs_T::setErrorStatus(const char_T* const aErrorStatus)
  const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
