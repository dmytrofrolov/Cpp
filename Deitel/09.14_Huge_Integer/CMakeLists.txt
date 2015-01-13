cmake_minimum_required(VERSION 2.8.4)
project(09_14_Huge_Integer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp hugeinteger.cpp)
add_executable(09_14_Huge_Integer ${SOURCE_FILES})