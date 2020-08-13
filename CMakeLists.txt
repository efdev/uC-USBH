if(CONFIG_UC_USBH)
	zephyr_library()
	zephyr_library_sources_ifdef(CONFIG_UC_USBH_MSC			Class/MSC/usbh_msc.c)

	#samr21 board support package and host controller driver
	zephyr_library_sources_ifdef(CONFIG_BOARD_ATSAMR21_XPRO		HCD/ATSAMx/usbh_hcd_atsamx.c)
	zephyr_library_sources_ifdef(CONFIG_BOARD_ATSAMR21_XPRO		zephyr/bsp/bsp_usbh_samr21.c)

	zephyr_include_directories(HCD/ATSAMx Class/MSC zephyr/bsp zephyr Source)

	zephyr_library_sources(
		Source/usbh_class.c
		Source/usbh_core.c
		Source/usbh_hub.c		
		zephyr/usbh_os.c
		zephyr/usbh_hc_cfg.c		
	)
endif()
