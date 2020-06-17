if(CONFIG_UC_USBH)
	zephyr_library()

	zephyr_include_directories(zephyr/uc-cpu zephyr/uc-lib HCD/STM32F_FS zephyr Source)

	zephyr_library_sources(
		Source/usbh_class.c
		Source/usbh_core.c
		Source/usbh_hub.c
		Source/usbh_os.c
		zephyr/uc-lib/lib_math.c
		zephyr/uc-lib/lib_mem.c
		zephyr/uc-lib/lib_str.c
		zephyr/uc-cpu/cpu_core.c
		zephyr/usbh_hc_cfg.c
		zephyr/uc-lib/lib_ascii.c

		# Host Controller Driver 
		HCD/STM32F_FS/usbh_hcd_stm32fx_fs.c
		#zephyr/cpu_a.s
	)
endif()
