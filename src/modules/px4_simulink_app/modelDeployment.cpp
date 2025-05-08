//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: modelDeployment.cpp
//
// Code generated for Simulink model 'modelDeployment'.
//
// Model version                  : 1.199
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Mon Apr 28 16:20:26 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "modelDeployment.h"
#include "rtwtypes.h"
#include "modelDeployment_types.h"
#include "modelDeployment_private.h"
#include <math.h>
#include <string.h>
#include "rt_assert.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"
#include "FxTDiffSim.h"
#include "FxTESO.h"
#include "FxtD_Quaternion.h"
#include "FxTESO_Quaternion.h"
#include "pdGc.h"
#include "asgsm.h"
#include "asgsm_quaternion.h"
#include "asgsm_obs.h"
#include "asgsm_quat_obs.h"

// Block signals (default storage)
B_modelDeployment_T modelDeployment_B;

// Block states (default storage)
DW_modelDeployment_T modelDeployment_DW;

// Real-time model
RT_MODEL_modelDeployment_T modelDeployment_M_ = RT_MODEL_modelDeployment_T();
RT_MODEL_modelDeployment_T *const modelDeployment_M = &modelDeployment_M_;

// Forward declaration for local functions
static real_T modelDeployment_rt_powd_snf(real_T u0, real_T u1);
static void modelDeploy_generateCubicCoeffs(const real_T posPts[2], const real_T
  velPts[2], real_T finalTime, real_T coeffVec[4]);
static void mo_addFlatSegmentsToPPFormParts(const real_T oldbreaks[10], const
  real_T oldCoeffs[216], real_T newBreaks[12], real_T newCoefs[264]);
static void PolyTrajSys_updateStoredPPForms(robotics_slcore_internal_bloc_T *obj,
  const real_T pp_breaks[12], const real_T pp_coefs[264]);
static void modelDeployment_ppval(const real_T pp_breaks[12], const real_T
  pp_coefs[264], real_T x, real_T v[6]);
static void modelDepl_generateQuinticCoeffs(const real_T posPts[2], const real_T
  velPts[2], const real_T accPts[2], real_T finalTime, real_T coeffVec[6]);
static void addFlatSegmentsToPPFormParts_f(const real_T oldbreaks[21], const
  real_T oldCoeffs[720], real_T newBreaks[23], real_T newCoefs[792]);
static void PolyTrajSys_updateStoredPPFor_f(robotics_slcore_internal_bl_f_T *obj,
  const real_T pp_breaks[23], const real_T pp_coefs[792]);
static void modelDeployment_ppval_f(const real_T pp_breaks[23], const real_T
  pp_coefs[792], real_T x, real_T v[6]);
static void addFlatSegmentsToPPFormParts_fj(const real_T oldbreaks[6], const
  real_T oldCoeffs[120], real_T newBreaks[8], real_T newCoefs[168]);
static void PolyTrajSys_updateStoredPPFo_fj(robotics_slcore_internal_b_fj_T *obj,
  const real_T pp_breaks[8], const real_T pp_coefs[168]);
static void modelDeployment_ppval_fj(const real_T pp_breaks[8], const real_T
  pp_coefs[168], real_T x, real_T v[6]);
static void addFlatSegmentsToPPFormPart_fjc(const real_T oldbreaks[12], const
  real_T oldCoeffs[264], real_T newBreaks[14], real_T newCoefs[312]);
static void PolyTrajSys_updateStoredPPF_fjc(robotics_slcore_internal__fjc_T *obj,
  const real_T pp_breaks[14], const real_T pp_coefs[312]);
static void modelDeployment_ppval_fjc(const real_T pp_breaks[14], const real_T
  pp_coefs[312], real_T x, real_T v[6]);
static real_T modelDeployment_rt_atan2d_snf(real_T u0, real_T u1);
static void modelDepl_PolyTrajSys_setupImpl(robotics_slcore_internal_bloc_T *obj);
static void modelDe_PolyTrajSys_setupImpl_f(robotics_slcore_internal_bl_f_T *obj);
static void modelD_PolyTrajSys_setupImpl_fj(robotics_slcore_internal_b_fj_T *obj);
static void model_PolyTrajSys_setupImpl_fjc(robotics_slcore_internal__fjc_T *obj);
static void modelDep_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);

// System initialize for atomic system:
void modelDeploy_ReadParameter3_Init(DW_ReadParameter3_modelDeploy_T *localDW)
{
  static const char_T ParameterNameStr[9] = "FAH_I_ZZ";

  // Start for MATLABSystem: '<S84>/Read Parameter3'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 4.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void modelDeployment_ReadParameter3(B_ReadParameter3_modelDeploym_T *localB,
  DW_ReadParameter3_modelDeploy_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S84>/Read Parameter3'
  b_varargout_2 = MW_Param_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter3_o1);
  if (b_varargout_2) {
    localB->ReadParameter3_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S84>/Read Parameter3'
}

// Termination for atomic system:
void modelDeploy_ReadParameter3_Term(DW_ReadParameter3_modelDeploy_T *localDW)
{
  // Terminate for MATLABSystem: '<S84>/Read Parameter3'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S84>/Read Parameter3'
}

//
// Output and update for atomic system:
//    '<S105>/Kronecker_product'
//    '<S106>/Kronecker_product'
//    '<S95>/Kronecker_product'
//    '<S96>/Kronecker_product'
//    '<S113>/Kronecker_product'
//    '<S114>/Kronecker_product'
//
void modelDeployme_Kronecker_product(const real_T rtu_q[4], const real_T rtu_p[4],
  real_T rty_r[4], B_Kronecker_product_modelDepl_T *localB)
{
  real_T rtu_q_0;
  real_T rtu_q_1;
  real_T rtu_q_2;
  real_T rtu_q_3;
  real_T rtu_q_4;
  real_T rtu_q_5;
  localB->rtu_q[0] = rtu_q[0];
  rtu_q_0 = rtu_q[1];
  rtu_q_1 = rtu_q[2];
  rtu_q_2 = rtu_q[3];
  localB->rtu_q[1] = rtu_q[1];
  localB->rtu_q[5] = rtu_q[0];
  rtu_q_3 = rtu_q[3];
  localB->rtu_q[13] = rtu_q[2];
  localB->rtu_q[2] = rtu_q[2];
  localB->rtu_q[6] = rtu_q[3];
  localB->rtu_q[10] = rtu_q[0];
  rtu_q_4 = rtu_q[1];
  localB->rtu_q[3] = rtu_q[3];
  rtu_q_5 = rtu_q[2];
  localB->rtu_q[11] = rtu_q[1];
  localB->rtu_q[15] = rtu_q[0];
  localB->rtu_q[4] = -rtu_q_0;
  localB->rtu_q[8] = -rtu_q_1;
  localB->rtu_q[12] = -rtu_q_2;
  localB->rtu_q[9] = -rtu_q_3;
  localB->rtu_q[14] = -rtu_q_4;
  localB->rtu_q[7] = -rtu_q_5;
  rtu_q_0 = rtu_p[1];
  rtu_q_1 = rtu_p[0];
  rtu_q_2 = rtu_p[2];
  rtu_q_3 = rtu_p[3];
  for (int32_T i = 0; i < 4; i++) {
    rty_r[i] = ((localB->rtu_q[i + 4] * rtu_q_0 + localB->rtu_q[i] * rtu_q_1) +
                localB->rtu_q[i + 8] * rtu_q_2) + localB->rtu_q[i + 12] *
      rtu_q_3;
  }
}

static real_T modelDeployment_rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    modelDeployment_B.d = fabs(u0);
    modelDeployment_B.d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (modelDeployment_B.d == 1.0) {
        y = 1.0;
      } else if (modelDeployment_B.d > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (modelDeployment_B.d1 == 0.0) {
      y = 1.0;
    } else if (modelDeployment_B.d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void modelDeploy_generateCubicCoeffs(const real_T posPts[2], const real_T
  velPts[2], real_T finalTime, real_T coeffVec[4])
{
  // Start for MATLABSystem: '<S93>/Polynomial Trajectory2' incorporates:
  //   MATLABSystem: '<S89>/Polynomial Trajectory3'
  //   MATLABSystem: '<S90>/Polynomial Trajectory'

  modelDeployment_B.posPts_idx_0 = posPts[1] - (finalTime * velPts[0] + posPts[0]);
  modelDeployment_B.posPts_idx_1 = velPts[1] - (0.0 * posPts[0] + velPts[0]);
  modelDeployment_B.coeffVec_tmp = finalTime * finalTime;
  coeffVec[0] = 1.0 / modelDeployment_B.coeffVec_tmp *
    modelDeployment_B.posPts_idx_1 + -2.0 / modelDeployment_rt_powd_snf
    (finalTime, 3.0) * modelDeployment_B.posPts_idx_0;
  coeffVec[3] = posPts[0];
  coeffVec[1] = 3.0 / modelDeployment_B.coeffVec_tmp *
    modelDeployment_B.posPts_idx_0 + -1.0 / finalTime *
    modelDeployment_B.posPts_idx_1;
  coeffVec[2] = velPts[0];
}

static void mo_addFlatSegmentsToPPFormParts(const real_T oldbreaks[10], const
  real_T oldCoeffs[216], real_T newBreaks[12], real_T newCoefs[264])
{
  memset(&modelDeployment_B.newSegmentCoeffs_l[0], 0, 24U * sizeof(real_T));
  for (modelDeployment_B.i3 = 0; modelDeployment_B.i3 < 6; modelDeployment_B.i3
       ++) {
    // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
    modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3 + 18] =
      ((oldCoeffs[modelDeployment_B.i3 + 54] * 0.0 +
        oldCoeffs[modelDeployment_B.i3] * 0.0) + oldCoeffs[modelDeployment_B.i3
       + 108] * 0.0) + oldCoeffs[modelDeployment_B.i3 + 162];
  }

  memset(&modelDeployment_B.coefsWithFlatStart_g[0], 0, 240U * sizeof(real_T));
  for (modelDeployment_B.i3 = 0; modelDeployment_B.i3 < 6; modelDeployment_B.i3
       ++) {
    modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3] =
      modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3];
    modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 60] =
      modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3 + 6];
    modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 120] =
      modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3 + 12];
    modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 180] =
      modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3 + 18];
  }

  for (modelDeployment_B.i3 = 0; modelDeployment_B.i3 < 54; modelDeployment_B.i3
       ++) {
    // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
    modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 6] =
      oldCoeffs[modelDeployment_B.i3];
    modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 66] =
      oldCoeffs[modelDeployment_B.i3 + 54];
    modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 126] =
      oldCoeffs[modelDeployment_B.i3 + 108];
    modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 186] =
      oldCoeffs[modelDeployment_B.i3 + 162];
  }

  // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
  modelDeployment_B.breaksWithFlatStart_l[0] = oldbreaks[0] - 1.0;
  memcpy(&modelDeployment_B.breaksWithFlatStart_l[1], &oldbreaks[0], 10U *
         sizeof(real_T));
  modelDeployment_B.holdPoint_h = modelDeployment_B.breaksWithFlatStart_l[10] -
    modelDeployment_B.breaksWithFlatStart_l[9];
  modelDeployment_B.evalPointVector_idx_0_c = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint_h, 3.0);
  modelDeployment_B.evalPointVector_idx_1_c = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint_h, 2.0);
  modelDeployment_B.evalPointVector_idx_2_p = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint_h, 1.0);
  modelDeployment_B.holdPoint_h = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint_h, 0.0);
  memset(&modelDeployment_B.newSegmentCoeffs_l[0], 0, 24U * sizeof(real_T));
  for (modelDeployment_B.i3 = 0; modelDeployment_B.i3 < 6; modelDeployment_B.i3
       ++) {
    // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
    modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3 + 18] =
      ((modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 54] *
        modelDeployment_B.evalPointVector_idx_0_c +
        modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 114] *
        modelDeployment_B.evalPointVector_idx_1_c) +
       modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 174] *
       modelDeployment_B.evalPointVector_idx_2_p) +
      modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 234] *
      modelDeployment_B.holdPoint_h;
  }

  memset(&newCoefs[0], 0, 264U * sizeof(real_T));
  for (modelDeployment_B.i3 = 0; modelDeployment_B.i3 < 60; modelDeployment_B.i3
       ++) {
    // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
    newCoefs[modelDeployment_B.i3] =
      modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3];
    newCoefs[modelDeployment_B.i3 + 66] =
      modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 60];
    newCoefs[modelDeployment_B.i3 + 132] =
      modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 120];
    newCoefs[modelDeployment_B.i3 + 198] =
      modelDeployment_B.coefsWithFlatStart_g[modelDeployment_B.i3 + 180];
  }

  for (modelDeployment_B.i3 = 0; modelDeployment_B.i3 < 6; modelDeployment_B.i3
       ++) {
    newCoefs[modelDeployment_B.i3 + 60] =
      modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3];
    newCoefs[modelDeployment_B.i3 + 126] =
      modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3 + 6];
    newCoefs[modelDeployment_B.i3 + 192] =
      modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3 + 12];
    newCoefs[modelDeployment_B.i3 + 258] =
      modelDeployment_B.newSegmentCoeffs_l[modelDeployment_B.i3 + 18];
  }

  // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
  memcpy(&newBreaks[0], &modelDeployment_B.breaksWithFlatStart_l[0], 11U *
         sizeof(real_T));
  newBreaks[11] = modelDeployment_B.breaksWithFlatStart_l[10] + 1.0;
}

static void PolyTrajSys_updateStoredPPForms(robotics_slcore_internal_bloc_T *obj,
  const real_T pp_breaks[12], const real_T pp_coefs[264])
{
  memset(&obj->PPDStruct.coefs[0], 0, 264U * sizeof(real_T));
  for (modelDeployment_B.b_i_k = 0; modelDeployment_B.b_i_k < 3;
       modelDeployment_B.b_i_k++) {
    for (modelDeployment_B.i10 = 0; modelDeployment_B.i10 < 66;
         modelDeployment_B.i10++) {
      // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
      obj->PPDStruct.coefs[modelDeployment_B.i10 + 66 * (modelDeployment_B.b_i_k
        + 1)] = pp_coefs[modelDeployment_B.b_i_k * 66 + modelDeployment_B.i10] *
        (3.0 - static_cast<real_T>(modelDeployment_B.b_i_k));
    }
  }

  memset(&obj->PPDDStruct.coefs[0], 0, 264U * sizeof(real_T));
  for (modelDeployment_B.b_i_k = 0; modelDeployment_B.b_i_k < 3;
       modelDeployment_B.b_i_k++) {
    for (modelDeployment_B.i10 = 0; modelDeployment_B.i10 < 66;
         modelDeployment_B.i10++) {
      // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
      obj->PPDDStruct.coefs[modelDeployment_B.i10 + 66 *
        (modelDeployment_B.b_i_k + 1)] = obj->
        PPDStruct.coefs[modelDeployment_B.b_i_k * 66 + modelDeployment_B.i10] *
        (3.0 - static_cast<real_T>(modelDeployment_B.b_i_k));
    }
  }

  memcpy(&obj->PPStruct.breaks[0], &pp_breaks[0], 12U * sizeof(real_T));
  memcpy(&obj->PPStruct.coefs[0], &pp_coefs[0], 264U * sizeof(real_T));

  // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
  memcpy(&obj->PPDStruct.breaks[0], &pp_breaks[0], 12U * sizeof(real_T));
  memcpy(&obj->PPDDStruct.breaks[0], &pp_breaks[0], 12U * sizeof(real_T));
}

static void modelDeployment_ppval(const real_T pp_breaks[12], const real_T
  pp_coefs[264], real_T x, real_T v[6])
{
  // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
  if (rtIsNaN(x)) {
    for (modelDeployment_B.low_ip1_h = 0; modelDeployment_B.low_ip1_h < 6;
         modelDeployment_B.low_ip1_h++) {
      v[modelDeployment_B.low_ip1_h] = (rtNaN);
    }
  } else {
    modelDeployment_B.low_i_o4 = 0;
    modelDeployment_B.low_ip1_h = 1;
    modelDeployment_B.high_i_l = 12;
    while (modelDeployment_B.high_i_l > modelDeployment_B.low_ip1_h + 1) {
      modelDeployment_B.mid_i_h = ((modelDeployment_B.low_i_o4 +
        modelDeployment_B.high_i_l) + 1) >> 1;
      if (x >= pp_breaks[modelDeployment_B.mid_i_h - 1]) {
        modelDeployment_B.low_i_o4 = modelDeployment_B.mid_i_h - 1;
        modelDeployment_B.low_ip1_h = modelDeployment_B.mid_i_h;
      } else {
        modelDeployment_B.high_i_l = modelDeployment_B.mid_i_h;
      }
    }

    modelDeployment_B.low_ip1_h = modelDeployment_B.low_i_o4 * 6;
    modelDeployment_B.xloc_e = x - pp_breaks[modelDeployment_B.low_i_o4];
    for (modelDeployment_B.low_i_o4 = 0; modelDeployment_B.low_i_o4 < 6;
         modelDeployment_B.low_i_o4++) {
      v[modelDeployment_B.low_i_o4] = pp_coefs[modelDeployment_B.low_ip1_h +
        modelDeployment_B.low_i_o4];
    }

    for (modelDeployment_B.low_i_o4 = 0; modelDeployment_B.low_i_o4 < 3;
         modelDeployment_B.low_i_o4++) {
      modelDeployment_B.high_i_l = ((modelDeployment_B.low_i_o4 + 1) * 66 +
        modelDeployment_B.low_ip1_h) - 1;
      for (modelDeployment_B.mid_i_h = 0; modelDeployment_B.mid_i_h < 6;
           modelDeployment_B.mid_i_h++) {
        v[modelDeployment_B.mid_i_h] = pp_coefs[(modelDeployment_B.high_i_l +
          modelDeployment_B.mid_i_h) + 1] + modelDeployment_B.xloc_e *
          v[modelDeployment_B.mid_i_h];
      }
    }
  }

  // End of Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
}

static void modelDepl_generateQuinticCoeffs(const real_T posPts[2], const real_T
  velPts[2], const real_T accPts[2], real_T finalTime, real_T coeffVec[6])
{
  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  coeffVec[0] = posPts[0];
  coeffVec[1] = velPts[0];
  coeffVec[2] = accPts[0] / 2.0;
  coeffVec[3] = 0.0;
  coeffVec[4] = 0.0;
  coeffVec[5] = 0.0;
  modelDeployment_B.xtmp = modelDeployment_rt_powd_snf(finalTime, 3.0);
  modelDeployment_B.coeffVec = modelDeployment_rt_powd_snf(finalTime, 4.0);
  modelDeployment_B.dv3[0] = 1.0;
  modelDeployment_B.dv3[3] = finalTime;
  modelDeployment_B.coeffVec_m = finalTime * finalTime;
  modelDeployment_B.dv3[6] = modelDeployment_B.coeffVec_m;
  modelDeployment_B.dv3[1] = 0.0;
  modelDeployment_B.dv3[4] = 1.0;
  modelDeployment_B.dv3[7] = 2.0 * finalTime;
  modelDeployment_B.dv3[2] = 0.0;
  modelDeployment_B.dv3[5] = 0.0;
  modelDeployment_B.dv3[8] = 2.0;
  modelDeployment_B.posPts[0] = posPts[1];
  modelDeployment_B.posPts[1] = velPts[1];
  modelDeployment_B.posPts[2] = accPts[1];
  modelDeployment_B.dv4[0] = 10.0 / modelDeployment_B.xtmp;
  modelDeployment_B.dv4[3] = -4.0 / modelDeployment_B.coeffVec_m;
  modelDeployment_B.dv4[6] = 1.0 / (2.0 * finalTime);
  modelDeployment_B.dv4[1] = -15.0 / modelDeployment_B.coeffVec;
  modelDeployment_B.dv4[4] = 7.0 / modelDeployment_B.xtmp;
  modelDeployment_B.dv4[7] = -1.0 / modelDeployment_B.coeffVec_m;
  modelDeployment_B.dv4[2] = 6.0 / modelDeployment_rt_powd_snf(finalTime, 5.0);
  modelDeployment_B.dv4[5] = -3.0 / modelDeployment_B.coeffVec;
  modelDeployment_B.dv4[8] = 1.0 / (2.0 * modelDeployment_B.xtmp);
  modelDeployment_B.xtmp = velPts[0];
  modelDeployment_B.coeffVec = posPts[0];
  modelDeployment_B.coeffVec_m = coeffVec[2];
  for (modelDeployment_B.i1 = 0; modelDeployment_B.i1 < 3; modelDeployment_B.i1
       ++) {
    modelDeployment_B.posPts_j[modelDeployment_B.i1] =
      modelDeployment_B.posPts[modelDeployment_B.i1] -
      ((modelDeployment_B.dv3[modelDeployment_B.i1 + 3] * modelDeployment_B.xtmp
        + modelDeployment_B.dv3[modelDeployment_B.i1] *
        modelDeployment_B.coeffVec) + modelDeployment_B.dv3[modelDeployment_B.i1
       + 6] * modelDeployment_B.coeffVec_m);
  }

  modelDeployment_B.xtmp = modelDeployment_B.posPts_j[1];
  modelDeployment_B.coeffVec = modelDeployment_B.posPts_j[0];
  modelDeployment_B.coeffVec_m = modelDeployment_B.posPts_j[2];
  for (modelDeployment_B.i1 = 0; modelDeployment_B.i1 < 3; modelDeployment_B.i1
       ++) {
    coeffVec[modelDeployment_B.i1 + 3] =
      (modelDeployment_B.dv4[modelDeployment_B.i1 + 3] * modelDeployment_B.xtmp
       + modelDeployment_B.dv4[modelDeployment_B.i1] *
       modelDeployment_B.coeffVec) + modelDeployment_B.dv4[modelDeployment_B.i1
      + 6] * modelDeployment_B.coeffVec_m;
  }

  modelDeployment_B.xtmp = coeffVec[0];

  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  coeffVec[0] = coeffVec[5];
  coeffVec[5] = modelDeployment_B.xtmp;
  modelDeployment_B.xtmp = coeffVec[1];

  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  coeffVec[1] = coeffVec[4];
  coeffVec[4] = modelDeployment_B.xtmp;
  modelDeployment_B.xtmp = coeffVec[2];

  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  coeffVec[2] = coeffVec[3];
  coeffVec[3] = modelDeployment_B.xtmp;
}

static void addFlatSegmentsToPPFormParts_f(const real_T oldbreaks[21], const
  real_T oldCoeffs[720], real_T newBreaks[23], real_T newCoefs[792])
{
  static const int8_T tmp[6] = { 0, 0, 0, 0, 0, 1 };

  memset(&modelDeployment_B.newSegmentCoeffs[0], 0, 36U * sizeof(real_T));
  for (modelDeployment_B.b_i_m = 0; modelDeployment_B.b_i_m < 6;
       modelDeployment_B.b_i_m++) {
    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    modelDeployment_B.holdPoint_a = 0.0;
    for (modelDeployment_B.i4 = 0; modelDeployment_B.i4 < 6;
         modelDeployment_B.i4++) {
      // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
      modelDeployment_B.holdPoint_a += oldCoeffs[120 * modelDeployment_B.i4 +
        modelDeployment_B.b_i_m] * static_cast<real_T>(tmp[modelDeployment_B.i4]);
    }

    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    modelDeployment_B.newSegmentCoeffs[modelDeployment_B.b_i_m + 30] =
      modelDeployment_B.holdPoint_a;
  }

  for (modelDeployment_B.b_i_m = 0; modelDeployment_B.b_i_m < 6;
       modelDeployment_B.b_i_m++) {
    for (modelDeployment_B.i4 = 0; modelDeployment_B.i4 < 6;
         modelDeployment_B.i4++) {
      modelDeployment_B.coefsWithFlatStart[modelDeployment_B.i4 + 126 *
        modelDeployment_B.b_i_m] = modelDeployment_B.newSegmentCoeffs[6 *
        modelDeployment_B.b_i_m + modelDeployment_B.i4];
    }

    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    memcpy(&modelDeployment_B.coefsWithFlatStart[modelDeployment_B.b_i_m * 126 +
           6], &oldCoeffs[modelDeployment_B.b_i_m * 120], 120U * sizeof(real_T));
  }

  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  modelDeployment_B.breaksWithFlatStart[0] = oldbreaks[0] - 1.0;
  memcpy(&modelDeployment_B.breaksWithFlatStart[1], &oldbreaks[0], 21U * sizeof
         (real_T));
  modelDeployment_B.holdPoint_a = modelDeployment_B.breaksWithFlatStart[21] -
    modelDeployment_B.breaksWithFlatStart[20];
  for (modelDeployment_B.b_i_m = 0; modelDeployment_B.b_i_m < 6;
       modelDeployment_B.b_i_m++) {
    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    modelDeployment_B.evalPointVector[modelDeployment_B.b_i_m] =
      modelDeployment_rt_powd_snf(modelDeployment_B.holdPoint_a, 6.0 - (
      static_cast<real_T>(modelDeployment_B.b_i_m) + 1.0));
  }

  memset(&modelDeployment_B.newSegmentCoeffs[0], 0, 36U * sizeof(real_T));
  for (modelDeployment_B.b_i_m = 0; modelDeployment_B.b_i_m < 6;
       modelDeployment_B.b_i_m++) {
    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    modelDeployment_B.holdPoint_a = 0.0;
    for (modelDeployment_B.i4 = 0; modelDeployment_B.i4 < 6;
         modelDeployment_B.i4++) {
      // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
      modelDeployment_B.holdPoint_a += modelDeployment_B.coefsWithFlatStart[(126
        * modelDeployment_B.i4 + modelDeployment_B.b_i_m) + 120] *
        modelDeployment_B.evalPointVector[modelDeployment_B.i4];
    }

    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    modelDeployment_B.newSegmentCoeffs[modelDeployment_B.b_i_m + 30] =
      modelDeployment_B.holdPoint_a;
  }

  for (modelDeployment_B.b_i_m = 0; modelDeployment_B.b_i_m < 6;
       modelDeployment_B.b_i_m++) {
    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    memcpy(&newCoefs[modelDeployment_B.b_i_m * 132],
           &modelDeployment_B.coefsWithFlatStart[modelDeployment_B.b_i_m * 126],
           126U * sizeof(real_T));
    for (modelDeployment_B.i4 = 0; modelDeployment_B.i4 < 6;
         modelDeployment_B.i4++) {
      newCoefs[(modelDeployment_B.i4 + 132 * modelDeployment_B.b_i_m) + 126] =
        modelDeployment_B.newSegmentCoeffs[6 * modelDeployment_B.b_i_m +
        modelDeployment_B.i4];
    }
  }

  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  memcpy(&newBreaks[0], &modelDeployment_B.breaksWithFlatStart[0], 22U * sizeof
         (real_T));
  newBreaks[22] = modelDeployment_B.breaksWithFlatStart[21] + 1.0;
}

static void PolyTrajSys_updateStoredPPFor_f(robotics_slcore_internal_bl_f_T *obj,
  const real_T pp_breaks[23], const real_T pp_coefs[792])
{
  memset(&obj->PPDStruct.coefs[0], 0, 792U * sizeof(real_T));
  for (modelDeployment_B.b_i_c = 0; modelDeployment_B.b_i_c < 5;
       modelDeployment_B.b_i_c++) {
    for (modelDeployment_B.i9 = 0; modelDeployment_B.i9 < 132;
         modelDeployment_B.i9++) {
      // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
      obj->PPDStruct.coefs[modelDeployment_B.i9 + 132 * (modelDeployment_B.b_i_c
        + 1)] = pp_coefs[modelDeployment_B.b_i_c * 132 + modelDeployment_B.i9] *
        (5.0 - static_cast<real_T>(modelDeployment_B.b_i_c));
    }
  }

  memset(&obj->PPDDStruct.coefs[0], 0, 792U * sizeof(real_T));
  for (modelDeployment_B.b_i_c = 0; modelDeployment_B.b_i_c < 5;
       modelDeployment_B.b_i_c++) {
    for (modelDeployment_B.i9 = 0; modelDeployment_B.i9 < 132;
         modelDeployment_B.i9++) {
      // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
      obj->PPDDStruct.coefs[modelDeployment_B.i9 + 132 *
        (modelDeployment_B.b_i_c + 1)] = obj->
        PPDStruct.coefs[modelDeployment_B.b_i_c * 132 + modelDeployment_B.i9] *
        (5.0 - static_cast<real_T>(modelDeployment_B.b_i_c));
    }
  }

  memcpy(&obj->PPStruct.breaks[0], &pp_breaks[0], 23U * sizeof(real_T));
  memcpy(&obj->PPStruct.coefs[0], &pp_coefs[0], 792U * sizeof(real_T));

  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  memcpy(&obj->PPDStruct.breaks[0], &pp_breaks[0], 23U * sizeof(real_T));
  memcpy(&obj->PPDDStruct.breaks[0], &pp_breaks[0], 23U * sizeof(real_T));
}

static void modelDeployment_ppval_f(const real_T pp_breaks[23], const real_T
  pp_coefs[792], real_T x, real_T v[6])
{
  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  if (rtIsNaN(x)) {
    for (modelDeployment_B.low_ip1_f = 0; modelDeployment_B.low_ip1_f < 6;
         modelDeployment_B.low_ip1_f++) {
      v[modelDeployment_B.low_ip1_f] = (rtNaN);
    }
  } else {
    modelDeployment_B.low_i_c = 0;
    modelDeployment_B.low_ip1_f = 1;
    modelDeployment_B.high_i_p = 23;
    while (modelDeployment_B.high_i_p > modelDeployment_B.low_ip1_f + 1) {
      modelDeployment_B.mid_i_e = ((modelDeployment_B.low_i_c +
        modelDeployment_B.high_i_p) + 1) >> 1;
      if (x >= pp_breaks[modelDeployment_B.mid_i_e - 1]) {
        modelDeployment_B.low_i_c = modelDeployment_B.mid_i_e - 1;
        modelDeployment_B.low_ip1_f = modelDeployment_B.mid_i_e;
      } else {
        modelDeployment_B.high_i_p = modelDeployment_B.mid_i_e;
      }
    }

    modelDeployment_B.low_ip1_f = modelDeployment_B.low_i_c * 6;
    modelDeployment_B.xloc_a = x - pp_breaks[modelDeployment_B.low_i_c];
    for (modelDeployment_B.low_i_c = 0; modelDeployment_B.low_i_c < 6;
         modelDeployment_B.low_i_c++) {
      v[modelDeployment_B.low_i_c] = pp_coefs[modelDeployment_B.low_ip1_f +
        modelDeployment_B.low_i_c];
    }

    for (modelDeployment_B.low_i_c = 0; modelDeployment_B.low_i_c < 5;
         modelDeployment_B.low_i_c++) {
      modelDeployment_B.high_i_p = ((modelDeployment_B.low_i_c + 1) * 132 +
        modelDeployment_B.low_ip1_f) - 1;
      for (modelDeployment_B.mid_i_e = 0; modelDeployment_B.mid_i_e < 6;
           modelDeployment_B.mid_i_e++) {
        v[modelDeployment_B.mid_i_e] = pp_coefs[(modelDeployment_B.high_i_p +
          modelDeployment_B.mid_i_e) + 1] + modelDeployment_B.xloc_a *
          v[modelDeployment_B.mid_i_e];
      }
    }
  }

  // End of Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
}

static void addFlatSegmentsToPPFormParts_fj(const real_T oldbreaks[6], const
  real_T oldCoeffs[120], real_T newBreaks[8], real_T newCoefs[168])
{
  memset(&modelDeployment_B.newSegmentCoeffs_d[0], 0, 24U * sizeof(real_T));
  for (modelDeployment_B.i2 = 0; modelDeployment_B.i2 < 6; modelDeployment_B.i2
       ++) {
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2 + 18] =
      ((oldCoeffs[modelDeployment_B.i2 + 30] * 0.0 +
        oldCoeffs[modelDeployment_B.i2] * 0.0) + oldCoeffs[modelDeployment_B.i2
       + 60] * 0.0) + oldCoeffs[modelDeployment_B.i2 + 90];
  }

  memset(&modelDeployment_B.coefsWithFlatStart_l[0], 0, 144U * sizeof(real_T));
  for (modelDeployment_B.i2 = 0; modelDeployment_B.i2 < 6; modelDeployment_B.i2
       ++) {
    modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2] =
      modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2];
    modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 36] =
      modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2 + 6];
    modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 72] =
      modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2 + 12];
    modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 108] =
      modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2 + 18];
  }

  for (modelDeployment_B.i2 = 0; modelDeployment_B.i2 < 30; modelDeployment_B.i2
       ++) {
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 6] =
      oldCoeffs[modelDeployment_B.i2];
    modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 42] =
      oldCoeffs[modelDeployment_B.i2 + 30];
    modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 78] =
      oldCoeffs[modelDeployment_B.i2 + 60];
    modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 114] =
      oldCoeffs[modelDeployment_B.i2 + 90];
  }

  // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
  modelDeployment_B.breaksWithFlatStart_d[0] = oldbreaks[0] - 1.0;
  for (modelDeployment_B.i2 = 0; modelDeployment_B.i2 < 6; modelDeployment_B.i2
       ++) {
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    modelDeployment_B.breaksWithFlatStart_d[modelDeployment_B.i2 + 1] =
      oldbreaks[modelDeployment_B.i2];
  }

  // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
  modelDeployment_B.holdPoint_c = modelDeployment_B.breaksWithFlatStart_d[6] -
    modelDeployment_B.breaksWithFlatStart_d[5];
  modelDeployment_B.evalPointVector_idx_0_m = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint_c, 3.0);
  modelDeployment_B.evalPointVector_idx_1_m = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint_c, 2.0);
  modelDeployment_B.evalPointVector_idx_2_j = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint_c, 1.0);
  modelDeployment_B.holdPoint_c = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint_c, 0.0);
  memset(&modelDeployment_B.newSegmentCoeffs_d[0], 0, 24U * sizeof(real_T));
  for (modelDeployment_B.i2 = 0; modelDeployment_B.i2 < 6; modelDeployment_B.i2
       ++) {
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2 + 18] =
      ((modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 30] *
        modelDeployment_B.evalPointVector_idx_0_m +
        modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 66] *
        modelDeployment_B.evalPointVector_idx_1_m) +
       modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 102] *
       modelDeployment_B.evalPointVector_idx_2_j) +
      modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 138] *
      modelDeployment_B.holdPoint_c;
  }

  memset(&newCoefs[0], 0, 168U * sizeof(real_T));
  for (modelDeployment_B.i2 = 0; modelDeployment_B.i2 < 36; modelDeployment_B.i2
       ++) {
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    newCoefs[modelDeployment_B.i2] =
      modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2];
    newCoefs[modelDeployment_B.i2 + 42] =
      modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 36];
    newCoefs[modelDeployment_B.i2 + 84] =
      modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 72];
    newCoefs[modelDeployment_B.i2 + 126] =
      modelDeployment_B.coefsWithFlatStart_l[modelDeployment_B.i2 + 108];
  }

  for (modelDeployment_B.i2 = 0; modelDeployment_B.i2 < 6; modelDeployment_B.i2
       ++) {
    newCoefs[modelDeployment_B.i2 + 36] =
      modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2];
    newCoefs[modelDeployment_B.i2 + 78] =
      modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2 + 6];
    newCoefs[modelDeployment_B.i2 + 120] =
      modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2 + 12];
    newCoefs[modelDeployment_B.i2 + 162] =
      modelDeployment_B.newSegmentCoeffs_d[modelDeployment_B.i2 + 18];
  }

  for (modelDeployment_B.i2 = 0; modelDeployment_B.i2 < 7; modelDeployment_B.i2
       ++) {
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    newBreaks[modelDeployment_B.i2] =
      modelDeployment_B.breaksWithFlatStart_d[modelDeployment_B.i2];
  }

  // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
  newBreaks[7] = modelDeployment_B.breaksWithFlatStart_d[6] + 1.0;
}

static void PolyTrajSys_updateStoredPPFo_fj(robotics_slcore_internal_b_fj_T *obj,
  const real_T pp_breaks[8], const real_T pp_coefs[168])
{
  memset(&obj->PPDStruct.coefs[0], 0, 168U * sizeof(real_T));
  for (modelDeployment_B.b_i_h = 0; modelDeployment_B.b_i_h < 3;
       modelDeployment_B.b_i_h++) {
    for (modelDeployment_B.i8 = 0; modelDeployment_B.i8 < 42;
         modelDeployment_B.i8++) {
      // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
      obj->PPDStruct.coefs[modelDeployment_B.i8 + 42 * (modelDeployment_B.b_i_h
        + 1)] = pp_coefs[modelDeployment_B.b_i_h * 42 + modelDeployment_B.i8] *
        (3.0 - static_cast<real_T>(modelDeployment_B.b_i_h));
    }
  }

  memset(&obj->PPDDStruct.coefs[0], 0, 168U * sizeof(real_T));
  for (modelDeployment_B.b_i_h = 0; modelDeployment_B.b_i_h < 3;
       modelDeployment_B.b_i_h++) {
    for (modelDeployment_B.i8 = 0; modelDeployment_B.i8 < 42;
         modelDeployment_B.i8++) {
      // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
      obj->PPDDStruct.coefs[modelDeployment_B.i8 + 42 * (modelDeployment_B.b_i_h
        + 1)] = obj->PPDStruct.coefs[modelDeployment_B.b_i_h * 42 +
        modelDeployment_B.i8] * (3.0 - static_cast<real_T>
        (modelDeployment_B.b_i_h));
    }
  }

  memcpy(&obj->PPStruct.breaks[0], &pp_breaks[0], sizeof(real_T) << 3U);
  memcpy(&obj->PPStruct.coefs[0], &pp_coefs[0], 168U * sizeof(real_T));

  // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
  memcpy(&obj->PPDStruct.breaks[0], &pp_breaks[0], sizeof(real_T) << 3U);
  memcpy(&obj->PPDDStruct.breaks[0], &pp_breaks[0], sizeof(real_T) << 3U);
}

