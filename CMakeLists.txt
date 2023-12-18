cmake_minimum_required(VERSION 3.0)
project(demo)

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -std=c++0x")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} src/Main.cpp)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/lib/*.cpp ${PROJECT_SOURCE_DIR}/src/include/*.h)
target_sources(${PROJECT_NAME} PUBLIC ${sources})