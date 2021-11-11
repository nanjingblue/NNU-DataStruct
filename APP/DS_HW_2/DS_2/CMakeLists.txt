cmake_minimum_required(VERSION 3.20)
project(ds_hw_2/DS_2)

include_directories(include)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp include/SeqList.h )