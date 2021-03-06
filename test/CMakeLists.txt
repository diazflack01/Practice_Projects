message("=====================================================")
message("===== Start CMakeLists.txt on test/ =================")
message("=====================================================")

################ GOOGLE TEST EXCLUSIVE ###################
# Find threads package which is needed for googletest. Specifying REQUIRED will make CMake exit when Threads is not found
find_package(Threads REQUIRED)

# enable `ctest` option in build directory
enable_testing()

### CalculatorTest
# Assign all cpp files to variable TEST_SOURCE_FILES
file(GLOB TEST_SOURCE_FILES main.cpp CalculatorTest.cpp ${PROJECT_SOURCE_DIR}/src/Calculator/*.cpp)

# set test name binary then create executable
set(PROJECT_TEST_NAME "${PROJECT_NAME}_test")
add_executable(${PROJECT_TEST_NAME} ${TEST_SOURCE_FILES})

# add dependencies for googletest for PROJECT_TEST_NAME so that those will be compiled before this one
add_dependencies(${PROJECT_TEST_NAME} gtest gtest_main gmock gmock_main) # gtest, gtest_main, gmock, and gmock_main are names to create shared library (Executed in googletests CMakeLists.txt, add_library(...) )

# Link needed libraries to test executable
target_link_libraries(${PROJECT_TEST_NAME} gtest gtest_main gmock gmock_main ${CMAKE_THREAD_LIBS_INIT})

# add test executable with name
add_test(CalculatorTest ${PROJECT_TEST_NAME})

### PalindromeTest
include_directories(${PROJECT_SOURCE_DIR}/src/Palindrome)
file(GLOB PALINDROME_TEST_SRC_FILES main.cpp PalindromeTest.cpp ${PROJECT_SOURCE_DIR}/src/Palindrome/*.cpp)
set(PALINDROME_TEST_EXEC_NAME "${PROJECT_NAME}_PalindromeTest")
add_executable(${PALINDROME_TEST_EXEC_NAME} ${PALINDROME_TEST_SRC_FILES})
add_dependencies(${PALINDROME_TEST_EXEC_NAME} gtest gtest_main gmock gmock_main)
target_link_libraries(${PALINDROME_TEST_EXEC_NAME} gtest gtest_main gmock gmock_main ${CMAKE_THREAD_LIBS_INIT})
add_test(PalindromeTest ${PALINDROME_TEST_EXEC_NAME})


### RagnarokTest
include_directories(${PROJECT_SOURCE_DIR}/src/Ragnarok Ragnarok)
file(GLOB RAGNAROK_ARCHER_SRC_FILES ${PROJECT_SOURCE_DIR}/src/Ragnarok/Hero/Archer.cpp)
file(GLOB RAGNAROK_ARCHER_TEST_SRC_FILES main.cpp Ragnarok/Hero/*.cpp)
set(RAGNAROK_ARCHER_TEST_EXEC_NAME "${PROJECT_NAME}_Ragnarok_ArcherTest")
add_executable(${RAGNAROK_ARCHER_TEST_EXEC_NAME} ${RAGNAROK_ARCHER_TEST_SRC_FILES} ${RAGNAROK_ARCHER_SRC_FILES})
add_dependencies(${RAGNAROK_ARCHER_TEST_EXEC_NAME} gtest gtest_main gmock gmock_main)
target_link_libraries(${RAGNAROK_ARCHER_TEST_EXEC_NAME} gtest gtest_main gmock gmock_main ${CMAKE_THREAD_LIBS_INIT})
