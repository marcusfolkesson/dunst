
set( DBUS_SERVICES_PATH "share/dbus-1/services"
	CACHE STRING "Path to DBUS services"
	)
install( FILES dunst.service
		DESTINATION ${DBUS_SERVICES_PATH}
		)
