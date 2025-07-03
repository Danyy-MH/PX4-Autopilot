//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: modelDeployment_data.cpp
//
// Code generated for Simulink model 'modelDeployment'.
//
// Model version                  : 1.215
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Mon Jun  9 16:25:09 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "modelDeployment.h"

// Model block global parameters (default storage)
real_T rtP_allo_i[36] = { -107304.11993402323, 107304.11993402334,
  -1.5886087413330681E-10, -107304.11993402311, 107304.11993402295,
  2.1922179910456044E-10, 61952.062529064, 61952.062529064526,
  -123904.12505812863, 61952.062529064213, 61952.062529063871,
  -123904.12505812802, 22548.706711977913, 22548.706711977939,
  22548.706711977891, 22548.706711977888, 22548.70671197792, 22548.706711977888,
  147334.91126708986, 147334.91126708995, 8.2130727548522041E-11,
  -147334.91126708998, -147334.91126708998, 7.9125094516733991E-11,
  -85063.850681084, 85063.850681084019, 170127.70136216795, 85063.850681084063,
  -85063.850681084077, -170127.70136216798, 201705.64801604467,
  -201705.64801604452, 201705.64801604446, -201705.64801604481,
  201705.64801604467, -201705.64801604449 } ;// Variable: allo_i
                                                //  Referenced by: '<S11>/Tmotor_10inch_allo_inv'


real_T rtP_coeff[3] = { -2.4168381002751213E-10, 0.0010250826774979823,
  1079.6636136839952 } ;               // Variable: coeff
                                          //  Referenced by: '<S2>/Constant'


