cmake_minimum_required(VERSION 2.8.4)
project(017_Count_Words_in_a_String)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(017_Count_Words_in_a_String ${SOURCE_FILES})