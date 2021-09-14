cmake_minimum_required(VERSION 3.20)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_library(random STATIC RandomGenerator.cpp include/RandomGenerator.h)
add_executable(Lab1 main.cpp IStrategy.cpp include/IStrategy.h Algorithms/LinialCongruentialMethod.cpp include/Algorithms/LinialCongruentialMethod.h RandomGenerator.cpp include/RandomGenerator.h Algorithms/QuadraticCongruentialMethod.cpp include/Algorithms/QuadraticCongruentialMethod.h Algorithms/FibonacciMethod.cpp include/Algorithms/FibonacciMethod.h Algorithms/InverseCongruentialMethod.cpp include/Algorithms/InverseCongruentialMethod.h)
add_subdirectory(Google_tests)