cmake_minimum_required(VERSION 3.20)

project(20190408ZuoShihai/Homework_2)

include_directories(include)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp include/LinkList.h include/SeqList.h)