cmake_minimum_required(VERSION 3.10)

project(Socket)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Socket/bin)

# Include the directory with header files
include_directories(${CMAKE_SOURCE_DIR}/Socket/include)

# Add the library target
add_library(SocketWrapper STATIC src/SocketWrapper.cpp)