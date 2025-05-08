//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pdGc.cpp
//
// Code generated for Simulink model 'pdGc'.
//
// Model version                  : 2.128
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:55 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pdGc.h"
#include "rtwtypes.h"
#include "pdGc_private.h"
#include <math.h>
#include <string.h>

P_pdGc_T pdGc_P = {
  // Expression: [5; 5; 40; 0.75; 0.75; 0.75]
  //  Referenced by: '<Root>/Saturation1'

  { 5.0, 5.0, 40.0, 0.75, 0.75, 0.75 },

  // Expression: [-5; -5; 0; -0.75; -0.75; -0.75]
  //  Referenced by: '<Root>/Saturation1'

  { -5.0, -5.0, 0.0, -0.75, -0.75, -0.75 },

  // Expression: [5; 5; 40; 0.75; 0.75; 0.75]
  //  Referenced by: '<Root>/Saturation2'

  { 5.0, 5.0, 40.0, 0.75, 0.75, 0.75 },

  // Expression: [-5; -5; 0; -0.75; -0.75; -0.75]
  //  Referenced by: '<Root>/Saturation2'

  { -5.0, -5.0, 0.0, -0.75, -0.75, -0.75 },

  // Expression: -1
  //  Referenced by: '<Root>/Gain4'

  -1.0,

  // Expression: [0;0;-9.81;0;0;0]
  //  Referenced by: '<Root>/Gravity Comp'

  { 0.0, 0.0, -9.81, 0.0, 0.0, 0.0 },

  // Expression: -1
  //  Referenced by: '<Root>/Gain3'

  -1.0,

  // Expression: zeros(6, 1)
  //  Referenced by: '<Root>/Constant2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  1U
};

