cmake_minimum_required(VERSION 3.20)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
add_executable(Lab1 main.cpp RandomGenerator.cpp Headers/RandomGenerator.h IStrategy.cpp Headers/IStrategy.h Algorithms/LinialCongruentMethod.cpp Headers/Algorithms/LinialCongruentMethod.h)
