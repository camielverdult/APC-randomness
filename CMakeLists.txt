cmake_minimum_required(VERSION 3.21)
project(APC_randomness)

set(CMAKE_CXX_STANDARD 20)

include_directories(examples)

add_executable(std_rand_example examples/std_rand.cpp)

add_executable(linear_congruential_example examples/linear_congruential.cpp examples/noise_mapper.h examples/noise_mapper.cpp)

add_executable(subtract_with_carry_example examples/subtract_with_carry_example.cpp)

add_executable(noise_map examples/noise_mapper.h examples/noise_mapper.cpp)

add_executable(gradient_noise_test1 examples/gradient_noise_test1.cpp)

add_executable(std_rand_gradient examples/std_rand_gradient_test.cpp)
