cmake_minimum_required(VERSION 2.8.4)
project(021_Fibonacci_sequence)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(021_Fibonacci_sequence ${SOURCE_FILES})