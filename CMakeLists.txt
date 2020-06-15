if(CONFIG_UC_USBH)
	zephyr_library()

	zephyr_include_directories(zephyr Source)

	zephyr_library_sources(
		Source/usbh_class.c
		Source/usbh_core.c
		Source/usbh_hub.c
		Source/usbh_os.c
		#zephyr/.c
	)
endif()
