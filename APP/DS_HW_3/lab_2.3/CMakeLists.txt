cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 14)

project(20190408ZuoShihai/lab_2.3)

include_directories(include)

add_executable(main main.cpp include/LinkList.h)