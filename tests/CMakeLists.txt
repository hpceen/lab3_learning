cmake_minimum_required(VERSION 3.20)
project(tests)

set(CMAKE_CXX_STANDARD 20)

######### googletest init #########
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
######### googletest init end #########

add_executable(tests tests.cpp)

######### links to static libs #########
include_directories(../lib_static/)
target_link_libraries(tests gtest_main lib_static #lib_dynamic
        )