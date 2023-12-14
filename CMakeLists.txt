cmake_minimum_required(VERSION 3.0)
project(demo)

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -std=c++0x")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} src/main.cpp)