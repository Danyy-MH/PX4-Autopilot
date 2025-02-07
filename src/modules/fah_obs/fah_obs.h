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
        (ParamFloat<px4::params::FAH_SOF_YAW>) _fah_sof_yaw
        
	)

    uORB::SubscriptionInterval _parameter_update_sub{ORB_ID(parameter_update), 1_s};
};
