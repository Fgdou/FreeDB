cmake_minimum_required(VERSION 3.16)
project(FreeDB)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS src/*)

add_library(FreeDB ${SRCS})

add_subdirectory(lib/googletest)

project(FreeDB_Test)
file(GLOB_RECURSE TESTS tests/*)
add_executable(FreeDB_Test ${TESTS})
target_link_libraries(FreeDB_Test gtest FreeDB)
target_include_directories(FreeDB_Test PUBLIC lib/googletest/googletest/include src)