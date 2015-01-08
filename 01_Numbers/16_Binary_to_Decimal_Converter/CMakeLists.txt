cmake_minimum_required(VERSION 2.8.4)
project(16_Binary_to_Decimal_Converter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(16_Binary_to_Decimal_Converter ${SOURCE_FILES})