//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: FxTESO_Quaternion.cpp
//
// Code generated for Simulink model 'FxTESO_Quaternion'.
//
// Model version                  : 1.48
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:26 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FxTESO_Quaternion.h"
#include "rtwtypes.h"
#include "FxTESO_Quaternion_private.h"
#include <string.h>
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

P_FxTESO_Quaternion_T FxTESO_Quaternion_P = {
  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<Root>/Memory1'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Memory4'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Constant1'

  { 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Memory5'

  { 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Memory2'

  { 0.0, 0.0, 0.0 },

  // Expression: [0; 0; -9.81]
  //  Referenced by: '<Root>/Memory6'

  { 0.0, 0.0, -9.81 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Memory3'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Constant3'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.5
  //  Referenced by: '<Root>/Gain14'

  0.5,

  // Expression: 0
  //  Referenced by: '<Root>/Constant13'

  0.0,

  // Expression: 2
  //  Referenced by: '<Root>/Constant5'

  2.0,

  // Expression: 1/3
  //  Referenced by: '<Root>/Gain13'

  0.33333333333333331,

  // Expression: 2
  //  Referenced by: '<Root>/Constant12'

  2.0,

  // Expression: 1/3
  //  Referenced by: '<Root>/Gain12'

  0.33333333333333331,

  // Computed Parameter: DiscreteTimeIntegrator2_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator2'

  0.002,

  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator2'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<Root>/Constant6'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<Root>/Gain5'

  0.5,

  // Expression: 1
  //  Referenced by: '<Root>/Constant7'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<Root>/Gain6'

  0.5,

  // Computed Parameter: DiscreteTimeIntegrator4_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator4'

  0.002,

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator4'

  { 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<Root>/Constant2'

  2.0,

  // Expression: 1/3
  //  Referenced by: '<Root>/Gain3'

  0.33333333333333331,

  // Expression: 2
  //  Referenced by: '<Root>/Constant4'

  2.0,

  // Expression: 1/3
  //  Referenced by: '<Root>/Gain4'

  0.33333333333333331,

  // Computed Parameter: DiscreteTimeIntegrator3_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator3'

  0.002,

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator3'

  { 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator5_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator5'

  0.002,

  // Expression: [0; 0; -9.81]
  //  Referenced by: '<Root>/Discrete-Time Integrator5'

  { 0.0, 0.0, -9.81 },

  // Expression: 1
  //  Referenced by: '<Root>/Constant15'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<Root>/Gain15'

  0.5,

  // Expression: 1
  //  Referenced by: '<Root>/Constant14'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<Root>/Gain16'

  0.5,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator1'

  0.002,

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator1'

  { 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.002,

  // Expression: [0; 0; 0]
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  { 0.0, 0.0, 0.0 }
};

// Forward declaration for local functions
static real_T FxTESO_Quater_xzlangeM_CmZ8yEA8(const real_T x[9],
  B_FxTESO_Quaternion_c_T *localB);
static void FxTESO_Quatern_xzlascl_G6oWZyOe(real_T cfrom, real_T cto, real_T A[9],
  B_FxTESO_Quaternion_c_T *localB);
static real_T FxTESO_Quaternio_xnrm2_lYZMmlSm(int32_T n, const real_T x[9],
  int32_T ix0, B_FxTESO_Quaternion_c_T *localB);
static real_T FxTESO_Quaternio_xnrm2_pXv7PuuY(const real_T x[3], int32_T ix0,
  B_FxTESO_Quaternion_c_T *localB);
static void FxTESO_Quatern_xzlascl_ftGcEjOL(real_T cfrom, real_T cto, real_T A[3],
  B_FxTESO_Quaternion_c_T *localB);
static void FxTESO_Quaternio_xrotg_QLPrMQ5c(real_T *a, real_T *b, real_T *c,
  real_T *s, B_FxTESO_Quaternion_c_T *localB);
static void FxTESO_Quaternion_xrot_PLEUrKWS(real_T x[9], int32_T ix0, int32_T
  iy0, real_T c, real_T s, B_FxTESO_Quaternion_c_T *localB);
static void FxTESO_Quaternion_svd_60uAVgXi(const real_T A[9], real_T U[9],
  real_T s[3], real_T V[9], B_FxTESO_Quaternion_c_T *localB);

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
static real_T FxTESO_Quater_xzlangeM_CmZ8yEA8(const real_T x[9],
  B_FxTESO_Quaternion_c_T *localB)
{
  real_T y;
  int32_T k;
  boolean_T exitg1;
  y = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    localB->absxk_l = fabs(x[k]);
    if (rtIsNaN(localB->absxk_l)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (localB->absxk_l > y) {
        y = localB->absxk_l;
      }

      k++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
static void FxTESO_Quatern_xzlascl_G6oWZyOe(real_T cfrom, real_T cto, real_T A[9],
  B_FxTESO_Quaternion_c_T *localB)
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

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
static real_T FxTESO_Quaternio_xnrm2_lYZMmlSm(int32_T n, const real_T x[9],
  int32_T ix0, B_FxTESO_Quaternion_c_T *localB)
{
  real_T y;
  int32_T kend;
  y = 0.0;
  localB->scale_g = 3.3121686421112381E-170;
  kend = ix0 + n;
  for (int32_T k = ix0; k < kend; k++) {
    localB->absxk = fabs(x[k - 1]);
    if (localB->absxk > localB->scale_g) {
      localB->t = localB->scale_g / localB->absxk;
      y = y * localB->t * localB->t + 1.0;
      localB->scale_g = localB->absxk;
    } else {
      localB->t = localB->absxk / localB->scale_g;
      y += localB->t * localB->t;
    }
  }

  return localB->scale_g * sqrt(y);
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
static real_T FxTESO_Quaternio_xnrm2_pXv7PuuY(const real_T x[3], int32_T ix0,
  B_FxTESO_Quaternion_c_T *localB)
{
  real_T y;
  y = 0.0;
  localB->scale_m = 3.3121686421112381E-170;
  for (int32_T k = ix0; k <= ix0 + 1; k++) {
    localB->absxk_n = fabs(x[k - 1]);
    if (localB->absxk_n > localB->scale_m) {
      localB->t_p = localB->scale_m / localB->absxk_n;
      y = y * localB->t_p * localB->t_p + 1.0;
      localB->scale_m = localB->absxk_n;
    } else {
      localB->t_p = localB->absxk_n / localB->scale_m;
      y += localB->t_p * localB->t_p;
    }
  }

  return localB->scale_m * sqrt(y);
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
static void FxTESO_Quatern_xzlascl_ftGcEjOL(real_T cfrom, real_T cto, real_T A[3],
  B_FxTESO_Quaternion_c_T *localB)
{
  boolean_T notdone;
  localB->cfromc_p = cfrom;
  localB->ctoc_c = cto;
  notdone = true;
  while (notdone) {
    real_T mul;
    localB->cfrom1_f = localB->cfromc_p * 2.0041683600089728E-292;
    localB->cto1_g = localB->ctoc_c / 4.9896007738368E+291;
    if ((fabs(localB->cfrom1_f) > fabs(localB->ctoc_c)) && (localB->ctoc_c !=
         0.0)) {
      mul = 2.0041683600089728E-292;
      localB->cfromc_p = localB->cfrom1_f;
    } else if (fabs(localB->cto1_g) > fabs(localB->cfromc_p)) {
      mul = 4.9896007738368E+291;
      localB->ctoc_c = localB->cto1_g;
    } else {
      mul = localB->ctoc_c / localB->cfromc_p;
      notdone = false;
    }

    A[0] *= mul;
    A[1] *= mul;
    A[2] *= mul;
  }
}

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
static void FxTESO_Quaternio_xrotg_QLPrMQ5c(real_T *a, real_T *b, real_T *c,
  real_T *s, B_FxTESO_Quaternion_c_T *localB)
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

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
static void FxTESO_Quaternion_xrot_PLEUrKWS(real_T x[9], int32_T ix0, int32_T
  iy0, real_T c, real_T s, B_FxTESO_Quaternion_c_T *localB)
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

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
static void FxTESO_Quaternion_svd_60uAVgXi(const real_T A[9], real_T U[9],
  real_T s[3], real_T V[9], B_FxTESO_Quaternion_c_T *localB)
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
  localB->anrm = FxTESO_Quater_xzlangeM_CmZ8yEA8(A, localB);
  localB->cscale = localB->anrm;
  if ((localB->anrm > 0.0) && (localB->anrm < 6.7178761075670888E-139)) {
    doscale = true;
    localB->cscale = 6.7178761075670888E-139;
    FxTESO_Quatern_xzlascl_G6oWZyOe(localB->anrm, localB->cscale, localB->b_A,
      localB);
  } else if (localB->anrm > 1.4885657073574029E+138) {
    doscale = true;
    localB->cscale = 1.4885657073574029E+138;
    FxTESO_Quatern_xzlascl_G6oWZyOe(localB->anrm, localB->cscale, localB->b_A,
      localB);
  }

  for (m = 0; m < 2; m++) {
    qp1 = m + 2;
    qs = 3 * m + m;
    qq = qs + 1;
    apply_transform = false;
    localB->nrm = FxTESO_Quaternio_xnrm2_lYZMmlSm(3 - m, localB->b_A, qs + 1,
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
      localB->nrm = FxTESO_Quaternio_xnrm2_pXv7PuuY(localB->e, 2, localB);
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
        FxTESO_Quaternio_xrotg_QLPrMQ5c(&localB->b_s[qs - 1], &localB->rt,
          &localB->r, &localB->sqds, localB);
        if (qs > qq + 1) {
          localB->rt = -localB->sqds * localB->e[0];
          localB->e[0] *= localB->r;
        }

        FxTESO_Quaternion_xrot_PLEUrKWS(localB->Vf, 3 * (qs - 1) + 1, 3 * (m + 1)
          + 1, localB->r, localB->sqds, localB);
      }
      break;

     case 2:
      localB->rt = localB->e[qq - 1];
      localB->e[qq - 1] = 0.0;
      for (qs = qq + 1; qs <= m + 2; qs++) {
        FxTESO_Quaternio_xrotg_QLPrMQ5c(&localB->b_s[qs - 1], &localB->rt,
          &localB->sqds, &localB->smm1, localB);
        localB->r = localB->e[qs - 1];
        localB->rt = -localB->smm1 * localB->r;
        localB->e[qs - 1] = localB->r * localB->sqds;
        FxTESO_Quaternion_xrot_PLEUrKWS(U, 3 * (qs - 1) + 1, 3 * (qq - 1) + 1,
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
        FxTESO_Quaternio_xrotg_QLPrMQ5c(&localB->rt, &localB->r, &localB->sqds,
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
        FxTESO_Quaternion_xrot_PLEUrKWS(localB->Vf, qs, qjj, localB->sqds,
          localB->smm1, localB);
        localB->b_s[e_k - 1] = localB->emm1 * localB->sqds + localB->r *
          localB->smm1;
        FxTESO_Quaternio_xrotg_QLPrMQ5c(&localB->b_s[e_k - 1], &localB->rt,
          &localB->sqds, &localB->smm1, localB);
        localB->emm1 = localB->e[e_k - 1];
        localB->rt = localB->emm1 * localB->sqds + localB->smm1 * localB->
          b_s[e_k];
        localB->b_s[e_k] = localB->emm1 * -localB->smm1 + localB->sqds *
          localB->b_s[e_k];
        localB->r = localB->smm1 * localB->e[e_k];
        localB->e[e_k] *= localB->sqds;
        FxTESO_Quaternion_xrot_PLEUrKWS(U, qs, qjj, localB->sqds, localB->smm1,
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
    FxTESO_Quatern_xzlascl_ftGcEjOL(localB->cscale, localB->anrm, s, localB);
  }

  for (m = 0; m < 3; m++) {
    V[3 * m] = localB->Vf[3 * m];
    qp1 = 3 * m + 1;
    V[qp1] = localB->Vf[qp1];
    qp1 = 3 * m + 2;
    V[qp1] = localB->Vf[qp1];
  }
}

// System initialize for referenced model: 'FxTESO_Quaternion'
void FxTESO_Quaternion_Init(DW_FxTESO_Quaternion_f_T *localDW)
{
  // InitializeConditions for Memory: '<Root>/Memory1'
  localDW->Memory1_PreviousInput[0] =
    FxTESO_Quaternion_P.Memory1_InitialCondition[0];
  localDW->Memory1_PreviousInput[1] =
    FxTESO_Quaternion_P.Memory1_InitialCondition[1];
  localDW->Memory1_PreviousInput[2] =
    FxTESO_Quaternion_P.Memory1_InitialCondition[2];
  localDW->Memory1_PreviousInput[3] =
    FxTESO_Quaternion_P.Memory1_InitialCondition[3];

  // InitializeConditions for Memory: '<Root>/Memory4'
  localDW->Memory4_PreviousInput[0] =
    FxTESO_Quaternion_P.Memory4_InitialCondition[0];

  // InitializeConditions for Memory: '<Root>/Memory5'
  localDW->Memory5_PreviousInput[0] =
    FxTESO_Quaternion_P.Memory5_InitialCondition[0];

  // InitializeConditions for Memory: '<Root>/Memory2'
  localDW->Memory2_PreviousInput[0] =
    FxTESO_Quaternion_P.Memory2_InitialCondition[0];

  // InitializeConditions for Memory: '<Root>/Memory6'
  localDW->Memory6_PreviousInput[0] =
    FxTESO_Quaternion_P.Memory6_InitialCondition[0];

  // InitializeConditions for Memory: '<Root>/Memory3'
  localDW->Memory3_PreviousInput[0] =
    FxTESO_Quaternion_P.Memory3_InitialCondition[0];

  // InitializeConditions for Memory: '<Root>/Memory4'
  localDW->Memory4_PreviousInput[1] =
    FxTESO_Quaternion_P.Memory4_InitialCondition[1];

  // InitializeConditions for Memory: '<Root>/Memory5'
  localDW->Memory5_PreviousInput[1] =
    FxTESO_Quaternion_P.Memory5_InitialCondition[1];

  // InitializeConditions for Memory: '<Root>/Memory2'
  localDW->Memory2_PreviousInput[1] =
    FxTESO_Quaternion_P.Memory2_InitialCondition[1];

  // InitializeConditions for Memory: '<Root>/Memory6'
  localDW->Memory6_PreviousInput[1] =
    FxTESO_Quaternion_P.Memory6_InitialCondition[1];

  // InitializeConditions for Memory: '<Root>/Memory3'
  localDW->Memory3_PreviousInput[1] =
    FxTESO_Quaternion_P.Memory3_InitialCondition[1];

  // InitializeConditions for Memory: '<Root>/Memory4'
  localDW->Memory4_PreviousInput[2] =
    FxTESO_Quaternion_P.Memory4_InitialCondition[2];

  // InitializeConditions for Memory: '<Root>/Memory5'
  localDW->Memory5_PreviousInput[2] =
    FxTESO_Quaternion_P.Memory5_InitialCondition[2];

  // InitializeConditions for Memory: '<Root>/Memory2'
  localDW->Memory2_PreviousInput[2] =
    FxTESO_Quaternion_P.Memory2_InitialCondition[2];

  // InitializeConditions for Memory: '<Root>/Memory6'
  localDW->Memory6_PreviousInput[2] =
    FxTESO_Quaternion_P.Memory6_InitialCondition[2];

  // InitializeConditions for Memory: '<Root>/Memory3'
  localDW->Memory3_PreviousInput[2] =
    FxTESO_Quaternion_P.Memory3_InitialCondition[2];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' 
  localDW->DiscreteTimeIntegrator2_DSTATE[0] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator2_IC[0];
  localDW->DiscreteTimeIntegrator2_DSTATE[1] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator2_IC[1];
  localDW->DiscreteTimeIntegrator2_DSTATE[2] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator2_IC[2];
  localDW->DiscreteTimeIntegrator2_DSTATE[3] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator2_IC[3];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' 
  localDW->DiscreteTimeIntegrator4_DSTATE[0] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator4_IC[0];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' 
  localDW->DiscreteTimeIntegrator3_DSTATE[0] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator3_IC[0];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' 
  localDW->DiscreteTimeIntegrator5_DSTATE[0] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator5_IC[0];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' 
  localDW->DiscreteTimeIntegrator1_DSTATE[0] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator1_IC[0];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  localDW->DiscreteTimeIntegrator_DSTATE[0] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator_IC[0];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' 
  localDW->DiscreteTimeIntegrator4_DSTATE[1] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator4_IC[1];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' 
  localDW->DiscreteTimeIntegrator3_DSTATE[1] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator3_IC[1];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' 
  localDW->DiscreteTimeIntegrator5_DSTATE[1] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator5_IC[1];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' 
  localDW->DiscreteTimeIntegrator1_DSTATE[1] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator1_IC[1];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  localDW->DiscreteTimeIntegrator_DSTATE[1] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator_IC[1];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' 
  localDW->DiscreteTimeIntegrator4_DSTATE[2] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator4_IC[2];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' 
  localDW->DiscreteTimeIntegrator3_DSTATE[2] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator3_IC[2];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' 
  localDW->DiscreteTimeIntegrator5_DSTATE[2] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator5_IC[2];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' 
  localDW->DiscreteTimeIntegrator1_DSTATE[2] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator1_IC[2];

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  localDW->DiscreteTimeIntegrator_DSTATE[2] =
    FxTESO_Quaternion_P.DiscreteTimeIntegrator_IC[2];
}

// Output and update for referenced model: 'FxTESO_Quaternion'
void FxTESO_Quaternion(const real_T rtu_pos[3], const real_T
  rtu_PX4Params_MCg_MCData[5], const real_T rtu_PX4Params_FxTQESOg_eps_1[6],
  const real_T rtu_PX4Params_FxTQESOg_eps_2[6], const real_T
  rtu_PX4Params_FxTQESOg_eps_3[6], const real_T rtu_PX4Params_FxTQESOg_eps_4[6],
  const real_T rtu_PX4Params_FxTQESOg_mu_1[6], const real_T
  rtu_PX4Params_FxTQESOg_mu_2[6], const real_T rtu_PX4Params_FxTQESOg_mu_3[6],
  const real_T rtu_PX4Params_FxTQESOg_alpha_q[6], const real_T
  rtu_PX4Params_FxTQESOg_beta_q[6], const real_T rtu_Fu_Fu[6], const real_T
  rtu_quaternion[4], real_T rty_state_hat_pos_hat[6], real_T
  rty_state_hat_pos_dot_hat[6], real_T rty_state_hat_pos_ddot_hat[6], real_T
  rty_state_hat_e_hat[6], real_T rty_state_hat_q_hat[4], real_T
  rty_state_hat_q_tilde[4], B_FxTESO_Quaternion_c_T *localB,
  DW_FxTESO_Quaternion_f_T *localDW)
{
  int32_T ar;
  int32_T b;
  int32_T br;
  int32_T exponent;
  int32_T p2;
  int32_T p3;
  int32_T r;
  boolean_T exitg1;
  boolean_T p;

  // MATLAB Function: '<Root>/MATLAB Function'
  memset(&localB->x[0], 0, 9U * sizeof(real_T));
  localB->x[0] = rtu_PX4Params_MCg_MCData[1];
  localB->x[4] = rtu_PX4Params_MCg_MCData[2];
  localB->x[8] = rtu_PX4Params_MCg_MCData[3];
  memcpy(&localB->Cv[0], &localB->x[0], 9U * sizeof(real_T));
  p2 = 3;
  p3 = 6;
  localB->Cv[1] /= localB->Cv[0];
  localB->Cv[2] /= localB->Cv[0];
  localB->Cv[4] -= localB->Cv[1] * localB->Cv[3];
  localB->Cv[5] -= localB->Cv[2] * localB->Cv[3];
  localB->Cv[7] -= localB->Cv[1] * localB->Cv[6];
  localB->Cv[8] -= localB->Cv[2] * localB->Cv[6];
  if (fabs(localB->Cv[5]) > fabs(localB->Cv[4])) {
    p2 = 6;
    p3 = 3;
    localB->t1 = localB->Cv[1];
    localB->Cv[1] = localB->Cv[2];
    localB->Cv[2] = localB->t1;
    localB->t1 = localB->Cv[4];
    localB->Cv[4] = localB->Cv[5];
    localB->Cv[5] = localB->t1;
    localB->t1 = localB->Cv[7];
    localB->Cv[7] = localB->Cv[8];
    localB->Cv[8] = localB->t1;
  }

  localB->Cv[5] /= localB->Cv[4];
  localB->Cv[8] -= localB->Cv[5] * localB->Cv[7];
  localB->t1 = (localB->Cv[1] * localB->Cv[5] - localB->Cv[2]) / localB->Cv[8];
  localB->t2 = -(localB->Cv[7] * localB->t1 + localB->Cv[1]) / localB->Cv[4];
  localB->J[0] = ((1.0 - localB->Cv[3] * localB->t2) - localB->Cv[6] *
                  localB->t1) / localB->Cv[0];
  localB->J[1] = localB->t2;
  localB->J[2] = localB->t1;
  localB->t1 = -localB->Cv[5] / localB->Cv[8];
  localB->t2 = (1.0 - localB->Cv[7] * localB->t1) / localB->Cv[4];
  localB->J[p2] = -(localB->Cv[3] * localB->t2 + localB->Cv[6] * localB->t1) /
    localB->Cv[0];
  localB->J[p2 + 1] = localB->t2;
  localB->J[p2 + 2] = localB->t1;
  localB->t1 = 1.0 / localB->Cv[8];
  localB->t2 = -localB->Cv[7] * localB->t1 / localB->Cv[4];
  localB->J[p3] = -(localB->Cv[3] * localB->t2 + localB->Cv[6] * localB->t1) /
    localB->Cv[0];
  localB->J[p3 + 1] = localB->t2;
  localB->J[p3 + 2] = localB->t1;

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // Sqrt: '<S31>/sqrt' incorporates:
  //   Memory: '<Root>/Memory1'
  //   Product: '<S32>/Product'
  //   Product: '<S32>/Product1'
  //   Product: '<S32>/Product2'
  //   Product: '<S32>/Product3'
  //   Sum: '<S32>/Sum'

  localB->t1 = sqrt(((localDW->Memory1_PreviousInput[0] *
                      localDW->Memory1_PreviousInput[0] +
                      localDW->Memory1_PreviousInput[1] *
                      localDW->Memory1_PreviousInput[1]) +
                     localDW->Memory1_PreviousInput[2] *
                     localDW->Memory1_PreviousInput[2]) +
                    localDW->Memory1_PreviousInput[3] *
                    localDW->Memory1_PreviousInput[3]);

  // Product: '<S11>/Product' incorporates:
  //   Memory: '<Root>/Memory1'

  localB->Product = localDW->Memory1_PreviousInput[0] / localB->t1;

  // Product: '<S11>/Product1' incorporates:
  //   Memory: '<Root>/Memory1'

  localB->Product1 = localDW->Memory1_PreviousInput[1] / localB->t1;

  // Product: '<S11>/Product2' incorporates:
  //   Memory: '<Root>/Memory1'

  localB->Product2 = localDW->Memory1_PreviousInput[2] / localB->t1;

  // Product: '<S11>/Product3' incorporates:
  //   Memory: '<Root>/Memory1'

  localB->Product3 = localDW->Memory1_PreviousInput[3] / localB->t1;

  // Sum: '<S28>/Sum' incorporates:
  //   Product: '<S28>/Product'
  //   Product: '<S28>/Product1'
  //   Product: '<S28>/Product2'
  //   Product: '<S28>/Product3'
  //   UnaryMinus: '<S6>/Unary Minus'
  //   UnaryMinus: '<S6>/Unary Minus1'
  //   UnaryMinus: '<S6>/Unary Minus2'

  localB->Sum = ((localB->Product * rtu_quaternion[1] + -localB->Product1 *
                  rtu_quaternion[0]) + -localB->Product2 * rtu_quaternion[3]) -
    -localB->Product3 * rtu_quaternion[2];

  // Sum: '<S29>/Sum' incorporates:
  //   Product: '<S29>/Product'
  //   Product: '<S29>/Product1'
  //   Product: '<S29>/Product2'
  //   Product: '<S29>/Product3'
  //   UnaryMinus: '<S6>/Unary Minus'
  //   UnaryMinus: '<S6>/Unary Minus1'
  //   UnaryMinus: '<S6>/Unary Minus2'

  localB->Sum_n = ((localB->Product * rtu_quaternion[2] - -localB->Product1 *
                    rtu_quaternion[3]) + -localB->Product2 * rtu_quaternion[0])
    + -localB->Product3 * rtu_quaternion[1];

  // Sum: '<S30>/Sum' incorporates:
  //   Product: '<S30>/Product'
  //   Product: '<S30>/Product1'
  //   Product: '<S30>/Product2'
  //   Product: '<S30>/Product3'
  //   UnaryMinus: '<S6>/Unary Minus'
  //   UnaryMinus: '<S6>/Unary Minus1'
  //   UnaryMinus: '<S6>/Unary Minus2'

  localB->Sum_f = ((localB->Product * rtu_quaternion[3] + -localB->Product1 *
                    rtu_quaternion[2]) - -localB->Product2 * rtu_quaternion[1])
    + -localB->Product3 * rtu_quaternion[0];

  // Sum: '<S27>/Sum' incorporates:
  //   Product: '<S27>/Product'
  //   Product: '<S27>/Product1'
  //   Product: '<S27>/Product2'
  //   Product: '<S27>/Product3'
  //   UnaryMinus: '<S6>/Unary Minus'
  //   UnaryMinus: '<S6>/Unary Minus1'
  //   UnaryMinus: '<S6>/Unary Minus2'

  localB->Sum_e = ((localB->Product * rtu_quaternion[0] - -localB->Product1 *
                    rtu_quaternion[1]) - -localB->Product2 * rtu_quaternion[2])
    - -localB->Product3 * rtu_quaternion[3];

  // SignalConversion generated from: '<S12>/ SFunction ' incorporates:
  //   MATLAB Function: '<Root>/calculateCvMatrix1'
  //   SignalConversion generated from: '<Root>/state_hat_Outport_1'

  rty_state_hat_q_tilde[0] = localB->Sum_e;
  rty_state_hat_q_tilde[1] = localB->Sum;
  rty_state_hat_q_tilde[2] = localB->Sum_n;
  rty_state_hat_q_tilde[3] = localB->Sum_f;

  // MATLAB Function: '<Root>/calculateCvMatrix1' incorporates:
  //   SignalConversion generated from: '<S12>/ SFunction '

  localB->x[0] = rty_state_hat_q_tilde[0] * 0.5;
  localB->x[3] = -rty_state_hat_q_tilde[3] * 0.5;
  localB->x[6] = rty_state_hat_q_tilde[2] * 0.5;
  localB->x[1] = rty_state_hat_q_tilde[3] * 0.5;
  localB->x[4] = rty_state_hat_q_tilde[0] * 0.5;
  localB->x[7] = -rty_state_hat_q_tilde[1] * 0.5;
  localB->x[2] = -rty_state_hat_q_tilde[2] * 0.5;
  localB->x[5] = rty_state_hat_q_tilde[1] * 0.5;
  localB->x[8] = rty_state_hat_q_tilde[0] * 0.5;
  p = true;
  for (p2 = 0; p2 < 9; p2++) {
    localB->Cv[p2] = 0.0;
    if (p) {
      localB->t1 = localB->x[p2];
      if (rtIsInf(localB->t1) || rtIsNaN(localB->t1)) {
        p = false;
      }
    }
  }

  if (!p) {
    for (p2 = 0; p2 < 9; p2++) {
      localB->Cv[p2] = (rtNaN);
    }
  } else {
    FxTESO_Quaternion_svd_60uAVgXi(localB->x, localB->U, localB->v, localB->V,
      localB);
    localB->t1 = fabs(localB->v[0]);
    if (rtIsInf(localB->t1) || rtIsNaN(localB->t1)) {
      localB->t1 = (rtNaN);
    } else if (localB->t1 < 4.4501477170144028E-308) {
      localB->t1 = 4.94065645841247E-324;
    } else {
      frexp(localB->t1, &exponent);
      localB->t1 = ldexp(1.0, exponent - 53);
    }

    localB->t1 *= 3.0;
    p2 = 0;
    exitg1 = false;
    while ((!exitg1) && (p2 < 3)) {
      if (rtIsInf(localB->v[p2]) || rtIsNaN(localB->v[p2])) {
        localB->t1 = 1.7976931348623157E+308;
        exitg1 = true;
      } else {
        p2++;
      }
    }

    r = -1;
    p2 = 0;
    while ((p2 < 3) && (localB->v[p2] > localB->t1)) {
      r++;
      p2++;
    }

    if (r + 1 > 0) {
      p3 = 1;
      for (p2 = 0; p2 <= r; p2++) {
        localB->t1 = 1.0 / localB->v[p2];
        for (exponent = p3; exponent <= p3 + 2; exponent++) {
          localB->V[exponent - 1] *= localB->t1;
        }

        p3 += 3;
      }

      for (p2 = 0; p2 <= 6; p2 += 3) {
        for (exponent = p2 + 1; exponent <= p2 + 3; exponent++) {
          localB->Cv[exponent - 1] = 0.0;
        }
      }

      br = 0;
      for (p2 = 0; p2 <= 6; p2 += 3) {
        ar = -1;
        br++;
        b = 3 * r + br;
        for (exponent = br; exponent <= b; exponent += 3) {
          for (p3 = p2 + 1; p3 <= p2 + 3; p3++) {
            localB->Cv[p3 - 1] += localB->V[(ar + p3) - p2] * localB->U[exponent
              - 1];
          }

          ar += 3;
        }
      }
    }
  }

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   MATLAB Function: '<S1>/Kronecker_product'
  //   SignalConversion generated from: '<S13>/ SFunction '

  rty_state_hat_q_hat[0] = localB->Product;
  rty_state_hat_q_hat[1] = localB->Product1;
  rty_state_hat_q_hat[2] = localB->Product2;
  rty_state_hat_q_hat[3] = localB->Product3;

  // MATLAB Function: '<S1>/Kronecker_product' incorporates:
  //   SignalConversion generated from: '<S13>/ SFunction '

  localB->rty_state_hat_q_hat[0] = rty_state_hat_q_hat[0];
  localB->rty_state_hat_q_hat[4] = -rty_state_hat_q_hat[1];
  localB->rty_state_hat_q_hat[8] = -rty_state_hat_q_hat[2];
  localB->rty_state_hat_q_hat[12] = -rty_state_hat_q_hat[3];
  localB->rty_state_hat_q_hat[1] = rty_state_hat_q_hat[1];
  localB->rty_state_hat_q_hat[5] = rty_state_hat_q_hat[0];
  localB->rty_state_hat_q_hat[9] = -rty_state_hat_q_hat[3];
  localB->rty_state_hat_q_hat[13] = rty_state_hat_q_hat[2];
  localB->rty_state_hat_q_hat[2] = rty_state_hat_q_hat[2];
  localB->rty_state_hat_q_hat[6] = rty_state_hat_q_hat[3];
  localB->rty_state_hat_q_hat[10] = rty_state_hat_q_hat[0];
  localB->rty_state_hat_q_hat[14] = -rty_state_hat_q_hat[1];
  localB->rty_state_hat_q_hat[3] = rty_state_hat_q_hat[3];
  localB->rty_state_hat_q_hat[7] = -rty_state_hat_q_hat[2];
  localB->rty_state_hat_q_hat[11] = rty_state_hat_q_hat[1];
  localB->rty_state_hat_q_hat[15] = rty_state_hat_q_hat[0];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant1'

  localB->Memory4_PreviousInput = localDW->Memory4_PreviousInput[0];
  rty_state_hat_pos_hat[0] = localB->Memory4_PreviousInput;
  rty_state_hat_pos_hat[3] = FxTESO_Quaternion_P.Constant1_Value[0];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1'
  rty_state_hat_pos_dot_hat[0] = localDW->Memory5_PreviousInput[0];
  rty_state_hat_pos_dot_hat[3] = localDW->Memory2_PreviousInput[0];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Memory: '<Root>/Memory6'

  rty_state_hat_pos_ddot_hat[0] = localDW->Memory6_PreviousInput[0];
  rty_state_hat_pos_ddot_hat[3] = localDW->Memory3_PreviousInput[0];

  // Sum: '<Root>/Sum8' incorporates:
  //   Product: '<Root>/Product13'

  localB->Memory4_PreviousInput = rtu_pos[0] - localB->Memory4_PreviousInput;
  localDW->Memory4_PreviousInput[0] = localB->Memory4_PreviousInput;

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant3'

  rty_state_hat_e_hat[0] = localB->Memory4_PreviousInput;
  rty_state_hat_e_hat[3] = FxTESO_Quaternion_P.Constant3_Value[0];

  // MATLAB Function: '<S1>/Kronecker_product'
  localB->t1 = rtu_Fu_Fu[0];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant1'

  localB->Memory4_PreviousInput = localDW->Memory4_PreviousInput[1];
  rty_state_hat_pos_hat[1] = localB->Memory4_PreviousInput;
  rty_state_hat_pos_hat[4] = FxTESO_Quaternion_P.Constant1_Value[1];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1'
  rty_state_hat_pos_dot_hat[1] = localDW->Memory5_PreviousInput[1];
  rty_state_hat_pos_dot_hat[4] = localDW->Memory2_PreviousInput[1];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Memory: '<Root>/Memory6'

  rty_state_hat_pos_ddot_hat[1] = localDW->Memory6_PreviousInput[1];
  rty_state_hat_pos_ddot_hat[4] = localDW->Memory3_PreviousInput[1];

  // Sum: '<Root>/Sum8' incorporates:
  //   Product: '<Root>/Product13'

  localB->Memory4_PreviousInput = rtu_pos[1] - localB->Memory4_PreviousInput;
  localDW->Memory4_PreviousInput[1] = localB->Memory4_PreviousInput;

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant3'

  rty_state_hat_e_hat[1] = localB->Memory4_PreviousInput;
  rty_state_hat_e_hat[4] = FxTESO_Quaternion_P.Constant3_Value[1];

  // MATLAB Function: '<S1>/Kronecker_product'
  localB->t2 = rtu_Fu_Fu[1];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant1'

  localB->Memory4_PreviousInput = localDW->Memory4_PreviousInput[2];
  rty_state_hat_pos_hat[2] = localB->Memory4_PreviousInput;
  rty_state_hat_pos_hat[5] = FxTESO_Quaternion_P.Constant1_Value[2];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1'
  rty_state_hat_pos_dot_hat[2] = localDW->Memory5_PreviousInput[2];
  rty_state_hat_pos_dot_hat[5] = localDW->Memory2_PreviousInput[2];

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Memory: '<Root>/Memory6'

  rty_state_hat_pos_ddot_hat[2] = localDW->Memory6_PreviousInput[2];
  rty_state_hat_pos_ddot_hat[5] = localDW->Memory3_PreviousInput[2];

  // Sum: '<Root>/Sum8' incorporates:
  //   Product: '<Root>/Product13'

  localB->Memory4_PreviousInput = rtu_pos[2] - localB->Memory4_PreviousInput;
  localDW->Memory4_PreviousInput[2] = localB->Memory4_PreviousInput;

  // SignalConversion generated from: '<Root>/state_hat_Outport_1' incorporates:
  //   Constant: '<Root>/Constant3'

  rty_state_hat_e_hat[2] = localB->Memory4_PreviousInput;
  rty_state_hat_e_hat[5] = FxTESO_Quaternion_P.Constant3_Value[2];

  // MATLAB Function: '<S1>/Kronecker_product'
  localB->Memory4_PreviousInput = rtu_Fu_Fu[2];
  for (p2 = 0; p2 < 4; p2++) {
    localB->r_g[p2] = ((localB->rty_state_hat_q_hat[p2 + 4] * localB->t1 +
                        localB->rty_state_hat_q_hat[p2] * 0.0) +
                       localB->rty_state_hat_q_hat[p2 + 8] * localB->t2) +
      localB->rty_state_hat_q_hat[p2 + 12] * localB->Memory4_PreviousInput;
  }

  // Gain: '<Root>/Gain14' incorporates:
  //   Product: '<S15>/Product'
  //   Product: '<S15>/Product1'
  //   Product: '<S15>/Product2'
  //   Product: '<S15>/Product3'
  //   Product: '<S16>/Product'
  //   Product: '<S16>/Product1'
  //   Product: '<S16>/Product2'
  //   Product: '<S16>/Product3'
  //   Product: '<S17>/Product'
  //   Product: '<S17>/Product1'
  //   Product: '<S17>/Product2'
  //   Product: '<S17>/Product3'
  //   Product: '<S18>/Product'
  //   Product: '<S18>/Product1'
  //   Product: '<S18>/Product2'
  //   Product: '<S18>/Product3'
  //   Sum: '<S15>/Sum'
  //   Sum: '<S16>/Sum'
  //   Sum: '<S17>/Sum'
  //   Sum: '<S18>/Sum'
  //   UnaryMinus: '<S4>/Unary Minus'
  //   UnaryMinus: '<S4>/Unary Minus1'
  //   UnaryMinus: '<S4>/Unary Minus2'

  localB->rtb_Gain14_idx_0 = (((localB->Product * localB->Sum_e -
    localB->Product1 * -localB->Sum) - localB->Product2 * -localB->Sum_n) -
    localB->Product3 * -localB->Sum_f) * FxTESO_Quaternion_P.Gain14_Gain;
  localB->rtb_Gain14_idx_1 = (((localB->Product * -localB->Sum +
    localB->Product1 * localB->Sum_e) + localB->Product2 * -localB->Sum_f) -
    localB->Product3 * -localB->Sum_n) * FxTESO_Quaternion_P.Gain14_Gain;
  localB->rtb_Gain14_idx_2 = (((localB->Product * -localB->Sum_n -
    localB->Product1 * -localB->Sum_f) + localB->Product2 * localB->Sum_e) +
    localB->Product3 * -localB->Sum) * FxTESO_Quaternion_P.Gain14_Gain;
  localB->rtb_Gain14_idx_3 = (((localB->Product * -localB->Sum_f +
    localB->Product1 * -localB->Sum_n) - localB->Product2 * -localB->Sum) +
    localB->Product3 * localB->Sum_e) * FxTESO_Quaternion_P.Gain14_Gain;

  // Signum: '<Root>/Sign15'
  if (rtIsNaN(localB->Sum)) {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[0] = (rtNaN);
  } else if (localB->Sum < 0.0) {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[0] = -1.0;
  } else {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[0] = (localB->Sum > 0.0);
  }

  if (rtIsNaN(localB->Sum_n)) {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[1] = (rtNaN);
  } else if (localB->Sum_n < 0.0) {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[1] = -1.0;
  } else {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[1] = (localB->Sum_n > 0.0);
  }

  if (rtIsNaN(localB->Sum_f)) {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[2] = (rtNaN);
  } else if (localB->Sum_f < 0.0) {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[2] = -1.0;
  } else {
    // Signum: '<Root>/Sign16' incorporates:
    //   Signum: '<Root>/Sign17'
    //   Signum: '<Root>/Sign18'
    //   Signum: '<Root>/Sign19'
    //   Signum: '<Root>/Sign20'
    //   Signum: '<Root>/Sign21'

    localB->v[2] = (localB->Sum_f > 0.0);
  }

  // Abs: '<Root>/Abs13' incorporates:
  //   Abs: '<Root>/Abs14'
  //   Abs: '<Root>/Abs15'
  //   Abs: '<Root>/Abs16'
  //   Abs: '<Root>/Abs17'
  //   Abs: '<Root>/Abs18'

  localB->t1 = fabs(localB->Sum);
  localB->Memory4_PreviousInput = localB->t1;

  // Product: '<Root>/Product1' incorporates:
  //   Abs: '<Root>/Abs13'
  //   Constant: '<Root>/Constant5'
  //   Gain: '<Root>/Gain13'
  //   Math: '<Root>/Power13'
  //   Signum: '<Root>/Sign15'
  //   Sum: '<Root>/Sum20'

  localB->Sum_gl = rt_powd_snf(localB->t1, (rtu_PX4Params_FxTQESOg_alpha_q[3] +
    FxTESO_Quaternion_P.Constant5_Value) * FxTESO_Quaternion_P.Gain13_Gain) *
    (localB->v[0] * rtu_PX4Params_FxTQESOg_eps_1[3]);

  // Product: '<Root>/Product14' incorporates:
  //   Abs: '<Root>/Abs14'
  //   Constant: '<Root>/Constant12'
  //   Gain: '<Root>/Gain12'
  //   Math: '<Root>/Power14'
  //   Signum: '<Root>/Sign15'
  //   Sum: '<Root>/Sum21'

  localB->Sum_k = rt_powd_snf(localB->t1, (rtu_PX4Params_FxTQESOg_beta_q[3] +
    FxTESO_Quaternion_P.Constant12_Value) * FxTESO_Quaternion_P.Gain12_Gain) *
    (localB->v[0] * rtu_PX4Params_FxTQESOg_mu_1[3]);

  // Abs: '<Root>/Abs13' incorporates:
  //   Abs: '<Root>/Abs14'
  //   Abs: '<Root>/Abs15'
  //   Abs: '<Root>/Abs16'
  //   Abs: '<Root>/Abs17'
  //   Abs: '<Root>/Abs18'

  localB->t1 = fabs(localB->Sum_n);
  localB->t2 = localB->t1;

  // Product: '<Root>/Product1' incorporates:
  //   Abs: '<Root>/Abs13'
  //   Constant: '<Root>/Constant5'
  //   Gain: '<Root>/Gain13'
  //   Math: '<Root>/Power13'
  //   Signum: '<Root>/Sign15'
  //   Sum: '<Root>/Sum20'

  localB->Sum_p = rt_powd_snf(localB->t1, (rtu_PX4Params_FxTQESOg_alpha_q[4] +
    FxTESO_Quaternion_P.Constant5_Value) * FxTESO_Quaternion_P.Gain13_Gain) *
    (localB->v[1] * rtu_PX4Params_FxTQESOg_eps_1[4]);

  // Product: '<Root>/Product14' incorporates:
  //   Abs: '<Root>/Abs14'
  //   Constant: '<Root>/Constant12'
  //   Gain: '<Root>/Gain12'
  //   Math: '<Root>/Power14'
  //   Signum: '<Root>/Sign15'
  //   Sum: '<Root>/Sum21'

  localB->rtu_PX4Params_FxTQESOg_mu_1_idx = rt_powd_snf(localB->t1,
    (rtu_PX4Params_FxTQESOg_beta_q[4] + FxTESO_Quaternion_P.Constant12_Value) *
    FxTESO_Quaternion_P.Gain12_Gain) * (localB->v[1] *
    rtu_PX4Params_FxTQESOg_mu_1[4]);

  // Abs: '<Root>/Abs13' incorporates:
  //   Abs: '<Root>/Abs14'
  //   Abs: '<Root>/Abs15'
  //   Abs: '<Root>/Abs16'
  //   Abs: '<Root>/Abs17'
  //   Abs: '<Root>/Abs18'

  localB->t1 = fabs(localB->Sum_f);

  // Product: '<Root>/Product1' incorporates:
  //   Abs: '<Root>/Abs13'
  //   Constant: '<Root>/Constant5'
  //   Gain: '<Root>/Gain13'
  //   Math: '<Root>/Power13'
  //   Signum: '<Root>/Sign15'
  //   Sum: '<Root>/Sum20'

  localB->rtu_PX4Params_FxTQESOg_eps_1_id = rt_powd_snf(localB->t1,
    (rtu_PX4Params_FxTQESOg_alpha_q[5] + FxTESO_Quaternion_P.Constant5_Value) *
    FxTESO_Quaternion_P.Gain13_Gain) * (localB->v[2] *
    rtu_PX4Params_FxTQESOg_eps_1[5]);

  // Product: '<Root>/Product14' incorporates:
  //   Abs: '<Root>/Abs14'
  //   Constant: '<Root>/Constant12'
  //   Gain: '<Root>/Gain12'
  //   Math: '<Root>/Power14'
  //   Signum: '<Root>/Sign15'
  //   Sum: '<Root>/Sum21'

  localB->rtu_PX4Params_FxTQESOg_mu_1_i_b = rt_powd_snf(localB->t1,
    (rtu_PX4Params_FxTQESOg_beta_q[5] + FxTESO_Quaternion_P.Constant12_Value) *
    FxTESO_Quaternion_P.Gain12_Gain) * (localB->v[2] *
    rtu_PX4Params_FxTQESOg_mu_1[5]);
  for (p2 = 0; p2 < 3; p2++) {
    // Sum: '<Root>/Sum22' incorporates:
    //   Product: '<Root>/Matrix Multiply1'

    localB->rtb_Cv_m = localB->Cv[p2];
    localB->d = localB->rtb_Cv_m * localB->Sum_gl;

    // Product: '<Root>/Matrix Multiply2'
    localB->rtb_Cv_c = localB->rtb_Cv_m * localB->Sum_k;

    // Sum: '<Root>/Sum22' incorporates:
    //   Product: '<Root>/Matrix Multiply1'

    localB->rtb_Cv_m = localB->Cv[p2 + 3];
    localB->d += localB->rtb_Cv_m * localB->Sum_p;

    // Product: '<Root>/Matrix Multiply2'
    localB->rtb_Cv_c += localB->rtb_Cv_m *
      localB->rtu_PX4Params_FxTQESOg_mu_1_idx;

    // Sum: '<Root>/Sum22' incorporates:
    //   Gain: '<Root>/Gain6'
    //   Product: '<Root>/Matrix Multiply1'
    //   Product: '<Root>/Matrix Multiply2'
    //   Product: '<Root>/Matrix Multiply6'

    localB->rtb_Cv_m = localB->Cv[p2 + 6];
    localB->MatrixMultiply6[p2] = ((localB->rtb_Cv_m *
      localB->rtu_PX4Params_FxTQESOg_eps_1_id + localB->d) +
      localDW->Memory2_PreviousInput[p2]) + (localB->rtb_Cv_m *
      localB->rtu_PX4Params_FxTQESOg_mu_1_i_b + localB->rtb_Cv_c);
  }

  // Sum: '<S19>/Sum' incorporates:
  //   Constant: '<Root>/Constant13'
  //   Product: '<S19>/Product'
  //   Product: '<S19>/Product1'
  //   Product: '<S19>/Product2'
  //   Product: '<S19>/Product3'

  localB->Sum_gl = ((localB->rtb_Gain14_idx_0 *
                     FxTESO_Quaternion_P.Constant13_Value -
                     localB->MatrixMultiply6[0] * localB->rtb_Gain14_idx_1) -
                    localB->MatrixMultiply6[1] * localB->rtb_Gain14_idx_2) -
    localB->MatrixMultiply6[2] * localB->rtb_Gain14_idx_3;

  // Sum: '<S20>/Sum' incorporates:
  //   Constant: '<Root>/Constant13'
  //   Product: '<S20>/Product'
  //   Product: '<S20>/Product1'
  //   Product: '<S20>/Product2'
  //   Product: '<S20>/Product3'

  localB->Sum_k = ((localB->rtb_Gain14_idx_0 * localB->MatrixMultiply6[0] +
                    localB->rtb_Gain14_idx_1 *
                    FxTESO_Quaternion_P.Constant13_Value) +
                   localB->rtb_Gain14_idx_2 * localB->MatrixMultiply6[2]) -
    localB->MatrixMultiply6[1] * localB->rtb_Gain14_idx_3;

  // Sum: '<S21>/Sum' incorporates:
  //   Constant: '<Root>/Constant13'
  //   Product: '<S21>/Product'
  //   Product: '<S21>/Product1'
  //   Product: '<S21>/Product2'
  //   Product: '<S21>/Product3'

  localB->Sum_p = ((localB->rtb_Gain14_idx_0 * localB->MatrixMultiply6[1] -
                    localB->rtb_Gain14_idx_1 * localB->MatrixMultiply6[2]) +
                   localB->rtb_Gain14_idx_2 *
                   FxTESO_Quaternion_P.Constant13_Value) +
    localB->MatrixMultiply6[0] * localB->rtb_Gain14_idx_3;

  // Sum: '<S22>/Sum' incorporates:
  //   Constant: '<Root>/Constant13'
  //   Product: '<S22>/Product'
  //   Product: '<S22>/Product1'
  //   Product: '<S22>/Product2'
  //   Product: '<S22>/Product3'

  localB->rtb_Gain14_idx_1 = ((localB->rtb_Gain14_idx_0 *
    localB->MatrixMultiply6[2] + localB->rtb_Gain14_idx_1 *
    localB->MatrixMultiply6[1]) - localB->MatrixMultiply6[0] *
    localB->rtb_Gain14_idx_2) + localB->rtb_Gain14_idx_3 *
    FxTESO_Quaternion_P.Constant13_Value;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
  //   Product: '<S23>/Product'
  //   Product: '<S23>/Product1'
  //   Product: '<S23>/Product2'
  //   Product: '<S23>/Product3'
  //   Sum: '<S23>/Sum'

  localB->rtb_Cv_m = (((localB->Sum_gl * localB->Sum_e - localB->Sum_k *
                        localB->Sum) - localB->Sum_p * localB->Sum_n) -
                      localB->rtb_Gain14_idx_1 * localB->Sum_f) *
    FxTESO_Quaternion_P.DiscreteTimeIntegrator2_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  localDW->Memory1_PreviousInput[0] = localB->rtb_Cv_m +
    localDW->DiscreteTimeIntegrator2_DSTATE[0];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
  //   Product: '<S24>/Product'
  //   Product: '<S24>/Product1'
  //   Product: '<S24>/Product2'
  //   Product: '<S24>/Product3'
  //   Sum: '<S24>/Sum'

  localB->rtb_Cv_c = (((localB->Sum_gl * localB->Sum + localB->Sum_k *
                        localB->Sum_e) + localB->Sum_p * localB->Sum_f) -
                      localB->rtb_Gain14_idx_1 * localB->Sum_n) *
    FxTESO_Quaternion_P.DiscreteTimeIntegrator2_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  localDW->Memory1_PreviousInput[1] = localB->rtb_Cv_c +
    localDW->DiscreteTimeIntegrator2_DSTATE[1];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
  //   Product: '<S25>/Product'
  //   Product: '<S25>/Product1'
  //   Product: '<S25>/Product2'
  //   Product: '<S25>/Product3'
  //   Sum: '<S25>/Sum'

  localB->rtb_Gain14_idx_0 = (((localB->Sum_gl * localB->Sum_n - localB->Sum_k *
    localB->Sum_f) + localB->Sum_p * localB->Sum_e) + localB->rtb_Gain14_idx_1 *
    localB->Sum) * FxTESO_Quaternion_P.DiscreteTimeIntegrator2_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  localDW->Memory1_PreviousInput[2] = localB->rtb_Gain14_idx_0 +
    localDW->DiscreteTimeIntegrator2_DSTATE[2];

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' incorporates:
  //   Product: '<S26>/Product'
  //   Product: '<S26>/Product1'
  //   Product: '<S26>/Product2'
  //   Product: '<S26>/Product3'
  //   Sum: '<S26>/Sum'

  localB->rtb_Gain14_idx_2 = (((localB->Sum_gl * localB->Sum_f + localB->Sum_k *
    localB->Sum_n) - localB->Sum_p * localB->Sum) + localB->rtb_Gain14_idx_1 *
    localB->Sum_e) * FxTESO_Quaternion_P.DiscreteTimeIntegrator2_gainval;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  localDW->Memory1_PreviousInput[3] = localB->rtb_Gain14_idx_2 +
    localDW->DiscreteTimeIntegrator2_DSTATE[3];

  // Signum: '<Root>/Sign5' incorporates:
  //   Product: '<Root>/Product13'

  localB->Sum = localDW->Memory4_PreviousInput[0];
  if (rtIsNaN(localB->Sum)) {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[0] = (rtNaN);
  } else if (localB->Sum < 0.0) {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[0] = -1.0;
  } else {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[0] = (localB->Sum > 0.0);
  }

  // Abs: '<Root>/Abs6' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Abs: '<Root>/Abs5'
  //   Abs: '<Root>/Abs7'
  //   Abs: '<Root>/Abs8'
  //   Abs: '<Root>/Abs9'
  //   Product: '<Root>/Product13'

  localB->Sum_n = fabs(localDW->Memory4_PreviousInput[0]);

  // Signum: '<Root>/Sign5' incorporates:
  //   Product: '<Root>/Product13'

  localB->Sum = localDW->Memory4_PreviousInput[1];
  if (rtIsNaN(localB->Sum)) {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[1] = (rtNaN);
  } else if (localB->Sum < 0.0) {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[1] = -1.0;
  } else {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[1] = (localB->Sum > 0.0);
  }

  // Abs: '<Root>/Abs6' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Abs: '<Root>/Abs5'
  //   Abs: '<Root>/Abs7'
  //   Abs: '<Root>/Abs8'
  //   Abs: '<Root>/Abs9'
  //   Product: '<Root>/Product13'

  localB->Sum_f = fabs(localDW->Memory4_PreviousInput[1]);

  // Signum: '<Root>/Sign5' incorporates:
  //   Product: '<Root>/Product13'

  localB->Sum = localDW->Memory4_PreviousInput[2];
  if (rtIsNaN(localB->Sum)) {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[2] = (rtNaN);
  } else if (localB->Sum < 0.0) {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[2] = -1.0;
  } else {
    // Signum: '<Root>/Sign6' incorporates:
    //   Signum: '<Root>/Sign3'
    //   Signum: '<Root>/Sign4'
    //   Signum: '<Root>/Sign7'
    //   Signum: '<Root>/Sign8'
    //   Signum: '<Root>/Sign9'

    localB->MatrixMultiply6[2] = (localB->Sum > 0.0);
  }

  // Abs: '<Root>/Abs6' incorporates:
  //   Abs: '<Root>/Abs4'
  //   Abs: '<Root>/Abs5'
  //   Abs: '<Root>/Abs7'
  //   Abs: '<Root>/Abs8'
  //   Abs: '<Root>/Abs9'
  //   Product: '<Root>/Product13'

  localB->Sum_e = fabs(localDW->Memory4_PreviousInput[2]);

  // MATLAB Function: '<S2>/Kronecker_product' incorporates:
  //   SignalConversion generated from: '<S14>/ SFunction '
  //   UnaryMinus: '<S5>/Unary Minus'
  //   UnaryMinus: '<S5>/Unary Minus1'
  //   UnaryMinus: '<S5>/Unary Minus2'

  localB->rty_state_hat_q_hat[0] = localB->r_g[0];
  localB->rty_state_hat_q_hat[4] = -localB->r_g[1];
  localB->rty_state_hat_q_hat[8] = -localB->r_g[2];
  localB->rty_state_hat_q_hat[12] = -localB->r_g[3];
  localB->rty_state_hat_q_hat[1] = localB->r_g[1];
  localB->rty_state_hat_q_hat[5] = localB->r_g[0];
  localB->rty_state_hat_q_hat[9] = -localB->r_g[3];
  localB->rty_state_hat_q_hat[13] = localB->r_g[2];
  localB->rty_state_hat_q_hat[2] = localB->r_g[2];
  localB->rty_state_hat_q_hat[6] = localB->r_g[3];
  localB->rty_state_hat_q_hat[10] = localB->r_g[0];
  localB->rty_state_hat_q_hat[14] = -localB->r_g[1];
  localB->rty_state_hat_q_hat[3] = localB->r_g[3];
  localB->rty_state_hat_q_hat[7] = -localB->r_g[2];
  localB->rty_state_hat_q_hat[11] = localB->r_g[1];
  localB->rty_state_hat_q_hat[15] = localB->r_g[0];
  for (p2 = 0; p2 < 4; p2++) {
    localB->r_g[p2] = ((localB->rty_state_hat_q_hat[p2 + 4] * -localB->Product1
                        + localB->rty_state_hat_q_hat[p2] * localB->Product) +
                       localB->rty_state_hat_q_hat[p2 + 8] * -localB->Product2)
      + localB->rty_state_hat_q_hat[p2 + 12] * -localB->Product3;
  }

  // End of MATLAB Function: '<S2>/Kronecker_product'

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Constant: '<Root>/Constant6'
  //   Constant: '<Root>/Constant7'
  //   Gain: '<Root>/Gain5'
  //   Gain: '<Root>/Gain6'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Memory: '<Root>/Memory6'
  //   Product: '<Root>/Divide'
  //   Product: '<Root>/Product8'
  //   Product: '<Root>/Product9'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum11'
  //   Sum: '<Root>/Sum9'

  localB->Sum = (((rt_powd_snf(localB->Sum_n, (rtu_PX4Params_FxTQESOg_alpha_q[0]
    + FxTESO_Quaternion_P.Constant6_Value) * FxTESO_Quaternion_P.Gain5_Gain) *
                   (rtu_PX4Params_FxTQESOg_eps_2[0] * localB->MatrixMultiply6[0])
                   + localDW->Memory6_PreviousInput[0]) + localB->r_g[1] /
                  rtu_PX4Params_MCg_MCData[0]) + rt_powd_snf(localB->Sum_n,
    (rtu_PX4Params_FxTQESOg_beta_q[0] + FxTESO_Quaternion_P.Constant7_Value) *
    FxTESO_Quaternion_P.Gain6_Gain) * (rtu_PX4Params_FxTQESOg_mu_2[0] *
    localB->MatrixMultiply6[0])) *
    FxTESO_Quaternion_P.DiscreteTimeIntegrator4_gainval;
  localB->gamma_hat_2_tmp[0] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
  localDW->DiscreteTimeIntegrator4_DSTATE[0] += localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Gain: '<Root>/Gain3'
  //   Gain: '<Root>/Gain4'
  //   Math: '<Root>/Power3'
  //   Math: '<Root>/Power4'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Memory: '<Root>/Memory5'
  //   Product: '<Root>/Product6'
  //   Product: '<Root>/Product7'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum5'
  //   Sum: '<Root>/Sum6'
  //   Sum: '<Root>/Sum7'
  //   Sum: '<Root>/Sum9'

  localB->Sum = ((rt_powd_snf(localB->Sum_n, (rtu_PX4Params_FxTQESOg_alpha_q[0]
    + FxTESO_Quaternion_P.Constant2_Value) * FxTESO_Quaternion_P.Gain3_Gain) *
                  (rtu_PX4Params_FxTQESOg_eps_1[0] * localB->MatrixMultiply6[0])
                  + localDW->Memory5_PreviousInput[0]) + rt_powd_snf
                 (localB->Sum_n, (rtu_PX4Params_FxTQESOg_beta_q[0] +
    FxTESO_Quaternion_P.Constant4_Value) * FxTESO_Quaternion_P.Gain4_Gain) *
                 (rtu_PX4Params_FxTQESOg_mu_1[0] * localB->MatrixMultiply6[0])) *
    FxTESO_Quaternion_P.DiscreteTimeIntegrator3_gainval;
  localB->gamma_hat_1_tmp[0] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->Memory4_PreviousInput[0] = localDW->DiscreteTimeIntegrator3_DSTATE[0]
    + localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Math: '<Root>/Power7'
  //   Math: '<Root>/Power8'
  //   Product: '<Root>/Product11'
  //   Product: '<Root>/Product12'
  //   Product: '<Root>/Product13'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum13'
  //   Sum: '<Root>/Sum9'

  localB->Sum = ((rtu_PX4Params_FxTQESOg_eps_3[0] * localB->MatrixMultiply6[0] *
                  rt_powd_snf(localB->Sum_n, rtu_PX4Params_FxTQESOg_alpha_q[0])
                  + rtu_PX4Params_FxTQESOg_mu_3[0] * localB->MatrixMultiply6[0] *
                  rt_powd_snf(localB->Sum_n, rtu_PX4Params_FxTQESOg_beta_q[0]))
                 + rtu_PX4Params_FxTQESOg_eps_4[0] * localB->MatrixMultiply6[0])
    * FxTESO_Quaternion_P.DiscreteTimeIntegrator5_gainval;
  localB->MatrixMultiply6[0] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator5'
  localDW->Memory6_PreviousInput[0] = localDW->DiscreteTimeIntegrator5_DSTATE[0]
    + localB->Sum;

  // Product: '<Root>/Product20' incorporates:
  //   Abs: '<Root>/Abs15'
  //   Constant: '<Root>/Constant15'
  //   Gain: '<Root>/Gain15'
  //   Math: '<Root>/Power15'
  //   Signum: '<Root>/Sign17'
  //   Sum: '<Root>/Sum28'

  localB->Product = rt_powd_snf(localB->Memory4_PreviousInput,
    (rtu_PX4Params_FxTQESOg_alpha_q[3] + FxTESO_Quaternion_P.Constant15_Value) *
    FxTESO_Quaternion_P.Gain15_Gain) * (localB->v[0] *
    rtu_PX4Params_FxTQESOg_eps_2[3]);

  // Product: '<Root>/Product21' incorporates:
  //   Abs: '<Root>/Abs15'
  //   Constant: '<Root>/Constant14'
  //   Gain: '<Root>/Gain16'
  //   Math: '<Root>/Power16'
  //   Signum: '<Root>/Sign17'
  //   Sum: '<Root>/Sum23'

  localB->Product1 = rt_powd_snf(localB->Memory4_PreviousInput,
    (rtu_PX4Params_FxTQESOg_beta_q[3] + FxTESO_Quaternion_P.Constant14_Value) *
    FxTESO_Quaternion_P.Gain16_Gain) * (localB->v[0] *
    rtu_PX4Params_FxTQESOg_mu_2[3]);

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Constant: '<Root>/Constant6'
  //   Constant: '<Root>/Constant7'
  //   Gain: '<Root>/Gain5'
  //   Gain: '<Root>/Gain6'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Memory: '<Root>/Memory6'
  //   Product: '<Root>/Divide'
  //   Product: '<Root>/Product8'
  //   Product: '<Root>/Product9'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum11'
  //   Sum: '<Root>/Sum9'

  localB->Sum = (((rt_powd_snf(localB->Sum_f, (rtu_PX4Params_FxTQESOg_alpha_q[1]
    + FxTESO_Quaternion_P.Constant6_Value) * FxTESO_Quaternion_P.Gain5_Gain) *
                   (rtu_PX4Params_FxTQESOg_eps_2[1] * localB->MatrixMultiply6[1])
                   + localDW->Memory6_PreviousInput[1]) + localB->r_g[2] /
                  rtu_PX4Params_MCg_MCData[0]) + rt_powd_snf(localB->Sum_f,
    (rtu_PX4Params_FxTQESOg_beta_q[1] + FxTESO_Quaternion_P.Constant7_Value) *
    FxTESO_Quaternion_P.Gain6_Gain) * (rtu_PX4Params_FxTQESOg_mu_2[1] *
    localB->MatrixMultiply6[1])) *
    FxTESO_Quaternion_P.DiscreteTimeIntegrator4_gainval;
  localB->gamma_hat_2_tmp[1] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
  localDW->DiscreteTimeIntegrator4_DSTATE[1] += localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Gain: '<Root>/Gain3'
  //   Gain: '<Root>/Gain4'
  //   Math: '<Root>/Power3'
  //   Math: '<Root>/Power4'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Memory: '<Root>/Memory5'
  //   Product: '<Root>/Product6'
  //   Product: '<Root>/Product7'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum5'
  //   Sum: '<Root>/Sum6'
  //   Sum: '<Root>/Sum7'
  //   Sum: '<Root>/Sum9'

  localB->Sum = ((rt_powd_snf(localB->Sum_f, (rtu_PX4Params_FxTQESOg_alpha_q[1]
    + FxTESO_Quaternion_P.Constant2_Value) * FxTESO_Quaternion_P.Gain3_Gain) *
                  (rtu_PX4Params_FxTQESOg_eps_1[1] * localB->MatrixMultiply6[1])
                  + localDW->Memory5_PreviousInput[1]) + rt_powd_snf
                 (localB->Sum_f, (rtu_PX4Params_FxTQESOg_beta_q[1] +
    FxTESO_Quaternion_P.Constant4_Value) * FxTESO_Quaternion_P.Gain4_Gain) *
                 (rtu_PX4Params_FxTQESOg_mu_1[1] * localB->MatrixMultiply6[1])) *
    FxTESO_Quaternion_P.DiscreteTimeIntegrator3_gainval;
  localB->gamma_hat_1_tmp[1] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->Memory4_PreviousInput[1] = localDW->DiscreteTimeIntegrator3_DSTATE[1]
    + localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Math: '<Root>/Power7'
  //   Math: '<Root>/Power8'
  //   Product: '<Root>/Product11'
  //   Product: '<Root>/Product12'
  //   Product: '<Root>/Product13'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum13'
  //   Sum: '<Root>/Sum9'

  localB->Sum = ((rtu_PX4Params_FxTQESOg_eps_3[1] * localB->MatrixMultiply6[1] *
                  rt_powd_snf(localB->Sum_f, rtu_PX4Params_FxTQESOg_alpha_q[1])
                  + rtu_PX4Params_FxTQESOg_mu_3[1] * localB->MatrixMultiply6[1] *
                  rt_powd_snf(localB->Sum_f, rtu_PX4Params_FxTQESOg_beta_q[1]))
                 + rtu_PX4Params_FxTQESOg_eps_4[1] * localB->MatrixMultiply6[1])
    * FxTESO_Quaternion_P.DiscreteTimeIntegrator5_gainval;
  localB->MatrixMultiply6[1] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator5'
  localDW->Memory6_PreviousInput[1] = localDW->DiscreteTimeIntegrator5_DSTATE[1]
    + localB->Sum;

  // Product: '<Root>/Product20' incorporates:
  //   Abs: '<Root>/Abs15'
  //   Constant: '<Root>/Constant15'
  //   Gain: '<Root>/Gain15'
  //   Math: '<Root>/Power15'
  //   Signum: '<Root>/Sign17'
  //   Sum: '<Root>/Sum28'

  localB->Product2 = rt_powd_snf(localB->t2, (rtu_PX4Params_FxTQESOg_alpha_q[4]
    + FxTESO_Quaternion_P.Constant15_Value) * FxTESO_Quaternion_P.Gain15_Gain) *
    (localB->v[1] * rtu_PX4Params_FxTQESOg_eps_2[4]);

  // Product: '<Root>/Product21' incorporates:
  //   Abs: '<Root>/Abs15'
  //   Constant: '<Root>/Constant14'
  //   Gain: '<Root>/Gain16'
  //   Math: '<Root>/Power16'
  //   Signum: '<Root>/Sign17'
  //   Sum: '<Root>/Sum23'

  localB->Product3 = rt_powd_snf(localB->t2, (rtu_PX4Params_FxTQESOg_beta_q[4] +
    FxTESO_Quaternion_P.Constant14_Value) * FxTESO_Quaternion_P.Gain16_Gain) *
    (localB->v[1] * rtu_PX4Params_FxTQESOg_mu_2[4]);

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Constant: '<Root>/Constant6'
  //   Constant: '<Root>/Constant7'
  //   Gain: '<Root>/Gain5'
  //   Gain: '<Root>/Gain6'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Memory: '<Root>/Memory6'
  //   Product: '<Root>/Divide'
  //   Product: '<Root>/Product8'
  //   Product: '<Root>/Product9'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum11'
  //   Sum: '<Root>/Sum9'

  localB->Sum = (((rt_powd_snf(localB->Sum_e, (rtu_PX4Params_FxTQESOg_alpha_q[2]
    + FxTESO_Quaternion_P.Constant6_Value) * FxTESO_Quaternion_P.Gain5_Gain) *
                   (rtu_PX4Params_FxTQESOg_eps_2[2] * localB->MatrixMultiply6[2])
                   + localDW->Memory6_PreviousInput[2]) + localB->r_g[3] /
                  rtu_PX4Params_MCg_MCData[0]) + rt_powd_snf(localB->Sum_e,
    (rtu_PX4Params_FxTQESOg_beta_q[2] + FxTESO_Quaternion_P.Constant7_Value) *
    FxTESO_Quaternion_P.Gain6_Gain) * (rtu_PX4Params_FxTQESOg_mu_2[2] *
    localB->MatrixMultiply6[2])) *
    FxTESO_Quaternion_P.DiscreteTimeIntegrator4_gainval;
  localB->gamma_hat_2_tmp[2] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
  localDW->DiscreteTimeIntegrator4_DSTATE[2] += localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Gain: '<Root>/Gain3'
  //   Gain: '<Root>/Gain4'
  //   Math: '<Root>/Power3'
  //   Math: '<Root>/Power4'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Memory: '<Root>/Memory5'
  //   Product: '<Root>/Product6'
  //   Product: '<Root>/Product7'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum5'
  //   Sum: '<Root>/Sum6'
  //   Sum: '<Root>/Sum7'
  //   Sum: '<Root>/Sum9'

  localB->Sum = ((rt_powd_snf(localB->Sum_e, (rtu_PX4Params_FxTQESOg_alpha_q[2]
    + FxTESO_Quaternion_P.Constant2_Value) * FxTESO_Quaternion_P.Gain3_Gain) *
                  (rtu_PX4Params_FxTQESOg_eps_1[2] * localB->MatrixMultiply6[2])
                  + localDW->Memory5_PreviousInput[2]) + rt_powd_snf
                 (localB->Sum_e, (rtu_PX4Params_FxTQESOg_beta_q[2] +
    FxTESO_Quaternion_P.Constant4_Value) * FxTESO_Quaternion_P.Gain4_Gain) *
                 (rtu_PX4Params_FxTQESOg_mu_1[2] * localB->MatrixMultiply6[2])) *
    FxTESO_Quaternion_P.DiscreteTimeIntegrator3_gainval;
  localB->gamma_hat_1_tmp[2] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
  localDW->Memory4_PreviousInput[2] = localDW->DiscreteTimeIntegrator3_DSTATE[2]
    + localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' incorporates:
  //   Abs: '<Root>/Abs6'
  //   Math: '<Root>/Power5'
  //   Math: '<Root>/Power6'
  //   Math: '<Root>/Power7'
  //   Math: '<Root>/Power8'
  //   Product: '<Root>/Product11'
  //   Product: '<Root>/Product12'
  //   Product: '<Root>/Product13'
  //   Signum: '<Root>/Sign5'
  //   Sum: '<Root>/Sum10'
  //   Sum: '<Root>/Sum13'
  //   Sum: '<Root>/Sum9'

  localB->Sum = ((rtu_PX4Params_FxTQESOg_eps_3[2] * localB->MatrixMultiply6[2] *
                  rt_powd_snf(localB->Sum_e, rtu_PX4Params_FxTQESOg_alpha_q[2])
                  + rtu_PX4Params_FxTQESOg_mu_3[2] * localB->MatrixMultiply6[2] *
                  rt_powd_snf(localB->Sum_e, rtu_PX4Params_FxTQESOg_beta_q[2]))
                 + rtu_PX4Params_FxTQESOg_eps_4[2] * localB->MatrixMultiply6[2])
    * FxTESO_Quaternion_P.DiscreteTimeIntegrator5_gainval;
  localB->MatrixMultiply6[2] = localB->Sum;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator5'
  localDW->Memory6_PreviousInput[2] = localDW->DiscreteTimeIntegrator5_DSTATE[2]
    + localB->Sum;

  // Product: '<Root>/Product20' incorporates:
  //   Abs: '<Root>/Abs13'
  //   Constant: '<Root>/Constant15'
  //   Gain: '<Root>/Gain15'
  //   Math: '<Root>/Power15'
  //   Signum: '<Root>/Sign17'
  //   Sum: '<Root>/Sum28'

  localB->Sum = rt_powd_snf(localB->t1, (rtu_PX4Params_FxTQESOg_alpha_q[5] +
    FxTESO_Quaternion_P.Constant15_Value) * FxTESO_Quaternion_P.Gain15_Gain) *
    (localB->v[2] * rtu_PX4Params_FxTQESOg_eps_2[5]);

  // Product: '<Root>/Product21' incorporates:
  //   Abs: '<Root>/Abs13'
  //   Constant: '<Root>/Constant14'
  //   Gain: '<Root>/Gain16'
  //   Math: '<Root>/Power16'
  //   Signum: '<Root>/Sign17'
  //   Sum: '<Root>/Sum23'

  localB->Sum_n = rt_powd_snf(localB->t1, (rtu_PX4Params_FxTQESOg_beta_q[5] +
    FxTESO_Quaternion_P.Constant14_Value) * FxTESO_Quaternion_P.Gain16_Gain) *
    (localB->v[2] * rtu_PX4Params_FxTQESOg_mu_2[5]);

  // Product: '<Root>/Product15' incorporates:
  //   Abs: '<Root>/Abs17'
  //   Math: '<Root>/Power17'
  //   Signum: '<Root>/Sign19'

  localB->Sum_f = localB->v[0] * rtu_PX4Params_FxTQESOg_eps_3[3] * rt_powd_snf
    (localB->Memory4_PreviousInput, rtu_PX4Params_FxTQESOg_alpha_q[3]);

  // Product: '<Root>/Product18' incorporates:
  //   Abs: '<Root>/Abs17'
  //   Math: '<Root>/Power18'
  //   Signum: '<Root>/Sign19'

  localB->Memory4_PreviousInput = localB->v[0] * rtu_PX4Params_FxTQESOg_mu_3[3] *
    rt_powd_snf(localB->Memory4_PreviousInput, rtu_PX4Params_FxTQESOg_beta_q[3]);

  // Product: '<Root>/Product15' incorporates:
  //   Abs: '<Root>/Abs17'
  //   Math: '<Root>/Power17'
  //   Signum: '<Root>/Sign19'

  localB->Sum_e = localB->v[1] * rtu_PX4Params_FxTQESOg_eps_3[4] * rt_powd_snf
    (localB->t2, rtu_PX4Params_FxTQESOg_alpha_q[4]);

  // Product: '<Root>/Product18' incorporates:
  //   Abs: '<Root>/Abs17'
  //   Math: '<Root>/Power18'
  //   Signum: '<Root>/Sign19'

  localB->t2 = localB->v[1] * rtu_PX4Params_FxTQESOg_mu_3[4] * rt_powd_snf
    (localB->t2, rtu_PX4Params_FxTQESOg_beta_q[4]);

  // Product: '<Root>/Product15' incorporates:
  //   Abs: '<Root>/Abs13'
  //   Math: '<Root>/Power17'
  //   Signum: '<Root>/Sign19'

  localB->rtb_Gain14_idx_1 = localB->v[2] * rtu_PX4Params_FxTQESOg_eps_3[5] *
    rt_powd_snf(localB->t1, rtu_PX4Params_FxTQESOg_alpha_q[5]);

  // Product: '<Root>/Product18' incorporates:
  //   Abs: '<Root>/Abs13'
  //   Math: '<Root>/Power18'
  //   Signum: '<Root>/Sign19'

  localB->t1 = localB->v[2] * rtu_PX4Params_FxTQESOg_mu_3[5] * rt_powd_snf
    (localB->t1, rtu_PX4Params_FxTQESOg_beta_q[5]);

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
  localDW->DiscreteTimeIntegrator2_DSTATE[0] = localB->rtb_Cv_m +
    localDW->Memory1_PreviousInput[0];
  localDW->DiscreteTimeIntegrator2_DSTATE[1] = localB->rtb_Cv_c +
    localDW->Memory1_PreviousInput[1];
  localDW->DiscreteTimeIntegrator2_DSTATE[2] = localB->rtb_Gain14_idx_0 +
    localDW->Memory1_PreviousInput[2];
  localDW->DiscreteTimeIntegrator2_DSTATE[3] = localB->rtb_Gain14_idx_2 +
    localDW->Memory1_PreviousInput[3];

  // Sum: '<Root>/Sum25' incorporates:
  //   Product: '<Root>/Matrix Multiply3'

  localB->rtb_Gain14_idx_0 = rtu_Fu_Fu[4];
  localB->rtb_Gain14_idx_2 = rtu_Fu_Fu[3];
  localB->rtb_Gain14_idx_3 = rtu_Fu_Fu[5];
  for (p2 = 0; p2 < 3; p2++) {
    // Sum: '<Root>/Sum24' incorporates:
    //   Product: '<Root>/Matrix Multiply4'

    localB->rtb_Cv_m = localB->Cv[p2];
    localB->rtb_Cv_c = localB->Cv[p2 + 3];
    localB->Sum_p = localB->Cv[p2 + 6];

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
    //   Memory: '<Root>/Memory3'
    //   Product: '<Root>/Matrix Multiply3'
    //   Product: '<Root>/Matrix Multiply4'
    //   Product: '<Root>/Matrix Multiply5'
    //   Sum: '<Root>/Sum24'
    //   Sum: '<Root>/Sum25'

    localB->Sum_gl = (((((localB->rtb_Cv_c * localB->Product2 + localB->rtb_Cv_m
                          * localB->Product) + localB->Sum_p * localB->Sum) +
                        localDW->Memory3_PreviousInput[p2]) + ((localB->rtb_Cv_c
      * localB->Product3 + localB->rtb_Cv_m * localB->Product1) + localB->Sum_p *
      localB->Sum_n)) + ((localB->J[p2 + 3] * localB->rtb_Gain14_idx_0 +
                          localB->J[p2] * localB->rtb_Gain14_idx_2) + localB->
                         J[p2 + 6] * localB->rtb_Gain14_idx_3)) *
      FxTESO_Quaternion_P.DiscreteTimeIntegrator1_gainval;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
    localB->Sum_k = localDW->DiscreteTimeIntegrator1_DSTATE[p2] + localB->Sum_gl;
    localDW->Memory2_PreviousInput[p2] = localB->Sum_k;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
    //   Product: '<Root>/Matrix Multiply6'
    //   Product: '<Root>/Matrix Multiply7'
    //   Product: '<Root>/Product19'
    //   Signum: '<Root>/Sign21'
    //   Sum: '<Root>/Sum26'
    //   Sum: '<Root>/Sum27'

    localB->rtb_Cv_m = ((((localB->rtb_Cv_c * localB->Sum_e + localB->rtb_Cv_m *
      localB->Sum_f) + localB->Sum_p * localB->rtb_Gain14_idx_1) +
                         ((localB->rtb_Cv_c * localB->t2 + localB->rtb_Cv_m *
      localB->Memory4_PreviousInput) + localB->Sum_p * localB->t1)) +
                        rtu_PX4Params_FxTQESOg_eps_4[p2 + 3] * localB->v[p2]) *
      FxTESO_Quaternion_P.DiscreteTimeIntegrator_gainval;

    // DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localB->rtb_Cv_c = localDW->DiscreteTimeIntegrator_DSTATE[p2] +
      localB->rtb_Cv_m;
    localDW->Memory3_PreviousInput[p2] = localB->rtb_Cv_c;

    // Update for Memory: '<Root>/Memory5' incorporates:
    //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'

    localB->Sum_p = localDW->DiscreteTimeIntegrator4_DSTATE[p2];
    localDW->Memory5_PreviousInput[p2] = localB->Sum_p;

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
    localDW->DiscreteTimeIntegrator4_DSTATE[p2] = localB->Sum_p +
      localB->gamma_hat_2_tmp[p2];

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
    localDW->DiscreteTimeIntegrator3_DSTATE[p2] = localDW->
      Memory4_PreviousInput[p2] + localB->gamma_hat_1_tmp[p2];

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator5'
    localDW->DiscreteTimeIntegrator5_DSTATE[p2] = localDW->
      Memory6_PreviousInput[p2] + localB->MatrixMultiply6[p2];

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
    localDW->DiscreteTimeIntegrator1_DSTATE[p2] = localB->Sum_k + localB->Sum_gl;

    // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
    localDW->DiscreteTimeIntegrator_DSTATE[p2] = localB->rtb_Cv_c +
      localB->rtb_Cv_m;
  }
}

// Model initialize function
void FxTESO_Quaternion_initialize(const char_T **rt_errorStatus,
  RT_MODEL_FxTESO_Quaternion_T *const FxTESO_Quaternion_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  FxTESO_Quaternion_M->setErrorStatusPointer(rt_errorStatus);
}

const char_T** RT_MODEL_FxTESO_Quaternion_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_FxTESO_Quaternion_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

const char_T* RT_MODEL_FxTESO_Quaternion_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_FxTESO_Quaternion_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
