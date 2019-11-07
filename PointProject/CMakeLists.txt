cmake_minimum_required(VERSION 3.1...3.15)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(PointProject VERSION 1.0 LANGUAGES CXX)

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)

# Find packages go here.

# You should usually split this into folders, but this is a simple example

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
add_library(PointLib src/point.cpp include/point.h)

target_compile_features(PointLib PUBLIC cxx_std_11)

# Link each target with other targets or add options, etc.
set_target_properties(PointLib PROPERTIES PUBLIC_HEADER include/point.h)
target_include_directories(PointLib PUBLIC include)

set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include")
configure_file(PointLibConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/PointLibConfig.cmake" @ONLY)
   
# ... for both
configure_file(PointLibConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/PointLibConfigVersion.cmake" @ONLY)
 

set(INSTALL_CMAKE_DIR ${CMAKE_INSTALL_PREFIX}/CMake)

# Install the PointLibConfig.cmake and PointLibConfigVersion.cmake
install(FILES
        "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/PointLibConfig.cmake"
        "${PROJECT_BINARY_DIR}/PointLibConfigVersion.cmake"
        DESTINATION "${INSTALL_CMAKE_DIR}" )

install(TARGETS PointLib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
# Adding something we can run - Output name matches target name
# add_executable(MyExample simple_example.cpp)

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
# target_link_libraries(MyExample PRIVATE PointLib)