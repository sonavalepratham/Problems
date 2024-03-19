cmake_minimum_required(VERSION "3.19.2")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(TrainBookingServer)

add_executable(${PROJECT_NAME} 
    main.cpp 
    src/server.cpp 
    src/ClientHandler.cpp
    )
include_directories(${CMAKE_SOURCE_DIR}/Client)
