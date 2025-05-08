#pragma once

#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <uORB/SubscriptionInterval.hpp>
#include <uORB/topics/parameter_update.h>

using namespace time_literals;

extern "C" __EXPORT int fah_obs_main(int argc, char *argv[]);

class FAH_OBS : public ModuleBase<FAH_OBS>, public ModuleParams
{
public:
    FAH_OBS(int example_param, bool example_flag);

    virtual ~FAH_OBS() = default;

    static int task_spawn(int argc, char *argv[]);

    static FAH_OBS *instantiate(int argc, char *argv[]);

    static int print_usage(const char *reason = nullptr);

    static int custom_command(int argc, char *argv[]);

    void run() override;

    int print_status() override;

private:
void parameters_update(bool force = false);

    DEFINE_PARAMETERS(
        (ParamFloat<px4::params::FAH_SOF_X>) _fah_sof_x,
        (ParamFloat<px4::params::FAH_SOF_Y>) _fah_sof_y,
        (ParamFloat<px4::params::FAH_SOF_Z>) _fah_sof_z,
        (ParamFloat<px4::params::FAH_SOF_ROLL>) _fah_sof_roll,
        (ParamFloat<px4::params::FAH_SOF_PITCH>) _fah_sof_pitch,
        (ParamFloat<px4::params::FAH_SOF_YAW>) _fah_sof_yaw,

	(ParamFloat<px4::params::X_G1>) _x_g1,
	(ParamFloat<px4::params::X_G2>) _x_g2,
	(ParamFloat<px4::params::X_VPI>) _x_vpi,
	(ParamFloat<px4::params::X_VRHO>) _x_vrho,
	(ParamFloat<px4::params::Y_G1>) _y_g1,
	(ParamFloat<px4::params::Y_G2>) _y_g2,
	(ParamFloat<px4::params::Y_VPI>) _y_vpi,
	(ParamFloat<px4::params::Y_VRHO>) _y_vrho,
	(ParamFloat<px4::params::Z_G1>) _z_g1,
	(ParamFloat<px4::params::Z_G2>) _z_g2,
	(ParamFloat<px4::params::Z_VPI>) _z_vpi,
	(ParamFloat<px4::params::Z_VRHO>) _z_vrho,
	(ParamFloat<px4::params::ROLL_G1>) _roll_g1,
	(ParamFloat<px4::params::ROLL_G2>) _roll_g2,
	(ParamFloat<px4::params::ROLL_VPI>) _roll_vpi,
	(ParamFloat<px4::params::ROLL_VRHO>) _roll_vrho,
	(ParamFloat<px4::params::PITCH_G1>) _pitch_g1,
	(ParamFloat<px4::params::PITCH_G2>) _pitch_g2,
	(ParamFloat<px4::params::PITCH_VPI>) _pitch_vpi,
	(ParamFloat<px4::params::PITCH_VRHO>) _pitch_vrho,
	(ParamFloat<px4::params::YAW_G1>) _yaw_g1,
	(ParamFloat<px4::params::YAW_G2>) _yaw_g2,
	(ParamFloat<px4::params::YAW_VPI>) _yaw_vpi,
	(ParamFloat<px4::params::YAW_VRHO>) _yaw_vrho,
	(ParamFloat<px4::params::X_MU1>) _x_mu1,
	(ParamFloat<px4::params::X_MU2>) _x_mu2,
	(ParamFloat<px4::params::X_MU3>) _x_mu3,
	(ParamFloat<px4::params::X_MU4>) _x_mu4,
	(ParamFloat<px4::params::X_ALPHA>) _x_alpha,
	(ParamFloat<px4::params::X_BETA>) _x_beta,

	(ParamFloat<px4::params::Y_MU1>) _y_mu1,
	(ParamFloat<px4::params::Y_MU2>) _y_mu2,
	(ParamFloat<px4::params::Y_MU3>) _y_mu3,
	(ParamFloat<px4::params::Y_MU4>) _y_mu4,
	(ParamFloat<px4::params::Y_ALPHA>) _y_alpha,
	(ParamFloat<px4::params::Y_BETA>) _y_beta,

	(ParamFloat<px4::params::Z_MU1>) _z_mu1,
	(ParamFloat<px4::params::Z_MU2>) _z_mu2,
	(ParamFloat<px4::params::Z_MU3>) _z_mu3,
	(ParamFloat<px4::params::Z_MU4>) _z_mu4,
	(ParamFloat<px4::params::Z_ALPHA>) _z_alpha,
	(ParamFloat<px4::params::Z_BETA>) _z_beta,

	(ParamFloat<px4::params::ROLL_MU1>) _roll_mu1,
	(ParamFloat<px4::params::ROLL_MU2>) _roll_mu2,
	(ParamFloat<px4::params::ROLL_MU3>) _roll_mu3,
	(ParamFloat<px4::params::ROLL_MU4>) _roll_mu4,
	(ParamFloat<px4::params::ROLL_ALPHA>) _roll_alpha,
	(ParamFloat<px4::params::ROLL_BETA>) _roll_beta,

	(ParamFloat<px4::params::PITCH_MU1>) _pitch_mu1,
	(ParamFloat<px4::params::PITCH_MU2>) _pitch_mu2,
	(ParamFloat<px4::params::PITCH_MU3>) _pitch_mu3,
	(ParamFloat<px4::params::PITCH_MU4>) _pitch_mu4,
	(ParamFloat<px4::params::PITCH_ALPHA>) _pitch_alpha,
	(ParamFloat<px4::params::PITCH_BETA>) _pitch_beta,

	(ParamFloat<px4::params::YAW_MU1>) _yaw_mu1,
	(ParamFloat<px4::params::YAW_MU2>) _yaw_mu2,
	(ParamFloat<px4::params::YAW_MU3>) _yaw_mu3,
	(ParamFloat<px4::params::YAW_MU4>) _yaw_mu4,
	(ParamFloat<px4::params::YAW_ALPHA>) _yaw_alpha,
	(ParamFloat<px4::params::YAW_BETA>) _yaw_beta,
	(ParamFloat<px4::params::CTRL2>) _ctrl2,
	(ParamFloat<px4::params::CTRL3>) _ctrl3  


	)

    uORB::SubscriptionInterval _parameter_update_sub{ORB_ID(parameter_update), 1_s};
};
