//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: asgsm_quat_obs.cpp
//
// Code generated for Simulink model 'asgsm_quat_obs'.
//
// Model version                  : 1.24
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue Apr 29 18:08:31 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "asgsm_quat_obs.h"
#include "rtwtypes.h"
#include "asgsm_quat_obs_private.h"
#include <string.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_powd_snf.h"
#include "norm_07B1VLxa.h"

P_asgsm_quat_obs_T asgsm_quat_obs_P = {
  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Memory'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<Root>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<Root>/Gain4'

  2.0,

  // Expression: 1/2
  //  Referenced by: '<Root>/Gain2'

  0.5,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.002,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1; 1; 1]
  //  Referenced by: '<Root>/Constant5'

  { 1.0, 1.0, 1.0 },

  // Expression: [1; 1; 1]
  //  Referenced by: '<Root>/Constant3'

  { 1.0, 1.0, 1.0 },

  // Expression: [2;2;2]
  //  Referenced by: '<Root>/Constant4'

  { 2.0, 2.0, 2.0 },

  // Expression: [5; 5; 40]
  //  Referenced by: '<Root>/Saturation'

  { 5.0, 5.0, 40.0 },

  // Expression: [-5; -5; 0]
  //  Referenced by: '<Root>/Saturation'

  { -5.0, -5.0, 0.0 },

  // Expression: [5; 5; 40]
  //  Referenced by: '<Root>/Saturation1'

  { 5.0, 5.0, 40.0 },

  // Expression: [-5; -5; 0]
  //  Referenced by: '<Root>/Saturation1'

  { -5.0, -5.0, 0.0 },

  // Expression: [1; 1; 1]
  //  Referenced by: '<Root>/Constant9'

  { 1.0, 1.0, 1.0 },

  // Expression: [1; 1; 1]
  //  Referenced by: '<Root>/Constant7'

  { 1.0, 1.0, 1.0 },

  // Expression: [2;2;2]
  //  Referenced by: '<Root>/Constant8'

  { 2.0, 2.0, 2.0 },

  // Expression: 0.5
  //  Referenced by: '<Root>/tau'

  0.5,

  // Expression: -0.5
  //  Referenced by: '<Root>/tau'

  -0.5
};

