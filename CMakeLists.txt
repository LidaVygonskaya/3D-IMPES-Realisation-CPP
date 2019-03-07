cmake_minimum_required(VERSION 3.13)
project(3_DIM_IMPES)

set(CMAKE_CXX_STANDARD 17)

add_executable(3_DIM_IMPES main.cpp Layer.cpp Water.h Oil.h Component.h)