#include "gtest/gtest.h"
#include "circular_list.h"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class CircularListTest: public ::testing::Test {
 protected:
    structures::CircularList<int> list{};

    void fill(void) {
      for (auto i = 0; i < 10; i++) {
        list.push_front(i);
      }
    }
};

TEST_F(CircularListTest, ConstructorSetsSizeTo0) {
    ASSERT_EQ(list.size(), 0u);
}

TEST_F(CircularListTest, OnInitSizeIsZero) { ASSERT_EQ(list.size(), 0u); }

TEST_F(CircularListTest, SizeReturnsCorrectSize) {
  ASSERT_EQ(list.size(), 0u);

  list.push_front(0);
  ASSERT_EQ(list.size(), 1u);
}

TEST_F(CircularListTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_EQ(list.empty(), true);
}

TEST_F(CircularListTest, EmptyReturnsFalseWhenNotEmpty) {
  list.push_front(0);
  ASSERT_EQ(list.empty(), false);
}

TEST_F(CircularListTest, ClearDeletesAllNodes) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  ASSERT_EQ(list.size(), 10);

  list.clear();
  ASSERT_EQ(list.size(), 0);
}

TEST_F(CircularListTest, AtThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.at(0), std::out_of_range);
}

TEST_F(CircularListTest, AtThrowsErrorWhenOutOfBounds) {
  list.push_front(0);
  ASSERT_THROW(list.at(1), std::out_of_range);
}

TEST_F(CircularListTest, AtReturnsDataAtIndex) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  for (auto i = 0; i < 10; i++) {
    ASSERT_EQ(list.at(i), 9 - i);
  }
}

TEST_F(CircularListTest, PushFrontIncreasesSize) {
  list.push_front(0);
  ASSERT_EQ(list.size(), 1u);
}

TEST_F(CircularListTest, PushFrontAddsNewNodeToTheBeginningOfTheList) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
    ASSERT_EQ(list.at(0), i);
  }
}

TEST_F(CircularListTest, FindReturnsElementIndex) {
  fill();

  ASSERT_EQ(list.find(0), 9);
  ASSERT_EQ(list.find(5), 4);
  ASSERT_EQ(list.find(9), 0);
}

TEST_F(CircularListTest, FindReturnsSizePlusOneWhenNotThere) {
  fill();
  ASSERT_EQ(list.find(11), 10);
}

TEST_F(CircularListTest, FindThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.find(0), std::out_of_range);
}

TEST_F(CircularListTest, ContainsReturnsTrueWhenContains) {
  fill();

  ASSERT_TRUE(list.contains(0));
  ASSERT_TRUE(list.contains(5));
  ASSERT_TRUE(list.contains(9));
}

TEST_F(CircularListTest, ContainsReturnsFalseWhenDontContain) {
  fill();

  ASSERT_FALSE(list.contains(-1));
  ASSERT_FALSE(list.contains(10));
}

TEST_F(CircularListTest, ContainsThrowsErrorOnEmptyList) {
  ASSERT_THROW(list.contains(0), std::out_of_range);
}


TEST_F(CircularListTest, InsertThrowsErroWhenOutOfBounds) {
  ASSERT_THROW(list.insert(1, -1), std::out_of_range);
  ASSERT_THROW(list.insert(1, 1), std::out_of_range);
}

TEST_F(CircularListTest, InsertAt0PushesFront) {
  list.insert(0, 0);
  ASSERT_EQ(list.at(0), 0);

  list.insert(1, 0);
  ASSERT_EQ(list.at(0), 1);
}

TEST_F(CircularListTest, InsertIncreasesSize) {
  list.insert(0, 0);
  ASSERT_EQ(list.size(), 1);

  list.insert(1, 1);
  ASSERT_EQ(list.size(), 2);
}

TEST_F(CircularListTest, InsertInsertsAtIndex) {
  for (auto i = 9; i >= 0; i--) {
    list.push_front(i);
  }

  list.insert(-5, 1);
  ASSERT_EQ(list.at(0), 0);
  ASSERT_EQ(list.at(1), -5);
  ASSERT_EQ(list.at(2), 1);
}

TEST_F(CircularListTest, InsertSortedInsertsAtTheCorrectPlace) {
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

TEST_F(CircularListTest, PopThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.pop(0), std::out_of_range);
}

TEST_F(CircularListTest, PopThrowsErrorWhenOutOfBounds) {
  ASSERT_THROW(list.pop(-1), std::out_of_range);

  list.push_front(0);
  ASSERT_THROW(list.pop(1), std::out_of_range);
}

TEST_F(CircularListTest, PopDecreasesSize) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  ASSERT_EQ(list.size(), 10);
  list.pop(5);
  ASSERT_EQ(list.size(), 9);
}

TEST_F(CircularListTest, PopIndexZeroPopsFront) {
  for (auto i = 0; i < 10; i++) {
    list.push_front(i);
  }

  for (auto i = 9; i >= 0; i--) {
    ASSERT_EQ(list.pop(0), i);
  }
}

TEST_F(CircularListTest, PopPopsAtIndex) {
  for (auto i = 9; i >= 0; i--) {
    list.push_front(i);
  }

  ASSERT_EQ(list.pop(5), 5);
  ASSERT_EQ(list.pop(0), 0);
  ASSERT_EQ(list.pop(7), 9);
}

TEST_F(CircularListTest, PopBackRemovesLastNode) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  for (auto i = 9; i >= 0; i--) {
    ASSERT_EQ(list.pop_back(), i);
  }
}

TEST_F(CircularListTest, RemoveThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.remove(0), std::out_of_range);
}

TEST_F(CircularListTest, RemoveThrowsErrorWhenDoesntContains) {
  for (auto i = 0; i < 10; i++) {
    list.push_back(i);
  }

  ASSERT_THROW(list.remove(-1), std::out_of_range);
  ASSERT_THROW(list.remove(10), std::out_of_range);
}

TEST_F(CircularListTest, RemovePopsData) {
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
