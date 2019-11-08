# set headers

set(header_path "${POINT_PROJECT_SOURCE_DIR}/include/PointLib")
set(header ${header_path}/point.h
			)

# set source files
set(src point.cpp
		)


# define library target
add_library(PointLib ${header} ${src})
target_include_directories(PointLib PUBLIC
                       $<BUILD_INTERFACE:${POINT_PROJECT_SOURCE_DIR}/include> # for headers when building
											 $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for config_impl.hpp when building
                       $<INSTALL_INTERFACE:${include_dest}> # for client in install mode
                       $<INSTALL_INTERFACE:${lib_dest}> # for config_impl.hpp in install mode
                       )
		

install(TARGETS PointLib EXPORT PointLib DESTINATION "${lib_dest}")
install(FILES ${header} DESTINATION "${include_dest}")