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

  void fill(void) {
    for (auto i = 0; i < queue.max_size(); i++) {
      queue.enqueue(i);
    }
  }
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

TEST_F(ArrayQueueTest, EnqueueIncreasesSize) {
  queue.enqueue(1);
  ASSERT_EQ(1, queue.size());
  queue.enqueue(1);
  ASSERT_EQ(2, queue.size());
}

TEST_F(ArrayQueueTest, EnqueueThrowsErrorWhenFull) {
  fill();

  ASSERT_THROW(queue.enqueue(5), std::out_of_range);
}

TEST_F(ArrayQueueTest, EnqueuesDataOnContents) {
  for (auto i = 0; i < queue.max_size(); i ++) {
    queue.enqueue(i);
    ASSERT_EQ(i, queue.contents[i]);
  }
}

TEST_F(ArrayQueueTest, DequeueDecreasesSize){
  fill();
  for (auto i = 19; i >= 0; i--) {
    queue.dequeue();
    ASSERT_EQ(i, queue.size());
  }
}

TEST_F(ArrayQueueTest, DequeueThrowsErrorWhenEmpty) {
  ASSERT_THROW(queue.dequeue(), std::out_of_range);
}

TEST_F(ArrayQueueTest, DequeueReturnsCorrectElement) {
  fill();
  for (auto i = 19; i >= 0; i--) {
    ASSERT_EQ(i, queue.dequeue());
  }
}
