cmake_minimum_required(VERSION 3.10)
project(app)

#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3d-curves)

find_library(lib3dcurves
    NAMES 3d-curves
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/3d-curves/lib
    )

add_executable(app main.cpp)

target_link_libraries(app PUBLIC
    ${lib3dcurves}
    )
