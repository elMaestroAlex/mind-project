cmake_minimum_required(VERSION 3.17)
project(kate)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/parser)

FILE(GLOB_RECURSE src src/*.cpp)

add_executable(mind ${src})
