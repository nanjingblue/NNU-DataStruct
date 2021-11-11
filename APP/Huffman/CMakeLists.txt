cmake_minimum_required(VERSION 3.20.2)

project(nanjingblue/HuffmanApp)


add_subdirectory(controller)
add_subdirectory(utils)
add_subdirectory(model)

include_directories(controller)

link_directories(controller)

aux_source_directory(. DIR_SRCS)

add_executable(main ${DIR_SRCS})

target_link_libraries(
    main
    controller
)

# target_link_directories(main PUBLIC controller)