// Output and update for referenced model: 'pdGc'
void pdGc(const real_T rtu_qd_qd[6], const real_T rtu_qd_qd_dot[6], const real_T
          rtu_q_pos_hat[6], const real_T rtu_q_pos_dot_hat[6], const real_T
          rtu_PX4Params_PDg_posGains[9], const real_T
          rtu_PX4Params_PDg_attGains[9], const real_T rtu_PX4Params_MCg_MCData[5],
          real_T rty_u_Fu[6], real_T rty_u_e[6], real_T rty_u_e_dot[6], real_T
          rty_u_sigma[6], real_T rty_u_kt[6], B_pdGc_c_T *localB)
{
  real_T rtb_Rib_tmp;
  real_T x_tmp;
  int32_T a;
  int32_T i;
  int32_T jA;
  int32_T jj;
  int32_T kAcol;
  int32_T n;
  int32_T p2;
  int8_T ipiv[6];
  int8_T p[6];

  // MATLAB Function: '<Root>/getMassMatrix'
  localB->M[0] = rtu_PX4Params_MCg_MCData[0];
  localB->M[6] = 0.0;
  localB->M[12] = 0.0;
  localB->M[18] = 0.0;
  localB->M[24] = 0.0;
  localB->M[30] = 0.0;
  localB->M[1] = 0.0;
  localB->M[7] = rtu_PX4Params_MCg_MCData[0];
  localB->M[13] = 0.0;
  localB->M[19] = 0.0;
  localB->M[25] = 0.0;
  localB->M[31] = 0.0;
  localB->M[2] = 0.0;
  localB->M[8] = 0.0;
  localB->M[14] = rtu_PX4Params_MCg_MCData[0];
  localB->M[20] = 0.0;
  localB->M[26] = 0.0;
  localB->M[32] = 0.0;
  localB->M[3] = 0.0;
  localB->M[9] = 0.0;
  localB->M[15] = 0.0;
  localB->M[21] = rtu_PX4Params_MCg_MCData[1];
  localB->M[27] = 0.0;
  localB->M[33] = 0.0;
  localB->M[4] = 0.0;
  localB->M[10] = 0.0;
  localB->M[16] = 0.0;
  localB->M[22] = 0.0;
  localB->M[28] = rtu_PX4Params_MCg_MCData[2];
  localB->M[34] = 0.0;
  localB->M[5] = 0.0;
  localB->M[11] = 0.0;
  localB->M[17] = 0.0;
  localB->M[23] = 0.0;
  localB->M[29] = 0.0;
  localB->M[35] = rtu_PX4Params_MCg_MCData[3];
  for (i = 0; i < 36; i++) {
    localB->Rib[i] = localB->M[i];
    localB->M_inv[i] = 0.0;
  }

  for (p2 = 0; p2 < 6; p2++) {
    ipiv[p2] = static_cast<int8_T>(p2 + 1);
  }

  for (p2 = 0; p2 < 5; p2++) {
    jj = p2 * 7;
    n = 7 - p2;
    a = 0;
    localB->smax = fabs(localB->Rib[jj]);
    for (i = 2; i < n; i++) {
      localB->s = fabs(localB->Rib[(jj + i) - 1]);
      if (localB->s > localB->smax) {
        a = i - 1;
        localB->smax = localB->s;
      }
    }

    if (localB->Rib[jj + a] != 0.0) {
      if (a != 0) {
        a += p2;
        ipiv[p2] = static_cast<int8_T>(a + 1);
        for (i = 0; i < 6; i++) {
          jA = i * 6 + p2;
          localB->smax = localB->Rib[jA];
          n = i * 6 + a;
          localB->Rib[jA] = localB->Rib[n];
          localB->Rib[n] = localB->smax;
        }
      }

      n = (jj - p2) + 6;
      for (i = jj + 2; i <= n; i++) {
        localB->Rib[i - 1] /= localB->Rib[jj];
      }
    }

    a = 4 - p2;
    jA = jj + 8;
    for (i = 0; i <= a; i++) {
      localB->smax = localB->Rib[(i * 6 + jj) + 6];
      if (localB->smax != 0.0) {
        kAcol = (jA - p2) + 4;
        for (n = jA; n <= kAcol; n++) {
          localB->Rib[n - 1] += localB->Rib[((jj + n) - jA) + 1] * -localB->smax;
        }
      }

      jA += 6;
    }
  }

  for (p2 = 0; p2 < 6; p2++) {
    p[p2] = static_cast<int8_T>(p2 + 1);
  }

  for (p2 = 0; p2 < 5; p2++) {
    int8_T ipiv_0;
    ipiv_0 = ipiv[p2];
    if (ipiv_0 > p2 + 1) {
      i = p[ipiv_0 - 1];
      p[ipiv_0 - 1] = p[p2];
      p[p2] = static_cast<int8_T>(i);
    }
  }

  for (n = 0; n < 6; n++) {
    a = (p[n] - 1) * 6;
    localB->M_inv[n + a] = 1.0;
    for (jj = n + 1; jj < 7; jj++) {
      p2 = (a + jj) - 1;
      if (localB->M_inv[p2] != 0.0) {
        for (i = jj + 1; i < 7; i++) {
          jA = (a + i) - 1;
          localB->M_inv[jA] -= localB->Rib[((jj - 1) * 6 + i) - 1] *
            localB->M_inv[p2];
        }
      }
    }
  }

  for (i = 0; i < 6; i++) {
    jA = 6 * i;
    for (n = 5; n >= 0; n--) {
      kAcol = 6 * n;
      p2 = n + jA;
      localB->smax = localB->M_inv[p2];
      if (localB->smax != 0.0) {
        localB->M_inv[p2] = localB->smax / localB->Rib[n + kAcol];
        for (jj = 0; jj < n; jj++) {
          a = jj + jA;
          localB->M_inv[a] -= localB->Rib[jj + kAcol] * localB->M_inv[p2];
        }
      }
    }
  }

  // End of MATLAB Function: '<Root>/getMassMatrix'

  // MATLAB Function: '<Root>/calculateRotationMatrix'
  localB->t1 = tan(rtu_q_pos_hat[4]);
  localB->smax = sin(rtu_q_pos_hat[3]);
  localB->s = cos(rtu_q_pos_hat[3]);
  x_tmp = cos(rtu_q_pos_hat[4]);
  localB->x[0] = 1.0;
  localB->x[3] = localB->smax * localB->t1;
  localB->x[6] = localB->s * localB->t1;
  localB->x[1] = 0.0;
  localB->x[4] = localB->s;
  localB->x[7] = -localB->smax;
  localB->x[2] = 0.0;
  localB->x[5] = localB->smax / x_tmp;
  localB->x[8] = localB->s / x_tmp;
  memcpy(&localB->b_x[0], &localB->x[0], 9U * sizeof(real_T));
  p2 = 3;
  i = 6;
  localB->b_x[1] /= localB->b_x[0];
  localB->b_x[2] /= localB->b_x[0];
  localB->b_x[4] -= localB->b_x[1] * localB->b_x[3];
  localB->b_x[5] -= localB->b_x[2] * localB->b_x[3];
  localB->b_x[7] -= localB->b_x[1] * localB->b_x[6];
  localB->b_x[8] -= localB->b_x[2] * localB->b_x[6];
  if (fabs(localB->b_x[5]) > fabs(localB->b_x[4])) {
    p2 = 6;
    i = 3;
    localB->t1 = localB->b_x[1];
    localB->b_x[1] = localB->b_x[2];
    localB->b_x[2] = localB->t1;
    localB->t1 = localB->b_x[4];
    localB->b_x[4] = localB->b_x[5];
    localB->b_x[5] = localB->t1;
    localB->t1 = localB->b_x[7];
    localB->b_x[7] = localB->b_x[8];
    localB->b_x[8] = localB->t1;
  }

  localB->b_x[5] /= localB->b_x[4];
  localB->b_x[8] -= localB->b_x[5] * localB->b_x[7];
  localB->t1 = (localB->b_x[1] * localB->b_x[5] - localB->b_x[2]) / localB->b_x
    [8];
  localB->t2 = -(localB->b_x[7] * localB->t1 + localB->b_x[1]) / localB->b_x[4];
  localB->x[0] = ((1.0 - localB->b_x[3] * localB->t2) - localB->b_x[6] *
                  localB->t1) / localB->b_x[0];
  localB->x[1] = localB->t2;
  localB->x[2] = localB->t1;
  localB->t1 = -localB->b_x[5] / localB->b_x[8];
  localB->t2 = (1.0 - localB->b_x[7] * localB->t1) / localB->b_x[4];
  localB->x[p2] = -(localB->b_x[3] * localB->t2 + localB->b_x[6] * localB->t1) /
    localB->b_x[0];
  localB->x[p2 + 1] = localB->t2;
  localB->x[p2 + 2] = localB->t1;
  localB->t1 = 1.0 / localB->b_x[8];
  localB->t2 = -localB->b_x[7] * localB->t1 / localB->b_x[4];
  localB->x[i] = -(localB->b_x[3] * localB->t2 + localB->b_x[6] * localB->t1) /
    localB->b_x[0];
  localB->x[i + 1] = localB->t2;
  localB->x[i + 2] = localB->t1;
  localB->t1 = cos(rtu_q_pos_hat[5]);
  localB->t2 = sin(rtu_q_pos_hat[5]);
  rtb_Rib_tmp = sin(rtu_q_pos_hat[4]);
  localB->Rib[0] = localB->t1 * x_tmp;
  localB->Rib[1] = localB->t1 * localB->smax * rtb_Rib_tmp + -localB->s *
    localB->t2;
  localB->Rib[2] = localB->s * localB->t1 * rtb_Rib_tmp + localB->smax *
    localB->t2;
  localB->Rib[6] = x_tmp * localB->t2;
  localB->Rib[7] = localB->t2 * rtb_Rib_tmp * localB->smax + cos(rtu_q_pos_hat[3])
    * cos(rtu_q_pos_hat[5]);
  localB->Rib[8] = sin(rtu_q_pos_hat[5]) * sin(rtu_q_pos_hat[4]) * localB->s +
    -localB->t1 * localB->smax;
  localB->Rib[12] = -rtb_Rib_tmp;
  localB->Rib[13] = x_tmp * localB->smax;
  localB->Rib[14] = x_tmp * localB->s;
  for (p2 = 0; p2 < 3; p2++) {
    n = (p2 + 3) * 6;
    localB->Rib[n] = 0.0;
    localB->Rib[6 * p2 + 3] = 0.0;
    localB->Rib[n + 3] = localB->x[3 * p2];
    localB->Rib[n + 1] = 0.0;
    localB->Rib[6 * p2 + 4] = 0.0;
    localB->Rib[n + 4] = localB->x[3 * p2 + 1];
    localB->Rib[n + 2] = 0.0;
    localB->Rib[6 * p2 + 5] = 0.0;
    localB->Rib[n + 5] = localB->x[3 * p2 + 2];
  }

  // End of MATLAB Function: '<Root>/calculateRotationMatrix'
  for (i = 0; i < 6; i++) {
    // Product: '<Root>/Matrix Multiply'
    localB->smax = 0.0;
    for (p2 = 0; p2 < 6; p2++) {
      localB->smax += localB->Rib[6 * p2 + i] * rtu_q_pos_dot_hat[p2];
    }

    localB->v[i] = localB->smax;

    // End of Product: '<Root>/Matrix Multiply'

    // Sum: '<Root>/Add'
    rty_u_e[i] = rtu_qd_qd[i] - rtu_q_pos_hat[i];
  }

  // ManualSwitch: '<Root>/Manual Switch'
  if (pdGc_P.ManualSwitch_CurrentSetting == 1) {
    // Product: '<Root>/Product4'
    localB->rtu_PX4Params_PDg_posGains[0] = rtu_PX4Params_PDg_posGains[0];
    localB->rtu_PX4Params_PDg_posGains[1] = rtu_PX4Params_PDg_posGains[3];
    localB->rtu_PX4Params_PDg_posGains[2] = rtu_PX4Params_PDg_posGains[6];
    localB->rtu_PX4Params_PDg_posGains[3] = rtu_PX4Params_PDg_attGains[0];
    localB->rtu_PX4Params_PDg_posGains[4] = rtu_PX4Params_PDg_attGains[3];
    localB->rtu_PX4Params_PDg_posGains[5] = rtu_PX4Params_PDg_attGains[6];

    // Product: '<Root>/Product5'
    localB->rtu_PX4Params_PDg_posGains_m[0] = rtu_PX4Params_PDg_posGains[2];
    localB->rtu_PX4Params_PDg_posGains_m[1] = rtu_PX4Params_PDg_posGains[5];
    localB->rtu_PX4Params_PDg_posGains_m[2] = rtu_PX4Params_PDg_posGains[8];
    localB->rtu_PX4Params_PDg_posGains_m[3] = rtu_PX4Params_PDg_attGains[2];
    localB->rtu_PX4Params_PDg_posGains_m[4] = rtu_PX4Params_PDg_attGains[5];
    localB->rtu_PX4Params_PDg_posGains_m[5] = rtu_PX4Params_PDg_attGains[8];

    // MATLAB Function: '<Root>/getPhiMatrix' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    localB->dv[0] = 0.0;
    localB->dv[1] = -localB->v[5];
    localB->dv[2] = localB->v[4];
    localB->dv[3] = 0.0;
    localB->dv[4] = -localB->v[2];
    localB->dv[5] = localB->v[1];
    localB->dv[6] = localB->v[5];
    localB->dv[7] = 0.0;
    localB->dv[8] = -localB->v[3];
    localB->dv[9] = localB->v[2];
    localB->dv[10] = 0.0;
    localB->dv[11] = -localB->v[0];
    localB->dv[12] = -localB->v[4];
    localB->dv[13] = localB->v[3];
    localB->dv[14] = 0.0;
    localB->dv[15] = -localB->v[1];
    localB->dv[16] = localB->v[0];
    localB->dv[17] = 0.0;
    localB->dv[18] = 0.0;
    localB->dv[19] = 0.0;
    localB->dv[20] = 0.0;
    localB->dv[21] = 0.0;
    localB->dv[22] = -localB->v[5];
    localB->dv[23] = localB->v[4];
    localB->dv[24] = 0.0;
    localB->dv[25] = 0.0;
    localB->dv[26] = 0.0;
    localB->dv[27] = localB->v[5];
    localB->dv[28] = 0.0;
    localB->dv[29] = -localB->v[3];
    localB->dv[30] = 0.0;
    localB->dv[31] = 0.0;
    localB->dv[32] = 0.0;
    localB->dv[33] = -localB->v[4];
    localB->dv[34] = localB->v[3];
    localB->dv[35] = 0.0;

    // Product: '<Root>/Product6' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    for (p2 = 0; p2 < 6; p2++) {
      x_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        x_tmp += localB->M[6 * i + p2] * localB->v[i];
      }

      localB->rtb_M_c[p2] = x_tmp;
    }

    for (p2 = 0; p2 < 6; p2++) {
      localB->smax = 0.0;
      for (i = 0; i < 6; i++) {
        localB->smax += localB->dv[6 * i + p2] * localB->rtb_M_c[i];
      }

      localB->v[p2] = localB->smax;
    }

    for (p2 = 0; p2 < 6; p2++) {
      localB->smax = 0.0;
      for (i = 0; i < 6; i++) {
        localB->smax += localB->M_inv[6 * i + p2] * localB->v[i];
      }

      // Sum: '<Root>/Sum1' incorporates:
      //   Constant: '<Root>/Gravity Comp'
      //   Gain: '<Root>/Gain3'
      //   Gain: '<Root>/Gain4'
      //   Product: '<Root>/Product4'
      //   Product: '<Root>/Product5'
      //   Sum: '<Root>/Add4'
      //   Sum: '<Root>/Sum'
      //   Sum: '<Root>/Sum2'

      localB->dv1[p2] = (((rtu_qd_qd_dot[p2] - rtu_q_pos_dot_hat[p2]) *
                          localB->rtu_PX4Params_PDg_posGains_m[p2] +
                          localB->rtu_PX4Params_PDg_posGains[p2] * rty_u_e[p2])
                         + pdGc_P.Gain3_Gain * pdGc_P.GravityComp_Value[p2]) -
        pdGc_P.Gain4_Gain * localB->smax;
    }

    // Product: '<Root>/Product3'
    for (p2 = 0; p2 < 6; p2++) {
      x_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        x_tmp += localB->M[6 * i + p2] * localB->dv1[i];
      }

      // Saturate: '<Root>/Saturation1'
      localB->smax = pdGc_P.Saturation1_LowerSat[p2];
      localB->s = pdGc_P.Saturation1_UpperSat[p2];
      if (x_tmp > localB->s) {
        rty_u_Fu[p2] = localB->s;
      } else if (x_tmp < localB->smax) {
        rty_u_Fu[p2] = localB->smax;
      } else {
        rty_u_Fu[p2] = x_tmp;
      }

      // End of Saturate: '<Root>/Saturation1'
    }
  } else {
    // Product: '<Root>/Product4'
    localB->rtu_PX4Params_PDg_posGains[0] = rtu_PX4Params_PDg_posGains[0];
    localB->rtu_PX4Params_PDg_posGains[1] = rtu_PX4Params_PDg_posGains[3];
    localB->rtu_PX4Params_PDg_posGains[2] = rtu_PX4Params_PDg_posGains[6];
    localB->rtu_PX4Params_PDg_posGains[3] = rtu_PX4Params_PDg_attGains[0];
    localB->rtu_PX4Params_PDg_posGains[4] = rtu_PX4Params_PDg_attGains[3];
    localB->rtu_PX4Params_PDg_posGains[5] = rtu_PX4Params_PDg_attGains[6];

    // Product: '<Root>/Product5'
    localB->rtu_PX4Params_PDg_posGains_m[0] = rtu_PX4Params_PDg_posGains[2];
    localB->rtu_PX4Params_PDg_posGains_m[1] = rtu_PX4Params_PDg_posGains[5];
    localB->rtu_PX4Params_PDg_posGains_m[2] = rtu_PX4Params_PDg_posGains[8];
    localB->rtu_PX4Params_PDg_posGains_m[3] = rtu_PX4Params_PDg_attGains[2];
    localB->rtu_PX4Params_PDg_posGains_m[4] = rtu_PX4Params_PDg_attGains[5];
    localB->rtu_PX4Params_PDg_posGains_m[5] = rtu_PX4Params_PDg_attGains[8];

    // MATLAB Function: '<Root>/getPhiMatrix' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    localB->dv[0] = 0.0;
    localB->dv[1] = -localB->v[5];
    localB->dv[2] = localB->v[4];
    localB->dv[3] = 0.0;
    localB->dv[4] = -localB->v[2];
    localB->dv[5] = localB->v[1];
    localB->dv[6] = localB->v[5];
    localB->dv[7] = 0.0;
    localB->dv[8] = -localB->v[3];
    localB->dv[9] = localB->v[2];
    localB->dv[10] = 0.0;
    localB->dv[11] = -localB->v[0];
    localB->dv[12] = -localB->v[4];
    localB->dv[13] = localB->v[3];
    localB->dv[14] = 0.0;
    localB->dv[15] = -localB->v[1];
    localB->dv[16] = localB->v[0];
    localB->dv[17] = 0.0;
    localB->dv[18] = 0.0;
    localB->dv[19] = 0.0;
    localB->dv[20] = 0.0;
    localB->dv[21] = 0.0;
    localB->dv[22] = -localB->v[5];
    localB->dv[23] = localB->v[4];
    localB->dv[24] = 0.0;
    localB->dv[25] = 0.0;
    localB->dv[26] = 0.0;
    localB->dv[27] = localB->v[5];
    localB->dv[28] = 0.0;
    localB->dv[29] = -localB->v[3];
    localB->dv[30] = 0.0;
    localB->dv[31] = 0.0;
    localB->dv[32] = 0.0;
    localB->dv[33] = -localB->v[4];
    localB->dv[34] = localB->v[3];
    localB->dv[35] = 0.0;

    // Product: '<Root>/Product6' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    for (p2 = 0; p2 < 6; p2++) {
      x_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        x_tmp += localB->M[6 * i + p2] * localB->v[i];
      }

      localB->rtb_M_c[p2] = x_tmp;
    }

    for (p2 = 0; p2 < 6; p2++) {
      localB->smax = 0.0;
      for (i = 0; i < 6; i++) {
        localB->smax += localB->dv[6 * i + p2] * localB->rtb_M_c[i];
      }

      localB->v[p2] = localB->smax;
    }

    for (p2 = 0; p2 < 6; p2++) {
      localB->smax = 0.0;
      for (i = 0; i < 6; i++) {
        localB->smax += localB->M_inv[6 * i + p2] * localB->v[i];
      }

      // Sum: '<Root>/Sum1' incorporates:
      //   Constant: '<Root>/Gravity Comp'
      //   Gain: '<Root>/Gain3'
      //   Gain: '<Root>/Gain4'
      //   Product: '<Root>/Product4'
      //   Product: '<Root>/Product5'
      //   Sum: '<Root>/Add4'
      //   Sum: '<Root>/Sum'
      //   Sum: '<Root>/Sum2'

      localB->dv1[p2] = (((rtu_qd_qd_dot[p2] - rtu_q_pos_dot_hat[p2]) *
                          localB->rtu_PX4Params_PDg_posGains_m[p2] +
                          localB->rtu_PX4Params_PDg_posGains[p2] * rty_u_e[p2])
                         + pdGc_P.Gain3_Gain * pdGc_P.GravityComp_Value[p2]) -
        pdGc_P.Gain4_Gain * localB->smax;
    }

    // Product: '<Root>/Product3'
    for (p2 = 0; p2 < 6; p2++) {
      x_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        x_tmp += localB->M[6 * i + p2] * localB->dv1[i];
      }

      localB->rtb_M_c[p2] = x_tmp;
    }

    // Product: '<Root>/Matrix Multiply2'
    for (p2 = 0; p2 < 6; p2++) {
      x_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        x_tmp += localB->Rib[6 * i + p2] * localB->rtb_M_c[i];
      }

      // Saturate: '<Root>/Saturation2'
      localB->smax = pdGc_P.Saturation2_LowerSat[p2];
      localB->s = pdGc_P.Saturation2_UpperSat[p2];
      if (x_tmp > localB->s) {
        rty_u_Fu[p2] = localB->s;
      } else if (x_tmp < localB->smax) {
        rty_u_Fu[p2] = localB->smax;
      } else {
        rty_u_Fu[p2] = x_tmp;
      }

      // End of Saturate: '<Root>/Saturation2'
    }

    // End of Product: '<Root>/Matrix Multiply2'
  }

  // End of ManualSwitch: '<Root>/Manual Switch'
  for (i = 0; i < 6; i++) {
    // Constant: '<Root>/Constant2'
    localB->smax = pdGc_P.Constant2_Value[i];
    rty_u_kt[i] = localB->smax;

    // SignalConversion generated from: '<Root>/u_Outport_1'
    rty_u_e_dot[i] = localB->smax;

    // SignalConversion generated from: '<Root>/u_Outport_1'
    rty_u_sigma[i] = localB->smax;
  }
}

// Model initialize function
void pdGc_initialize(const char_T **rt_errorStatus, RT_MODEL_pdGc_T *const
                     pdGc_M)
{
  // Registration code

  // initialize error status
  pdGc_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_pdGc_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_pdGc_T::setErrorStatusPointer(const char_T** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_pdGc_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_pdGc_T::setErrorStatus(const char_T* const aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
