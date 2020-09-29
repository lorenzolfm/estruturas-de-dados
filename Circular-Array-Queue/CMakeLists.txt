cmake_minimum_required(VERSION 3.1)

project(CircularArrayQueue)

# Locate GTest
find_package(GTest REQUIRED)

include_directories(
  ${GTEST_INCLUDE_DIRS}
  include
  src
  )

set(test_SOURCES tests/test_circular_array_queue.cpp)
set(include_SOURCES include/circular_array_queue.h)
set(src_SOURCES src/circular_array_queue.cpp)

add_executable(test ${test_SOURCES} ${include_SOURCES} ${src_SOURCES})
target_link_libraries(test ${GTEST_LIBRARIES} pthread)