// Block parameters (default storage)
P_modelDeployment_T modelDeployment_P = {
  // Mask Parameter: DirectionCosineMatrixtoRotation
  //  Referenced by:
  //    '<S64>/Constant'
  //    '<S66>/Constant'

  4.4408920985006262E-16,

  // Mask Parameter: DirectionCosineMatrixtoRotati_l
  //  Referenced by:
  //    '<S43>/Constant'
  //    '<S53>/Constant'
  //    '<S55>/Constant'

  1U,

  // Computed Parameter: data_out_Outport_2_Y0
  //  Referenced by:

  {
    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // Fu

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // e

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // e_dot

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // sigma

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // kt

      {
        0.0, 0.0, 0.0, 0.0 }
      // qe
    },                                 // Fu

    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // pos_hat

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // pos_dot_hat

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // pos_ddot_hat

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // e_hat

      {
        0.0, 0.0, 0.0, 0.0 }
      ,                                // q_hat

      {
        0.0, 0.0, 0.0, 0.0 }
      // q_tilde
    },                                 // state_hat

    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // qd

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // qd_dot

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // qd_ddot

      {
        0.0, 0.0, 0.0, 0.0 }
      // quaternion_d
    },                                 // qd

    {
      0.0, 0.0, 0.0 }
    ,                                  // pos

    {
      0.0, 0.0, 0.0 }
    // att
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S27>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S23>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S26>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S22>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S125>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // q0d
    0.0F,                              // q1d
    0.0F,                              // q2d
    0.0F,                              // q3d
    0.0F,                              // q0hat
    0.0F,                              // q1hat
    0.0F,                              // q2hat
    0.0F,                              // q3hat
    0.0F,                              // q0e
    0.0F,                              // q1e
    0.0F,                              // q2e
    0.0F,                              // q3e
    0.0F,                              // q0ehat
    0.0F,                              // q1ehat
    0.0F,                              // q2ehat
    0.0F                               // q3ehat
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S36>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S35>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S25>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S21>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S131>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // xd
    0.0F,                              // yd
    0.0F,                              // zd
    0.0F,                              // phid
    0.0F,                              // thetad
    0.0F                               // psid
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S129>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // ex
    0.0F,                              // ey
    0.0F,                              // ez
    0.0F,                              // ephi
    0.0F,                              // etheta
    0.0F                               // epsi
  },

  // Computed Parameter: Constant_Value_pw
  //  Referenced by: '<S134>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // ehatx
    0.0F,                              // ehaty
    0.0F,                              // ehatz
    0.0F,                              // ehatroll
    0.0F,                              // ehatpitch
    0.0F                               // ehatyaw
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S124>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // xhat
    0.0F,                              // yhat
    0.0F,                              // zhat
    0.0F,                              // phihat
    0.0F,                              // thetahat
    0.0F                               // psihat
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S128>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // xhatdot
    0.0F,                              // yhatdot
    0.0F,                              // zhatdot
    0.0F,                              // phihatdot
    0.0F,                              // thetahatdot
    0.0F                               // psihatdot
  },

  // Computed Parameter: Constant_Value_oy
  //  Referenced by: '<S126>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // gamma3_x
    0.0F,                              // gamma3_y
    0.0F,                              // gamma3_z
    0.0F,                              // gamma3_phi
    0.0F,                              // gamma3_theta
    0.0F                               // gamma3_psi
  },

  // Computed Parameter: Constant_Value_dw
  //  Referenced by: '<S123>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // fx
    0.0F,                              // fy
    0.0F,                              // fz
    0.0F,                              // tau_x
    0.0F,                              // tau_y
    0.0F                               // tau_z
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S133>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // ktx
    0.0F,                              // kty
    0.0F,                              // ktz
    0.0F,                              // ktroll
    0.0F,                              // ktpitch
    0.0F                               // ktyaw
  },

  // Computed Parameter: Constant_Value_ms
  //  Referenced by: '<S127>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // phi
    0.0F,                              // theta
    0.0F                               // psi
  },

  // Computed Parameter: Constant_Value_eo
  //  Referenced by: '<S130>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // pwm1
    0.0F,                              // pwm2
    0.0F,                              // pwm3
    0.0F,                              // pwm4
    0.0F,                              // pwm5
    0.0F                               // pwm6
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S132>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // sigmax
    0.0F,                              // sigmay
    0.0F,                              // sigmaz
    0.0F,                              // sigmaroll
    0.0F,                              // sigmapitch
    0.0F                               // sigmayaw
  },

  // Computed Parameter: omega2_Y0
  //  Referenced by: '<S8>/omega2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Unit Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Unit Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Unit Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Unit Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Unit Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S8>/Unit Delay'

  0.0,

  // Computed Parameter: Merge1_1_InitialOutput
  //  Referenced by: '<S8>/Merge1'

  0.0,

  // Computed Parameter: Merge1_2_InitialOutput
  //  Referenced by: '<S8>/Merge1'

  0.0,

  // Computed Parameter: Merge1_3_InitialOutput
  //  Referenced by: '<S8>/Merge1'

  0.0,

  // Computed Parameter: Merge1_4_InitialOutput
  //  Referenced by: '<S8>/Merge1'

  0.0,

  // Computed Parameter: Merge1_5_InitialOutput
  //  Referenced by: '<S8>/Merge1'

  0.0,

  // Computed Parameter: Merge1_6_InitialOutput
  //  Referenced by: '<S8>/Merge1'

  0.0,

  // Computed Parameter: Merge_1_InitialOutput
  //  Referenced by: '<S8>/Merge'

  0.0,

  // Computed Parameter: Merge_2_InitialOutput
  //  Referenced by: '<S8>/Merge'

  0.0,

  // Computed Parameter: Merge_3_InitialOutput
  //  Referenced by: '<S8>/Merge'

  0.0,

  // Computed Parameter: Merge_4_InitialOutput
  //  Referenced by: '<S8>/Merge'

  0.0,

  // Computed Parameter: Merge_5_InitialOutput
  //  Referenced by: '<S8>/Merge'

  0.0,

  // Computed Parameter: Merge_6_InitialOutput
  //  Referenced by: '<S8>/Merge'

  0.0,

  // Expression: 1
  //  Referenced by: '<S49>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S50>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S45>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S46>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S55>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S53>/Constant1'

  0.0,

  // Expression: -eye(3)
  //  Referenced by: '<S56>/Bias1'

  { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 },

  // Expression: -1
  //  Referenced by: '<S57>/Bias'

  -1.0,

  // Computed Parameter: Out1_Y0_iz
  //  Referenced by: '<S87>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S87>/Memory'

  0.0,

  // Expression: zeros(6, 10 )
  //  Referenced by: '<S93>/Polynomial Trajectory2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [zeros(2, 10);
  // 0 0.3 0.3 1.2 1.2 1.2 1.2 1.2 1.2 0.3;
  // zeros(3, 10)]
  //  Referenced by: '<S93>/Constant7'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3, 0.0, 0.0, 0.0 },

  // Expression: [ 0, 3, 6, 8, 15, 18, 21, 24, 34, 38]
  //  Referenced by: '<S93>/Constant8'

  { 0.0, 3.0, 6.0, 8.0, 15.0, 18.0, 21.0, 24.0, 34.0, 38.0 },

  // Expression: zeros(6, 1)
  //  Referenced by: '<S93>/Constant6'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: ones(6, 1) * 2
  //  Referenced by: '<S92>/Constant13'

  { 2.0, 2.0, 2.0, 2.0, 2.0, 2.0 },

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<S104>/Memory'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<S104>/Memory1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S104>/Discrete-Time Integrator'

  0.002,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<S104>/Discrete-Time Integrator'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S104>/Discrete-Time Integrator1'

  0.002,

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<S104>/Discrete-Time Integrator1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<S92>/Constant2'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6, 1)
  //  Referenced by: '<S92>/Constant6'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<S104>/zeta'

  2.0,

  // Expression: zeros(6, 21)
  //  Referenced by: '<S91>/Polynomial Trajectory3'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros( 6, 21)
  //  Referenced by: '<S91>/Polynomial Trajectory3'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [zeros(2, 21);
  // 0 0.3 0.3 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 0.3;
  // 0 0 0 0 0 0.2 0.2 0 0 -0.2 -0.2 0 0 0 0 0 0 0 0 0 0;
  // 0 0 0 0 0 0 0 0 0 0 0 0 0 0.2 0.2 0 0 -0.2 -0.2 0 0
  // zeros(1, 21)]
  //  Referenced by: '<S91>/Constant10'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.2, 0.2, 0.0, 0.0, 0.0, 0.0, 1.2, 0.2, 0.0, 0.0, 0.0, 0.0, 1.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, -0.2, 0.0, 0.0,
    0.0, 0.0, 1.2, -0.2, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.2, 0.0, 0.0, 0.0, 1.2, 0.0, 0.2, 0.0,
    0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2,
    0.0, -0.2, 0.0, 0.0, 0.0, 1.2, 0.0, -0.2, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.3, 0.0, 0.0, 0.0 },

  // Expression: [ 0, 3, 6, 8, 15, 17, 21, 23, 24, 26, 30, 32, 33, 35, 39, 41, 42, 44, 48, 50, 53]
  //  Referenced by: '<S91>/Constant11'

  { 0.0, 3.0, 6.0, 8.0, 15.0, 17.0, 21.0, 23.0, 24.0, 26.0, 30.0, 32.0, 33.0,
    35.0, 39.0, 41.0, 42.0, 44.0, 48.0, 50.0, 53.0 },

  // Expression: zeros(6, 1)
  //  Referenced by: '<S91>/Constant6'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros( 6, 6 )
  //  Referenced by: '<S90>/Polynomial Trajectory'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [zeros(2, 6);
  // 0 0.3 0.3 1.2 1.2 0.3;
  // zeros(3, 6);]
  //  Referenced by: '<S90>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.3, 0.0, 0.0, 0.0 },

  // Expression: [0, 3, 6, 8, 20, 22]
  //  Referenced by: '<S90>/Constant4'

  { 0.0, 3.0, 6.0, 8.0, 20.0, 22.0 },

  // Expression: zeros(6, 1)
  //  Referenced by: '<S90>/Constant'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<S90>/Constant2'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6, 12)
  //  Referenced by: '<S89>/Polynomial Trajectory3'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0 0 0 0 0 -0.5 0.5 0.5 -0.5 -0.5 0 0;
  // 0 0 0 0 0 0.5 0.5 -0.5 -0.5 0.5 0 0;
  // 0 0.3 0.3 1.2 1.2 1.2 1.2 1.2 1.2 1.2 1.2 0.3;
  // zeros(3, 12)]
  //  Referenced by: '<S89>/Constant10'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, 0.0, 0.0, 0.0,
    -0.5, 0.5, 1.2, 0.0, 0.0, 0.0, 0.5, 0.5, 1.2, 0.0, 0.0, 0.0, 0.5, -0.5, 1.2,
    0.0, 0.0, 0.0, -0.5, -0.5, 1.2, 0.0, 0.0, 0.0, -0.5, 0.5, 1.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3, 0.0, 0.0, 0.0 },

  // Expression: [ 0, 3, 6, 8, 15, 18, 21, 24, 27, 30, 33, 36]
  //  Referenced by: '<S89>/Constant11'

  { 0.0, 3.0, 6.0, 8.0, 15.0, 18.0, 21.0, 24.0, 27.0, 30.0, 33.0, 36.0 },

  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<S89>/Constant2'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6, 1)
  //  Referenced by: '<S89>/Constant9'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(2, 7)
  //  Referenced by: '<S94>/Polynomial Trajectory3'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0, 0.3, 0.3, 1.2, 1.2, 1.2, 0.3;
  // zeros(1, 7)]
  //  Referenced by: '<S94>/Constant1'

  { 0.0, 0.0, 0.3, 0.0, 0.3, 0.0, 1.2, 0.0, 1.2, 0.0, 1.2, 0.0, 0.3, 0.0 },

  // Expression: [0, 3, 6, 8, 11, 44, 47]
  //  Referenced by: '<S94>/Constant'

  { 0.0, 3.0, 6.0, 8.0, 11.0, 44.0, 47.0 },

  // Expression: [0; 0; 0; 0; 0; 0]
  //  Referenced by: '<S94>/Constant12'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: ones(5, 1) * 2
  //  Referenced by: '<S94>/Constant13'

  { 2.0, 2.0, 2.0, 2.0, 2.0 },

  // Expression: [0; 0; 0; 0; 0]
  //  Referenced by: '<S117>/Memory'

  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0; 0; 0; 0; 0]
  //  Referenced by: '<S117>/Memory1'

  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator_gainva_k
  //  Referenced by: '<S117>/Discrete-Time Integrator'

  0.002,

  // Expression: [0; 0; 0; 0; 0]
  //  Referenced by: '<S117>/Discrete-Time Integrator'

  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: DiscreteTimeIntegrator1_gainv_i
  //  Referenced by: '<S117>/Discrete-Time Integrator1'

  0.002,

  // Expression: [0; 0; 0; 0; 0]
  //  Referenced by: '<S117>/Discrete-Time Integrator1'

  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 2
  //  Referenced by: '<S117>/zeta'

  2.0,

  // Computed Parameter: Merge_InitialOutput
  //  Referenced by: '<S88>/Merge'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S24>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant3'

  0.0,

  // Expression: 1
  //  Referenced by: '<S24>/Constant2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S6>/Constant'

  1.0,

  // Expression: [1,1,-1]
  //  Referenced by: '<S4>/Gain1'

  { 1.0, 1.0, -1.0 },

  // Expression: [1;1;1;-1]'
  //  Referenced by: '<S4>/Gain'

  { 1.0, 1.0, 1.0, -1.0 },

  // Expression: 2
  //  Referenced by: '<S70>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S73>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S68>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S74>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S69>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S72>/Gain'

  2.0,

  // Expression: [-1 1 1]
  //  Referenced by: '<S42>/Gain1'

  { -1.0, 1.0, 1.0 },

  // Expression: [-1 1]
  //  Referenced by: '<S42>/Gain2'

  { -1.0, 1.0 },

  // Expression: [1 1]
  //  Referenced by: '<S42>/Gain3'

  { 1.0, 1.0 },

  // Expression: 2000
  //  Referenced by: '<S2>/Saturation'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S2>/Saturation'

  1000.0,

  // Expression: 1
  //  Referenced by: '<S2>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Saturation1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S24>/Constant4'

  1.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant5'

  0.0,

  // Computed Parameter: Assertion_Enabled
  //  Referenced by: '<S63>/Assertion'

  true,

  // Computed Parameter: Assertion_Enabled_c
  //  Referenced by: '<S61>/Assertion'

  true,

  // Computed Parameter: Assertion_Enabled_e
  //  Referenced by: '<S60>/Assertion'

  true,

  // Computed Parameter: Assertion_Enabled_l
  //  Referenced by: '<S58>/Assertion'

  true,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<S6>/Manual Switch1'

  0U,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<S6>/Manual Switch'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