static void modelDeployment_ppval_fj(const real_T pp_breaks[8], const real_T
  pp_coefs[168], real_T x, real_T v[6])
{
  // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
  if (rtIsNaN(x)) {
    for (modelDeployment_B.low_ip1_l = 0; modelDeployment_B.low_ip1_l < 6;
         modelDeployment_B.low_ip1_l++) {
      v[modelDeployment_B.low_ip1_l] = (rtNaN);
    }
  } else {
    modelDeployment_B.low_i_o = 0;
    modelDeployment_B.low_ip1_l = 1;
    modelDeployment_B.high_i_m = 8;
    while (modelDeployment_B.high_i_m > modelDeployment_B.low_ip1_l + 1) {
      modelDeployment_B.mid_i_m = ((modelDeployment_B.low_i_o +
        modelDeployment_B.high_i_m) + 1) >> 1;
      if (x >= pp_breaks[modelDeployment_B.mid_i_m - 1]) {
        modelDeployment_B.low_i_o = modelDeployment_B.mid_i_m - 1;
        modelDeployment_B.low_ip1_l = modelDeployment_B.mid_i_m;
      } else {
        modelDeployment_B.high_i_m = modelDeployment_B.mid_i_m;
      }
    }

    modelDeployment_B.low_ip1_l = modelDeployment_B.low_i_o * 6;
    modelDeployment_B.xloc_p = x - pp_breaks[modelDeployment_B.low_i_o];
    for (modelDeployment_B.low_i_o = 0; modelDeployment_B.low_i_o < 6;
         modelDeployment_B.low_i_o++) {
      v[modelDeployment_B.low_i_o] = pp_coefs[modelDeployment_B.low_ip1_l +
        modelDeployment_B.low_i_o];
    }

    for (modelDeployment_B.low_i_o = 0; modelDeployment_B.low_i_o < 3;
         modelDeployment_B.low_i_o++) {
      modelDeployment_B.high_i_m = ((modelDeployment_B.low_i_o + 1) * 42 +
        modelDeployment_B.low_ip1_l) - 1;
      for (modelDeployment_B.mid_i_m = 0; modelDeployment_B.mid_i_m < 6;
           modelDeployment_B.mid_i_m++) {
        v[modelDeployment_B.mid_i_m] = pp_coefs[(modelDeployment_B.high_i_m +
          modelDeployment_B.mid_i_m) + 1] + modelDeployment_B.xloc_p *
          v[modelDeployment_B.mid_i_m];
      }
    }
  }

  // End of Start for MATLABSystem: '<S90>/Polynomial Trajectory'
}

static void addFlatSegmentsToPPFormPart_fjc(const real_T oldbreaks[12], const
  real_T oldCoeffs[264], real_T newBreaks[14], real_T newCoefs[312])
{
  memset(&modelDeployment_B.newSegmentCoeffs_g[0], 0, 24U * sizeof(real_T));
  for (modelDeployment_B.i_c = 0; modelDeployment_B.i_c < 6;
       modelDeployment_B.i_c++) {
    // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
    modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c + 18] =
      ((oldCoeffs[modelDeployment_B.i_c + 66] * 0.0 +
        oldCoeffs[modelDeployment_B.i_c] * 0.0) +
       oldCoeffs[modelDeployment_B.i_c + 132] * 0.0) +
      oldCoeffs[modelDeployment_B.i_c + 198];
  }

  memset(&modelDeployment_B.coefsWithFlatStart_b[0], 0, 288U * sizeof(real_T));
  for (modelDeployment_B.i_c = 0; modelDeployment_B.i_c < 6;
       modelDeployment_B.i_c++) {
    modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c] =
      modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c];
    modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 72] =
      modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c + 6];
    modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 144] =
      modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c + 12];
    modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 216] =
      modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c + 18];
  }

  for (modelDeployment_B.i_c = 0; modelDeployment_B.i_c < 66;
       modelDeployment_B.i_c++) {
    // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
    modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 6] =
      oldCoeffs[modelDeployment_B.i_c];
    modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 78] =
      oldCoeffs[modelDeployment_B.i_c + 66];
    modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 150] =
      oldCoeffs[modelDeployment_B.i_c + 132];
    modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 222] =
      oldCoeffs[modelDeployment_B.i_c + 198];
  }

  // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
  modelDeployment_B.breaksWithFlatStart_b[0] = oldbreaks[0] - 1.0;
  memcpy(&modelDeployment_B.breaksWithFlatStart_b[1], &oldbreaks[0], 12U *
         sizeof(real_T));
  modelDeployment_B.holdPoint = modelDeployment_B.breaksWithFlatStart_b[12] -
    modelDeployment_B.breaksWithFlatStart_b[11];
  modelDeployment_B.evalPointVector_idx_0 = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint, 3.0);
  modelDeployment_B.evalPointVector_idx_1 = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint, 2.0);
  modelDeployment_B.evalPointVector_idx_2 = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint, 1.0);
  modelDeployment_B.holdPoint = modelDeployment_rt_powd_snf
    (modelDeployment_B.holdPoint, 0.0);
  memset(&modelDeployment_B.newSegmentCoeffs_g[0], 0, 24U * sizeof(real_T));
  for (modelDeployment_B.i_c = 0; modelDeployment_B.i_c < 6;
       modelDeployment_B.i_c++) {
    // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
    modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c + 18] =
      ((modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 66] *
        modelDeployment_B.evalPointVector_idx_0 +
        modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 138] *
        modelDeployment_B.evalPointVector_idx_1) +
       modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 210] *
       modelDeployment_B.evalPointVector_idx_2) +
      modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 282] *
      modelDeployment_B.holdPoint;
  }

  memset(&newCoefs[0], 0, 312U * sizeof(real_T));
  for (modelDeployment_B.i_c = 0; modelDeployment_B.i_c < 72;
       modelDeployment_B.i_c++) {
    // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
    newCoefs[modelDeployment_B.i_c] =
      modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c];
    newCoefs[modelDeployment_B.i_c + 78] =
      modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 72];
    newCoefs[modelDeployment_B.i_c + 156] =
      modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 144];
    newCoefs[modelDeployment_B.i_c + 234] =
      modelDeployment_B.coefsWithFlatStart_b[modelDeployment_B.i_c + 216];
  }

  for (modelDeployment_B.i_c = 0; modelDeployment_B.i_c < 6;
       modelDeployment_B.i_c++) {
    newCoefs[modelDeployment_B.i_c + 72] =
      modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c];
    newCoefs[modelDeployment_B.i_c + 150] =
      modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c + 6];
    newCoefs[modelDeployment_B.i_c + 228] =
      modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c + 12];
    newCoefs[modelDeployment_B.i_c + 306] =
      modelDeployment_B.newSegmentCoeffs_g[modelDeployment_B.i_c + 18];
  }

  // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
  memcpy(&newBreaks[0], &modelDeployment_B.breaksWithFlatStart_b[0], 13U *
         sizeof(real_T));
  newBreaks[13] = modelDeployment_B.breaksWithFlatStart_b[12] + 1.0;
}

static void PolyTrajSys_updateStoredPPF_fjc(robotics_slcore_internal__fjc_T *obj,
  const real_T pp_breaks[14], const real_T pp_coefs[312])
{
  memset(&obj->PPDStruct.coefs[0], 0, 312U * sizeof(real_T));
  for (modelDeployment_B.b_i_mc = 0; modelDeployment_B.b_i_mc < 3;
       modelDeployment_B.b_i_mc++) {
    for (modelDeployment_B.i7 = 0; modelDeployment_B.i7 < 78;
         modelDeployment_B.i7++) {
      // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
      obj->PPDStruct.coefs[modelDeployment_B.i7 + 78 * (modelDeployment_B.b_i_mc
        + 1)] = pp_coefs[modelDeployment_B.b_i_mc * 78 + modelDeployment_B.i7] *
        (3.0 - static_cast<real_T>(modelDeployment_B.b_i_mc));
    }
  }

  memset(&obj->PPDDStruct.coefs[0], 0, 312U * sizeof(real_T));
  for (modelDeployment_B.b_i_mc = 0; modelDeployment_B.b_i_mc < 3;
       modelDeployment_B.b_i_mc++) {
    for (modelDeployment_B.i7 = 0; modelDeployment_B.i7 < 78;
         modelDeployment_B.i7++) {
      // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
      obj->PPDDStruct.coefs[modelDeployment_B.i7 + 78 *
        (modelDeployment_B.b_i_mc + 1)] = obj->
        PPDStruct.coefs[modelDeployment_B.b_i_mc * 78 + modelDeployment_B.i7] *
        (3.0 - static_cast<real_T>(modelDeployment_B.b_i_mc));
    }
  }

  memcpy(&obj->PPStruct.breaks[0], &pp_breaks[0], 14U * sizeof(real_T));
  memcpy(&obj->PPStruct.coefs[0], &pp_coefs[0], 312U * sizeof(real_T));

  // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
  memcpy(&obj->PPDStruct.breaks[0], &pp_breaks[0], 14U * sizeof(real_T));
  memcpy(&obj->PPDDStruct.breaks[0], &pp_breaks[0], 14U * sizeof(real_T));
}

static void modelDeployment_ppval_fjc(const real_T pp_breaks[14], const real_T
  pp_coefs[312], real_T x, real_T v[6])
{
  // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
  if (rtIsNaN(x)) {
    for (modelDeployment_B.low_ip1 = 0; modelDeployment_B.low_ip1 < 6;
         modelDeployment_B.low_ip1++) {
      v[modelDeployment_B.low_ip1] = (rtNaN);
    }
  } else {
    modelDeployment_B.low_i = 0;
    modelDeployment_B.low_ip1 = 1;
    modelDeployment_B.high_i = 14;
    while (modelDeployment_B.high_i > modelDeployment_B.low_ip1 + 1) {
      modelDeployment_B.mid_i = ((modelDeployment_B.low_i +
        modelDeployment_B.high_i) + 1) >> 1;
      if (x >= pp_breaks[modelDeployment_B.mid_i - 1]) {
        modelDeployment_B.low_i = modelDeployment_B.mid_i - 1;
        modelDeployment_B.low_ip1 = modelDeployment_B.mid_i;
      } else {
        modelDeployment_B.high_i = modelDeployment_B.mid_i;
      }
    }

    modelDeployment_B.low_ip1 = modelDeployment_B.low_i * 6;
    modelDeployment_B.xloc = x - pp_breaks[modelDeployment_B.low_i];
    for (modelDeployment_B.low_i = 0; modelDeployment_B.low_i < 6;
         modelDeployment_B.low_i++) {
      v[modelDeployment_B.low_i] = pp_coefs[modelDeployment_B.low_ip1 +
        modelDeployment_B.low_i];
    }

    for (modelDeployment_B.low_i = 0; modelDeployment_B.low_i < 3;
         modelDeployment_B.low_i++) {
      modelDeployment_B.high_i = ((modelDeployment_B.low_i + 1) * 78 +
        modelDeployment_B.low_ip1) - 1;
      for (modelDeployment_B.mid_i = 0; modelDeployment_B.mid_i < 6;
           modelDeployment_B.mid_i++) {
        v[modelDeployment_B.mid_i] = pp_coefs[(modelDeployment_B.high_i +
          modelDeployment_B.mid_i) + 1] + modelDeployment_B.xloc *
          v[modelDeployment_B.mid_i];
      }
    }
  }

  // End of Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
}

static real_T modelDeployment_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      modelDeployment_B.i5 = 1;
    } else {
      modelDeployment_B.i5 = -1;
    }

    if (u1 > 0.0) {
      modelDeployment_B.i6 = 1;
    } else {
      modelDeployment_B.i6 = -1;
    }

    y = atan2(static_cast<real_T>(modelDeployment_B.i5), static_cast<real_T>
              (modelDeployment_B.i6));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void modelDepl_PolyTrajSys_setupImpl(robotics_slcore_internal_bloc_T *obj)
{
  int32_T b_j;
  int32_T i;
  int32_T obj_tmp;
  for (i = 0; i < 60; i++) {
    // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
    obj->PrevOptInputs.f1[i] = 1.0;
  }

  for (i = 0; i < 10; i++) {
    // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
    obj->PrevOptInputs.f2[i] = 1.0;
  }

  memset(&modelDeployment_B.coefMat_m[0], 0, 216U * sizeof(real_T));

  // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
  modelDeployment_B.dv14[0] = 1.0;
  modelDeployment_B.dv14[1] = 1.0;
  for (i = 0; i < 9; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
      obj_tmp = i * 6 + b_j;
      modelDeployment_B.obj[0] = obj->VelocityBoundaryCondition[obj_tmp];
      modelDeployment_B.obj[1] = obj->VelocityBoundaryCondition[(i + 1) * 6 +
        b_j];
      modelDeploy_generateCubicCoeffs(modelDeployment_B.dv14,
        modelDeployment_B.obj, 1.0, modelDeployment_B.dv8);
      modelDeployment_B.coefMat_m[obj_tmp] = modelDeployment_B.dv8[0];
      modelDeployment_B.coefMat_m[obj_tmp + 54] = modelDeployment_B.dv8[1];
      modelDeployment_B.coefMat_m[obj_tmp + 108] = modelDeployment_B.dv8[2];
      modelDeployment_B.coefMat_m[obj_tmp + 162] = modelDeployment_B.dv8[3];
    }
  }

  for (i = 0; i < 10; i++) {
    modelDeployment_B.dv2[i] = static_cast<real_T>(i) + 1.0;
  }

  mo_addFlatSegmentsToPPFormParts(modelDeployment_B.dv2,
    modelDeployment_B.coefMat_m, modelDeployment_B.modBreaks_b,
    modelDeployment_B.modCoeffs_cv);

  // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
  PolyTrajSys_updateStoredPPForms(obj, modelDeployment_B.modBreaks_b,
    modelDeployment_B.modCoeffs_cv);
  obj->PPFormUpdatedNeeded = false;
}

static void modelDe_PolyTrajSys_setupImpl_f(robotics_slcore_internal_bl_f_T *obj)
{
  real_T obj_0[2];
  int32_T b_j;
  int32_T i;
  int32_T obj_tmp;
  int32_T obj_tmp_0;
  for (obj_tmp_0 = 0; obj_tmp_0 < 126; obj_tmp_0++) {
    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    obj->PrevOptInputs.f1[obj_tmp_0] = 1.0;
  }

  for (i = 0; i < 21; i++) {
    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    obj->PrevOptInputs.f2[i] = 1.0;
  }

  memset(&modelDeployment_B.coefMat_c[0], 0, 720U * sizeof(real_T));

  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  modelDeployment_B.dv17[0] = 1.0;
  modelDeployment_B.dv17[1] = 1.0;
  for (i = 0; i < 20; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
      obj_tmp = i * 6 + b_j;
      modelDeployment_B.obj_a[0] = obj->VelocityBoundaryCondition[obj_tmp];
      obj_0[0] = obj->AccelerationBoundaryCondition[obj_tmp];
      obj_tmp_0 = (i + 1) * 6 + b_j;
      modelDeployment_B.obj_a[1] = obj->VelocityBoundaryCondition[obj_tmp_0];
      obj_0[1] = obj->AccelerationBoundaryCondition[obj_tmp_0];
      modelDepl_generateQuinticCoeffs(modelDeployment_B.dv17,
        modelDeployment_B.obj_a, obj_0, 1.0, modelDeployment_B.dv6);
      for (obj_tmp_0 = 0; obj_tmp_0 < 6; obj_tmp_0++) {
        modelDeployment_B.coefMat_c[obj_tmp + 120 * obj_tmp_0] =
          modelDeployment_B.dv6[obj_tmp_0];
      }
    }
  }

  for (obj_tmp_0 = 0; obj_tmp_0 < 21; obj_tmp_0++) {
    modelDeployment_B.dv[obj_tmp_0] = static_cast<real_T>(obj_tmp_0) + 1.0;
  }

  addFlatSegmentsToPPFormParts_f(modelDeployment_B.dv,
    modelDeployment_B.coefMat_c, modelDeployment_B.modBreaks_d,
    modelDeployment_B.modCoeffs_m);

  // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
  PolyTrajSys_updateStoredPPFor_f(obj, modelDeployment_B.modBreaks_d,
    modelDeployment_B.modCoeffs_m);
  obj->PPFormUpdatedNeeded = false;
}

static void modelD_PolyTrajSys_setupImpl_fj(robotics_slcore_internal_b_fj_T *obj)
{
  int32_T b_j;
  int32_T i;
  int32_T obj_tmp;
  for (i = 0; i < 36; i++) {
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    obj->PrevOptInputs.f1[i] = 1.0;
  }

  for (i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    obj->PrevOptInputs.f2[i] = 1.0;
  }

  memset(&modelDeployment_B.coefMat_d[0], 0, 120U * sizeof(real_T));

  // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
  modelDeployment_B.dv16[0] = 1.0;
  modelDeployment_B.dv16[1] = 1.0;
  for (i = 0; i < 5; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
      obj_tmp = i * 6 + b_j;
      modelDeployment_B.obj_f[0] = obj->VelocityBoundaryCondition[obj_tmp];
      modelDeployment_B.obj_f[1] = obj->VelocityBoundaryCondition[(i + 1) * 6 +
        b_j];
      modelDeploy_generateCubicCoeffs(modelDeployment_B.dv16,
        modelDeployment_B.obj_f, 1.0, modelDeployment_B.dv10);
      modelDeployment_B.coefMat_d[obj_tmp] = modelDeployment_B.dv10[0];
      modelDeployment_B.coefMat_d[obj_tmp + 30] = modelDeployment_B.dv10[1];
      modelDeployment_B.coefMat_d[obj_tmp + 60] = modelDeployment_B.dv10[2];
      modelDeployment_B.coefMat_d[obj_tmp + 90] = modelDeployment_B.dv10[3];
    }
  }

  for (i = 0; i < 6; i++) {
    modelDeployment_B.dv5[i] = static_cast<real_T>(i) + 1.0;
  }

  addFlatSegmentsToPPFormParts_fj(modelDeployment_B.dv5,
    modelDeployment_B.coefMat_d, modelDeployment_B.modBreaks_bn,
    modelDeployment_B.modCoeffs_p);

  // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
  PolyTrajSys_updateStoredPPFo_fj(obj, modelDeployment_B.modBreaks_bn,
    modelDeployment_B.modCoeffs_p);
  obj->PPFormUpdatedNeeded = false;
}

static void model_PolyTrajSys_setupImpl_fjc(robotics_slcore_internal__fjc_T *obj)
{
  real_T obj_0[2];
  int32_T b_j;
  int32_T i;
  int32_T obj_tmp;
  for (i = 0; i < 72; i++) {
    // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
    obj->PrevOptInputs.f1[i] = 1.0;
  }

  for (i = 0; i < 12; i++) {
    // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
    obj->PrevOptInputs.f2[i] = 1.0;
  }

  memset(&modelDeployment_B.coefMat_f[0], 0, 264U * sizeof(real_T));

  // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
  modelDeployment_B.dv15[0] = 1.0;
  modelDeployment_B.dv15[1] = 1.0;
  for (i = 0; i < 11; i++) {
    for (b_j = 0; b_j < 6; b_j++) {
      // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
      obj_tmp = i * 6 + b_j;
      obj_0[0] = obj->VelocityBoundaryCondition[obj_tmp];
      obj_0[1] = obj->VelocityBoundaryCondition[(i + 1) * 6 + b_j];
      modelDeploy_generateCubicCoeffs(modelDeployment_B.dv15, obj_0, 1.0,
        modelDeployment_B.dv9);
      modelDeployment_B.coefMat_f[obj_tmp] = modelDeployment_B.dv9[0];
      modelDeployment_B.coefMat_f[obj_tmp + 66] = modelDeployment_B.dv9[1];
      modelDeployment_B.coefMat_f[obj_tmp + 132] = modelDeployment_B.dv9[2];
      modelDeployment_B.coefMat_f[obj_tmp + 198] = modelDeployment_B.dv9[3];
    }
  }

  for (i = 0; i < 12; i++) {
    modelDeployment_B.dv1[i] = static_cast<real_T>(i) + 1.0;
  }

  addFlatSegmentsToPPFormPart_fjc(modelDeployment_B.dv1,
    modelDeployment_B.coefMat_f, modelDeployment_B.modBreaks_o,
    modelDeployment_B.modCoeffs_c);

  // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
  PolyTrajSys_updateStoredPPF_fjc(obj, modelDeployment_B.modBreaks_o,
    modelDeployment_B.modCoeffs_c);
  obj->PPFormUpdatedNeeded = false;
}

static void modelDep_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
{
  int32_T n;
  int32_T n_0;
  obj->ValidMotorIdx[0] = true;
  obj->ValidMotorIdx[1] = true;
  obj->ValidMotorIdx[2] = true;
  obj->ValidMotorIdx[3] = true;
  obj->ValidMotorIdx[4] = true;
  obj->ValidMotorIdx[5] = true;
  n = 0;
  for (int32_T b_k = 0; b_k < 12; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidMotorIdx[b_k]) {
      n++;
    }
  }

  n_0 = 0;
  for (int32_T b_k = 0; b_k < 8; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidServoIdx[b_k]) {
      n_0++;
    }
  }

  // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
  obj->QSize = static_cast<uint8_T>(n + n_0);
  MW_actuators_init(obj->QSize);
}

