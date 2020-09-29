#include <stdexcept>

#include "gtest/gtest.h"
#include "string_list.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class StringListTest: public::testing::Test {
  protected:
};

TEST(StringListTest, Check)
{
  ASSERT_EQ(1, 1);
}
