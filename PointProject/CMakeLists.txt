cmake_minimum_required(VERSION 3.0)
project(POINT_PROJECT)

# define library version (update: apparently you can also do it in project()!)
set(POINT_PROJECT_VERSION_MAJOR 1 CACHE STRING "major version" FORCE)
set(POINT_PROJECT_VERSION_MINOR 0 CACHE STRING "minor version" FORCE)
set(POINT_PROJECT_VERSION ${POINT_PROJECT_VERSION_MAJOR}.${POINT_PROJECT_VERSION_MINOR} CACHE STRING "version" FORCE)


set(include_dest "include/PointLib-${POINT_PROJECT_VERSION}")
set(main_lib_dest "lib/PointLib-${POINT_PROJECT_VERSION}")
set(lib_dest "${main_lib_dest}/${CMAKE_BUILD_TYPE}")

configure_file(PointLib-config-version.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/PointLib-config-version.cmake @ONLY)

install(FILES PointLib-config.cmake ${CMAKE_CURRENT_BINARY_DIR}/PointLib-config-version.cmake DESTINATION ${main_lib_dest})
install(EXPORT PointLib DESTINATION "${lib_dest}")

# add subdiretories
add_subdirectory(src)