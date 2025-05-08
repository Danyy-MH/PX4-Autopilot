//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xdotc_kGz03SeF.cpp
//
// Code generated for Simulink model 'FxTESO_Quaternion'.
//
// Model version                  : 1.48
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:26 2025
//
#include "rtwtypes.h"
#include "xdotc_kGz03SeF.h"

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
real_T xdotc_kGz03SeF(int32_T n, const real_T x[9], int32_T ix0, const real_T y
                      [9], int32_T iy0)
{
  real_T d;
  int32_T b;
  d = 0.0;
  b = static_cast<uint8_T>(n);
  for (int32_T k = 0; k < b; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }

  return d;
}

//
// File trailer for generated code.
//
// [EOF]
//
