px4_add_module(
	MODULE modules__fah_ctrl
	MAIN fah_ctrl
	SRCS
		fah_ctrl.cpp
	MODULE_CONFIG
		module.yaml
		asgsm.yaml
	)
