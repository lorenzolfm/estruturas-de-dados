#include <stdexcept>

#include "array_queue.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class ArrayQueueTest : public ::testing::Test {
 protected:
  structures::ArrayQueue<int> queue{20};
  structures::ArrayQueue<int> default_queue{};
};

TEST_F(ArrayQueueTest, ConstructorSetsCorrectMaxSize) {
  ASSERT_EQ(10u, default_queue.max_size_);
  ASSERT_EQ(20u, queue.max_size_);
}

TEST_F(ArrayQueueTest, ConstructorSetsCorrectSize) {
  ASSERT_EQ(-1, default_queue.size_);
  ASSERT_EQ(-1, queue.size_);
}

TEST_F(ArrayQueueTest, MaxSizeReturnCorrectValue) {
  ASSERT_EQ(20u, queue.max_size());
}

TEST_F(ArrayQueueTest, SizeReturnsCorrectValue) {
  ASSERT_EQ(0, queue.size());

  queue.size_ = 10;
  ASSERT_EQ(11, queue.size());
}

TEST_F(ArrayQueueTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(queue.empty());
}

TEST_F(ArrayQueueTest, EmptyReturnsFalseWhenNotEmpty) {
  queue.size_ = 3;
  ASSERT_FALSE(queue.empty());
}

TEST_F(ArrayQueueTest, FullReturnsTrueWhenFull) {
  queue.size_ = 19;
  ASSERT_TRUE(queue.full());
}

TEST_F(ArrayQueueTest, FullReturnsFalseWhenNotFull) {
  ASSERT_FALSE(queue.full());
}
