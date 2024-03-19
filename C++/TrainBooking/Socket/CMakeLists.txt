cmake_minimum_required(VERSION "3.19.2")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(PSsocket 
src/socket.cpp
)