cmake_minimum_required(VERSION 3.15)
project(orderbook_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES main.cpp)
add_executable(orderbook_cpp ${SOURCE_FILES})

include_directories(OrderBook)
add_subdirectory(OrderBook)
add_subdirectory(OrderBookTests)

target_link_libraries(orderbook_cpp OrderBook)