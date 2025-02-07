#pragma once

#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <uORB/SubscriptionInterval.hpp>
#include <uORB/topics/parameter_update.h>

using namespace time_literals;

extern "C" __EXPORT int fah_ctrl_main(int argc, char *argv[]);

class FAH_CTRL : public ModuleBase<FAH_CTRL>, public ModuleParams
{
public:
    FAH_CTRL(int example_param, bool example_flag);

    virtual ~FAH_CTRL() = default;

    static int task_spawn(int argc, char *argv[]);

    static FAH_CTRL *instantiate(int argc, char *argv[]);

    static int print_usage(const char *reason = nullptr);

    static int custom_command(int argc, char *argv[]);

    void run() override;

    int print_status() override;

private:
void parameters_update(bool force = false);

    DEFINE_PARAMETERS(
        (ParamFloat<px4::params::FAH_X_P>) _fah_x_p,
        (ParamFloat<px4::params::FAH_X_D>) _fah_x_d,
        (ParamFloat<px4::params::FAH_X_I>) _fah_x_i,
        (ParamFloat<px4::params::FAH_Y_P>) _fah_y_p,
        (ParamFloat<px4::params::FAH_Y_D>) _fah_y_d,
        (ParamFloat<px4::params::FAH_Y_I>) _fah_y_i,
        (ParamFloat<px4::params::FAH_Z_P>) _fah_z_p,
        (ParamFloat<px4::params::FAH_Z_D>) _fah_z_d,
        (ParamFloat<px4::params::FAH_Z_I>) _fah_z_i,
        
        (ParamFloat<px4::params::FAH_ROLL_P>) _fah_roll_p,
        (ParamFloat<px4::params::FAH_ROLL_I>) _fah_roll_i,
        (ParamFloat<px4::params::FAH_ROLL_D>) _fah_roll_d,
        (ParamFloat<px4::params::FAH_PITCH_P>) _fah_pitch_p,
        (ParamFloat<px4::params::FAH_PITCH_I>) _fah_pitch_i,
        (ParamFloat<px4::params::FAH_PITCH_D>) _fah_pitch_d,
        (ParamFloat<px4::params::FAH_YAW_P>) _fah_yaw_p,
        (ParamFloat<px4::params::FAH_YAW_I>) _fah_yaw_i,
        (ParamFloat<px4::params::FAH_YAW_D>) _fah_yaw_d,
        
        (ParamFloat<px4::params::FAH_MASS>) _fah_mass,
        (ParamFloat<px4::params::FAH_I_XX>) _fah_i_xx,
        (ParamFloat<px4::params::FAH_I_YY>) _fah_i_yy,
        (ParamFloat<px4::params::FAH_I_ZZ>) _fah_i_zz,
	(ParamFloat<px4::params::FAH_ALT_DES>) _fah_alt_des,
	(ParamFloat<px4::params::FAH_X_DES>) _fah_x_des,
	(ParamFloat<px4::params::FAH_Y_DES>) _fah_y_des,
	(ParamInt<px4::params::TRAJ_SEL>) _traj_sel,
	(ParamInt<px4::params::CTRL_SEL>) _ctrl_sel,

	(ParamFloat<px4::params::X_XI1>) _x_xi1,
	(ParamFloat<px4::params::X_XI2>) _x_xi2,
	(ParamFloat<px4::params::X_LAM1>) _x_lam1,
	(ParamFloat<px4::params::X_LAM2>) _x_lam2,
	(ParamFloat<px4::params::X_ALPHA_U>) _x_alpha_u,
	(ParamFloat<px4::params::X_BETA_U>) _x_beta_u,
	(ParamFloat<px4::params::X_EPS_U>) _x_eps_u,

	(ParamFloat<px4::params::Y_XI1>) _y_xi1,
	(ParamFloat<px4::params::Y_XI2>) _y_xi2,
	(ParamFloat<px4::params::Y_LAM1>) _y_lam1,
	(ParamFloat<px4::params::Y_LAM2>) _y_lam2,
	(ParamFloat<px4::params::Y_ALPHA_U>) _y_alpha_u,
	(ParamFloat<px4::params::Y_BETA_U>) _y_beta_u,
	(ParamFloat<px4::params::Y_EPS_U>) _y_eps_u,

	(ParamFloat<px4::params::Z_XI1>) _z_xi1,
	(ParamFloat<px4::params::Z_XI2>) _z_xi2,
	(ParamFloat<px4::params::Z_LAM1>) _z_lam1,
	(ParamFloat<px4::params::Z_LAM2>) _z_lam2,
	(ParamFloat<px4::params::Z_ALPHA_U>) _z_alpha_u,
	(ParamFloat<px4::params::Z_BETA_U>) _z_beta_u,
	(ParamFloat<px4::params::Z_EPS_U>) _z_eps_u

    )

    uORB::SubscriptionInterval _parameter_update_sub{ORB_ID(parameter_update), 1_s};
};
