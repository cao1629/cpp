cmake_minimum_required(VERSION 3.10)

project(cpp)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_BUILD_TYPE Debug)

add_executable(main main.cpp)
add_executable(a1 a1.c)