// Model step function
void modelDeployment_step(void)
{
  static const real_T b[6] = { 0.0, 0.0, 0.3, 0.0, 0.0, 0.0 };

  static const real_T c[6] = { 0.0, 0.0, 1.2, 0.0, 0.0, 0.0 };

  boolean_T exitg1;
  boolean_T guard1;

  // MATLABSystem: '<S86>/Read Parameter2'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_fw.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S86>/Read Parameter1'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_op.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S86>/Read Parameter3'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_g.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S86>/Read Parameter4'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_es.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S86>/Read Parameter8'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_j3.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S86>/Read Parameter5'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_di.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // MATLABSystem: '<S86>/Read Parameter6'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_mt.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_f);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_f = 0.0F;
  }

  // MATLABSystem: '<S86>/Read Parameter9'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_d.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_iz);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_iz = 0.0F;
  }

  // MATLABSystem: '<S86>/Read Parameter7'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_h.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ff);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ff = 0.0F;
  }

  // DataTypeConversion: '<S86>/Data Type Conversion' incorporates:
  //   MATLABSystem: '<S86>/Read Parameter1'
  //   MATLABSystem: '<S86>/Read Parameter2'
  //   MATLABSystem: '<S86>/Read Parameter3'
  //   MATLABSystem: '<S86>/Read Parameter4'
  //   MATLABSystem: '<S86>/Read Parameter5'
  //   MATLABSystem: '<S86>/Read Parameter6'
  //   MATLABSystem: '<S86>/Read Parameter7'
  //   MATLABSystem: '<S86>/Read Parameter8'
  //   MATLABSystem: '<S86>/Read Parameter9'
  //
  modelDeployment_B.posGains[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.posGains[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.posGains[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.posGains[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.posGains[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.posGains[5] = modelDeployment_B.ParamStep_ip;
  modelDeployment_B.posGains[6] = modelDeployment_B.ParamStep_f;
  modelDeployment_B.posGains[7] = modelDeployment_B.ParamStep_iz;
  modelDeployment_B.posGains[8] = modelDeployment_B.ParamStep_ff;

  // MATLABSystem: '<S81>/Read Parameter8'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_dm.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S81>/Read Parameter2'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ef.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S81>/Read Parameter9'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_mh.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S81>/Read Parameter10'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_or1.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S81>/Read Parameter1'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ff.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S81>/Read Parameter11'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_dz.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // MATLABSystem: '<S81>/Read Parameter12'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_dio.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_f);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_f = 0.0F;
  }

  // MATLABSystem: '<S81>/Read Parameter3'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_lt.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_iz);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_iz = 0.0F;
  }

  // MATLABSystem: '<S81>/Read Parameter13'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_cj.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ff);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ff = 0.0F;
  }

  // DataTypeConversion: '<S81>/Data Type Conversion' incorporates:
  //   MATLABSystem: '<S81>/Read Parameter1'
  //   MATLABSystem: '<S81>/Read Parameter10'
  //   MATLABSystem: '<S81>/Read Parameter11'
  //   MATLABSystem: '<S81>/Read Parameter12'
  //   MATLABSystem: '<S81>/Read Parameter13'
  //   MATLABSystem: '<S81>/Read Parameter2'
  //   MATLABSystem: '<S81>/Read Parameter3'
  //   MATLABSystem: '<S81>/Read Parameter8'
  //   MATLABSystem: '<S81>/Read Parameter9'
  //
  modelDeployment_B.attGains[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.attGains[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.attGains[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.attGains[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.attGains[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.attGains[5] = modelDeployment_B.ParamStep_ip;
  modelDeployment_B.attGains[6] = modelDeployment_B.ParamStep_f;
  modelDeployment_B.attGains[7] = modelDeployment_B.ParamStep_iz;
  modelDeployment_B.attGains[8] = modelDeployment_B.ParamStep_ff;

  // MATLABSystem: '<S80>/Read Parameter5'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_m1.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter12'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_df.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter18'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_cz.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter23'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_jg.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter32'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_kf.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter37'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ms.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S80>/Data Type Conversion3' incorporates:
  //   MATLABSystem: '<S80>/Read Parameter12'
  //   MATLABSystem: '<S80>/Read Parameter18'
  //   MATLABSystem: '<S80>/Read Parameter23'
  //   MATLABSystem: '<S80>/Read Parameter32'
  //   MATLABSystem: '<S80>/Read Parameter37'
  //   MATLABSystem: '<S80>/Read Parameter5'
  //
  modelDeployment_B.DataTypeConversion3[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion3[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion3[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion3[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion3[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion3[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S80>/Read Parameter6'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_mx.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter13'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_gc.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter19'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_aw.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter24'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ic.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter33'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_lq.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter38'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_gj.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S80>/Data Type Conversion6' incorporates:
  //   MATLABSystem: '<S80>/Read Parameter13'
  //   MATLABSystem: '<S80>/Read Parameter19'
  //   MATLABSystem: '<S80>/Read Parameter24'
  //   MATLABSystem: '<S80>/Read Parameter33'
  //   MATLABSystem: '<S80>/Read Parameter38'
  //   MATLABSystem: '<S80>/Read Parameter6'
  //
  modelDeployment_B.DataTypeConversion6[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion6[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion6[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion6[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion6[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion6[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S80>/Read Parameter3'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_cit.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter10'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ma.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter16'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_gsw.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter21'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_psz.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter30'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ce.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter35'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_mhh.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S80>/Data Type Conversion4' incorporates:
  //   MATLABSystem: '<S80>/Read Parameter10'
  //   MATLABSystem: '<S80>/Read Parameter16'
  //   MATLABSystem: '<S80>/Read Parameter21'
  //   MATLABSystem: '<S80>/Read Parameter3'
  //   MATLABSystem: '<S80>/Read Parameter30'
  //   MATLABSystem: '<S80>/Read Parameter35'
  //
  modelDeployment_B.DataTypeConversion4[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion4[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion4[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion4[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion4[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion4[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S80>/Read Parameter4'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_a0.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter11'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_fc.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter17'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_f0.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter22'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_hi.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter31'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_nqd.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter36'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ab.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S80>/Data Type Conversion2' incorporates:
  //   MATLABSystem: '<S80>/Read Parameter11'
  //   MATLABSystem: '<S80>/Read Parameter17'
  //   MATLABSystem: '<S80>/Read Parameter22'
  //   MATLABSystem: '<S80>/Read Parameter31'
  //   MATLABSystem: '<S80>/Read Parameter36'
  //   MATLABSystem: '<S80>/Read Parameter4'
  //
  modelDeployment_B.DataTypeConversion2[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion2[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion2[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion2[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion2[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion2[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S80>/Read Parameter'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_km.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter7'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_nq.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter25'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_bqm.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter14'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_pw.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter39'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_a5d.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter28'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ir.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S80>/Data Type Conversion' incorporates:
  //   MATLABSystem: '<S80>/Read Parameter'
  //   MATLABSystem: '<S80>/Read Parameter14'
  //   MATLABSystem: '<S80>/Read Parameter25'
  //   MATLABSystem: '<S80>/Read Parameter28'
  //   MATLABSystem: '<S80>/Read Parameter39'
  //   MATLABSystem: '<S80>/Read Parameter7'
  //
  modelDeployment_B.DataTypeConversion[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S80>/Read Parameter1'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_f3.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter8'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_px.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter26'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_am.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter15'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_an.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter40'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ez.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter29'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_pdi.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S80>/Data Type Conversion1' incorporates:
  //   MATLABSystem: '<S80>/Read Parameter1'
  //   MATLABSystem: '<S80>/Read Parameter15'
  //   MATLABSystem: '<S80>/Read Parameter26'
  //   MATLABSystem: '<S80>/Read Parameter29'
  //   MATLABSystem: '<S80>/Read Parameter40'
  //   MATLABSystem: '<S80>/Read Parameter8'
  //
  modelDeployment_B.DataTypeConversion1[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion1[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion1[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion1[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion1[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion1[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S80>/Read Parameter2'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_hg.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter9'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_lj.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter27'
  modelDeployment_B.NOT = MW_Param_Step
    (modelDeployment_DW.obj_lqw.MW_PARAMHANDLE, MW_SINGLE,
     &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter20'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_oe.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter41'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_k2.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S80>/Read Parameter34'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_in.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S80>/Data Type Conversion5' incorporates:
  //   MATLABSystem: '<S80>/Read Parameter2'
  //   MATLABSystem: '<S80>/Read Parameter20'
  //   MATLABSystem: '<S80>/Read Parameter27'
  //   MATLABSystem: '<S80>/Read Parameter34'
  //   MATLABSystem: '<S80>/Read Parameter41'
  //   MATLABSystem: '<S80>/Read Parameter9'
  //
  modelDeployment_B.DataTypeConversion5[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion5[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion5[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion5[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion5[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion5[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S84>/Read Parameter'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_lm.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S84>/Read Parameter1'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_kc.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S84>/Read Parameter2'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_p3.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  modelDeployment_ReadParameter3(&modelDeployment_B.ReadParameter3_pnae,
    &modelDeployment_DW.ReadParameter3_pnae);
  modelDeployment_ReadParameter3(&modelDeployment_B.ReadParameter4_pna,
    &modelDeployment_DW.ReadParameter4_pna);

  // DataTypeConversion: '<S84>/Data Type Conversion' incorporates:
  //   MATLABSystem: '<S84>/Read Parameter'
  //   MATLABSystem: '<S84>/Read Parameter1'
  //   MATLABSystem: '<S84>/Read Parameter2'
  //
  modelDeployment_B.MCData[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.MCData[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.MCData[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.MCData[3] =
    modelDeployment_B.ReadParameter3_pnae.ReadParameter3_o1;
  modelDeployment_B.MCData[4] =
    modelDeployment_B.ReadParameter4_pna.ReadParameter3_o1;

  // MATLABSystem: '<S82>/Read Parameter'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ml.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter4'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_nc.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter8'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_pk.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter12'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_nh.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter16'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_po.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter20'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_bz.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S82>/Data Type Conversion' incorporates:
  //   MATLABSystem: '<S82>/Read Parameter'
  //   MATLABSystem: '<S82>/Read Parameter12'
  //   MATLABSystem: '<S82>/Read Parameter16'
  //   MATLABSystem: '<S82>/Read Parameter20'
  //   MATLABSystem: '<S82>/Read Parameter4'
  //   MATLABSystem: '<S82>/Read Parameter8'
  //
  modelDeployment_B.DataTypeConversion_c[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion_c[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion_c[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion_c[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion_c[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion_c[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S82>/Read Parameter1'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_hq.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter5'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_k1.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter9'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_o5.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter13'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_gt.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter17'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_cg.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter21'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ny.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S82>/Data Type Conversion3' incorporates:
  //   MATLABSystem: '<S82>/Read Parameter1'
  //   MATLABSystem: '<S82>/Read Parameter13'
  //   MATLABSystem: '<S82>/Read Parameter17'
  //   MATLABSystem: '<S82>/Read Parameter21'
  //   MATLABSystem: '<S82>/Read Parameter5'
  //   MATLABSystem: '<S82>/Read Parameter9'
  //
  modelDeployment_B.DataTypeConversion3_c[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion3_c[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion3_c[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion3_c[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion3_c[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion3_c[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S82>/Read Parameter2'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_c1.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter6'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_pi.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter10'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_mb.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter14'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_go.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter18'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_pm.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter22'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_kb.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S82>/Data Type Conversion2' incorporates:
  //   MATLABSystem: '<S82>/Read Parameter10'
  //   MATLABSystem: '<S82>/Read Parameter14'
  //   MATLABSystem: '<S82>/Read Parameter18'
  //   MATLABSystem: '<S82>/Read Parameter2'
  //   MATLABSystem: '<S82>/Read Parameter22'
  //   MATLABSystem: '<S82>/Read Parameter6'
  //
  modelDeployment_B.DataTypeConversion2_m[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion2_m[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion2_m[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion2_m[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion2_m[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion2_m[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S82>/Read Parameter3'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_dp.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter7'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_dj.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter11'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_lw.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter15'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_jn.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter19'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_o4.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S82>/Read Parameter23'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_j5.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S82>/Data Type Conversion1' incorporates:
  //   MATLABSystem: '<S82>/Read Parameter11'
  //   MATLABSystem: '<S82>/Read Parameter15'
  //   MATLABSystem: '<S82>/Read Parameter19'
  //   MATLABSystem: '<S82>/Read Parameter23'
  //   MATLABSystem: '<S82>/Read Parameter3'
  //   MATLABSystem: '<S82>/Read Parameter7'
  //
  modelDeployment_B.DataTypeConversion1_h[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion1_h[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion1_h[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion1_h[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion1_h[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion1_h[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S83>/Read Parameter24'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_gs.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter32'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_jm.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_jz.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter6'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_hr.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter12'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_id.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter20'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_jy.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S83>/Data Type Conversion' incorporates:
  //   MATLABSystem: '<S83>/Read Parameter'
  //   MATLABSystem: '<S83>/Read Parameter12'
  //   MATLABSystem: '<S83>/Read Parameter20'
  //   MATLABSystem: '<S83>/Read Parameter24'
  //   MATLABSystem: '<S83>/Read Parameter32'
  //   MATLABSystem: '<S83>/Read Parameter6'
  //
  modelDeployment_B.DataTypeConversion_n[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion_n[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion_n[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion_n[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion_n[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion_n[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S83>/Read Parameter25'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_kx.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter33'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_na.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter1'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_pd.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter7'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_br.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter13'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_hh.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter21'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_pl.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S83>/Data Type Conversion1' incorporates:
  //   MATLABSystem: '<S83>/Read Parameter1'
  //   MATLABSystem: '<S83>/Read Parameter13'
  //   MATLABSystem: '<S83>/Read Parameter21'
  //   MATLABSystem: '<S83>/Read Parameter25'
  //   MATLABSystem: '<S83>/Read Parameter33'
  //   MATLABSystem: '<S83>/Read Parameter7'
  //
  modelDeployment_B.DataTypeConversion1_d[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion1_d[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion1_d[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion1_d[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion1_d[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion1_d[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S83>/Read Parameter28'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_dl.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter34'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_gg.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter2'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ps.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter8'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_a.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter16'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_pc.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter22'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_cy.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S83>/Data Type Conversion2' incorporates:
  //   MATLABSystem: '<S83>/Read Parameter16'
  //   MATLABSystem: '<S83>/Read Parameter2'
  //   MATLABSystem: '<S83>/Read Parameter22'
  //   MATLABSystem: '<S83>/Read Parameter28'
  //   MATLABSystem: '<S83>/Read Parameter34'
  //   MATLABSystem: '<S83>/Read Parameter8'
  //
  modelDeployment_B.DataTypeConversion2_m1[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion2_m1[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion2_m1[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion2_m1[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion2_m1[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion2_m1[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S83>/Read Parameter29'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_a5.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter35'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_i.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter3'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ci.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter9'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_lu.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter17'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_fq.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter23'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_h3.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S83>/Data Type Conversion3' incorporates:
  //   MATLABSystem: '<S83>/Read Parameter17'
  //   MATLABSystem: '<S83>/Read Parameter23'
  //   MATLABSystem: '<S83>/Read Parameter29'
  //   MATLABSystem: '<S83>/Read Parameter3'
  //   MATLABSystem: '<S83>/Read Parameter35'
  //   MATLABSystem: '<S83>/Read Parameter9'
  //
  modelDeployment_B.DataTypeConversion3_k[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion3_k[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion3_k[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion3_k[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion3_k[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion3_k[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S83>/Read Parameter30'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_dx.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter26'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_hx.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter4'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_b3.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter10'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_fx.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter18'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_bm.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter14'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_dc.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S83>/Data Type Conversion4' incorporates:
  //   MATLABSystem: '<S83>/Read Parameter10'
  //   MATLABSystem: '<S83>/Read Parameter14'
  //   MATLABSystem: '<S83>/Read Parameter18'
  //   MATLABSystem: '<S83>/Read Parameter26'
  //   MATLABSystem: '<S83>/Read Parameter30'
  //   MATLABSystem: '<S83>/Read Parameter4'
  //
  modelDeployment_B.DataTypeConversion4_k[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion4_k[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion4_k[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion4_k[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion4_k[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion4_k[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S83>/Read Parameter31'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_mu.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter27'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_kz.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_i);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_i = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter5'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_bq.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_l);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_l = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter11'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_ns.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter19'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_mz.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_o2);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_o2 = 0.0F;
  }

  // MATLABSystem: '<S83>/Read Parameter15'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_my.MW_PARAMHANDLE,
    MW_SINGLE, &modelDeployment_B.ParamStep_ip);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_ip = 0.0F;
  }

  // DataTypeConversion: '<S83>/Data Type Conversion5' incorporates:
  //   MATLABSystem: '<S83>/Read Parameter11'
  //   MATLABSystem: '<S83>/Read Parameter15'
  //   MATLABSystem: '<S83>/Read Parameter19'
  //   MATLABSystem: '<S83>/Read Parameter27'
  //   MATLABSystem: '<S83>/Read Parameter31'
  //   MATLABSystem: '<S83>/Read Parameter5'
  //
  modelDeployment_B.DataTypeConversion5_d[0] = modelDeployment_B.ParamStep;
  modelDeployment_B.DataTypeConversion5_d[1] = modelDeployment_B.ParamStep_i;
  modelDeployment_B.DataTypeConversion5_d[2] = modelDeployment_B.ParamStep_l;
  modelDeployment_B.DataTypeConversion5_d[3] = modelDeployment_B.ParamStep_o;
  modelDeployment_B.DataTypeConversion5_d[4] = modelDeployment_B.ParamStep_o2;
  modelDeployment_B.DataTypeConversion5_d[5] = modelDeployment_B.ParamStep_ip;

  // MATLABSystem: '<S35>/SourceBlock'
  modelDeployment_B.NOT = uORB_read_step(modelDeployment_DW.obj_m.orbMetadataObj,
    &modelDeployment_DW.obj_m.eventStructObj, &modelDeployment_B.r2, false,
    5000.0);

  // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S36>/Enable'

  // Start for MATLABSystem: '<S35>/SourceBlock'
  if (modelDeployment_B.NOT) {
    // SignalConversion generated from: '<S36>/In1'
    modelDeployment_B.In1_o = modelDeployment_B.r2;
  }

  // End of Outputs for SubSystem: '<S35>/Enabled Subsystem'

  // If: '<S24>/If'
  if (modelDeployment_B.In1_o.values[7] > 1500) {
    // Outputs for IfAction SubSystem: '<S24>/If Action Subsystem' incorporates:
    //   ActionPort: '<S28>/Action Port'

    // SignalConversion generated from: '<S28>/In1' incorporates:
    //   Constant: '<S24>/Constant'

    modelDeployment_B.Product3_g = modelDeployment_P.Constant_Value_bm;

    // End of Outputs for SubSystem: '<S24>/If Action Subsystem'

    // DataTypeConversion: '<S24>/Data Type Conversion' incorporates:
    //   Constant: '<S24>/Constant'

    modelDeployment_B.DataTypeConversion_h =
      (modelDeployment_P.Constant_Value_bm != 0.0);
  } else {
    // Outputs for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S29>/Action Port'

    // SignalConversion generated from: '<S29>/In1' incorporates:
    //   Constant: '<S24>/Constant1'

    modelDeployment_B.Product3_g = modelDeployment_P.Constant1_Value_g;

    // End of Outputs for SubSystem: '<S24>/If Action Subsystem1'

    // DataTypeConversion: '<S24>/Data Type Conversion' incorporates:
    //   Constant: '<S24>/Constant1'

    modelDeployment_B.DataTypeConversion_h =
      (modelDeployment_P.Constant1_Value_g != 0.0);
  }

  // End of If: '<S24>/If'

  // MATLABSystem: '<S6>/Read Parameter1'
  modelDeployment_B.NOT = MW_Param_Step(modelDeployment_DW.obj_n.MW_PARAMHANDLE,
    MW_INT32, &modelDeployment_B.ParamStep_g);
  if (modelDeployment_B.NOT) {
    modelDeployment_B.ParamStep_g = 0;
  }

  // ManualSwitch: '<S6>/Manual Switch1'
  if (modelDeployment_P.ManualSwitch1_CurrentSetting == 1) {
    // If: '<S24>/If1'
    if (modelDeployment_B.In1_o.values[6] > 1500) {
      // Logic: '<S6>/NOT' incorporates:
      //   Constant: '<S24>/Constant2'
      //   DataTypeConversion: '<S24>/Data Type Conversion1'

      modelDeployment_B.NOT = !(modelDeployment_P.Constant2_Value_b != 0.0);
    } else {
      // Logic: '<S6>/NOT' incorporates:
      //   Constant: '<S24>/Constant3'
      //   DataTypeConversion: '<S24>/Data Type Conversion1'

      modelDeployment_B.NOT = !(modelDeployment_P.Constant3_Value != 0.0);
    }

    // End of If: '<S24>/If1'
  } else {
    // Logic: '<S6>/NOT' incorporates:
    //   DataTypeConversion: '<S24>/Data Type Conversion'

    modelDeployment_B.NOT = !(modelDeployment_B.Product3_g != 0.0);
  }

  // End of ManualSwitch: '<S6>/Manual Switch1'

  // RelationalOperator: '<S6>/Relational Operator' incorporates:
  //   Constant: '<S6>/Constant'

  modelDeployment_B.RelationalOperator = (modelDeployment_B.NOT ==
    modelDeployment_P.Constant_Value_pr);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S87>/Enable'

  if (modelDeployment_B.RelationalOperator) {
    // Memory: '<S87>/Memory'
    modelDeployment_B.Memory = modelDeployment_DW.Memory_PreviousInput_d;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // DigitalClock: '<S6>/Digital Clock'
  modelDeployment_B.t = ((modelDeployment_M->Timing.clockTick0) * 0.004);

  // Sum: '<S6>/Sum'
  modelDeployment_B.t_reset = modelDeployment_B.t - modelDeployment_B.Memory;

  // ManualSwitch: '<S6>/Manual Switch' incorporates:
  //   DataTypeConversion: '<S24>/Data Type Conversion'
  //   Logic: '<S6>/AND'

  if (modelDeployment_P.ManualSwitch_CurrentSetting == 1) {
    modelDeployment_B.NOT = (modelDeployment_B.DataTypeConversion_h &&
      modelDeployment_B.NOT);
  } else {
    modelDeployment_B.NOT = (modelDeployment_B.Product3_g != 0.0);
  }

  // Outputs for Enabled SubSystem: '<S6>/Subsystem' incorporates:
  //   EnablePort: '<S88>/arm'

  if (modelDeployment_B.NOT) {
    // SwitchCase: '<S88>/Switch Case' incorporates:
    //   Constant: '<S92>/Constant13'
    //   DataTypeConversion: '<S6>/Data Type Conversion1'
    //   MATLABSystem: '<S6>/Read Parameter1'
    //   MATLABSystem: '<S89>/Polynomial Trajectory3'
    //   MATLABSystem: '<S90>/Polynomial Trajectory'
    //   MATLABSystem: '<S91>/Polynomial Trajectory3'
    //   MATLABSystem: '<S93>/Polynomial Trajectory2'
    //   Product: '<S104>/Product6'
    //
    modelDeployment_B.ParamStep = static_cast<real32_T>(fmod(static_cast<real_T>
      (static_cast<real32_T>(modelDeployment_B.ParamStep_g)), 4.294967296E+9));
    switch (modelDeployment_B.ParamStep < 0.0F ? -static_cast<int32_T>(
             static_cast<uint32_T>(-modelDeployment_B.ParamStep)) : static_cast<
            int32_T>(static_cast<uint32_T>(modelDeployment_B.ParamStep))) {
     case 0:
      // Outputs for IfAction SubSystem: '<S88>/If Action Subsystem4' incorporates:
      //   ActionPort: '<S93>/Action Port'

      // MATLABSystem: '<S93>/Polynomial Trajectory2' incorporates:
      //   Constant: '<S93>/Constant7'
      //   Constant: '<S93>/Constant8'
      //
      modelDeployment_B.NOT = false;
      modelDeployment_B.p = true;
      modelDeployment_B.ParamStep_g = 0;
      exitg1 = false;
      while ((!exitg1) && (modelDeployment_B.ParamStep_g < 60)) {
        if (!(modelDeployment_DW.obj_f.VelocityBoundaryCondition[modelDeployment_B.ParamStep_g]
              ==
              modelDeployment_P.PolynomialTrajectory2_VelocityB[modelDeployment_B.ParamStep_g]))
        {
          modelDeployment_B.p = false;
          exitg1 = true;
        } else {
          modelDeployment_B.ParamStep_g++;
        }
      }

      if (modelDeployment_B.p) {
        modelDeployment_B.NOT = true;
      }

      if (!modelDeployment_B.NOT) {
        if (modelDeployment_DW.obj_f.isInitialized == 1) {
          modelDeployment_DW.obj_f.TunablePropsChanged = true;
          modelDeployment_DW.obj_f.tunablePropertyChanged[3] = true;
        }

        memcpy(&modelDeployment_DW.obj_f.VelocityBoundaryCondition[0],
               &modelDeployment_P.PolynomialTrajectory2_VelocityB[0], 60U *
               sizeof(real_T));
      }

      if (modelDeployment_DW.obj_f.TunablePropsChanged) {
        modelDeployment_DW.obj_f.TunablePropsChanged = false;
        if (modelDeployment_DW.obj_f.tunablePropertyChanged[3] ||
            modelDeployment_DW.obj_f.tunablePropertyChanged[4]) {
          modelDeployment_B.NOT = true;
        } else {
          modelDeployment_B.NOT = false;
        }

        modelDeployment_DW.obj_f.PPFormUpdatedNeeded = modelDeployment_B.NOT;
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             5; modelDeployment_B.ParamStep_g++) {
          modelDeployment_DW.obj_f.tunablePropertyChanged[modelDeployment_B.ParamStep_g]
            = false;
        }
      }

      guard1 = false;
      if (modelDeployment_DW.obj_f.PPFormUpdatedNeeded) {
        guard1 = true;
      } else {
        modelDeployment_B.NOT = false;
        modelDeployment_B.p = true;
        modelDeployment_B.ParamStep_g = 0;
        exitg1 = false;
        while ((!exitg1) && (modelDeployment_B.ParamStep_g < 60)) {
          if (!(modelDeployment_P.Constant7_Value[modelDeployment_B.ParamStep_g]
                ==
                modelDeployment_DW.obj_f.PrevOptInputs.f1[modelDeployment_B.ParamStep_g]))
          {
            modelDeployment_B.p = false;
            exitg1 = true;
          } else {
            modelDeployment_B.ParamStep_g++;
          }
        }

        if (!modelDeployment_B.p) {
          modelDeployment_B.p = false;
        } else {
          modelDeployment_B.p = true;
          modelDeployment_B.ParamStep_g = 0;
          exitg1 = false;
          while ((!exitg1) && (modelDeployment_B.ParamStep_g < 10)) {
            if (!(modelDeployment_P.Constant8_Value[modelDeployment_B.ParamStep_g]
                  ==
                  modelDeployment_DW.obj_f.PrevOptInputs.f2[modelDeployment_B.ParamStep_g]))
            {
              modelDeployment_B.p = false;
              exitg1 = true;
            } else {
              modelDeployment_B.ParamStep_g++;
            }
          }
        }

        if (modelDeployment_B.p) {
          modelDeployment_B.NOT = true;
        }

        memcpy(&modelDeployment_DW.obj_f.PrevOptInputs.f1[0],
               &modelDeployment_P.Constant7_Value[0], 60U * sizeof(real_T));
        memcpy(&modelDeployment_DW.obj_f.PrevOptInputs.f2[0],
               &modelDeployment_P.Constant8_Value[0], 10U * sizeof(real_T));
        if (!modelDeployment_B.NOT) {
          guard1 = true;
        }
      }

      if (guard1) {
        memset(&modelDeployment_B.coefMat_g[0], 0, 216U * sizeof(real_T));
        for (modelDeployment_B.b_i = 0; modelDeployment_B.b_i < 9;
             modelDeployment_B.b_i++) {
          modelDeployment_B.Product3_g =
            modelDeployment_P.Constant8_Value[modelDeployment_B.b_i + 1] -
            modelDeployment_P.Constant8_Value[modelDeployment_B.b_i];
          for (modelDeployment_B.b_j = 0; modelDeployment_B.b_j < 6;
               modelDeployment_B.b_j++) {
            modelDeployment_B.ParamStep_g = modelDeployment_B.b_i * 6 +
              modelDeployment_B.b_j;
            modelDeployment_B.dv11[0] =
              modelDeployment_P.Constant7_Value[modelDeployment_B.ParamStep_g];
            modelDeployment_B.dv12[0] =
              modelDeployment_DW.obj_f.VelocityBoundaryCondition[modelDeployment_B.ParamStep_g];
            modelDeployment_B.i = (modelDeployment_B.b_i + 1) * 6 +
              modelDeployment_B.b_j;
            modelDeployment_B.dv11[1] =
              modelDeployment_P.Constant7_Value[modelDeployment_B.i];
            modelDeployment_B.dv12[1] =
              modelDeployment_DW.obj_f.VelocityBoundaryCondition[modelDeployment_B.i];
            modelDeploy_generateCubicCoeffs(modelDeployment_B.dv11,
              modelDeployment_B.dv12, modelDeployment_B.Product3_g,
              modelDeployment_B.dv7);
            modelDeployment_B.coefMat_g[modelDeployment_B.ParamStep_g] =
              modelDeployment_B.dv7[0];
            modelDeployment_B.coefMat_g[modelDeployment_B.ParamStep_g + 54] =
              modelDeployment_B.dv7[1];
            modelDeployment_B.coefMat_g[modelDeployment_B.ParamStep_g + 108] =
              modelDeployment_B.dv7[2];
            modelDeployment_B.coefMat_g[modelDeployment_B.ParamStep_g + 162] =
              modelDeployment_B.dv7[3];
          }
        }

        mo_addFlatSegmentsToPPFormParts(modelDeployment_P.Constant8_Value,
          modelDeployment_B.coefMat_g, modelDeployment_B.modBreaks_n,
          modelDeployment_B.coefMat_p);
        PolyTrajSys_updateStoredPPForms(&modelDeployment_DW.obj_f,
          modelDeployment_B.modBreaks_n, modelDeployment_B.coefMat_p);
        modelDeployment_DW.obj_f.PPFormUpdatedNeeded = false;
      }

      modelDeployment_B.Product1_or = modelDeployment_B.t_reset;
      if (modelDeployment_B.t_reset == modelDeployment_DW.obj_f.PPStruct.breaks
          [10]) {
        for (modelDeployment_B.i = 0; modelDeployment_B.i < 1;
             modelDeployment_B.i++) {
          modelDeployment_B.Product1_or =
            modelDeployment_DW.obj_f.PPStruct.breaks[10] -
            2.2204460492503131E-15;
        }
      }

      // MATLABSystem: '<S93>/Polynomial Trajectory2'
      modelDeployment_ppval(modelDeployment_DW.obj_f.PPStruct.breaks,
                            modelDeployment_DW.obj_f.PPStruct.coefs,
                            modelDeployment_B.t_reset,
                            modelDeployment_B.PolynomialTrajectory2_o1);

      // MATLAB Function: '<S93>/rpyd2quaterniond' incorporates:
      //   MATLABSystem: '<S93>/Polynomial Trajectory2'

      if (modelDeployment_B.t_reset < 15.0) {
        modelDeployment_B.t_reset = 0.0;
        modelDeployment_B.Product3_g = 0.0;
      } else if ((modelDeployment_B.t_reset >= 15.0) &&
                 (modelDeployment_B.t_reset < 31.0)) {
        modelDeployment_B.t_reset = (modelDeployment_B.t_reset - 15.0) *
          0.78539816339744828;
        modelDeployment_B.Product3_g = 0.78539816339744828;
      } else {
        modelDeployment_B.t_reset = 0.0;
        modelDeployment_B.Product3_g = 0.0;
      }

      modelDeployment_B.qx_c[0] = cos
        (modelDeployment_B.PolynomialTrajectory2_o1[3] / 2.0);
      modelDeployment_B.qx_c[1] = sin
        (modelDeployment_B.PolynomialTrajectory2_o1[3] / 2.0);
      modelDeployment_B.qx_c[2] = 0.0;
      modelDeployment_B.qx_c[3] = 0.0;
      modelDeployment_B.qy_e[0] = cos
        (modelDeployment_B.PolynomialTrajectory2_o1[4] / 2.0);
      modelDeployment_B.qy_e[1] = 0.0;
      modelDeployment_B.qy_e[2] = sin
        (modelDeployment_B.PolynomialTrajectory2_o1[4] / 2.0);
      modelDeployment_B.qy_e[3] = 0.0;
      modelDeployment_B.qz_e[0] = cos(modelDeployment_B.t_reset / 2.0);
      modelDeployment_B.qz_e[1] = 0.0;
      modelDeployment_B.qz_e[2] = 0.0;
      modelDeployment_B.qz_e[3] = sin(modelDeployment_B.t_reset / 2.0);

      // End of MATLAB Function: '<S93>/rpyd2quaterniond'

      // MATLAB Function: '<S106>/Kronecker_product'
      modelDeployme_Kronecker_product(modelDeployment_B.qx_c,
        modelDeployment_B.qy_e, modelDeployment_B.r_b1,
        &modelDeployment_B.sf_Kronecker_product_n);

      // MATLAB Function: '<S105>/Kronecker_product'
      modelDeployme_Kronecker_product(modelDeployment_B.r_b1,
        modelDeployment_B.qz_e, modelDeployment_B.qx_c,
        &modelDeployment_B.sf_Kronecker_product);

      // Sqrt: '<S111>/sqrt' incorporates:
      //   Product: '<S112>/Product'
      //   Product: '<S112>/Product1'
      //   Product: '<S112>/Product2'
      //   Product: '<S112>/Product3'
      //   Sum: '<S112>/Sum'

      modelDeployment_B.t_reset = sqrt(((modelDeployment_B.qx_c[0] *
        modelDeployment_B.qx_c[0] + modelDeployment_B.qx_c[1] *
        modelDeployment_B.qx_c[1]) + modelDeployment_B.qx_c[2] *
        modelDeployment_B.qx_c[2]) + modelDeployment_B.qx_c[3] *
        modelDeployment_B.qx_c[3]);

      // MATLABSystem: '<S93>/Polynomial Trajectory2'
      modelDeployment_ppval(modelDeployment_DW.obj_f.PPDStruct.breaks,
                            modelDeployment_DW.obj_f.PPDStruct.coefs,
                            modelDeployment_B.Product1_or,
                            modelDeployment_B.pose_d);

      // Merge: '<S88>/Merge' incorporates:
      //   Constant: '<S93>/Constant6'
      //   Product: '<S107>/Product'
      //   Product: '<S107>/Product1'
      //   Product: '<S107>/Product2'
      //   Product: '<S107>/Product3'
      //   SignalConversion generated from: '<S93>/yawturn'

      modelDeployment_B.Merge[6] = modelDeployment_B.pose_d[0];
      modelDeployment_B.Merge[9] = 0.0;
      modelDeployment_B.Merge[7] = modelDeployment_B.pose_d[1];
      modelDeployment_B.Merge[10] = 0.0;
      modelDeployment_B.Merge[8] = modelDeployment_B.pose_d[2];
      modelDeployment_B.Merge[11] = modelDeployment_B.Product3_g;
      for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 6;
           modelDeployment_B.ParamStep_g++) {
        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g] =
          modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.ParamStep_g];
        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g + 12] =
          modelDeployment_P.Constant6_Value[modelDeployment_B.ParamStep_g];
      }

      modelDeployment_B.Merge[18] = modelDeployment_B.qx_c[0] /
        modelDeployment_B.t_reset;
      modelDeployment_B.Merge[19] = modelDeployment_B.qx_c[1] /
        modelDeployment_B.t_reset;
      modelDeployment_B.Merge[20] = modelDeployment_B.qx_c[2] /
        modelDeployment_B.t_reset;
      modelDeployment_B.Merge[21] = modelDeployment_B.qx_c[3] /
        modelDeployment_B.t_reset;

      // End of Outputs for SubSystem: '<S88>/If Action Subsystem4'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S88>/If Action Subsystem3' incorporates:
      //   ActionPort: '<S92>/Action Port'

      // MATLAB Function: '<S92>/Lemniscate Trajectory'
      modelDeployment_B.Product3_g = 6.2831853071795862 *
        modelDeployment_B.t_reset / 25.0;
      if (modelDeployment_B.t_reset < 3.0) {
        modelDeployment_B.PolynomialTrajectory2_o1[0] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[1] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[2] =
          modelDeployment_B.t_reset * 0.1;
        modelDeployment_B.PolynomialTrajectory2_o1[3] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[4] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[5] = 0.0;
      } else if ((modelDeployment_B.t_reset >= 3.0) &&
                 (modelDeployment_B.t_reset < 6.0)) {
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             6; modelDeployment_B.ParamStep_g++) {
          modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.ParamStep_g]
            = b[modelDeployment_B.ParamStep_g];
        }
      } else if ((modelDeployment_B.t_reset >= 6.0) &&
                 (modelDeployment_B.t_reset < 8.0)) {
        modelDeployment_B.PolynomialTrajectory2_o1[0] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[1] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[2] =
          (modelDeployment_B.t_reset - 8.0) * 0.9 / 2.0 + 1.2;
        modelDeployment_B.PolynomialTrajectory2_o1[3] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[4] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[5] = 0.0;
      } else if ((modelDeployment_B.t_reset >= 8.0) &&
                 (modelDeployment_B.t_reset < 33.0)) {
        modelDeployment_B.t_reset = sin(modelDeployment_B.Product3_g - 2.0);
        modelDeployment_B.PolynomialTrajectory2_o1[0] = 3.0 *
          modelDeployment_B.t_reset;
        modelDeployment_B.PolynomialTrajectory2_o1[1] = 3.0 *
          modelDeployment_B.t_reset * cos(modelDeployment_B.Product3_g - 2.0);
        modelDeployment_B.PolynomialTrajectory2_o1[2] = 1.2;
        modelDeployment_B.PolynomialTrajectory2_o1[3] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[4] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[5] = 0.0;
      } else if ((modelDeployment_B.t_reset >= 33.0) &&
                 (modelDeployment_B.t_reset < 36.0)) {
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             6; modelDeployment_B.ParamStep_g++) {
          modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.ParamStep_g]
            = c[modelDeployment_B.ParamStep_g];
        }
      } else if ((modelDeployment_B.t_reset >= 36.0) &&
                 (modelDeployment_B.t_reset < 39.0)) {
        modelDeployment_B.PolynomialTrajectory2_o1[0] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[1] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[2] =
          (modelDeployment_B.t_reset - 39.0) * -0.9 / 3.0 + 0.3;
        modelDeployment_B.PolynomialTrajectory2_o1[3] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[4] = 0.0;
        modelDeployment_B.PolynomialTrajectory2_o1[5] = 0.0;
      } else {
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             6; modelDeployment_B.ParamStep_g++) {
          modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.ParamStep_g]
            = b[modelDeployment_B.ParamStep_g];
        }
      }

      // End of MATLAB Function: '<S92>/Lemniscate Trajectory'

      // Merge: '<S88>/Merge' incorporates:
      //   Constant: '<S92>/Constant2'
      //   SignalConversion generated from: '<S92>/lemni'

      modelDeployment_B.Merge[18] = modelDeployment_P.Constant2_Value[0];
      modelDeployment_B.Merge[19] = modelDeployment_P.Constant2_Value[1];
      modelDeployment_B.Merge[20] = modelDeployment_P.Constant2_Value[2];
      modelDeployment_B.Merge[21] = modelDeployment_P.Constant2_Value[3];
      for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i
           ++) {
        // Product: '<S104>/Product6' incorporates:
        //   Constant: '<S92>/Constant13'

        modelDeployment_B.Product3_g =
          modelDeployment_P.Constant13_Value[modelDeployment_B.i];

        // DiscreteIntegrator: '<S104>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S92>/Constant13'
        //   Memory: '<S104>/Memory'
        //   Memory: '<S104>/Memory1'
        //   Product: '<S104>/Product6'
        //   Product: '<S104>/Product7'
        //   Sum: '<S104>/Sum5'
        //   Sum: '<S104>/Sum6'

        modelDeployment_B.Product3_g =
          ((modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.i] -
            modelDeployment_DW.Memory_PreviousInput_f[modelDeployment_B.i]) *
           modelDeployment_B.Product3_g -
           modelDeployment_DW.Memory1_PreviousInput_h[modelDeployment_B.i]) *
          modelDeployment_B.Product3_g *
          modelDeployment_P.DiscreteTimeIntegrator_gainval;
        modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.i] =
          modelDeployment_B.Product3_g;

        // DiscreteIntegrator: '<S104>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S92>/Constant13'
        //   Product: '<S104>/Product6'

        modelDeployment_B.t_reset =
          modelDeployment_DW.DiscreteTimeIntegrator_DSTATE_l[modelDeployment_B.i]
          + modelDeployment_B.Product3_g;

        // DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' incorporates:
        //   DiscreteIntegrator: '<S104>/Discrete-Time Integrator'

        modelDeployment_B.Product1_or =
          modelDeployment_P.DiscreteTimeIntegrator1_gainval *
          modelDeployment_B.t_reset;

        // DiscreteIntegrator: '<S104>/Discrete-Time Integrator1'
        modelDeployment_B.Product2_p =
          modelDeployment_DW.DiscreteTimeIntegrator1_DSTAT_h[modelDeployment_B.i]
          + modelDeployment_B.Product1_or;
        modelDeployment_DW.Memory_PreviousInput_f[modelDeployment_B.i] =
          modelDeployment_B.Product2_p;

        // Merge: '<S88>/Merge' incorporates:
        //   Constant: '<S92>/Constant6'
        //   SignalConversion generated from: '<S92>/lemni'

        modelDeployment_B.Merge[modelDeployment_B.i] =
          modelDeployment_B.Product2_p;
        modelDeployment_B.Merge[modelDeployment_B.i + 6] =
          modelDeployment_B.t_reset;
        modelDeployment_B.Merge[modelDeployment_B.i + 12] =
          modelDeployment_P.Constant6_Value_i[modelDeployment_B.i];

        // Update for Memory: '<S104>/Memory1' incorporates:
        //   DiscreteIntegrator: '<S104>/Discrete-Time Integrator'
        //   Gain: '<S104>/zeta'

        modelDeployment_DW.Memory1_PreviousInput_h[modelDeployment_B.i] =
          modelDeployment_P.zeta_Gain * modelDeployment_B.t_reset;

        // Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator'
        modelDeployment_DW.DiscreteTimeIntegrator_DSTATE_l[modelDeployment_B.i] =
          modelDeployment_B.t_reset + modelDeployment_B.Product3_g;

        // Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1'
        modelDeployment_DW.DiscreteTimeIntegrator1_DSTAT_h[modelDeployment_B.i] =
          modelDeployment_B.Product2_p + modelDeployment_B.Product1_or;
      }

      // End of Outputs for SubSystem: '<S88>/If Action Subsystem3'
      break;

     case 2:
      // Outputs for IfAction SubSystem: '<S88>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // MATLABSystem: '<S91>/Polynomial Trajectory3' incorporates:
      //   Constant: '<S91>/Constant10'
      //   Constant: '<S91>/Constant11'
      //
      modelDeployment_B.NOT = false;
      modelDeployment_B.p = true;
      modelDeployment_B.ParamStep_g = 0;
      exitg1 = false;
      while ((!exitg1) && (modelDeployment_B.ParamStep_g < 126)) {
        if (!(modelDeployment_DW.obj.VelocityBoundaryCondition[modelDeployment_B.ParamStep_g]
              ==
              modelDeployment_P.PolynomialTrajectory3_VelocityB[modelDeployment_B.ParamStep_g]))
        {
          modelDeployment_B.p = false;
          exitg1 = true;
        } else {
          modelDeployment_B.ParamStep_g++;
        }
      }

      if (modelDeployment_B.p) {
        modelDeployment_B.NOT = true;
      }

      if (!modelDeployment_B.NOT) {
        if (modelDeployment_DW.obj.isInitialized == 1) {
          modelDeployment_DW.obj.TunablePropsChanged = true;
          modelDeployment_DW.obj.tunablePropertyChanged[3] = true;
        }

        memcpy(&modelDeployment_DW.obj.VelocityBoundaryCondition[0],
               &modelDeployment_P.PolynomialTrajectory3_VelocityB[0], 126U *
               sizeof(real_T));
      }

      modelDeployment_B.NOT = false;
      modelDeployment_B.p = true;
      modelDeployment_B.ParamStep_g = 0;
      exitg1 = false;
      while ((!exitg1) && (modelDeployment_B.ParamStep_g < 126)) {
        if (!(modelDeployment_DW.obj.AccelerationBoundaryCondition[modelDeployment_B.ParamStep_g]
              ==
              modelDeployment_P.PolynomialTrajectory3_Accelerat[modelDeployment_B.ParamStep_g]))
        {
          modelDeployment_B.p = false;
          exitg1 = true;
        } else {
          modelDeployment_B.ParamStep_g++;
        }
      }

      if (modelDeployment_B.p) {
        modelDeployment_B.NOT = true;
      }

      if (!modelDeployment_B.NOT) {
        if (modelDeployment_DW.obj.isInitialized == 1) {
          modelDeployment_DW.obj.TunablePropsChanged = true;
          modelDeployment_DW.obj.tunablePropertyChanged[4] = true;
        }

        memcpy(&modelDeployment_DW.obj.AccelerationBoundaryCondition[0],
               &modelDeployment_P.PolynomialTrajectory3_Accelerat[0], 126U *
               sizeof(real_T));
      }

      if (modelDeployment_DW.obj.TunablePropsChanged) {
        modelDeployment_DW.obj.TunablePropsChanged = false;
        if (modelDeployment_DW.obj.tunablePropertyChanged[3] ||
            modelDeployment_DW.obj.tunablePropertyChanged[4]) {
          modelDeployment_B.NOT = true;
        } else {
          modelDeployment_B.NOT = false;
        }

        modelDeployment_DW.obj.PPFormUpdatedNeeded = modelDeployment_B.NOT;
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             5; modelDeployment_B.ParamStep_g++) {
          modelDeployment_DW.obj.tunablePropertyChanged[modelDeployment_B.ParamStep_g]
            = false;
        }
      }

      guard1 = false;
      if (modelDeployment_DW.obj.PPFormUpdatedNeeded) {
        guard1 = true;
      } else {
        modelDeployment_B.NOT = false;
        modelDeployment_B.p = true;
        modelDeployment_B.ParamStep_g = 0;
        exitg1 = false;
        while ((!exitg1) && (modelDeployment_B.ParamStep_g < 126)) {
          if (!(modelDeployment_P.Constant10_Value[modelDeployment_B.ParamStep_g]
                ==
                modelDeployment_DW.obj.PrevOptInputs.f1[modelDeployment_B.ParamStep_g]))
          {
            modelDeployment_B.p = false;
            exitg1 = true;
          } else {
            modelDeployment_B.ParamStep_g++;
          }
        }

        if (!modelDeployment_B.p) {
          modelDeployment_B.p = false;
        } else {
          modelDeployment_B.p = true;
          modelDeployment_B.ParamStep_g = 0;
          exitg1 = false;
          while ((!exitg1) && (modelDeployment_B.ParamStep_g < 21)) {
            if (!(modelDeployment_P.Constant11_Value[modelDeployment_B.ParamStep_g]
                  ==
                  modelDeployment_DW.obj.PrevOptInputs.f2[modelDeployment_B.ParamStep_g]))
            {
              modelDeployment_B.p = false;
              exitg1 = true;
            } else {
              modelDeployment_B.ParamStep_g++;
            }
          }
        }

        if (modelDeployment_B.p) {
          modelDeployment_B.NOT = true;
        }

        memcpy(&modelDeployment_DW.obj.PrevOptInputs.f1[0],
               &modelDeployment_P.Constant10_Value[0], 126U * sizeof(real_T));
        memcpy(&modelDeployment_DW.obj.PrevOptInputs.f2[0],
               &modelDeployment_P.Constant11_Value[0], 21U * sizeof(real_T));
        if (!modelDeployment_B.NOT) {
          guard1 = true;
        }
      }

      if (guard1) {
        memset(&modelDeployment_B.coefMat[0], 0, 720U * sizeof(real_T));
        for (modelDeployment_B.b_i = 0; modelDeployment_B.b_i < 20;
             modelDeployment_B.b_i++) {
          modelDeployment_B.Product3_g =
            modelDeployment_P.Constant11_Value[modelDeployment_B.b_i + 1] -
            modelDeployment_P.Constant11_Value[modelDeployment_B.b_i];
          for (modelDeployment_B.b_j = 0; modelDeployment_B.b_j < 6;
               modelDeployment_B.b_j++) {
            modelDeployment_B.ParamStep_g = modelDeployment_B.b_i * 6 +
              modelDeployment_B.b_j;
            modelDeployment_B.dv11[0] =
              modelDeployment_P.Constant10_Value[modelDeployment_B.ParamStep_g];
            modelDeployment_B.dv12[0] =
              modelDeployment_DW.obj.VelocityBoundaryCondition[modelDeployment_B.ParamStep_g];
            modelDeployment_B.dv13[0] =
              modelDeployment_DW.obj.AccelerationBoundaryCondition[modelDeployment_B.ParamStep_g];
            modelDeployment_B.i = (modelDeployment_B.b_i + 1) * 6 +
              modelDeployment_B.b_j;
            modelDeployment_B.dv11[1] =
              modelDeployment_P.Constant10_Value[modelDeployment_B.i];
            modelDeployment_B.dv12[1] =
              modelDeployment_DW.obj.VelocityBoundaryCondition[modelDeployment_B.i];
            modelDeployment_B.dv13[1] =
              modelDeployment_DW.obj.AccelerationBoundaryCondition[modelDeployment_B.i];
            modelDepl_generateQuinticCoeffs(modelDeployment_B.dv11,
              modelDeployment_B.dv12, modelDeployment_B.dv13,
              modelDeployment_B.Product3_g, modelDeployment_B.pose_d);
            for (modelDeployment_B.i = 0; modelDeployment_B.i < 6;
                 modelDeployment_B.i++) {
              modelDeployment_B.coefMat[modelDeployment_B.ParamStep_g + 120 *
                modelDeployment_B.i] =
                modelDeployment_B.pose_d[modelDeployment_B.i];
            }
          }
        }

        addFlatSegmentsToPPFormParts_f(modelDeployment_P.Constant11_Value,
          modelDeployment_B.coefMat, modelDeployment_B.modBreaks,
          modelDeployment_B.modCoeffs);
        PolyTrajSys_updateStoredPPFor_f(&modelDeployment_DW.obj,
          modelDeployment_B.modBreaks, modelDeployment_B.modCoeffs);
        modelDeployment_DW.obj.PPFormUpdatedNeeded = false;
      }

      modelDeployment_B.Product1_or = modelDeployment_B.t_reset;
      if (modelDeployment_B.t_reset == modelDeployment_DW.obj.PPStruct.breaks[21])
      {
        for (modelDeployment_B.i = 0; modelDeployment_B.i < 1;
             modelDeployment_B.i++) {
          modelDeployment_B.Product1_or =
            modelDeployment_DW.obj.PPStruct.breaks[21] - 2.2204460492503131E-15;
        }
      }

      // MATLABSystem: '<S91>/Polynomial Trajectory3'
      modelDeployment_ppval_f(modelDeployment_DW.obj.PPStruct.breaks,
        modelDeployment_DW.obj.PPStruct.coefs, modelDeployment_B.t_reset,
        modelDeployment_B.PolynomialTrajectory2_o1);

      // MATLAB Function: '<S91>/rpyd2quaterniond' incorporates:
      //   MATLABSystem: '<S91>/Polynomial Trajectory3'

      modelDeployment_B.qx_c[0] = cos
        (modelDeployment_B.PolynomialTrajectory2_o1[3] / 2.0);
      modelDeployment_B.qx_c[1] = sin
        (modelDeployment_B.PolynomialTrajectory2_o1[3] / 2.0);
      modelDeployment_B.qx_c[2] = 0.0;
      modelDeployment_B.qx_c[3] = 0.0;
      modelDeployment_B.qy_e[0] = cos
        (modelDeployment_B.PolynomialTrajectory2_o1[4] / 2.0);
      modelDeployment_B.qy_e[1] = 0.0;
      modelDeployment_B.qy_e[2] = sin
        (modelDeployment_B.PolynomialTrajectory2_o1[4] / 2.0);
      modelDeployment_B.qy_e[3] = 0.0;
      modelDeployment_B.qz_e[0] = cos
        (modelDeployment_B.PolynomialTrajectory2_o1[5] / 2.0);
      modelDeployment_B.qz_e[1] = 0.0;
      modelDeployment_B.qz_e[2] = 0.0;
      modelDeployment_B.qz_e[3] = sin
        (modelDeployment_B.PolynomialTrajectory2_o1[5] / 2.0);

      // MATLAB Function: '<S96>/Kronecker_product'
      modelDeployme_Kronecker_product(modelDeployment_B.qx_c,
        modelDeployment_B.qy_e, modelDeployment_B.r_b1,
        &modelDeployment_B.sf_Kronecker_product_k);

      // MATLAB Function: '<S95>/Kronecker_product'
      modelDeployme_Kronecker_product(modelDeployment_B.r_b1,
        modelDeployment_B.qz_e, modelDeployment_B.qx_c,
        &modelDeployment_B.sf_Kronecker_product_l);

      // Sqrt: '<S101>/sqrt' incorporates:
      //   Product: '<S102>/Product'
      //   Product: '<S102>/Product1'
      //   Product: '<S102>/Product2'
      //   Product: '<S102>/Product3'
      //   Sum: '<S102>/Sum'

      modelDeployment_B.Product3_g = sqrt(((modelDeployment_B.qx_c[0] *
        modelDeployment_B.qx_c[0] + modelDeployment_B.qx_c[1] *
        modelDeployment_B.qx_c[1]) + modelDeployment_B.qx_c[2] *
        modelDeployment_B.qx_c[2]) + modelDeployment_B.qx_c[3] *
        modelDeployment_B.qx_c[3]);

      // MATLABSystem: '<S91>/Polynomial Trajectory3'
      modelDeployment_ppval_f(modelDeployment_DW.obj.PPDStruct.breaks,
        modelDeployment_DW.obj.PPDStruct.coefs, modelDeployment_B.Product1_or,
        modelDeployment_B.pose_d);
      for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 6;
           modelDeployment_B.ParamStep_g++) {
        // Merge: '<S88>/Merge' incorporates:
        //   Constant: '<S91>/Constant6'
        //   SignalConversion generated from: '<S91>/rollpitch'

        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g] =
          modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.ParamStep_g];
        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g + 6] =
          modelDeployment_B.pose_d[modelDeployment_B.ParamStep_g];
        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g + 12] =
          modelDeployment_P.Constant6_Value_a[modelDeployment_B.ParamStep_g];
      }

      // Merge: '<S88>/Merge' incorporates:
      //   Product: '<S97>/Product'
      //   Product: '<S97>/Product1'
      //   Product: '<S97>/Product2'
      //   Product: '<S97>/Product3'
      //   SignalConversion generated from: '<S91>/rollpitch'

      modelDeployment_B.Merge[18] = modelDeployment_B.qx_c[0] /
        modelDeployment_B.Product3_g;
      modelDeployment_B.Merge[19] = modelDeployment_B.qx_c[1] /
        modelDeployment_B.Product3_g;
      modelDeployment_B.Merge[20] = modelDeployment_B.qx_c[2] /
        modelDeployment_B.Product3_g;
      modelDeployment_B.Merge[21] = modelDeployment_B.qx_c[3] /
        modelDeployment_B.Product3_g;

      // End of Outputs for SubSystem: '<S88>/If Action Subsystem2'
      break;

     case 3:
      // Outputs for IfAction SubSystem: '<S88>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S90>/Action Port'

      // MATLABSystem: '<S90>/Polynomial Trajectory' incorporates:
      //   Constant: '<S90>/Constant1'
      //   Constant: '<S90>/Constant4'
      //
      modelDeployment_B.NOT = false;
      modelDeployment_B.p = true;
      modelDeployment_B.ParamStep_g = 0;
      exitg1 = false;
      while ((!exitg1) && (modelDeployment_B.ParamStep_g < 36)) {
        if (!(modelDeployment_DW.obj_fs.VelocityBoundaryCondition[modelDeployment_B.ParamStep_g]
              ==
              modelDeployment_P.PolynomialTrajectory_VelocityBo[modelDeployment_B.ParamStep_g]))
        {
          modelDeployment_B.p = false;
          exitg1 = true;
        } else {
          modelDeployment_B.ParamStep_g++;
        }
      }

      if (modelDeployment_B.p) {
        modelDeployment_B.NOT = true;
      }

      if (!modelDeployment_B.NOT) {
        if (modelDeployment_DW.obj_fs.isInitialized == 1) {
          modelDeployment_DW.obj_fs.TunablePropsChanged = true;
          modelDeployment_DW.obj_fs.tunablePropertyChanged[3] = true;
        }

        memcpy(&modelDeployment_DW.obj_fs.VelocityBoundaryCondition[0],
               &modelDeployment_P.PolynomialTrajectory_VelocityBo[0], 36U *
               sizeof(real_T));
      }

      if (modelDeployment_DW.obj_fs.TunablePropsChanged) {
        modelDeployment_DW.obj_fs.TunablePropsChanged = false;
        if (modelDeployment_DW.obj_fs.tunablePropertyChanged[3] ||
            modelDeployment_DW.obj_fs.tunablePropertyChanged[4]) {
          modelDeployment_B.NOT = true;
        } else {
          modelDeployment_B.NOT = false;
        }

        modelDeployment_DW.obj_fs.PPFormUpdatedNeeded = modelDeployment_B.NOT;
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             5; modelDeployment_B.ParamStep_g++) {
          modelDeployment_DW.obj_fs.tunablePropertyChanged[modelDeployment_B.ParamStep_g]
            = false;
        }
      }

      guard1 = false;
      if (modelDeployment_DW.obj_fs.PPFormUpdatedNeeded) {
        guard1 = true;
      } else {
        modelDeployment_B.NOT = false;
        modelDeployment_B.p = true;
        modelDeployment_B.ParamStep_g = 0;
        exitg1 = false;
        while ((!exitg1) && (modelDeployment_B.ParamStep_g < 36)) {
          if (!(modelDeployment_P.Constant1_Value_f[modelDeployment_B.ParamStep_g]
                ==
                modelDeployment_DW.obj_fs.PrevOptInputs.f1[modelDeployment_B.ParamStep_g]))
          {
            modelDeployment_B.p = false;
            exitg1 = true;
          } else {
            modelDeployment_B.ParamStep_g++;
          }
        }

        if (!modelDeployment_B.p) {
          modelDeployment_B.p = false;
        } else {
          modelDeployment_B.p = true;
          modelDeployment_B.ParamStep_g = 0;
          exitg1 = false;
          while ((!exitg1) && (modelDeployment_B.ParamStep_g < 6)) {
            if (!(modelDeployment_P.Constant4_Value[modelDeployment_B.ParamStep_g]
                  ==
                  modelDeployment_DW.obj_fs.PrevOptInputs.f2[modelDeployment_B.ParamStep_g]))
            {
              modelDeployment_B.p = false;
              exitg1 = true;
            } else {
              modelDeployment_B.ParamStep_g++;
            }
          }
        }

        if (modelDeployment_B.p) {
          modelDeployment_B.NOT = true;
        }

        memcpy(&modelDeployment_DW.obj_fs.PrevOptInputs.f1[0],
               &modelDeployment_P.Constant1_Value_f[0], 36U * sizeof(real_T));
        for (modelDeployment_B.i = 0; modelDeployment_B.i < 6;
             modelDeployment_B.i++) {
          modelDeployment_DW.obj_fs.PrevOptInputs.f2[modelDeployment_B.i] =
            modelDeployment_P.Constant4_Value[modelDeployment_B.i];
        }

        if (!modelDeployment_B.NOT) {
          guard1 = true;
        }
      }

      if (guard1) {
        memset(&modelDeployment_B.coefMat_j[0], 0, 120U * sizeof(real_T));
        for (modelDeployment_B.b_i = 0; modelDeployment_B.b_i < 5;
             modelDeployment_B.b_i++) {
          modelDeployment_B.Product3_g =
            modelDeployment_P.Constant4_Value[modelDeployment_B.b_i + 1] -
            modelDeployment_P.Constant4_Value[modelDeployment_B.b_i];
          for (modelDeployment_B.b_j = 0; modelDeployment_B.b_j < 6;
               modelDeployment_B.b_j++) {
            modelDeployment_B.ParamStep_g = modelDeployment_B.b_i * 6 +
              modelDeployment_B.b_j;
            modelDeployment_B.dv11[0] =
              modelDeployment_P.Constant1_Value_f[modelDeployment_B.ParamStep_g];
            modelDeployment_B.dv12[0] =
              modelDeployment_DW.obj_fs.VelocityBoundaryCondition[modelDeployment_B.ParamStep_g];
            modelDeployment_B.i = (modelDeployment_B.b_i + 1) * 6 +
              modelDeployment_B.b_j;
            modelDeployment_B.dv11[1] =
              modelDeployment_P.Constant1_Value_f[modelDeployment_B.i];
            modelDeployment_B.dv12[1] =
              modelDeployment_DW.obj_fs.VelocityBoundaryCondition[modelDeployment_B.i];
            modelDeploy_generateCubicCoeffs(modelDeployment_B.dv11,
              modelDeployment_B.dv12, modelDeployment_B.Product3_g,
              modelDeployment_B.dv7);
            modelDeployment_B.coefMat_j[modelDeployment_B.ParamStep_g] =
              modelDeployment_B.dv7[0];
            modelDeployment_B.coefMat_j[modelDeployment_B.ParamStep_g + 30] =
              modelDeployment_B.dv7[1];
            modelDeployment_B.coefMat_j[modelDeployment_B.ParamStep_g + 60] =
              modelDeployment_B.dv7[2];
            modelDeployment_B.coefMat_j[modelDeployment_B.ParamStep_g + 90] =
              modelDeployment_B.dv7[3];
          }
        }

        addFlatSegmentsToPPFormParts_fj(modelDeployment_P.Constant4_Value,
          modelDeployment_B.coefMat_j, modelDeployment_B.modBreaks_h,
          modelDeployment_B.modCoeffs_n);
        PolyTrajSys_updateStoredPPFo_fj(&modelDeployment_DW.obj_fs,
          modelDeployment_B.modBreaks_h, modelDeployment_B.modCoeffs_n);
        modelDeployment_DW.obj_fs.PPFormUpdatedNeeded = false;
      }

      modelDeployment_B.Product1_or = modelDeployment_B.t_reset;
      if (modelDeployment_B.t_reset ==
          modelDeployment_DW.obj_fs.PPStruct.breaks[6]) {
        for (modelDeployment_B.i = 0; modelDeployment_B.i < 1;
             modelDeployment_B.i++) {
          modelDeployment_B.Product1_or =
            modelDeployment_DW.obj_fs.PPStruct.breaks[6] -
            2.2204460492503131E-15;
        }
      }

      // MATLABSystem: '<S90>/Polynomial Trajectory'
      modelDeployment_ppval_fj(modelDeployment_DW.obj_fs.PPStruct.breaks,
        modelDeployment_DW.obj_fs.PPStruct.coefs, modelDeployment_B.t_reset,
        modelDeployment_B.pose_d);
      modelDeployment_ppval_fj(modelDeployment_DW.obj_fs.PPDStruct.breaks,
        modelDeployment_DW.obj_fs.PPDStruct.coefs, modelDeployment_B.Product1_or,
        modelDeployment_B.PolynomialTrajectory2_o1);
      for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 6;
           modelDeployment_B.ParamStep_g++) {
        // Merge: '<S88>/Merge' incorporates:
        //   Constant: '<S90>/Constant'
        //   SignalConversion generated from: '<S90>/take-off'

        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g] =
          modelDeployment_B.pose_d[modelDeployment_B.ParamStep_g];
        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g + 6] =
          modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.ParamStep_g];
        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g + 12] =
          modelDeployment_P.Constant_Value_c[modelDeployment_B.ParamStep_g];
      }

      // Merge: '<S88>/Merge' incorporates:
      //   Constant: '<S90>/Constant2'
      //   SignalConversion generated from: '<S90>/take-off'

      modelDeployment_B.Merge[18] = modelDeployment_P.Constant2_Value_n[0];
      modelDeployment_B.Merge[19] = modelDeployment_P.Constant2_Value_n[1];
      modelDeployment_B.Merge[20] = modelDeployment_P.Constant2_Value_n[2];
      modelDeployment_B.Merge[21] = modelDeployment_P.Constant2_Value_n[3];

      // End of Outputs for SubSystem: '<S88>/If Action Subsystem1'
      break;

     case 4:
      // Outputs for IfAction SubSystem: '<S88>/If Action Subsystem' incorporates:
      //   ActionPort: '<S89>/Action Port'

      // MATLABSystem: '<S89>/Polynomial Trajectory3' incorporates:
      //   Constant: '<S89>/Constant10'
      //   Constant: '<S89>/Constant11'
      //
      modelDeployment_B.NOT = false;
      modelDeployment_B.p = true;
      modelDeployment_B.ParamStep_g = 0;
      exitg1 = false;
      while ((!exitg1) && (modelDeployment_B.ParamStep_g < 72)) {
        if (!(modelDeployment_DW.obj_c.VelocityBoundaryCondition[modelDeployment_B.ParamStep_g]
              ==
              modelDeployment_P.PolynomialTrajectory3_Velocit_e[modelDeployment_B.ParamStep_g]))
        {
          modelDeployment_B.p = false;
          exitg1 = true;
        } else {
          modelDeployment_B.ParamStep_g++;
        }
      }

      if (modelDeployment_B.p) {
        modelDeployment_B.NOT = true;
      }

      if (!modelDeployment_B.NOT) {
        if (modelDeployment_DW.obj_c.isInitialized == 1) {
          modelDeployment_DW.obj_c.TunablePropsChanged = true;
          modelDeployment_DW.obj_c.tunablePropertyChanged[3] = true;
        }

        memcpy(&modelDeployment_DW.obj_c.VelocityBoundaryCondition[0],
               &modelDeployment_P.PolynomialTrajectory3_Velocit_e[0], 72U *
               sizeof(real_T));
      }

      if (modelDeployment_DW.obj_c.TunablePropsChanged) {
        modelDeployment_DW.obj_c.TunablePropsChanged = false;
        if (modelDeployment_DW.obj_c.tunablePropertyChanged[3] ||
            modelDeployment_DW.obj_c.tunablePropertyChanged[4]) {
          modelDeployment_B.NOT = true;
        } else {
          modelDeployment_B.NOT = false;
        }

        modelDeployment_DW.obj_c.PPFormUpdatedNeeded = modelDeployment_B.NOT;
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             5; modelDeployment_B.ParamStep_g++) {
          modelDeployment_DW.obj_c.tunablePropertyChanged[modelDeployment_B.ParamStep_g]
            = false;
        }
      }

      guard1 = false;
      if (modelDeployment_DW.obj_c.PPFormUpdatedNeeded) {
        guard1 = true;
      } else {
        modelDeployment_B.NOT = false;
        modelDeployment_B.p = true;
        modelDeployment_B.ParamStep_g = 0;
        exitg1 = false;
        while ((!exitg1) && (modelDeployment_B.ParamStep_g < 72)) {
          if (!(modelDeployment_P.Constant10_Value_o[modelDeployment_B.ParamStep_g]
                ==
                modelDeployment_DW.obj_c.PrevOptInputs.f1[modelDeployment_B.ParamStep_g]))
          {
            modelDeployment_B.p = false;
            exitg1 = true;
          } else {
            modelDeployment_B.ParamStep_g++;
          }
        }

        if (!modelDeployment_B.p) {
          modelDeployment_B.p = false;
        } else {
          modelDeployment_B.p = true;
          modelDeployment_B.ParamStep_g = 0;
          exitg1 = false;
          while ((!exitg1) && (modelDeployment_B.ParamStep_g < 12)) {
            if (!(modelDeployment_P.Constant11_Value_g[modelDeployment_B.ParamStep_g]
                  ==
                  modelDeployment_DW.obj_c.PrevOptInputs.f2[modelDeployment_B.ParamStep_g]))
            {
              modelDeployment_B.p = false;
              exitg1 = true;
            } else {
              modelDeployment_B.ParamStep_g++;
            }
          }
        }

        if (modelDeployment_B.p) {
          modelDeployment_B.NOT = true;
        }

        memcpy(&modelDeployment_DW.obj_c.PrevOptInputs.f1[0],
               &modelDeployment_P.Constant10_Value_o[0], 72U * sizeof(real_T));
        memcpy(&modelDeployment_DW.obj_c.PrevOptInputs.f2[0],
               &modelDeployment_P.Constant11_Value_g[0], 12U * sizeof(real_T));
        if (!modelDeployment_B.NOT) {
          guard1 = true;
        }
      }

      if (guard1) {
        memset(&modelDeployment_B.coefMat_p[0], 0, 264U * sizeof(real_T));
        for (modelDeployment_B.b_i = 0; modelDeployment_B.b_i < 11;
             modelDeployment_B.b_i++) {
          modelDeployment_B.Product3_g =
            modelDeployment_P.Constant11_Value_g[modelDeployment_B.b_i + 1] -
            modelDeployment_P.Constant11_Value_g[modelDeployment_B.b_i];
          for (modelDeployment_B.b_j = 0; modelDeployment_B.b_j < 6;
               modelDeployment_B.b_j++) {
            modelDeployment_B.ParamStep_g = modelDeployment_B.b_i * 6 +
              modelDeployment_B.b_j;
            modelDeployment_B.dv11[0] =
              modelDeployment_P.Constant10_Value_o[modelDeployment_B.ParamStep_g];
            modelDeployment_B.dv12[0] =
              modelDeployment_DW.obj_c.VelocityBoundaryCondition[modelDeployment_B.ParamStep_g];
            modelDeployment_B.i = (modelDeployment_B.b_i + 1) * 6 +
              modelDeployment_B.b_j;
            modelDeployment_B.dv11[1] =
              modelDeployment_P.Constant10_Value_o[modelDeployment_B.i];
            modelDeployment_B.dv12[1] =
              modelDeployment_DW.obj_c.VelocityBoundaryCondition[modelDeployment_B.i];
            modelDeploy_generateCubicCoeffs(modelDeployment_B.dv11,
              modelDeployment_B.dv12, modelDeployment_B.Product3_g,
              modelDeployment_B.dv7);
            modelDeployment_B.coefMat_p[modelDeployment_B.ParamStep_g] =
              modelDeployment_B.dv7[0];
            modelDeployment_B.coefMat_p[modelDeployment_B.ParamStep_g + 66] =
              modelDeployment_B.dv7[1];
            modelDeployment_B.coefMat_p[modelDeployment_B.ParamStep_g + 132] =
              modelDeployment_B.dv7[2];
            modelDeployment_B.coefMat_p[modelDeployment_B.ParamStep_g + 198] =
              modelDeployment_B.dv7[3];
          }
        }

        addFlatSegmentsToPPFormPart_fjc(modelDeployment_P.Constant11_Value_g,
          modelDeployment_B.coefMat_p, modelDeployment_B.modBreaks_l,
          modelDeployment_B.modCoeffs_k);
        PolyTrajSys_updateStoredPPF_fjc(&modelDeployment_DW.obj_c,
          modelDeployment_B.modBreaks_l, modelDeployment_B.modCoeffs_k);
        modelDeployment_DW.obj_c.PPFormUpdatedNeeded = false;
      }

      modelDeployment_B.Product1_or = modelDeployment_B.t_reset;
      if (modelDeployment_B.t_reset == modelDeployment_DW.obj_c.PPStruct.breaks
          [12]) {
        for (modelDeployment_B.i = 0; modelDeployment_B.i < 1;
             modelDeployment_B.i++) {
          modelDeployment_B.Product1_or =
            modelDeployment_DW.obj_c.PPStruct.breaks[12] -
            2.2204460492503131E-15;
        }
      }

      // MATLABSystem: '<S89>/Polynomial Trajectory3'
      modelDeployment_ppval_fjc(modelDeployment_DW.obj_c.PPStruct.breaks,
        modelDeployment_DW.obj_c.PPStruct.coefs, modelDeployment_B.t_reset,
        modelDeployment_B.pose_d);
      modelDeployment_ppval_fjc(modelDeployment_DW.obj_c.PPDStruct.breaks,
        modelDeployment_DW.obj_c.PPDStruct.coefs, modelDeployment_B.Product1_or,
        modelDeployment_B.PolynomialTrajectory2_o1);
      for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 6;
           modelDeployment_B.ParamStep_g++) {
        // Merge: '<S88>/Merge' incorporates:
        //   Constant: '<S89>/Constant9'
        //   SignalConversion generated from: '<S89>/square'

        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g] =
          modelDeployment_B.pose_d[modelDeployment_B.ParamStep_g];
        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g + 6] =
          modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.ParamStep_g];
        modelDeployment_B.Merge[modelDeployment_B.ParamStep_g + 12] =
          modelDeployment_P.Constant9_Value[modelDeployment_B.ParamStep_g];
      }

      // Merge: '<S88>/Merge' incorporates:
      //   Constant: '<S89>/Constant2'
      //   SignalConversion generated from: '<S89>/square'

      modelDeployment_B.Merge[18] = modelDeployment_P.Constant2_Value_e[0];
      modelDeployment_B.Merge[19] = modelDeployment_P.Constant2_Value_e[1];
      modelDeployment_B.Merge[20] = modelDeployment_P.Constant2_Value_e[2];
      modelDeployment_B.Merge[21] = modelDeployment_P.Constant2_Value_e[3];

      // End of Outputs for SubSystem: '<S88>/If Action Subsystem'
      break;

     case 5:
      // Outputs for IfAction SubSystem: '<S88>/If Action Subsystem5' incorporates:
      //   ActionPort: '<S94>/Action Port'

      // MATLAB Function: '<S94>/Lemniscate Trajectory'
      modelDeployment_B.Product3_g = 6.2831853071795862 *
        modelDeployment_B.t_reset / 25.0;
      if (modelDeployment_B.t_reset < 3.0) {
        modelDeployment_B.pose_d[0] = 0.0;
        modelDeployment_B.pose_d[1] = 0.0;
        modelDeployment_B.pose_d[2] = modelDeployment_B.t_reset * 0.1;
        modelDeployment_B.pose_d[3] = 0.0;
        modelDeployment_B.pose_d[4] = 0.0;
        modelDeployment_B.pose_d[5] = 0.0;
      } else if ((modelDeployment_B.t_reset >= 3.0) &&
                 (modelDeployment_B.t_reset < 6.0)) {
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             6; modelDeployment_B.ParamStep_g++) {
          modelDeployment_B.pose_d[modelDeployment_B.ParamStep_g] =
            b[modelDeployment_B.ParamStep_g];
        }
      } else if ((modelDeployment_B.t_reset >= 6.0) &&
                 (modelDeployment_B.t_reset < 8.0)) {
        modelDeployment_B.pose_d[0] = 0.0;
        modelDeployment_B.pose_d[1] = 0.0;
        modelDeployment_B.pose_d[2] = (modelDeployment_B.t_reset - 8.0) * 0.9 /
          2.0 + 1.2;
        modelDeployment_B.pose_d[3] = 0.0;
        modelDeployment_B.pose_d[4] = 0.0;
        modelDeployment_B.pose_d[5] = 0.0;
      } else if ((modelDeployment_B.t_reset >= 8.0) &&
                 (modelDeployment_B.t_reset < 11.0)) {
        modelDeployment_B.pose_d[0] = 0.0;
        modelDeployment_B.pose_d[1] = 0.0;
        modelDeployment_B.pose_d[2] = 1.2;
        modelDeployment_B.pose_d[3] = 0.0;
        modelDeployment_B.pose_d[4] = 0.0;
        modelDeployment_B.pose_d[5] = (modelDeployment_B.t_reset - 8.0) *
          -0.261746077120484;
      } else if ((modelDeployment_B.t_reset >= 11.0) &&
                 (modelDeployment_B.t_reset < 36.0)) {
        modelDeployment_B.t_reset = sin(modelDeployment_B.Product3_g - 2.75);
        modelDeployment_B.Product1_or = cos(modelDeployment_B.Product3_g - 2.75);
        modelDeployment_B.pose_d[0] = 3.0 * modelDeployment_B.t_reset;
        modelDeployment_B.pose_d[1] = 3.0 * modelDeployment_B.t_reset *
          modelDeployment_B.Product1_or;
        modelDeployment_B.pose_d[2] = 1.2;
        modelDeployment_B.pose_d[3] = 0.0;
        modelDeployment_B.pose_d[4] = 0.0;
        modelDeployment_B.pose_d[5] = modelDeployment_rt_atan2d_snf(cos
          ((modelDeployment_B.Product3_g - 2.75) * 2.0) * 18.849555921538759 /
          25.0, 18.849555921538759 * modelDeployment_B.Product1_or / 25.0) -
          1.5707963267948966;
      } else if ((modelDeployment_B.t_reset >= 36.0) &&
                 (modelDeployment_B.t_reset < 39.0)) {
        modelDeployment_B.pose_d[0] = 0.0;
        modelDeployment_B.pose_d[1] = 0.0;
        modelDeployment_B.pose_d[2] = 1.2;
        modelDeployment_B.pose_d[3] = 0.0;
        modelDeployment_B.pose_d[4] = 0.0;
        modelDeployment_B.pose_d[5] = (modelDeployment_B.t_reset - 39.0) *
          0.261746077120484;
      } else if ((modelDeployment_B.t_reset >= 39.0) &&
                 (modelDeployment_B.t_reset < 42.0)) {
        modelDeployment_B.pose_d[0] = 0.0;
        modelDeployment_B.pose_d[1] = 0.0;
        modelDeployment_B.pose_d[2] = (modelDeployment_B.t_reset - 42.0) * -0.9 /
          3.0 + 0.3;
        modelDeployment_B.pose_d[3] = 0.0;
        modelDeployment_B.pose_d[4] = 0.0;
        modelDeployment_B.pose_d[5] = 0.0;
      } else {
        for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g <
             6; modelDeployment_B.ParamStep_g++) {
          modelDeployment_B.pose_d[modelDeployment_B.ParamStep_g] =
            b[modelDeployment_B.ParamStep_g];
        }
      }

      // End of MATLAB Function: '<S94>/Lemniscate Trajectory'

      // S-Function (sdspunwrap2): '<S94>/Unwrap1'
      if (modelDeployment_DW.Unwrap1_FirstStep) {
        modelDeployment_DW.Unwrap1_Prev = modelDeployment_B.pose_d[5];
        modelDeployment_DW.Unwrap1_FirstStep = false;
      }

      modelDeployment_B.Product3_g = modelDeployment_B.pose_d[5] -
        modelDeployment_DW.Unwrap1_Prev;
      modelDeployment_B.t_reset = modelDeployment_B.Product3_g - floor
        ((modelDeployment_B.Product3_g + 3.1415926535897931) /
         6.2831853071795862) * 6.2831853071795862;
      if ((modelDeployment_B.t_reset == -3.1415926535897931) &&
          (modelDeployment_B.Product3_g > 0.0)) {
        modelDeployment_B.t_reset = 3.1415926535897931;
      }

      modelDeployment_B.Product3_g = modelDeployment_B.t_reset -
        modelDeployment_B.Product3_g;
      if (fabs(modelDeployment_B.Product3_g) > 3.1415926535897931) {
        modelDeployment_DW.Unwrap1_Cumsum += modelDeployment_B.Product3_g;
      }

      modelDeployment_DW.Unwrap1_Prev = modelDeployment_B.pose_d[5];
      for (modelDeployment_B.i = 0; modelDeployment_B.i < 5; modelDeployment_B.i
           ++) {
        // Product: '<S117>/Product6' incorporates:
        //   Constant: '<S94>/Constant13'

        modelDeployment_B.Product3_g =
          modelDeployment_P.Constant13_Value_f[modelDeployment_B.i];

        // DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
        //   Constant: '<S94>/Constant13'
        //   Memory: '<S117>/Memory'
        //   Product: '<S117>/Product6'
        //   Product: '<S117>/Product7'
        //   Sum: '<S117>/Sum5'
        //   Sum: '<S117>/Sum6'

        modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.i] =
          ((modelDeployment_B.pose_d[modelDeployment_B.i] -
            modelDeployment_DW.Memory_PreviousInput[modelDeployment_B.i]) *
           modelDeployment_B.Product3_g -
           modelDeployment_DW.Memory1_PreviousInput[modelDeployment_B.i]) *
          modelDeployment_B.Product3_g *
          modelDeployment_P.DiscreteTimeIntegrator_gainva_k;
      }

      // DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
      //   Constant: '<S94>/Constant13'
      //   Memory: '<S117>/Memory'
      //   Product: '<S117>/Product6'
      //   Product: '<S117>/Product7'
      //   S-Function (sdspunwrap2): '<S94>/Unwrap1'
      //   Sum: '<S117>/Sum5'
      //   Sum: '<S117>/Sum6'

      modelDeployment_B.PolynomialTrajectory2_o1[5] =
        (((modelDeployment_B.pose_d[5] + modelDeployment_DW.Unwrap1_Cumsum) -
          modelDeployment_DW.Memory_PreviousInput[5]) *
         modelDeployment_P.Constant13_Value_f[5] -
         modelDeployment_DW.Memory1_PreviousInput[5]) *
        modelDeployment_P.Constant13_Value_f[5] *
        modelDeployment_P.DiscreteTimeIntegrator_gainva_k;
      for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i
           ++) {
        // DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
        modelDeployment_B.Product3_g =
          modelDeployment_DW.DiscreteTimeIntegrator_DSTATE[modelDeployment_B.i]
          + modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.i];
        modelDeployment_DW.DiscreteTimeIntegrator_DSTATE[modelDeployment_B.i] =
          modelDeployment_B.Product3_g;

        // DiscreteIntegrator: '<S117>/Discrete-Time Integrator1' incorporates:
        //   DiscreteIntegrator: '<S117>/Discrete-Time Integrator'

        modelDeployment_B.Product1_or =
          modelDeployment_P.DiscreteTimeIntegrator1_gainv_i *
          modelDeployment_B.Product3_g;
        modelDeployment_B.pose_d[modelDeployment_B.i] =
          modelDeployment_B.Product1_or;

        // DiscreteIntegrator: '<S117>/Discrete-Time Integrator1'
        modelDeployment_DW.Memory_PreviousInput[modelDeployment_B.i] =
          modelDeployment_DW.DiscreteTimeIntegrator1_DSTATE[modelDeployment_B.i]
          + modelDeployment_B.Product1_or;
      }

      // MATLAB Function: '<S94>/rpyd2quaterniond'
      modelDeployment_B.r_b1[0] = cos(modelDeployment_DW.Memory_PreviousInput[3]
        / 2.0);
      modelDeployment_B.r_b1[1] = sin(modelDeployment_DW.Memory_PreviousInput[3]
        / 2.0);
      modelDeployment_B.r_b1[2] = 0.0;
      modelDeployment_B.r_b1[3] = 0.0;
      modelDeployment_B.qx_c[0] = cos(modelDeployment_DW.Memory_PreviousInput[4]
        / 2.0);
      modelDeployment_B.qx_c[1] = 0.0;
      modelDeployment_B.qx_c[2] = sin(modelDeployment_DW.Memory_PreviousInput[4]
        / 2.0);
      modelDeployment_B.qx_c[3] = 0.0;
      modelDeployment_B.qz_e[0] = cos(modelDeployment_DW.Memory_PreviousInput[5]
        / 2.0);
      modelDeployment_B.qz_e[1] = 0.0;
      modelDeployment_B.qz_e[2] = 0.0;
      modelDeployment_B.qz_e[3] = sin(modelDeployment_DW.Memory_PreviousInput[5]
        / 2.0);

      // MATLAB Function: '<S114>/Kronecker_product'
      modelDeployme_Kronecker_product(modelDeployment_B.r_b1,
        modelDeployment_B.qx_c, &modelDeployment_DW.Memory1_PreviousInput[0],
        &modelDeployment_B.sf_Kronecker_product_a);

      // MATLAB Function: '<S113>/Kronecker_product'
      modelDeployme_Kronecker_product(&modelDeployment_DW.Memory1_PreviousInput
        [0], modelDeployment_B.qz_e, modelDeployment_B.r_b1,
        &modelDeployment_B.sf_Kronecker_product_b);

      // Sqrt: '<S121>/sqrt' incorporates:
      //   Product: '<S122>/Product'
      //   Product: '<S122>/Product1'
      //   Product: '<S122>/Product2'
      //   Product: '<S122>/Product3'
      //   Sum: '<S122>/Sum'

      modelDeployment_B.Product3_g = sqrt(((modelDeployment_B.r_b1[0] *
        modelDeployment_B.r_b1[0] + modelDeployment_B.r_b1[1] *
        modelDeployment_B.r_b1[1]) + modelDeployment_B.r_b1[2] *
        modelDeployment_B.r_b1[2]) + modelDeployment_B.r_b1[3] *
        modelDeployment_B.r_b1[3]);

      // Merge: '<S88>/Merge' incorporates:
      //   Constant: '<S94>/Constant12'
      //   Product: '<S116>/Product'
      //   Product: '<S116>/Product1'
      //   Product: '<S116>/Product2'
      //   Product: '<S116>/Product3'
      //   SignalConversion generated from: '<S94>/lemniquat'

      modelDeployment_B.Merge[18] = modelDeployment_B.r_b1[0] /
        modelDeployment_B.Product3_g;
      modelDeployment_B.Merge[19] = modelDeployment_B.r_b1[1] /
        modelDeployment_B.Product3_g;
      modelDeployment_B.Merge[20] = modelDeployment_B.r_b1[2] /
        modelDeployment_B.Product3_g;
      modelDeployment_B.Merge[21] = modelDeployment_B.r_b1[3] /
        modelDeployment_B.Product3_g;
      for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i
           ++) {
        modelDeployment_B.t_reset =
          modelDeployment_DW.Memory_PreviousInput[modelDeployment_B.i];
        modelDeployment_B.Merge[modelDeployment_B.i] = modelDeployment_B.t_reset;
        modelDeployment_B.Product3_g =
          modelDeployment_DW.DiscreteTimeIntegrator_DSTATE[modelDeployment_B.i];
        modelDeployment_B.Merge[modelDeployment_B.i + 6] =
          modelDeployment_B.Product3_g;
        modelDeployment_B.Merge[modelDeployment_B.i + 12] =
          modelDeployment_P.Constant12_Value[modelDeployment_B.i];

        // Update for Memory: '<S117>/Memory1' incorporates:
        //   Constant: '<S94>/Constant12'
        //   DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
        //   Gain: '<S117>/zeta'

        modelDeployment_DW.Memory1_PreviousInput[modelDeployment_B.i] =
          modelDeployment_P.zeta_Gain_h * modelDeployment_B.Product3_g;

        // Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
        modelDeployment_DW.DiscreteTimeIntegrator_DSTATE[modelDeployment_B.i] =
          modelDeployment_B.Product3_g +
          modelDeployment_B.PolynomialTrajectory2_o1[modelDeployment_B.i];

        // Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator1'
        modelDeployment_DW.DiscreteTimeIntegrator1_DSTATE[modelDeployment_B.i] =
          modelDeployment_B.t_reset +
          modelDeployment_B.pose_d[modelDeployment_B.i];
      }

      // End of Outputs for SubSystem: '<S88>/If Action Subsystem5'
      break;
    }

    // End of SwitchCase: '<S88>/Switch Case'
  }

  // End of ManualSwitch: '<S6>/Manual Switch'
  // End of Outputs for SubSystem: '<S6>/Subsystem'

  // MATLABSystem: '<S23>/SourceBlock'
  modelDeployment_B.NOT = uORB_read_step(modelDeployment_DW.obj_j.orbMetadataObj,
    &modelDeployment_DW.obj_j.eventStructObj, &modelDeployment_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S27>/Enable'

  // Start for MATLABSystem: '<S23>/SourceBlock'
  if (modelDeployment_B.NOT) {
    // SignalConversion generated from: '<S27>/In1'
    modelDeployment_B.In1 = modelDeployment_B.r;
  }

  // End of Outputs for SubSystem: '<S23>/Enabled Subsystem'

  // Gain: '<S4>/Gain1' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion3'

  modelDeployment_B.Gain1[0] = modelDeployment_P.Gain1_Gain[0] *
    modelDeployment_B.In1.y;
  modelDeployment_B.Gain1[1] = modelDeployment_B.In1.x *
    modelDeployment_P.Gain1_Gain[1];
  modelDeployment_B.Gain1[2] = modelDeployment_P.Gain1_Gain[2] *
    modelDeployment_B.In1.z;

  // MATLABSystem: '<S21>/SourceBlock'
  modelDeployment_B.NOT = uORB_read_step(modelDeployment_DW.obj_k.orbMetadataObj,
    &modelDeployment_DW.obj_k.eventStructObj, &modelDeployment_B.r3, false, 1.0);

  // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S25>/Enable'

  // Start for MATLABSystem: '<S21>/SourceBlock'
  if (modelDeployment_B.NOT) {
    // SignalConversion generated from: '<S25>/In1'
    modelDeployment_B.In1_p = modelDeployment_B.r3;
  }

  // End of Outputs for SubSystem: '<S21>/Enabled Subsystem'

  // Gain: '<S4>/Gain' incorporates:
  //   DataTypeConversion: '<S4>/Data Type Conversion4'

  modelDeployment_B.r_b1[0] = modelDeployment_P.Gain_Gain[0] *
    modelDeployment_B.In1_p.q[0];
  modelDeployment_B.r_b1[1] = modelDeployment_P.Gain_Gain[1] *
    modelDeployment_B.In1_p.q[2];
  modelDeployment_B.r_b1[2] = modelDeployment_B.In1_p.q[1] *
    modelDeployment_P.Gain_Gain[2];
  modelDeployment_B.r_b1[3] = modelDeployment_P.Gain_Gain[3] *
    modelDeployment_B.In1_p.q[3];

  // Sqrt: '<S78>/sqrt' incorporates:
  //   Product: '<S79>/Product'
  //   Product: '<S79>/Product1'
  //   Product: '<S79>/Product2'
  //   Product: '<S79>/Product3'
  //   Sum: '<S79>/Sum'

  modelDeployment_B.Product3_g = sqrt(((modelDeployment_B.r_b1[0] *
    modelDeployment_B.r_b1[0] + modelDeployment_B.r_b1[1] *
    modelDeployment_B.r_b1[1]) + modelDeployment_B.r_b1[2] *
    modelDeployment_B.r_b1[2]) + modelDeployment_B.r_b1[3] *
    modelDeployment_B.r_b1[3]);

  // Product: '<S77>/Product'
  modelDeployment_B.t_reset = modelDeployment_B.r_b1[0] /
    modelDeployment_B.Product3_g;

  // Product: '<S77>/Product1'
  modelDeployment_B.Product1_or = modelDeployment_B.r_b1[1] /
    modelDeployment_B.Product3_g;

  // Product: '<S77>/Product2'
  modelDeployment_B.Product2_p = modelDeployment_B.r_b1[2] /
    modelDeployment_B.Product3_g;

  // Product: '<S77>/Product3'
  modelDeployment_B.Product3_g = modelDeployment_B.r_b1[3] /
    modelDeployment_B.Product3_g;

  // Product: '<S67>/Product3' incorporates:
  //   Product: '<S71>/Product3'

  modelDeployment_B.rtb_VectorConcatenate_tmp_jz = modelDeployment_B.t_reset *
    modelDeployment_B.t_reset;

  // Product: '<S67>/Product2' incorporates:
  //   Product: '<S71>/Product2'

  modelDeployment_B.rtb_VectorConcatenate_tmp_o = modelDeployment_B.Product1_or *
    modelDeployment_B.Product1_or;

  // Product: '<S67>/Product1' incorporates:
  //   Product: '<S71>/Product1'
  //   Product: '<S75>/Product1'

  modelDeployment_B.rtb_VectorConcatenate_tmp_n = modelDeployment_B.Product2_p *
    modelDeployment_B.Product2_p;

  // Product: '<S67>/Product' incorporates:
  //   Product: '<S71>/Product'
  //   Product: '<S75>/Product'

  modelDeployment_B.rtb_VectorConcatenate_tmp_i = modelDeployment_B.Product3_g *
    modelDeployment_B.Product3_g;

  // Sum: '<S67>/Sum' incorporates:
  //   Product: '<S67>/Product'
  //   Product: '<S67>/Product1'
  //   Product: '<S67>/Product2'
  //   Product: '<S67>/Product3'

  modelDeployment_B.VectorConcatenate[0] =
    ((modelDeployment_B.rtb_VectorConcatenate_tmp_jz +
      modelDeployment_B.rtb_VectorConcatenate_tmp_o) -
     modelDeployment_B.rtb_VectorConcatenate_tmp_n) -
    modelDeployment_B.rtb_VectorConcatenate_tmp_i;

  // Product: '<S70>/Product3' incorporates:
  //   Product: '<S68>/Product3'

  modelDeployment_B.rtb_VectorConcatenate_tmp = modelDeployment_B.Product3_g *
    modelDeployment_B.t_reset;

  // Product: '<S70>/Product2' incorporates:
  //   Product: '<S68>/Product2'

  modelDeployment_B.rtb_VectorConcatenate_tmp_j = modelDeployment_B.Product1_or *
    modelDeployment_B.Product2_p;

  // Gain: '<S70>/Gain' incorporates:
  //   Product: '<S70>/Product2'
  //   Product: '<S70>/Product3'
  //   Sum: '<S70>/Sum'

  modelDeployment_B.VectorConcatenate[1] =
    (modelDeployment_B.rtb_VectorConcatenate_tmp_j -
     modelDeployment_B.rtb_VectorConcatenate_tmp) *
    modelDeployment_P.Gain_Gain_a;

  // Product: '<S73>/Product2' incorporates:
  //   Product: '<S69>/Product2'

  modelDeployment_B.rtb_VectorConcatenate_tmp_oy = modelDeployment_B.Product1_or
    * modelDeployment_B.Product3_g;

  // Product: '<S73>/Product1' incorporates:
  //   Product: '<S69>/Product1'

  modelDeployment_B.rtb_VectorConcatenate_tmp_nv = modelDeployment_B.t_reset *
    modelDeployment_B.Product2_p;

  // Gain: '<S73>/Gain' incorporates:
  //   Product: '<S73>/Product1'
  //   Product: '<S73>/Product2'
  //   Sum: '<S73>/Sum'

  modelDeployment_B.VectorConcatenate[2] =
    (modelDeployment_B.rtb_VectorConcatenate_tmp_nv +
     modelDeployment_B.rtb_VectorConcatenate_tmp_oy) *
    modelDeployment_P.Gain_Gain_m;

  // Gain: '<S68>/Gain' incorporates:
  //   Sum: '<S68>/Sum'

  modelDeployment_B.VectorConcatenate[3] =
    (modelDeployment_B.rtb_VectorConcatenate_tmp +
     modelDeployment_B.rtb_VectorConcatenate_tmp_j) *
    modelDeployment_P.Gain_Gain_g;

  // Sum: '<S71>/Sum' incorporates:
  //   Sum: '<S75>/Sum'

  modelDeployment_B.rtb_VectorConcatenate_tmp_jz -=
    modelDeployment_B.rtb_VectorConcatenate_tmp_o;
  modelDeployment_B.VectorConcatenate[4] =
    (modelDeployment_B.rtb_VectorConcatenate_tmp_jz +
     modelDeployment_B.rtb_VectorConcatenate_tmp_n) -
    modelDeployment_B.rtb_VectorConcatenate_tmp_i;

  // Product: '<S74>/Product1' incorporates:
  //   Product: '<S72>/Product1'

  modelDeployment_B.rtb_VectorConcatenate_tmp_o = modelDeployment_B.t_reset *
    modelDeployment_B.Product1_or;

  // Product: '<S74>/Product2' incorporates:
  //   Product: '<S72>/Product2'

  modelDeployment_B.rtb_VectorConcatenate_tmp = modelDeployment_B.Product2_p *
    modelDeployment_B.Product3_g;

  // Gain: '<S74>/Gain' incorporates:
  //   Product: '<S74>/Product1'
  //   Product: '<S74>/Product2'
  //   Sum: '<S74>/Sum'

  modelDeployment_B.VectorConcatenate[5] =
    (modelDeployment_B.rtb_VectorConcatenate_tmp -
     modelDeployment_B.rtb_VectorConcatenate_tmp_o) *
    modelDeployment_P.Gain_Gain_k;

  // Gain: '<S69>/Gain' incorporates:
  //   Sum: '<S69>/Sum'

  modelDeployment_B.VectorConcatenate[6] =
    (modelDeployment_B.rtb_VectorConcatenate_tmp_oy -
     modelDeployment_B.rtb_VectorConcatenate_tmp_nv) *
    modelDeployment_P.Gain_Gain_l;

  // Gain: '<S72>/Gain' incorporates:
  //   Sum: '<S72>/Sum'

  modelDeployment_B.VectorConcatenate[7] =
    (modelDeployment_B.rtb_VectorConcatenate_tmp_o +
     modelDeployment_B.rtb_VectorConcatenate_tmp) *
    modelDeployment_P.Gain_Gain_n;

  // Sum: '<S75>/Sum'
  modelDeployment_B.VectorConcatenate[8] =
    (modelDeployment_B.rtb_VectorConcatenate_tmp_jz -
     modelDeployment_B.rtb_VectorConcatenate_tmp_n) +
    modelDeployment_B.rtb_VectorConcatenate_tmp_i;

  // Gain: '<S42>/Gain1' incorporates:
  //   Concatenate: '<S76>/Vector Concatenate'
  //   Selector: '<S42>/Selector1'

  modelDeployment_B.Product3_g = modelDeployment_P.Gain1_Gain_e[2] *
    modelDeployment_B.VectorConcatenate[2];

  // If: '<S38>/If'
  if ((modelDeployment_B.Product3_g >= 1.0) || (modelDeployment_B.Product3_g <=
       -1.0)) {
    // Outputs for IfAction SubSystem: '<S38>/AxisRotZeroR3' incorporates:
    //   ActionPort: '<S41>/Action Port'

    // Fcn: '<S41>/Fcn1' incorporates:
    //   Concatenate: '<S76>/Vector Concatenate'
    //   Gain: '<S42>/Gain3'
    //   Selector: '<S42>/Selector3'

    modelDeployment_B.Merge_b[0] = modelDeployment_rt_atan2d_snf
      (modelDeployment_P.Gain3_Gain[0] * modelDeployment_B.VectorConcatenate[7],
       modelDeployment_P.Gain3_Gain[1] * modelDeployment_B.VectorConcatenate[4]);

    // If: '<S48>/If' incorporates:
    //   Constant: '<S49>/Constant'
    //   Constant: '<S50>/Constant'
    //   Fcn: '<S41>/Fcn2'

    if (modelDeployment_B.Product3_g > 1.0) {
      modelDeployment_B.Product3_g = modelDeployment_P.Constant_Value_bd;
    } else if (modelDeployment_B.Product3_g < -1.0) {
      modelDeployment_B.Product3_g = modelDeployment_P.Constant_Value_h;
    }

    if (modelDeployment_B.Product3_g > 1.0) {
      modelDeployment_B.Product3_g = 1.0;
    } else if (modelDeployment_B.Product3_g < -1.0) {
      modelDeployment_B.Product3_g = -1.0;
    }

    // End of If: '<S48>/If'

    // Fcn: '<S41>/Fcn2'
    modelDeployment_B.Merge_b[1] = asin(modelDeployment_B.Product3_g);

    // Fcn: '<S41>/Fcn3'
    modelDeployment_B.Merge_b[2] = 0.0;

    // End of Outputs for SubSystem: '<S38>/AxisRotZeroR3'
  } else {
    // Outputs for IfAction SubSystem: '<S38>/AxisRotDefault' incorporates:
    //   ActionPort: '<S40>/Action Port'

    // Fcn: '<S40>/Fcn1' incorporates:
    //   Concatenate: '<S76>/Vector Concatenate'
    //   Gain: '<S42>/Gain1'
    //   Selector: '<S42>/Selector1'

    modelDeployment_B.Merge_b[0] = modelDeployment_rt_atan2d_snf
      (modelDeployment_P.Gain1_Gain_e[0] * modelDeployment_B.VectorConcatenate[5],
       modelDeployment_P.Gain1_Gain_e[1] * modelDeployment_B.VectorConcatenate[8]);

    // Outputs for IfAction SubSystem: '<S44>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S47>/Action Port'

    // If: '<S44>/If' incorporates:
    //   Fcn: '<S40>/Fcn2'
    //   SignalConversion generated from: '<S47>/In'

    modelDeployment_B.Merge_b[1] = asin(modelDeployment_B.Product3_g);

    // End of Outputs for SubSystem: '<S44>/If Action Subsystem2'

    // Fcn: '<S40>/Fcn3' incorporates:
    //   Concatenate: '<S76>/Vector Concatenate'
    //   Gain: '<S42>/Gain2'
    //   Selector: '<S42>/Selector2'

    modelDeployment_B.Merge_b[2] = modelDeployment_rt_atan2d_snf
      (modelDeployment_P.Gain2_Gain[0] * modelDeployment_B.VectorConcatenate[1],
       modelDeployment_B.VectorConcatenate[0] * modelDeployment_P.Gain2_Gain[1]);

    // End of Outputs for SubSystem: '<S38>/AxisRotDefault'
  }

  // End of If: '<S38>/If'

  // Outputs for Enabled SubSystem: '<S1>/EnableController' incorporates:
  //   EnablePort: '<S8>/arm'

  if (modelDeployment_B.DataTypeConversion_h) {
    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   UnitDelay generated from: '<S8>/Unit Delay'

    modelDeployment_B.qe[0] = modelDeployment_DW.UnitDelay_6_DSTATE[0];
    modelDeployment_B.qe[1] = modelDeployment_DW.UnitDelay_6_DSTATE[1];
    modelDeployment_B.qe[2] = modelDeployment_DW.UnitDelay_6_DSTATE[2];
    modelDeployment_B.qe[3] = modelDeployment_DW.UnitDelay_6_DSTATE[3];
    for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i++)
    {
      // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   UnitDelay generated from: '<S8>/Unit Delay'

      modelDeployment_B.e[modelDeployment_B.i] =
        modelDeployment_DW.UnitDelay_2_DSTATE[modelDeployment_B.i];

      // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   UnitDelay generated from: '<S8>/Unit Delay'

      modelDeployment_B.sigma[modelDeployment_B.i] =
        modelDeployment_DW.UnitDelay_4_DSTATE[modelDeployment_B.i];

      // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   UnitDelay generated from: '<S8>/Unit Delay'

      modelDeployment_B.kt[modelDeployment_B.i] =
        modelDeployment_DW.UnitDelay_5_DSTATE[modelDeployment_B.i];

      // SignalConversion generated from: '<S8>/data_out_Outport_2'
      modelDeployment_B.qd[modelDeployment_B.i] =
        modelDeployment_B.Merge[modelDeployment_B.i];

      // Product: '<S11>/Matrix Multiply1' incorporates:
      //   Constant: '<S11>/Tmotor_10inch_allo_inv'

      modelDeployment_B.Product2_p = 0.0;
      for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 6;
           modelDeployment_B.ParamStep_g++) {
        // Product: '<S11>/Matrix Multiply1' incorporates:
        //   Constant: '<S11>/Tmotor_10inch_allo_inv'
        //   UnitDelay generated from: '<S8>/Unit Delay'

        modelDeployment_B.Product2_p += rtP_allo_i[6 *
          modelDeployment_B.ParamStep_g + modelDeployment_B.i] *
          modelDeployment_DW.UnitDelay_1_DSTATE[modelDeployment_B.ParamStep_g];
      }

      // Product: '<S11>/Matrix Multiply1' incorporates:
      //   Constant: '<S11>/Tmotor_10inch_allo_inv'

      modelDeployment_B.MatrixMultiply1[modelDeployment_B.i] =
        modelDeployment_B.Product2_p;
    }

    // MATLABSystem: '<S8>/Read Parameter1'
    modelDeployment_B.NOT = MW_Param_Step
      (modelDeployment_DW.obj_pq.MW_PARAMHANDLE, MW_INT32,
       &modelDeployment_B.ParamStep_g);
    if (modelDeployment_B.NOT) {
      modelDeployment_B.ParamStep_g = 0;
    }

    // SwitchCase: '<S8>/Switch Case1' incorporates:
    //   DataTypeConversion: '<S8>/Data Type Conversion1'
    //   MATLABSystem: '<S8>/Read Parameter1'
    //
    modelDeployment_B.ParamStep = static_cast<real32_T>(fmod(static_cast<real_T>
      (static_cast<real32_T>(modelDeployment_B.ParamStep_g)), 4.294967296E+9));
    switch (modelDeployment_B.ParamStep < 0.0F ? -static_cast<int32_T>(
             static_cast<uint32_T>(-modelDeployment_B.ParamStep)) : static_cast<
            int32_T>(static_cast<uint32_T>(modelDeployment_B.ParamStep))) {
     case 1:
      // Outputs for IfAction SubSystem: '<S8>/Fixed-Time Differentiator' incorporates:
      //   ActionPort: '<S12>/Action Port'

      // Merge generated from: '<S8>/Merge1' incorporates:
      //   ModelReference generated from: '<S12>/Model'

      FxTDiffSim(&modelDeployment_B.Gain1[0], &modelDeployment_B.Merge_b[0],
                 &modelDeployment_B.DataTypeConversion_c[0],
                 &modelDeployment_B.DataTypeConversion3_c[0],
                 &modelDeployment_B.DataTypeConversion2_m[0],
                 &modelDeployment_B.DataTypeConversion1_h[0],
                 &modelDeployment_B.pos_hat[0], &modelDeployment_B.pos_dot_hat[0],
                 &modelDeployment_B.pos_ddot_hat[0], &modelDeployment_B.e_hat[0],
                 &modelDeployment_B.q_hat[0], &modelDeployment_B.q_tilde[0],
                 &(modelDeployment_DW.Model_InstanceData_j.rtb),
                 &(modelDeployment_DW.Model_InstanceData_j.rtdw));

      // End of Outputs for SubSystem: '<S8>/Fixed-Time Differentiator'
      break;

     case 2:
      // Outputs for IfAction SubSystem: '<S8>/Fixed-Time ESO' incorporates:
      //   ActionPort: '<S13>/Action Port'

      // Merge generated from: '<S8>/Merge1' incorporates:
      //   ModelReference generated from: '<S13>/Model'
      //   UnitDelay generated from: '<S8>/Unit Delay'

      FxTESO(&modelDeployment_B.Gain1[0], &modelDeployment_B.Merge_b[0],
             &modelDeployment_B.MCData[0],
             &modelDeployment_B.DataTypeConversion3_k[0],
             &modelDeployment_B.DataTypeConversion_n[0],
             &modelDeployment_B.DataTypeConversion1_d[0],
             &modelDeployment_B.DataTypeConversion2_m1[0],
             &modelDeployment_B.DataTypeConversion4_k[0],
             &modelDeployment_B.DataTypeConversion5_d[0],
             &modelDeployment_DW.UnitDelay_1_DSTATE[0],
             &modelDeployment_B.pos_hat[0], &modelDeployment_B.pos_dot_hat[0],
             &modelDeployment_B.pos_ddot_hat[0], &modelDeployment_B.e_hat[0],
             &modelDeployment_B.q_hat[0], &modelDeployment_B.q_tilde[0],
             &(modelDeployment_DW.Model_InstanceData_o.rtb),
             &(modelDeployment_DW.Model_InstanceData_o.rtdw));

      // End of Outputs for SubSystem: '<S8>/Fixed-Time ESO'
      break;

     case 3:
      // Outputs for IfAction SubSystem: '<S8>/Fixed-Time Quaternion Differentiator' incorporates:
      //   ActionPort: '<S14>/Action Port'

      // Merge generated from: '<S8>/Merge1' incorporates:
      //   ModelReference generated from: '<S14>/FxTDQuat'

      FxtD_Quaternion(&modelDeployment_B.Gain1[0],
                      &modelDeployment_B.DataTypeConversion_c[0],
                      &modelDeployment_B.DataTypeConversion3_c[0],
                      &modelDeployment_B.DataTypeConversion2_m[0],
                      &modelDeployment_B.DataTypeConversion1_h[0],
                      &modelDeployment_B.r_b1[0], &modelDeployment_B.pos_hat[0],
                      &modelDeployment_B.pos_dot_hat[0],
                      &modelDeployment_B.pos_ddot_hat[0],
                      &modelDeployment_B.e_hat[0], &modelDeployment_B.q_hat[0],
                      &modelDeployment_B.q_tilde[0],
                      &(modelDeployment_DW.FxTDQuat_InstanceData.rtb),
                      &(modelDeployment_DW.FxTDQuat_InstanceData.rtdw));

      // End of Outputs for SubSystem: '<S8>/Fixed-Time Quaternion Differentiator' 
      break;

     case 4:
      // Outputs for IfAction SubSystem: '<S8>/Fixed-Time Quaternion ESO' incorporates:
      //   ActionPort: '<S15>/Action Port'

      // Merge generated from: '<S8>/Merge1' incorporates:
      //   ModelReference generated from: '<S15>/Model'
      //   UnitDelay generated from: '<S8>/Unit Delay'

      FxTESO_Quaternion(&modelDeployment_B.Gain1[0], &modelDeployment_B.MCData[0],
                        &modelDeployment_B.DataTypeConversion_n[0],
                        &modelDeployment_B.DataTypeConversion1_d[0],
                        &modelDeployment_B.DataTypeConversion2_m1[0],
                        &modelDeployment_B.DataTypeConversion3_k[0],
                        &modelDeployment_B.DataTypeConversion_n[0],
                        &modelDeployment_B.DataTypeConversion1_d[0],
                        &modelDeployment_B.DataTypeConversion2_m1[0],
                        &modelDeployment_B.DataTypeConversion4_k[0],
                        &modelDeployment_B.DataTypeConversion5_d[0],
                        &modelDeployment_DW.UnitDelay_1_DSTATE[0],
                        &modelDeployment_B.r_b1[0], &modelDeployment_B.pos_hat[0],
                        &modelDeployment_B.pos_dot_hat[0],
                        &modelDeployment_B.pos_ddot_hat[0],
                        &modelDeployment_B.e_hat[0], &modelDeployment_B.q_hat[0],
                        &modelDeployment_B.q_tilde[0],
                        &(modelDeployment_DW.Model_InstanceData.rtb),
                        &(modelDeployment_DW.Model_InstanceData.rtdw));

      // End of Outputs for SubSystem: '<S8>/Fixed-Time Quaternion ESO'
      break;
    }

    // End of SwitchCase: '<S8>/Switch Case1'
    for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i++)
    {
      // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   UnitDelay generated from: '<S8>/Unit Delay'

      modelDeployment_B.Fu_d[modelDeployment_B.i] =
        modelDeployment_DW.UnitDelay_1_DSTATE[modelDeployment_B.i];

      // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Merge generated from: '<S8>/Merge1'

      modelDeployment_B.pos_hat_c[modelDeployment_B.i] =
        modelDeployment_B.pos_hat[modelDeployment_B.i];

      // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Merge generated from: '<S8>/Merge1'

      modelDeployment_B.pos_dot_hat_i[modelDeployment_B.i] =
        modelDeployment_B.pos_dot_hat[modelDeployment_B.i];

      // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Merge generated from: '<S8>/Merge1'

      modelDeployment_B.pos_ddot_hat_f[modelDeployment_B.i] =
        modelDeployment_B.pos_ddot_hat[modelDeployment_B.i];

      // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Merge generated from: '<S8>/Merge1'

      modelDeployment_B.e_hat_l[modelDeployment_B.i] =
        modelDeployment_B.e_hat[modelDeployment_B.i];
    }

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge generated from: '<S8>/Merge1'

    modelDeployment_B.q_hat_p[0] = modelDeployment_B.q_hat[0];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge generated from: '<S8>/Merge1'

    modelDeployment_B.q_tilde_k[0] = modelDeployment_B.q_tilde[0];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge generated from: '<S8>/Merge1'

    modelDeployment_B.q_hat_p[1] = modelDeployment_B.q_hat[1];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge generated from: '<S8>/Merge1'

    modelDeployment_B.q_tilde_k[1] = modelDeployment_B.q_tilde[1];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge generated from: '<S8>/Merge1'

    modelDeployment_B.q_hat_p[2] = modelDeployment_B.q_hat[2];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge generated from: '<S8>/Merge1'

    modelDeployment_B.q_tilde_k[2] = modelDeployment_B.q_tilde[2];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge generated from: '<S8>/Merge1'

    modelDeployment_B.q_hat_p[3] = modelDeployment_B.q_hat[3];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge generated from: '<S8>/Merge1'

    modelDeployment_B.q_tilde_k[3] = modelDeployment_B.q_tilde[3];

    // MATLABSystem: '<S8>/Read Parameter'
    modelDeployment_B.NOT = MW_Param_Step
      (modelDeployment_DW.obj_bi.MW_PARAMHANDLE, MW_INT32,
       &modelDeployment_B.ParamStep_g);
    if (modelDeployment_B.NOT) {
      modelDeployment_B.ParamStep_g = 0;
    }

    // SwitchCase: '<S8>/Switch Case' incorporates:
    //   DataTypeConversion: '<S8>/Data Type Conversion'
    //   MATLABSystem: '<S8>/Read Parameter'
    //
    modelDeployment_B.ParamStep = static_cast<real32_T>(fmod(static_cast<real_T>
      (static_cast<real32_T>(modelDeployment_B.ParamStep_g)), 4.294967296E+9));
    switch (modelDeployment_B.ParamStep < 0.0F ? -static_cast<int32_T>(
             static_cast<uint32_T>(-modelDeployment_B.ParamStep)) : static_cast<
            int32_T>(static_cast<uint32_T>(modelDeployment_B.ParamStep))) {
     case 0:
      // Outputs for IfAction SubSystem: '<S8>/PDController' incorporates:
      //   ActionPort: '<S16>/Action Port'

      // Merge generated from: '<S8>/Merge' incorporates:
      //   ModelReference generated from: '<S16>/Model'

      pdGc(&modelDeployment_B.Merge[0], &modelDeployment_B.Merge[6],
           &modelDeployment_B.pos_hat[0], &modelDeployment_B.pos_dot_hat[0],
           &modelDeployment_B.posGains[0], &modelDeployment_B.attGains[0],
           &modelDeployment_B.MCData[0], &modelDeployment_B.Fu_f[0],
           &modelDeployment_B.e_h[0], &modelDeployment_B.e_dot[0],
           &modelDeployment_B.sigma_f[0], &modelDeployment_B.kt_b[0],
           &(modelDeployment_DW.Model_InstanceData_d.rtb));

      // Merge generated from: '<S8>/Merge' incorporates:
      //   ModelReference generated from: '<S16>/Model'
      //   SignalConversion generated from: '<S16>/Model'

      modelDeployment_B.qe_p[0] = modelDeployment_B.qe_fc[0];
      modelDeployment_B.qe_p[1] = modelDeployment_B.qe_fc[1];
      modelDeployment_B.qe_p[2] = modelDeployment_B.qe_fc[2];
      modelDeployment_B.qe_p[3] = modelDeployment_B.qe_fc[3];

      // End of Outputs for SubSystem: '<S8>/PDController'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S8>/ASGSMController' incorporates:
      //   ActionPort: '<S9>/Action Port'

      // Merge generated from: '<S8>/Merge' incorporates:
      //   ModelReference generated from: '<S9>/Model'

      asgsm(&modelDeployment_B.Merge[0], &modelDeployment_B.Merge[6],
            &modelDeployment_B.Merge[12], &modelDeployment_B.pos_hat[0],
            &modelDeployment_B.pos_dot_hat[0],
            &modelDeployment_B.DataTypeConversion3[0],
            &modelDeployment_B.DataTypeConversion6[0],
            &modelDeployment_B.DataTypeConversion4[0],
            &modelDeployment_B.DataTypeConversion2[0],
            &modelDeployment_B.DataTypeConversion[0],
            &modelDeployment_B.DataTypeConversion1[0],
            &modelDeployment_B.DataTypeConversion5[0],
            &modelDeployment_B.MCData[0], &modelDeployment_B.Fu_f[0],
            &modelDeployment_B.e_h[0], &modelDeployment_B.sigma_f[0],
            &modelDeployment_B.kt_bq[0],
            &(modelDeployment_DW.Model_InstanceData_ju.rtb),
            &(modelDeployment_DW.Model_InstanceData_ju.rtdw));
      for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i
           ++) {
        // Merge generated from: '<S8>/Merge' incorporates:
        //   ModelReference generated from: '<S9>/Model'
        //   SignalConversion generated from: '<S9>/Model'

        modelDeployment_B.e_dot[modelDeployment_B.i] =
          modelDeployment_B.e_dot_l[modelDeployment_B.i];

        // Merge generated from: '<S8>/Merge' incorporates:
        //   ModelReference generated from: '<S9>/Model'
        //   SignalConversion generated from: '<S9>/Model'

        modelDeployment_B.kt_b[modelDeployment_B.i] =
          modelDeployment_B.kt_bq[modelDeployment_B.i];
      }

      // Merge generated from: '<S8>/Merge' incorporates:
      //   ModelReference generated from: '<S9>/Model'
      //   SignalConversion generated from: '<S9>/Model'

      modelDeployment_B.qe_p[0] = modelDeployment_B.qe_f[0];
      modelDeployment_B.qe_p[1] = modelDeployment_B.qe_f[1];
      modelDeployment_B.qe_p[2] = modelDeployment_B.qe_f[2];
      modelDeployment_B.qe_p[3] = modelDeployment_B.qe_f[3];

      // End of Outputs for SubSystem: '<S8>/ASGSMController'
      break;

     case 2:
      // Outputs for IfAction SubSystem: '<S8>/QuaternionASGSM' incorporates:
      //   ActionPort: '<S17>/Action Port'

      // Merge generated from: '<S8>/Merge' incorporates:
      //   ModelReference generated from: '<S17>/Model'

      asgsm_quaternion(&modelDeployment_B.Merge[0], &modelDeployment_B.Merge[6],
                       &modelDeployment_B.Merge[18], &modelDeployment_B.pos_hat
                       [0], &modelDeployment_B.pos_dot_hat[0],
                       &modelDeployment_B.pos_ddot_hat[0],
                       &modelDeployment_B.q_hat[0],
                       &modelDeployment_B.DataTypeConversion3[0],
                       &modelDeployment_B.DataTypeConversion6[0],
                       &modelDeployment_B.DataTypeConversion4[0],
                       &modelDeployment_B.DataTypeConversion2[0],
                       &modelDeployment_B.DataTypeConversion[0],
                       &modelDeployment_B.DataTypeConversion1[0],
                       &modelDeployment_B.MCData[0], &modelDeployment_B.Fu_f[0],
                       &modelDeployment_B.e_h[0], &modelDeployment_B.e_dot[0],
                       &modelDeployment_B.sigma_f[0], &modelDeployment_B.kt_b[0],
                       &modelDeployment_B.qe_p[0],
                       &(modelDeployment_DW.Model_InstanceData_h.rtb),
                       &(modelDeployment_DW.Model_InstanceData_h.rtdw));

      // End of Outputs for SubSystem: '<S8>/QuaternionASGSM'
      break;

     case 3:
      // Outputs for IfAction SubSystem: '<S8>/ASGSMControllerObs' incorporates:
      //   ActionPort: '<S10>/Action Port'

      // Merge generated from: '<S8>/Merge' incorporates:
      //   ModelReference generated from: '<S10>/Model'

      asgsm_obs(&modelDeployment_B.Merge[0], &modelDeployment_B.Merge[6],
                &modelDeployment_B.pos_hat[0], &modelDeployment_B.pos_dot_hat[0],
                &modelDeployment_B.pos_ddot_hat[0],
                &modelDeployment_B.DataTypeConversion3[0],
                &modelDeployment_B.DataTypeConversion6[0],
                &modelDeployment_B.DataTypeConversion4[0],
                &modelDeployment_B.DataTypeConversion2[0],
                &modelDeployment_B.DataTypeConversion[0],
                &modelDeployment_B.DataTypeConversion1[0],
                &modelDeployment_B.DataTypeConversion5[0],
                &modelDeployment_B.MCData[0], &modelDeployment_B.Fu_f[0],
                &modelDeployment_B.e_h[0], &modelDeployment_B.sigma_f[0],
                &modelDeployment_B.kt_e[0],
                &(modelDeployment_DW.Model_InstanceData_jg.rtb),
                &(modelDeployment_DW.Model_InstanceData_jg.rtdw));
      for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i
           ++) {
        // Merge generated from: '<S8>/Merge' incorporates:
        //   ModelReference generated from: '<S10>/Model'
        //   SignalConversion generated from: '<S10>/Model'

        modelDeployment_B.e_dot[modelDeployment_B.i] =
          modelDeployment_B.e_dot_g[modelDeployment_B.i];

        // Merge generated from: '<S8>/Merge' incorporates:
        //   ModelReference generated from: '<S10>/Model'
        //   SignalConversion generated from: '<S10>/Model'

        modelDeployment_B.kt_b[modelDeployment_B.i] =
          modelDeployment_B.kt_e[modelDeployment_B.i];
      }

      // Merge generated from: '<S8>/Merge' incorporates:
      //   ModelReference generated from: '<S10>/Model'
      //   SignalConversion generated from: '<S10>/Model'

      modelDeployment_B.qe_p[0] = modelDeployment_B.qe_e[0];
      modelDeployment_B.qe_p[1] = modelDeployment_B.qe_e[1];
      modelDeployment_B.qe_p[2] = modelDeployment_B.qe_e[2];
      modelDeployment_B.qe_p[3] = modelDeployment_B.qe_e[3];

      // End of Outputs for SubSystem: '<S8>/ASGSMControllerObs'
      break;

     case 4:
      // Outputs for IfAction SubSystem: '<S8>/QuaternionASGSMObs' incorporates:
      //   ActionPort: '<S18>/Action Port'

      // Merge generated from: '<S8>/Merge' incorporates:
      //   ModelReference generated from: '<S18>/Model'

      asgsm_quat_obs(&modelDeployment_B.Merge[0], &modelDeployment_B.Merge[6],
                     &modelDeployment_B.Merge[18], &modelDeployment_B.pos_hat[0],
                     &modelDeployment_B.pos_dot_hat[0],
                     &modelDeployment_B.pos_ddot_hat[0],
                     &modelDeployment_B.q_hat[0],
                     &modelDeployment_B.DataTypeConversion3[0],
                     &modelDeployment_B.DataTypeConversion6[0],
                     &modelDeployment_B.DataTypeConversion4[0],
                     &modelDeployment_B.DataTypeConversion2[0],
                     &modelDeployment_B.DataTypeConversion[0],
                     &modelDeployment_B.DataTypeConversion1[0],
                     &modelDeployment_B.MCData[0], &modelDeployment_B.Fu_f[0],
                     &modelDeployment_B.e_h[0], &modelDeployment_B.e_dot[0],
                     &modelDeployment_B.sigma_f[0], &modelDeployment_B.kt_b[0],
                     &modelDeployment_B.qe_p[0],
                     &(modelDeployment_DW.Model_InstanceData_g.rtb),
                     &(modelDeployment_DW.Model_InstanceData_g.rtdw));

      // End of Outputs for SubSystem: '<S8>/QuaternionASGSMObs'
      break;
    }

    // End of SwitchCase: '<S8>/Switch Case'

    // SignalConversion generated from: '<S8>/data_out_Outport_2'
    modelDeployment_B.quaternion_d[0] = modelDeployment_B.Merge[18];
    modelDeployment_B.quaternion_d[1] = modelDeployment_B.Merge[19];
    modelDeployment_B.quaternion_d[2] = modelDeployment_B.Merge[20];
    modelDeployment_B.quaternion_d[3] = modelDeployment_B.Merge[21];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Gain: '<S4>/Gain1'

    modelDeployment_B.pos[0] = modelDeployment_B.Gain1[0];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge: '<S38>/Merge'

    modelDeployment_B.att[0] = modelDeployment_B.Merge_b[0];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Gain: '<S4>/Gain1'

    modelDeployment_B.pos[1] = modelDeployment_B.Gain1[1];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge: '<S38>/Merge'

    modelDeployment_B.att[1] = modelDeployment_B.Merge_b[1];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Gain: '<S4>/Gain1'

    modelDeployment_B.pos[2] = modelDeployment_B.Gain1[2];

    // SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Merge: '<S38>/Merge'

    modelDeployment_B.att[2] = modelDeployment_B.Merge_b[2];
  }

  // End of Outputs for SubSystem: '<S1>/EnableController'

  // MATLAB Function: '<S2>/calculatePWM' incorporates:
  //   Constant: '<S2>/Constant'

  modelDeployment_B.Product3_g = rtP_coeff[0];
  modelDeployment_B.t_reset = rtP_coeff[1];
  modelDeployment_B.Product1_or = rtP_coeff[2];
  for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 6;
       modelDeployment_B.ParamStep_g++) {
    // Product: '<S11>/Matrix Multiply1'
    modelDeployment_B.Product2_p =
      modelDeployment_B.MatrixMultiply1[modelDeployment_B.ParamStep_g];

    // Saturate: '<S2>/Saturation' incorporates:
    //   Product: '<S11>/Matrix Multiply1'

    modelDeployment_B.Product2_p = (modelDeployment_B.Product2_p *
      modelDeployment_B.Product2_p * modelDeployment_B.Product3_g +
      modelDeployment_B.t_reset * modelDeployment_B.Product2_p) +
      modelDeployment_B.Product1_or;
    if (modelDeployment_B.Product2_p > modelDeployment_P.Saturation_UpperSat) {
      modelDeployment_B.Product2_p = modelDeployment_P.Saturation_UpperSat;
    } else if (modelDeployment_B.Product2_p <
               modelDeployment_P.Saturation_LowerSat) {
      modelDeployment_B.Product2_p = modelDeployment_P.Saturation_LowerSat;
    }

    modelDeployment_B.DataTypeConversion3[modelDeployment_B.ParamStep_g] =
      modelDeployment_B.Product2_p;

    // End of Saturate: '<S2>/Saturation'

    // MATLAB Function: '<S2>/NormPWM' incorporates:
    //   Saturate: '<S2>/Saturation'

    modelDeployment_B.Product2_p = (modelDeployment_B.Product2_p - 1000.0) /
      1000.0;

    // Saturate: '<S2>/Saturation1'
    if (modelDeployment_B.Product2_p > modelDeployment_P.Saturation1_UpperSat) {
      // DataTypeConversion: '<S2>/Data Type Conversion'
      modelDeployment_B.DataTypeConversion_b[modelDeployment_B.ParamStep_g] =
        static_cast<real32_T>(modelDeployment_P.Saturation1_UpperSat);
    } else if (modelDeployment_B.Product2_p <
               modelDeployment_P.Saturation1_LowerSat) {
      // DataTypeConversion: '<S2>/Data Type Conversion'
      modelDeployment_B.DataTypeConversion_b[modelDeployment_B.ParamStep_g] =
        static_cast<real32_T>(modelDeployment_P.Saturation1_LowerSat);
    } else {
      // DataTypeConversion: '<S2>/Data Type Conversion'
      modelDeployment_B.DataTypeConversion_b[modelDeployment_B.ParamStep_g] =
        static_cast<real32_T>(modelDeployment_B.Product2_p);
    }

    // End of Saturate: '<S2>/Saturation1'
  }

  // End of MATLAB Function: '<S2>/calculatePWM'

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 12;
       modelDeployment_B.ParamStep_g++) {
    modelDeployment_B.motorValues[modelDeployment_B.ParamStep_g] = (rtNaNF);
  }

  for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 8;
       modelDeployment_B.ParamStep_g++) {
    modelDeployment_B.servoValues[modelDeployment_B.ParamStep_g] = (rtNaNF);
  }

  modelDeployment_B.motorValues[0] = modelDeployment_B.DataTypeConversion_b[0];
  modelDeployment_B.motorValues[1] = modelDeployment_B.DataTypeConversion_b[1];
  modelDeployment_B.motorValues[2] = modelDeployment_B.DataTypeConversion_b[2];
  modelDeployment_B.motorValues[3] = modelDeployment_B.DataTypeConversion_b[3];
  modelDeployment_B.motorValues[4] = modelDeployment_B.DataTypeConversion_b[4];
  modelDeployment_B.motorValues[5] = modelDeployment_B.DataTypeConversion_b[5];
  MW_actuators_set(modelDeployment_B.DataTypeConversion_h,
                   &modelDeployment_B.motorValues[0],
                   &modelDeployment_B.servoValues[0]);

  // End of MATLABSystem: '<Root>/PX4 Actuator Write'
  for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i++)
  {
    // DataTypeConversion: '<S7>/Data Type Conversion5' incorporates:
    //   Saturate: '<S2>/Saturation'

    modelDeployment_B.DataTypeConversion_b[modelDeployment_B.i] =
      static_cast<real32_T>
      (modelDeployment_B.DataTypeConversion3[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion_k[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.Fu_d[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion1_m[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.pos_hat_c[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion11' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion11[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.pos_ddot_hat_f[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion3' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion3_f[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.pos_dot_hat_i[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion4' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion4_f[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.e[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion6' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion6_n[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.qd[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion7' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion7[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.sigma[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion8' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion8[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.kt[modelDeployment_B.i]);

    // DataTypeConversion: '<S7>/Data Type Conversion9' incorporates:
    //   SignalConversion generated from: '<S8>/data_out_Outport_2'

    modelDeployment_B.DataTypeConversion9[modelDeployment_B.i] =
      static_cast<real32_T>(modelDeployment_B.e_hat_l[modelDeployment_B.i]);
  }

  // MATLABSystem: '<S7>/PX4 Timestamp'
  modelDeployment_B.rtb_PX4Timestamp_a = hrt_absolute_time();

  // BusAssignment: '<S7>/Bus Assignment9' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment9.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment9.ehatx =
    modelDeployment_B.DataTypeConversion9[0];
  modelDeployment_B.BusAssignment9.ehaty =
    modelDeployment_B.DataTypeConversion9[1];
  modelDeployment_B.BusAssignment9.ehatz =
    modelDeployment_B.DataTypeConversion9[2];
  modelDeployment_B.BusAssignment9.ehatroll =
    modelDeployment_B.DataTypeConversion9[3];
  modelDeployment_B.BusAssignment9.ehatpitch =
    modelDeployment_B.DataTypeConversion9[4];
  modelDeployment_B.BusAssignment9.ehatyaw =
    modelDeployment_B.DataTypeConversion9[5];

  // MATLABSystem: '<S146>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment9'

  uORB_write_step(modelDeployment_DW.obj_jmm.orbMetadataObj,
                  &modelDeployment_DW.obj_jmm.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment9);

  // BusAssignment: '<S7>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment.fx = modelDeployment_B.DataTypeConversion_k[0];
  modelDeployment_B.BusAssignment.fy = modelDeployment_B.DataTypeConversion_k[1];
  modelDeployment_B.BusAssignment.fz = modelDeployment_B.DataTypeConversion_k[2];
  modelDeployment_B.BusAssignment.tau_x =
    modelDeployment_B.DataTypeConversion_k[3];
  modelDeployment_B.BusAssignment.tau_y =
    modelDeployment_B.DataTypeConversion_k[4];
  modelDeployment_B.BusAssignment.tau_z =
    modelDeployment_B.DataTypeConversion_k[5];

  // MATLABSystem: '<S135>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment'

  uORB_write_step(modelDeployment_DW.obj_ib.orbMetadataObj,
                  &modelDeployment_DW.obj_ib.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment);

  // BusAssignment: '<S7>/Bus Assignment1' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment1.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment1.xhat =
    modelDeployment_B.DataTypeConversion1_m[0];
  modelDeployment_B.BusAssignment1.yhat =
    modelDeployment_B.DataTypeConversion1_m[1];
  modelDeployment_B.BusAssignment1.zhat =
    modelDeployment_B.DataTypeConversion1_m[2];
  modelDeployment_B.BusAssignment1.phihat =
    modelDeployment_B.DataTypeConversion1_m[3];
  modelDeployment_B.BusAssignment1.thetahat =
    modelDeployment_B.DataTypeConversion1_m[4];
  modelDeployment_B.BusAssignment1.psihat =
    modelDeployment_B.DataTypeConversion1_m[5];

  // MATLABSystem: '<S136>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment1'

  uORB_write_step(modelDeployment_DW.obj_ff4.orbMetadataObj,
                  &modelDeployment_DW.obj_ff4.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment1);

  // BusAssignment: '<S7>/Bus Assignment11' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment11.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment11.gamma3_x =
    modelDeployment_B.DataTypeConversion11[0];
  modelDeployment_B.BusAssignment11.gamma3_y =
    modelDeployment_B.DataTypeConversion11[1];
  modelDeployment_B.BusAssignment11.gamma3_z =
    modelDeployment_B.DataTypeConversion11[2];
  modelDeployment_B.BusAssignment11.gamma3_phi =
    modelDeployment_B.DataTypeConversion11[3];
  modelDeployment_B.BusAssignment11.gamma3_theta =
    modelDeployment_B.DataTypeConversion11[4];
  modelDeployment_B.BusAssignment11.gamma3_psi =
    modelDeployment_B.DataTypeConversion11[5];

  // MATLABSystem: '<S138>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment11'

  uORB_write_step(modelDeployment_DW.obj_ht.orbMetadataObj,
                  &modelDeployment_DW.obj_ht.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment11);

  // BusAssignment: '<S7>/Bus Assignment2' incorporates:
  //   DataTypeConversion: '<S7>/Data Type Conversion2'
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment2.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment2.x = static_cast<real32_T>
    (modelDeployment_B.pos[0]);
  modelDeployment_B.BusAssignment2.y = static_cast<real32_T>
    (modelDeployment_B.pos[1]);
  modelDeployment_B.BusAssignment2.z = static_cast<real32_T>
    (modelDeployment_B.pos[2]);
  modelDeployment_B.BusAssignment2.phi = static_cast<real32_T>
    (modelDeployment_B.att[0]);
  modelDeployment_B.BusAssignment2.theta = static_cast<real32_T>
    (modelDeployment_B.att[1]);
  modelDeployment_B.BusAssignment2.psi = static_cast<real32_T>
    (modelDeployment_B.att[2]);

  // MATLABSystem: '<S139>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment2'

  uORB_write_step(modelDeployment_DW.obj_md.orbMetadataObj,
                  &modelDeployment_DW.obj_md.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment2);

  // BusAssignment: '<S7>/Bus Assignment3' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment3.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment3.xhatdot =
    modelDeployment_B.DataTypeConversion3_f[0];
  modelDeployment_B.BusAssignment3.yhatdot =
    modelDeployment_B.DataTypeConversion3_f[1];
  modelDeployment_B.BusAssignment3.zhatdot =
    modelDeployment_B.DataTypeConversion3_f[2];
  modelDeployment_B.BusAssignment3.phihatdot =
    modelDeployment_B.DataTypeConversion3_f[3];
  modelDeployment_B.BusAssignment3.thetahatdot =
    modelDeployment_B.DataTypeConversion3_f[4];
  modelDeployment_B.BusAssignment3.psihatdot =
    modelDeployment_B.DataTypeConversion3_f[5];

  // MATLABSystem: '<S140>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment3'

  uORB_write_step(modelDeployment_DW.obj_pj.orbMetadataObj,
                  &modelDeployment_DW.obj_pj.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment3);

  // BusAssignment: '<S7>/Bus Assignment4' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment4.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment4.ex = modelDeployment_B.DataTypeConversion4_f
    [0];
  modelDeployment_B.BusAssignment4.ey = modelDeployment_B.DataTypeConversion4_f
    [1];
  modelDeployment_B.BusAssignment4.ez = modelDeployment_B.DataTypeConversion4_f
    [2];
  modelDeployment_B.BusAssignment4.ephi =
    modelDeployment_B.DataTypeConversion4_f[3];
  modelDeployment_B.BusAssignment4.etheta =
    modelDeployment_B.DataTypeConversion4_f[4];
  modelDeployment_B.BusAssignment4.epsi =
    modelDeployment_B.DataTypeConversion4_f[5];

  // MATLABSystem: '<S141>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment4'

  uORB_write_step(modelDeployment_DW.obj_myb.orbMetadataObj,
                  &modelDeployment_DW.obj_myb.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment4);

  // BusAssignment: '<S7>/Bus Assignment6' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment6.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment6.xd = modelDeployment_B.DataTypeConversion6_n
    [0];
  modelDeployment_B.BusAssignment6.yd = modelDeployment_B.DataTypeConversion6_n
    [1];
  modelDeployment_B.BusAssignment6.zd = modelDeployment_B.DataTypeConversion6_n
    [2];
  modelDeployment_B.BusAssignment6.phid =
    modelDeployment_B.DataTypeConversion6_n[3];
  modelDeployment_B.BusAssignment6.thetad =
    modelDeployment_B.DataTypeConversion6_n[4];
  modelDeployment_B.BusAssignment6.psid =
    modelDeployment_B.DataTypeConversion6_n[5];

  // MATLABSystem: '<S143>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment6'

  uORB_write_step(modelDeployment_DW.obj_p4.orbMetadataObj,
                  &modelDeployment_DW.obj_p4.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment6);

  // BusAssignment: '<S7>/Bus Assignment7' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment7.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment7.sigmax =
    modelDeployment_B.DataTypeConversion7[0];
  modelDeployment_B.BusAssignment7.sigmay =
    modelDeployment_B.DataTypeConversion7[1];
  modelDeployment_B.BusAssignment7.sigmaz =
    modelDeployment_B.DataTypeConversion7[2];
  modelDeployment_B.BusAssignment7.sigmaroll =
    modelDeployment_B.DataTypeConversion7[3];
  modelDeployment_B.BusAssignment7.sigmapitch =
    modelDeployment_B.DataTypeConversion7[4];
  modelDeployment_B.BusAssignment7.sigmayaw =
    modelDeployment_B.DataTypeConversion7[5];

  // MATLABSystem: '<S144>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment7'

  uORB_write_step(modelDeployment_DW.obj_cjd.orbMetadataObj,
                  &modelDeployment_DW.obj_cjd.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment7);

  // BusAssignment: '<S7>/Bus Assignment8' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment8.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment8.ktx = modelDeployment_B.DataTypeConversion8[0];
  modelDeployment_B.BusAssignment8.kty = modelDeployment_B.DataTypeConversion8[1];
  modelDeployment_B.BusAssignment8.ktz = modelDeployment_B.DataTypeConversion8[2];
  modelDeployment_B.BusAssignment8.ktroll =
    modelDeployment_B.DataTypeConversion8[3];
  modelDeployment_B.BusAssignment8.ktpitch =
    modelDeployment_B.DataTypeConversion8[4];
  modelDeployment_B.BusAssignment8.ktyaw =
    modelDeployment_B.DataTypeConversion8[5];

  // MATLABSystem: '<S145>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment8'

  uORB_write_step(modelDeployment_DW.obj_o5o.orbMetadataObj,
                  &modelDeployment_DW.obj_o5o.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment8);

  // BusAssignment: '<S7>/Bus Assignment5' incorporates:
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment5.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment5.pwm1 =
    modelDeployment_B.DataTypeConversion_b[0];
  modelDeployment_B.BusAssignment5.pwm2 =
    modelDeployment_B.DataTypeConversion_b[1];
  modelDeployment_B.BusAssignment5.pwm3 =
    modelDeployment_B.DataTypeConversion_b[2];
  modelDeployment_B.BusAssignment5.pwm4 =
    modelDeployment_B.DataTypeConversion_b[3];
  modelDeployment_B.BusAssignment5.pwm5 =
    modelDeployment_B.DataTypeConversion_b[4];
  modelDeployment_B.BusAssignment5.pwm6 =
    modelDeployment_B.DataTypeConversion_b[5];

  // MATLABSystem: '<S142>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment5'

  uORB_write_step(modelDeployment_DW.obj_ida.orbMetadataObj,
                  &modelDeployment_DW.obj_ida.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment5);

  // BusAssignment: '<S7>/Bus Assignment10' incorporates:
  //   DataTypeConversion: '<S7>/Data Type Conversion10'
  //   MATLABSystem: '<S7>/PX4 Timestamp'

  modelDeployment_B.BusAssignment10.timestamp =
    modelDeployment_B.rtb_PX4Timestamp_a;
  modelDeployment_B.BusAssignment10.q0d = static_cast<real32_T>
    (modelDeployment_B.quaternion_d[0]);
  modelDeployment_B.BusAssignment10.q1d = static_cast<real32_T>
    (modelDeployment_B.quaternion_d[1]);
  modelDeployment_B.BusAssignment10.q2d = static_cast<real32_T>
    (modelDeployment_B.quaternion_d[2]);
  modelDeployment_B.BusAssignment10.q3d = static_cast<real32_T>
    (modelDeployment_B.quaternion_d[3]);
  modelDeployment_B.BusAssignment10.q0hat = static_cast<real32_T>
    (modelDeployment_B.q_hat_p[0]);
  modelDeployment_B.BusAssignment10.q1hat = static_cast<real32_T>
    (modelDeployment_B.q_hat_p[1]);
  modelDeployment_B.BusAssignment10.q2hat = static_cast<real32_T>
    (modelDeployment_B.q_hat_p[2]);
  modelDeployment_B.BusAssignment10.q3hat = static_cast<real32_T>
    (modelDeployment_B.q_hat_p[3]);
  modelDeployment_B.BusAssignment10.q0e = static_cast<real32_T>
    (modelDeployment_B.qe[0]);
  modelDeployment_B.BusAssignment10.q1e = static_cast<real32_T>
    (modelDeployment_B.qe[1]);
  modelDeployment_B.BusAssignment10.q2e = static_cast<real32_T>
    (modelDeployment_B.qe[2]);
  modelDeployment_B.BusAssignment10.q3e = static_cast<real32_T>
    (modelDeployment_B.qe[3]);
  modelDeployment_B.BusAssignment10.q0ehat = static_cast<real32_T>
    (modelDeployment_B.q_tilde_k[0]);
  modelDeployment_B.BusAssignment10.q1ehat = static_cast<real32_T>
    (modelDeployment_B.q_tilde_k[1]);
  modelDeployment_B.BusAssignment10.q2ehat = static_cast<real32_T>
    (modelDeployment_B.q_tilde_k[2]);
  modelDeployment_B.BusAssignment10.q3ehat = static_cast<real32_T>
    (modelDeployment_B.q_tilde_k[3]);

  // MATLABSystem: '<S137>/SinkBlock' incorporates:
  //   BusAssignment: '<S7>/Bus Assignment10'

  uORB_write_step(modelDeployment_DW.obj_ii.orbMetadataObj,
                  &modelDeployment_DW.obj_ii.orbAdvertiseObj,
                  &modelDeployment_B.BusAssignment10);

  // If: '<S43>/If1' incorporates:
  //   Constant: '<S43>/Constant'

  if (modelDeployment_P.DirectionCosineMatrixtoRotati_l > 1) {
    // Outputs for IfAction SubSystem: '<S43>/If Warning//Error' incorporates:
    //   ActionPort: '<S52>/if'

    // Bias: '<S56>/Bias1' incorporates:
    //   Concatenate: '<S76>/Vector Concatenate'
    //   Math: '<S56>/Math Function'
    //   Product: '<S56>/Product'

    for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 3;
         modelDeployment_B.ParamStep_g++) {
      for (modelDeployment_B.i = 0; modelDeployment_B.i < 3; modelDeployment_B.i
           ++) {
        modelDeployment_B.b_i = 3 * modelDeployment_B.i +
          modelDeployment_B.ParamStep_g;
        modelDeployment_B.posGains[modelDeployment_B.b_i] =
          ((modelDeployment_B.VectorConcatenate[3 *
            modelDeployment_B.ParamStep_g + 1] *
            modelDeployment_B.VectorConcatenate[3 * modelDeployment_B.i + 1] +
            modelDeployment_B.VectorConcatenate[3 *
            modelDeployment_B.ParamStep_g] *
            modelDeployment_B.VectorConcatenate[3 * modelDeployment_B.i]) +
           modelDeployment_B.VectorConcatenate[3 * modelDeployment_B.ParamStep_g
           + 2] * modelDeployment_B.VectorConcatenate[3 * modelDeployment_B.i +
           2]) + modelDeployment_P.Bias1_Bias[modelDeployment_B.b_i];
      }
    }

    // End of Bias: '<S56>/Bias1'

    // RelationalOperator: '<S64>/Compare' incorporates:
    //   Abs: '<S56>/Abs2'
    //   Constant: '<S64>/Constant'

    for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 9;
         modelDeployment_B.ParamStep_g++) {
      modelDeployment_B.Compare[modelDeployment_B.ParamStep_g] = (fabs
        (modelDeployment_B.posGains[modelDeployment_B.ParamStep_g]) >
        modelDeployment_P.DirectionCosineMatrixtoRotation);
    }

    // End of RelationalOperator: '<S64>/Compare'

    // Logic: '<S56>/Logical Operator1' incorporates:
    //   RelationalOperator: '<S64>/Compare'

    modelDeployment_B.NOT = modelDeployment_B.Compare[0];
    for (modelDeployment_B.ParamStep_g = 0; modelDeployment_B.ParamStep_g < 8;
         modelDeployment_B.ParamStep_g++) {
      modelDeployment_B.NOT = (modelDeployment_B.NOT ||
        modelDeployment_B.Compare[modelDeployment_B.ParamStep_g + 1]);
    }

    // If: '<S52>/If' incorporates:
    //   Abs: '<S57>/Abs1'
    //   Bias: '<S57>/Bias'
    //   Constant: '<S66>/Constant'
    //   Logic: '<S56>/Logical Operator1'
    //   Product: '<S65>/Product'
    //   Product: '<S65>/Product1'
    //   Product: '<S65>/Product2'
    //   Product: '<S65>/Product3'
    //   Product: '<S65>/Product4'
    //   Product: '<S65>/Product5'
    //   RelationalOperator: '<S66>/Compare'
    //   Sum: '<S65>/Sum'

    if (fabs((((((modelDeployment_B.VectorConcatenate[0] *
                  modelDeployment_B.VectorConcatenate[4] *
                  modelDeployment_B.VectorConcatenate[8] -
                  modelDeployment_B.VectorConcatenate[0] *
                  modelDeployment_B.VectorConcatenate[5] *
                  modelDeployment_B.VectorConcatenate[7]) -
                 modelDeployment_B.VectorConcatenate[1] *
                 modelDeployment_B.VectorConcatenate[3] *
                 modelDeployment_B.VectorConcatenate[8]) +
                modelDeployment_B.VectorConcatenate[2] *
                modelDeployment_B.VectorConcatenate[3] *
                modelDeployment_B.VectorConcatenate[7]) +
               modelDeployment_B.VectorConcatenate[1] *
               modelDeployment_B.VectorConcatenate[5] *
               modelDeployment_B.VectorConcatenate[6]) -
              modelDeployment_B.VectorConcatenate[2] *
              modelDeployment_B.VectorConcatenate[4] *
              modelDeployment_B.VectorConcatenate[6]) +
             modelDeployment_P.Bias_Bias) >
        modelDeployment_P.DirectionCosineMatrixtoRotation) {
      // Outputs for IfAction SubSystem: '<S52>/If Not Proper' incorporates:
      //   ActionPort: '<S55>/Action Port'

      // If: '<S55>/If' incorporates:
      //   Constant: '<S55>/Constant'

      if (modelDeployment_P.DirectionCosineMatrixtoRotati_l == 2) {
        // Outputs for IfAction SubSystem: '<S55>/Warning' incorporates:
        //   ActionPort: '<S63>/Action Port'

        // Assertion: '<S63>/Assertion' incorporates:
        //   Constant: '<S55>/Constant1'

        utAssert(modelDeployment_P.Constant1_Value != 0.0);

        // End of Outputs for SubSystem: '<S55>/Warning'
      } else if (modelDeployment_P.DirectionCosineMatrixtoRotati_l == 3) {
        // Outputs for IfAction SubSystem: '<S55>/Error' incorporates:
        //   ActionPort: '<S61>/Action Port'

        // Assertion: '<S61>/Assertion' incorporates:
        //   Constant: '<S55>/Constant1'

        utAssert(modelDeployment_P.Constant1_Value != 0.0);

        // End of Outputs for SubSystem: '<S55>/Error'
      }

      // End of If: '<S55>/If'
      // End of Outputs for SubSystem: '<S52>/If Not Proper'
    } else if (modelDeployment_B.NOT) {
      // Outputs for IfAction SubSystem: '<S52>/Else If Not Orthogonal' incorporates:
      //   ActionPort: '<S53>/Action Port'

      // If: '<S53>/If' incorporates:
      //   Constant: '<S53>/Constant'

      if (modelDeployment_P.DirectionCosineMatrixtoRotati_l == 2) {
        // Outputs for IfAction SubSystem: '<S53>/Warning' incorporates:
        //   ActionPort: '<S60>/Action Port'

        // Assertion: '<S60>/Assertion' incorporates:
        //   Constant: '<S53>/Constant1'

        utAssert(modelDeployment_P.Constant1_Value_e != 0.0);

        // End of Outputs for SubSystem: '<S53>/Warning'
      } else if (modelDeployment_P.DirectionCosineMatrixtoRotati_l == 3) {
        // Outputs for IfAction SubSystem: '<S53>/Error' incorporates:
        //   ActionPort: '<S58>/Action Port'

        // Assertion: '<S58>/Assertion' incorporates:
        //   Constant: '<S53>/Constant1'

        utAssert(modelDeployment_P.Constant1_Value_e != 0.0);

        // End of Outputs for SubSystem: '<S53>/Error'
      }

      // End of If: '<S53>/If'
      // End of Outputs for SubSystem: '<S52>/Else If Not Orthogonal'
    }

    // End of If: '<S52>/If'
    // End of Outputs for SubSystem: '<S43>/If Warning//Error'
  }

  // End of If: '<S43>/If1'

  // MATLABSystem: '<S85>/Read Parameter'
  MW_Param_Step(modelDeployment_DW.obj_mw.MW_PARAMHANDLE, MW_SINGLE,
                &modelDeployment_B.ParamStep);

  // MATLABSystem: '<S85>/Read Parameter1'
  MW_Param_Step(modelDeployment_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
                &modelDeployment_B.ParamStep);

  // MATLABSystem: '<S85>/Read Parameter2'
  MW_Param_Step(modelDeployment_DW.obj_p.MW_PARAMHANDLE, MW_SINGLE,
                &modelDeployment_B.ParamStep);

  // MATLABSystem: '<S85>/Read Parameter3'
  MW_Param_Step(modelDeployment_DW.obj_l.MW_PARAMHANDLE, MW_SINGLE,
                &modelDeployment_B.ParamStep);

  // MATLABSystem: '<S85>/Read Parameter4'
  MW_Param_Step(modelDeployment_DW.obj_d5.MW_PARAMHANDLE, MW_SINGLE,
                &modelDeployment_B.ParamStep);

  // MATLABSystem: '<S85>/Read Parameter5'
  MW_Param_Step(modelDeployment_DW.obj_eu.MW_PARAMHANDLE, MW_SINGLE,
                &modelDeployment_B.ParamStep);

  // MATLABSystem: '<S22>/SourceBlock'
  uORB_read_step(modelDeployment_DW.obj_e.orbMetadataObj,
                 &modelDeployment_DW.obj_e.eventStructObj, &modelDeployment_B.r1,
                 false, 1.0);

  // Update for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S87>/Enable'

  if (modelDeployment_B.RelationalOperator) {
    // Update for Memory: '<S87>/Memory'
    modelDeployment_DW.Memory_PreviousInput_d = modelDeployment_B.t;
  }

  // End of Update for SubSystem: '<S6>/Enabled Subsystem'

  // Update for Enabled SubSystem: '<S1>/EnableController' incorporates:
  //   EnablePort: '<S8>/arm'

  if (modelDeployment_B.DataTypeConversion_h) {
    // Update for UnitDelay generated from: '<S8>/Unit Delay' incorporates:
    //   Merge generated from: '<S8>/Merge'

    modelDeployment_DW.UnitDelay_6_DSTATE[0] = modelDeployment_B.qe_p[0];
    modelDeployment_DW.UnitDelay_6_DSTATE[1] = modelDeployment_B.qe_p[1];
    modelDeployment_DW.UnitDelay_6_DSTATE[2] = modelDeployment_B.qe_p[2];
    modelDeployment_DW.UnitDelay_6_DSTATE[3] = modelDeployment_B.qe_p[3];

    // Update for UnitDelay generated from: '<S8>/Unit Delay' incorporates:
    //   Merge generated from: '<S8>/Merge'

    for (modelDeployment_B.i = 0; modelDeployment_B.i < 6; modelDeployment_B.i++)
    {
      modelDeployment_DW.UnitDelay_2_DSTATE[modelDeployment_B.i] =
        modelDeployment_B.e_h[modelDeployment_B.i];
      modelDeployment_DW.UnitDelay_4_DSTATE[modelDeployment_B.i] =
        modelDeployment_B.sigma_f[modelDeployment_B.i];
      modelDeployment_DW.UnitDelay_5_DSTATE[modelDeployment_B.i] =
        modelDeployment_B.kt_b[modelDeployment_B.i];
      modelDeployment_DW.UnitDelay_1_DSTATE[modelDeployment_B.i] =
        modelDeployment_B.Fu_f[modelDeployment_B.i];
    }
  }

  // End of Update for SubSystem: '<S1>/EnableController'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.004, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  modelDeployment_M->Timing.clockTick0++;
}

// Model initialize function
void modelDeployment_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Model Initialize function for ModelReference Block: '<S9>/Model'
  asgsm_initialize(modelDeployment_M->getErrorStatusPointer(),
                   &(modelDeployment_DW.Model_InstanceData_ju.rtm));

  // Model Initialize function for ModelReference Block: '<S10>/Model'
  asgsm_obs_initialize(modelDeployment_M->getErrorStatusPointer(),
                       &(modelDeployment_DW.Model_InstanceData_jg.rtm));

  // Model Initialize function for ModelReference Block: '<S12>/Model'
  FxTDiffSim_initialize(modelDeployment_M->getErrorStatusPointer(),
                        &(modelDeployment_DW.Model_InstanceData_j.rtm));

  // Model Initialize function for ModelReference Block: '<S13>/Model'
  FxTESO_initialize(modelDeployment_M->getErrorStatusPointer(),
                    &(modelDeployment_DW.Model_InstanceData_o.rtm));

  // Model Initialize function for ModelReference Block: '<S14>/FxTDQuat'
  FxtD_Quaternion_initialize(modelDeployment_M->getErrorStatusPointer(),
    &(modelDeployment_DW.FxTDQuat_InstanceData.rtm));

  // Model Initialize function for ModelReference Block: '<S15>/Model'
  FxTESO_Quaternion_initialize(modelDeployment_M->getErrorStatusPointer(),
    &(modelDeployment_DW.Model_InstanceData.rtm));

  // Model Initialize function for ModelReference Block: '<S16>/Model'
  pdGc_initialize(modelDeployment_M->getErrorStatusPointer(),
                  &(modelDeployment_DW.Model_InstanceData_d.rtm));

  // Model Initialize function for ModelReference Block: '<S17>/Model'
  asgsm_quaternion_initialize(modelDeployment_M->getErrorStatusPointer(),
    &(modelDeployment_DW.Model_InstanceData_h.rtm));

  // Model Initialize function for ModelReference Block: '<S18>/Model'
  asgsm_quat_obs_initialize(modelDeployment_M->getErrorStatusPointer(),
    &(modelDeployment_DW.Model_InstanceData_g.rtm));

  {
    static const char_T ParameterNameStr[8] = "FAH_X_P";
    static const char_T ParameterNameStr_0[8] = "FAH_X_I";
    static const char_T ParameterNameStr_1[8] = "FAH_X_D";
    static const char_T ParameterNameStr_2[8] = "FAH_Y_P";
    static const char_T ParameterNameStr_3[8] = "FAH_Y_I";
    static const char_T ParameterNameStr_4[8] = "FAH_Y_D";
    static const char_T ParameterNameStr_5[8] = "FAH_Z_P";
    static const char_T ParameterNameStr_6[8] = "FAH_Z_I";
    static const char_T ParameterNameStr_7[8] = "FAH_Z_D";
    static const char_T ParameterNameStr_8[11] = "FAH_ROLL_P";
    static const char_T ParameterNameStr_9[11] = "FAH_ROLL_I";
    static const char_T ParameterNameStr_a[11] = "FAH_ROLL_D";
    static const char_T ParameterNameStr_b[12] = "FAH_PITCH_P";
    static const char_T ParameterNameStr_c[12] = "FAH_PITCH_I";
    static const char_T ParameterNameStr_d[12] = "FAH_PITCH_D";
    static const char_T ParameterNameStr_e[10] = "FAH_YAW_P";
    static const char_T ParameterNameStr_f[10] = "FAH_YAW_I";
    static const char_T ParameterNameStr_g[10] = "FAH_YAW_D";
    static const char_T ParameterNameStr_h[6] = "X_XI1";
    static const char_T ParameterNameStr_i[6] = "Y_XI1";
    static const char_T ParameterNameStr_j[6] = "Z_XI1";
    static const char_T ParameterNameStr_k[9] = "ROLL_XI1";
    static const char_T ParameterNameStr_l[10] = "PITCH_XI1";
    static const char_T ParameterNameStr_m[8] = "YAW_XI1";
    static const char_T ParameterNameStr_n[6] = "X_XI2";
    static const char_T ParameterNameStr_o[6] = "Y_XI2";
    static const char_T ParameterNameStr_p[6] = "Z_XI2";
    static const char_T ParameterNameStr_q[9] = "ROLL_XI2";
    static const char_T ParameterNameStr_r[10] = "PITCH_XI2";
    static const char_T ParameterNameStr_s[8] = "YAW_XI2";
    static const char_T ParameterNameStr_t[7] = "X_LAM1";
    static const char_T ParameterNameStr_u[7] = "Y_LAM1";
    static const char_T ParameterNameStr_v[7] = "Z_LAM1";
    static const char_T ParameterNameStr_w[10] = "ROLL_LAM1";
    static const char_T ParameterNameStr_x[11] = "PITCH_LAM1";
    static const char_T ParameterNameStr_y[9] = "YAW_LAM1";
    static const char_T ParameterNameStr_z[7] = "X_LAM2";
    static const char_T ParameterNameStr_10[7] = "Y_LAM2";
    static const char_T ParameterNameStr_11[7] = "Z_LAM2";
    static const char_T ParameterNameStr_12[10] = "ROLL_LAM2";
    static const char_T ParameterNameStr_13[11] = "PITCH_LAM2";
    static const char_T ParameterNameStr_14[9] = "YAW_LAM2";
    static const char_T ParameterNameStr_15[10] = "X_ALPHA_U";
    static const char_T ParameterNameStr_16[10] = "Y_ALPHA_U";
    static const char_T ParameterNameStr_17[10] = "Z_ALPHA_U";
    static const char_T ParameterNameStr_18[13] = "ROLL_ALPHA_U";
    static const char_T ParameterNameStr_19[14] = "PITCH_ALPHA_U";
    static const char_T ParameterNameStr_1a[12] = "YAW_ALPHA_U";
    static const char_T ParameterNameStr_1b[9] = "X_BETA_U";
    static const char_T ParameterNameStr_1c[9] = "Y_BETA_U";
    static const char_T ParameterNameStr_1d[9] = "Z_BETA_U";
    static const char_T ParameterNameStr_1e[12] = "ROLL_BETA_U";
    static const char_T ParameterNameStr_1f[13] = "PITCH_BETA_U";
    static const char_T ParameterNameStr_1g[11] = "YAW_BETA_U";
    static const char_T ParameterNameStr_1h[8] = "X_EST_U";
    static const char_T ParameterNameStr_1i[8] = "Y_EST_U";
    static const char_T ParameterNameStr_1j[8] = "Z_EST_U";
    static const char_T ParameterNameStr_1k[11] = "ROLL_EST_U";
    static const char_T ParameterNameStr_1l[12] = "PITCH_EST_U";
    static const char_T ParameterNameStr_1m[10] = "YAW_EST_U";
    static const char_T ParameterNameStr_1n[9] = "FAH_MASS";
    static const char_T ParameterNameStr_1o[9] = "FAH_I_XX";
    static const char_T ParameterNameStr_1p[9] = "FAH_I_YY";
    static const char_T ParameterNameStr_1q[5] = "X_G1";
    static const char_T ParameterNameStr_1r[5] = "Y_G1";
    static const char_T ParameterNameStr_1s[5] = "Z_G1";
    static const char_T ParameterNameStr_1t[8] = "ROLL_G1";
    static const char_T ParameterNameStr_1u[9] = "PITCH_G1";
    static const char_T ParameterNameStr_1v[7] = "YAW_G1";
    static const char_T ParameterNameStr_1w[5] = "X_G2";
    static const char_T ParameterNameStr_1x[5] = "Y_G2";
    static const char_T ParameterNameStr_1y[5] = "Z_G2";
    static const char_T ParameterNameStr_1z[8] = "ROLL_G2";
    static const char_T ParameterNameStr_20[9] = "PITCH_G2";
    static const char_T ParameterNameStr_21[7] = "YAW_G2";
    static const char_T ParameterNameStr_22[6] = "X_VPI";
    static const char_T ParameterNameStr_23[6] = "Y_VPI";
    static const char_T ParameterNameStr_24[6] = "Z_VPI";
    static const char_T ParameterNameStr_25[9] = "ROLL_VPI";
    static const char_T ParameterNameStr_26[10] = "PITCH_VPI";
    static const char_T ParameterNameStr_27[8] = "YAW_VPI";
    static const char_T ParameterNameStr_28[7] = "X_VRHO";
    static const char_T ParameterNameStr_29[7] = "Y_VRHO";
    static const char_T ParameterNameStr_2a[7] = "Z_VRHO";
    static const char_T ParameterNameStr_2b[10] = "ROLL_VRHO";
    static const char_T ParameterNameStr_2c[11] = "PITCH_VRHO";
    static const char_T ParameterNameStr_2d[9] = "YAW_VRHO";
    static const char_T ParameterNameStr_2e[6] = "X_MU1";
    static const char_T ParameterNameStr_2f[6] = "Y_MU1";
    static const char_T ParameterNameStr_2g[6] = "Z_MU1";
    static const char_T ParameterNameStr_2h[9] = "ROLL_MU1";
    static const char_T ParameterNameStr_2i[10] = "PITCH_MU1";
    static const char_T ParameterNameStr_2j[8] = "YAW_MU1";
    static const char_T ParameterNameStr_2k[6] = "X_MU2";
    static const char_T ParameterNameStr_2l[6] = "Y_MU2";
    static const char_T ParameterNameStr_2m[6] = "Z_MU2";
    static const char_T ParameterNameStr_2n[9] = "ROLL_MU2";
    static const char_T ParameterNameStr_2o[10] = "PITCH_MU2";
    static const char_T ParameterNameStr_2p[8] = "YAW_MU2";
    static const char_T ParameterNameStr_2q[6] = "X_MU3";
    static const char_T ParameterNameStr_2r[6] = "Y_MU3";
    static const char_T ParameterNameStr_2s[6] = "Z_MU3";
    static const char_T ParameterNameStr_2t[9] = "ROLL_MU3";
    static const char_T ParameterNameStr_2u[10] = "PITCH_MU3";
    static const char_T ParameterNameStr_2v[8] = "YAW_MU3";
    static const char_T ParameterNameStr_2w[6] = "X_MU4";
    static const char_T ParameterNameStr_2x[6] = "Y_MU4";
    static const char_T ParameterNameStr_2y[6] = "Z_MU4";
    static const char_T ParameterNameStr_2z[9] = "ROLL_MU4";
    static const char_T ParameterNameStr_30[10] = "PITCH_MU4";
    static const char_T ParameterNameStr_31[8] = "YAW_MU4";
    static const char_T ParameterNameStr_32[8] = "X_ALPHA";
    static const char_T ParameterNameStr_33[8] = "Y_ALPHA";
    static const char_T ParameterNameStr_34[8] = "Z_ALPHA";
    static const char_T ParameterNameStr_35[11] = "ROLL_ALPHA";
    static const char_T ParameterNameStr_36[12] = "PITCH_ALPHA";
    static const char_T ParameterNameStr_37[10] = "YAW_ALPHA";
    static const char_T ParameterNameStr_38[7] = "X_BETA";
    static const char_T ParameterNameStr_39[7] = "Y_BETA";
    static const char_T ParameterNameStr_3a[7] = "Z_BETA";
    static const char_T ParameterNameStr_3b[10] = "ROLL_BETA";
    static const char_T ParameterNameStr_3c[11] = "PITCH_BETA";
    static const char_T ParameterNameStr_3d[9] = "YAW_BETA";
    static const char_T ParameterNameStr_3e[9] = "TRAJ_SEL";
    static const char_T ParameterNameStr_3f[10] = "FAH_SOF_X";
    static const char_T ParameterNameStr_3g[10] = "FAH_SOF_Y";
    static const char_T ParameterNameStr_3h[10] = "FAH_SOF_Z";
    static const char_T ParameterNameStr_3i[13] = "FAH_SOF_ROLL";
    static const char_T ParameterNameStr_3j[14] = "FAH_SOF_PITCH";
    static const char_T ParameterNameStr_3k[12] = "FAH_SOF_YAW";
    static const char_T ParameterNameStr_3l[8] = "EST_SEL";
    static const char_T ParameterNameStr_3m[9] = "CTRL_SEL";
    int32_T i;

    // SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S36>/In1' incorporates:
    //   Outport: '<S36>/Out1'

    modelDeployment_B.In1_o = modelDeployment_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // InitializeConditions for Memory: '<S87>/Memory'
    modelDeployment_DW.Memory_PreviousInput_d =
      modelDeployment_P.Memory_InitialCondition;

    // SystemInitialize for Memory: '<S87>/Memory' incorporates:
    //   Outport: '<S87>/Out1'

    modelDeployment_B.Memory = modelDeployment_P.Out1_Y0_iz;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Subsystem'
    // SystemInitialize for IfAction SubSystem: '<S88>/If Action Subsystem4'
    // Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
    memset(&modelDeployment_DW.obj_f.AccelerationBoundaryCondition[0], 0, 10U *
           sizeof(real_T));
    for (i = 0; i < 5; i++) {
      modelDeployment_DW.obj_f.tunablePropertyChanged[i] = false;
    }

    memcpy(&modelDeployment_DW.obj_f.VelocityBoundaryCondition[0],
           &modelDeployment_P.PolynomialTrajectory2_VelocityB[0], 60U * sizeof
           (real_T));
    modelDeployment_DW.obj_f.isInitialized = 1;
    modelDepl_PolyTrajSys_setupImpl(&modelDeployment_DW.obj_f);
    modelDeployment_DW.obj_f.TunablePropsChanged = false;

    // End of Start for MATLABSystem: '<S93>/Polynomial Trajectory2'
    // End of SystemInitialize for SubSystem: '<S88>/If Action Subsystem4'

    // SystemInitialize for IfAction SubSystem: '<S88>/If Action Subsystem3'
    for (i = 0; i < 6; i++) {
      // InitializeConditions for Memory: '<S104>/Memory'
      modelDeployment_DW.Memory_PreviousInput_f[i] =
        modelDeployment_P.Memory_InitialCondition_n[i];

      // InitializeConditions for Memory: '<S104>/Memory1'
      modelDeployment_DW.Memory1_PreviousInput_h[i] =
        modelDeployment_P.Memory1_InitialCondition[i];

      // InitializeConditions for DiscreteIntegrator: '<S104>/Discrete-Time Integrator' 
      modelDeployment_DW.DiscreteTimeIntegrator_DSTATE_l[i] =
        modelDeployment_P.DiscreteTimeIntegrator_IC[i];

      // InitializeConditions for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' 
      modelDeployment_DW.DiscreteTimeIntegrator1_DSTAT_h[i] =
        modelDeployment_P.DiscreteTimeIntegrator1_IC[i];
    }

    // End of SystemInitialize for SubSystem: '<S88>/If Action Subsystem3'

    // SystemInitialize for IfAction SubSystem: '<S88>/If Action Subsystem2'
    // Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    for (i = 0; i < 5; i++) {
      modelDeployment_DW.obj.tunablePropertyChanged[i] = false;
    }

    memcpy(&modelDeployment_DW.obj.VelocityBoundaryCondition[0],
           &modelDeployment_P.PolynomialTrajectory3_VelocityB[0], 126U * sizeof
           (real_T));
    memcpy(&modelDeployment_DW.obj.AccelerationBoundaryCondition[0],
           &modelDeployment_P.PolynomialTrajectory3_Accelerat[0], 126U * sizeof
           (real_T));
    modelDeployment_DW.obj.isInitialized = 1;
    modelDe_PolyTrajSys_setupImpl_f(&modelDeployment_DW.obj);
    modelDeployment_DW.obj.TunablePropsChanged = false;

    // End of Start for MATLABSystem: '<S91>/Polynomial Trajectory3'
    // End of SystemInitialize for SubSystem: '<S88>/If Action Subsystem2'

    // SystemInitialize for IfAction SubSystem: '<S88>/If Action Subsystem1'
    // Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    memset(&modelDeployment_DW.obj_fs.AccelerationBoundaryCondition[0], 0, 10U *
           sizeof(real_T));
    for (i = 0; i < 5; i++) {
      modelDeployment_DW.obj_fs.tunablePropertyChanged[i] = false;
    }

    memcpy(&modelDeployment_DW.obj_fs.VelocityBoundaryCondition[0],
           &modelDeployment_P.PolynomialTrajectory_VelocityBo[0], 36U * sizeof
           (real_T));
    modelDeployment_DW.obj_fs.isInitialized = 1;
    modelD_PolyTrajSys_setupImpl_fj(&modelDeployment_DW.obj_fs);
    modelDeployment_DW.obj_fs.TunablePropsChanged = false;

    // End of Start for MATLABSystem: '<S90>/Polynomial Trajectory'
    // End of SystemInitialize for SubSystem: '<S88>/If Action Subsystem1'

    // SystemInitialize for IfAction SubSystem: '<S88>/If Action Subsystem'
    // Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
    memset(&modelDeployment_DW.obj_c.AccelerationBoundaryCondition[0], 0, 10U *
           sizeof(real_T));
    for (i = 0; i < 5; i++) {
      modelDeployment_DW.obj_c.tunablePropertyChanged[i] = false;
    }

    memcpy(&modelDeployment_DW.obj_c.VelocityBoundaryCondition[0],
           &modelDeployment_P.PolynomialTrajectory3_Velocit_e[0], 72U * sizeof
           (real_T));
    modelDeployment_DW.obj_c.isInitialized = 1;
    model_PolyTrajSys_setupImpl_fjc(&modelDeployment_DW.obj_c);
    modelDeployment_DW.obj_c.TunablePropsChanged = false;

    // End of Start for MATLABSystem: '<S89>/Polynomial Trajectory3'
    // End of SystemInitialize for SubSystem: '<S88>/If Action Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S88>/If Action Subsystem5'
    // InitializeConditions for S-Function (sdspunwrap2): '<S94>/Unwrap1'
    modelDeployment_DW.Unwrap1_FirstStep = true;
    for (i = 0; i < 6; i++) {
      // InitializeConditions for Memory: '<S117>/Memory'
      modelDeployment_DW.Memory_PreviousInput[i] =
        modelDeployment_P.Memory_InitialCondition_a[i];

      // InitializeConditions for Memory: '<S117>/Memory1'
      modelDeployment_DW.Memory1_PreviousInput[i] =
        modelDeployment_P.Memory1_InitialCondition_p[i];

      // InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' 
      modelDeployment_DW.DiscreteTimeIntegrator_DSTATE[i] =
        modelDeployment_P.DiscreteTimeIntegrator_IC_d[i];

      // InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator1' 
      modelDeployment_DW.DiscreteTimeIntegrator1_DSTATE[i] =
        modelDeployment_P.DiscreteTimeIntegrator1_IC_l[i];
    }

    // End of SystemInitialize for SubSystem: '<S88>/If Action Subsystem5'
    for (i = 0; i < 22; i++) {
      // SystemInitialize for Merge: '<S88>/Merge'
      modelDeployment_B.Merge[i] = modelDeployment_P.Merge_InitialOutput;
    }

    // End of SystemInitialize for SubSystem: '<S6>/Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S27>/In1' incorporates:
    //   Outport: '<S27>/Out1'

    modelDeployment_B.In1 = modelDeployment_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S25>/In1' incorporates:
    //   Outport: '<S25>/Out1'

    modelDeployment_B.In1_p = modelDeployment_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1>/EnableController'
    // InitializeConditions for UnitDelay generated from: '<S8>/Unit Delay'
    modelDeployment_DW.UnitDelay_6_DSTATE[0] =
      modelDeployment_P.UnitDelay_6_InitialCondition;
    modelDeployment_DW.UnitDelay_6_DSTATE[1] =
      modelDeployment_P.UnitDelay_6_InitialCondition;
    modelDeployment_DW.UnitDelay_6_DSTATE[2] =
      modelDeployment_P.UnitDelay_6_InitialCondition;
    modelDeployment_DW.UnitDelay_6_DSTATE[3] =
      modelDeployment_P.UnitDelay_6_InitialCondition;

    // InitializeConditions for UnitDelay generated from: '<S8>/Unit Delay'
    for (i = 0; i < 6; i++) {
      modelDeployment_DW.UnitDelay_2_DSTATE[i] =
        modelDeployment_P.UnitDelay_2_InitialCondition;
      modelDeployment_DW.UnitDelay_4_DSTATE[i] =
        modelDeployment_P.UnitDelay_4_InitialCondition;
      modelDeployment_DW.UnitDelay_5_DSTATE[i] =
        modelDeployment_P.UnitDelay_5_InitialCondition;
      modelDeployment_DW.UnitDelay_1_DSTATE[i] =
        modelDeployment_P.UnitDelay_1_InitialCondition;
    }

    // SystemInitialize for IfAction SubSystem: '<S8>/Fixed-Time Differentiator' 
    // SystemInitialize for ModelReference generated from: '<S12>/Model'
    FxTDiffSim_Init(&(modelDeployment_DW.Model_InstanceData_j.rtdw));

    // End of SystemInitialize for SubSystem: '<S8>/Fixed-Time Differentiator'

    // SystemInitialize for IfAction SubSystem: '<S8>/Fixed-Time ESO'
    // SystemInitialize for ModelReference generated from: '<S13>/Model'
    FxTESO_Init(&(modelDeployment_DW.Model_InstanceData_o.rtdw));

    // End of SystemInitialize for SubSystem: '<S8>/Fixed-Time ESO'

    // SystemInitialize for IfAction SubSystem: '<S8>/Fixed-Time Quaternion Differentiator' 
    // SystemInitialize for ModelReference generated from: '<S14>/FxTDQuat'
    FxtD_Quaternion_Init(&(modelDeployment_DW.FxTDQuat_InstanceData.rtdw));

    // End of SystemInitialize for SubSystem: '<S8>/Fixed-Time Quaternion Differentiator' 

    // SystemInitialize for IfAction SubSystem: '<S8>/Fixed-Time Quaternion ESO' 
    // SystemInitialize for ModelReference generated from: '<S15>/Model'
    FxTESO_Quaternion_Init(&(modelDeployment_DW.Model_InstanceData.rtdw));

    // End of SystemInitialize for SubSystem: '<S8>/Fixed-Time Quaternion ESO'
    for (i = 0; i < 6; i++) {
      // SystemInitialize for Merge generated from: '<S8>/Merge1'
      modelDeployment_B.pos_hat[i] = modelDeployment_P.Merge1_1_InitialOutput;

      // SystemInitialize for Merge generated from: '<S8>/Merge1'
      modelDeployment_B.pos_dot_hat[i] =
        modelDeployment_P.Merge1_2_InitialOutput;

      // SystemInitialize for Merge generated from: '<S8>/Merge1'
      modelDeployment_B.pos_ddot_hat[i] =
        modelDeployment_P.Merge1_3_InitialOutput;

      // SystemInitialize for Merge generated from: '<S8>/Merge1'
      modelDeployment_B.e_hat[i] = modelDeployment_P.Merge1_4_InitialOutput;
    }

    // SystemInitialize for Merge generated from: '<S8>/Merge1'
    modelDeployment_B.q_hat[0] = modelDeployment_P.Merge1_5_InitialOutput;

    // SystemInitialize for Merge generated from: '<S8>/Merge1'
    modelDeployment_B.q_tilde[0] = modelDeployment_P.Merge1_6_InitialOutput;

    // SystemInitialize for Merge generated from: '<S8>/Merge1'
    modelDeployment_B.q_hat[1] = modelDeployment_P.Merge1_5_InitialOutput;

    // SystemInitialize for Merge generated from: '<S8>/Merge1'
    modelDeployment_B.q_tilde[1] = modelDeployment_P.Merge1_6_InitialOutput;

    // SystemInitialize for Merge generated from: '<S8>/Merge1'
    modelDeployment_B.q_hat[2] = modelDeployment_P.Merge1_5_InitialOutput;

    // SystemInitialize for Merge generated from: '<S8>/Merge1'
    modelDeployment_B.q_tilde[2] = modelDeployment_P.Merge1_6_InitialOutput;

    // SystemInitialize for Merge generated from: '<S8>/Merge1'
    modelDeployment_B.q_hat[3] = modelDeployment_P.Merge1_5_InitialOutput;

    // SystemInitialize for Merge generated from: '<S8>/Merge1'
    modelDeployment_B.q_tilde[3] = modelDeployment_P.Merge1_6_InitialOutput;

    // SystemInitialize for IfAction SubSystem: '<S8>/ASGSMController'
    // SystemInitialize for ModelReference generated from: '<S9>/Model'
    asgsm_Init(&(modelDeployment_DW.Model_InstanceData_ju.rtdw));

    // End of SystemInitialize for SubSystem: '<S8>/ASGSMController'

    // SystemInitialize for IfAction SubSystem: '<S8>/QuaternionASGSM'
    // SystemInitialize for ModelReference generated from: '<S17>/Model'
    asgsm_quaternion_Init(&(modelDeployment_DW.Model_InstanceData_h.rtdw));

    // End of SystemInitialize for SubSystem: '<S8>/QuaternionASGSM'

    // SystemInitialize for IfAction SubSystem: '<S8>/ASGSMControllerObs'
    // SystemInitialize for ModelReference generated from: '<S10>/Model'
    asgsm_obs_Init(&(modelDeployment_DW.Model_InstanceData_jg.rtdw));

    // End of SystemInitialize for SubSystem: '<S8>/ASGSMControllerObs'

    // SystemInitialize for IfAction SubSystem: '<S8>/QuaternionASGSMObs'
    // SystemInitialize for ModelReference generated from: '<S18>/Model'
    asgsm_quat_obs_Init(&(modelDeployment_DW.Model_InstanceData_g.rtdw));

    // End of SystemInitialize for SubSystem: '<S8>/QuaternionASGSMObs'
    for (i = 0; i < 6; i++) {
      // SystemInitialize for Merge generated from: '<S8>/Merge'
      modelDeployment_B.Fu_f[i] = modelDeployment_P.Merge_1_InitialOutput;

      // SystemInitialize for Merge generated from: '<S8>/Merge'
      modelDeployment_B.e_h[i] = modelDeployment_P.Merge_2_InitialOutput;

      // SystemInitialize for Merge generated from: '<S8>/Merge'
      modelDeployment_B.e_dot[i] = modelDeployment_P.Merge_3_InitialOutput;

      // SystemInitialize for Merge generated from: '<S8>/Merge'
      modelDeployment_B.sigma_f[i] = modelDeployment_P.Merge_4_InitialOutput;

      // SystemInitialize for Merge generated from: '<S8>/Merge'
      modelDeployment_B.kt_b[i] = modelDeployment_P.Merge_5_InitialOutput;
    }

    // SystemInitialize for Merge generated from: '<S8>/Merge'
    modelDeployment_B.qe_p[0] = modelDeployment_P.Merge_6_InitialOutput;
    modelDeployment_B.qe_p[1] = modelDeployment_P.Merge_6_InitialOutput;
    modelDeployment_B.qe_p[2] = modelDeployment_P.Merge_6_InitialOutput;
    modelDeployment_B.qe_p[3] = modelDeployment_P.Merge_6_InitialOutput;

    // Start for MATLABSystem: '<S8>/Read Parameter1'
    modelDeployment_DW.obj_pq.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pq.isInitialized = 1;
    modelDeployment_DW.obj_pq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3l[0], true, 4.0);
    modelDeployment_DW.obj_pq.isSetupComplete = true;

    // Start for MATLABSystem: '<S8>/Read Parameter'
    modelDeployment_DW.obj_bi.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_bi.isInitialized = 1;
    modelDeployment_DW.obj_bi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3m[0], true, 4.0);
    modelDeployment_DW.obj_bi.isSetupComplete = true;

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.qe[0] = modelDeployment_P.data_out_Outport_2_Y0.Fu.qe[0];
    modelDeployment_B.qe[1] = modelDeployment_P.data_out_Outport_2_Y0.Fu.qe[1];
    modelDeployment_B.qe[2] = modelDeployment_P.data_out_Outport_2_Y0.Fu.qe[2];
    modelDeployment_B.qe[3] = modelDeployment_P.data_out_Outport_2_Y0.Fu.qe[3];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.q_hat_p[0] =
      modelDeployment_P.data_out_Outport_2_Y0.state_hat.q_hat[0];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.q_tilde_k[0] =
      modelDeployment_P.data_out_Outport_2_Y0.state_hat.q_tilde[0];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.q_hat_p[1] =
      modelDeployment_P.data_out_Outport_2_Y0.state_hat.q_hat[1];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.q_tilde_k[1] =
      modelDeployment_P.data_out_Outport_2_Y0.state_hat.q_tilde[1];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.q_hat_p[2] =
      modelDeployment_P.data_out_Outport_2_Y0.state_hat.q_hat[2];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.q_tilde_k[2] =
      modelDeployment_P.data_out_Outport_2_Y0.state_hat.q_tilde[2];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.q_hat_p[3] =
      modelDeployment_P.data_out_Outport_2_Y0.state_hat.q_hat[3];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.q_tilde_k[3] =
      modelDeployment_P.data_out_Outport_2_Y0.state_hat.q_tilde[3];
    for (i = 0; i < 6; i++) {
      // SystemInitialize for Product: '<S11>/Matrix Multiply1' incorporates:
      //   Outport: '<S8>/omega2'

      modelDeployment_B.MatrixMultiply1[i] = modelDeployment_P.omega2_Y0;

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.Fu_d[i] =
        modelDeployment_P.data_out_Outport_2_Y0.Fu.Fu[i];

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.e[i] = modelDeployment_P.data_out_Outport_2_Y0.Fu.e[i];

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.sigma[i] =
        modelDeployment_P.data_out_Outport_2_Y0.Fu.sigma[i];

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.kt[i] = modelDeployment_P.data_out_Outport_2_Y0.Fu.kt[i];

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.pos_hat_c[i] =
        modelDeployment_P.data_out_Outport_2_Y0.state_hat.pos_hat[i];

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.pos_dot_hat_i[i] =
        modelDeployment_P.data_out_Outport_2_Y0.state_hat.pos_dot_hat[i];

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.pos_ddot_hat_f[i] =
        modelDeployment_P.data_out_Outport_2_Y0.state_hat.pos_ddot_hat[i];

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.e_hat_l[i] =
        modelDeployment_P.data_out_Outport_2_Y0.state_hat.e_hat[i];

      // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
      //   Outport: '<S8>/data_out_Outport_2'

      modelDeployment_B.qd[i] = modelDeployment_P.data_out_Outport_2_Y0.qd.qd[i];
    }

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.quaternion_d[0] =
      modelDeployment_P.data_out_Outport_2_Y0.qd.quaternion_d[0];
    modelDeployment_B.quaternion_d[1] =
      modelDeployment_P.data_out_Outport_2_Y0.qd.quaternion_d[1];
    modelDeployment_B.quaternion_d[2] =
      modelDeployment_P.data_out_Outport_2_Y0.qd.quaternion_d[2];
    modelDeployment_B.quaternion_d[3] =
      modelDeployment_P.data_out_Outport_2_Y0.qd.quaternion_d[3];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.pos[0] = modelDeployment_P.data_out_Outport_2_Y0.pos[0];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.att[0] = modelDeployment_P.data_out_Outport_2_Y0.att[0];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.pos[1] = modelDeployment_P.data_out_Outport_2_Y0.pos[1];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.att[1] = modelDeployment_P.data_out_Outport_2_Y0.att[1];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.pos[2] = modelDeployment_P.data_out_Outport_2_Y0.pos[2];

    // SystemInitialize for SignalConversion generated from: '<S8>/data_out_Outport_2' incorporates:
    //   Outport: '<S8>/data_out_Outport_2'

    modelDeployment_B.att[2] = modelDeployment_P.data_out_Outport_2_Y0.att[2];

    // End of SystemInitialize for SubSystem: '<S1>/EnableController'

    // Start for MATLABSystem: '<S86>/Read Parameter2'
    modelDeployment_DW.obj_fw.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_fw.isInitialized = 1;
    modelDeployment_DW.obj_fw.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
      true, 4.0);
    modelDeployment_DW.obj_fw.isSetupComplete = true;

    // Start for MATLABSystem: '<S86>/Read Parameter1'
    modelDeployment_DW.obj_op.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_op.isInitialized = 1;
    modelDeployment_DW.obj_op.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, 4.0);
    modelDeployment_DW.obj_op.isSetupComplete = true;

    // Start for MATLABSystem: '<S86>/Read Parameter3'
    modelDeployment_DW.obj_g.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_g.isInitialized = 1;
    modelDeployment_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1
      [0], true, 4.0);
    modelDeployment_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S86>/Read Parameter4'
    modelDeployment_DW.obj_es.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_es.isInitialized = 1;
    modelDeployment_DW.obj_es.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, 4.0);
    modelDeployment_DW.obj_es.isSetupComplete = true;

    // Start for MATLABSystem: '<S86>/Read Parameter8'
    modelDeployment_DW.obj_j3.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_j3.isInitialized = 1;
    modelDeployment_DW.obj_j3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, 4.0);
    modelDeployment_DW.obj_j3.isSetupComplete = true;

    // Start for MATLABSystem: '<S86>/Read Parameter5'
    modelDeployment_DW.obj_di.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_di.isInitialized = 1;
    modelDeployment_DW.obj_di.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, 4.0);
    modelDeployment_DW.obj_di.isSetupComplete = true;

    // Start for MATLABSystem: '<S86>/Read Parameter6'
    modelDeployment_DW.obj_mt.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_mt.isInitialized = 1;
    modelDeployment_DW.obj_mt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, 4.0);
    modelDeployment_DW.obj_mt.isSetupComplete = true;

    // Start for MATLABSystem: '<S86>/Read Parameter9'
    modelDeployment_DW.obj_d.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_d.isInitialized = 1;
    modelDeployment_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_6
      [0], true, 4.0);
    modelDeployment_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S86>/Read Parameter7'
    modelDeployment_DW.obj_h.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_h.isInitialized = 1;
    modelDeployment_DW.obj_h.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_7
      [0], true, 4.0);
    modelDeployment_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter8'
    modelDeployment_DW.obj_dm.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_dm.isInitialized = 1;
    modelDeployment_DW.obj_dm.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, 4.0);
    modelDeployment_DW.obj_dm.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter2'
    modelDeployment_DW.obj_ef.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ef.isInitialized = 1;
    modelDeployment_DW.obj_ef.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, 4.0);
    modelDeployment_DW.obj_ef.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter9'
    modelDeployment_DW.obj_mh.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_mh.isInitialized = 1;
    modelDeployment_DW.obj_mh.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, 4.0);
    modelDeployment_DW.obj_mh.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter10'
    modelDeployment_DW.obj_or1.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_or1.isInitialized = 1;
    modelDeployment_DW.obj_or1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, 4.0);
    modelDeployment_DW.obj_or1.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter1'
    modelDeployment_DW.obj_ff.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ff.isInitialized = 1;
    modelDeployment_DW.obj_ff.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, 4.0);
    modelDeployment_DW.obj_ff.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter11'
    modelDeployment_DW.obj_dz.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_dz.isInitialized = 1;
    modelDeployment_DW.obj_dz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, 4.0);
    modelDeployment_DW.obj_dz.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter12'
    modelDeployment_DW.obj_dio.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_dio.isInitialized = 1;
    modelDeployment_DW.obj_dio.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, 4.0);
    modelDeployment_DW.obj_dio.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter3'
    modelDeployment_DW.obj_lt.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_lt.isInitialized = 1;
    modelDeployment_DW.obj_lt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, 4.0);
    modelDeployment_DW.obj_lt.isSetupComplete = true;

    // Start for MATLABSystem: '<S81>/Read Parameter13'
    modelDeployment_DW.obj_cj.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_cj.isInitialized = 1;
    modelDeployment_DW.obj_cj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, 4.0);
    modelDeployment_DW.obj_cj.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter5'
    modelDeployment_DW.obj_m1.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_m1.isInitialized = 1;
    modelDeployment_DW.obj_m1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, 4.0);
    modelDeployment_DW.obj_m1.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter12'
    modelDeployment_DW.obj_df.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_df.isInitialized = 1;
    modelDeployment_DW.obj_df.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, 4.0);
    modelDeployment_DW.obj_df.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter18'
    modelDeployment_DW.obj_cz.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_cz.isInitialized = 1;
    modelDeployment_DW.obj_cz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_j[0], true, 4.0);
    modelDeployment_DW.obj_cz.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter23'
    modelDeployment_DW.obj_jg.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_jg.isInitialized = 1;
    modelDeployment_DW.obj_jg.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_k[0], true, 4.0);
    modelDeployment_DW.obj_jg.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter32'
    modelDeployment_DW.obj_kf.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_kf.isInitialized = 1;
    modelDeployment_DW.obj_kf.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_l[0], true, 4.0);
    modelDeployment_DW.obj_kf.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter37'
    modelDeployment_DW.obj_ms.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ms.isInitialized = 1;
    modelDeployment_DW.obj_ms.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_m[0], true, 4.0);
    modelDeployment_DW.obj_ms.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter6'
    modelDeployment_DW.obj_mx.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_mx.isInitialized = 1;
    modelDeployment_DW.obj_mx.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_n[0], true, 4.0);
    modelDeployment_DW.obj_mx.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter13'
    modelDeployment_DW.obj_gc.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_gc.isInitialized = 1;
    modelDeployment_DW.obj_gc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_o[0], true, 4.0);
    modelDeployment_DW.obj_gc.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter19'
    modelDeployment_DW.obj_aw.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_aw.isInitialized = 1;
    modelDeployment_DW.obj_aw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_p[0], true, 4.0);
    modelDeployment_DW.obj_aw.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter24'
    modelDeployment_DW.obj_ic.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ic.isInitialized = 1;
    modelDeployment_DW.obj_ic.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_q[0], true, 4.0);
    modelDeployment_DW.obj_ic.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter33'
    modelDeployment_DW.obj_lq.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_lq.isInitialized = 1;
    modelDeployment_DW.obj_lq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_r[0], true, 4.0);
    modelDeployment_DW.obj_lq.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter38'
    modelDeployment_DW.obj_gj.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_gj.isInitialized = 1;
    modelDeployment_DW.obj_gj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_s[0], true, 4.0);
    modelDeployment_DW.obj_gj.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter3'
    modelDeployment_DW.obj_cit.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_cit.isInitialized = 1;
    modelDeployment_DW.obj_cit.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_t[0], true, 4.0);
    modelDeployment_DW.obj_cit.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter10'
    modelDeployment_DW.obj_ma.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ma.isInitialized = 1;
    modelDeployment_DW.obj_ma.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_u[0], true, 4.0);
    modelDeployment_DW.obj_ma.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter16'
    modelDeployment_DW.obj_gsw.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_gsw.isInitialized = 1;
    modelDeployment_DW.obj_gsw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_v[0], true, 4.0);
    modelDeployment_DW.obj_gsw.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter21'
    modelDeployment_DW.obj_psz.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_psz.isInitialized = 1;
    modelDeployment_DW.obj_psz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_w[0], true, 4.0);
    modelDeployment_DW.obj_psz.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter30'
    modelDeployment_DW.obj_ce.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ce.isInitialized = 1;
    modelDeployment_DW.obj_ce.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_x[0], true, 4.0);
    modelDeployment_DW.obj_ce.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter35'
    modelDeployment_DW.obj_mhh.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_mhh.isInitialized = 1;
    modelDeployment_DW.obj_mhh.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_y[0], true, 4.0);
    modelDeployment_DW.obj_mhh.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter4'
    modelDeployment_DW.obj_a0.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_a0.isInitialized = 1;
    modelDeployment_DW.obj_a0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_z[0], true, 4.0);
    modelDeployment_DW.obj_a0.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter11'
    modelDeployment_DW.obj_fc.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_fc.isInitialized = 1;
    modelDeployment_DW.obj_fc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_10[0], true, 4.0);
    modelDeployment_DW.obj_fc.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter17'
    modelDeployment_DW.obj_f0.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_f0.isInitialized = 1;
    modelDeployment_DW.obj_f0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_11[0], true, 4.0);
    modelDeployment_DW.obj_f0.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter22'
    modelDeployment_DW.obj_hi.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_hi.isInitialized = 1;
    modelDeployment_DW.obj_hi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_12[0], true, 4.0);
    modelDeployment_DW.obj_hi.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter31'
    modelDeployment_DW.obj_nqd.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_nqd.isInitialized = 1;
    modelDeployment_DW.obj_nqd.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_13[0], true, 4.0);
    modelDeployment_DW.obj_nqd.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter36'
    modelDeployment_DW.obj_ab.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ab.isInitialized = 1;
    modelDeployment_DW.obj_ab.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_14[0], true, 4.0);
    modelDeployment_DW.obj_ab.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter'
    modelDeployment_DW.obj_km.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_km.isInitialized = 1;
    modelDeployment_DW.obj_km.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_15[0], true, 4.0);
    modelDeployment_DW.obj_km.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter7'
    modelDeployment_DW.obj_nq.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_nq.isInitialized = 1;
    modelDeployment_DW.obj_nq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_16[0], true, 4.0);
    modelDeployment_DW.obj_nq.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter25'
    modelDeployment_DW.obj_bqm.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_bqm.isInitialized = 1;
    modelDeployment_DW.obj_bqm.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_17[0], true, 4.0);
    modelDeployment_DW.obj_bqm.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter14'
    modelDeployment_DW.obj_pw.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pw.isInitialized = 1;
    modelDeployment_DW.obj_pw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_18[0], true, 4.0);
    modelDeployment_DW.obj_pw.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter39'
    modelDeployment_DW.obj_a5d.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_a5d.isInitialized = 1;
    modelDeployment_DW.obj_a5d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_19[0], true, 4.0);
    modelDeployment_DW.obj_a5d.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter28'
    modelDeployment_DW.obj_ir.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ir.isInitialized = 1;
    modelDeployment_DW.obj_ir.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1a[0], true, 4.0);
    modelDeployment_DW.obj_ir.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter1'
    modelDeployment_DW.obj_f3.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_f3.isInitialized = 1;
    modelDeployment_DW.obj_f3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1b[0], true, 4.0);
    modelDeployment_DW.obj_f3.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter8'
    modelDeployment_DW.obj_px.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_px.isInitialized = 1;
    modelDeployment_DW.obj_px.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1c[0], true, 4.0);
    modelDeployment_DW.obj_px.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter26'
    modelDeployment_DW.obj_am.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_am.isInitialized = 1;
    modelDeployment_DW.obj_am.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1d[0], true, 4.0);
    modelDeployment_DW.obj_am.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter15'
    modelDeployment_DW.obj_an.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_an.isInitialized = 1;
    modelDeployment_DW.obj_an.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1e[0], true, 4.0);
    modelDeployment_DW.obj_an.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter40'
    modelDeployment_DW.obj_ez.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ez.isInitialized = 1;
    modelDeployment_DW.obj_ez.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1f[0], true, 4.0);
    modelDeployment_DW.obj_ez.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter29'
    modelDeployment_DW.obj_pdi.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pdi.isInitialized = 1;
    modelDeployment_DW.obj_pdi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1g[0], true, 4.0);
    modelDeployment_DW.obj_pdi.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter2'
    modelDeployment_DW.obj_hg.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_hg.isInitialized = 1;
    modelDeployment_DW.obj_hg.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1h[0], true, 4.0);
    modelDeployment_DW.obj_hg.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter9'
    modelDeployment_DW.obj_lj.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_lj.isInitialized = 1;
    modelDeployment_DW.obj_lj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1i[0], true, 4.0);
    modelDeployment_DW.obj_lj.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter27'
    modelDeployment_DW.obj_lqw.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_lqw.isInitialized = 1;
    modelDeployment_DW.obj_lqw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1j[0], true, 4.0);
    modelDeployment_DW.obj_lqw.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter20'
    modelDeployment_DW.obj_oe.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_oe.isInitialized = 1;
    modelDeployment_DW.obj_oe.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1k[0], true, 4.0);
    modelDeployment_DW.obj_oe.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter41'
    modelDeployment_DW.obj_k2.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_k2.isInitialized = 1;
    modelDeployment_DW.obj_k2.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1l[0], true, 4.0);
    modelDeployment_DW.obj_k2.isSetupComplete = true;

    // Start for MATLABSystem: '<S80>/Read Parameter34'
    modelDeployment_DW.obj_in.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_in.isInitialized = 1;
    modelDeployment_DW.obj_in.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1m[0], true, 4.0);
    modelDeployment_DW.obj_in.isSetupComplete = true;

    // Start for MATLABSystem: '<S84>/Read Parameter'
    modelDeployment_DW.obj_lm.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_lm.isInitialized = 1;
    modelDeployment_DW.obj_lm.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1n[0], true, 4.0);
    modelDeployment_DW.obj_lm.isSetupComplete = true;

    // Start for MATLABSystem: '<S84>/Read Parameter1'
    modelDeployment_DW.obj_kc.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_kc.isInitialized = 1;
    modelDeployment_DW.obj_kc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1o[0], true, 4.0);
    modelDeployment_DW.obj_kc.isSetupComplete = true;

    // Start for MATLABSystem: '<S84>/Read Parameter2'
    modelDeployment_DW.obj_p3.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_p3.isInitialized = 1;
    modelDeployment_DW.obj_p3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1p[0], true, 4.0);
    modelDeployment_DW.obj_p3.isSetupComplete = true;
    modelDeploy_ReadParameter3_Init(&modelDeployment_DW.ReadParameter3_pnae);
    modelDeploy_ReadParameter3_Init(&modelDeployment_DW.ReadParameter4_pna);

    // Start for MATLABSystem: '<S82>/Read Parameter'
    modelDeployment_DW.obj_ml.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ml.isInitialized = 1;
    modelDeployment_DW.obj_ml.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1q[0], true, 4.0);
    modelDeployment_DW.obj_ml.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter4'
    modelDeployment_DW.obj_nc.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_nc.isInitialized = 1;
    modelDeployment_DW.obj_nc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1r[0], true, 4.0);
    modelDeployment_DW.obj_nc.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter8'
    modelDeployment_DW.obj_pk.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pk.isInitialized = 1;
    modelDeployment_DW.obj_pk.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1s[0], true, 4.0);
    modelDeployment_DW.obj_pk.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter12'
    modelDeployment_DW.obj_nh.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_nh.isInitialized = 1;
    modelDeployment_DW.obj_nh.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1t[0], true, 4.0);
    modelDeployment_DW.obj_nh.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter16'
    modelDeployment_DW.obj_po.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_po.isInitialized = 1;
    modelDeployment_DW.obj_po.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1u[0], true, 4.0);
    modelDeployment_DW.obj_po.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter20'
    modelDeployment_DW.obj_bz.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_bz.isInitialized = 1;
    modelDeployment_DW.obj_bz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1v[0], true, 4.0);
    modelDeployment_DW.obj_bz.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter1'
    modelDeployment_DW.obj_hq.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_hq.isInitialized = 1;
    modelDeployment_DW.obj_hq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1w[0], true, 4.0);
    modelDeployment_DW.obj_hq.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter5'
    modelDeployment_DW.obj_k1.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_k1.isInitialized = 1;
    modelDeployment_DW.obj_k1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1x[0], true, 4.0);
    modelDeployment_DW.obj_k1.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter9'
    modelDeployment_DW.obj_o5.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_o5.isInitialized = 1;
    modelDeployment_DW.obj_o5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1y[0], true, 4.0);
    modelDeployment_DW.obj_o5.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter13'
    modelDeployment_DW.obj_gt.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_gt.isInitialized = 1;
    modelDeployment_DW.obj_gt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1z[0], true, 4.0);
    modelDeployment_DW.obj_gt.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter17'
    modelDeployment_DW.obj_cg.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_cg.isInitialized = 1;
    modelDeployment_DW.obj_cg.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_20[0], true, 4.0);
    modelDeployment_DW.obj_cg.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter21'
    modelDeployment_DW.obj_ny.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ny.isInitialized = 1;
    modelDeployment_DW.obj_ny.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_21[0], true, 4.0);
    modelDeployment_DW.obj_ny.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter2'
    modelDeployment_DW.obj_c1.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_c1.isInitialized = 1;
    modelDeployment_DW.obj_c1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_22[0], true, 4.0);
    modelDeployment_DW.obj_c1.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter6'
    modelDeployment_DW.obj_pi.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pi.isInitialized = 1;
    modelDeployment_DW.obj_pi.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_23[0], true, 4.0);
    modelDeployment_DW.obj_pi.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter10'
    modelDeployment_DW.obj_mb.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_mb.isInitialized = 1;
    modelDeployment_DW.obj_mb.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_24[0], true, 4.0);
    modelDeployment_DW.obj_mb.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter14'
    modelDeployment_DW.obj_go.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_go.isInitialized = 1;
    modelDeployment_DW.obj_go.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_25[0], true, 4.0);
    modelDeployment_DW.obj_go.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter18'
    modelDeployment_DW.obj_pm.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pm.isInitialized = 1;
    modelDeployment_DW.obj_pm.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_26[0], true, 4.0);
    modelDeployment_DW.obj_pm.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter22'
    modelDeployment_DW.obj_kb.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_kb.isInitialized = 1;
    modelDeployment_DW.obj_kb.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_27[0], true, 4.0);
    modelDeployment_DW.obj_kb.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter3'
    modelDeployment_DW.obj_dp.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_dp.isInitialized = 1;
    modelDeployment_DW.obj_dp.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_28[0], true, 4.0);
    modelDeployment_DW.obj_dp.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter7'
    modelDeployment_DW.obj_dj.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_dj.isInitialized = 1;
    modelDeployment_DW.obj_dj.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_29[0], true, 4.0);
    modelDeployment_DW.obj_dj.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter11'
    modelDeployment_DW.obj_lw.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_lw.isInitialized = 1;
    modelDeployment_DW.obj_lw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2a[0], true, 4.0);
    modelDeployment_DW.obj_lw.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter15'
    modelDeployment_DW.obj_jn.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_jn.isInitialized = 1;
    modelDeployment_DW.obj_jn.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2b[0], true, 4.0);
    modelDeployment_DW.obj_jn.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter19'
    modelDeployment_DW.obj_o4.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_o4.isInitialized = 1;
    modelDeployment_DW.obj_o4.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2c[0], true, 4.0);
    modelDeployment_DW.obj_o4.isSetupComplete = true;

    // Start for MATLABSystem: '<S82>/Read Parameter23'
    modelDeployment_DW.obj_j5.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_j5.isInitialized = 1;
    modelDeployment_DW.obj_j5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2d[0], true, 4.0);
    modelDeployment_DW.obj_j5.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter24'
    modelDeployment_DW.obj_gs.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_gs.isInitialized = 1;
    modelDeployment_DW.obj_gs.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2e[0], true, 4.0);
    modelDeployment_DW.obj_gs.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter32'
    modelDeployment_DW.obj_jm.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_jm.isInitialized = 1;
    modelDeployment_DW.obj_jm.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2f[0], true, 4.0);
    modelDeployment_DW.obj_jm.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter'
    modelDeployment_DW.obj_jz.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_jz.isInitialized = 1;
    modelDeployment_DW.obj_jz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2g[0], true, 4.0);
    modelDeployment_DW.obj_jz.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter6'
    modelDeployment_DW.obj_hr.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_hr.isInitialized = 1;
    modelDeployment_DW.obj_hr.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2h[0], true, 4.0);
    modelDeployment_DW.obj_hr.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter12'
    modelDeployment_DW.obj_id.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_id.isInitialized = 1;
    modelDeployment_DW.obj_id.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2i[0], true, 4.0);
    modelDeployment_DW.obj_id.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter20'
    modelDeployment_DW.obj_jy.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_jy.isInitialized = 1;
    modelDeployment_DW.obj_jy.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2j[0], true, 4.0);
    modelDeployment_DW.obj_jy.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter25'
    modelDeployment_DW.obj_kx.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_kx.isInitialized = 1;
    modelDeployment_DW.obj_kx.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2k[0], true, 4.0);
    modelDeployment_DW.obj_kx.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter33'
    modelDeployment_DW.obj_na.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_na.isInitialized = 1;
    modelDeployment_DW.obj_na.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2l[0], true, 4.0);
    modelDeployment_DW.obj_na.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter1'
    modelDeployment_DW.obj_pd.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pd.isInitialized = 1;
    modelDeployment_DW.obj_pd.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2m[0], true, 4.0);
    modelDeployment_DW.obj_pd.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter7'
    modelDeployment_DW.obj_br.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_br.isInitialized = 1;
    modelDeployment_DW.obj_br.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2n[0], true, 4.0);
    modelDeployment_DW.obj_br.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter13'
    modelDeployment_DW.obj_hh.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_hh.isInitialized = 1;
    modelDeployment_DW.obj_hh.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2o[0], true, 4.0);
    modelDeployment_DW.obj_hh.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter21'
    modelDeployment_DW.obj_pl.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pl.isInitialized = 1;
    modelDeployment_DW.obj_pl.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2p[0], true, 4.0);
    modelDeployment_DW.obj_pl.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter28'
    modelDeployment_DW.obj_dl.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_dl.isInitialized = 1;
    modelDeployment_DW.obj_dl.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2q[0], true, 4.0);
    modelDeployment_DW.obj_dl.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter34'
    modelDeployment_DW.obj_gg.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_gg.isInitialized = 1;
    modelDeployment_DW.obj_gg.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2r[0], true, 4.0);
    modelDeployment_DW.obj_gg.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter2'
    modelDeployment_DW.obj_ps.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ps.isInitialized = 1;
    modelDeployment_DW.obj_ps.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2s[0], true, 4.0);
    modelDeployment_DW.obj_ps.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter8'
    modelDeployment_DW.obj_a.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_a.isInitialized = 1;
    modelDeployment_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2t[0], true, 4.0);
    modelDeployment_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter16'
    modelDeployment_DW.obj_pc.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pc.isInitialized = 1;
    modelDeployment_DW.obj_pc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2u[0], true, 4.0);
    modelDeployment_DW.obj_pc.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter22'
    modelDeployment_DW.obj_cy.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_cy.isInitialized = 1;
    modelDeployment_DW.obj_cy.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2v[0], true, 4.0);
    modelDeployment_DW.obj_cy.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter29'
    modelDeployment_DW.obj_a5.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_a5.isInitialized = 1;
    modelDeployment_DW.obj_a5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2w[0], true, 4.0);
    modelDeployment_DW.obj_a5.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter35'
    modelDeployment_DW.obj_i.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_i.isInitialized = 1;
    modelDeployment_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2x[0], true, 4.0);
    modelDeployment_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter3'
    modelDeployment_DW.obj_ci.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ci.isInitialized = 1;
    modelDeployment_DW.obj_ci.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2y[0], true, 4.0);
    modelDeployment_DW.obj_ci.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter9'
    modelDeployment_DW.obj_lu.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_lu.isInitialized = 1;
    modelDeployment_DW.obj_lu.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2z[0], true, 4.0);
    modelDeployment_DW.obj_lu.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter17'
    modelDeployment_DW.obj_fq.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_fq.isInitialized = 1;
    modelDeployment_DW.obj_fq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_30[0], true, 4.0);
    modelDeployment_DW.obj_fq.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter23'
    modelDeployment_DW.obj_h3.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_h3.isInitialized = 1;
    modelDeployment_DW.obj_h3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_31[0], true, 4.0);
    modelDeployment_DW.obj_h3.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter30'
    modelDeployment_DW.obj_dx.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_dx.isInitialized = 1;
    modelDeployment_DW.obj_dx.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_32[0], true, 4.0);
    modelDeployment_DW.obj_dx.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter26'
    modelDeployment_DW.obj_hx.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_hx.isInitialized = 1;
    modelDeployment_DW.obj_hx.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_33[0], true, 4.0);
    modelDeployment_DW.obj_hx.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter4'
    modelDeployment_DW.obj_b3.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_b3.isInitialized = 1;
    modelDeployment_DW.obj_b3.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_34[0], true, 4.0);
    modelDeployment_DW.obj_b3.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter10'
    modelDeployment_DW.obj_fx.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_fx.isInitialized = 1;
    modelDeployment_DW.obj_fx.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_35[0], true, 4.0);
    modelDeployment_DW.obj_fx.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter18'
    modelDeployment_DW.obj_bm.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_bm.isInitialized = 1;
    modelDeployment_DW.obj_bm.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_36[0], true, 4.0);
    modelDeployment_DW.obj_bm.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter14'
    modelDeployment_DW.obj_dc.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_dc.isInitialized = 1;
    modelDeployment_DW.obj_dc.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_37[0], true, 4.0);
    modelDeployment_DW.obj_dc.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter31'
    modelDeployment_DW.obj_mu.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_mu.isInitialized = 1;
    modelDeployment_DW.obj_mu.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_38[0], true, 4.0);
    modelDeployment_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter27'
    modelDeployment_DW.obj_kz.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_kz.isInitialized = 1;
    modelDeployment_DW.obj_kz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_39[0], true, 4.0);
    modelDeployment_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter5'
    modelDeployment_DW.obj_bq.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_bq.isInitialized = 1;
    modelDeployment_DW.obj_bq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3a[0], true, 4.0);
    modelDeployment_DW.obj_bq.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter11'
    modelDeployment_DW.obj_ns.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ns.isInitialized = 1;
    modelDeployment_DW.obj_ns.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3b[0], true, 4.0);
    modelDeployment_DW.obj_ns.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter19'
    modelDeployment_DW.obj_mz.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_mz.isInitialized = 1;
    modelDeployment_DW.obj_mz.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3c[0], true, 4.0);
    modelDeployment_DW.obj_mz.isSetupComplete = true;

    // Start for MATLABSystem: '<S83>/Read Parameter15'
    modelDeployment_DW.obj_my.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_my.isInitialized = 1;
    modelDeployment_DW.obj_my.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3d[0], true, 4.0);
    modelDeployment_DW.obj_my.isSetupComplete = true;

    // Start for MATLABSystem: '<S35>/SourceBlock'
    modelDeployment_DW.obj_m.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_m.isInitialized = 1;
    modelDeployment_DW.obj_m.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(modelDeployment_DW.obj_m.orbMetadataObj,
                         &modelDeployment_DW.obj_m.eventStructObj);
    modelDeployment_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/Read Parameter1'
    modelDeployment_DW.obj_n.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_n.isInitialized = 1;
    modelDeployment_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3e[0], true, 4.0);
    modelDeployment_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S23>/SourceBlock'
    modelDeployment_DW.obj_j.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_j.isInitialized = 1;
    modelDeployment_DW.obj_j.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(modelDeployment_DW.obj_j.orbMetadataObj,
                         &modelDeployment_DW.obj_j.eventStructObj);
    modelDeployment_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S21>/SourceBlock'
    modelDeployment_DW.obj_k.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_k.isInitialized = 1;
    modelDeployment_DW.obj_k.orbMetadataObj = ORB_ID(vehicle_attitude);
    uORB_read_initialize(modelDeployment_DW.obj_k.orbMetadataObj,
                         &modelDeployment_DW.obj_k.eventStructObj);
    modelDeployment_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      modelDeployment_DW.obj_o.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      modelDeployment_DW.obj_o.ValidServoIdx[i] = false;
    }

    modelDeployment_DW.obj_o.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_o.isSetupComplete = false;
    modelDeployment_DW.obj_o.isInitialized = 1;
    modelDep_PX4Actuators_setupImpl(&modelDeployment_DW.obj_o);
    modelDeployment_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'

    // Start for MATLABSystem: '<S7>/PX4 Timestamp'
    modelDeployment_DW.obj_or.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_or.isInitialized = 1;
    modelDeployment_DW.obj_or.isSetupComplete = true;

    // Start for MATLABSystem: '<S146>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment9'

    modelDeployment_DW.obj_jmm.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_jmm.isInitialized = 1;
    modelDeployment_DW.obj_jmm.orbMetadataObj = ORB_ID(custom_est_error);
    uORB_write_initialize(modelDeployment_DW.obj_jmm.orbMetadataObj,
                          &modelDeployment_DW.obj_jmm.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment9, 1);
    modelDeployment_DW.obj_jmm.isSetupComplete = true;

    // Start for MATLABSystem: '<S135>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment'

    modelDeployment_DW.obj_ib.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ib.isInitialized = 1;
    modelDeployment_DW.obj_ib.orbMetadataObj = ORB_ID(custom_forces);
    uORB_write_initialize(modelDeployment_DW.obj_ib.orbMetadataObj,
                          &modelDeployment_DW.obj_ib.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment, 1);
    modelDeployment_DW.obj_ib.isSetupComplete = true;

    // Start for MATLABSystem: '<S136>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'

    modelDeployment_DW.obj_ff4.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ff4.isInitialized = 1;
    modelDeployment_DW.obj_ff4.orbMetadataObj = ORB_ID(custom_est_pos);
    uORB_write_initialize(modelDeployment_DW.obj_ff4.orbMetadataObj,
                          &modelDeployment_DW.obj_ff4.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment1, 1);
    modelDeployment_DW.obj_ff4.isSetupComplete = true;

    // Start for MATLABSystem: '<S138>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment11'

    modelDeployment_DW.obj_ht.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ht.isInitialized = 1;
    modelDeployment_DW.obj_ht.orbMetadataObj = ORB_ID(custom_extended_state);
    uORB_write_initialize(modelDeployment_DW.obj_ht.orbMetadataObj,
                          &modelDeployment_DW.obj_ht.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment11, 1);
    modelDeployment_DW.obj_ht.isSetupComplete = true;

    // Start for MATLABSystem: '<S139>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment2'

    modelDeployment_DW.obj_md.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_md.isInitialized = 1;
    modelDeployment_DW.obj_md.orbMetadataObj = ORB_ID(custom_pos);
    uORB_write_initialize(modelDeployment_DW.obj_md.orbMetadataObj,
                          &modelDeployment_DW.obj_md.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment2, 1);
    modelDeployment_DW.obj_md.isSetupComplete = true;

    // Start for MATLABSystem: '<S140>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment3'

    modelDeployment_DW.obj_pj.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_pj.isInitialized = 1;
    modelDeployment_DW.obj_pj.orbMetadataObj = ORB_ID(custom_est_vel);
    uORB_write_initialize(modelDeployment_DW.obj_pj.orbMetadataObj,
                          &modelDeployment_DW.obj_pj.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment3, 1);
    modelDeployment_DW.obj_pj.isSetupComplete = true;

    // Start for MATLABSystem: '<S141>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment4'

    modelDeployment_DW.obj_myb.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_myb.isInitialized = 1;
    modelDeployment_DW.obj_myb.orbMetadataObj = ORB_ID(custom_error);
    uORB_write_initialize(modelDeployment_DW.obj_myb.orbMetadataObj,
                          &modelDeployment_DW.obj_myb.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment4, 1);
    modelDeployment_DW.obj_myb.isSetupComplete = true;

    // Start for MATLABSystem: '<S143>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment6'

    modelDeployment_DW.obj_p4.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_p4.isInitialized = 1;
    modelDeployment_DW.obj_p4.orbMetadataObj = ORB_ID(custom_des_pos);
    uORB_write_initialize(modelDeployment_DW.obj_p4.orbMetadataObj,
                          &modelDeployment_DW.obj_p4.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment6, 1);
    modelDeployment_DW.obj_p4.isSetupComplete = true;

    // Start for MATLABSystem: '<S144>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment7'

    modelDeployment_DW.obj_cjd.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_cjd.isInitialized = 1;
    modelDeployment_DW.obj_cjd.orbMetadataObj = ORB_ID(custom_sigma);
    uORB_write_initialize(modelDeployment_DW.obj_cjd.orbMetadataObj,
                          &modelDeployment_DW.obj_cjd.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment7, 1);
    modelDeployment_DW.obj_cjd.isSetupComplete = true;

    // Start for MATLABSystem: '<S145>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment8'

    modelDeployment_DW.obj_o5o.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_o5o.isInitialized = 1;
    modelDeployment_DW.obj_o5o.orbMetadataObj = ORB_ID(custom_kt);
    uORB_write_initialize(modelDeployment_DW.obj_o5o.orbMetadataObj,
                          &modelDeployment_DW.obj_o5o.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment8, 1);
    modelDeployment_DW.obj_o5o.isSetupComplete = true;

    // Start for MATLABSystem: '<S142>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment5'

    modelDeployment_DW.obj_ida.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ida.isInitialized = 1;
    modelDeployment_DW.obj_ida.orbMetadataObj = ORB_ID(custom_pwm);
    uORB_write_initialize(modelDeployment_DW.obj_ida.orbMetadataObj,
                          &modelDeployment_DW.obj_ida.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment5, 1);
    modelDeployment_DW.obj_ida.isSetupComplete = true;

    // Start for MATLABSystem: '<S137>/SinkBlock' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment10'

    modelDeployment_DW.obj_ii.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_ii.isInitialized = 1;
    modelDeployment_DW.obj_ii.orbMetadataObj = ORB_ID(custom_quaternion);
    uORB_write_initialize(modelDeployment_DW.obj_ii.orbMetadataObj,
                          &modelDeployment_DW.obj_ii.orbAdvertiseObj,
                          &modelDeployment_B.BusAssignment10, 1);
    modelDeployment_DW.obj_ii.isSetupComplete = true;

    // Start for MATLABSystem: '<S85>/Read Parameter'
    modelDeployment_DW.obj_mw.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_mw.isInitialized = 1;
    modelDeployment_DW.obj_mw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3f[0], true, 4.0);
    modelDeployment_DW.obj_mw.isSetupComplete = true;

    // Start for MATLABSystem: '<S85>/Read Parameter1'
    modelDeployment_DW.obj_b.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_b.isInitialized = 1;
    modelDeployment_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3g[0], true, 4.0);
    modelDeployment_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S85>/Read Parameter2'
    modelDeployment_DW.obj_p.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_p.isInitialized = 1;
    modelDeployment_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3h[0], true, 4.0);
    modelDeployment_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S85>/Read Parameter3'
    modelDeployment_DW.obj_l.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_l.isInitialized = 1;
    modelDeployment_DW.obj_l.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3i[0], true, 4.0);
    modelDeployment_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S85>/Read Parameter4'
    modelDeployment_DW.obj_d5.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_d5.isInitialized = 1;
    modelDeployment_DW.obj_d5.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3j[0], true, 4.0);
    modelDeployment_DW.obj_d5.isSetupComplete = true;

    // Start for MATLABSystem: '<S85>/Read Parameter5'
    modelDeployment_DW.obj_eu.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_eu.isInitialized = 1;
    modelDeployment_DW.obj_eu.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3k[0], true, 4.0);
    modelDeployment_DW.obj_eu.isSetupComplete = true;

    // Start for MATLABSystem: '<S22>/SourceBlock'
    modelDeployment_DW.obj_e.matlabCodegenIsDeleted = false;
    modelDeployment_DW.obj_e.isInitialized = 1;
    modelDeployment_DW.obj_e.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(modelDeployment_DW.obj_e.orbMetadataObj,
                         &modelDeployment_DW.obj_e.eventStructObj);
    modelDeployment_DW.obj_e.isSetupComplete = true;
  }
}

