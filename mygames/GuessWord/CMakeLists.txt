cmake_minimum_required(VERSION 3.10)

project(GuessWord VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.c)
add_executable(run ${SRC_FILES})
target_include_directories(run PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
