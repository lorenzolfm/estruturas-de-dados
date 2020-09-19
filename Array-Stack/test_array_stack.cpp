#include <stdexcept>

#include "array_stack.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class ArrayStackTest : public ::testing::Test {
 protected:
  structures::ArrayStack<int> stack{20u};
  structures::ArrayStack<int> default_stack{};

  void fill() {
    for (auto i = 0; i < stack.max_size(); i++) {
      stack.push(i);
    }
  }
};

TEST_F(ArrayStackTest, DefaultStackReturnsDefaultMasSize) {
  ASSERT_EQ(10u, default_stack.max_size());
}

TEST_F(ArrayStackTest, StackWithSetMaxSizeReturnsCorrectValue) {
  ASSERT_EQ(20u, stack.max_size());
}

TEST_F(ArrayStackTest, EmptyStacksReturnsCorrectSize) {
  ASSERT_EQ(0, stack.size());
  ASSERT_EQ(0, default_stack.size());
}

TEST_F(ArrayStackTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(stack.empty());
}

TEST_F(ArrayStackTest, EmptyReturnsFalseWhenNotEmpty) {
  stack.push(0);
  ASSERT_FALSE(stack.empty());
}

TEST_F(ArrayStackTest, FullReturnsFalseWhenNotFull) {
  ASSERT_FALSE(stack.full());
}

TEST_F(ArrayStackTest, FullReturnsTrueWhenFull) {
  fill();
  ASSERT_TRUE(stack.full());
}

TEST_F(ArrayStackTest, ClearStackSuccessfully) {
  fill();
  stack.clear();
  ASSERT_EQ(0, stack.size());
}

TEST_F(ArrayStackTest, PushIncreasesSize) {
  stack.push(1);
  ASSERT_EQ(1, stack.size());
}

TEST_F(ArrayStackTest, PushPushesData) {
  stack.push(1);
  ASSERT_EQ(1, stack.top());

  stack.push(2);
  ASSERT_EQ(2, stack.top());
}

TEST_F(ArrayStackTest, ThrowsErrorWhenPushOnFull) {
  fill();
  ASSERT_TRUE(stack.full());
  ASSERT_THROW(stack.push(1), std::out_of_range);
}

TEST_F(ArrayStackTest, PopDecreasesSize) {
  fill();
  stack.pop();

  ASSERT_EQ(stack.size(), stack.max_size() - 1);

  stack.pop();
  ASSERT_EQ(stack.size(), stack.max_size() - 2);
}

TEST_F(ArrayStackTest, PopCorrectElement) {
  fill();
  for (auto i = 0u; i < stack.max_size(); ++i) {
    ASSERT_EQ((stack.max_size() - 1) - i, stack.pop());
  }
}

TEST_F(ArrayStackTest, PopFromEmptyThrowsError) {
  ASSERT_THROW(stack.pop(), std::out_of_range);

  fill();
  for (auto i = 0u; i < stack.max_size(); ++i) {
    ASSERT_EQ((stack.max_size() - 1) - i, stack.pop());
  }

  ASSERT_THROW(stack.pop(), std::out_of_range);
}

TEST_F(ArrayStackTest, TopReturnsTopElement) {
  fill();
  for (auto i = 0u; i < stack.max_size(); ++i) {
    ASSERT_EQ((stack.max_size() - 1) - i, stack.top());
    stack.pop();
  }
}

TEST_F(ArrayStackTest, TopOnEmptyThrowsError) {
  ASSERT_THROW(stack.top(), std::out_of_range);
}
