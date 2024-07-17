cmake_minimum_required(VERSION 3.10)

project(Client)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Client/bin)

#include_directories(${CMAKE_SOURCE_DIR}/d1/include)
include_directories(${CMAKE_SOURCE_DIR}/Socket/include)


# Add the executable
add_executable(Client_executable src/main.cpp) # Adjust the source file(s) as needed

target_link_libraries(Client_executable PRIVATE SocketWrapper)


