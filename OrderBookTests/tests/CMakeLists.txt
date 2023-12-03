cmake_minimum_required(VERSION 3.15)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(RunTests SomeTests.cpp)

target_link_libraries(RunTests gtest gtest_main OrderBook)

add_test(NAME RunTests COMMAND RunTests)

# include(GoogleTest)
# gtest_discover_tests(RunTests)