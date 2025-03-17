cmake_minimum_required(VERSION 3.10)
project(shortestPathsOnGraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(Graph src/Graph.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main Graph)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest/CMakeLists.txt")
    message(WARNING "GoogleTest submodule not initialized. Attempting to initialize...")
    execute_process(COMMAND git submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE result)
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "Failed to initialize submodules. Please run:
        git submodule update --init --recursive
        ")
    endif()
endif()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(run_tests tests/test_graph.cpp)
target_link_libraries(run_tests Graph ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME GraphTest COMMAND run_tests)
