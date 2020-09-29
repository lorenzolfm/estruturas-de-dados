cmake_minimum_required(VERSION 3.1)

project(ArrayList)

# Locate GTest
find_package(GTest REQUIRED)

include_directories(
  ${GTEST_INCLUDE_DIRS}
  include
  src
  )

set(array_test_SOURCES tests/test_array_list.cpp)
set(array_include_SOURCES include/array_list.h)
set(array_src_SOURCES src/array_list.cpp)

add_executable(array_test ${array_test_SOURCES} ${array_include_SOURCES} ${array_src_SOURCES})
target_link_libraries(array_test ${GTEST_LIBRARIES} pthread)

set(string_test_SOURCES tests/test_string_list.cpp)
set(string_include_SOURCES include/string_list.h)
set(string_src_SOURCES src/string_list.cpp)

add_executable(string_test ${string_test_SOURCES} ${string_include_SOURCES} ${string_src_SOURCES})
target_link_libraries(string_test ${GTEST_LIBRARIES} pthread)
