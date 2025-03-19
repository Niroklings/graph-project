cmake_minimum_required(VERSION 3.10)

project(GraphTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(../include)

link_directories(../build)

add_executable(run_tests test_graph.cpp)

target_link_libraries(run_tests Graph ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME GraphTest COMMAND run_tests)