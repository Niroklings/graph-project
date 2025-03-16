cmake_minimum_required(VERSION 3.10)

project(shortestPathsOnGraph)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES shortestPath.cpp)

configure_file(${CMAKE_SOURCE_DIR}/graph.txt ${CMAKE_BINARY_DIR}/graph.txt COPYONLY)

add_executable(shortestPathsOnGraph ${SOURCE_FILES})


