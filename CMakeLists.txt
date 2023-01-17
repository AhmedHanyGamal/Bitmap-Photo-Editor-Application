cmake_minimum_required(VERSION 3.22)
project(ya_rab_t4ta8al)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ya_rab_t4ta8al
        bmplib.cpp
        bmplib.h
        "image filter.cpp")
