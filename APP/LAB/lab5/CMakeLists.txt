cmake_minimum_required(VERSION 3.20)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab5 main.cpp include/LinkBiTree.h)
