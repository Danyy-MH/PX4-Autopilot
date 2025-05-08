//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xaxpy_8Bk0aMTr.cpp
//
// Code generated for Simulink model 'FxTESO_Quaternion'.
//
// Model version                  : 1.48
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 23 20:30:26 2025
//
#include "rtwtypes.h"
#include "xaxpy_8Bk0aMTr.h"

// Function for MATLAB Function: '<Root>/calculateCvMatrix1'
void xaxpy_8Bk0aMTr(int32_T n, real_T a, const real_T x[9], int32_T ix0, real_T
                    y[3], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
