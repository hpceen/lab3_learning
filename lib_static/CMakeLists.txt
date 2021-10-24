cmake_minimum_required(VERSION 3.20)
project(lib_static)

set(CMAKE_CXX_STANDARD 20)

add_library(lib_static class_s.cpp class_s.h strucrt_s.cpp strucrt_s.h)