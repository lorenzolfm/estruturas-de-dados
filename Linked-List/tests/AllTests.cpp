#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
#include "linked_list.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}
