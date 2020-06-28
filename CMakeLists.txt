if(CONFIG_UC_USBH)
	zephyr_library()

	zephyr_include_directories(Source/uc-cpu Source/uc-lib HCD/ATSAMx zephyr Source)

	zephyr_library_sources(
		Source/usbh_class.c
		Source/usbh_core.c
		Source/usbh_hub.c
		zephyr/usbh_os.c
		Source/uc-lib/lib_math.c
		Source/uc-lib/lib_mem.c
		Source/uc-lib/lib_str.c
		Source/uc-cpu/cpu_core.c
		zephyr/usbh_hc_cfg.c
		Source/uc-lib/lib_ascii.c
		zephyr/bsp_usbh_template.c
		# Host Controller Driver 
		HCD/ATSAMx/usbh_hcd_atsamx.c
	)
endif()
