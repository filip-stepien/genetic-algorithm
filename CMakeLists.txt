cmake_minimum_required(VERSION 3.27)
project(genetic_algorithm)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-static -static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include(FetchContent)

FetchContent_Declare(variadic-table
    GIT_REPOSITORY https://github.com/friedmud/variadic_table.git
    GIT_TAG        master
)

FetchContent_GetProperties(variadic-table)

if(NOT variadic-table_POPULATED)
    FetchContent_Populate(variadic-table)
    add_library(variadic-table INTERFACE)
    target_include_directories(variadic-table INTERFACE ${variadic-table_SOURCE_DIR}/include)
endif()

FetchContent_Declare(progressbar
        GIT_REPOSITORY https://github.com/gipert/progressbar.git
        GIT_TAG        master
)

FetchContent_GetProperties(progressbar)

if(NOT progressbar_POPULATED)
    FetchContent_Populate(progressbar)
    add_library(progressbar INTERFACE)
    target_include_directories(progressbar INTERFACE ${progressbar_SOURCE_DIR}/include)
endif()

add_executable(genetic_algorithm
    src/main.cpp
    src/Algorithm.cpp
    src/Characteristic.cpp
    src/Random.cpp
    src/Individual.cpp
    src/WindowUtils.cpp
    src/Params.cpp
)

target_link_libraries(genetic_algorithm PRIVATE variadic-table progressbar)

target_include_directories(genetic_algorithm PRIVATE ${CMAKE_SOURCE_DIR}/src/include)