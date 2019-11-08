cmake_minimum_required(VERSION 3.1...3.15)

set (CMAKE_VERBOSE_MAKEFILE ON)

project(PointBindings VERSION 1.0 LANGUAGES CXX)

find_package(PointLib 1.0 REQUIRED)

set(SOURCE_DIR "src")

find_package(pybind11)
pybind11_add_module(point ${SOURCES} "${SOURCE_DIR}/point_bindings.cpp")
target_link_libraries(point PUBLIC PointLib)