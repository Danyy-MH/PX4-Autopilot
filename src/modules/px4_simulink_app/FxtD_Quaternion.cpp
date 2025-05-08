//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FxtD_Quaternion.cpp
//
// Code generated for Simulink model 'FxtD_Quaternion'.
//
// Model version                  : 1.17
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:32 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FxtD_Quaternion.h"
#include "rtwtypes.h"
#include "FxtD_Quaternion_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_powd_snf.h"
#include "xdotc_kGz03SeF.h"
#include "xaxpy_hLW3vASe.h"
#include "xaxpy_8Bk0aMTr.h"
#include "xaxpy_l5uLg2P0.h"
#include "xswap_nAn5Zpao.h"

P_FxtD_Quaternion_T FxtD_Quaternion_P = {
  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<Root>/Memory3'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<Root>/Gain'

  2.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant1'

  1.0,

  // Expression: 2
  //  Referenced by: '<Root>/Gain2'

  2.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant3'

  1.0,

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Memory4'

  { 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Memory1'

  { 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Memory2'

  { 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Constant4'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.5
  //  Referenced by: '<Root>/Gain4'

  0.5,

  // Expression: 0
  //  Referenced by: '<Root>/Constant8'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator4_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator4'

  0.002,

  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator4'

  { 1.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator1'

  0.002,

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator1'

  { 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator3_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator3'

  0.002,

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator3'

  { 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator2_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator2'

  0.002,

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator2'

  { 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<Root>/Constant5'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
};

// Forward declaration for local functions
static real_T FxtD_Quaterni_xzlangeM_CmZ8yEA8(const real_T x[9],
  B_FxtD_Quaternion_c_T *localB);
static void FxtD_Quaternio_xzlascl_G6oWZyOe(real_T cfrom, real_T cto, real_T A[9],
  B_FxtD_Quaternion_c_T *localB);
static real_T FxtD_Quaternion_xnrm2_lYZMmlSm(int32_T n, const real_T x[9],
  int32_T ix0, B_FxtD_Quaternion_c_T *localB);
static real_T FxtD_Quaternion_xnrm2_pXv7PuuY(const real_T x[3], int32_T ix0,
  B_FxtD_Quaternion_c_T *localB);
static void FxtD_Quaternio_xzlascl_ftGcEjOL(real_T cfrom, real_T cto, real_T A[3],
  B_FxtD_Quaternion_c_T *localB);
static void FxtD_Quaternion_xrotg_QLPrMQ5c(real_T *a, real_T *b, real_T *c,
  real_T *s, B_FxtD_Quaternion_c_T *localB);
static void FxtD_Quaternion_xrot_PLEUrKWS(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s, B_FxtD_Quaternion_c_T *localB);
static void FxtD_Quaternion_svd_60uAVgXi(const real_T A[9], real_T U[9], real_T
  s[3], real_T V[9], B_FxtD_Quaternion_c_T *localB);

// Function for MATLAB Function: '<Root>/calculateCvMatrix'
static real_T FxtD_Quaterni_xzlangeM_CmZ8yEA8(const real_T x[9],
  B_FxtD_Quaternion_c_T *localB)
{
  real_T y;
  int32_T k;
  boolean_T exitg1;
  y = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    localB->absxk_m = fabs(x[k]);
    if (rtIsNaN(localB->absxk_m)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (localB->absxk_m > y) {
        y = localB->absxk_m;
      }

      k++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix'
static void FxtD_Quaternio_xzlascl_G6oWZyOe(real_T cfrom, real_T cto, real_T A[9],
  B_FxtD_Quaternion_c_T *localB)
{
  boolean_T notdone;
  localB->cfromc = cfrom;
  localB->ctoc = cto;
  notdone = true;
  while (notdone) {
    localB->cfrom1 = localB->cfromc * 2.0041683600089728E-292;
    localB->cto1 = localB->ctoc / 4.9896007738368E+291;
    if ((fabs(localB->cfrom1) > fabs(localB->ctoc)) && (localB->ctoc != 0.0)) {
      localB->mul = 2.0041683600089728E-292;
      localB->cfromc = localB->cfrom1;
    } else if (fabs(localB->cto1) > fabs(localB->cfromc)) {
      localB->mul = 4.9896007738368E+291;
      localB->ctoc = localB->cto1;
    } else {
      localB->mul = localB->ctoc / localB->cfromc;
      notdone = false;
    }

    for (int32_T j = 0; j < 3; j++) {
      int32_T offset;
      offset = j * 3;
      A[offset] *= localB->mul;
      A[offset + 1] *= localB->mul;
      A[offset + 2] *= localB->mul;
    }
  }
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix'
static real_T FxtD_Quaternion_xnrm2_lYZMmlSm(int32_T n, const real_T x[9],
  int32_T ix0, B_FxtD_Quaternion_c_T *localB)
{
  real_T y;
  int32_T kend;
  y = 0.0;
  localB->scale_c = 3.3121686421112381E-170;
  kend = ix0 + n;
  for (int32_T k = ix0; k < kend; k++) {
    localB->absxk = fabs(x[k - 1]);
    if (localB->absxk > localB->scale_c) {
      localB->t = localB->scale_c / localB->absxk;
      y = y * localB->t * localB->t + 1.0;
      localB->scale_c = localB->absxk;
    } else {
      localB->t = localB->absxk / localB->scale_c;
      y += localB->t * localB->t;
    }
  }

  return localB->scale_c * sqrt(y);
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix'
static real_T FxtD_Quaternion_xnrm2_pXv7PuuY(const real_T x[3], int32_T ix0,
  B_FxtD_Quaternion_c_T *localB)
{
  real_T y;
  y = 0.0;
  localB->scale_f = 3.3121686421112381E-170;
  for (int32_T k = ix0; k <= ix0 + 1; k++) {
    localB->absxk_g = fabs(x[k - 1]);
    if (localB->absxk_g > localB->scale_f) {
      localB->t_g = localB->scale_f / localB->absxk_g;
      y = y * localB->t_g * localB->t_g + 1.0;
      localB->scale_f = localB->absxk_g;
    } else {
      localB->t_g = localB->absxk_g / localB->scale_f;
      y += localB->t_g * localB->t_g;
    }
  }

  return localB->scale_f * sqrt(y);
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix'
static void FxtD_Quaternio_xzlascl_ftGcEjOL(real_T cfrom, real_T cto, real_T A[3],
  B_FxtD_Quaternion_c_T *localB)
{
  boolean_T notdone;
  localB->cfromc_k = cfrom;
  localB->ctoc_c = cto;
  notdone = true;
  while (notdone) {
    real_T mul;
    localB->cfrom1_b = localB->cfromc_k * 2.0041683600089728E-292;
    localB->cto1_p = localB->ctoc_c / 4.9896007738368E+291;
    if ((fabs(localB->cfrom1_b) > fabs(localB->ctoc_c)) && (localB->ctoc_c !=
         0.0)) {
      mul = 2.0041683600089728E-292;
      localB->cfromc_k = localB->cfrom1_b;
    } else if (fabs(localB->cto1_p) > fabs(localB->cfromc_k)) {
      mul = 4.9896007738368E+291;
      localB->ctoc_c = localB->cto1_p;
    } else {
      mul = localB->ctoc_c / localB->cfromc_k;
      notdone = false;
    }

    A[0] *= mul;
    A[1] *= mul;
    A[2] *= mul;
  }
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix'
static void FxtD_Quaternion_xrotg_QLPrMQ5c(real_T *a, real_T *b, real_T *c,
  real_T *s, B_FxtD_Quaternion_c_T *localB)
{
  localB->roe = *b;
  localB->absa = fabs(*a);
  localB->absb = fabs(*b);
  if (localB->absa > localB->absb) {
    localB->roe = *a;
  }

  localB->scale = localB->absa + localB->absb;
  if (localB->scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T bds;
    localB->ads = localB->absa / localB->scale;
    bds = localB->absb / localB->scale;
    localB->scale *= sqrt(localB->ads * localB->ads + bds * bds);
    if (localB->roe < 0.0) {
      localB->scale = -localB->scale;
    }

    *c = *a / localB->scale;
    *s = *b / localB->scale;
    if (localB->absa > localB->absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = localB->scale;
  }
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix'
static void FxtD_Quaternion_xrot_PLEUrKWS(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s, B_FxtD_Quaternion_c_T *localB)
{
  real_T temp_tmp;
  localB->temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = localB->temp * c - temp_tmp * s;
  x[ix0 - 1] = temp_tmp * c + localB->temp * s;
  localB->temp = x[ix0] * c + x[iy0] * s;
  x[iy0] = x[iy0] * c - x[ix0] * s;
  x[ix0] = localB->temp;
  localB->temp = x[iy0 + 1];
  temp_tmp = x[ix0 + 1];
  x[iy0 + 1] = localB->temp * c - temp_tmp * s;
  x[ix0 + 1] = temp_tmp * c + localB->temp * s;
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix'
static void FxtD_Quaternion_svd_60uAVgXi(const real_T A[9], real_T U[9], real_T
  s[3], real_T V[9], B_FxtD_Quaternion_c_T *localB)
{
  int32_T e_k;
  int32_T m;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  int32_T qs;
  boolean_T apply_transform;
  boolean_T doscale;
  boolean_T exitg1;
  localB->b_s[0] = 0.0;
  localB->e[0] = 0.0;
  localB->work[0] = 0.0;
  localB->b_s[1] = 0.0;
  localB->e[1] = 0.0;
  localB->work[1] = 0.0;
  localB->b_s[2] = 0.0;
  localB->e[2] = 0.0;
  localB->work[2] = 0.0;
  for (qs = 0; qs < 9; qs++) {
    localB->b_A[qs] = A[qs];
    U[qs] = 0.0;
    localB->Vf[qs] = 0.0;
  }

  doscale = false;
  localB->anrm = FxtD_Quaterni_xzlangeM_CmZ8yEA8(A, localB);
  localB->cscale = localB->anrm;
  if ((localB->anrm > 0.0) && (localB->anrm < 6.7178761075670888E-139)) {
    doscale = true;
    localB->cscale = 6.7178761075670888E-139;
    FxtD_Quaternio_xzlascl_G6oWZyOe(localB->anrm, localB->cscale, localB->b_A,
      localB);
  } else if (localB->anrm > 1.4885657073574029E+138) {
    doscale = true;
    localB->cscale = 1.4885657073574029E+138;
    FxtD_Quaternio_xzlascl_G6oWZyOe(localB->anrm, localB->cscale, localB->b_A,
      localB);
  }

  for (m = 0; m < 2; m++) {
    qp1 = m + 2;
    qs = 3 * m + m;
    qq = qs + 1;
    apply_transform = false;
    localB->nrm = FxtD_Quaternion_xnrm2_lYZMmlSm(3 - m, localB->b_A, qs + 1,
      localB);
    if (localB->nrm > 0.0) {
      apply_transform = true;
      if (localB->b_A[qs] < 0.0) {
        localB->nrm = -localB->nrm;
      }

      localB->b_s[m] = localB->nrm;
      if (fabs(localB->nrm) >= 1.0020841800044864E-292) {
        localB->nrm = 1.0 / localB->nrm;
        qjj = (qs - m) + 3;
        for (e_k = qq; e_k <= qjj; e_k++) {
          localB->b_A[e_k - 1] *= localB->nrm;
        }
      } else {
        qjj = (qs - m) + 3;
        for (e_k = qq; e_k <= qjj; e_k++) {
          localB->b_A[e_k - 1] /= localB->b_s[m];
        }
      }

      localB->b_A[qs]++;
      localB->b_s[m] = -localB->b_s[m];
    } else {
      localB->b_s[m] = 0.0;
    }

    for (qq = qp1; qq < 4; qq++) {
      qjj = (qq - 1) * 3 + m;
      if (apply_transform) {
        xaxpy_hLW3vASe(3 - m, -(xdotc_kGz03SeF(3 - m, localB->b_A, qs + 1,
          localB->b_A, qjj + 1) / localB->b_A[qs]), qs + 1, localB->b_A, qjj + 1);
      }

      localB->e[qq - 1] = localB->b_A[qjj];
    }

    for (qq = m + 1; qq < 4; qq++) {
      qs = (3 * m + qq) - 1;
      U[qs] = localB->b_A[qs];
    }

    if (m + 1 <= 1) {
      localB->nrm = FxtD_Quaternion_xnrm2_pXv7PuuY(localB->e, 2, localB);
      if (localB->nrm == 0.0) {
        localB->e[0] = 0.0;
      } else {
        if (localB->e[1] < 0.0) {
          localB->e[0] = -localB->nrm;
        } else {
          localB->e[0] = localB->nrm;
        }

        localB->nrm = localB->e[0];
        if (fabs(localB->e[0]) >= 1.0020841800044864E-292) {
          localB->nrm = 1.0 / localB->e[0];
          for (qq = qp1; qq < 4; qq++) {
            localB->e[qq - 1] *= localB->nrm;
          }
        } else {
          for (qq = qp1; qq < 4; qq++) {
            localB->e[qq - 1] /= localB->nrm;
          }
        }

        localB->e[1]++;
        localB->e[0] = -localB->e[0];
        for (qq = qp1; qq < 4; qq++) {
          localB->work[qq - 1] = 0.0;
        }

        for (qq = qp1; qq < 4; qq++) {
          xaxpy_8Bk0aMTr(2, localB->e[qq - 1], localB->b_A, 3 * (qq - 1) + 2,
                         localB->work, 2);
        }

        for (qq = qp1; qq < 4; qq++) {
          xaxpy_l5uLg2P0(2, -localB->e[qq - 1] / localB->e[1], localB->work, 2,
                         localB->b_A, 3 * (qq - 1) + 2);
        }
      }

      for (qq = qp1; qq < 4; qq++) {
        localB->Vf[qq - 1] = localB->e[qq - 1];
      }
    }
  }

  m = 1;
  localB->b_s[2] = localB->b_A[8];
  localB->e[1] = localB->b_A[7];
  localB->e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (qp1 = 1; qp1 >= 0; qp1--) {
    qq = 3 * qp1 + qp1;
    if (localB->b_s[qp1] != 0.0) {
      for (qs = qp1 + 2; qs < 4; qs++) {
        qjj = ((qs - 1) * 3 + qp1) + 1;
        xaxpy_hLW3vASe(3 - qp1, -(xdotc_kGz03SeF(3 - qp1, U, qq + 1, U, qjj) /
          U[qq]), qq + 1, U, qjj);
      }

      for (qjj = qp1 + 1; qjj < 4; qjj++) {
        qs = (3 * qp1 + qjj) - 1;
        U[qs] = -U[qs];
      }

      U[qq]++;
      if (qp1 - 1 >= 0) {
        U[3 * qp1] = 0.0;
      }
    } else {
      U[3 * qp1] = 0.0;
      U[3 * qp1 + 1] = 0.0;
      U[3 * qp1 + 2] = 0.0;
      U[qq] = 1.0;
    }
  }

  for (qp1 = 2; qp1 >= 0; qp1--) {
    if ((qp1 + 1 <= 1) && (localB->e[0] != 0.0)) {
      xaxpy_hLW3vASe(2, -(xdotc_kGz03SeF(2, localB->Vf, 2, localB->Vf, 5) /
                          localB->Vf[1]), 2, localB->Vf, 5);
      xaxpy_hLW3vASe(2, -(xdotc_kGz03SeF(2, localB->Vf, 2, localB->Vf, 8) /
                          localB->Vf[1]), 2, localB->Vf, 8);
    }

    localB->Vf[3 * qp1] = 0.0;
    localB->Vf[3 * qp1 + 1] = 0.0;
    localB->Vf[3 * qp1 + 2] = 0.0;
    localB->Vf[qp1 + 3 * qp1] = 1.0;
  }

  qp1 = 0;
  localB->nrm = 0.0;
  for (qq = 0; qq < 3; qq++) {
    localB->r = localB->b_s[qq];
    if (localB->r != 0.0) {
      localB->rt = fabs(localB->r);
      localB->r /= localB->rt;
      localB->b_s[qq] = localB->rt;
      if (qq + 1 < 3) {
        localB->e[qq] /= localB->r;
      }

      qs = 3 * qq + 1;
      for (qjj = qs; qjj <= qs + 2; qjj++) {
        U[qjj - 1] *= localB->r;
      }
    }

    if (qq + 1 < 3) {
      localB->r = localB->e[qq];
      if (localB->r != 0.0) {
        localB->rt = fabs(localB->r);
        localB->r = localB->rt / localB->r;
        localB->e[qq] = localB->rt;
        localB->b_s[qq + 1] *= localB->r;
        qs = (qq + 1) * 3 + 1;
        for (qjj = qs; qjj <= qs + 2; qjj++) {
          localB->Vf[qjj - 1] *= localB->r;
        }
      }
    }

    localB->r = fabs(localB->b_s[qq]);
    localB->rt = fabs(localB->e[qq]);
    if ((localB->r >= localB->rt) || rtIsNaN(localB->rt)) {
      localB->rt = localB->r;
    }

    if ((!(localB->nrm >= localB->rt)) && (!rtIsNaN(localB->rt))) {
      localB->nrm = localB->rt;
    }
  }

  while ((m + 2 > 0) && (qp1 < 75)) {
    qq = m + 1;
    exitg1 = false;
    while (!(exitg1 || (qq == 0))) {
      localB->rt = fabs(localB->e[qq - 1]);
      if (localB->rt <= (fabs(localB->b_s[qq - 1]) + fabs(localB->b_s[qq])) *
          2.2204460492503131E-16) {
        localB->e[qq - 1] = 0.0;
        exitg1 = true;
      } else if ((localB->rt <= 1.0020841800044864E-292) || ((qp1 > 20) &&
                  (localB->rt <= 2.2204460492503131E-16 * localB->nrm))) {
        localB->e[qq - 1] = 0.0;
        exitg1 = true;
      } else {
        qq--;
      }
    }

    if (m + 1 == qq) {
      qjj = 4;
    } else {
      qs = m + 2;
      qjj = m + 2;
      exitg1 = false;
      while ((!exitg1) && (qjj >= qq)) {
        qs = qjj;
        if (qjj == qq) {
          exitg1 = true;
        } else {
          localB->rt = 0.0;
          if (qjj < m + 2) {
            localB->rt = fabs(localB->e[qjj - 1]);
          }

          if (qjj > qq + 1) {
            localB->rt += fabs(localB->e[qjj - 2]);
          }

          localB->r = fabs(localB->b_s[qjj - 1]);
          if ((localB->r <= 2.2204460492503131E-16 * localB->rt) || (localB->r <=
               1.0020841800044864E-292)) {
            localB->b_s[qjj - 1] = 0.0;
            exitg1 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qs == qq) {
        qjj = 3;
      } else if (m + 2 == qs) {
        qjj = 1;
      } else {
        qjj = 2;
        qq = qs;
      }
    }

    switch (qjj) {
     case 1:
      localB->rt = localB->e[m];
      localB->e[m] = 0.0;
      for (qs = m + 1; qs >= qq + 1; qs--) {
        FxtD_Quaternion_xrotg_QLPrMQ5c(&localB->b_s[qs - 1], &localB->rt,
          &localB->r, &localB->sqds, localB);
        if (qs > qq + 1) {
          localB->rt = -localB->sqds * localB->e[0];
          localB->e[0] *= localB->r;
        }

        FxtD_Quaternion_xrot_PLEUrKWS(localB->Vf, 3 * (qs - 1) + 1, 3 * (m + 1)
          + 1, localB->r, localB->sqds, localB);
      }
      break;

     case 2:
      localB->rt = localB->e[qq - 1];
      localB->e[qq - 1] = 0.0;
      for (qs = qq + 1; qs <= m + 2; qs++) {
        FxtD_Quaternion_xrotg_QLPrMQ5c(&localB->b_s[qs - 1], &localB->rt,
          &localB->sqds, &localB->smm1, localB);
        localB->r = localB->e[qs - 1];
        localB->rt = -localB->smm1 * localB->r;
        localB->e[qs - 1] = localB->r * localB->sqds;
        FxtD_Quaternion_xrot_PLEUrKWS(U, 3 * (qs - 1) + 1, 3 * (qq - 1) + 1,
          localB->sqds, localB->smm1, localB);
      }
      break;

     case 3:
      localB->sqds = localB->b_s[m + 1];
      localB->r = fabs(localB->sqds);
      localB->rt = fabs(localB->b_s[m]);
      if ((localB->r >= localB->rt) || rtIsNaN(localB->rt)) {
        localB->rt = localB->r;
      }

      localB->r = fabs(localB->e[m]);
      if ((localB->rt >= localB->r) || rtIsNaN(localB->r)) {
        localB->r = localB->rt;
      }

      localB->rt = fabs(localB->b_s[qq]);
      if ((localB->r >= localB->rt) || rtIsNaN(localB->rt)) {
        localB->rt = localB->r;
      }

      localB->r = fabs(localB->e[qq]);
      if ((localB->rt >= localB->r) || rtIsNaN(localB->r)) {
        localB->r = localB->rt;
      }

      localB->rt = localB->sqds / localB->r;
      localB->smm1 = localB->b_s[m] / localB->r;
      localB->emm1 = localB->e[m] / localB->r;
      localB->sqds = localB->b_s[qq] / localB->r;
      localB->smm1 = ((localB->smm1 + localB->rt) * (localB->smm1 - localB->rt)
                      + localB->emm1 * localB->emm1) / 2.0;
      localB->emm1 *= localB->rt;
      localB->emm1 *= localB->emm1;
      if ((localB->smm1 != 0.0) || (localB->emm1 != 0.0)) {
        localB->shift = sqrt(localB->smm1 * localB->smm1 + localB->emm1);
        if (localB->smm1 < 0.0) {
          localB->shift = -localB->shift;
        }

        localB->shift = localB->emm1 / (localB->smm1 + localB->shift);
      } else {
        localB->shift = 0.0;
      }

      localB->rt = (localB->sqds + localB->rt) * (localB->sqds - localB->rt) +
        localB->shift;
      localB->r = localB->e[qq] / localB->r * localB->sqds;
      for (e_k = qq + 1; e_k <= m + 1; e_k++) {
        FxtD_Quaternion_xrotg_QLPrMQ5c(&localB->rt, &localB->r, &localB->sqds,
          &localB->smm1, localB);
        if (e_k > qq + 1) {
          localB->e[0] = localB->rt;
        }

        localB->r = localB->e[e_k - 1];
        localB->emm1 = localB->b_s[e_k - 1];
        localB->e[e_k - 1] = localB->r * localB->sqds - localB->emm1 *
          localB->smm1;
        localB->rt = localB->smm1 * localB->b_s[e_k];
        localB->b_s[e_k] *= localB->sqds;
        qs = (e_k - 1) * 3 + 1;
        qjj = 3 * e_k + 1;
        FxtD_Quaternion_xrot_PLEUrKWS(localB->Vf, qs, qjj, localB->sqds,
          localB->smm1, localB);
        localB->b_s[e_k - 1] = localB->emm1 * localB->sqds + localB->r *
          localB->smm1;
        FxtD_Quaternion_xrotg_QLPrMQ5c(&localB->b_s[e_k - 1], &localB->rt,
          &localB->sqds, &localB->smm1, localB);
        localB->emm1 = localB->e[e_k - 1];
        localB->rt = localB->emm1 * localB->sqds + localB->smm1 * localB->
          b_s[e_k];
        localB->b_s[e_k] = localB->emm1 * -localB->smm1 + localB->sqds *
          localB->b_s[e_k];
        localB->r = localB->smm1 * localB->e[e_k];
        localB->e[e_k] *= localB->sqds;
        FxtD_Quaternion_xrot_PLEUrKWS(U, qs, qjj, localB->sqds, localB->smm1,
          localB);
      }

      localB->e[m] = localB->rt;
      qp1++;
      break;

     default:
      if (localB->b_s[qq] < 0.0) {
        localB->b_s[qq] = -localB->b_s[qq];
        qp1 = 3 * qq + 1;
        for (qs = qp1; qs <= qp1 + 2; qs++) {
          localB->Vf[qs - 1] = -localB->Vf[qs - 1];
        }
      }

      qp1 = qq + 1;
      while ((qq + 1 < 3) && (localB->b_s[qq] < localB->b_s[qp1])) {
        localB->rt = localB->b_s[qq];
        localB->b_s[qq] = localB->b_s[qp1];
        localB->b_s[qp1] = localB->rt;
        qs = 3 * qq + 1;
        qjj = (qq + 1) * 3 + 1;
        xswap_nAn5Zpao(localB->Vf, qs, qjj);
        xswap_nAn5Zpao(U, qs, qjj);
        qq = qp1;
        qp1++;
      }

      qp1 = 0;
      m--;
      break;
    }
  }

  s[0] = localB->b_s[0];
  s[1] = localB->b_s[1];
  s[2] = localB->b_s[2];
  if (doscale) {
    FxtD_Quaternio_xzlascl_ftGcEjOL(localB->cscale, localB->anrm, s, localB);
  }

  for (m = 0; m < 3; m++) {
    V[3 * m] = localB->Vf[3 * m];
    qp1 = 3 * m + 1;
    V[qp1] = localB->Vf[qp1];
    qp1 = 3 * m + 2;
    V[qp1] = localB->Vf[qp1];
  }
}

// System initialize for referenced model: 'FxtD_Quaternion'
void FxtD_Quaternion_Init(DW_FxtD_Quaternion_f_T *localDW)
{
  // InitializeConditions for Memory: '<Root>/Memory3'
  localDW->Memory3_PreviousInput[0] =
    FxtD_Quaternion_P.Memory3_InitialCondition[0];
  localDW->Memory3_PreviousInput[1] =
    FxtD_Quaternion_P.Memory3_InitialCondition[1];
  localDW->Memory3_PreviousInput[2] =
    FxtD_Quaternion_P.Memory3_InitialCondition[2];
  localDW->Memory3_PreviousInput[3] =
    FxtD_Quaternion_P.Memory3_InitialCondition[3];

  // InitializeConditions for Memory: '<Root>/Memory4'
  localDW->Memory4_PreviousInput[0] =
    FxtD_Quaternion_P.Memory4_InitialCondition[0];

  // InitializeConditions for Memory: '<Root>/Memory1'
  localDW->Memory1_PreviousInput[0] =
    FxtD_Quaternion_P.Memory1_InitialCondition[0];

  // InitializeConditions for Memory: '<Root>/Memory2'
  localDW->Memory2_PreviousInput[0] =
    FxtD_Quaternion_P.Memory2_InitialCondition[0];

  // InitializeConditions for Memory: '<Root>/Memory4'
  localDW->Memory4_PreviousInput[1] =
    FxtD_Quaternion_P.Memory4_InitialCondition[1];

  // InitializeConditions for Memory: '<Root>/Memory1'
  localDW->Memory1_PreviousInput[1] =
    FxtD_Quaternion_P.Memory1_InitialCondition[1];

  // InitializeConditions for Memory: '<Root>/Memory2'
  localDW->Memory2_PreviousInput[1] =
    FxtD_Quaternion_P.Memory2_InitialCondition[1];

  // InitializeConditions for Memory: '<Root>/Memory4'
  localDW->Memory4_PreviousInput[2] =
    FxtD_Quaternion_P.Memory4_InitialCondition[2];

  // InitializeConditions for Memory: '<Root>/Memory1'
  localDW->Memory1_PreviousInput[2] =
    FxtD_Quaternion_P.Memory1_InitialCondition[2];

  // InitializeConditions for Memory: '<Root>/Memory2'
  localDW->Memory2_PreviousInput[2] =
    FxtD_Quaternion_P.Memory2_InitialCondition[2];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' 
  localDW->DiscreteTimeIntegrator4_DSTATE[0] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator4_IC[0];
  localDW->DiscreteTimeIntegrator4_DSTATE[1] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator4_IC[1];
  localDW->DiscreteTimeIntegrator4_DSTATE[2] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator4_IC[2];
  localDW->DiscreteTimeIntegrator4_DSTATE[3] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator4_IC[3];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' 
  localDW->DiscreteTimeIntegrator1_DSTATE[0] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator1_IC[0];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' 
  localDW->DiscreteTimeIntegrator3_DSTATE[0] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator3_IC[0];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' 
  localDW->DiscreteTimeIntegrator2_DSTATE[0] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator2_IC[0];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' 
  localDW->DiscreteTimeIntegrator1_DSTATE[1] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator1_IC[1];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' 
  localDW->DiscreteTimeIntegrator3_DSTATE[1] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator3_IC[1];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' 
  localDW->DiscreteTimeIntegrator2_DSTATE[1] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator2_IC[1];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' 
  localDW->DiscreteTimeIntegrator1_DSTATE[2] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator1_IC[2];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' 
  localDW->DiscreteTimeIntegrator3_DSTATE[2] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator3_IC[2];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' 
  localDW->DiscreteTimeIntegrator2_DSTATE[2] =
    FxtD_Quaternion_P.DiscreteTimeIntegrator2_IC[2];
}

// Output and update for referenced model: 'FxtD_Quaternion'
void FxtD_Quaternion(const real_T rtu_pos[3], const real_T
                     rtu_PX4Params_FxTDiffg_G1[6], const real_T
                     rtu_PX4Params_FxTDiffg_G2[6], const real_T
                     rtu_PX4Params_FxTDiffg_lam1[6], const real_T
                     rtu_PX4Params_FxTDiffg_vrho1[6], const real_T
                     rtu_quaternion[4], real_T rty_state_hat_pos_hat[6], real_T
                     rty_state_hat_pos_dot_hat[6], real_T
                     rty_state_hat_pos_ddot_hat[6], real_T rty_state_hat_e_hat[6],
                     real_T rty_state_hat_q_hat[4], real_T
                     rty_state_hat_q_tilde[4], B_FxtD_Quaternion_c_T *localB,
                     DW_FxtD_Quaternion_f_T *localDW)
{
  int32_T ar;
  int32_T b;
  int32_T br;
  int32_T c_k;
  int32_T exponent;
  int32_T vcol;
  boolean_T exitg1;
  boolean_T p;
  boolean_T tmp;
  boolean_T tmp_0;

  // Sqrt: '<S25>/sqrt' incorporates:
  //   Memory: '<Root>/Memory3'
  //   Product: '<S26>/Product'
  //   Product: '<S26>/Product1'
  //   Product: '<S26>/Product2'
  //   Product: '<S26>/Product3'
  //   Sum: '<S26>/Sum'

  localB->Product3_eu = sqrt(((localDW->Memory3_PreviousInput[0] *
    localDW->Memory3_PreviousInput[0] + localDW->Memory3_PreviousInput[1] *
    localDW->Memory3_PreviousInput[1]) + localDW->Memory3_PreviousInput[2] *
    localDW->Memory3_PreviousInput[2]) + localDW->Memory3_PreviousInput[3] *
    localDW->Memory3_PreviousInput[3]);

  // Product: '<S7>/Product' incorporates:
  //   Memory: '<Root>/Memory3'

  localB->Product2_d = localDW->Memory3_PreviousInput[0] / localB->Product3_eu;

  // Product: '<S7>/Product1' incorporates:
  //   Memory: '<Root>/Memory3'

  localB->Product1_c = localDW->Memory3_PreviousInput[1] / localB->Product3_eu;

  // Product: '<S7>/Product2' incorporates:
  //   Memory: '<Root>/Memory3'

  localB->UnaryMinus1 = localDW->Memory3_PreviousInput[2] / localB->Product3_eu;

  // Product: '<S7>/Product3' incorporates:
  //   Memory: '<Root>/Memory3'

  localB->Product3_eu = localDW->Memory3_PreviousInput[3] / localB->Product3_eu;

  // Sum: '<S22>/Sum' incorporates:
  //   Product: '<S22>/Product'
  //   Product: '<S22>/Product1'
  //   Product: '<S22>/Product2'
  //   Product: '<S22>/Product3'
  //   UnaryMinus: '<S2>/Unary Minus'
  //   UnaryMinus: '<S2>/Unary Minus1'
  //   UnaryMinus: '<S2>/Unary Minus2'

  localB->Sum = ((localB->Product2_d * rtu_quaternion[1] + -localB->Product1_c *
                  rtu_quaternion[0]) + -localB->UnaryMinus1 * rtu_quaternion[3])
    - -localB->Product3_eu * rtu_quaternion[2];

  // Sum: '<S23>/Sum' incorporates:
  //   Product: '<S23>/Product'
  //   Product: '<S23>/Product1'
  //   Product: '<S23>/Product2'
  //   Product: '<S23>/Product3'
  //   UnaryMinus: '<S2>/Unary Minus'
  //   UnaryMinus: '<S2>/Unary Minus1'
  //   UnaryMinus: '<S2>/Unary Minus2'

  localB->Sum_f = ((localB->Product2_d * rtu_quaternion[2] - -localB->Product1_c
                    * rtu_quaternion[3]) + -localB->UnaryMinus1 *
                   rtu_quaternion[0]) + -localB->Product3_eu * rtu_quaternion[1];

  // Sum: '<S24>/Sum' incorporates:
  //   Product: '<S24>/Product'
  //   Product: '<S24>/Product1'
  //   Product: '<S24>/Product2'
  //   Product: '<S24>/Product3'
  //   UnaryMinus: '<S2>/Unary Minus'
  //   UnaryMinus: '<S2>/Unary Minus1'
  //   UnaryMinus: '<S2>/Unary Minus2'

  localB->Sum_b = ((localB->Product2_d * rtu_quaternion[3] + -localB->Product1_c
                    * rtu_quaternion[2]) - -localB->UnaryMinus1 *
                   rtu_quaternion[1]) + -localB->Product3_eu * rtu_quaternion[0];

  // Sum: '<S21>/Sum' incorporates:
  //   Product: '<S21>/Product'
  //   Product: '<S21>/Product1'
  //   Product: '<S21>/Product2'
  //   Product: '<S21>/Product3'
  //   UnaryMinus: '<S2>/Unary Minus'
  //   UnaryMinus: '<S2>/Unary Minus1'
  //   UnaryMinus: '<S2>/Unary Minus2'

  localB->Sum_a = ((localB->Product2_d * rtu_quaternion[0] - -localB->Product1_c
                    * rtu_quaternion[1]) - -localB->UnaryMinus1 *
                   rtu_quaternion[2]) - -localB->Product3_eu * rtu_quaternion[3];

  // SignalConversion generated from: '<S8>/ SFunction ' incorporates:
  //   MATLAB Function: '<Root>/calculateCvMatrix'
  //   SignalConversion generated from: '<Root>/state_hat_Outport_1'

  rty_state_hat_q_tilde[0] = localB->Sum_a;
  rty_state_hat_q_tilde[1] = localB->Sum;
  rty_state_hat_q_tilde[2] = localB->Sum_f;
  rty_state_hat_q_tilde[3] = localB->Sum_b;

  // MATLAB Function: '<Root>/calculateCvMatrix' incorporates:
  //   SignalConversion generated from: '<S8>/ SFunction '

  localB->A[0] = rty_state_hat_q_tilde[0] * 0.5;
  localB->A[3] = -rty_state_hat_q_tilde[3] * 0.5;
  localB->A[6] = rty_state_hat_q_tilde[2] * 0.5;
  localB->A[1] = rty_state_hat_q_tilde[3] * 0.5;
  localB->A[4] = rty_state_hat_q_tilde[0] * 0.5;
  localB->A[7] = -rty_state_hat_q_tilde[1] * 0.5;
  localB->A[2] = -rty_state_hat_q_tilde[2] * 0.5;
  localB->A[5] = rty_state_hat_q_tilde[1] * 0.5;
  localB->A[8] = rty_state_hat_q_tilde[0] * 0.5;
  p = true;
  for (c_k = 0; c_k < 9; c_k++) {
    localB->Cv[c_k] = 0.0;
    if (p) {
      localB->absx = localB->A[c_k];
      if (rtIsInf(localB->absx) || rtIsNaN(localB->absx)) {
        p = false;
      }
    }
  }

  if (!p) {
    for (c_k = 0; c_k < 9; c_k++) {
      localB->Cv[c_k] = (rtNaN);
    }
  } else {
    FxtD_Quaternion_svd_60uAVgXi(localB->A, localB->U, localB->Product8,
      localB->V, localB);
    localB->absx = fabs(localB->Product8[0]);
    if (rtIsInf(localB->absx) || rtIsNaN(localB->absx)) {
      localB->absx = (rtNaN);
    } else if (localB->absx < 4.4501477170144028E-308) {
      localB->absx = 4.94065645841247E-324;
    } else {
      frexp(localB->absx, &exponent);
      localB->absx = ldexp(1.0, exponent - 53);
    }

    localB->absx *= 3.0;
    c_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c_k < 3)) {
      if (rtIsInf(localB->Product8[c_k]) || rtIsNaN(localB->Product8[c_k])) {
        localB->absx = 1.7976931348623157E+308;
        exitg1 = true;
      } else {
        c_k++;
      }
    }

    localB->r_n = -1;
    c_k = 0;
    while ((c_k < 3) && (localB->Product8[c_k] > localB->absx)) {
      localB->r_n++;
      c_k++;
    }

    if (localB->r_n + 1 > 0) {
      vcol = 1;
      for (c_k = 0; c_k <= localB->r_n; c_k++) {
        localB->absx = 1.0 / localB->Product8[c_k];
        for (exponent = vcol; exponent <= vcol + 2; exponent++) {
          localB->V[exponent - 1] *= localB->absx;
        }

        vcol += 3;
      }

      for (c_k = 0; c_k <= 6; c_k += 3) {
        for (exponent = c_k + 1; exponent <= c_k + 3; exponent++) {
          localB->Cv[exponent - 1] = 0.0;
        }
      }

      br = 0;
      for (c_k = 0; c_k <= 6; c_k += 3) {
        ar = -1;
        br++;
        b = 3 * localB->r_n + br;
        for (exponent = br; exponent <= b; exponent += 3) {
          for (vcol = c_k + 1; vcol <= c_k + 3; vcol++) {
            localB->Cv[vcol - 1] += localB->V[(ar + vcol) - c_k] * localB->
              U[exponent - 1];
          }

          ar += 3;
        }
      }
    }
  }

  for (c_k = 0; c_k < 6; c_k++) {
    // Sum: '<Root>/Sum1' incorporates:
    //   Constant: '<Root>/Constant1'
    //   Gain: '<Root>/Gain'

    localB->Sum1[c_k] = FxtD_Quaternion_P.Gain_Gain *
      rtu_PX4Params_FxTDiffg_lam1[c_k] - FxtD_Quaternion_P.Constant1_Value;

    // Sum: '<Root>/Sum2' incorporates:
    //   Constant: '<Root>/Constant3'
    //   Gain: '<Root>/Gain2'

    localB->Sum2[c_k] = FxtD_Quaternion_P.Gain2_Gain *
      rtu_PX4Params_FxTDiffg_vrho1[c_k] - FxtD_Quaternion_P.Constant3_Value;
  }

  // SignalConversion generated from: '<Root>/state_hat_Outport_1'
  rty_state_hat_q_hat[0] = localB->Product2_d;
  rty_state_hat_q_hat[1] = localB->Product1_c;
  rty_state_hat_q_hat[2] = localB->UnaryMinus1;
  rty_state_hat_q_hat[3] = localB->Product3_eu;

  // Gain: '<Root>/Gain4' incorporates:
  //   Product: '<S10>/Product'
  //   Product: '<S10>/Product1'
  //   Product: '<S10>/Product2'
  //   Product: '<S10>/Product3'
  //   Product: '<S11>/Product'
  //   Product: '<S11>/Product1'
  //   Product: '<S11>/Product2'
  //   Product: '<S11>/Product3'
  //   Product: '<S12>/Product'
  //   Product: '<S12>/Product1'
  //   Product: '<S12>/Product2'
  //   Product: '<S12>/Product3'
  //   Product: '<S9>/Product'
  //   Product: '<S9>/Product1'
  //   Product: '<S9>/Product2'
  //   Product: '<S9>/Product3'
  //   Sum: '<S10>/Sum'
  //   Sum: '<S11>/Sum'
  //   Sum: '<S12>/Sum'
  //   Sum: '<S9>/Sum'

  localB->rtb_Gain4_idx_0 = (((localB->Product2_d * localB->Sum_a -
    localB->Product1_c * localB->Sum) - localB->UnaryMinus1 * localB->Sum_f) -
    localB->Product3_eu * localB->Sum_b) * FxtD_Quaternion_P.Gain4_Gain;
  localB->rtb_Gain4_idx_1 = (((localB->Product2_d * localB->Sum +
    localB->Product1_c * localB->Sum_a) + localB->UnaryMinus1 * localB->Sum_b) -
    localB->Product3_eu * localB->Sum_f) * FxtD_Quaternion_P.Gain4_Gain;
  localB->rtb_Gain4_idx_2 = (((localB->Product2_d * localB->Sum_f -
    localB->Product1_c * localB->Sum_b) + localB->UnaryMinus1 * localB->Sum_a) +
    localB->Product3_eu * localB->Sum) * FxtD_Quaternion_P.Gain4_Gain;
  localB->rtb_Gain4_idx_3 = (((localB->Product2_d * localB->Sum_b +
    localB->Product1_c * localB->Sum_f) - localB->UnaryMinus1 * localB->Sum) +
    localB->Product3_eu * localB->Sum_a) * FxtD_Quaternion_P.Gain4_Gain;

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant'

  localB->Product3_eu = localDW->Memory4_PreviousInput[0];
  rty_state_hat_pos_hat[0] = localB->Product3_eu;
  rty_state_hat_pos_hat[3] = FxtD_Quaternion_P.Constant_Value[0];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1'
  rty_state_hat_pos_dot_hat[0] = localDW->Memory1_PreviousInput[0];
  rty_state_hat_pos_dot_hat[3] = localDW->Memory2_PreviousInput[0];

  // Sum: '<Root>/Sum' incorporates:
  //   Math: '<Root>/Power1'

  localB->Product3_eu = rtu_pos[0] - localB->Product3_eu;
  localDW->Memory4_PreviousInput[0] = localB->Product3_eu;

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant4'

  rty_state_hat_e_hat[0] = localB->Product3_eu;
  rty_state_hat_e_hat[3] = FxtD_Quaternion_P.Constant4_Value[0];

  // Signum: '<Root>/Sign3'
  p = rtIsNaN(localB->Sum);
  if (p) {
    localB->rtb_Cv_m = (rtNaN);
  } else if (localB->Sum < 0.0) {
    localB->rtb_Cv_m = -1.0;
  } else {
    localB->rtb_Cv_m = (localB->Sum > 0.0);
  }

  // Product: '<Root>/Product6' incorporates:
  //   Product: '<Root>/Product7'
  //   Signum: '<Root>/Sign3'

  localB->Sum_m = localB->rtb_Cv_m * rtu_PX4Params_FxTDiffg_G1[3];

  // Abs: '<Root>/Abs4' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Abs: '<Root>/Abs6'
  //   Abs: '<Root>/Abs7'

  localB->Product3_eu = fabs(localB->Sum);
  localB->absx = localB->Product3_eu;

  // Product: '<Root>/Product6' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Math: '<Root>/Power3'

  localB->Product2_d = localB->Sum_m * rt_powd_snf(localB->Product3_eu,
    rtu_PX4Params_FxTDiffg_lam1[3]);

  // Product: '<Root>/Product7' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power4'

  localB->rtb_Product8_tmp_idx_0 = localB->Sum_m * rt_powd_snf
    (localB->Product3_eu, rtu_PX4Params_FxTDiffg_vrho1[3]);

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant'

  localB->Product3_eu = localDW->Memory4_PreviousInput[1];
  rty_state_hat_pos_hat[1] = localB->Product3_eu;
  rty_state_hat_pos_hat[4] = FxtD_Quaternion_P.Constant_Value[1];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1'
  rty_state_hat_pos_dot_hat[1] = localDW->Memory1_PreviousInput[1];
  rty_state_hat_pos_dot_hat[4] = localDW->Memory2_PreviousInput[1];

  // Sum: '<Root>/Sum' incorporates:
  //   Math: '<Root>/Power1'

  localB->Product3_eu = rtu_pos[1] - localB->Product3_eu;
  localDW->Memory4_PreviousInput[1] = localB->Product3_eu;

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant4'

  rty_state_hat_e_hat[1] = localB->Product3_eu;
  rty_state_hat_e_hat[4] = FxtD_Quaternion_P.Constant4_Value[1];

  // Signum: '<Root>/Sign3'
  tmp = rtIsNaN(localB->Sum_f);
  if (tmp) {
    localB->rtb_Cv_m = (rtNaN);
  } else if (localB->Sum_f < 0.0) {
    localB->rtb_Cv_m = -1.0;
  } else {
    localB->rtb_Cv_m = (localB->Sum_f > 0.0);
  }

  // Product: '<Root>/Product6' incorporates:
  //   Product: '<Root>/Product7'
  //   Signum: '<Root>/Sign3'

  localB->Sum_m = localB->rtb_Cv_m * rtu_PX4Params_FxTDiffg_G1[4];

  // Abs: '<Root>/Abs4' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Abs: '<Root>/Abs6'
  //   Abs: '<Root>/Abs7'

  localB->Product3_eu = fabs(localB->Sum_f);
  localB->Product1_c = localB->Product3_eu;

  // Product: '<Root>/Product6' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Math: '<Root>/Power3'

  localB->UnaryMinus1 = localB->Sum_m * rt_powd_snf(localB->Product3_eu,
    rtu_PX4Params_FxTDiffg_lam1[4]);

  // Product: '<Root>/Product7' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power4'

  localB->rtb_Product8_tmp_idx_1 = localB->Sum_m * rt_powd_snf
    (localB->Product3_eu, rtu_PX4Params_FxTDiffg_vrho1[4]);

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant'

  localB->Product3_eu = localDW->Memory4_PreviousInput[2];
  rty_state_hat_pos_hat[2] = localB->Product3_eu;
  rty_state_hat_pos_hat[5] = FxtD_Quaternion_P.Constant_Value[2];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1'
  rty_state_hat_pos_dot_hat[2] = localDW->Memory1_PreviousInput[2];
  rty_state_hat_pos_dot_hat[5] = localDW->Memory2_PreviousInput[2];

  // Sum: '<Root>/Sum' incorporates:
  //   Math: '<Root>/Power1'

  localB->Product3_eu = rtu_pos[2] - localB->Product3_eu;
  localDW->Memory4_PreviousInput[2] = localB->Product3_eu;

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant4'

  rty_state_hat_e_hat[2] = localB->Product3_eu;
  rty_state_hat_e_hat[5] = FxtD_Quaternion_P.Constant4_Value[2];

  // Signum: '<Root>/Sign3'
  tmp_0 = rtIsNaN(localB->Sum_b);
  if (tmp_0) {
    localB->rtb_Cv_m = (rtNaN);
  } else if (localB->Sum_b < 0.0) {
    localB->rtb_Cv_m = -1.0;
  } else {
    localB->rtb_Cv_m = (localB->Sum_b > 0.0);
  }

  // Product: '<Root>/Product6' incorporates:
  //   Product: '<Root>/Product7'
  //   Signum: '<Root>/Sign3'

  localB->Sum_m = localB->rtb_Cv_m * rtu_PX4Params_FxTDiffg_G1[5];

  // Abs: '<Root>/Abs4' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Abs: '<Root>/Abs6'
  //   Abs: '<Root>/Abs7'

  localB->Product3_eu = fabs(localB->Sum_b);

  // Product: '<Root>/Product6' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Math: '<Root>/Power3'

  localB->rtb_Product8_tmp_idx_2 = localB->Sum_m * rt_powd_snf
    (localB->Product3_eu, rtu_PX4Params_FxTDiffg_lam1[5]);

  // Product: '<Root>/Product7' incorporates:
  //   Abs: '<Root>/Abs5'
  //   Math: '<Root>/Power4'

  localB->Sum_m *= rt_powd_snf(localB->Product3_eu,
    rtu_PX4Params_FxTDiffg_vrho1[5]);
  for (c_k = 0; c_k < 3; c_k++) {
    // Sum: '<Root>/Sum7' incorporates:
    //   Product: '<Root>/Matrix Multiply1'

    localB->Sum_d = localB->Cv[c_k];
    localB->rtb_Cv_m = localB->Sum_d * localB->Product2_d;

    // Product: '<Root>/Matrix Multiply2'
    localB->rtb_Cv_c = localB->Sum_d * localB->rtb_Product8_tmp_idx_0;

    // Sum: '<Root>/Sum7' incorporates:
    //   Product: '<Root>/Matrix Multiply1'

    localB->Sum_d = localB->Cv[c_k + 3];
    localB->rtb_Cv_m += localB->Sum_d * localB->UnaryMinus1;

    // Product: '<Root>/Matrix Multiply2'
    localB->rtb_Cv_c += localB->Sum_d * localB->rtb_Product8_tmp_idx_1;

    // Sum: '<Root>/Sum7' incorporates:
    //   Memory: '<Root>/Memory2'
    //   Product: '<Root>/Matrix Multiply1'
    //   Product: '<Root>/Matrix Multiply2'
    //   Product: '<Root>/Product8'

    localB->Sum_d = localB->Cv[c_k + 6];
    localB->Product8[c_k] = ((localB->Sum_d * localB->rtb_Product8_tmp_idx_2 +
      localB->rtb_Cv_m) + localDW->Memory2_PreviousInput[c_k]) + (localB->Sum_d *
      localB->Sum_m + localB->rtb_Cv_c);
  }

  // Sum: '<S13>/Sum' incorporates:
  //   Constant: '<Root>/Constant8'
  //   Product: '<S13>/Product'
  //   Product: '<S13>/Product1'
  //   Product: '<S13>/Product2'
  //   Product: '<S13>/Product3'

  localB->Product2_d = ((localB->rtb_Gain4_idx_0 *
    FxtD_Quaternion_P.Constant8_Value - localB->Product8[0] *
    localB->rtb_Gain4_idx_1) - localB->Product8[1] * localB->rtb_Gain4_idx_2) -
    localB->Product8[2] * localB->rtb_Gain4_idx_3;

  // Sum: '<S14>/Sum' incorporates:
  //   Constant: '<Root>/Constant8'
  //   Product: '<S14>/Product'
  //   Product: '<S14>/Product1'
  //   Product: '<S14>/Product2'
  //   Product: '<S14>/Product3'

  localB->UnaryMinus1 = ((localB->rtb_Gain4_idx_0 * localB->Product8[0] +
    localB->rtb_Gain4_idx_1 * FxtD_Quaternion_P.Constant8_Value) +
    localB->rtb_Gain4_idx_2 * localB->Product8[2]) - localB->Product8[1] *
    localB->rtb_Gain4_idx_3;

  // Sum: '<S15>/Sum' incorporates:
  //   Constant: '<Root>/Constant8'
  //   Product: '<S15>/Product'
  //   Product: '<S15>/Product1'
  //   Product: '<S15>/Product2'
  //   Product: '<S15>/Product3'

  localB->Sum_m = ((localB->rtb_Gain4_idx_0 * localB->Product8[1] -
                    localB->rtb_Gain4_idx_1 * localB->Product8[2]) +
                   localB->rtb_Gain4_idx_2 * FxtD_Quaternion_P.Constant8_Value)
    + localB->Product8[0] * localB->rtb_Gain4_idx_3;

  // Sum: '<S16>/Sum' incorporates:
  //   Constant: '<Root>/Constant8'
  //   Product: '<S16>/Product'
  //   Product: '<S16>/Product1'
  //   Product: '<S16>/Product2'
  //   Product: '<S16>/Product3'

  localB->Sum_d = ((localB->rtb_Gain4_idx_0 * localB->Product8[2] +
                    localB->rtb_Gain4_idx_1 * localB->Product8[1]) -
                   localB->Product8[0] * localB->rtb_Gain4_idx_2) +
    localB->rtb_Gain4_idx_3 * FxtD_Quaternion_P.Constant8_Value;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' incorporates:
  //   Product: '<S17>/Product'
  //   Product: '<S17>/Product1'
  //   Product: '<S17>/Product2'
  //   Product: '<S17>/Product3'
  //   Sum: '<S17>/Sum'
  //   UnaryMinus: '<S1>/Unary Minus'
  //   UnaryMinus: '<S1>/Unary Minus1'
  //   UnaryMinus: '<S1>/Unary Minus2'

  localB->rtb_Gain4_idx_0 = (((localB->Product2_d * localB->Sum_a -
    localB->UnaryMinus1 * -localB->Sum) - localB->Sum_m * -localB->Sum_f) -
    localB->Sum_d * -localB->Sum_b) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator4_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
  localDW->Memory3_PreviousInput[0] = localB->rtb_Gain4_idx_0 +
    localDW->DiscreteTimeIntegrator4_DSTATE[0];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' incorporates:
  //   Product: '<S18>/Product'
  //   Product: '<S18>/Product1'
  //   Product: '<S18>/Product2'
  //   Product: '<S18>/Product3'
  //   Sum: '<S18>/Sum'
  //   UnaryMinus: '<S1>/Unary Minus'
  //   UnaryMinus: '<S1>/Unary Minus1'
  //   UnaryMinus: '<S1>/Unary Minus2'

  localB->rtb_Gain4_idx_1 = (((localB->Product2_d * -localB->Sum +
    localB->UnaryMinus1 * localB->Sum_a) + localB->Sum_m * -localB->Sum_b) -
    localB->Sum_d * -localB->Sum_f) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator4_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
  localDW->Memory3_PreviousInput[1] = localB->rtb_Gain4_idx_1 +
    localDW->DiscreteTimeIntegrator4_DSTATE[1];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' incorporates:
  //   Product: '<S19>/Product'
  //   Product: '<S19>/Product1'
  //   Product: '<S19>/Product2'
  //   Product: '<S19>/Product3'
  //   Sum: '<S19>/Sum'
  //   UnaryMinus: '<S1>/Unary Minus'
  //   UnaryMinus: '<S1>/Unary Minus1'
  //   UnaryMinus: '<S1>/Unary Minus2'

  localB->rtb_Gain4_idx_2 = (((localB->Product2_d * -localB->Sum_f -
    localB->UnaryMinus1 * -localB->Sum_b) + localB->Sum_m * localB->Sum_a) +
    localB->Sum_d * -localB->Sum) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator4_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
  localDW->Memory3_PreviousInput[2] = localB->rtb_Gain4_idx_2 +
    localDW->DiscreteTimeIntegrator4_DSTATE[2];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' incorporates:
  //   Product: '<S20>/Product'
  //   Product: '<S20>/Product1'
  //   Product: '<S20>/Product2'
  //   Product: '<S20>/Product3'
  //   Sum: '<S20>/Sum'
  //   UnaryMinus: '<S1>/Unary Minus'
  //   UnaryMinus: '<S1>/Unary Minus1'
  //   UnaryMinus: '<S1>/Unary Minus2'

  localB->Sum_a = (((localB->Product2_d * -localB->Sum_b + localB->UnaryMinus1 *
                     -localB->Sum_f) - localB->Sum_m * -localB->Sum) +
                   localB->Sum_d * localB->Sum_a) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator4_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
  localDW->Memory3_PreviousInput[3] = localB->Sum_a +
    localDW->DiscreteTimeIntegrator4_DSTATE[3];

  // Signum: '<Root>/Sign2' incorporates:
  //   Math: '<Root>/Power1'

  localB->Sum_m = localDW->Memory4_PreviousInput[0];
  if (rtIsNaN(localB->Sum_m)) {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = (rtNaN);
  } else if (localB->Sum_m < 0.0) {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = -1.0;
  } else {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = (localB->Sum_m > 0.0);
  }

  // Product: '<Root>/Product5' incorporates:
  //   Product: '<Root>/Product1'
  //   Signum: '<Root>/Sign2'

  localB->Sum_m = rtu_PX4Params_FxTDiffg_G2[0] * localB->rtb_Gain4_idx_3;

  // Abs: '<Root>/Abs2' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Abs: '<Root>/Abs3'
  //   Math: '<Root>/Power1'

  localB->Sum_d = fabs(localDW->Memory4_PreviousInput[0]);

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Abs: '<Root>/Abs3'
  //   Math: '<Root>/Power2'
  //   Math: '<Root>/Power7'
  //   Product: '<Root>/Product1'
  //   Product: '<Root>/Product5'
  //   Sum: '<Root>/Sum4'

  localB->Sum_m = (localB->Sum_m * rt_powd_snf(localB->Sum_d, localB->Sum1[0]) +
                   localB->Sum_m * rt_powd_snf(localB->Sum_d, localB->Sum2[0])) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator1_gainval;
  localB->Product2_d = localB->Sum_m;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
  localDW->DiscreteTimeIntegrator1_DSTATE[0] += localB->Sum_m;

  // Product: '<Root>/Product3' incorporates:
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'

  localB->rtb_Gain4_idx_3 *= rtu_PX4Params_FxTDiffg_G1[0];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Memory: '<Root>/Memory1'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Sum: '<Root>/Sum3'

  localB->rtb_Gain4_idx_3 = ((localB->rtb_Gain4_idx_3 * rt_powd_snf
    (localB->Sum_d, rtu_PX4Params_FxTDiffg_lam1[0]) +
    localDW->Memory1_PreviousInput[0]) + localB->rtb_Gain4_idx_3 * rt_powd_snf
    (localB->Sum_d, rtu_PX4Params_FxTDiffg_vrho1[0])) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator3_gainval;

  // Product: '<Root>/Product3'
  localB->Product8[0] = localB->rtb_Gain4_idx_3;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->Memory4_PreviousInput[0] = localDW->DiscreteTimeIntegrator3_DSTATE[0]
    + localB->rtb_Gain4_idx_3;

  // Signum: '<Root>/Sign3'
  if (p) {
    localB->rtb_Cv_m = (rtNaN);
  } else if (localB->Sum < 0.0) {
    localB->rtb_Cv_m = -1.0;
  } else {
    localB->rtb_Cv_m = (localB->Sum > 0.0);
  }

  // Product: '<Root>/Product8' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product9'
  //   Signum: '<Root>/Sign3'

  localB->Sum_d = rtu_PX4Params_FxTDiffg_G2[3] * localB->rtb_Cv_m;
  localB->Sum = localB->Sum_d * rt_powd_snf(localB->absx, localB->Sum1[3]);

  // Product: '<Root>/Product9' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Math: '<Root>/Power6'

  localB->absx = localB->Sum_d * rt_powd_snf(localB->absx, localB->Sum2[3]);

  // Signum: '<Root>/Sign2' incorporates:
  //   Math: '<Root>/Power1'

  localB->Sum_m = localDW->Memory4_PreviousInput[1];
  if (rtIsNaN(localB->Sum_m)) {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = (rtNaN);
  } else if (localB->Sum_m < 0.0) {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = -1.0;
  } else {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = (localB->Sum_m > 0.0);
  }

  // Product: '<Root>/Product5' incorporates:
  //   Product: '<Root>/Product1'
  //   Signum: '<Root>/Sign2'

  localB->Sum_m = rtu_PX4Params_FxTDiffg_G2[1] * localB->rtb_Gain4_idx_3;

  // Abs: '<Root>/Abs2' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Abs: '<Root>/Abs3'
  //   Math: '<Root>/Power1'

  localB->Sum_d = fabs(localDW->Memory4_PreviousInput[1]);

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Abs: '<Root>/Abs3'
  //   Math: '<Root>/Power2'
  //   Math: '<Root>/Power7'
  //   Product: '<Root>/Product1'
  //   Product: '<Root>/Product5'
  //   Sum: '<Root>/Sum4'

  localB->Sum_m = (localB->Sum_m * rt_powd_snf(localB->Sum_d, localB->Sum1[1]) +
                   localB->Sum_m * rt_powd_snf(localB->Sum_d, localB->Sum2[1])) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator1_gainval;
  localB->UnaryMinus1 = localB->Sum_m;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
  localDW->DiscreteTimeIntegrator1_DSTATE[1] += localB->Sum_m;

  // Product: '<Root>/Product3' incorporates:
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'

  localB->rtb_Gain4_idx_3 *= rtu_PX4Params_FxTDiffg_G1[1];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Memory: '<Root>/Memory1'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Sum: '<Root>/Sum3'

  localB->rtb_Gain4_idx_3 = ((localB->rtb_Gain4_idx_3 * rt_powd_snf
    (localB->Sum_d, rtu_PX4Params_FxTDiffg_lam1[1]) +
    localDW->Memory1_PreviousInput[1]) + localB->rtb_Gain4_idx_3 * rt_powd_snf
    (localB->Sum_d, rtu_PX4Params_FxTDiffg_vrho1[1])) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator3_gainval;

  // Product: '<Root>/Product3'
  localB->Product8[1] = localB->rtb_Gain4_idx_3;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->Memory4_PreviousInput[1] = localDW->DiscreteTimeIntegrator3_DSTATE[1]
    + localB->rtb_Gain4_idx_3;

  // Signum: '<Root>/Sign3'
  if (tmp) {
    localB->rtb_Cv_m = (rtNaN);
  } else if (localB->Sum_f < 0.0) {
    localB->rtb_Cv_m = -1.0;
  } else {
    localB->rtb_Cv_m = (localB->Sum_f > 0.0);
  }

  // Product: '<Root>/Product8' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product9'
  //   Signum: '<Root>/Sign3'

  localB->Sum_d = rtu_PX4Params_FxTDiffg_G2[4] * localB->rtb_Cv_m;
  localB->Sum_f = localB->Sum_d * rt_powd_snf(localB->Product1_c, localB->Sum1[4]);

  // Product: '<Root>/Product9' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Math: '<Root>/Power6'

  localB->Product1_c = localB->Sum_d * rt_powd_snf(localB->Product1_c,
    localB->Sum2[4]);

  // Signum: '<Root>/Sign2' incorporates:
  //   Math: '<Root>/Power1'

  localB->Sum_m = localDW->Memory4_PreviousInput[2];
  if (rtIsNaN(localB->Sum_m)) {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = (rtNaN);
  } else if (localB->Sum_m < 0.0) {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = -1.0;
  } else {
    // Signum: '<Root>/Sign'
    localB->rtb_Gain4_idx_3 = (localB->Sum_m > 0.0);
  }

  // Product: '<Root>/Product5' incorporates:
  //   Product: '<Root>/Product1'
  //   Signum: '<Root>/Sign2'

  localB->Sum_m = rtu_PX4Params_FxTDiffg_G2[2] * localB->rtb_Gain4_idx_3;

  // Abs: '<Root>/Abs2' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Abs: '<Root>/Abs3'
  //   Math: '<Root>/Power1'

  localB->Sum_d = fabs(localDW->Memory4_PreviousInput[2]);

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Abs: '<Root>/Abs2'
  //   Abs: '<Root>/Abs3'
  //   Math: '<Root>/Power2'
  //   Math: '<Root>/Power7'
  //   Product: '<Root>/Product1'
  //   Product: '<Root>/Product5'
  //   Sum: '<Root>/Sum4'

  localB->Sum_m = (localB->Sum_m * rt_powd_snf(localB->Sum_d, localB->Sum1[2]) +
                   localB->Sum_m * rt_powd_snf(localB->Sum_d, localB->Sum2[2])) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator1_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
  localDW->DiscreteTimeIntegrator1_DSTATE[2] += localB->Sum_m;

  // Product: '<Root>/Product3' incorporates:
  //   Product: '<Root>/Product4'
  //   Signum: '<Root>/Sign'

  localB->rtb_Gain4_idx_3 *= rtu_PX4Params_FxTDiffg_G1[2];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' incorporates:
  //   Abs: '<Root>/Abs'
  //   Abs: '<Root>/Abs1'
  //   Math: '<Root>/Power'
  //   Math: '<Root>/Power1'
  //   Memory: '<Root>/Memory1'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product4'
  //   Sum: '<Root>/Sum3'

  localB->rtb_Gain4_idx_3 = ((localB->rtb_Gain4_idx_3 * rt_powd_snf
    (localB->Sum_d, rtu_PX4Params_FxTDiffg_lam1[2]) +
    localDW->Memory1_PreviousInput[2]) + localB->rtb_Gain4_idx_3 * rt_powd_snf
    (localB->Sum_d, rtu_PX4Params_FxTDiffg_vrho1[2])) *
    FxtD_Quaternion_P.DiscreteTimeIntegrator3_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->Memory4_PreviousInput[2] = localDW->DiscreteTimeIntegrator3_DSTATE[2]
    + localB->rtb_Gain4_idx_3;

  // Signum: '<Root>/Sign3'
  if (tmp_0) {
    localB->rtb_Cv_m = (rtNaN);
  } else if (localB->Sum_b < 0.0) {
    localB->rtb_Cv_m = -1.0;
  } else {
    localB->rtb_Cv_m = (localB->Sum_b > 0.0);
  }

  // Product: '<Root>/Product8' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Math: '<Root>/Power5'
  //   Product: '<Root>/Product9'
  //   Signum: '<Root>/Sign3'

  localB->Sum_d = rtu_PX4Params_FxTDiffg_G2[5] * localB->rtb_Cv_m;
  localB->Sum_b = localB->Sum_d * rt_powd_snf(localB->Product3_eu, localB->Sum1
    [5]);

  // Product: '<Root>/Product9' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Math: '<Root>/Power6'

  localB->Product3_eu = localB->Sum_d * rt_powd_snf(localB->Product3_eu,
    localB->Sum2[5]);
  for (c_k = 0; c_k < 3; c_k++) {
    // Product: '<Root>/Matrix Multiply3'
    localB->Sum_d = localB->Cv[c_k];
    localB->rtb_Cv_c = localB->Sum_d * localB->Sum;

    // Product: '<Root>/Matrix Multiply4'
    localB->rtb_Cv_m = localB->Sum_d * localB->absx;

    // Product: '<Root>/Matrix Multiply3'
    localB->Sum_d = localB->Cv[c_k + 3];
    localB->rtb_Cv_c += localB->Sum_d * localB->Sum_f;

    // Product: '<Root>/Matrix Multiply4'
    localB->rtb_Cv_m += localB->Sum_d * localB->Product1_c;

    // Product: '<Root>/Matrix Multiply3'
    localB->Sum_d = localB->Cv[c_k + 6];

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
    //   Product: '<Root>/Matrix Multiply3'
    //   Product: '<Root>/Matrix Multiply4'
    //   Sum: '<Root>/Sum11'

    localB->Sum_d = ((localB->Sum_d * localB->Sum_b + localB->rtb_Cv_c) +
                     (localB->Sum_d * localB->Product3_eu + localB->rtb_Cv_m)) *
      FxtD_Quaternion_P.DiscreteTimeIntegrator2_gainval;
    localB->rtb_Sum4_tmp[c_k] = localB->Sum_d;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
    localDW->Memory2_PreviousInput[c_k] =
      localDW->DiscreteTimeIntegrator2_DSTATE[c_k] + localB->Sum_d;
  }

  // Constant: '<Root>/Constant5'
  for (c_k = 0; c_k < 6; c_k++) {
    // Constant: '<Root>/Constant5'
    rty_state_hat_pos_ddot_hat[c_k] = FxtD_Quaternion_P.Constant5_Value[c_k];
  }

  // End of Constant: '<Root>/Constant5'

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
  localDW->DiscreteTimeIntegrator4_DSTATE[0] = localB->rtb_Gain4_idx_0 +
    localDW->Memory3_PreviousInput[0];
  localDW->DiscreteTimeIntegrator4_DSTATE[1] = localB->rtb_Gain4_idx_1 +
    localDW->Memory3_PreviousInput[1];
  localDW->DiscreteTimeIntegrator4_DSTATE[2] = localB->rtb_Gain4_idx_2 +
    localDW->Memory3_PreviousInput[2];
  localDW->DiscreteTimeIntegrator4_DSTATE[3] = localB->Sum_a +
    localDW->Memory3_PreviousInput[3];

  // Update for Memory: '<Root>/Memory1' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'

  localDW->Memory1_PreviousInput[0] = localDW->DiscreteTimeIntegrator1_DSTATE[0];

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Memory: '<Root>/Memory1'

  localDW->DiscreteTimeIntegrator1_DSTATE[0] += localB->Product2_d;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->DiscreteTimeIntegrator3_DSTATE[0] = localDW->Memory4_PreviousInput[0]
    + localB->Product8[0];

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  localDW->DiscreteTimeIntegrator2_DSTATE[0] = localDW->Memory2_PreviousInput[0]
    + localB->rtb_Sum4_tmp[0];

  // Update for Memory: '<Root>/Memory1' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'

  localDW->Memory1_PreviousInput[1] = localDW->DiscreteTimeIntegrator1_DSTATE[1];

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Memory: '<Root>/Memory1'

  localDW->DiscreteTimeIntegrator1_DSTATE[1] += localB->UnaryMinus1;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->DiscreteTimeIntegrator3_DSTATE[1] = localDW->Memory4_PreviousInput[1]
    + localB->Product8[1];

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  localDW->DiscreteTimeIntegrator2_DSTATE[1] = localDW->Memory2_PreviousInput[1]
    + localB->rtb_Sum4_tmp[1];

  // Update for Memory: '<Root>/Memory1' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'

  localDW->Memory1_PreviousInput[2] = localDW->DiscreteTimeIntegrator1_DSTATE[2];

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
  //   Memory: '<Root>/Memory1'

  localDW->DiscreteTimeIntegrator1_DSTATE[2] += localB->Sum_m;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->DiscreteTimeIntegrator3_DSTATE[2] = localDW->Memory4_PreviousInput[2]
    + localB->rtb_Gain4_idx_3;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  localDW->DiscreteTimeIntegrator2_DSTATE[2] = localDW->Memory2_PreviousInput[2]
    + localB->rtb_Sum4_tmp[2];
}

// Model initialize function
void FxtD_Quaternion_initialize(const char_T **rt_errorStatus,
  RT_MODEL_FxtD_Quaternion_T *const FxtD_Quaternion_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  FxtD_Quaternion_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_FxtD_Quaternion_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_FxtD_Quaternion_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_FxtD_Quaternion_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_FxtD_Quaternion_T::setErrorStatus(const char_T* const aErrorStatus)
  const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
