cmake_minimum_required(VERSION 3.0)
project(demo)

message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message("CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR})
message("CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -std=c++20")

# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRCS)
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# add_library(cal_lib SHARED ${SRCS})

add_executable(${PROJECT_NAME} src/Main.cpp)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/lib/*.cpp ${PROJECT_SOURCE_DIR}/src/include/*.h)
target_sources(${PROJECT_NAME} PUBLIC ${sources})
target_link_libraries(${PROJECT_NAME} gtest)