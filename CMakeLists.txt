message("=====================================================")
message("===== Start CMakeLists.txt on Practice_Projects =====")
message("=====================================================")

cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "Baby Calculator")
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)

message(STATUS "This is message(STATUS)")

add_subdirectory(src)
