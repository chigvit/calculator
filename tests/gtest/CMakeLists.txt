# tests/gtest/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

option(CODE_COVERAGE "Enable coverage reporting" OFF)

add_executable(utest_evaluate utest_evaluate.cpp
                ../../src/functions.cpp)

set(SOURCES              
    ../../src/functions.cpp
    )

target_link_libraries(utest_evaluate gtest gtest_main)

set_target_properties(utest_evaluate PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
