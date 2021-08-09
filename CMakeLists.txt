cmake_minimum_required(VERSION 3.16)
project(FreeDB)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRCS src/*)

add_executable(FreeDB ${SRCS})