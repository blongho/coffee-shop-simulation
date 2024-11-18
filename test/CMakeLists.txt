cmake_minimum_required(VERSION 3.29)
project(CoffeeShopProgramTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_DIR ../include)
set(SRC_DIR ../src)

file(GLOB COFFEE_HEADERS ${HEADER_DIR}/Coffee.h ${HEADER_DIR}/*Coffee.h)

message(STATUS "COFFEE HEADERS are ${COFFEE_HEADERS}")

file(GLOB COFFEE_SRC ${SRC_DIR}/Coffee.cpp ${SRC_DIR}/*Coffee.cpp)

message(STATUS "COFFEE SOURCES are ${COFFEE_SRC}")

find_package(Catch2 REQUIRED)

add_executable(test_coffee
        ${COFFEE_HEADERS}
        ${COFFEE_SRC}
        test-coffee.cpp)

add_executable(test_coffee_order
        ${COFFEE_HEADERS}
        ${COFFEE_SRC}
        ${HEADER_DIR}/CoffeeOrder.h
        ${SRC_DIR}/CoffeeOrder.cpp
        test-coffee-order.cpp)

target_link_libraries(test_coffee PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test_coffee_order PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)

catch_discover_tests(test_coffee)
catch_discover_tests(test_coffee_order)
