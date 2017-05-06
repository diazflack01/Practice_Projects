message("=====================================================")
message("===== Start CMakeLists.txt on Practice_Projects =====")
message("=====================================================")

# cmake version
cmake_minimum_required(VERSION 3.5)

# set project name
set(PROJECT_NAME "Baby_Project_CMake_GTest")
project(${PROJECT_NAME})
enable_language(C CXX)

# Add definitions. Compiler flags? Not yet sure...
add_definitions(-Wall -Werror -ansi -Wno-deprecated -pthread)

# Set to Debug. For prints? Not yet sure, how logs differ...
set(CMAKE_BUILD_TYPE Debug)

# Set other variables
set(EXTERNAL_DIR ${PROJECT_SOURCE_DIR}/externals)

# Add googletest. This will call CMakeLists.txt of googletest and it will compile the libraries along with your project
add_subdirectory(${EXTERNAL_DIR}/googletest)

# googltest includes for test files and for Calculator class hpp
include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src/Calculator) # gtest_SOURCE_DIR was defined when googletest was compiled

# for src
add_subdirectory(src)

# for test
add_subdirectory(test)
