message("=====================================================")
message("===== Start CMakeLists.txt on Practice_Projects =====")
message("=====================================================")

cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "Baby Calculator")
project(${PROJECT_NAME})

find_package(Threads REQUIRED)

#add_definitions(-Wall -ansi -Wno-deprecated -pthread)
add_definitions(-Wall -ansi -Wno-deprecated -pthread)

set(CMAKE_BUILD_TYPE Debug)

message(STATUS "This is message(STATUS)")

set(EXT_DIR ${PROJECT_SOURCE_DIR}/externals)
set(GOOGLE_TEST_DIR ${EXT_DIR}/googletest)
set(PROJECT_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

### googletest
#add_subdirectory(${GOOGLE_TEST_DIR})
add_subdirectory(${EXT_DIR}/googletest)

### enable `ctest`
enable_testing()

### include googltest include directory
include_directories(${GTEST_INCLUDE_DIRS})
message("GTEST_INCLUDE_DIRS ${GTEST_INCLUDE_DIRS}")


#file(GLOB TEST_SRC_FILES ${PROJECT_TEST_DIR}/*.cpp)
### include 
include_directories(${PROJECT_SOURCE_DIR}/src/Calculator)
#add_executable(testFile ${TEST_SRC_FILES})
add_executable(testFile test/calculator_test.cpp)
target_include_directories(testFile PUBLIC ${GTEST_INCLUDE_DIRS} ${GOOGLE_TEST_DIR}/googletest/include ${GOOGLE_TEST_DIR}/googlemock/include)
#add_dependencies(testFile googletest)

#target_link_libraries(testFile ${GTEST_LIBS_DIR}/libgtest.a ${GTEST_LIBS_DIR}/libgtest_main.a)
message("GTEST_LIBS_DIR ${GTEST_LIBS_DIR}")
set(gtest_libs_dirr ${PROJECT_BINARY_DIR}/externals/googletest/googlemock/gtest)
#target_link_libraries(testFile ${gtest_libs_dirr}/gtest ${gtest_libs_dirr}/gtest_main)
target_link_libraries(testFile ${gtest_libs_dirr}/libgtest.a ${gtest_libs_dirr}/libgtest_main.a)
target_link_libraries(testFile ${CMAKE_THREAD_LIBS_INIT})
#add_test(test1 testFile)

### src
add_subdirectory(src)
