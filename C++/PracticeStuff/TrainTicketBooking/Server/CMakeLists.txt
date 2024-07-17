cmake_minimum_required(VERSION 3.10)

project(Server)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Server/bin)

#include_directories(${CMAKE_SOURCE_DIR}/Server/include)
include_directories(${CMAKE_SOURCE_DIR}/Socket/include)


# Add the executable
add_executable(Server_executable src/main.cpp) # Adjust the source file(s) as needed

target_link_libraries(Server_executable PRIVATE SocketWrapper)

