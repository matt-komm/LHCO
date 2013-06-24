cmake_minimum_required (VERSION 2.6)
project (LHCOEvent)
include_directories(${CMAKE_HOME_DIRECTORY})
add_executable(test test/test.cxx)
