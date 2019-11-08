# This project uses pybind11 to create python binding for the NeoPZ library.
# Author: Gustavo Batistela
# Date: 13/09/2019
cmake_minimum_required (VERSION 3.11.0)

set (CMAKE_VERBOSE_MAKEFILE ON)

project (LINE_PROJECT)

# point project
find_package(PointLib 1.0 REQUIRED)
# pybind11
find_package(pybind11)

# Project related sources
set(SOURCE_DIR "src")
set(INCLUDE_DIR "include")
pybind11_add_module(line "${SOURCE_DIR}/line.cpp" "${SOURCE_DIR}/line_bindings.cpp")
target_link_libraries(line PUBLIC PointLib)
target_include_directories(line PUBLIC ${INCLUDE_DIR})