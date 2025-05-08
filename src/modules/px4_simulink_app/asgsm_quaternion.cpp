//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: asgsm_quaternion.cpp
//
// Code generated for Simulink model 'asgsm_quaternion'.
//
// Model version                  : 1.43
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue Apr 29 18:08:38 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "asgsm_quaternion.h"
#include "rtwtypes.h"
#include "asgsm_quaternion_private.h"
#include <string.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_powd_snf.h"
#include "norm_07B1VLxa.h"
#include "rt_assert.h"

P_asgsm_quaternion_T asgsm_quaternion_P = {
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

  // Expression: [0; 0; -9.81]
  //  Referenced by: '<Root>/Constant'

  { 0.0, 0.0, -9.81 },

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

  -0.5,

  // Computed Parameter: Assertion_Enabled
  //  Referenced by: '<S2>/Assertion'

  true
};

// Forward declaration for local functions
static void asgsm_quaternion_rt_invd3x3_snf(const real_T u[9], real_T y[9],
  B_asgsm_quaternion_c_T *localB);
static void asgsm_quaternion_rt_invd3x3_snf(const real_T u[9], real_T y[9],
  B_asgsm_quaternion_c_T *localB)
{
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  memcpy(&localB->x[0], &u[0], 9U * sizeof(real_T));
  p1 = 1;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(u[0]);
  absx21 = fabs(u[1]);
  absx31 = fabs(u[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 4;
    p2 = 0;
    localB->x[0] = u[1];
    localB->x[1] = u[0];
    localB->x[3] = u[4];
    localB->x[4] = u[3];
    localB->x[6] = u[7];
    localB->x[7] = u[6];
  } else if (absx31 > absx11) {
    p1 = 7;
    p3 = 0;
    localB->x[2] = localB->x[0];
    localB->x[0] = u[2];
    localB->x[5] = localB->x[3];
    localB->x[3] = u[5];
    localB->x[8] = localB->x[6];
    localB->x[6] = u[8];
  }

  absx11 = localB->x[1] / localB->x[0];
  localB->x[1] = absx11;
  absx21 = localB->x[2] / localB->x[0];
  localB->x[2] = absx21;
  localB->x[4] -= absx11 * localB->x[3];
  localB->x[5] -= absx21 * localB->x[3];
  localB->x[7] -= absx11 * localB->x[6];
  localB->x[8] -= absx21 * localB->x[6];
  if (fabs(localB->x[5]) > fabs(localB->x[4])) {
    int32_T itmp;
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    localB->x[1] = absx21;
    localB->x[2] = absx11;
    absx11 = localB->x[4];
    localB->x[4] = localB->x[5];
    localB->x[5] = absx11;
    absx11 = localB->x[7];
    localB->x[7] = localB->x[8];
    localB->x[8] = absx11;
  }

  absx11 = localB->x[5] / localB->x[4];
  localB->x[8] -= absx11 * localB->x[7];
  absx21 = (localB->x[1] * absx11 - localB->x[2]) / localB->x[8];
  absx31 = -(localB->x[7] * absx21 + localB->x[1]) / localB->x[4];
  y[p1 - 1] = ((1.0 - localB->x[3] * absx31) - localB->x[6] * absx21) /
    localB->x[0];
  y[p1] = absx31;
  y[p1 + 1] = absx21;
  absx21 = -absx11 / localB->x[8];
  absx31 = (1.0 - localB->x[7] * absx21) / localB->x[4];
  y[p2] = -(localB->x[3] * absx31 + localB->x[6] * absx21) / localB->x[0];
  y[p2 + 1] = absx31;
  y[p2 + 2] = absx21;
  absx21 = 1.0 / localB->x[8];
  absx31 = -localB->x[7] * absx21 / localB->x[4];
  y[p3] = -(localB->x[3] * absx31 + localB->x[6] * absx21) / localB->x[0];
  y[p3 + 1] = absx31;
  y[p3 + 2] = absx21;
}

// System initialize for referenced model: 'asgsm_quaternion'
void asgsm_quaternion_Init(DW_asgsm_quaternion_f_T *localDW)
{
  for (int32_T i = 0; i < 6; i++) {
    // InitializeConditions for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput[i] =
      asgsm_quaternion_P.Memory_InitialCondition[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE[i] =
      asgsm_quaternion_P.DiscreteTimeIntegrator_IC[i];
  }
}

// Output and update for referenced model: 'asgsm_quaternion'
void asgsm_quaternion(const real_T rtu_qd_qd[6], const real_T rtu_qd_qd_dot[6],
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
                      real_T rty_u_kt[6], real_T rty_u_qe[4],
                      B_asgsm_quaternion_c_T *localB, DW_asgsm_quaternion_f_T
                      *localDW)
{
  real_T rtu_qd_quaternion_d_0;
  real_T rtu_qd_quaternion_d_1;
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

  localB->rtb_Power5_f = rtu_qd_qd[0] - rtu_q_pos_hat[0];
  localB->Power5[0] = localB->rtb_Power5_f;

  // Sum: '<Root>/Sum15' incorporates:
  //   Product: '<Root>/Product24'

  localB->rtb_Product24_g = rtu_qd_qd_dot[0] - rtu_q_pos_dot_hat[0];
  localB->Product24[0] = localB->rtb_Product24_g;

  // Abs: '<Root>/Abs' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power5'

  localB->rtb_Sum23_tmp = fabs(localB->rtb_Power5_f);
  localB->rtb_Sum23_tmp_idx_0 = localB->rtb_Sum23_tmp;

  // Signum: '<Root>/Sign1'
  if (rtIsNaN(localB->rtb_Product24_g)) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = (rtNaN);
  } else if (localB->rtb_Product24_g < 0.0) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = -1.0;
  } else {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = (localB->rtb_Product24_g > 0.0);
  }

  localB->rtb_Sum23_tmp_idx_0_m = localB->rtb_Sum23_tmp_g;

  // Abs: '<Root>/Abs1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Product: '<Root>/Product24'

  localB->rtb_Product24_g = fabs(localB->rtb_Product24_g);
  localB->rtb_Sum23_tmp_idx_0_n = localB->rtb_Product24_g;

  // Signum: '<Root>/Sign'
  if (rtIsNaN(localB->rtb_Power5_f)) {
    localB->Product3_c = (rtNaN);
  } else if (localB->rtb_Power5_f < 0.0) {
    localB->Product3_c = -1.0;
  } else {
    localB->Product3_c = (localB->rtb_Power5_f > 0.0);
  }

  // Sum: '<Root>/Sum9' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'
  //   Signum: '<Root>/Sign1'
  //   Sum: '<Root>/Sum23'

  localB->Sum23[0] = (rtu_PX4Params_ASGSMg_zeta1[0] * rt_powd_snf
                      (localB->rtb_Sum23_tmp, rtu_PX4Params_ASGSMg_lambda1[0]) *
                      localB->Product3_c + localB->rtb_Power5_f) +
    rtu_PX4Params_ASGSMg_zeta2[0] * rt_powd_snf(localB->rtb_Product24_g,
    rtu_PX4Params_ASGSMg_lambda2[0]) * localB->rtb_Sum23_tmp_g;

  // Sum: '<Root>/Sum14' incorporates:
  //   Math: '<Root>/Power5'

  localB->rtb_Power5_f = rtu_qd_qd[1] - rtu_q_pos_hat[1];
  localB->Power5[1] = localB->rtb_Power5_f;

  // Sum: '<Root>/Sum15' incorporates:
  //   Product: '<Root>/Product24'

  localB->rtb_Product24_g = rtu_qd_qd_dot[1] - rtu_q_pos_dot_hat[1];
  localB->Product24[1] = localB->rtb_Product24_g;

  // Abs: '<Root>/Abs' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power5'

  localB->rtb_Sum23_tmp = fabs(localB->rtb_Power5_f);
  localB->rtb_Sum23_tmp_idx_1 = localB->rtb_Sum23_tmp;

  // Signum: '<Root>/Sign1'
  if (rtIsNaN(localB->rtb_Product24_g)) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = (rtNaN);
  } else if (localB->rtb_Product24_g < 0.0) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = -1.0;
  } else {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = (localB->rtb_Product24_g > 0.0);
  }

  localB->rtb_Sum23_tmp_idx_1_p = localB->rtb_Sum23_tmp_g;

  // Abs: '<Root>/Abs1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Product: '<Root>/Product24'

  localB->rtb_Product24_g = fabs(localB->rtb_Product24_g);
  localB->rtb_Sum23_tmp_idx_1_l = localB->rtb_Product24_g;

  // Signum: '<Root>/Sign'
  if (rtIsNaN(localB->rtb_Power5_f)) {
    localB->Product3_c = (rtNaN);
  } else if (localB->rtb_Power5_f < 0.0) {
    localB->Product3_c = -1.0;
  } else {
    localB->Product3_c = (localB->rtb_Power5_f > 0.0);
  }

  // Sum: '<Root>/Sum9' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'
  //   Signum: '<Root>/Sign1'
  //   Sum: '<Root>/Sum23'

  localB->Sum23[1] = (rtu_PX4Params_ASGSMg_zeta1[1] * rt_powd_snf
                      (localB->rtb_Sum23_tmp, rtu_PX4Params_ASGSMg_lambda1[1]) *
                      localB->Product3_c + localB->rtb_Power5_f) +
    rtu_PX4Params_ASGSMg_zeta2[1] * rt_powd_snf(localB->rtb_Product24_g,
    rtu_PX4Params_ASGSMg_lambda2[1]) * localB->rtb_Sum23_tmp_g;

  // Sum: '<Root>/Sum14' incorporates:
  //   Math: '<Root>/Power5'

  localB->rtb_Power5_f = rtu_qd_qd[2] - rtu_q_pos_hat[2];
  localB->Power5[2] = localB->rtb_Power5_f;

  // Sum: '<Root>/Sum15' incorporates:
  //   Product: '<Root>/Product24'

  localB->rtb_Product24_g = rtu_qd_qd_dot[2] - rtu_q_pos_dot_hat[2];
  localB->Product24[2] = localB->rtb_Product24_g;

  // Abs: '<Root>/Abs' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power5'

  localB->rtb_Sum23_tmp = fabs(localB->rtb_Power5_f);

  // Signum: '<Root>/Sign1'
  if (rtIsNaN(localB->rtb_Product24_g)) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = (rtNaN);
  } else if (localB->rtb_Product24_g < 0.0) {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = -1.0;
  } else {
    // Signum: '<Root>/Sign2'
    localB->rtb_Sum23_tmp_g = (localB->rtb_Product24_g > 0.0);
  }

  // Abs: '<Root>/Abs1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Product: '<Root>/Product24'

  localB->rtb_Product24_g = fabs(localB->rtb_Product24_g);

  // Signum: '<Root>/Sign'
  if (rtIsNaN(localB->rtb_Power5_f)) {
    localB->Product3_c = (rtNaN);
  } else if (localB->rtb_Power5_f < 0.0) {
    localB->Product3_c = -1.0;
  } else {
    localB->Product3_c = (localB->rtb_Power5_f > 0.0);
  }

  // Sum: '<Root>/Sum9' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'
  //   Signum: '<Root>/Sign1'
  //   Sum: '<Root>/Sum23'

  localB->Sum23[2] = (rtu_PX4Params_ASGSMg_zeta1[2] * rt_powd_snf
                      (localB->rtb_Sum23_tmp, rtu_PX4Params_ASGSMg_lambda1[2]) *
                      localB->Product3_c + localB->rtb_Power5_f) +
    rtu_PX4Params_ASGSMg_zeta2[2] * rt_powd_snf(localB->rtb_Product24_g,
    rtu_PX4Params_ASGSMg_lambda2[2]) * localB->rtb_Sum23_tmp_g;

  // MATLAB Function: '<S3>/Kronecker_product' incorporates:
  //   SignalConversion generated from: '<S12>/ SFunction '
  //   UnaryMinus: '<S7>/Unary Minus'
  //   UnaryMinus: '<S7>/Unary Minus1'
  //   UnaryMinus: '<S7>/Unary Minus2'

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
  localB->Product3_c = rtu_qd_quaternion_d[1];
  localB->rtb_Power5_f = rtu_qd_quaternion_d[0];
  rtu_qd_quaternion_d_0 = rtu_qd_quaternion_d[2];
  rtu_qd_quaternion_d_1 = rtu_qd_quaternion_d[3];
  for (i = 0; i < 4; i++) {
    localB->r_o[i] = ((localB->rtb_TmpSignalConversionAtSFun_m[i + 4] *
                       localB->Product3_c +
                       localB->rtb_TmpSignalConversionAtSFun_m[i] *
                       localB->rtb_Power5_f) +
                      localB->rtb_TmpSignalConversionAtSFun_m[i + 8] *
                      rtu_qd_quaternion_d_0) +
      localB->rtb_TmpSignalConversionAtSFun_m[i + 12] * rtu_qd_quaternion_d_1;
  }

  // Sqrt: '<S15>/sqrt' incorporates:
  //   Product: '<S16>/Product'
  //   Product: '<S16>/Product1'
  //   Product: '<S16>/Product2'
  //   Product: '<S16>/Product3'
  //   Sum: '<S16>/Sum'

  localB->Product3_c = sqrt(((localB->r_o[0] * localB->r_o[0] + localB->r_o[1] *
    localB->r_o[1]) + localB->r_o[2] * localB->r_o[2]) + localB->r_o[3] *
    localB->r_o[3]);

  // SignalConversion generated from: '<S17>/ SFunction ' incorporates:
  //   MATLAB Function: '<S10>/MATLAB Function'
  //   Product: '<S9>/Product'
  //   Product: '<S9>/Product1'
  //   Product: '<S9>/Product2'
  //   Product: '<S9>/Product3'
  //   SignalConversion generated from: '<Root>/u_Outport_1'

  rty_u_qe[0] = localB->r_o[0] / localB->Product3_c;
  rty_u_qe[1] = localB->r_o[1] / localB->Product3_c;
  rty_u_qe[2] = localB->r_o[2] / localB->Product3_c;
  rty_u_qe[3] = localB->r_o[3] / localB->Product3_c;

  // MATLAB Function: '<S10>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S17>/ SFunction '

  localB->lnq[0] = rty_u_qe[1];
  localB->lnq[1] = rty_u_qe[2];
  localB->lnq[2] = rty_u_qe[3];
  localB->Product3_c = norm_07B1VLxa(localB->lnq);
  if (localB->Product3_c == 0.0) {
    localB->lnq[0] = 0.0;
    localB->lnq[1] = 0.0;
    localB->lnq[2] = 0.0;
  } else {
    localB->rtb_Power5_f = acos(rty_u_qe[0]);
    localB->lnq[0] = rty_u_qe[1] / localB->Product3_c * localB->rtb_Power5_f;
    localB->lnq[1] = rty_u_qe[2] / localB->Product3_c * localB->rtb_Power5_f;
    localB->lnq[2] = rty_u_qe[3] / localB->Product3_c * localB->rtb_Power5_f;
  }

  // Gain: '<Root>/Gain4' incorporates:
  //   Sum: '<Root>/Sum20'

  localB->rtb_Power5_f = asgsm_quaternion_P.Gain4_Gain * localB->lnq[0];
  localB->lnq[0] = localB->rtb_Power5_f;

  // Sum: '<Root>/Sum16' incorporates:
  //   Saturate: '<Root>/tau'

  localB->Product3_c = rtu_qd_qd_dot[3] - rtu_q_pos_dot_hat[3];
  localB->tau[0] = localB->Product3_c;

  // Abs: '<Root>/Abs8' incorporates:
  //   Abs: '<Root>/Abs7'
  //   Sum: '<Root>/Sum20'

  rtu_qd_quaternion_d_0 = fabs(localB->rtb_Power5_f);
  localB->rtb_Saturation1_tmp[0] = rtu_qd_quaternion_d_0;

  // Signum: '<Root>/Sign6' incorporates:
  //   Saturate: '<Root>/tau'

  if (rtIsNaN(localB->Product3_c)) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = (rtNaN);
  } else if (localB->Product3_c < 0.0) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = -1.0;
  } else {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = (localB->Product3_c > 0.0);
  }

  localB->rtb_Saturation1_tmp_b[0] = rtu_qd_quaternion_d_1;

  // Abs: '<Root>/Abs9' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Saturate: '<Root>/tau'

  localB->rtb_Saturation1_tmp_c = fabs(localB->Product3_c);
  localB->rtb_Saturation1_tmp_p[0] = localB->rtb_Saturation1_tmp_c;

  // Signum: '<Root>/Sign5'
  if (rtIsNaN(localB->rtb_Power5_f)) {
    localB->Product3_c = (rtNaN);
  } else if (localB->rtb_Power5_f < 0.0) {
    localB->Product3_c = -1.0;
  } else {
    localB->Product3_c = (localB->rtb_Power5_f > 0.0);
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

  localB->Product3_c = (rtu_PX4Params_ASGSMg_zeta1[3] * rt_powd_snf
                        (rtu_qd_quaternion_d_0, rtu_PX4Params_ASGSMg_lambda1[3])
                        * localB->Product3_c + localB->rtb_Power5_f) +
    rtu_PX4Params_ASGSMg_zeta2[3] * rt_powd_snf(localB->rtb_Saturation1_tmp_c,
    rtu_PX4Params_ASGSMg_lambda2[3]) * rtu_qd_quaternion_d_1;
  localB->Saturation1[0] = localB->Product3_c;

  // Abs: '<Root>/Abs3'
  localB->rtb_Sum23_c[0] = localB->Sum23[0];
  localB->rtb_Sum23_c[3] = localB->Product3_c;

  // Gain: '<Root>/Gain4' incorporates:
  //   Sum: '<Root>/Sum20'

  localB->rtb_Power5_f = asgsm_quaternion_P.Gain4_Gain * localB->lnq[1];
  localB->lnq[1] = localB->rtb_Power5_f;

  // Sum: '<Root>/Sum16' incorporates:
  //   Saturate: '<Root>/tau'

  localB->Product3_c = rtu_qd_qd_dot[4] - rtu_q_pos_dot_hat[4];
  localB->tau[1] = localB->Product3_c;

  // Abs: '<Root>/Abs8' incorporates:
  //   Abs: '<Root>/Abs7'
  //   Sum: '<Root>/Sum20'

  rtu_qd_quaternion_d_0 = fabs(localB->rtb_Power5_f);
  localB->rtb_Saturation1_tmp[1] = rtu_qd_quaternion_d_0;

  // Signum: '<Root>/Sign6' incorporates:
  //   Saturate: '<Root>/tau'

  if (rtIsNaN(localB->Product3_c)) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = (rtNaN);
  } else if (localB->Product3_c < 0.0) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = -1.0;
  } else {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = (localB->Product3_c > 0.0);
  }

  localB->rtb_Saturation1_tmp_b[1] = rtu_qd_quaternion_d_1;

  // Abs: '<Root>/Abs9' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Saturate: '<Root>/tau'

  localB->rtb_Saturation1_tmp_c = fabs(localB->Product3_c);
  localB->rtb_Saturation1_tmp_p[1] = localB->rtb_Saturation1_tmp_c;

  // Signum: '<Root>/Sign5'
  if (rtIsNaN(localB->rtb_Power5_f)) {
    localB->Product3_c = (rtNaN);
  } else if (localB->rtb_Power5_f < 0.0) {
    localB->Product3_c = -1.0;
  } else {
    localB->Product3_c = (localB->rtb_Power5_f > 0.0);
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

  localB->Product3_c = (rtu_PX4Params_ASGSMg_zeta1[4] * rt_powd_snf
                        (rtu_qd_quaternion_d_0, rtu_PX4Params_ASGSMg_lambda1[4])
                        * localB->Product3_c + localB->rtb_Power5_f) +
    rtu_PX4Params_ASGSMg_zeta2[4] * rt_powd_snf(localB->rtb_Saturation1_tmp_c,
    rtu_PX4Params_ASGSMg_lambda2[4]) * rtu_qd_quaternion_d_1;
  localB->Saturation1[1] = localB->Product3_c;

  // Abs: '<Root>/Abs3'
  localB->rtb_Sum23_c[1] = localB->Sum23[1];
  localB->rtb_Sum23_c[4] = localB->Product3_c;

  // Gain: '<Root>/Gain4' incorporates:
  //   Sum: '<Root>/Sum20'

  localB->rtb_Power5_f = asgsm_quaternion_P.Gain4_Gain * localB->lnq[2];
  localB->lnq[2] = localB->rtb_Power5_f;

  // Sum: '<Root>/Sum16' incorporates:
  //   Saturate: '<Root>/tau'

  localB->Product3_c = rtu_qd_qd_dot[5] - rtu_q_pos_dot_hat[5];
  localB->tau[2] = localB->Product3_c;

  // Abs: '<Root>/Abs8' incorporates:
  //   Abs: '<Root>/Abs7'
  //   Sum: '<Root>/Sum20'

  rtu_qd_quaternion_d_0 = fabs(localB->rtb_Power5_f);
  localB->rtb_Saturation1_tmp[2] = rtu_qd_quaternion_d_0;

  // Signum: '<Root>/Sign6' incorporates:
  //   Saturate: '<Root>/tau'

  if (rtIsNaN(localB->Product3_c)) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = (rtNaN);
  } else if (localB->Product3_c < 0.0) {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = -1.0;
  } else {
    // Signum: '<Root>/Sign7'
    rtu_qd_quaternion_d_1 = (localB->Product3_c > 0.0);
  }

  localB->rtb_Saturation1_tmp_b[2] = rtu_qd_quaternion_d_1;

  // Abs: '<Root>/Abs9' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Saturate: '<Root>/tau'

  localB->rtb_Saturation1_tmp_c = fabs(localB->Product3_c);
  localB->rtb_Saturation1_tmp_p[2] = localB->rtb_Saturation1_tmp_c;

  // Signum: '<Root>/Sign5'
  if (rtIsNaN(localB->rtb_Power5_f)) {
    localB->Product3_c = (rtNaN);
  } else if (localB->rtb_Power5_f < 0.0) {
    localB->Product3_c = -1.0;
  } else {
    localB->Product3_c = (localB->rtb_Power5_f > 0.0);
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

  localB->Product3_c = (rtu_PX4Params_ASGSMg_zeta1[5] * rt_powd_snf
                        (rtu_qd_quaternion_d_0, rtu_PX4Params_ASGSMg_lambda1[5])
                        * localB->Product3_c + localB->rtb_Power5_f) +
    rtu_PX4Params_ASGSMg_zeta2[5] * rt_powd_snf(localB->rtb_Saturation1_tmp_c,
    rtu_PX4Params_ASGSMg_lambda2[5]) * rtu_qd_quaternion_d_1;
  localB->Saturation1[2] = localB->Product3_c;

  // Abs: '<Root>/Abs3'
  localB->rtb_Sum23_c[2] = localB->Sum23[2];
  localB->rtb_Sum23_c[5] = localB->Product3_c;

  // Signum: '<Root>/Sign3'
  localB->rtb_Sum23_k[0] = localB->Sum23[0];
  localB->rtb_Sum23_k[3] = localB->Saturation1[0];

  // Product: '<Root>/Product10' incorporates:
  //   Signum: '<Root>/Sign3'

  localB->rtb_Sum23_cx[0] = localB->Sum23[0];
  localB->rtb_Sum23_cx[3] = localB->Saturation1[0];

  // Signum: '<Root>/Sign3'
  localB->rtb_Sum23_k[1] = localB->Sum23[1];
  localB->rtb_Sum23_k[4] = localB->Saturation1[1];

  // Product: '<Root>/Product10' incorporates:
  //   Signum: '<Root>/Sign3'

  localB->rtb_Sum23_cx[1] = localB->Sum23[1];
  localB->rtb_Sum23_cx[4] = localB->Saturation1[1];

  // Signum: '<Root>/Sign3' incorporates:
  //   Saturate: '<Root>/Saturation1'
  //   Sum: '<Root>/Sum24'

  localB->rtb_Sum23_k[2] = localB->Sum23[2];
  localB->rtb_Sum23_k[5] = localB->Product3_c;

  // Product: '<Root>/Product10' incorporates:
  //   Saturate: '<Root>/Saturation1'
  //   Signum: '<Root>/Sign3'
  //   Sum: '<Root>/Sum24'

  localB->rtb_Sum23_cx[2] = localB->Sum23[2];
  localB->rtb_Sum23_cx[5] = localB->Product3_c;
  for (i = 0; i < 6; i++) {
    // Sqrt: '<Root>/Sqrt3' incorporates:
    //   Abs: '<Root>/Abs3'
    //   Sqrt: '<Root>/Sqrt2'

    localB->rtb_Power5_f = sqrt(fabs(localB->rtb_Sum23_c[i]));

    // Math: '<Root>/Power3' incorporates:
    //   Math: '<Root>/Power2'

    rtu_qd_quaternion_d_0 = rty_u_kt[i];
    rtu_qd_quaternion_d_1 = rtu_qd_quaternion_d_0 * rtu_qd_quaternion_d_0;

    // Signum: '<Root>/Sign3' incorporates:
    //   Gain: '<Root>/Gain1'

    localB->Product3_c = localB->rtb_Sum23_k[i];
    if (rtIsNaN(localB->Product3_c)) {
      localB->Product3_c = (rtNaN);
    } else if (localB->Product3_c < 0.0) {
      localB->Product3_c = -1.0;
    } else {
      localB->Product3_c = (localB->Product3_c > 0.0);
    }

    // Sum: '<Root>/Sum4' incorporates:
    //   Gain: '<Root>/Gain1'
    //   Gain: '<Root>/Gain2'
    //   Math: '<Root>/Power3'
    //   Product: '<Root>/Product10'
    //   Product: '<Root>/Product8'
    //   Signum: '<Root>/Sign3'
    //   Sqrt: '<Root>/Sqrt3'

    localB->Sum4[i] = (0.0 - asgsm_quaternion_P.Gain1_Gain *
                       rtu_qd_quaternion_d_0 * localB->rtb_Power5_f *
                       localB->Product3_c) - asgsm_quaternion_P.Gain2_Gain *
      rtu_qd_quaternion_d_1 * localB->rtb_Sum23_cx[i];

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
    //   Math: '<Root>/Power3'
    //   Product: '<Root>/Product11'
    //   Product: '<Root>/Product9'
    //   Sqrt: '<Root>/Sqrt'
    //   Sqrt: '<Root>/Sqrt1'
    //   Sqrt: '<Root>/Sqrt3'
    //   Sum: '<Root>/Sum11'

    localB->rtb_Power5_f = (sqrt(rtu_PX4Params_ASGSMg_alpha_u[i]) *
      localB->rtb_Power5_f - sqrt(rtu_PX4Params_ASGSMg_beta_u[i]) *
      rtu_qd_quaternion_d_1) * asgsm_quaternion_P.DiscreteTimeIntegrator_gainval;
    localB->rtb_Sum4_tmp[i] = localB->rtb_Power5_f;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localDW->Memory_PreviousInput[i] = localDW->DiscreteTimeIntegrator_DSTATE[i]
      + localB->rtb_Power5_f;
  }

  // Product: '<Root>/Product19'
  localB->Product3_c = rtu_q_pos_dot_hat[4];
  localB->rtb_Power5_f = rtu_q_pos_dot_hat[3];
  rtu_qd_quaternion_d_0 = rtu_q_pos_dot_hat[5];
  for (i = 0; i < 3; i++) {
    // SignalConversion generated from: '<Root>/u_Outport_1'
    rty_u_sigma[i] = localB->Sum23[i];
    rty_u_sigma[i + 3] = localB->Saturation1[i];

    // SignalConversion generated from: '<Root>/u_Outport_1'
    rty_u_e_dot[i] = localB->Product24[i];
    rty_u_e_dot[i + 3] = localB->tau[i];

    // SignalConversion generated from: '<Root>/u_Outport_1'
    rty_u_e[i] = localB->Power5[i];
    rty_u_e[i + 3] = localB->lnq[i];

    // Product: '<Root>/Product19' incorporates:
    //   Saturate: '<Root>/Saturation1'

    localB->Saturation1[i] = (localB->J[i + 3] * localB->Product3_c + localB->
      J[i] * localB->rtb_Power5_f) + localB->J[i + 6] * rtu_qd_quaternion_d_0;
  }

  // MATLAB Function: '<S4>/Kronecker_product' incorporates:
  //   MATLAB Function: '<S3>/Kronecker_product'
  //   SignalConversion generated from: '<S12>/ SFunction '
  //   UnaryMinus: '<S7>/Unary Minus'
  //   UnaryMinus: '<S7>/Unary Minus1'
  //   UnaryMinus: '<S7>/Unary Minus2'

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

  // Saturate: '<Root>/Saturation' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Abs: '<Root>/Abs2'
  //   Abs: '<Root>/Abs5'
  //   Constant: '<Root>/Constant'
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
  //   Signum: '<Root>/Sign2'
  //   Sum: '<Root>/F_u'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum17'
  //   Sum: '<Root>/Sum18'

  localB->rtb_Sum23_tmp_idx_0 = ((((rt_powd_snf(localB->rtb_Sum23_tmp_idx_0,
    rtu_PX4Params_ASGSMg_lambda1[0] - asgsm_quaternion_P.Constant3_Value[0]) *
    (rtu_PX4Params_ASGSMg_lambda1[0] * rtu_PX4Params_ASGSMg_zeta1[0]) +
    asgsm_quaternion_P.Constant5_Value[0]) * (rt_powd_snf
    (localB->rtb_Sum23_tmp_idx_0_n, asgsm_quaternion_P.Constant4_Value[0] -
     rtu_PX4Params_ASGSMg_lambda2[0]) * localB->rtb_Sum23_tmp_idx_0_m /
    (rtu_PX4Params_ASGSMg_zeta2[0] * rtu_PX4Params_ASGSMg_lambda2[0])) -
    rtu_q_pos_ddot_hat[0]) - asgsm_quaternion_P.Constant_Value[0]) -
    localB->Sum4[0]) * rtu_PX4Params_MCg_MCData[0];
  if (localB->rtb_Sum23_tmp_idx_0 > asgsm_quaternion_P.Saturation_UpperSat[0]) {
    // MATLAB Function: '<S4>/Kronecker_product'
    localB->rtb_Sum23_tmp_idx_0 = asgsm_quaternion_P.Saturation_UpperSat[0];
  } else if (localB->rtb_Sum23_tmp_idx_0 <
             asgsm_quaternion_P.Saturation_LowerSat[0]) {
    // MATLAB Function: '<S4>/Kronecker_product'
    localB->rtb_Sum23_tmp_idx_0 = asgsm_quaternion_P.Saturation_LowerSat[0];
  }

  localB->rtb_Sum23_tmp_idx_1 = ((((rt_powd_snf(localB->rtb_Sum23_tmp_idx_1,
    rtu_PX4Params_ASGSMg_lambda1[1] - asgsm_quaternion_P.Constant3_Value[1]) *
    (rtu_PX4Params_ASGSMg_lambda1[1] * rtu_PX4Params_ASGSMg_zeta1[1]) +
    asgsm_quaternion_P.Constant5_Value[1]) * (rt_powd_snf
    (localB->rtb_Sum23_tmp_idx_1_l, asgsm_quaternion_P.Constant4_Value[1] -
     rtu_PX4Params_ASGSMg_lambda2[1]) * localB->rtb_Sum23_tmp_idx_1_p /
    (rtu_PX4Params_ASGSMg_zeta2[1] * rtu_PX4Params_ASGSMg_lambda2[1])) -
    rtu_q_pos_ddot_hat[1]) - asgsm_quaternion_P.Constant_Value[1]) -
    localB->Sum4[1]) * rtu_PX4Params_MCg_MCData[0];
  if (localB->rtb_Sum23_tmp_idx_1 > asgsm_quaternion_P.Saturation_UpperSat[1]) {
    // MATLAB Function: '<S4>/Kronecker_product'
    localB->rtb_Sum23_tmp_idx_1 = asgsm_quaternion_P.Saturation_UpperSat[1];
  } else if (localB->rtb_Sum23_tmp_idx_1 <
             asgsm_quaternion_P.Saturation_LowerSat[1]) {
    // MATLAB Function: '<S4>/Kronecker_product'
    localB->rtb_Sum23_tmp_idx_1 = asgsm_quaternion_P.Saturation_LowerSat[1];
  }

  localB->rtb_Sum23_tmp = ((((rt_powd_snf(localB->rtb_Sum23_tmp,
    rtu_PX4Params_ASGSMg_lambda1[2] - asgsm_quaternion_P.Constant3_Value[2]) *
    (rtu_PX4Params_ASGSMg_lambda1[2] * rtu_PX4Params_ASGSMg_zeta1[2]) +
    asgsm_quaternion_P.Constant5_Value[2]) * (rt_powd_snf
    (localB->rtb_Product24_g, asgsm_quaternion_P.Constant4_Value[2] -
     rtu_PX4Params_ASGSMg_lambda2[2]) * localB->rtb_Sum23_tmp_g /
    (rtu_PX4Params_ASGSMg_zeta2[2] * rtu_PX4Params_ASGSMg_lambda2[2])) -
    rtu_q_pos_ddot_hat[2]) - asgsm_quaternion_P.Constant_Value[2]) -
    localB->Sum4[2]) * rtu_PX4Params_MCg_MCData[0];
  if (localB->rtb_Sum23_tmp > asgsm_quaternion_P.Saturation_UpperSat[2]) {
    // MATLAB Function: '<S4>/Kronecker_product'
    localB->rtb_Sum23_tmp = asgsm_quaternion_P.Saturation_UpperSat[2];
  } else if (localB->rtb_Sum23_tmp < asgsm_quaternion_P.Saturation_LowerSat[2])
  {
    // MATLAB Function: '<S4>/Kronecker_product'
    localB->rtb_Sum23_tmp = asgsm_quaternion_P.Saturation_LowerSat[2];
  }

  // End of Saturate: '<Root>/Saturation'

  // MATLAB Function: '<S4>/Kronecker_product'
  for (i = 0; i < 4; i++) {
    localB->r_o[i] = ((localB->rtb_TmpSignalConversionAtSFun_m[i + 4] *
                       localB->rtb_Sum23_tmp_idx_0 +
                       localB->rtb_TmpSignalConversionAtSFun_m[i] * 0.0) +
                      localB->rtb_TmpSignalConversionAtSFun_m[i + 8] *
                      localB->rtb_Sum23_tmp_idx_1) +
      localB->rtb_TmpSignalConversionAtSFun_m[i + 12] * localB->rtb_Sum23_tmp;
  }

  // MATLAB Function: '<S5>/Kronecker_product'
  localB->rtb_TmpSignalConversionAtSFun_m[0] = localB->r_o[0];
  localB->rtb_TmpSignalConversionAtSFun_m[4] = -localB->r_o[1];
  localB->rtb_TmpSignalConversionAtSFun_m[8] = -localB->r_o[2];
  localB->rtb_TmpSignalConversionAtSFun_m[12] = -localB->r_o[3];
  localB->rtb_TmpSignalConversionAtSFun_m[1] = localB->r_o[1];
  localB->rtb_TmpSignalConversionAtSFun_m[5] = localB->r_o[0];
  localB->rtb_TmpSignalConversionAtSFun_m[9] = -localB->r_o[3];
  localB->rtb_TmpSignalConversionAtSFun_m[13] = localB->r_o[2];
  localB->rtb_TmpSignalConversionAtSFun_m[2] = localB->r_o[2];
  localB->rtb_TmpSignalConversionAtSFun_m[6] = localB->r_o[3];
  localB->rtb_TmpSignalConversionAtSFun_m[10] = localB->r_o[0];
  localB->rtb_TmpSignalConversionAtSFun_m[14] = -localB->r_o[1];
  localB->rtb_TmpSignalConversionAtSFun_m[3] = localB->r_o[3];
  localB->rtb_TmpSignalConversionAtSFun_m[7] = -localB->r_o[2];
  localB->rtb_TmpSignalConversionAtSFun_m[11] = localB->r_o[1];
  localB->rtb_TmpSignalConversionAtSFun_m[15] = localB->r_o[0];
  localB->rtb_Sum23_tmp = rtu_q_q_hat[1];
  localB->rtb_Sum23_tmp_g = rtu_q_q_hat[0];
  localB->rtb_Product24_g = rtu_q_q_hat[2];
  localB->rtb_Sum23_tmp_idx_1 = rtu_q_q_hat[3];
  for (i = 0; i < 4; i++) {
    localB->r_o[i] = ((localB->rtb_TmpSignalConversionAtSFun_m[i + 4] *
                       localB->rtb_Sum23_tmp +
                       localB->rtb_TmpSignalConversionAtSFun_m[i] *
                       localB->rtb_Sum23_tmp_g) +
                      localB->rtb_TmpSignalConversionAtSFun_m[i + 8] *
                      localB->rtb_Product24_g) +
      localB->rtb_TmpSignalConversionAtSFun_m[i + 12] *
      localB->rtb_Sum23_tmp_idx_1;
  }

  // End of MATLAB Function: '<S5>/Kronecker_product'

  // Product: '<S2>/Product'
  asgsm_quaternion_rt_invd3x3_snf(localB->J, localB->dv, localB);

  // Sum: '<S1>/Sum' incorporates:
  //   Product: '<S1>/Element Product'

  localB->rtb_Sum23_tmp = localB->Saturation1[2] * rtu_q_pos_dot_hat[4] -
    localB->Saturation1[1] * rtu_q_pos_dot_hat[5];
  localB->rtb_Sum23_tmp_g = localB->Saturation1[0] * rtu_q_pos_dot_hat[5] -
    localB->Saturation1[2] * rtu_q_pos_dot_hat[3];
  localB->rtb_Product24_g = localB->Saturation1[1] * rtu_q_pos_dot_hat[3] -
    localB->Saturation1[0] * rtu_q_pos_dot_hat[4];

  // Sum: '<Root>/Sum23' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Abs: '<Root>/Abs7'
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<Root>/Constant9'
  //   Math: '<Root>/Power6'
  //   Math: '<Root>/Power7'
  //   Product: '<Root>/Divide3'
  //   Product: '<Root>/Matrix Multiply2'
  //   Product: '<Root>/Product20'
  //   Product: '<Root>/Product21'
  //   Product: '<Root>/Product22'
  //   Product: '<Root>/Product23'
  //   Product: '<Root>/Product24'
  //   Signum: '<Root>/Sign7'
  //   Sum: '<Root>/Sum19'
  //   Sum: '<Root>/Sum20'
  //   Sum: '<Root>/Sum21'
  //   Sum: '<Root>/Sum22'

  for (i = 0; i < 3; i++) {
    // Math: '<Root>/Power7' incorporates:
    //   Product: '<Root>/Matrix Multiply2'
    //   Sum: '<Root>/Sum21'

    localB->rtb_Sum23_tmp_idx_1 = rtu_PX4Params_ASGSMg_lambda1[i + 3];

    // Math: '<Root>/Power6' incorporates:
    //   Product: '<Root>/Matrix Multiply2'
    //   Sum: '<Root>/Sum20'

    localB->rtb_Sum23_tmp_idx_1_p = rtu_PX4Params_ASGSMg_lambda2[i + 3];
    localB->Sum23[i] = ((((localB->dv[i + 3] * localB->rtb_Sum23_tmp_g +
      localB->dv[i] * localB->rtb_Sum23_tmp) + localB->dv[i + 6] *
                          localB->rtb_Product24_g) - rtu_q_pos_ddot_hat[i + 3])
                        - localB->Sum4[i + 3]) + (rtu_PX4Params_ASGSMg_zeta1[i +
      3] * localB->rtb_Sum23_tmp_idx_1 * rt_powd_snf(localB->
      rtb_Saturation1_tmp[i], localB->rtb_Sum23_tmp_idx_1 -
      asgsm_quaternion_P.Constant7_Value[i]) +
      asgsm_quaternion_P.Constant9_Value[i]) * (rt_powd_snf
      (localB->rtb_Saturation1_tmp_p[i], asgsm_quaternion_P.Constant8_Value[i] -
       localB->rtb_Sum23_tmp_idx_1_p) * localB->rtb_Saturation1_tmp_b[i] /
      (rtu_PX4Params_ASGSMg_zeta2[i + 3] * localB->rtb_Sum23_tmp_idx_1_p));
  }

  // End of Sum: '<Root>/Sum23'

  // Product: '<Root>/Matrix Multiply5'
  localB->Product3_c = localB->Sum23[1];
  localB->rtb_Sum23_tmp = localB->Sum23[0];
  localB->rtb_Sum23_tmp_g = localB->Sum23[2];
  for (i = 0; i < 3; i++) {
    localB->rtb_Product24_g = (localB->J[i + 3] * localB->Product3_c + localB->
      J[i] * localB->rtb_Sum23_tmp) + localB->J[i + 6] * localB->rtb_Sum23_tmp_g;

    // Saturate: '<Root>/Saturation1'
    localB->rtb_Sum23_tmp_idx_0 = localB->r_o[i + 1];
    localB->rtb_Sum23_tmp_idx_1 = asgsm_quaternion_P.Saturation1_LowerSat[i];
    localB->rtb_Sum23_tmp_idx_1_p = asgsm_quaternion_P.Saturation1_UpperSat[i];
    if (localB->rtb_Sum23_tmp_idx_0 > localB->rtb_Sum23_tmp_idx_1_p) {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i] = localB->rtb_Sum23_tmp_idx_1_p;
    } else if (localB->rtb_Sum23_tmp_idx_0 < localB->rtb_Sum23_tmp_idx_1) {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i] = localB->rtb_Sum23_tmp_idx_1;
    } else {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i] = localB->rtb_Sum23_tmp_idx_0;
    }

    // End of Saturate: '<Root>/Saturation1'

    // Saturate: '<Root>/tau'
    if (localB->rtb_Product24_g > asgsm_quaternion_P.tau_UpperSat) {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i + 3] = asgsm_quaternion_P.tau_UpperSat;
    } else if (localB->rtb_Product24_g < asgsm_quaternion_P.tau_LowerSat) {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i + 3] = asgsm_quaternion_P.tau_LowerSat;
    } else {
      // SignalConversion generated from: '<Root>/u_Outport_1'
      rty_u_Fu[i + 3] = localB->rtb_Product24_g;
    }

    // End of Saturate: '<Root>/tau'
  }

  // End of Product: '<Root>/Matrix Multiply5'

  // Assertion: '<S2>/Assertion' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   Product: '<S11>/Product'
  //   Product: '<S11>/Product1'
  //   Product: '<S11>/Product2'
  //   Product: '<S11>/Product5'
  //   Sum: '<S11>/Sum'

  utAssert(((rtu_PX4Params_MCg_MCData[1] * rtu_PX4Params_MCg_MCData[2] *
             rtu_PX4Params_MCg_MCData[3] - rtu_PX4Params_MCg_MCData[1] * 0.0 *
             0.0) - 0.0 * rtu_PX4Params_MCg_MCData[3]) - 0.0 *
           rtu_PX4Params_MCg_MCData[2] * 0.0 != 0.0);

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  for (i = 0; i < 6; i++) {
    localDW->DiscreteTimeIntegrator_DSTATE[i] = localDW->Memory_PreviousInput[i]
      + localB->rtb_Sum4_tmp[i];
  }
}

// Model initialize function
void asgsm_quaternion_initialize(const char_T **rt_errorStatus,
  RT_MODEL_asgsm_quaternion_T *const asgsm_quaternion_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  asgsm_quaternion_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_asgsm_quaternion_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_asgsm_quaternion_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_asgsm_quaternion_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_asgsm_quaternion_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
