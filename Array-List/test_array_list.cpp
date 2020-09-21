#include <stdexcept>
#include <stdio.h>

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

  void push_back_fill(void) {
    for (auto i = 0; i < list.max_size(); i++) {
      list.push_back(i);
    }
  }
};

TEST_F(ArrayListTest, ConstructorInitializesSizeToMinusOne) {
  ASSERT_EQ(-1, list.size_);
  ASSERT_EQ(-1, list.size_);
}

TEST_F(ArrayListTest, ConstructorInitializesCorrectMaxSize) {
  ASSERT_EQ(20, list.max_size_);
  ASSERT_EQ(10, default_list.max_size_);
}

TEST_F(ArrayListTest, ClearSetsSizeToMinusOne) {
  list.size_ = 10;
  ASSERT_EQ(10, list.size_);
  list.clear();
  ASSERT_EQ(-1, list.size_);
}

TEST_F(ArrayListTest, MaxSizeReturnCorrectValue) {
  ASSERT_EQ(20, list.max_size());
  ASSERT_EQ(10, default_list.max_size());
}

TEST_F(ArrayListTest, SizeReturnsCorrectValue) {
  ASSERT_EQ(0, list.size());
  list.size_ = 1;
  ASSERT_EQ(2, list.size());
}

TEST_F(ArrayListTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(list.empty());
}

TEST_F(ArrayListTest, EmptyReturnsFalseWhenNotEmpty) {
  list.size_ = 5;
  ASSERT_FALSE(list.empty());
}

TEST_F(ArrayListTest, FullReturnsTrueWhenFull) {
  list.size_ = 19;
  ASSERT_TRUE(list.full());
}

TEST_F(ArrayListTest, FullReturnsFalseWhenNotFull) {
  ASSERT_FALSE(list.full());
  list.size_ = 18;
  ASSERT_FALSE(list.full());
}

TEST_F(ArrayListTest, PushBackIncreasesSize) {
  ASSERT_EQ(0, list.size());
  list.push_back(1);
  ASSERT_EQ(1, list.size());
}

TEST_F(ArrayListTest, PushBackThrowsErrorWhenFull) {
  list.size_ = 19;
  ASSERT_THROW(list.push_back(10), std::out_of_range);
}

TEST_F(ArrayListTest, PushBackAddDataToEndOfList) {
  push_back_fill();
  for (auto i = 0; i < list.max_size(); i++) {
    ASSERT_EQ(i, list.contents[i]);
  }
}
