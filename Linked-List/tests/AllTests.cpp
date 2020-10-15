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

class LinkedListTest : public ::testing::Test {
 protected:
  structures::LinkedList<int> list{};
};

TEST_F(LinkedListTest, OnInitSizeIsZero) { ASSERT_EQ(list.size(), 0u); }

TEST_F(LinkedListTest, SizeReturnsCorrectSize) {
  ASSERT_EQ(list.size(), 0u);

  list.push_front(0);
  ASSERT_EQ(list.size(), 1u);
}

TEST_F(LinkedListTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_EQ(list.empty(), true);
}

TEST_F(LinkedListTest, EmptyReturnsFalseWhenNotEmpty) {
  list.push_front(0);
  ASSERT_EQ(list.empty(), false);
}

TEST_F(LinkedListTest, ClearDeletesAllNodes) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  ASSERT_EQ(list.size(), 10);

  list.clear();
  ASSERT_EQ(list.size(), 0);
}

TEST_F(LinkedListTest, AtThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.at(0), std::out_of_range);
}

TEST_F(LinkedListTest, AtThrowsErrorWhenOutOfBounds) {
  list.push_front(0);
  ASSERT_THROW(list.at(1), std::out_of_range);
}

TEST_F(LinkedListTest, AtReturnsDataAtIndex) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  for (auto i = 0; i < 10; i++) {
    ASSERT_EQ(list.at(i), 9 - i);
  }
}

TEST_F(LinkedListTest, PushFrontIncreasesSize) {
  list.push_front(0);
  ASSERT_EQ(list.size(), 1u);
}

TEST_F(LinkedListTest, PushFrontAddsNewNodeToTheBeginningOfTheList) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
    ASSERT_EQ(list.at(0), i);
  }
}

TEST_F(LinkedListTest, InsertThrowsErroWhenOutOfBounds) {
  ASSERT_THROW(list.insert(1, -1), std::out_of_range);
  ASSERT_THROW(list.insert(1, 1), std::out_of_range);
}

TEST_F(LinkedListTest, InsertAt0PushesFront) {
  list.insert(0, 0);
  ASSERT_EQ(list.at(0), 0);

  list.insert(1, 0);
  ASSERT_EQ(list.at(0), 1);
}

TEST_F(LinkedListTest, InsertIncreasesSize) {
  list.insert(0, 0);
  ASSERT_EQ(list.size(), 1);

  list.insert(1, 1);
  ASSERT_EQ(list.size(), 2);
}

TEST_F(LinkedListTest, InsertInsertsAtIndex) {
  for (auto i = 9; i >= 0; i--) {
    list.push_front(i);
  }

  list.insert(-5, 1);
  ASSERT_EQ(list.at(0), 0);
  ASSERT_EQ(list.at(1), -5);
  ASSERT_EQ(list.at(2), 1);
}

TEST_F(LinkedListTest, PopThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.pop(0), std::out_of_range);
}

TEST_F(LinkedListTest, PopThrowsErrorWhenOutOfBounds) {
  ASSERT_THROW(list.pop(-1), std::out_of_range);

  list.push_front(0);
  ASSERT_THROW(list.pop(1), std::out_of_range);
}

TEST_F(LinkedListTest, PopDecreasesSize) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  ASSERT_EQ(list.size(), 10);
  list.pop(5);
  ASSERT_EQ(list.size(), 9);
}

TEST_F(LinkedListTest, PopIndexZeroPopsFront) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  for (auto i = 9; i >= 0; i--) {
    ASSERT_EQ(list.pop(0), i);
  }
}

TEST_F(LinkedListTest, PopPopsAtIndex) {
  for (auto i = 9; i >= 0; i--) {
    list.push_front(i);
  }

  ASSERT_EQ(list.pop(5), 5);
  ASSERT_EQ(list.pop(0), 0);
  ASSERT_EQ(list.pop(7), 9);
}

TEST_F(LinkedListTest, PushBackIncreasesSize) {
  ASSERT_EQ(list.size(), 0);
  list.push_back(0);
  ASSERT_EQ(list.size(), 1);
}

TEST_F(LinkedListTest, PushBackPushesBack) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
    ASSERT_EQ(list.at(i), i);
  }
}

TEST_F(LinkedListTest, InsertSortedInsertsAtTheCorrectPlace) {
  list.push_back(0);
  list.push_back(2);
  list.push_back(4);

  list.insert_sorted(-1);
  ASSERT_EQ(list.at(0), -1);
  list.insert_sorted(1);
  ASSERT_EQ(list.at(2), 1);
  list.insert_sorted(5);
  ASSERT_EQ(list.at(5), 5);
}

TEST_F(LinkedListTest, PopBackRemovesLastNode) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  for (auto i = 9; i >= 0; i--) {
    ASSERT_EQ(list.pop_back(), i);
  }
}

TEST_F(LinkedListTest, FindReturnsElementIndex) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  ASSERT_EQ(list.find(0), 0);
  ASSERT_EQ(list.find(5), 5);
  ASSERT_EQ(list.find(9), 9);
}

TEST_F(LinkedListTest, ContainsReturnsTrueWhenContains) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  ASSERT_TRUE(list.contains(0));
  ASSERT_TRUE(list.contains(5));
  ASSERT_TRUE(list.contains(9));
}

TEST_F(LinkedListTest, ContainsReturnsFalseWhenDontContain) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  ASSERT_FALSE(list.contains(-1));
  ASSERT_FALSE(list.contains(10));
}

TEST_F(LinkedListTest, RemoveThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.remove(0), std::out_of_range);
}

TEST_F(LinkedListTest, RemoveThrowsErrorWhenDoesntContains) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  ASSERT_THROW(list.remove(-1), std::out_of_range);
  ASSERT_THROW(list.remove(10), std::out_of_range);
}

TEST_F(LinkedListTest, RemovePopsData) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  list.remove(0);
  ASSERT_FALSE(list.contains(0));
  list.remove(5);
  ASSERT_FALSE(list.contains(5));
  list.remove(9);
  ASSERT_FALSE(list.contains(9));
}

TEST_F(LinkedListTest, OperatorOverloaded) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  ASSERT_EQ(list[0], 0);
  ASSERT_EQ(list[5], 5);
  ASSERT_EQ(list[9], 9);
}
