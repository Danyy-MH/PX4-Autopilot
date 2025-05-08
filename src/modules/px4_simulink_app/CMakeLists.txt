## This cmakelist.txt file was generated from
## the UAV Toolbox Support Package for PX4 Autopilots

set(MAVLINK_LIBRARY_DIR "${CMAKE_BINARY_DIR}/mavlink")
set(MAVLINK_DIALECT_UAVIONIX "uAvionix")

add_definitions(
-DMODEL=modelDeployment -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DPX4 -DFMUv6c -DNULL=0 -DMW_PX4_NUTTX_BUILD -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -D__linux__ -DXCP_PLATFORM_LINUX_NO_PIE_SUPPORT -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT )

px4_add_module(
    MODULE modules__px4_simulink_app
    MAIN px4_simulink_app
    STACK_MAIN 2000
SRCS
   MW_ParameterRead.cpp
   MW_PX4_ActuatorDevice.cpp
   MW_PX4_Actuators.cpp
   MW_uORB_Read.cpp
   MW_uORB_Write.cpp
   ert_main.cpp
   modelDeployment.cpp
   modelDeployment_data.cpp
   MW_PX4_TaskControl.cpp
   nuttxinitialize.cpp
   FxTDiffSim.cpp
   FxTESO.cpp
   FxTESO_Quaternion.cpp
   FxtD_Quaternion.cpp
   asgsm.cpp
   asgsm_data.cpp
   asgsm_obs.cpp
   asgsm_obs_data.cpp
   asgsm_quat_obs.cpp
   asgsm_quaternion.cpp
   pdGc.cpp
   pdGc_data.cpp
   rtGetInf.cpp
   rtGetNaN.cpp
   rt_nonfinite.cpp
   rt_powd_snf.cpp
   xaxpy_8Bk0aMTr.cpp
   xaxpy_hLW3vASe.cpp
   xaxpy_l5uLg2P0.cpp
   xdotc_kGz03SeF.cpp
   xswap_nAn5Zpao.cpp
   norm_07B1VLxa.cpp
    COMPILE_FLAGS
       -fpermissive
       -Wno-narrowing
       -Wno-address-of-packed-member 
       -Wno-cast-align
    INCLUDES
       ${PX4_SOURCE_DIR}/src/modules/mavlink
       ${MAVLINK_LIBRARY_DIR}
       ${MAVLINK_LIBRARY_DIR}/${CONFIG_MAVLINK_DIALECT}
       ${MAVLINK_LIBRARY_DIR}/${MAVLINK_DIALECT_UAVIONIX}
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/pdGc
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/asgsm_quaternion
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/asgsm_quat_obs
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/asgsm_obs
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/asgsm
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/FxtD_Quaternion
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/FxTESO_Quaternion
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/FxTESO
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/FxTDiffSim
       /home/danyy/Documents/PX4-Controllers/codeGen
       /home/danyy/Documents/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/px4/core/include
       /home/danyy/Documents/PX4-Controllers/codeGen/modelDeployment_ert_rtw
       /usr/local/MATLAB/R2024b/extern/include
       /usr/local/MATLAB/R2024b/simulink/include
       /usr/local/MATLAB/R2024b/rtw/c/src
       /usr/local/MATLAB/R2024b/rtw/c/src/ext_mode/common
       /usr/local/MATLAB/R2024b/rtw/c/ert
       /usr/local/MATLAB/R2024b/toolbox/dsp/dsp/include
       /usr/local/MATLAB/R2024b/toolbox/dsp/dsp/extern/src/export/include/src
       /usr/local/MATLAB/R2024b/toolbox/dsp/dsp/extern/src/export/include
       /usr/local/MATLAB/R2024b/toolbox/shared/dsp/vision/matlab/include
       /home/danyy/Documents/PX4-Controllers/codeGen/slprj/ert/_sharedutils
)

get_target_property(PX4_SL_APP_COMPILE_FLAGS modules__px4_simulink_app COMPILE_OPTIONS)
list(REMOVE_ITEM PX4_SL_APP_COMPILE_FLAGS -Werror)
set_target_properties(modules__px4_simulink_app PROPERTIES COMPILE_OPTIONS "${PX4_SL_APP_COMPILE_FLAGS}")

