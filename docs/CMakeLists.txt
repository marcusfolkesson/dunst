
add_custom_target(man ALL)

add_custom_command(
		TARGET man
		COMMAND pod2man ARGS -s 1 -c "Dunst manual" ${CMAKE_SOURCE_DIR}/README.pod ${CMAKE_CURRENT_BINARY_DIR}/dunst.1
		OUTPUTS ${CMAKE_CURRENT_BINARY_DIR}/dunst.1
		)

add_custom_command(
		TARGET man
		DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/dunst.1
		)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/dunst.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)

