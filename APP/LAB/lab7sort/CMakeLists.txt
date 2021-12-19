cmake_minimum_required(VERSION 3.20)
project(lab7sort)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab7sort main.cpp include/gen_render.h include/sort.h include/gen_render.cpp)

