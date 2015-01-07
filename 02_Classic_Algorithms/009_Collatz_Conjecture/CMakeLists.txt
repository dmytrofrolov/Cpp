cmake_minimum_required(VERSION 2.8.4)
project(009_Collatz_Conjecture)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(009_Collatz_Conjecture ${SOURCE_FILES})