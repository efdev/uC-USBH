if(CONFIG_UC_USBH)
	zephyr_library()

	zephyr_include_directories(Source/MSC Source/uc-lib HCD/ATSAMx zephyr Source)
#Source/uc-cpu Source/uc-lib 
	zephyr_library_sources(
		Source/usbh_class.c
		Source/usbh_core.c
		Source/usbh_hub.c

		Source/MSC/usbh_msc.c
		# Source/HID/usbh_hid.c
		# Source/HID/usbh_hidparser.c
		# App/HID/app_usbh_hid.c
		# App/HID/app_usbh_keyboard.c
		# App/HID/app_usbh_mouse.c
		# App/HID/app_usbh_mouse.c
		zephyr/usbh_os.c
		Source/uc-lib/lib_mem.c
		zephyr/usbh_hc_cfg.c
		#Source/uc-lib/lib_ascii.c
		zephyr/bsp_usbh_template.c
		# Host Controller Driver 
		HCD/ATSAMx/usbh_hcd_atsamx.c
	)
endif()
