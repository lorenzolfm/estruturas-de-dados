cmake_minimum_required(VERSION 3.1)

project(ArrayStack)

# Locate GTest
find_package(GTest REQUIRED)

include_directories(
  ${GTEST_INCLUDE_DIRS}
  include
  src
  )

add_executable(test tests/test_array_stack.cpp include/array_stack.h src/array_stack.cpp)
target_link_libraries(test ${GTEST_LIBRARIES} pthread)