// System initialize for referenced model: 'asgsm_quat_obs'
void asgsm_quat_obs_Init(DW_asgsm_quat_obs_f_T *localDW)
{
  for (int32_T i = 0; i < 6; i++) {
    // InitializeConditions for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput[i] =
      asgsm_quat_obs_P.Memory_InitialCondition[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE[i] =
      asgsm_quat_obs_P.DiscreteTimeIntegrator_IC[i];
  }
}

// Output and update for referenced model: 'asgsm_quat_obs'
void asgsm_quat_obs(const real_T rtu_qd_qd[6], const real_T rtu_qd_qd_dot[6],
                    const real_T rtu_qd_quaternion_d[4], const real_T
                    rtu_q_pos_hat[6], const real_T rtu_q_pos_dot_hat[6], const
                    real_T rtu_q_pos_ddot_hat[6], const real_T rtu_q_q_hat[4],
                    const real_T rtu_PX4Params_ASGSMg_zeta1[6], const real_T
                    rtu_PX4Params_ASGSMg_zeta2[6], const real_T
                    rtu_PX4Params_ASGSMg_lambda1[6], const real_T
                    rtu_PX4Params_ASGSMg_lambda2[6], const real_T
                    rtu_PX4Params_ASGSMg_alpha_u[6], const real_T
                    rtu_PX4Params_ASGSMg_beta_u[6], const real_T
                    rtu_PX4Params_MCg_MCData[5], real_T rty_u_Fu[6], real_T
                    rty_u_e[6], real_T rty_u_e_dot[6], real_T rty_u_sigma[6],
                    real_T rty_u_kt[6], real_T rty_u_qe[4], B_asgsm_quat_obs_c_T
                    *localB, DW_asgsm_quat_obs_f_T *localDW)
{
  real_T rtb_Sum4_tmp;
  real_T rtu_qd_quaternion_d_0;
  real_T rtu_qd_quaternion_d_1;
  real_T rtu_qd_quaternion_d_2;
  int32_T i;

  // MATLAB Function: '<Root>/MATLAB Function'
  memset(&localB->J[0], 0, 9U * sizeof(real_T));
  localB->J[0] = rtu_PX4Params_MCg_MCData[1];
  localB->J[4] = rtu_PX4Params_MCg_MCData[2];
  localB->J[8] = rtu_PX4Params_MCg_MCData[3];

  // Memory: '<Root>/Memory'
  for (i = 0; i < 6; i++) {
    rty_u_kt[i] = localDW->Memory_PreviousInput[i];
  }

  // End of Memory: '<Root>/Memory'

  // Sum: '<Root>/Sum14' incorporates:
  //   Math: '<Root>/Power5'

  localB->rtb_Power5_g = rtu_qd_qd[0] - rtu_q_pos_hat[0];

  // SignalConversion generated from: '<Root>/u_Outport_1' incorporates:
  //   Math: '<Root>/Power5'
  //   Sum: '<Root>/Sum14'

  rty_u_e[0] = localB->rtb_Power5_g;

  // Sum: '<Root>/Sum15' incorporates:
  //   Sum: '<Root>/Sum23'

  localB->rtb_Sum23_g = rtu_qd_qd_dot[0] - rtu_q_pos_dot_hat[0];

  // SignalConversion generated from: '<Root>/u_Outport_1' incorporates:
  //   Sum: '<Root>/Sum15'
  //   Sum: '<Root>/Sum23'

  rty_u_e_dot[0] = localB->rtb_Sum23_g;

  // Abs: '<Root>/Abs' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power5'

  localB->rtb_Product24_tmp = fabs(localB->rtb_Power5_g);
  localB->rtb_Product24_tmp_idx_0 = localB->rtb_Product24_tmp;

  // Signum: '<Root>/Sign1'
  if (rtIsNaN(localB->rtb_Sum23_g)) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = (rtNaN);
  } else if (localB->rtb_Sum23_g < 0.0) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = -1.0;
  } else {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = (localB->rtb_Sum23_g > 0.0);
  }

  localB->rtb_Product24_tmp_idx_0_d = localB->rtb_Product24_tmp_m;

  // Abs: '<Root>/Abs1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Sum: '<Root>/Sum23'

  localB->rtb_Product24_tmp_n = fabs(localB->rtb_Sum23_g);
  localB->rtb_Product24_tmp_idx_0_g = localB->rtb_Product24_tmp_n;

  // Signum: '<Root>/Sign'
  if (rtIsNaN(localB->rtb_Power5_g)) {
    localB->u = (rtNaN);
  } else if (localB->rtb_Power5_g < 0.0) {
    localB->u = -1.0;
  } else {
    localB->u = (localB->rtb_Power5_g > 0.0);
  }

  // Sum: '<Root>/Sum9' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product24'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'
  //   Signum: '<Root>/Sign1'

  localB->rtb_Product24_idx_0 = (rtu_PX4Params_ASGSMg_zeta1[0] * rt_powd_snf
    (localB->rtb_Product24_tmp, rtu_PX4Params_ASGSMg_lambda1[0]) * localB->u +
    localB->rtb_Power5_g) + rtu_PX4Params_ASGSMg_zeta2[0] * rt_powd_snf
    (localB->rtb_Product24_tmp_n, rtu_PX4Params_ASGSMg_lambda2[0]) *
    localB->rtb_Product24_tmp_m;

  // Sum: '<Root>/Sum14' incorporates:
  //   Math: '<Root>/Power5'

  localB->rtb_Power5_g = rtu_qd_qd[1] - rtu_q_pos_hat[1];
  localB->rtb_Power5_idx_1 = localB->rtb_Power5_g;

  // Sum: '<Root>/Sum15' incorporates:
  //   Sum: '<Root>/Sum23'

  localB->rtb_Sum23_g = rtu_qd_qd_dot[1] - rtu_q_pos_dot_hat[1];
  localB->rtb_Sum23_idx_1 = localB->rtb_Sum23_g;

  // Abs: '<Root>/Abs' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power5'

  localB->rtb_Product24_tmp = fabs(localB->rtb_Power5_g);
  localB->rtb_Product24_tmp_idx_1 = localB->rtb_Product24_tmp;

  // Signum: '<Root>/Sign1'
  if (rtIsNaN(localB->rtb_Sum23_g)) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = (rtNaN);
  } else if (localB->rtb_Sum23_g < 0.0) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = -1.0;
  } else {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = (localB->rtb_Sum23_g > 0.0);
  }

  localB->rtb_Product24_tmp_idx_1_l = localB->rtb_Product24_tmp_m;

  // Abs: '<Root>/Abs1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Sum: '<Root>/Sum23'

  localB->rtb_Product24_tmp_n = fabs(localB->rtb_Sum23_g);
  localB->rtb_Product24_tmp_idx_1_d = localB->rtb_Product24_tmp_n;

  // Signum: '<Root>/Sign'
  if (rtIsNaN(localB->rtb_Power5_g)) {
    localB->u = (rtNaN);
  } else if (localB->rtb_Power5_g < 0.0) {
    localB->u = -1.0;
  } else {
    localB->u = (localB->rtb_Power5_g > 0.0);
  }

  // Sum: '<Root>/Sum9' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product24'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'
  //   Signum: '<Root>/Sign1'

  localB->rtb_Product24_idx_1 = (rtu_PX4Params_ASGSMg_zeta1[1] * rt_powd_snf
    (localB->rtb_Product24_tmp, rtu_PX4Params_ASGSMg_lambda1[1]) * localB->u +
    localB->rtb_Power5_g) + rtu_PX4Params_ASGSMg_zeta2[1] * rt_powd_snf
    (localB->rtb_Product24_tmp_n, rtu_PX4Params_ASGSMg_lambda2[1]) *
    localB->rtb_Product24_tmp_m;

  // Sum: '<Root>/Sum14' incorporates:
  //   Math: '<Root>/Power5'

  localB->rtb_Power5_g = rtu_qd_qd[2] - rtu_q_pos_hat[2];

  // Sum: '<Root>/Sum15' incorporates:
  //   Sum: '<Root>/Sum23'

  localB->rtb_Sum23_g = rtu_qd_qd_dot[2] - rtu_q_pos_dot_hat[2];

  // Abs: '<Root>/Abs' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power5'

  localB->rtb_Product24_tmp = fabs(localB->rtb_Power5_g);

  // Signum: '<Root>/Sign1'
  if (rtIsNaN(localB->rtb_Sum23_g)) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = (rtNaN);
  } else if (localB->rtb_Sum23_g < 0.0) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = -1.0;
  } else {
    // Signum: '<Root>/Sign2'
    localB->rtb_Product24_tmp_m = (localB->rtb_Sum23_g > 0.0);
  }

  // Abs: '<Root>/Abs1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Sum: '<Root>/Sum23'

  localB->rtb_Product24_tmp_n = fabs(localB->rtb_Sum23_g);

  // Signum: '<Root>/Sign'
  if (rtIsNaN(localB->rtb_Power5_g)) {
    localB->u = (rtNaN);
  } else if (localB->rtb_Power5_g < 0.0) {
    localB->u = -1.0;
  } else {
    localB->u = (localB->rtb_Power5_g > 0.0);
  }

  // Sum: '<Root>/Sum9' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product24'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'
  //   Signum: '<Root>/Sign1'

  localB->rtb_Product24_idx_2 = (rtu_PX4Params_ASGSMg_zeta1[2] * rt_powd_snf
    (localB->rtb_Product24_tmp, rtu_PX4Params_ASGSMg_lambda1[2]) * localB->u +
    localB->rtb_Power5_g) + rtu_PX4Params_ASGSMg_zeta2[2] * rt_powd_snf
    (localB->rtb_Product24_tmp_n, rtu_PX4Params_ASGSMg_lambda2[2]) *
    localB->rtb_Product24_tmp_m;

  // MATLAB Function: '<S1>/Kronecker_product' incorporates:
  //   SignalConversion generated from: '<S9>/ SFunction '
  //   UnaryMinus: '<S5>/Unary Minus'
  //   UnaryMinus: '<S5>/Unary Minus1'
  //   UnaryMinus: '<S5>/Unary Minus2'

  localB->rtb_TmpSignalConversionAtSFun_m[0] = rtu_q_q_hat[0];
  localB->rtb_TmpSignalConversionAtSFun_m[4] = rtu_q_q_hat[1];
  localB->rtb_TmpSignalConversionAtSFun_m[8] = rtu_q_q_hat[2];
  localB->rtb_TmpSignalConversionAtSFun_m[12] = rtu_q_q_hat[3];
  localB->rtb_TmpSignalConversionAtSFun_m[1] = -rtu_q_q_hat[1];
  localB->rtb_TmpSignalConversionAtSFun_m[5] = rtu_q_q_hat[0];
  localB->rtb_TmpSignalConversionAtSFun_m[9] = rtu_q_q_hat[3];
  localB->rtb_TmpSignalConversionAtSFun_m[13] = -rtu_q_q_hat[2];
  localB->rtb_TmpSignalConversionAtSFun_m[2] = -rtu_q_q_hat[2];
  localB->rtb_TmpSignalConversionAtSFun_m[6] = -rtu_q_q_hat[3];
  localB->rtb_TmpSignalConversionAtSFun_m[10] = rtu_q_q_hat[0];
  localB->rtb_TmpSignalConversionAtSFun_m[14] = rtu_q_q_hat[1];
  localB->rtb_TmpSignalConversionAtSFun_m[3] = -rtu_q_q_hat[3];
  localB->rtb_TmpSignalConversionAtSFun_m[7] = rtu_q_q_hat[2];
  localB->rtb_TmpSignalConversionAtSFun_m[11] = -rtu_q_q_hat[1];
  localB->rtb_TmpSignalConversionAtSFun_m[15] = rtu_q_q_hat[0];
  localB->sqrt_b = rtu_qd_quaternion_d[1];
  rtu_qd_quaternion_d_0 = rtu_qd_quaternion_d[0];
  rtu_qd_quaternion_d_1 = rtu_qd_quaternion_d[2];
  rtu_qd_quaternion_d_2 = rtu_qd_quaternion_d[3];
  for (i = 0; i < 4; i++) {
    localB->r_g[i] = ((localB->rtb_TmpSignalConversionAtSFun_m[i + 4] *
                       localB->sqrt_b + localB->
                       rtb_TmpSignalConversionAtSFun_m[i] *
                       rtu_qd_quaternion_d_0) +
                      localB->rtb_TmpSignalConversionAtSFun_m[i + 8] *
                      rtu_qd_quaternion_d_1) +
      localB->rtb_TmpSignalConversionAtSFun_m[i + 12] * rtu_qd_quaternion_d_2;
  }

  // Sqrt: '<S12>/sqrt' incorporates:
  //   Product: '<S13>/Product'
  //   Product: '<S13>/Product1'
  //   Product: '<S13>/Product2'
  //   Product: '<S13>/Product3'
  //   Sum: '<S13>/Sum'

  localB->sqrt_b = sqrt(((localB->r_g[0] * localB->r_g[0] + localB->r_g[1] *
    localB->r_g[1]) + localB->r_g[2] * localB->r_g[2]) + localB->r_g[3] *
                        localB->r_g[3]);

  // SignalConversion generated from: '<S14>/ SFunction ' incorporates:
  //   MATLAB Function: '<S8>/MATLAB Function'
  //   Product: '<S7>/Product'
  //   Product: '<S7>/Product1'
  //   Product: '<S7>/Product2'
  //   Product: '<S7>/Product3'
  //   SignalConversion generated from: '<Root>/u_Outport_1'

  rty_u_qe[0] = localB->r_g[0] / localB->sqrt_b;
  rty_u_qe[1] = localB->r_g[1] / localB->sqrt_b;
  rty_u_qe[2] = localB->r_g[2] / localB->sqrt_b;
  rty_u_qe[3] = localB->r_g[3] / localB->sqrt_b;

  // MATLAB Function: '<S8>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S14>/ SFunction '

  localB->lnq[0] = rty_u_qe[1];
  localB->lnq[1] = rty_u_qe[2];
  localB->lnq[2] = rty_u_qe[3];
  localB->sqrt_b = norm_07B1VLxa(localB->lnq);
  if (localB->sqrt_b == 0.0) {
    localB->lnq[0] = 0.0;
    localB->lnq[1] = 0.0;
    localB->lnq[2] = 0.0;
  } else {
    rtu_qd_quaternion_d_0 = acos(rty_u_qe[0]);
    localB->lnq[0] = rty_u_qe[1] / localB->sqrt_b * rtu_qd_quaternion_d_0;
    localB->lnq[1] = rty_u_qe[2] / localB->sqrt_b * rtu_qd_quaternion_d_0;
    localB->lnq[2] = rty_u_qe[3] / localB->sqrt_b * rtu_qd_quaternion_d_0;
  }

  // Gain: '<Root>/Gain4' incorporates:
  //   Sum: '<Root>/Sum20'

  localB->rtb_lnq_p = asgsm_quat_obs_P.Gain4_Gain * localB->lnq[0];
  localB->lnq[0] = localB->rtb_lnq_p;

  // Sum: '<Root>/Sum16' incorporates:
  //   Saturate: '<Root>/tau'

  localB->rtb_tau_c = rtu_qd_qd_dot[3] - rtu_q_pos_dot_hat[3];

  // SignalConversion generated from: '<Root>/u_Outport_1' incorporates:
  //   Saturate: '<Root>/tau'
  //   Sum: '<Root>/Sum16'

  rty_u_e_dot[3] = localB->rtb_tau_c;

  // Abs: '<Root>/Abs8' incorporates:
  //   Abs: '<Root>/Abs7'
  //   Sum: '<Root>/Sum20'

  localB->sqrt_b = fabs(localB->rtb_lnq_p);
  localB->rtb_Saturation1_tmp_idx_0 = localB->sqrt_b;

  // Signum: '<Root>/Sign6'
  if (rtIsNaN(localB->rtb_tau_c)) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = (rtNaN);
  } else if (localB->rtb_tau_c < 0.0) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = -1.0;
  } else {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = (localB->rtb_tau_c > 0.0);
  }

  localB->rtb_Saturation1_tmp_idx_0_p = rtu_qd_quaternion_d_0;

  // Abs: '<Root>/Abs9' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Saturate: '<Root>/tau'

  rtu_qd_quaternion_d_1 = fabs(localB->rtb_tau_c);
  localB->rtb_Saturation1_tmp_idx_0_l = rtu_qd_quaternion_d_1;

  // Signum: '<Root>/Sign5'
  if (rtIsNaN(localB->rtb_lnq_p)) {
    localB->u = (rtNaN);
  } else if (localB->rtb_lnq_p < 0.0) {
    localB->u = -1.0;
  } else {
    localB->u = (localB->rtb_lnq_p > 0.0);
  }

  // Sum: '<Root>/Sum24' incorporates:
  //   Abs: '<Root>/Abs8'
  //   Abs: '<Root>/Abs9'
  //   Math: '<Root>/Power8'
  //   Math: '<Root>/Power9'
  //   Product: '<Root>/Product26'
  //   Product: '<Root>/Product27'
  //   Saturate: '<Root>/Saturation1'
  //   Signum: '<Root>/Sign5'
  //   Signum: '<Root>/Sign6'
  //   Sum: '<Root>/Sum20'

  localB->rtb_Saturation1_f = (rtu_PX4Params_ASGSMg_zeta1[3] * rt_powd_snf
    (localB->sqrt_b, rtu_PX4Params_ASGSMg_lambda1[3]) * localB->u +
    localB->rtb_lnq_p) + rtu_PX4Params_ASGSMg_zeta2[3] * rt_powd_snf
    (rtu_qd_quaternion_d_1, rtu_PX4Params_ASGSMg_lambda2[3]) *
    rtu_qd_quaternion_d_0;
  localB->rtb_Saturation1_idx_0 = localB->rtb_Saturation1_f;

  // Abs: '<Root>/Abs3'
  localB->rtb_Product24_c[0] = localB->rtb_Product24_idx_0;
  localB->rtb_Product24_c[3] = localB->rtb_Saturation1_f;

  // Gain: '<Root>/Gain4' incorporates:
  //   Sum: '<Root>/Sum20'

  localB->rtb_lnq_p = asgsm_quat_obs_P.Gain4_Gain * localB->lnq[1];
  localB->lnq[1] = localB->rtb_lnq_p;

  // Sum: '<Root>/Sum16' incorporates:
  //   Saturate: '<Root>/tau'

  localB->rtb_tau_c = rtu_qd_qd_dot[4] - rtu_q_pos_dot_hat[4];
  localB->rtb_tau_idx_1 = localB->rtb_tau_c;

  // Abs: '<Root>/Abs8' incorporates:
  //   Abs: '<Root>/Abs7'
  //   Sum: '<Root>/Sum20'

  localB->sqrt_b = fabs(localB->rtb_lnq_p);
  rtu_qd_quaternion_d_2 = localB->sqrt_b;

  // Signum: '<Root>/Sign6'
  if (rtIsNaN(localB->rtb_tau_c)) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = (rtNaN);
  } else if (localB->rtb_tau_c < 0.0) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = -1.0;
  } else {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = (localB->rtb_tau_c > 0.0);
  }

  localB->rtb_Saturation1_tmp_idx_1 = rtu_qd_quaternion_d_0;

  // Abs: '<Root>/Abs9' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Saturate: '<Root>/tau'

  rtu_qd_quaternion_d_1 = fabs(localB->rtb_tau_c);
  localB->rtb_Saturation1_tmp_idx_1_j = rtu_qd_quaternion_d_1;

  // Signum: '<Root>/Sign5'
  if (rtIsNaN(localB->rtb_lnq_p)) {
    localB->u = (rtNaN);
  } else if (localB->rtb_lnq_p < 0.0) {
    localB->u = -1.0;
  } else {
    localB->u = (localB->rtb_lnq_p > 0.0);
  }

  // Sum: '<Root>/Sum24' incorporates:
  //   Abs: '<Root>/Abs8'
  //   Abs: '<Root>/Abs9'
  //   Math: '<Root>/Power8'
  //   Math: '<Root>/Power9'
  //   Product: '<Root>/Product26'
  //   Product: '<Root>/Product27'
  //   Saturate: '<Root>/Saturation1'
  //   Signum: '<Root>/Sign5'
  //   Signum: '<Root>/Sign6'
  //   Sum: '<Root>/Sum20'

  localB->rtb_Saturation1_f = (rtu_PX4Params_ASGSMg_zeta1[4] * rt_powd_snf
    (localB->sqrt_b, rtu_PX4Params_ASGSMg_lambda1[4]) * localB->u +
    localB->rtb_lnq_p) + rtu_PX4Params_ASGSMg_zeta2[4] * rt_powd_snf
    (rtu_qd_quaternion_d_1, rtu_PX4Params_ASGSMg_lambda2[4]) *
    rtu_qd_quaternion_d_0;
  localB->rtb_Saturation1_idx_1 = localB->rtb_Saturation1_f;

  // Abs: '<Root>/Abs3'
  localB->rtb_Product24_c[1] = localB->rtb_Product24_idx_1;
  localB->rtb_Product24_c[4] = localB->rtb_Saturation1_f;

  // Gain: '<Root>/Gain4' incorporates:
  //   Sum: '<Root>/Sum20'

  localB->rtb_lnq_p = asgsm_quat_obs_P.Gain4_Gain * localB->lnq[2];

  // Sum: '<Root>/Sum16' incorporates:
  //   Saturate: '<Root>/tau'

  localB->rtb_tau_c = rtu_qd_qd_dot[5] - rtu_q_pos_dot_hat[5];

  // Abs: '<Root>/Abs8' incorporates:
  //   Abs: '<Root>/Abs7'
  //   Sum: '<Root>/Sum20'

  localB->sqrt_b = fabs(localB->rtb_lnq_p);

  // Signum: '<Root>/Sign6'
  if (rtIsNaN(localB->rtb_tau_c)) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = (rtNaN);
  } else if (localB->rtb_tau_c < 0.0) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = -1.0;
  } else {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_0 = (localB->rtb_tau_c > 0.0);
  }

  // Abs: '<Root>/Abs9' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Saturate: '<Root>/tau'

  rtu_qd_quaternion_d_1 = fabs(localB->rtb_tau_c);

  // Signum: '<Root>/Sign5'
  if (rtIsNaN(localB->rtb_lnq_p)) {
    localB->u = (rtNaN);
  } else if (localB->rtb_lnq_p < 0.0) {
    localB->u = -1.0;
  } else {
    localB->u = (localB->rtb_lnq_p > 0.0);
  }

  // Sum: '<Root>/Sum24' incorporates:
  //   Abs: '<Root>/Abs8'
  //   Abs: '<Root>/Abs9'
  //   Math: '<Root>/Power8'
  //   Math: '<Root>/Power9'
  //   Product: '<Root>/Product26'
  //   Product: '<Root>/Product27'
  //   Saturate: '<Root>/Saturation1'
  //   Signum: '<Root>/Sign5'
  //   Signum: '<Root>/Sign6'
  //   Sum: '<Root>/Sum20'

  localB->rtb_Saturation1_f = (rtu_PX4Params_ASGSMg_zeta1[5] * rt_powd_snf
    (localB->sqrt_b, rtu_PX4Params_ASGSMg_lambda1[5]) * localB->u +
    localB->rtb_lnq_p) + rtu_PX4Params_ASGSMg_zeta2[5] * rt_powd_snf
    (rtu_qd_quaternion_d_1, rtu_PX4Params_ASGSMg_lambda2[5]) *
    rtu_qd_quaternion_d_0;

  // Abs: '<Root>/Abs3'
  localB->rtb_Product24_c[2] = localB->rtb_Product24_idx_2;
  localB->rtb_Product24_c[5] = localB->rtb_Saturation1_f;

  // Signum: '<Root>/Sign3'
  localB->rtb_Product24_k[0] = localB->rtb_Product24_idx_0;
  localB->rtb_Product24_k[3] = localB->rtb_Saturation1_idx_0;

  // Product: '<Root>/Product10' incorporates:
  //   Signum: '<Root>/Sign3'

  localB->rtb_Product24_cx[0] = localB->rtb_Product24_idx_0;
  localB->rtb_Product24_cx[3] = localB->rtb_Saturation1_idx_0;

  // Signum: '<Root>/Sign3'
  localB->rtb_Product24_k[1] = localB->rtb_Product24_idx_1;
  localB->rtb_Product24_k[4] = localB->rtb_Saturation1_idx_1;

  // Product: '<Root>/Product10' incorporates:
  //   Signum: '<Root>/Sign3'

  localB->rtb_Product24_cx[1] = localB->rtb_Product24_idx_1;
  localB->rtb_Product24_cx[4] = localB->rtb_Saturation1_idx_1;

  // Signum: '<Root>/Sign3' incorporates:
  //   Saturate: '<Root>/Saturation1'
  //   Sum: '<Root>/Sum24'

  localB->rtb_Product24_k[2] = localB->rtb_Product24_idx_2;
  localB->rtb_Product24_k[5] = localB->rtb_Saturation1_f;

  // Product: '<Root>/Product10' incorporates:
  //   Saturate: '<Root>/Saturation1'
  //   Signum: '<Root>/Sign3'
  //   Sum: '<Root>/Sum24'

  localB->rtb_Product24_cx[2] = localB->rtb_Product24_idx_2;
  localB->rtb_Product24_cx[5] = localB->rtb_Saturation1_f;
  for (i = 0; i < 6; i++) {
    // Sqrt: '<Root>/Sqrt3' incorporates:
    //   Abs: '<Root>/Abs3'
    //   Sqrt: '<Root>/Sqrt2'

    localB->rtb_Sum4_tmp_d = sqrt(fabs(localB->rtb_Product24_c[i]));

    // Math: '<Root>/Power3' incorporates:
    //   Math: '<Root>/Power2'

    localB->rty_u_kt = rty_u_kt[i];
    rtb_Sum4_tmp = localB->rty_u_kt * localB->rty_u_kt;

    // Signum: '<Root>/Sign3' incorporates:
    //   Gain: '<Root>/Gain1'

    localB->u = localB->rtb_Product24_k[i];
    if (rtIsNaN(localB->u)) {
      localB->u = (rtNaN);
    } else if (localB->u < 0.0) {
      localB->u = -1.0;
    } else {
      localB->u = (localB->u > 0.0);
    }

    // Sum: '<Root>/Sum4' incorporates:
    //   Gain: '<Root>/Gain1'
    //   Gain: '<Root>/Gain2'
    //   Math: '<Root>/Power3'
    //   Product: '<Root>/Product10'
    //   Product: '<Root>/Product8'
    //   Signum: '<Root>/Sign3'
    //   Sqrt: '<Root>/Sqrt3'

    localB->Sum4[i] = (0.0 - asgsm_quat_obs_P.Gain1_Gain * localB->rty_u_kt *
                       localB->rtb_Sum4_tmp_d * localB->u) -
      asgsm_quat_obs_P.Gain2_Gain * rtb_Sum4_tmp * localB->rtb_Product24_cx[i];

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
    //   Math: '<Root>/Power3'
    //   Product: '<Root>/Product11'
    //   Product: '<Root>/Product9'
    //   Sqrt: '<Root>/Sqrt'
    //   Sqrt: '<Root>/Sqrt1'
    //   Sqrt: '<Root>/Sqrt3'
    //   Sum: '<Root>/Sum11'

    localB->rtb_Sum4_tmp_d = (sqrt(rtu_PX4Params_ASGSMg_alpha_u[i]) *
      localB->rtb_Sum4_tmp_d - sqrt(rtu_PX4Params_ASGSMg_beta_u[i]) *
      rtb_Sum4_tmp) * asgsm_quat_obs_P.DiscreteTimeIntegrator_gainval;
    localB->rtb_Sum4_tmp[i] = localB->rtb_Sum4_tmp_d;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localDW->Memory_PreviousInput[i] = localDW->DiscreteTimeIntegrator_DSTATE[i]
      + localB->rtb_Sum4_tmp_d;
  }

  // MATLAB Function: '<S2>/Kronecker_product' incorporates:
  //   MATLAB Function: '<S1>/Kronecker_product'
  //   SignalConversion generated from: '<S9>/ SFunction '
  //   UnaryMinus: '<S5>/Unary Minus'
  //   UnaryMinus: '<S5>/Unary Minus1'
  //   UnaryMinus: '<S5>/Unary Minus2'

  localB->rtb_TmpSignalConversionAtSFun_m[0] = rtu_q_q_hat[0];
  localB->rtb_TmpSignalConversionAtSFun_m[4] = rtu_q_q_hat[1];
  localB->rtb_TmpSignalConversionAtSFun_m[8] = rtu_q_q_hat[2];
  localB->rtb_TmpSignalConversionAtSFun_m[12] = rtu_q_q_hat[3];
  localB->rtb_TmpSignalConversionAtSFun_m[1] = -rtu_q_q_hat[1];
  localB->rtb_TmpSignalConversionAtSFun_m[5] = rtu_q_q_hat[0];
  localB->rtb_TmpSignalConversionAtSFun_m[9] = rtu_q_q_hat[3];
  localB->rtb_TmpSignalConversionAtSFun_m[13] = -rtu_q_q_hat[2];
  localB->rtb_TmpSignalConversionAtSFun_m[2] = -rtu_q_q_hat[2];
  localB->rtb_TmpSignalConversionAtSFun_m[6] = -rtu_q_q_hat[3];
  localB->rtb_TmpSignalConversionAtSFun_m[10] = rtu_q_q_hat[0];
  localB->rtb_TmpSignalConversionAtSFun_m[14] = rtu_q_q_hat[1];
  localB->rtb_TmpSignalConversionAtSFun_m[3] = -rtu_q_q_hat[3];
  localB->rtb_TmpSignalConversionAtSFun_m[7] = rtu_q_q_hat[2];
  localB->rtb_TmpSignalConversionAtSFun_m[11] = -rtu_q_q_hat[1];
  localB->rtb_TmpSignalConversionAtSFun_m[15] = rtu_q_q_hat[0];

  // SignalConversion generated from: '<Root>/u_Outport_1'
  rty_u_sigma[0] = localB->rtb_Product24_idx_0;
  rty_u_sigma[3] = localB->rtb_Saturation1_idx_0;

  // SignalConversion generated from: '<Root>/u_Outport_1'
  rty_u_e[3] = localB->lnq[0];

  // Saturate: '<Root>/Saturation' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Abs: '<Root>/Abs5'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Math: '<Root>/Power4'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Divide2'
  //   Product: '<Root>/Product13'
  //   Product: '<Root>/Product14'
  //   Product: '<Root>/Product15'
  //   Product: '<Root>/Product16'
  //   Product: '<Root>/Product17'
  //   Product: '<Root>/Product18'
  //   Signum: '<Root>/Sign2'
  //   Sum: '<Root>/F_u'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum17'
  //   Sum: '<Root>/Sum18'

  localB->rtb_Product24_tmp_idx_0 = (((rt_powd_snf
    (localB->rtb_Product24_tmp_idx_0, rtu_PX4Params_ASGSMg_lambda1[0] -
     asgsm_quat_obs_P.Constant3_Value[0]) * (rtu_PX4Params_ASGSMg_lambda1[0] *
    rtu_PX4Params_ASGSMg_zeta1[0]) + asgsm_quat_obs_P.Constant5_Value[0]) *
    (rt_powd_snf(localB->rtb_Product24_tmp_idx_0_g,
                 asgsm_quat_obs_P.Constant4_Value[0] -
                 rtu_PX4Params_ASGSMg_lambda2[0]) *
     localB->rtb_Product24_tmp_idx_0_d / (rtu_PX4Params_ASGSMg_zeta2[0] *
    rtu_PX4Params_ASGSMg_lambda2[0])) - rtu_q_pos_ddot_hat[0]) - localB->Sum4[0])
    * rtu_PX4Params_MCg_MCData[0];
  if (localB->rtb_Product24_tmp_idx_0 > asgsm_quat_obs_P.Saturation_UpperSat[0])
  {
    // MATLAB Function: '<S2>/Kronecker_product'
    localB->rtb_Product24_tmp_idx_0 = asgsm_quat_obs_P.Saturation_UpperSat[0];
  } else if (localB->rtb_Product24_tmp_idx_0 <
             asgsm_quat_obs_P.Saturation_LowerSat[0]) {
    // MATLAB Function: '<S2>/Kronecker_product'
    localB->rtb_Product24_tmp_idx_0 = asgsm_quat_obs_P.Saturation_LowerSat[0];
  }

  // SignalConversion generated from: '<Root>/u_Outport_1'
  rty_u_sigma[1] = localB->rtb_Product24_idx_1;
  rty_u_sigma[4] = localB->rtb_Saturation1_idx_1;

  // SignalConversion generated from: '<Root>/u_Outport_1'
  rty_u_e_dot[1] = localB->rtb_Sum23_idx_1;
  rty_u_e_dot[4] = localB->rtb_tau_idx_1;

  // SignalConversion generated from: '<Root>/u_Outport_1'
  rty_u_e[1] = localB->rtb_Power5_idx_1;
  rty_u_e[4] = localB->lnq[1];

  // Saturate: '<Root>/Saturation' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Abs: '<Root>/Abs5'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Math: '<Root>/Power4'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Divide2'
  //   Product: '<Root>/Product13'
  //   Product: '<Root>/Product14'
  //   Product: '<Root>/Product15'
  //   Product: '<Root>/Product16'
  //   Product: '<Root>/Product17'
  //   Product: '<Root>/Product18'
  //   Signum: '<Root>/Sign2'
  //   Sum: '<Root>/F_u'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum17'
  //   Sum: '<Root>/Sum18'

  localB->rtb_Power5_idx_1 = (((rt_powd_snf(localB->rtb_Product24_tmp_idx_1,
    rtu_PX4Params_ASGSMg_lambda1[1] - asgsm_quat_obs_P.Constant3_Value[1]) *
    (rtu_PX4Params_ASGSMg_lambda1[1] * rtu_PX4Params_ASGSMg_zeta1[1]) +
    asgsm_quat_obs_P.Constant5_Value[1]) * (rt_powd_snf
    (localB->rtb_Product24_tmp_idx_1_d, asgsm_quat_obs_P.Constant4_Value[1] -
     rtu_PX4Params_ASGSMg_lambda2[1]) * localB->rtb_Product24_tmp_idx_1_l /
    (rtu_PX4Params_ASGSMg_zeta2[1] * rtu_PX4Params_ASGSMg_lambda2[1])) -
    rtu_q_pos_ddot_hat[1]) - localB->Sum4[1]) * rtu_PX4Params_MCg_MCData[0];
  if (localB->rtb_Power5_idx_1 > asgsm_quat_obs_P.Saturation_UpperSat[1]) {
    // MATLAB Function: '<S2>/Kronecker_product'
    localB->rtb_Power5_idx_1 = asgsm_quat_obs_P.Saturation_UpperSat[1];
  } else if (localB->rtb_Power5_idx_1 < asgsm_quat_obs_P.Saturation_LowerSat[1])
  {
    // MATLAB Function: '<S2>/Kronecker_product'
    localB->rtb_Power5_idx_1 = asgsm_quat_obs_P.Saturation_LowerSat[1];
  }

  // SignalConversion generated from: '<Root>/u_Outport_1' incorporates:
  //   Saturate: '<Root>/Saturation1'
  //   Sum: '<Root>/Sum24'

  rty_u_sigma[2] = localB->rtb_Product24_idx_2;
  rty_u_sigma[5] = localB->rtb_Saturation1_f;

  // SignalConversion generated from: '<Root>/u_Outport_1' incorporates:
  //   Saturate: '<Root>/tau'
  //   Sum: '<Root>/Sum15'
  //   Sum: '<Root>/Sum16'
  //   Sum: '<Root>/Sum23'

  rty_u_e_dot[2] = localB->rtb_Sum23_g;
  rty_u_e_dot[5] = localB->rtb_tau_c;

  // SignalConversion generated from: '<Root>/u_Outport_1' incorporates:
  //   Gain: '<Root>/Gain4'
  //   Math: '<Root>/Power5'
  //   Sum: '<Root>/Sum14'
  //   Sum: '<Root>/Sum20'

  rty_u_e[2] = localB->rtb_Power5_g;
  rty_u_e[5] = localB->rtb_lnq_p;

  // Saturate: '<Root>/Saturation' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Math: '<Root>/Power4'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Divide2'
  //   Product: '<Root>/Product13'
  //   Product: '<Root>/Product14'
  //   Product: '<Root>/Product15'
  //   Product: '<Root>/Product16'
  //   Product: '<Root>/Product17'
  //   Product: '<Root>/Product18'
  //   Signum: '<Root>/Sign1'
  //   Sum: '<Root>/F_u'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum17'
  //   Sum: '<Root>/Sum18'

  localB->rtb_Power5_g = (((rt_powd_snf(localB->rtb_Product24_tmp,
    rtu_PX4Params_ASGSMg_lambda1[2] - asgsm_quat_obs_P.Constant3_Value[2]) *
    (rtu_PX4Params_ASGSMg_lambda1[2] * rtu_PX4Params_ASGSMg_zeta1[2]) +
    asgsm_quat_obs_P.Constant5_Value[2]) * (rt_powd_snf
    (localB->rtb_Product24_tmp_n, asgsm_quat_obs_P.Constant4_Value[2] -
     rtu_PX4Params_ASGSMg_lambda2[2]) * localB->rtb_Product24_tmp_m /
    (rtu_PX4Params_ASGSMg_zeta2[2] * rtu_PX4Params_ASGSMg_lambda2[2])) -
    rtu_q_pos_ddot_hat[2]) - localB->Sum4[2]) * rtu_PX4Params_MCg_MCData[0];
  if (localB->rtb_Power5_g > asgsm_quat_obs_P.Saturation_UpperSat[2]) {
    // MATLAB Function: '<S2>/Kronecker_product'
    localB->rtb_Power5_g = asgsm_quat_obs_P.Saturation_UpperSat[2];
  } else if (localB->rtb_Power5_g < asgsm_quat_obs_P.Saturation_LowerSat[2]) {
    // MATLAB Function: '<S2>/Kronecker_product'
    localB->rtb_Power5_g = asgsm_quat_obs_P.Saturation_LowerSat[2];
  }

  // MATLAB Function: '<S2>/Kronecker_product'
  for (i = 0; i < 4; i++) {
    localB->r_g[i] = ((localB->rtb_TmpSignalConversionAtSFun_m[i + 4] *
                       localB->rtb_Product24_tmp_idx_0 +
                       localB->rtb_TmpSignalConversionAtSFun_m[i] * 0.0) +
                      localB->rtb_TmpSignalConversionAtSFun_m[i + 8] *
                      localB->rtb_Power5_idx_1) +
      localB->rtb_TmpSignalConversionAtSFun_m[i + 12] * localB->rtb_Power5_g;
  }

  // MATLAB Function: '<S3>/Kronecker_product'
  localB->rtb_TmpSignalConversionAtSFun_m[0] = localB->r_g[0];
  localB->rtb_TmpSignalConversionAtSFun_m[4] = -localB->r_g[1];
  localB->rtb_TmpSignalConversionAtSFun_m[8] = -localB->r_g[2];
  localB->rtb_TmpSignalConversionAtSFun_m[12] = -localB->r_g[3];
  localB->rtb_TmpSignalConversionAtSFun_m[1] = localB->r_g[1];
  localB->rtb_TmpSignalConversionAtSFun_m[5] = localB->r_g[0];
  localB->rtb_TmpSignalConversionAtSFun_m[9] = -localB->r_g[3];
  localB->rtb_TmpSignalConversionAtSFun_m[13] = localB->r_g[2];
  localB->rtb_TmpSignalConversionAtSFun_m[2] = localB->r_g[2];
  localB->rtb_TmpSignalConversionAtSFun_m[6] = localB->r_g[3];
  localB->rtb_TmpSignalConversionAtSFun_m[10] = localB->r_g[0];
  localB->rtb_TmpSignalConversionAtSFun_m[14] = -localB->r_g[1];
  localB->rtb_TmpSignalConversionAtSFun_m[3] = localB->r_g[3];
  localB->rtb_TmpSignalConversionAtSFun_m[7] = -localB->r_g[2];
  localB->rtb_TmpSignalConversionAtSFun_m[11] = localB->r_g[1];
  localB->rtb_TmpSignalConversionAtSFun_m[15] = localB->r_g[0];
  localB->rtb_Power5_g = rtu_q_q_hat[1];
  localB->rtb_Sum23_g = rtu_q_q_hat[0];
  localB->rtb_Product24_tmp = rtu_q_q_hat[2];
  localB->rtb_Product24_tmp_m = rtu_q_q_hat[3];
  for (i = 0; i < 4; i++) {
    localB->r_g[i] = ((localB->rtb_TmpSignalConversionAtSFun_m[i + 4] *
                       localB->rtb_Power5_g +
                       localB->rtb_TmpSignalConversionAtSFun_m[i] *
                       localB->rtb_Sum23_g) +
                      localB->rtb_TmpSignalConversionAtSFun_m[i + 8] *
                      localB->rtb_Product24_tmp) +
      localB->rtb_TmpSignalConversionAtSFun_m[i + 12] *
      localB->rtb_Product24_tmp_m;
  }

  // End of MATLAB Function: '<S3>/Kronecker_product'

  // Sum: '<Root>/Sum23' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Abs: '<Root>/Abs7'
  //   Abs: '<Root>/Abs8'
  //   Abs: '<Root>/Abs9'
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<Root>/Constant9'
  //   Math: '<Root>/Power6'
  //   Math: '<Root>/Power7'
  //   Product: '<Root>/Divide3'
  //   Product: '<Root>/Product20'
  //   Product: '<Root>/Product21'
  //   Product: '<Root>/Product22'
  //   Product: '<Root>/Product23'
  //   Product: '<Root>/Product24'
  //   Signum: '<Root>/Sign6'
  //   Signum: '<Root>/Sign7'
  //   Sum: '<Root>/Sum19'
  //   Sum: '<Root>/Sum20'
  //   Sum: '<Root>/Sum21'
  //   Sum: '<Root>/Sum22'

  localB->rtb_Power5_g = (rt_powd_snf(localB->rtb_Saturation1_tmp_idx_0,
    rtu_PX4Params_ASGSMg_lambda1[3] - asgsm_quat_obs_P.Constant7_Value[0]) *
    (rtu_PX4Params_ASGSMg_lambda1[3] * rtu_PX4Params_ASGSMg_zeta1[3]) +
    asgsm_quat_obs_P.Constant9_Value[0]) * (rt_powd_snf
    (localB->rtb_Saturation1_tmp_idx_0_l, asgsm_quat_obs_P.Constant8_Value[0] -
     rtu_PX4Params_ASGSMg_lambda2[3]) * localB->rtb_Saturation1_tmp_idx_0_p /
    (rtu_PX4Params_ASGSMg_zeta2[3] * rtu_PX4Params_ASGSMg_lambda2[3])) + ((0.0 -
    rtu_q_pos_ddot_hat[3]) - localB->Sum4[3]);
  localB->rtb_Sum23_g = (rt_powd_snf(rtu_qd_quaternion_d_2,
    rtu_PX4Params_ASGSMg_lambda1[4] - asgsm_quat_obs_P.Constant7_Value[1]) *
    (rtu_PX4Params_ASGSMg_lambda1[4] * rtu_PX4Params_ASGSMg_zeta1[4]) +
    asgsm_quat_obs_P.Constant9_Value[1]) * (rt_powd_snf
    (localB->rtb_Saturation1_tmp_idx_1_j, asgsm_quat_obs_P.Constant8_Value[1] -
     rtu_PX4Params_ASGSMg_lambda2[4]) * localB->rtb_Saturation1_tmp_idx_1 /
    (rtu_PX4Params_ASGSMg_zeta2[4] * rtu_PX4Params_ASGSMg_lambda2[4])) + ((0.0 -
    rtu_q_pos_ddot_hat[4]) - localB->Sum4[4]);
  localB->rtb_Product24_tmp = (rt_powd_snf(localB->sqrt_b,
    rtu_PX4Params_ASGSMg_lambda1[5] - asgsm_quat_obs_P.Constant7_Value[2]) *
    (rtu_PX4Params_ASGSMg_lambda1[5] * rtu_PX4Params_ASGSMg_zeta1[5]) +
    asgsm_quat_obs_P.Constant9_Value[2]) * (rt_powd_snf(rtu_qd_quaternion_d_1,
    asgsm_quat_obs_P.Constant8_Value[2] - rtu_PX4Params_ASGSMg_lambda2[5]) *
    rtu_qd_quaternion_d_0 / (rtu_PX4Params_ASGSMg_zeta2[5] *
    rtu_PX4Params_ASGSMg_lambda2[5])) + ((0.0 - rtu_q_pos_ddot_hat[5]) -
    localB->Sum4[5]);
  for (i = 0; i < 3; i++) {
    // Product: '<Root>/Matrix Multiply5'
    localB->rtb_Product24_tmp_m = (localB->J[i + 3] * localB->rtb_Sum23_g +
      localB->J[i] * localB->rtb_Power5_g) + localB->J[i + 6] *
      localB->rtb_Product24_tmp;

    // Saturate: '<Root>/Saturation1'
    localB->rtb_Product24_tmp_idx_0 = localB->r_g[i + 1];
    localB->rtb_Product24_tmp_n = asgsm_quat_obs_P.Saturation1_LowerSat[i];
    localB->rtb_Product24_idx_2 = asgsm_quat_obs_P.Saturation1_UpperSat[i];
    if (localB->rtb_Product24_tmp_idx_0 > localB->rtb_Product24_idx_2) {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i] = localB->rtb_Product24_idx_2;
    } else if (localB->rtb_Product24_tmp_idx_0 < localB->rtb_Product24_tmp_n) {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i] = localB->rtb_Product24_tmp_n;
    } else {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i] = localB->rtb_Product24_tmp_idx_0;
    }

    // End of Saturate: '<Root>/Saturation1'

    // Saturate: '<Root>/tau' incorporates:
    //   Product: '<Root>/Matrix Multiply5'

    if (localB->rtb_Product24_tmp_m > asgsm_quat_obs_P.tau_UpperSat) {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i + 3] = asgsm_quat_obs_P.tau_UpperSat;
    } else if (localB->rtb_Product24_tmp_m < asgsm_quat_obs_P.tau_LowerSat) {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i + 3] = asgsm_quat_obs_P.tau_LowerSat;
    } else {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i + 3] = localB->rtb_Product24_tmp_m;
    }

    // End of Saturate: '<Root>/tau'
  }

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  for (i = 0; i < 6; i++) {
    localDW->DiscreteTimeIntegrator_DSTATE[i] = localDW->Memory_PreviousInput[i]
      + localB->rtb_Sum4_tmp[i];
  }
}

// Model initialize function
void asgsm_quat_obs_initialize(const char_T **rt_errorStatus,
  RT_MODEL_asgsm_quat_obs_T *const asgsm_quat_obs_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  asgsm_quat_obs_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_asgsm_quat_obs_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_asgsm_quat_obs_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_asgsm_quat_obs_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_asgsm_quat_obs_T::setErrorStatus(const char_T* const aErrorStatus)
  const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
