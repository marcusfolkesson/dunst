cmake_minimum_required (VERSION 3.0)
project(Dunst
		VERSION 1.0
		)

include_directories(include)
add_subdirectory(src)
add_subdirectory(configs)
add_subdirectory(docs)

# Pack source code 
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_SOURCE_GENERATOR "TBZ2")
set(CPACK_SOURCE_PACKAGE_FILE_NAME
  "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
set(CPACK_SOURCE_IGNORE_FILES
  "/build/;/.git/;/.bzr/;~$;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)
