cmake_minimum_required(VERSION 3.0)
project(3d-curves)

set(SOURCES
    circle.cpp
    ellipse.cpp
    helix.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(3d-curves SHARED ${SOURCES})
target_include_directories(3d-curves PUBLIC include)
