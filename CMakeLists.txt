cmake_minimum_required(VERSION 3.20)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_library(random STATIC RandomGenerator.cpp include/RandomGenerator.h)
add_executable(Lab1 main.cpp IStrategy.cpp include/IStrategy.h Algorithms/LinealCongruentialMethod.cpp include/Algorithms/LinealCongruentialMethod.h RandomGenerator.cpp include/RandomGenerator.h Algorithms/QuadraticCongruentialMethod.cpp include/Algorithms/QuadraticCongruentialMethod.h Algorithms/FibonacciMethod.cpp include/Algorithms/FibonacciMethod.h Algorithms/InverseCongruentialMethod.cpp include/Algorithms/InverseCongruentialMethod.h Algorithms/Utils.cpp include/Algorithms/Utils.h Algorithms/UnityMethod.cpp include/Algorithms/UnityMethod.h include/Algorithms/algorithms.h Algorithms/ThreeSigmaMethod.cpp include/Algorithms/ThreeSigmaMethod.h IUniformStrategy.cpp include/IUniformStrategy.h Algorithms/PolarCoordintesMethod.cpp include/Algorithms/PolarCoordintesMethod.h Algorithms/LogarithmExponentialMethod.cpp include/Algorithms/LogarithmExponentialMethod.h Algorithms/CorrelationMethod.cpp include/Algorithms/CorrelationMethod.h Algorithms/AhrensGammaMethod.cpp include/Algorithms/AhrensGammaMethod.h)
add_subdirectory(Google_tests)