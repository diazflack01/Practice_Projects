message("=====================================================")
message("===== Start CMakeLists.txt on Practice_Projects =====")
message("=====================================================")

### Cmake version
cmake_minimum_required(VERSION 3.5)

### Set project name
set(PROJECT_NAME "Baby Calculator")
project(${PROJECT_NAME})

### Find threads package. Specifying REQUIRED will make CMake exit when Threads is not found
find_package(Threads REQUIRED)

### Add definitions. Compiler flags? Not yet sure...
add_definitions(-Wall -ansi -Wno-deprecated -pthread)

### Set to Debug. For prints? Not yet sure, how logs differ...
set(CMAKE_BUILD_TYPE Debug)


### Set other variables
set(EXT_DIR ${PROJECT_SOURCE_DIR}/externals)
set(GOOGLE_TEST_DIR ${EXT_DIR}/googletest)
set(PROJECT_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

### Add googletest. This will call CMakeLists.txt of googletest and it will compile the libraries along with your project
add_subdirectory(${GOOGLE_TEST_DIR})
#add_subdirectory(${EXT_DIR}/googletest)

### enable `ctest` option in project directory
enable_testing()

### googltest includes -- NOT WORKING
include_directories(${GTEST_INCLUDE_DIRS}) #message("GTEST_INCLUDE_DIRS ${GTEST_INCLUDE_DIRS}")


file(GLOB TEST_SRC_FILES ${PROJECT_TEST_DIR}/*.cpp)
### include 
include_directories(${PROJECT_SOURCE_DIR}/src/Calculator)

#add_executable(testFile ${TEST_SRC_FILES})
add_executable(testFile test/calculator_test.cpp)
target_include_directories(testFile PUBLIC ${GTEST_INCLUDE_DIRS} ${GOOGLE_TEST_DIR}/googletest/include ${GOOGLE_TEST_DIR}/googlemock/include)
### Not working. Dont know what is the use of this...
#add_dependencies(testFile googletest)

### Link gtest libraries
#target_link_libraries(testFile ${GTEST_LIBS_DIR}/libgtest.a ${GTEST_LIBS_DIR}/libgtest_main.a) -- ${GTEST_LIBS_DIR} has no output
#message("GTEST_LIBS_DIR ${GTEST_LIBS_DIR}") -- NOT WORKING

set(gtest_libs_dirr ${PROJECT_BINARY_DIR}/externals/googletest/googlemock/gtest)
### Actual linking of googltest libraries to compiled executable
target_link_libraries(testFile ${gtest_libs_dirr}/libgtest.a ${gtest_libs_dirr}/libgtest_main.a)

### Linking of Threads for -pthread. Dont know what it is for exactly...
target_link_libraries(testFile ${CMAKE_THREAD_LIBS_INIT})

### arg1 will be the displayed name when `ctest` is executed. Arg2 is the test binary that will be executed where the output result will be based on
add_test(testFile testFile)

### src
add_subdirectory(src)
