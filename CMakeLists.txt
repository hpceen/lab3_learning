cmake_minimum_required(VERSION 3.20)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib_static)

add_subdirectory(main)

add_subdirectory(tests)

add_subdirectory(lib_dynamic)