cmake_minimum_required(VERSION 3.21)
project(APC_randomness)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(examples)

add_executable(APC_randomness
        examples/std_rand.cpp examples/cpp11rand.cpp)
