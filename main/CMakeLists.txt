cmake_minimum_required(VERSION 3.20)
project(main)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp)
#include_directories(../lib_static/)
#target_link_libraries(main lib_static)
include_directories(../lib_dynamic/)
target_link_libraries(main lib_dynamic)