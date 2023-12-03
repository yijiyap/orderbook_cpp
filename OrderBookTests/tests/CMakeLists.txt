cmake_minimum_required(VERSION 3.15)

enable_testing()
include_directories($(gtest_SOURCE_DIR)/include $(gtest_SOURCE_DIR))
add_executable(RunTest SomeTests.cpp)
target_link_libraries(RunTest gtest gtest_main)

add_test(NAME RunTest COMMAND RunTest)

include(GoogleTest)
gtest_discover_tests(RunTest)