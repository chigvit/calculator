cmake_minimum_required(VERSION 3.10)

project(calculator)

set(CMAKE_CXX_STANDARD 17)

#For check by sanitize ancoment and rebuild
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

option(BUILD_TESTS "Build unit tests." ON )
option(CODE_COVERAGE "Enable coverage reporting" OFF)
option(BULD_GPROF "Build for gprof perfomance" OFF)

include_directories(include)

add_executable(calculator 
                src/main.cpp
                src/functions.cpp)

set(SOURCES
        src/main.cpp
        src/functions.cpp
        )

#        g++ -w -fno-inline -pg -O2 -DHZ=60  calculator

if(BULD_GPROF)
    message(STATUS "Build for gprof perfomanc")
        # Add fladgs
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -fno-inline -pg -O2 -DHZ=60")
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgprof")
endif()

    
if(CODE_COVERAGE)
    message(STATUS "Building with coverage support")
    # Add fladgs
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
endif()

if ( BUILD_TESTS )
  
    add_subdirectory(lib/googletest)
    enable_testing()
    add_subdirectory(tests/gtest)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

endif ( )

