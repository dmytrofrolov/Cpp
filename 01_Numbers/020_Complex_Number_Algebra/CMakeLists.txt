cmake_minimum_required(VERSION 2.8.4)
project(20_Complex_Number_Algebra)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp complex.cpp)
add_executable(20_Complex_Number_Algebra ${SOURCE_FILES})