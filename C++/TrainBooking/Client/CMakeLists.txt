cmake_minimum_required(VERSION "3.19.2")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(TrainBookingClient)
add_executable(TrainBookingClient 
main.cpp
src/client.cpp
)
include_directories(${CMAKE_SOURCE_DIR}/Client)