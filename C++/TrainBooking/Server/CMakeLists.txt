cmake_minimum_required(VERSION "3.19.2")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(TrainBookingServer)

add_executable(${PROJECT_NAME} 
    main.cpp 
    src/server.cpp 
    src/ClientHandler.cpp
    )
target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