// Model terminate function
void modelDeployment_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S86>/Read Parameter2'
  if (!modelDeployment_DW.obj_fw.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_fw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter2'

  // Terminate for MATLABSystem: '<S86>/Read Parameter1'
  if (!modelDeployment_DW.obj_op.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_op.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter1'

  // Terminate for MATLABSystem: '<S86>/Read Parameter3'
  if (!modelDeployment_DW.obj_g.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter3'

  // Terminate for MATLABSystem: '<S86>/Read Parameter4'
  if (!modelDeployment_DW.obj_es.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_es.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter4'

  // Terminate for MATLABSystem: '<S86>/Read Parameter8'
  if (!modelDeployment_DW.obj_j3.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_j3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter8'

  // Terminate for MATLABSystem: '<S86>/Read Parameter5'
  if (!modelDeployment_DW.obj_di.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_di.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter5'

  // Terminate for MATLABSystem: '<S86>/Read Parameter6'
  if (!modelDeployment_DW.obj_mt.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_mt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter6'

  // Terminate for MATLABSystem: '<S86>/Read Parameter9'
  if (!modelDeployment_DW.obj_d.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter9'

  // Terminate for MATLABSystem: '<S86>/Read Parameter7'
  if (!modelDeployment_DW.obj_h.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S86>/Read Parameter7'

  // Terminate for MATLABSystem: '<S81>/Read Parameter8'
  if (!modelDeployment_DW.obj_dm.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_dm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter8'

  // Terminate for MATLABSystem: '<S81>/Read Parameter2'
  if (!modelDeployment_DW.obj_ef.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ef.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter2'

  // Terminate for MATLABSystem: '<S81>/Read Parameter9'
  if (!modelDeployment_DW.obj_mh.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_mh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter9'

  // Terminate for MATLABSystem: '<S81>/Read Parameter10'
  if (!modelDeployment_DW.obj_or1.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_or1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter10'

  // Terminate for MATLABSystem: '<S81>/Read Parameter1'
  if (!modelDeployment_DW.obj_ff.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ff.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter1'

  // Terminate for MATLABSystem: '<S81>/Read Parameter11'
  if (!modelDeployment_DW.obj_dz.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_dz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter11'

  // Terminate for MATLABSystem: '<S81>/Read Parameter12'
  if (!modelDeployment_DW.obj_dio.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_dio.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter12'

  // Terminate for MATLABSystem: '<S81>/Read Parameter3'
  if (!modelDeployment_DW.obj_lt.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_lt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter3'

  // Terminate for MATLABSystem: '<S81>/Read Parameter13'
  if (!modelDeployment_DW.obj_cj.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_cj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S81>/Read Parameter13'

  // Terminate for MATLABSystem: '<S80>/Read Parameter5'
  if (!modelDeployment_DW.obj_m1.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_m1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter5'

  // Terminate for MATLABSystem: '<S80>/Read Parameter12'
  if (!modelDeployment_DW.obj_df.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_df.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter12'

  // Terminate for MATLABSystem: '<S80>/Read Parameter18'
  if (!modelDeployment_DW.obj_cz.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_cz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter18'

  // Terminate for MATLABSystem: '<S80>/Read Parameter23'
  if (!modelDeployment_DW.obj_jg.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_jg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter23'

  // Terminate for MATLABSystem: '<S80>/Read Parameter32'
  if (!modelDeployment_DW.obj_kf.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_kf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter32'

  // Terminate for MATLABSystem: '<S80>/Read Parameter37'
  if (!modelDeployment_DW.obj_ms.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ms.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter37'

  // Terminate for MATLABSystem: '<S80>/Read Parameter6'
  if (!modelDeployment_DW.obj_mx.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_mx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter6'

  // Terminate for MATLABSystem: '<S80>/Read Parameter13'
  if (!modelDeployment_DW.obj_gc.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_gc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter13'

  // Terminate for MATLABSystem: '<S80>/Read Parameter19'
  if (!modelDeployment_DW.obj_aw.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_aw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter19'

  // Terminate for MATLABSystem: '<S80>/Read Parameter24'
  if (!modelDeployment_DW.obj_ic.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ic.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter24'

  // Terminate for MATLABSystem: '<S80>/Read Parameter33'
  if (!modelDeployment_DW.obj_lq.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_lq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter33'

  // Terminate for MATLABSystem: '<S80>/Read Parameter38'
  if (!modelDeployment_DW.obj_gj.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_gj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter38'

  // Terminate for MATLABSystem: '<S80>/Read Parameter3'
  if (!modelDeployment_DW.obj_cit.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_cit.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter3'

  // Terminate for MATLABSystem: '<S80>/Read Parameter10'
  if (!modelDeployment_DW.obj_ma.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ma.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter10'

  // Terminate for MATLABSystem: '<S80>/Read Parameter16'
  if (!modelDeployment_DW.obj_gsw.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_gsw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter16'

  // Terminate for MATLABSystem: '<S80>/Read Parameter21'
  if (!modelDeployment_DW.obj_psz.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_psz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter21'

  // Terminate for MATLABSystem: '<S80>/Read Parameter30'
  if (!modelDeployment_DW.obj_ce.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ce.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter30'

  // Terminate for MATLABSystem: '<S80>/Read Parameter35'
  if (!modelDeployment_DW.obj_mhh.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_mhh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter35'

  // Terminate for MATLABSystem: '<S80>/Read Parameter4'
  if (!modelDeployment_DW.obj_a0.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_a0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter4'

  // Terminate for MATLABSystem: '<S80>/Read Parameter11'
  if (!modelDeployment_DW.obj_fc.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_fc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter11'

  // Terminate for MATLABSystem: '<S80>/Read Parameter17'
  if (!modelDeployment_DW.obj_f0.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_f0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter17'

  // Terminate for MATLABSystem: '<S80>/Read Parameter22'
  if (!modelDeployment_DW.obj_hi.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_hi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter22'

  // Terminate for MATLABSystem: '<S80>/Read Parameter31'
  if (!modelDeployment_DW.obj_nqd.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_nqd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter31'

  // Terminate for MATLABSystem: '<S80>/Read Parameter36'
  if (!modelDeployment_DW.obj_ab.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ab.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter36'

  // Terminate for MATLABSystem: '<S80>/Read Parameter'
  if (!modelDeployment_DW.obj_km.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_km.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter'

  // Terminate for MATLABSystem: '<S80>/Read Parameter7'
  if (!modelDeployment_DW.obj_nq.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_nq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter7'

  // Terminate for MATLABSystem: '<S80>/Read Parameter25'
  if (!modelDeployment_DW.obj_bqm.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_bqm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter25'

  // Terminate for MATLABSystem: '<S80>/Read Parameter14'
  if (!modelDeployment_DW.obj_pw.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter14'

  // Terminate for MATLABSystem: '<S80>/Read Parameter39'
  if (!modelDeployment_DW.obj_a5d.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_a5d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter39'

  // Terminate for MATLABSystem: '<S80>/Read Parameter28'
  if (!modelDeployment_DW.obj_ir.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ir.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter28'

  // Terminate for MATLABSystem: '<S80>/Read Parameter1'
  if (!modelDeployment_DW.obj_f3.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_f3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter1'

  // Terminate for MATLABSystem: '<S80>/Read Parameter8'
  if (!modelDeployment_DW.obj_px.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_px.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter8'

  // Terminate for MATLABSystem: '<S80>/Read Parameter26'
  if (!modelDeployment_DW.obj_am.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_am.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter26'

  // Terminate for MATLABSystem: '<S80>/Read Parameter15'
  if (!modelDeployment_DW.obj_an.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_an.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter15'

  // Terminate for MATLABSystem: '<S80>/Read Parameter40'
  if (!modelDeployment_DW.obj_ez.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ez.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter40'

  // Terminate for MATLABSystem: '<S80>/Read Parameter29'
  if (!modelDeployment_DW.obj_pdi.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pdi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter29'

  // Terminate for MATLABSystem: '<S80>/Read Parameter2'
  if (!modelDeployment_DW.obj_hg.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_hg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter2'

  // Terminate for MATLABSystem: '<S80>/Read Parameter9'
  if (!modelDeployment_DW.obj_lj.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_lj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter9'

  // Terminate for MATLABSystem: '<S80>/Read Parameter27'
  if (!modelDeployment_DW.obj_lqw.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_lqw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter27'

  // Terminate for MATLABSystem: '<S80>/Read Parameter20'
  if (!modelDeployment_DW.obj_oe.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_oe.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter20'

  // Terminate for MATLABSystem: '<S80>/Read Parameter41'
  if (!modelDeployment_DW.obj_k2.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_k2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter41'

  // Terminate for MATLABSystem: '<S80>/Read Parameter34'
  if (!modelDeployment_DW.obj_in.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_in.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S80>/Read Parameter34'

  // Terminate for MATLABSystem: '<S84>/Read Parameter'
  if (!modelDeployment_DW.obj_lm.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_lm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S84>/Read Parameter'

  // Terminate for MATLABSystem: '<S84>/Read Parameter1'
  if (!modelDeployment_DW.obj_kc.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_kc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S84>/Read Parameter1'

  // Terminate for MATLABSystem: '<S84>/Read Parameter2'
  if (!modelDeployment_DW.obj_p3.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_p3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S84>/Read Parameter2'
  modelDeploy_ReadParameter3_Term(&modelDeployment_DW.ReadParameter3_pnae);
  modelDeploy_ReadParameter3_Term(&modelDeployment_DW.ReadParameter4_pna);

  // Terminate for MATLABSystem: '<S82>/Read Parameter'
  if (!modelDeployment_DW.obj_ml.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ml.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter'

  // Terminate for MATLABSystem: '<S82>/Read Parameter4'
  if (!modelDeployment_DW.obj_nc.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_nc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter4'

  // Terminate for MATLABSystem: '<S82>/Read Parameter8'
  if (!modelDeployment_DW.obj_pk.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter8'

  // Terminate for MATLABSystem: '<S82>/Read Parameter12'
  if (!modelDeployment_DW.obj_nh.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_nh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter12'

  // Terminate for MATLABSystem: '<S82>/Read Parameter16'
  if (!modelDeployment_DW.obj_po.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_po.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter16'

  // Terminate for MATLABSystem: '<S82>/Read Parameter20'
  if (!modelDeployment_DW.obj_bz.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_bz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter20'

  // Terminate for MATLABSystem: '<S82>/Read Parameter1'
  if (!modelDeployment_DW.obj_hq.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_hq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter1'

  // Terminate for MATLABSystem: '<S82>/Read Parameter5'
  if (!modelDeployment_DW.obj_k1.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_k1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter5'

  // Terminate for MATLABSystem: '<S82>/Read Parameter9'
  if (!modelDeployment_DW.obj_o5.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_o5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter9'

  // Terminate for MATLABSystem: '<S82>/Read Parameter13'
  if (!modelDeployment_DW.obj_gt.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_gt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter13'

  // Terminate for MATLABSystem: '<S82>/Read Parameter17'
  if (!modelDeployment_DW.obj_cg.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_cg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter17'

  // Terminate for MATLABSystem: '<S82>/Read Parameter21'
  if (!modelDeployment_DW.obj_ny.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ny.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter21'

  // Terminate for MATLABSystem: '<S82>/Read Parameter2'
  if (!modelDeployment_DW.obj_c1.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_c1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter2'

  // Terminate for MATLABSystem: '<S82>/Read Parameter6'
  if (!modelDeployment_DW.obj_pi.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter6'

  // Terminate for MATLABSystem: '<S82>/Read Parameter10'
  if (!modelDeployment_DW.obj_mb.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_mb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter10'

  // Terminate for MATLABSystem: '<S82>/Read Parameter14'
  if (!modelDeployment_DW.obj_go.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_go.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter14'

  // Terminate for MATLABSystem: '<S82>/Read Parameter18'
  if (!modelDeployment_DW.obj_pm.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter18'

  // Terminate for MATLABSystem: '<S82>/Read Parameter22'
  if (!modelDeployment_DW.obj_kb.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_kb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter22'

  // Terminate for MATLABSystem: '<S82>/Read Parameter3'
  if (!modelDeployment_DW.obj_dp.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_dp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter3'

  // Terminate for MATLABSystem: '<S82>/Read Parameter7'
  if (!modelDeployment_DW.obj_dj.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_dj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter7'

  // Terminate for MATLABSystem: '<S82>/Read Parameter11'
  if (!modelDeployment_DW.obj_lw.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_lw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter11'

  // Terminate for MATLABSystem: '<S82>/Read Parameter15'
  if (!modelDeployment_DW.obj_jn.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_jn.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter15'

  // Terminate for MATLABSystem: '<S82>/Read Parameter19'
  if (!modelDeployment_DW.obj_o4.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_o4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter19'

  // Terminate for MATLABSystem: '<S82>/Read Parameter23'
  if (!modelDeployment_DW.obj_j5.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_j5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S82>/Read Parameter23'

  // Terminate for MATLABSystem: '<S83>/Read Parameter24'
  if (!modelDeployment_DW.obj_gs.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_gs.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter24'

  // Terminate for MATLABSystem: '<S83>/Read Parameter32'
  if (!modelDeployment_DW.obj_jm.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_jm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter32'

  // Terminate for MATLABSystem: '<S83>/Read Parameter'
  if (!modelDeployment_DW.obj_jz.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_jz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter'

  // Terminate for MATLABSystem: '<S83>/Read Parameter6'
  if (!modelDeployment_DW.obj_hr.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_hr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter6'

  // Terminate for MATLABSystem: '<S83>/Read Parameter12'
  if (!modelDeployment_DW.obj_id.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_id.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter12'

  // Terminate for MATLABSystem: '<S83>/Read Parameter20'
  if (!modelDeployment_DW.obj_jy.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_jy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter20'

  // Terminate for MATLABSystem: '<S83>/Read Parameter25'
  if (!modelDeployment_DW.obj_kx.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_kx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter25'

  // Terminate for MATLABSystem: '<S83>/Read Parameter33'
  if (!modelDeployment_DW.obj_na.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_na.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter33'

  // Terminate for MATLABSystem: '<S83>/Read Parameter1'
  if (!modelDeployment_DW.obj_pd.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter1'

  // Terminate for MATLABSystem: '<S83>/Read Parameter7'
  if (!modelDeployment_DW.obj_br.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_br.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter7'

  // Terminate for MATLABSystem: '<S83>/Read Parameter13'
  if (!modelDeployment_DW.obj_hh.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_hh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter13'

  // Terminate for MATLABSystem: '<S83>/Read Parameter21'
  if (!modelDeployment_DW.obj_pl.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter21'

  // Terminate for MATLABSystem: '<S83>/Read Parameter28'
  if (!modelDeployment_DW.obj_dl.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_dl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter28'

  // Terminate for MATLABSystem: '<S83>/Read Parameter34'
  if (!modelDeployment_DW.obj_gg.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_gg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter34'

  // Terminate for MATLABSystem: '<S83>/Read Parameter2'
  if (!modelDeployment_DW.obj_ps.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ps.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter2'

  // Terminate for MATLABSystem: '<S83>/Read Parameter8'
  if (!modelDeployment_DW.obj_a.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter8'

  // Terminate for MATLABSystem: '<S83>/Read Parameter16'
  if (!modelDeployment_DW.obj_pc.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter16'

  // Terminate for MATLABSystem: '<S83>/Read Parameter22'
  if (!modelDeployment_DW.obj_cy.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_cy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter22'

  // Terminate for MATLABSystem: '<S83>/Read Parameter29'
  if (!modelDeployment_DW.obj_a5.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_a5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter29'

  // Terminate for MATLABSystem: '<S83>/Read Parameter35'
  if (!modelDeployment_DW.obj_i.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter35'

  // Terminate for MATLABSystem: '<S83>/Read Parameter3'
  if (!modelDeployment_DW.obj_ci.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ci.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter3'

  // Terminate for MATLABSystem: '<S83>/Read Parameter9'
  if (!modelDeployment_DW.obj_lu.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_lu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter9'

  // Terminate for MATLABSystem: '<S83>/Read Parameter17'
  if (!modelDeployment_DW.obj_fq.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_fq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter17'

  // Terminate for MATLABSystem: '<S83>/Read Parameter23'
  if (!modelDeployment_DW.obj_h3.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_h3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter23'

  // Terminate for MATLABSystem: '<S83>/Read Parameter30'
  if (!modelDeployment_DW.obj_dx.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_dx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter30'

  // Terminate for MATLABSystem: '<S83>/Read Parameter26'
  if (!modelDeployment_DW.obj_hx.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_hx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter26'

  // Terminate for MATLABSystem: '<S83>/Read Parameter4'
  if (!modelDeployment_DW.obj_b3.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_b3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter4'

  // Terminate for MATLABSystem: '<S83>/Read Parameter10'
  if (!modelDeployment_DW.obj_fx.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_fx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter10'

  // Terminate for MATLABSystem: '<S83>/Read Parameter18'
  if (!modelDeployment_DW.obj_bm.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_bm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter18'

  // Terminate for MATLABSystem: '<S83>/Read Parameter14'
  if (!modelDeployment_DW.obj_dc.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_dc.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter14'

  // Terminate for MATLABSystem: '<S83>/Read Parameter31'
  if (!modelDeployment_DW.obj_mu.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter31'

  // Terminate for MATLABSystem: '<S83>/Read Parameter27'
  if (!modelDeployment_DW.obj_kz.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_kz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter27'

  // Terminate for MATLABSystem: '<S83>/Read Parameter5'
  if (!modelDeployment_DW.obj_bq.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_bq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter5'

  // Terminate for MATLABSystem: '<S83>/Read Parameter11'
  if (!modelDeployment_DW.obj_ns.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ns.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter11'

  // Terminate for MATLABSystem: '<S83>/Read Parameter19'
  if (!modelDeployment_DW.obj_mz.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_mz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter19'

  // Terminate for MATLABSystem: '<S83>/Read Parameter15'
  if (!modelDeployment_DW.obj_my.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_my.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S83>/Read Parameter15'

  // Terminate for MATLABSystem: '<S35>/SourceBlock'
  if (!modelDeployment_DW.obj_m.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_m.isInitialized == 1) &&
        modelDeployment_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&modelDeployment_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S35>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/Read Parameter1'
  if (!modelDeployment_DW.obj_n.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Read Parameter1'

  // Terminate for MATLABSystem: '<S23>/SourceBlock'
  if (!modelDeployment_DW.obj_j.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_j.isInitialized == 1) &&
        modelDeployment_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&modelDeployment_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S23>/SourceBlock'

  // Terminate for MATLABSystem: '<S21>/SourceBlock'
  if (!modelDeployment_DW.obj_k.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_k.isInitialized == 1) &&
        modelDeployment_DW.obj_k.isSetupComplete) {
      uORB_read_terminate(&modelDeployment_DW.obj_k.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S21>/SourceBlock'

  // Terminate for Enabled SubSystem: '<S1>/EnableController'
  // Terminate for MATLABSystem: '<S8>/Read Parameter1'
  if (!modelDeployment_DW.obj_pq.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter1'

  // Terminate for MATLABSystem: '<S8>/Read Parameter'
  if (!modelDeployment_DW.obj_bi.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_bi.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Read Parameter'
  // End of Terminate for SubSystem: '<S1>/EnableController'

  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!modelDeployment_DW.obj_o.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_o.isInitialized == 1) &&
        modelDeployment_DW.obj_o.isSetupComplete) {
      for (i = 0; i < 12; i++) {
        modelDeployment_B.motorValues_e[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (modelDeployment_DW.obj_o.ValidMotorIdx[i]) {
          modelDeployment_B.motorValues_e[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (modelDeployment_DW.obj_o.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &modelDeployment_B.motorValues_e[0], &servoValues
                       [0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'

  // Terminate for MATLABSystem: '<S7>/PX4 Timestamp'
  if (!modelDeployment_DW.obj_or.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_or.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S146>/SinkBlock'
  if (!modelDeployment_DW.obj_jmm.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_jmm.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_jmm.isInitialized == 1) &&
        modelDeployment_DW.obj_jmm.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_jmm.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S146>/SinkBlock'

  // Terminate for MATLABSystem: '<S135>/SinkBlock'
  if (!modelDeployment_DW.obj_ib.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_ib.isInitialized == 1) &&
        modelDeployment_DW.obj_ib.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_ib.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S135>/SinkBlock'

  // Terminate for MATLABSystem: '<S136>/SinkBlock'
  if (!modelDeployment_DW.obj_ff4.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ff4.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_ff4.isInitialized == 1) &&
        modelDeployment_DW.obj_ff4.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_ff4.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S136>/SinkBlock'

  // Terminate for MATLABSystem: '<S138>/SinkBlock'
  if (!modelDeployment_DW.obj_ht.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ht.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_ht.isInitialized == 1) &&
        modelDeployment_DW.obj_ht.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_ht.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S138>/SinkBlock'

  // Terminate for MATLABSystem: '<S139>/SinkBlock'
  if (!modelDeployment_DW.obj_md.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_md.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_md.isInitialized == 1) &&
        modelDeployment_DW.obj_md.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_md.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S139>/SinkBlock'

  // Terminate for MATLABSystem: '<S140>/SinkBlock'
  if (!modelDeployment_DW.obj_pj.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_pj.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_pj.isInitialized == 1) &&
        modelDeployment_DW.obj_pj.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_pj.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S140>/SinkBlock'

  // Terminate for MATLABSystem: '<S141>/SinkBlock'
  if (!modelDeployment_DW.obj_myb.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_myb.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_myb.isInitialized == 1) &&
        modelDeployment_DW.obj_myb.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_myb.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S141>/SinkBlock'

  // Terminate for MATLABSystem: '<S143>/SinkBlock'
  if (!modelDeployment_DW.obj_p4.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_p4.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_p4.isInitialized == 1) &&
        modelDeployment_DW.obj_p4.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_p4.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S143>/SinkBlock'

  // Terminate for MATLABSystem: '<S144>/SinkBlock'
  if (!modelDeployment_DW.obj_cjd.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_cjd.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_cjd.isInitialized == 1) &&
        modelDeployment_DW.obj_cjd.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_cjd.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S144>/SinkBlock'

  // Terminate for MATLABSystem: '<S145>/SinkBlock'
  if (!modelDeployment_DW.obj_o5o.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_o5o.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_o5o.isInitialized == 1) &&
        modelDeployment_DW.obj_o5o.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_o5o.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S145>/SinkBlock'

  // Terminate for MATLABSystem: '<S142>/SinkBlock'
  if (!modelDeployment_DW.obj_ida.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ida.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_ida.isInitialized == 1) &&
        modelDeployment_DW.obj_ida.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_ida.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S142>/SinkBlock'

  // Terminate for MATLABSystem: '<S137>/SinkBlock'
  if (!modelDeployment_DW.obj_ii.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_ii.isInitialized == 1) &&
        modelDeployment_DW.obj_ii.isSetupComplete) {
      uORB_write_terminate(&modelDeployment_DW.obj_ii.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S137>/SinkBlock'

  // Terminate for MATLABSystem: '<S85>/Read Parameter'
  if (!modelDeployment_DW.obj_mw.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_mw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S85>/Read Parameter'

  // Terminate for MATLABSystem: '<S85>/Read Parameter1'
  if (!modelDeployment_DW.obj_b.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S85>/Read Parameter1'

  // Terminate for MATLABSystem: '<S85>/Read Parameter2'
  if (!modelDeployment_DW.obj_p.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S85>/Read Parameter2'

  // Terminate for MATLABSystem: '<S85>/Read Parameter3'
  if (!modelDeployment_DW.obj_l.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S85>/Read Parameter3'

  // Terminate for MATLABSystem: '<S85>/Read Parameter4'
  if (!modelDeployment_DW.obj_d5.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_d5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S85>/Read Parameter4'

  // Terminate for MATLABSystem: '<S85>/Read Parameter5'
  if (!modelDeployment_DW.obj_eu.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_eu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S85>/Read Parameter5'

  // Terminate for MATLABSystem: '<S22>/SourceBlock'
  if (!modelDeployment_DW.obj_e.matlabCodegenIsDeleted) {
    modelDeployment_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((modelDeployment_DW.obj_e.isInitialized == 1) &&
        modelDeployment_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&modelDeployment_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S22>/SourceBlock'
}

const char_T** RT_MODEL_modelDeployment_T::getErrorStatusPointer()
{
  return &errorStatus;
}

const char_T* RT_MODEL_modelDeployment_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_modelDeployment_T::setErrorStatus(const char_T* const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
