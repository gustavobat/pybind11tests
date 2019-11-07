cmake_minimum_required (VERSION 3.11.0)

project(ErrorEstimationPythonBindings 
    DESCRIPTION "Python bindings for NeoPZ error estimation related classes"
    LANGUAGES CXX
)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(TARGET_INCLUDE_DIRS)

add_library(ErrorEstimationBindings src/bindings.cpp)

find_package(PZ REQUIRED)

message( ${CMAKE_CURRENT_SOURCE_DIR} )
message( ${PZ_USING_LOG4CXX} )
# Enables log4cxx library
if(${PZ_USING_LOG4CXX})
  message(STATUS "Setting up log4cxx...")
  find_package(log4cxx REQUIRED)
  target_include_directories(ErrorEstimationBindings 
    PUBLIC
  	  log4cxx
  	)
endif()







