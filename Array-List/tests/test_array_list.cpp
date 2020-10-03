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
  ASSERT_EQ(0, list.size());
  ASSERT_EQ(0, list.size());
}

TEST_F(ArrayListTest, ConstructorInitializesCorrectMaxSize) {
  ASSERT_EQ(20, list.max_size());
  ASSERT_EQ(10, default_list.max_size());
}

TEST_F(ArrayListTest, ClearSetsSizeToMinusOne) {
  push_back_fill();
  ASSERT_EQ(20, list.size());
  list.clear();
  ASSERT_EQ(0, list.size());
}

TEST_F(ArrayListTest, MaxSizeReturnCorrectValue) {
  ASSERT_EQ(20, list.max_size());
  ASSERT_EQ(10, default_list.max_size());
}

TEST_F(ArrayListTest, SizeReturnsCorrectValue) {
  ASSERT_EQ(0, list.size());
  push_back_fill();
  ASSERT_EQ(20, list.size());
}

TEST_F(ArrayListTest, EmptyReturnsTrueWhenEmpty) { ASSERT_TRUE(list.empty()); }

TEST_F(ArrayListTest, EmptyReturnsFalseWhenNotEmpty) {
  list.push_back(1);
  ASSERT_FALSE(list.empty());
}

TEST_F(ArrayListTest, FullReturnsTrueWhenFull) {
  push_back_fill();
  ASSERT_TRUE(list.full());
}

TEST_F(ArrayListTest, FullReturnsFalseWhenNotFull) {
  ASSERT_FALSE(list.full());
  push_back_fill();
  list.pop_back();
  ASSERT_FALSE(list.full());
}

TEST_F(ArrayListTest, PushBackIncreasesSize) {
  ASSERT_EQ(0, list.size());
  list.push_back(1);
  ASSERT_EQ(1, list.size());
}

TEST_F(ArrayListTest, PushBackThrowsErrorWhenFull) {
  push_back_fill();
  ASSERT_THROW(list.push_back(10), std::out_of_range);
}

TEST_F(ArrayListTest, PushBackAddDataToEndOfList) {
  push_back_fill();
  for (auto i = 0; i < list.max_size(); i++) {
    ASSERT_EQ(i, list[i]);
  }
}

TEST_F(ArrayListTest, PopBackDecreasesSize) {
  push_back_fill();
  list.pop_back();
  ASSERT_EQ(19, list.size());
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
    ASSERT_EQ(i, list[i + 1]);
  }
}

TEST_F(ArrayListTest, PushFrontInsertsDataInAtIndex0) {
  for (auto i = 0; i < list.max_size(); i++) {
    list.push_front(i);
    ASSERT_EQ(i, list[0]);
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
  ASSERT_THROW(list.insert(1, 1), std::out_of_range);
}

TEST_F(ArrayListTest, InsertsAtTheRightPlace) {
  for (auto i = 0; i < list.max_size() - 1; i++) {
    list.push_back(i);
  }

  list.insert(10, 5);
  ASSERT_EQ(list.size(), 20);
  ASSERT_EQ(list[4], 4);
  ASSERT_EQ(list[5], 10);
  ASSERT_EQ(list[6], 5);
}

TEST_F(ArrayListTest, PopThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.pop(10), std::out_of_range);
}

TEST_F(ArrayListTest, PopThowsErrorWhenInvalidIndex) {
  push_back_fill();
  ASSERT_THROW(list.pop(-1), std::out_of_range);
  ASSERT_THROW(list.pop(20), std::out_of_range);
}

TEST_F(ArrayListTest, PopsTheCorrectElement) {
  push_back_fill();
  ASSERT_EQ(5, list.pop(5));
  ASSERT_EQ(6, list.pop(5));
  ASSERT_EQ(0, list.pop(0));
}

TEST_F(ArrayListTest, InsertSortedThrowsErrorWhenFull) {
  push_back_fill();
  ASSERT_THROW(list.insert_sorted(5), std::out_of_range);
}

TEST_F(ArrayListTest, InsertInOrderIncreasesSize) {
  for (auto i = 0; i < list.max_size(); i++) {
    list.insert_sorted(i);
    ASSERT_EQ(i + 1, list.size());
  }
}

TEST_F(ArrayListTest, InsertInOrder) {
  for (auto i = 19; i >= 0; --i) {
    list.insert_sorted(i);
  }

  for (auto i = 0; i < list.max_size(); ++i) {
    ASSERT_EQ(i, list[i]);
  }

  list.clear();

  list.insert_sorted(10);
  list.insert_sorted(-10);
  list.insert_sorted(42);
  list.insert_sorted(0);
  ASSERT_EQ(-10, list[0]);
  ASSERT_EQ(0, list[1]);
  ASSERT_EQ(10, list[2]);
  ASSERT_EQ(42, list[3]);
}

TEST_F(ArrayListTest, ContainsReturnsTrueWhenContainsData) {
  push_back_fill();
  for (auto i = 0; i < list.max_size(); i++) {
    ASSERT_TRUE(list.contains(i));
  }
}

TEST_F(ArrayListTest, ContainsReturnsFalseWhenDoesntContainsData) {
  push_back_fill();

  ASSERT_FALSE(list.contains(500));
  ASSERT_FALSE(list.contains(-1));
}

TEST_F(ArrayListTest, FindReturnsSizeWhenElementNotFound) {
  push_back_fill();
  ASSERT_EQ(list.find(500), list.size());
}

TEST_F(ArrayListTest, FindReturnsTheIndexOfData) {
  push_back_fill();
  for (auto i = 0; i < list.max_size(); i++) {
    ASSERT_EQ(i, list.find(i));
  }
}

TEST_F(ArrayListTest, RemoveThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.remove(10), std::out_of_range);
}

TEST_F(ArrayListTest, RemoveElementNotContainedReturnsSize) {
  push_back_fill();
  ASSERT_THROW(list.remove(500), std::invalid_argument);
}

TEST_F(ArrayListTest, RemoveElementReturnsTheCorrectElement) {
  push_back_fill();

  list.remove(3);
  ASSERT_EQ(19, list.size());
  ASSERT_FALSE(list.contains(3));
}

TEST_F(ArrayListTest, AccessOnIndexGreaterThenSize) {
  ASSERT_THROW(list[0], std::out_of_range);
  ASSERT_THROW(list.at(0), std::out_of_range);

  list.push_back(0);
  ASSERT_THROW(list[1], std::out_of_range);
  ASSERT_THROW(list.at(1), std::out_of_range);
}

TEST_F(ArrayListTest, AccessOnNegativeIndex) {
  ASSERT_THROW(list[-1], std::out_of_range);
  ASSERT_THROW(list.at(-2), std::out_of_range);
}

TEST_F(ArrayListTest, IndexAccess) {
  for (auto i = 0; i < list.max_size(); i++) {
    list.push_back(i);
  }

  for (auto i = 0; i < list.max_size(); i++) {
    ASSERT_EQ(list.at(i), i);
    ASSERT_EQ(list[i], i);
  }
}
