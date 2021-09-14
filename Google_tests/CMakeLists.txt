# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run RandomGenerator_test.cpp ../RandomGenerator.cpp ../include/RandomGenerator.h)
target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run random)
target_link_libraries(random gtest gtest_main)
enable_testing()
add_test(NAME random-generator COMMAND Google_Tests_run)