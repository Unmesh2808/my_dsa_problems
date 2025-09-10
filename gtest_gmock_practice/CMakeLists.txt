cmake_minimum_required(VERSION 3.10)

project(MyGtestPractice CXX)

find_package(GTest CONFIG REQUIRED)

add_executable(mytest prime.cpp fibonacci.cpp)

target_link_libraries(mytest GTest::gtest_main GTest::gtest)