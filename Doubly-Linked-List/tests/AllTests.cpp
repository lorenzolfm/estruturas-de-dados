#include "gtest/gtest.h"
#include "doubly_linked_list.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class DoublyLinkedListTest : public ::testing::Test {
  protected:
    structures::DoublyLinkedList<int> list{};

    void fill(void) {
      for (auto i = 0; i < 10; i++) {
        list.push_front(i);
      }
    }
};

TEST_F(DoublyLinkedListTest, OnInitSizeIsZero) { ASSERT_EQ(list.size(), 0u); }

TEST_F(DoublyLinkedListTest, SizeReturnsCorrectSize) {
  ASSERT_EQ(list.size(), 0u);

  list.push_front(0);
  ASSERT_EQ(list.size(), 1u);
}

TEST_F(DoublyLinkedListTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_EQ(list.empty(), true);
}

TEST_F(DoublyLinkedListTest, EmptyReturnsFalseWhenNotEmpty) {
  list.push_front(0);
  ASSERT_EQ(list.empty(), false);
}

TEST_F(DoublyLinkedListTest, ClearDeletesAllNodes) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  ASSERT_EQ(list.size(), 10);

  list.clear();
  ASSERT_EQ(list.size(), 0);
}

TEST_F(DoublyLinkedListTest, AtThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.at(0), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, AtThrowsErrorWhenOutOfBounds) {
  list.push_front(0);
  ASSERT_THROW(list.at(1), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, AtReturnsDataAtIndex) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  for (auto i = 0; i < 10; i++) {
    ASSERT_EQ(list.at(i), 9 - i);
  }
}

TEST_F(DoublyLinkedListTest, PushFrontIncreasesSize) {
  list.push_front(0);
  ASSERT_EQ(list.size(), 1u);
}

TEST_F(DoublyLinkedListTest, PushFrontAddsNewNodeToTheBeginningOfTheList) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
    ASSERT_EQ(list.at(0), i);
  }
}

TEST_F(DoublyLinkedListTest, FindReturnsElementIndex) {
  fill();

  ASSERT_EQ(list.find(0), 9);
  ASSERT_EQ(list.find(5), 4);
  ASSERT_EQ(list.find(9), 0);
}

TEST_F(DoublyLinkedListTest, FindReturnsSizePlusOneWhenNotThere) {
  fill();
  ASSERT_EQ(list.find(11), 10);
}

TEST_F(DoublyLinkedListTest, FindThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.find(0), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, ContainsReturnsTrueWhenContains) {
  fill();

  ASSERT_TRUE(list.contains(0));
  ASSERT_TRUE(list.contains(5));
  ASSERT_TRUE(list.contains(9));
}

TEST_F(DoublyLinkedListTest, ContainsReturnsFalseWhenDontContain) {
  fill();

  ASSERT_FALSE(list.contains(-1));
  ASSERT_FALSE(list.contains(10));
}

TEST_F(DoublyLinkedListTest, ContainsThrowsErrorOnEmptyList) {
  ASSERT_THROW(list.contains(0), std::out_of_range);
}


TEST_F(DoublyLinkedListTest, InsertThrowsErroWhenOutOfBounds) {
  ASSERT_THROW(list.insert(1, -1), std::out_of_range);
  ASSERT_THROW(list.insert(1, 1), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, InsertAt0PushesFront) {
  list.insert(0, 0);
  ASSERT_EQ(list.at(0), 0);

  list.insert(1, 0);
  ASSERT_EQ(list.at(0), 1);
}

TEST_F(DoublyLinkedListTest, InsertIncreasesSize) {
  list.insert(0, 0);
  ASSERT_EQ(list.size(), 1);

  list.insert(1, 1);
  ASSERT_EQ(list.size(), 2);
}

TEST_F(DoublyLinkedListTest, InsertInsertsAtIndex) {
  for (auto i = 9; i >= 0; i--) {
    list.push_front(i);
  }

  list.insert(-5, 1);
  ASSERT_EQ(list.at(0), 0);
  ASSERT_EQ(list.at(1), -5);
  ASSERT_EQ(list.at(2), 1);
}

TEST_F(DoublyLinkedListTest, InsertSortedInsertsAtTheCorrectPlace) {
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

TEST_F(DoublyLinkedListTest, PopThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.pop(0), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, PopThrowsErrorWhenOutOfBounds) {
  ASSERT_THROW(list.pop(-1), std::out_of_range);

  list.push_front(0);
  ASSERT_THROW(list.pop(1), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, PopDecreasesSize) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  ASSERT_EQ(list.size(), 10);
  list.pop(5);
  ASSERT_EQ(list.size(), 9);
}

TEST_F(DoublyLinkedListTest, PopIndexZeroPopsFront) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  for (auto i = 9; i >= 0; i--) {
    ASSERT_EQ(list.pop(0), i);
  }
}

TEST_F(DoublyLinkedListTest, PopPopsAtIndex) {
  for (auto i = 9; i >= 0; i--) {
    list.push_front(i);
  }

  ASSERT_EQ(list.pop(5), 5);
  ASSERT_EQ(list.pop(0), 0);
  ASSERT_EQ(list.pop(7), 9);
}

TEST_F(DoublyLinkedListTest, PopBackRemovesLastNode) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  for (auto i = 9; i >= 0; i--) {
    ASSERT_EQ(list.pop_back(), i);
  }
}

TEST_F(DoublyLinkedListTest, RemoveThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.remove(0), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, RemoveThrowsErrorWhenDoesntContains) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  ASSERT_THROW(list.remove(-1), std::out_of_range);
  ASSERT_THROW(list.remove(10), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, RemovePopsData) {
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
