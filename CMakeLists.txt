cmake_minimum_required(VERSION 3.10)
project(shortestPathsOnGraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(Graph src/Graph.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main Graph)

#добавить поддержку тестирования
#enable_testing()
#add_subdirectory(tests)
