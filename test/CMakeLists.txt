message("=====================================================")
message("===== Start CMakeLists.txt on test/ =================")
message("=====================================================")

################ GOOGLE TEST EXCLUSIVE ###################
# Find threads package which is needed for googletest. Specifying REQUIRED will make CMake exit when Threads is not found
find_package(Threads REQUIRED)

# Assign all cpp files to variable TEST_SOURCE_FILES
file(GLOB TEST_SOURCE_FILES *.cpp ${PROJECT_SOURCE_DIR}/src/Calculator/*.cpp)

# set test name binary then create executable
set(PROJECT_TEST_NAME "${PROJECT_NAME}_test")
add_executable(${PROJECT_TEST_NAME} ${TEST_SOURCE_FILES})

# add dependencies for googletest for PROJECT_TEST_NAME so that those will be compiled before this one
add_dependencies(${PROJECT_TEST_NAME} gtest gtest_main gmock gmock_main) # gtest, gtest_main, gmock, and gmock_main are names to create shared library (Executed in googletests CMakeLists.txt, add_library(...) )

# Link needed libraries to test executable
target_link_libraries(${PROJECT_TEST_NAME} gtest gtest_main gmock gmock_main ${CMAKE_THREAD_LIBS_INIT})

# enable `ctest` option in build directory
enable_testing()

# add test executable with name
add_test(CalculatorTest ${PROJECT_TEST_NAME})
