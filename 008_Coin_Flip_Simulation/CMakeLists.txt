cmake_minimum_required(VERSION 2.8.4)
project(008_Coin_Flip_Simulation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(008_Coin_Flip_Simulation ${SOURCE_FILES})