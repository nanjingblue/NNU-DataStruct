SET(CMAKE_CXX_COMPILER C:/env/mingw64/bin/g++)

aux_source_directory(
    ${CMAKE_CURRENT_SOURCE_DIR} src
)

add_library(controller ${src})

target_link_libraries(
    controller
    utils
    model
)

# target_link_directories(controller PUBLIC ../utils)
