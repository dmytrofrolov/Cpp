cmake_minimum_required(VERSION 2.8.4)
project(007_Product_Inventory_Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    inventory.cpp
    product.cpp)

add_executable(007_Product_Inventory_Project ${SOURCE_FILES})