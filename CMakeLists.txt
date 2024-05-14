cmake_minimum_required(VERSION 3.27)
project(genetic_algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(genetic_algorithm src/main.cpp
        src/Algorithm.cpp
        src/Characteristic.cpp
        src/Random.cpp
        src/Individual.cpp
        src/include/Individual.hpp)

target_include_directories(genetic_algorithm PRIVATE ${CMAKE_SOURCE_DIR}/src/include)