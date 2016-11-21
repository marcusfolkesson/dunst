
#Check dependencies
find_package (PkgConfig REQUIRED)
pkg_check_modules (GLIB2 REQUIRED glib-2.0)
pkg_check_modules (LIBNOTIFY REQUIRED libnotify)
pkg_check_modules (FREETYPE REQUIRED freetype2)
pkg_check_modules (DBUS REQUIRED dbus-1)
pkg_check_modules (PANGO REQUIRED pango)
pkg_check_modules (CAIRO REQUIRED cairo)
pkg_check_modules (PANGOCAIRO REQUIRED pangocairo)
pkg_check_modules (XINERAMA REQUIRED xinerama)
pkg_check_modules (X11 REQUIRED x11)
pkg_check_modules (XDG REQUIRED libxdg-basedir)


include_directories( ${LIBNOTIFY_INCLUDE_DIRS} 
						${GLIB2_INCLUDE_DIRS}
						${FREETYPE_INCLUDE_DIRS}
						${DBUS_INCLUDE_DIRS}
						${PANGO_INCLUDE_DIRS}
						${CAIRO_INCLUDE_DIRS}
						)

#Determine version
find_package(Git)
if(GIT_FOUND)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} describe --match build
            OUTPUT_VARIABLE VERSION
            OUTPUT_STRIP_TRAILING_WHITESPACE)
	add_definitions(-DVERSION="${VERSION}")

else()
	add_definitions(-DVERSION="${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")

endif()


#Applications used by Dunst
set( APP_DMENU "/usr/bin/dmenu"
	CACHE STRING "Path to dmenu"
	)
add_definitions(-DAPP_DMENU="${APP_DMENU}")

set( APP_BROWSER "/usr/bin/firefox"
	CACHE STRING "Path to web browser"
	)
add_definitions(-DAPP_BROWSER="${APP_DMENU}")

set( ICON_FOLDERS "/usr/share/icons/gnome/16x16/status/:/usr/share/icons/gnome/16x16/devices/"
	CACHE STRING "Path icon folders. Multiple folders may be listed with comma-seperation"
	)
add_definitions(-DICON_FOLDERS="${APP_DMENU}")

#Targets
add_executable(dunst
				dbus.c
				dunst.c
				menu.c
				notification.c
				option_parser.c
				rules.c
				settings.c
				utils.c
				x.c
				)

add_executable(dunstify
				dunstify.c
				)

set_target_properties(
		dunstify PROPERTIES
		EXCLUDE_FROM_DEFAULT_BUILD TRUE
		EXCLUDE_FROM_ALL TRUE
		)

#Linking
target_link_libraries(dunst 
				${LIBNOTIFY_LIBRARIES} 
				${GLIB2_LIBRARIES}
				${FREETYPE_LIBRARIES}
				${DBUS_LIBRARIES}
				${PANGO_LIBRARIES}
				${CAIRO_LIBRARIES}
				${PANGOCAIRO_LIBRARIES}
				${XINERAMA_LIBRARIES}
				${X11_LIBRARIES}
				${XDG_LIBRARIES}
				${XSS_LIBRARIES}
				m
				Xss
				)

target_link_libraries(dunstify
				${LIBNOTIFY_LIBRARIES} 
				${GLIB2_LIBRARIES}
				)

#Installs
install(TARGETS dunst
		DESTINATION bin)
