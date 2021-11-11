cmake_minimum_required(VERSION 3.20)
project(lab2_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab2_3 main.cpp include/seq_queue.h include/labyrinth.h)
