//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: asgsm.cpp
//
// Code generated for Simulink model 'asgsm'.
//
// Model version                  : 4.30
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:37 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "asgsm.h"
#include "rtwtypes.h"
#include "asgsm_private.h"
#include <math.h>
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_powd_snf.h"

P_asgsm_T asgsm_P = {
  // Expression: [0; 0; g; 0; 0; 0]
  //  Referenced by: '<Root>/Gravity Compensation'

  { 0.0, 0.0, 9.81, 0.0, 0.0, 0.0 },

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

// System initialize for referenced model: 'asgsm'
void asgsm_Init(DW_asgsm_f_T *localDW)
{
  for (int32_T i = 0; i < 6; i++) {
    // InitializeConditions for Memory: '<Root>/Memory'
    localDW->Memory_PreviousInput[i] = asgsm_P.Memory_InitialCondition[i];

    // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
    localDW->DiscreteTimeIntegrator_DSTATE[i] =
      asgsm_P.DiscreteTimeIntegrator_IC[i];
  }
}

// Output and update for referenced model: 'asgsm'
void asgsm(const real_T rtu_qd_qd[6], const real_T rtu_qd_qd_dot[6], const
           real_T rtu_qd_qd_ddot[6], const real_T rtu_q_pos_hat[6], const real_T
           rtu_q_pos_dot_hat[6], const real_T rtu_PX4Params_ASGSMg_zeta1[6],
           const real_T rtu_PX4Params_ASGSMg_zeta2[6], const real_T
           rtu_PX4Params_ASGSMg_lambda1[6], const real_T
           rtu_PX4Params_ASGSMg_lambda2[6], const real_T
           rtu_PX4Params_ASGSMg_alpha_u[6], const real_T
           rtu_PX4Params_ASGSMg_beta_u[6], const real_T
           rtu_PX4Params_ASGSMg_epsilon_u[6], const real_T
           rtu_PX4Params_MCg_MCData[5], real_T rty_u_Fu[6], real_T rty_u_e[6],
           real_T rty_u_sigma[6], real_T rty_u_kt[6], B_asgsm_c_T *localB,
           DW_asgsm_f_T *localDW)
{
  int32_T a;
  int32_T c_j;
  int32_T i;
  int32_T jA;
  int32_T jj;
  int32_T kAcol;
  int32_T rtb_e_dot_tmp;
  int8_T ipiv[6];
  int8_T p[6];
  int8_T ipiv_0;

  // MATLAB Function: '<Root>/calculateRbi'
  localB->smax = cos(rtu_q_pos_hat[5]);
  localB->s = sin(rtu_q_pos_hat[3]);
  localB->A_tmp = sin(rtu_q_pos_hat[5]);
  localB->A_tmp_c = cos(rtu_q_pos_hat[3]);
  localB->A_tmp_k = sin(rtu_q_pos_hat[4]);
  localB->A_tmp_cx = cos(rtu_q_pos_hat[4]);
  localB->A_tmp_b = tan(rtu_q_pos_hat[4]);
  localB->e_dot[0] = localB->smax * localB->A_tmp_cx;
  localB->e_dot[6] = localB->smax * localB->s * localB->A_tmp_k +
    -localB->A_tmp_c * localB->A_tmp;
  localB->e_dot[12] = localB->A_tmp_c * localB->smax * localB->A_tmp_k +
    localB->s * localB->A_tmp;
  localB->e_dot[1] = localB->A_tmp_cx * localB->A_tmp;
  localB->e_dot[7] = localB->A_tmp * localB->A_tmp_k * localB->s + cos
    (rtu_q_pos_hat[3]) * cos(rtu_q_pos_hat[5]);
  localB->e_dot[13] = sin(rtu_q_pos_hat[5]) * sin(rtu_q_pos_hat[4]) *
    localB->A_tmp_c + -localB->smax * localB->s;
  localB->e_dot[2] = -localB->A_tmp_k;
  localB->e_dot[8] = localB->A_tmp_cx * localB->s;
  localB->e_dot[14] = localB->A_tmp_cx * localB->A_tmp_c;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_e_dot_tmp = (c_j + 3) * 6;
    localB->e_dot[rtb_e_dot_tmp] = 0.0;
    localB->e_dot[6 * c_j + 3] = 0.0;
    localB->e_dot[rtb_e_dot_tmp + 1] = 0.0;
    localB->e_dot[6 * c_j + 4] = 0.0;
    localB->e_dot[rtb_e_dot_tmp + 2] = 0.0;
    localB->e_dot[6 * c_j + 5] = 0.0;
  }

  localB->e_dot[21] = 1.0;
  localB->e_dot[27] = localB->s * localB->A_tmp_b;
  localB->e_dot[33] = localB->A_tmp_c * localB->A_tmp_b;
  localB->e_dot[22] = 0.0;
  localB->e_dot[28] = localB->A_tmp_c;
  localB->e_dot[34] = -localB->s;
  localB->e_dot[23] = 0.0;
  localB->e_dot[29] = localB->s / localB->A_tmp_cx;
  localB->e_dot[35] = localB->A_tmp_c / localB->A_tmp_cx;
  memset(&localB->Rbi[0], 0, 36U * sizeof(real_T));
  for (c_j = 0; c_j < 6; c_j++) {
    ipiv[c_j] = static_cast<int8_T>(c_j + 1);
  }

  for (c_j = 0; c_j < 5; c_j++) {
    jj = c_j * 7;
    rtb_e_dot_tmp = 5 - c_j;
    a = 0;
    localB->smax = fabs(localB->e_dot[jj]);
    for (i = 2; i <= rtb_e_dot_tmp + 1; i++) {
      localB->s = fabs(localB->e_dot[(jj + i) - 1]);
      if (localB->s > localB->smax) {
        a = i - 1;
        localB->smax = localB->s;
      }
    }

    if (localB->e_dot[jj + a] != 0.0) {
      if (a != 0) {
        a += c_j;
        ipiv[c_j] = static_cast<int8_T>(a + 1);
        for (i = 0; i < 6; i++) {
          jA = i * 6 + c_j;
          localB->smax = localB->e_dot[jA];
          rtb_e_dot_tmp = i * 6 + a;
          localB->e_dot[jA] = localB->e_dot[rtb_e_dot_tmp];
          localB->e_dot[rtb_e_dot_tmp] = localB->smax;
        }
      }

      rtb_e_dot_tmp = (jj - c_j) + 6;
      for (i = jj + 2; i <= rtb_e_dot_tmp; i++) {
        localB->e_dot[i - 1] /= localB->e_dot[jj];
      }
    }

    a = 4 - c_j;
    jA = jj + 8;
    for (i = 0; i <= a; i++) {
      localB->smax = localB->e_dot[(i * 6 + jj) + 6];
      if (localB->smax != 0.0) {
        kAcol = (jA - c_j) + 4;
        for (rtb_e_dot_tmp = jA; rtb_e_dot_tmp <= kAcol; rtb_e_dot_tmp++) {
          localB->e_dot[rtb_e_dot_tmp - 1] += localB->e_dot[((jj + rtb_e_dot_tmp)
            - jA) + 1] * -localB->smax;
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

  for (rtb_e_dot_tmp = 0; rtb_e_dot_tmp < 6; rtb_e_dot_tmp++) {
    a = (p[rtb_e_dot_tmp] - 1) * 6;
    localB->Rbi[rtb_e_dot_tmp + a] = 1.0;
    for (jj = rtb_e_dot_tmp + 1; jj < 7; jj++) {
      c_j = (a + jj) - 1;
      if (localB->Rbi[c_j] != 0.0) {
        for (i = jj + 1; i < 7; i++) {
          jA = (a + i) - 1;
          localB->Rbi[jA] -= localB->e_dot[((jj - 1) * 6 + i) - 1] * localB->
            Rbi[c_j];
        }
      }
    }
  }

  for (i = 0; i < 6; i++) {
    jA = 6 * i;
    for (rtb_e_dot_tmp = 5; rtb_e_dot_tmp >= 0; rtb_e_dot_tmp--) {
      kAcol = 6 * rtb_e_dot_tmp;
      c_j = rtb_e_dot_tmp + jA;
      localB->smax = localB->Rbi[c_j];
      if (localB->smax != 0.0) {
        localB->Rbi[c_j] = localB->smax / localB->e_dot[rtb_e_dot_tmp + kAcol];
        for (jj = 0; jj < rtb_e_dot_tmp; jj++) {
          a = jj + jA;
          localB->Rbi[a] -= localB->e_dot[jj + kAcol] * localB->Rbi[c_j];
        }
      }
    }
  }

  // Product: '<Root>/Matrix Multiply'
  for (c_j = 0; c_j < 6; c_j++) {
    // Product: '<Root>/Matrix Multiply'
    localB->smax = 0.0;
    for (i = 0; i < 6; i++) {
      localB->smax += localB->Rbi[6 * i + c_j] * rtu_q_pos_dot_hat[i];
    }

    // Product: '<Root>/Matrix Multiply'
    localB->MatrixMultiply[c_j] = localB->smax;
  }

  // End of Product: '<Root>/Matrix Multiply'

  // MATLAB Function: '<Root>/constantFunctions' incorporates:
  //   MATLAB Function: '<Root>/calculateRbi'

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
    localB->e_dot[i] = localB->M[i];
    localB->M_inv[i] = 0.0;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    ipiv[c_j] = static_cast<int8_T>(c_j + 1);
  }

  for (c_j = 0; c_j < 5; c_j++) {
    jj = c_j * 7;
    rtb_e_dot_tmp = 5 - c_j;
    a = 0;
    localB->smax = fabs(localB->e_dot[jj]);
    for (i = 2; i <= rtb_e_dot_tmp + 1; i++) {
      localB->s = fabs(localB->e_dot[(jj + i) - 1]);
      if (localB->s > localB->smax) {
        a = i - 1;
        localB->smax = localB->s;
      }
    }

    if (localB->e_dot[jj + a] != 0.0) {
      if (a != 0) {
        a += c_j;
        ipiv[c_j] = static_cast<int8_T>(a + 1);
        for (i = 0; i < 6; i++) {
          jA = i * 6 + c_j;
          localB->smax = localB->e_dot[jA];
          rtb_e_dot_tmp = i * 6 + a;
          localB->e_dot[jA] = localB->e_dot[rtb_e_dot_tmp];
          localB->e_dot[rtb_e_dot_tmp] = localB->smax;
        }
      }

      rtb_e_dot_tmp = (jj - c_j) + 6;
      for (i = jj + 2; i <= rtb_e_dot_tmp; i++) {
        localB->e_dot[i - 1] /= localB->e_dot[jj];
      }
    }

    a = 4 - c_j;
    jA = jj + 8;
    for (i = 0; i <= a; i++) {
      localB->smax = localB->e_dot[(i * 6 + jj) + 6];
      if (localB->smax != 0.0) {
        kAcol = (jA - c_j) + 4;
        for (rtb_e_dot_tmp = jA; rtb_e_dot_tmp <= kAcol; rtb_e_dot_tmp++) {
          localB->e_dot[rtb_e_dot_tmp - 1] += localB->e_dot[((jj + rtb_e_dot_tmp)
            - jA) + 1] * -localB->smax;
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

  for (rtb_e_dot_tmp = 0; rtb_e_dot_tmp < 6; rtb_e_dot_tmp++) {
    a = (p[rtb_e_dot_tmp] - 1) * 6;
    localB->M_inv[rtb_e_dot_tmp + a] = 1.0;
    for (jj = rtb_e_dot_tmp + 1; jj < 7; jj++) {
      c_j = (a + jj) - 1;
      if (localB->M_inv[c_j] != 0.0) {
        for (i = jj + 1; i < 7; i++) {
          jA = (a + i) - 1;
          localB->M_inv[jA] -= localB->e_dot[((jj - 1) * 6 + i) - 1] *
            localB->M_inv[c_j];
        }
      }
    }
  }

  for (i = 0; i < 6; i++) {
    jA = 6 * i;
    for (rtb_e_dot_tmp = 5; rtb_e_dot_tmp >= 0; rtb_e_dot_tmp--) {
      kAcol = 6 * rtb_e_dot_tmp;
      c_j = rtb_e_dot_tmp + jA;
      localB->smax = localB->M_inv[c_j];
      if (localB->smax != 0.0) {
        localB->M_inv[c_j] = localB->smax / localB->e_dot[rtb_e_dot_tmp + kAcol];
        for (jj = 0; jj < rtb_e_dot_tmp; jj++) {
          a = jj + jA;
          localB->M_inv[a] -= localB->e_dot[jj + kAcol] * localB->M_inv[c_j];
        }
      }
    }
  }

  // Math: '<Root>/Transpose' incorporates:
  //   MATLAB Function: '<Root>/constantFunctions'
  //   Product: '<Root>/Matrix Multiply'

  localB->e_dot[0] = 0.0;
  localB->e_dot[1] = -localB->MatrixMultiply[5];
  localB->e_dot[2] = localB->MatrixMultiply[4];
  localB->e_dot[3] = 0.0;
  localB->e_dot[4] = -localB->MatrixMultiply[2];
  localB->e_dot[5] = localB->MatrixMultiply[1];
  localB->e_dot[6] = localB->MatrixMultiply[5];
  localB->e_dot[7] = 0.0;
  localB->e_dot[8] = -localB->MatrixMultiply[3];
  localB->e_dot[9] = localB->MatrixMultiply[2];
  localB->e_dot[10] = 0.0;
  localB->e_dot[11] = -localB->MatrixMultiply[0];
  localB->e_dot[12] = -localB->MatrixMultiply[4];
  localB->e_dot[13] = localB->MatrixMultiply[3];
  localB->e_dot[14] = 0.0;
  localB->e_dot[15] = -localB->MatrixMultiply[1];
  localB->e_dot[16] = localB->MatrixMultiply[0];
  localB->e_dot[17] = 0.0;
  localB->e_dot[18] = 0.0;
  localB->e_dot[19] = 0.0;
  localB->e_dot[20] = 0.0;
  localB->e_dot[21] = 0.0;
  localB->e_dot[22] = -localB->MatrixMultiply[5];
  localB->e_dot[23] = localB->MatrixMultiply[4];
  localB->e_dot[24] = 0.0;
  localB->e_dot[25] = 0.0;
  localB->e_dot[26] = 0.0;
  localB->e_dot[27] = localB->MatrixMultiply[5];
  localB->e_dot[28] = 0.0;
  localB->e_dot[29] = -localB->MatrixMultiply[3];
  localB->e_dot[30] = 0.0;
  localB->e_dot[31] = 0.0;
  localB->e_dot[32] = 0.0;
  localB->e_dot[33] = -localB->MatrixMultiply[4];
  localB->e_dot[34] = localB->MatrixMultiply[3];
  localB->e_dot[35] = 0.0;
  for (i = 0; i < 6; i++) {
    // Sum: '<Root>/Sum19'
    localB->s = rtu_qd_qd_dot[i] - rtu_q_pos_dot_hat[i];

    // Sum: '<Root>/Sum17'
    localB->A_tmp = rtu_qd_qd[i] - rtu_q_pos_hat[i];
    rty_u_e[i] = localB->A_tmp;

    // Abs: '<Root>/Abs1' incorporates:
    //   Abs: '<Root>/Abs6'

    localB->smax = fabs(localB->s);
    localB->dv[i] = localB->smax;

    // Signum: '<Root>/Sign2'
    if (rtIsNaN(localB->s)) {
      // Signum: '<Root>/Sign6'
      localB->s = (rtNaN);
    } else if (localB->s < 0.0) {
      // Signum: '<Root>/Sign6'
      localB->s = -1.0;
    } else {
      // Signum: '<Root>/Sign6'
      localB->s = (localB->s > 0.0);
    }

    localB->dv1[i] = localB->s;

    // Signum: '<Root>/Sign1'
    if (rtIsNaN(localB->A_tmp)) {
      localB->A_tmp_c = (rtNaN);
    } else if (localB->A_tmp < 0.0) {
      localB->A_tmp_c = -1.0;
    } else {
      localB->A_tmp_c = (localB->A_tmp > 0.0);
    }

    // Sum: '<Root>/Sum18' incorporates:
    //   Abs: '<Root>/Abs'
    //   Abs: '<Root>/Abs1'
    //   Math: '<Root>/Power'
    //   Math: '<Root>/Power1'
    //   Product: '<Root>/Product11'
    //   Product: '<Root>/Product12'
    //   Signum: '<Root>/Sign1'
    //   Signum: '<Root>/Sign2'

    localB->A_tmp = (rtu_PX4Params_ASGSMg_zeta1[i] * rt_powd_snf(fabs
      (localB->A_tmp), rtu_PX4Params_ASGSMg_lambda1[i]) * localB->A_tmp_c +
                     localB->A_tmp) + rtu_PX4Params_ASGSMg_zeta2[i] *
      rt_powd_snf(localB->smax, rtu_PX4Params_ASGSMg_lambda2[i]) * localB->s;
    rty_u_sigma[i] = localB->A_tmp;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
    //   Abs: '<Root>/Abs2'
    //   Memory: '<Root>/Memory'
    //   Product: '<Root>/Product16'
    //   Sqrt: '<Root>/Sqrt1'
    //   Sqrt: '<Root>/Sqrt2'
    //   Sum: '<Root>/Sum20'

    localB->smax = (sqrt(rtu_PX4Params_ASGSMg_alpha_u[i]) * sqrt(fabs
      (localB->A_tmp)) - localDW->Memory_PreviousInput[i]) *
      asgsm_P.DiscreteTimeIntegrator_gainval;
    localB->dv2[i] = localB->smax;
    rty_u_kt[i] = localDW->DiscreteTimeIntegrator_DSTATE[i] + localB->smax;

    // Product: '<Root>/Product30' incorporates:
    //   Product: '<Root>/Matrix Multiply'

    localB->smax = 0.0;
    for (c_j = 0; c_j < 6; c_j++) {
      localB->smax += localB->M[6 * c_j + i] * localB->MatrixMultiply[c_j];
    }

    localB->rtb_M_m[i] = localB->smax;
  }

  // Product: '<Root>/Product30'
  for (c_j = 0; c_j < 6; c_j++) {
    localB->smax = 0.0;
    for (i = 0; i < 6; i++) {
      localB->smax += localB->e_dot[6 * i + c_j] * localB->rtb_M_m[i];
    }

    localB->MatrixMultiply[c_j] = localB->smax;
  }

  // Sum: '<Root>/Sum23' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Abs: '<Root>/Abs6'
  //   Abs: '<Root>/Abs7'
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Gravity Compensation'
  //   Gain: '<Root>/Gain'
  //   Gain: '<Root>/Gain3'
  //   Math: '<Root>/Power4'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Divide3'
  //   Product: '<Root>/Product'
  //   Product: '<Root>/Product1'
  //   Product: '<Root>/Product2'
  //   Product: '<Root>/Product30'
  //   Product: '<Root>/Product31'
  //   Product: '<Root>/Product32'
  //   Product: '<Root>/Product33'
  //   Product: '<Root>/Product34'
  //   Signum: '<Root>/Sign4'
  //   Signum: '<Root>/Sign6'
  //   Sqrt: '<Root>/Sqrt4'
  //   Sum: '<Root>/Sum'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<Root>/Sum26'
  //   Sum: '<Root>/Sum28'

  for (c_j = 0; c_j < 6; c_j++) {
    localB->smax = 0.0;
    for (i = 0; i < 6; i++) {
      localB->smax += localB->M_inv[6 * i + c_j] * localB->MatrixMultiply[i];
    }

    // Sum: '<Root>/Sum26' incorporates:
    //   Product: '<Root>/Product30'

    localB->A_tmp_c = rtu_PX4Params_ASGSMg_lambda2[c_j];

    // Product: '<Root>/Product33' incorporates:
    //   Product: '<Root>/Product30'

    localB->A_tmp_k = rtu_PX4Params_ASGSMg_lambda1[c_j];

    // Gain: '<Root>/Gain3' incorporates:
    //   Product: '<Root>/Product30'

    localB->A_tmp_cx = rty_u_kt[c_j];

    // Abs: '<Root>/Abs4' incorporates:
    //   Product: '<Root>/Product30'

    localB->A_tmp = rty_u_sigma[c_j];

    // Signum: '<Root>/Sign4'
    if (rtIsNaN(localB->A_tmp)) {
      localB->s = (rtNaN);
    } else if (localB->A_tmp < 0.0) {
      localB->s = -1.0;
    } else {
      localB->s = (localB->A_tmp > 0.0);
    }

    localB->rtb_M_m[c_j] = ((rt_powd_snf(localB->dv[c_j],
      asgsm_P.Constant2_Value - localB->A_tmp_c) * localB->dv1[c_j] /
      (localB->A_tmp_c * rtu_PX4Params_ASGSMg_zeta2[c_j]) * (localB->A_tmp_k *
      rtu_PX4Params_ASGSMg_zeta1[c_j] * rt_powd_snf(fabs(rty_u_e[c_j]),
      localB->A_tmp_k - asgsm_P.Constant3_Value) + asgsm_P.Constant3_Value) +
      (rtu_qd_qd_ddot[c_j] - localB->smax)) +
      asgsm_P.GravityCompensation_Value[c_j]) - ((0.0 - asgsm_P.Gain3_Gain *
      localB->A_tmp_cx * sqrt(fabs(localB->A_tmp)) * localB->s) -
      asgsm_P.Gain_Gain * localB->A_tmp * localB->A_tmp_cx *
      rtu_PX4Params_ASGSMg_epsilon_u[c_j]);
  }

  // End of Sum: '<Root>/Sum23'
  for (c_j = 0; c_j < 6; c_j++) {
    // Product: '<Root>/Product29'
    localB->smax = 0.0;
    for (i = 0; i < 6; i++) {
      localB->smax += localB->M[6 * i + c_j] * localB->rtb_M_m[i];
    }

    // Saturate: '<Root>/Saturation' incorporates:
    //   Product: '<Root>/Product29'

    localB->s = asgsm_P.Saturation_LowerSat[c_j];
    localB->A_tmp = asgsm_P.Saturation_UpperSat[c_j];
    if (localB->smax > localB->A_tmp) {
      localB->dv[c_j] = localB->A_tmp;
    } else if (localB->smax < localB->s) {
      localB->dv[c_j] = localB->s;
    } else {
      localB->dv[c_j] = localB->smax;
    }

    // End of Saturate: '<Root>/Saturation'
  }

  for (i = 0; i < 6; i++) {
    // Product: '<Root>/Matrix Multiply2'
    localB->smax = 0.0;
    for (c_j = 0; c_j < 6; c_j++) {
      localB->smax += localB->Rbi[6 * c_j + i] * localB->dv[c_j];
    }

    rty_u_Fu[i] = localB->smax;

    // End of Product: '<Root>/Matrix Multiply2'

    // Product: '<Root>/Product3'
    localB->A_tmp_cx = rty_u_kt[i];

    // Update for Memory: '<Root>/Memory' incorporates:
    //   Product: '<Root>/Product17'
    //   Product: '<Root>/Product3'
    //   Sqrt: '<Root>/Sqrt'

    localDW->Memory_PreviousInput[i] = localB->A_tmp_cx * localB->A_tmp_cx *
      sqrt(rtu_PX4Params_ASGSMg_beta_u[i]);

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localDW->DiscreteTimeIntegrator_DSTATE[i] = localB->A_tmp_cx + localB->dv2[i];
  }
}

// Model initialize function
void asgsm_initialize(const char_T **rt_errorStatus, RT_MODEL_asgsm_T *const
                      asgsm_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  asgsm_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_asgsm_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_asgsm_T::setErrorStatusPointer(const char_T** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_asgsm_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_asgsm_T::setErrorStatus(const char_T* const aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
