cmake_minimum_required(VERSION 3.1)

project(ArrayList)

# Locate GTest
find_package(GTest REQUIRED)

include_directories(
  ${GTEST_INCLUDE_DIRS}
  include
  src
  )

set(test_SOURCES tests/test_array_list.cpp)
set(include_SOURCES include/array_list.h)
set(src_SOURCES src/array_list.cpp)

add_executable(test ${test_SOURCES} ${include_SOURCES} ${src_SOURCES})
target_link_libraries(test ${GTEST_LIBRARIES} pthread)
