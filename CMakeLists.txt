cmake_minimum_required(VERSION 3.10)

project(shortestPathsOnGraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(Graph src/Graph.cpp)

configure_file(
    ${CMAKE_SOURCE_DIR}/graph.txt
    ${CMAKE_BINARY_DIR}/graph.txt
    COPYONLY
)

add_executable(main src/main.cpp)
target_link_libraries(main Graph)