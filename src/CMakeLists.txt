message("=====================================================")
message("===== CMakeLists.txt in ${CMAKE_CURRENT_SOURCE_DIR} =====")
message("=====================================================")

message("CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}")
message("PROJECT_NAME ${PROJECT_NAME}")
message("PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}")
message("CMAKE_C_COMPILER ${CMAKE_C_COMPILER}")
message("CMAKE_C_FLAGS ${CMAKE_C_FLAGS}")
message("CMAKE_CXX_COMPILER ${CMAKE_CXX_COMPILER}")
message("CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}")
message(" ${}")
message(" ${}")
message(" ${}")
message(" ${}")
message(" ${}")
message(" ${}")
message(" ${}")
message(" ${}")
message(" ${}")

file(GLOB_RECURSE SOURCES main.cpp Calculator/*.cpp)
include_directories(Calculator)

add_executable(Calculator ${SOURCES})

##### For Ragnarok
