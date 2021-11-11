cmake_minimum_required(VERSION 3.19)
project(DS_HW/HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(main main.cpp include/LinkQueue.h include/SeqQueue.h include/LinkStack.h)