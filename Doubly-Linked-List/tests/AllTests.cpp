
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
  //ASSERT_EQ(list.find(0), 1);

  fill();
  ASSERT_EQ(list.find(11), 10);
}
