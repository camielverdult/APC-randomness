cmake_minimum_required(VERSION 3.21)
project(APC_randomness)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(examples)

add_executable(std_rand_example
        examples/std_rand.cpp)

add_executable(cpp11_rand_example examples/cpp11rand.cpp)
