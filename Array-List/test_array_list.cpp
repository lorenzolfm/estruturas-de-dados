#include <stdio.h>

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

TEST_F(ArrayListTest, EmptyReturnsTrueWhenEmpty) { ASSERT_TRUE(list.empty()); }

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

TEST_F(ArrayListTest, PopBackDecreasesSize) {
  push_back_fill();
  list.pop_back();
  ASSERT_EQ(19, list.size());
  list.pop_back();
  ASSERT_EQ(18, list.size());
}

TEST_F(ArrayListTest, PopBackThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.pop_back(), std::out_of_range);
}

TEST_F(ArrayListTest, PopBackReturnsLastElement) {
  push_back_fill();
  for (auto i = 19; i >= 0; i--) {
    ASSERT_EQ(i, list.pop_back());
  }
}

TEST_F(ArrayListTest, PushFrontIncreasesSize) {
  ASSERT_EQ(0, list.size());
  list.push_front(1);
  ASSERT_EQ(1, list.size());
}

TEST_F(ArrayListTest, PushFrontThrowsErrorWhenFull) {
  push_back_fill();
  ASSERT_THROW(list.push_front(10), std::out_of_range);
}

TEST_F(ArrayListTest, PushFrontMovesBackwards) {
  push_back_fill();
  list.pop_back();
  list.push_front(666);
  for (auto i = 0; i < list.max_size() - 1; i++) {
    ASSERT_EQ(i, list.contents[i + 1]);
  }
}

TEST_F(ArrayListTest, PushFrontInsertsDataInAtIndex0) {
  for (auto i = 0; i < list.max_size(); i++) {
    list.push_front(i);
    ASSERT_EQ(i, list.contents[0]);
  }
}

TEST_F(ArrayListTest, PopFrontDecreasesSize) {
  push_back_fill();
  ASSERT_EQ(list.size(), list.max_size());
  list.pop_front();
  ASSERT_EQ(list.size(), list.max_size() - 1);
}

TEST_F(ArrayListTest, PopFrontThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.pop_front(), std::out_of_range);
}

TEST_F(ArrayListTest, PopFrontRemovesFrontElement) {
  push_back_fill();
  for (auto i = 0; i < list.max_size(); i++) {
    ASSERT_EQ(i, list.pop_front());
  }
}

TEST_F(ArrayListTest, InsertThrowsErrorWhenFull) {
  push_back_fill();
  ASSERT_THROW(list.insert(1, 1), std::out_of_range);
}

TEST_F(ArrayListTest, InsertThrowsErrorWhenInvalidIndex) {
  ASSERT_THROW(list.insert(1, -1), std::out_of_range);
  ASSERT_THROW(list.insert(1, 20), std::out_of_range);
}

TEST_F(ArrayListTest, InsertsAtTheRightPlace) {
  for (auto i = 0; i < list.max_size() - 1; i++) {
    list.push_back(i);
  }

  list.insert(10, 5);
  ASSERT_EQ(list.size(), 20);
  ASSERT_EQ(list.contents[4], 4);
  ASSERT_EQ(list.contents[5], 10);
  ASSERT_EQ(list.contents[6], 5);
}
