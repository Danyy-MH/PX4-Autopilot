//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xswap_nAn5Zpao.cpp
//
// Code generated for Simulink model 'FxTESO_Quaternion'.
//
// Model version                  : 1.48
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:26 2025
//
#include "rtwtypes.h"
#include "xswap_nAn5Zpao.h"

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
void xswap_nAn5Zpao(real_T x[9], int32_T ix0, int32_T iy0)
{
  real_T temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
  temp = x[ix0 + 1];
  x[ix0 + 1] = x[iy0 + 1];
  x[iy0 + 1] = temp;
}

//
// File trailer for generated code.
//
// [EOF]
//
