include_directories(Head)

add_executable(demo01 demo01.cpp Head/demo01Test.h Source/demo01Test.cpp Head/LinkList.h Source/LinkList.cpp)
add_executable(demo02 demo02.cpp Head/LinkList.h)