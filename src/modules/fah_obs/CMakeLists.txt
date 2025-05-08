px4_add_module(
	MODULE modules__fah_obs
	MAIN fah_obs
	SRCS
		fah_obs.cpp
	MODULE_CONFIG
		module.yaml
		fxtdiff.yaml
		fxteso.yaml
	)
