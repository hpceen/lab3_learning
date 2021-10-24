cmake_minimum_required(VERSION 3.20)
project(lib_dynamic)

set(CMAKE_CXX_STANDARD 20)

add_library(lib_dynamic class_d.cpp class_d.h strucrt_d.cpp strucrt_d.h)