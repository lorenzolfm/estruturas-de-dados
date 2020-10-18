
#include <stdlib.h>

#include "gtest/gtest.h"
#include "linked_stack.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class LinkedStackTest : public ::testing::Test {
 protected:
  structures::LinkedStack<int> stack{};

  void fill(void) {
    for (auto i = 0; i < 10; i++) {
      stack.push(i);
    }
  }
};

TEST_F(LinkedStackTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(stack.empty());
}

TEST_F(LinkedStackTest, EmptyReturnsFalseWhenNotEmpty) {
  stack.push(0);
  ASSERT_FALSE(stack.empty());
}

TEST_F(LinkedStackTest, ClearStackSuccessfully) {
  fill();
  stack.clear();
  ASSERT_EQ(0, stack.size());
}

TEST_F(LinkedStackTest, PushIncreasesSize) {
  stack.push(1);
  ASSERT_EQ(1, stack.size());
}

TEST_F(LinkedStackTest, PushPushesData) {
  stack.push(1);
  ASSERT_EQ(1, stack.top());

  stack.push(2);
  ASSERT_EQ(2, stack.top());
}

TEST_F(LinkedStackTest, PopDecreasesSize) {
  fill();
  stack.pop();

  ASSERT_EQ(stack.size(), 10 - 1);

  stack.pop();
  ASSERT_EQ(stack.size(), 10 - 2);
}

TEST_F(LinkedStackTest, PopCorrectElement) {
  fill();
  for (auto i = 0u; i < 10; ++i) {
    ASSERT_EQ((10 - 1) - i, stack.pop());
  }
}

TEST_F(LinkedStackTest, PopFromEmptyThrowsError) {
  ASSERT_THROW(stack.pop(), std::out_of_range);

  fill();
  for (auto i = 0u; i < 10; ++i) {
    ASSERT_EQ((10 - 1) - i, stack.pop());
  }

  ASSERT_THROW(stack.pop(), std::out_of_range);
}

TEST_F(LinkedStackTest, TopReturnsTopElement) {
  fill();
  for (auto i = 0u; i < 10; ++i) {
    ASSERT_EQ(9 - i, stack.top());
    stack.pop();
  }
}

TEST_F(LinkedStackTest, TopOnEmptyThrowsError) {
  ASSERT_THROW(stack.top(), std::out_of_range);
}

TEST_F(LinkedStackTest, TopAsLhsWorks) {
  fill();
  stack.top() = -2;
  ASSERT_EQ(-2, stack.top());
}
