#include <stdexcept>

#include "array_list.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class ArrayListTest : public ::testing::Test {
 protected:
  structures::ArrayList<int> list{20};
  structures::ArrayList<int> default_list{};
};

TEST_F(ArrayListTest, ConstructorInitializesSizeToMinusOne) {
  ASSERT_EQ(-1, list.size_);
  ASSERT_EQ(-1, list.size_);
}

TEST_F(ArrayListTest, ConstructorInitializesCorrectMaxSize) {
  ASSERT_EQ(20, list.max_size_);
  ASSERT_EQ(10, default_list.max_size_);
}
