cmake_minimum_required(VERSION 3.15)
project(orderbook_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp)
add_executable(orderbook_cpp ${SOURCE_FILES})

include_directories(OrderBook)
add_subdirectory(OrderBook)
add_subdirectory(OrderBookTests)

target_link_libraries(orderbook_cpp OrderBook)