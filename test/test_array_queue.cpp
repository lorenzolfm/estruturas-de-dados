#include <stdexcept>

#include "../include/array_queue.h"
#include "gtest/gtest.h"

//int main(int argc, char* argv[]) {
  //std::srand(std::time(NULL));
  //::testing::InitGoogleTest(&argc, argv);
  ////::testing::FLAGS_gtest_death_test_style = "fast";
  //return RUN_ALL_TESTS();
//}

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
  ASSERT_EQ(10u, default_queue.max_size());
  ASSERT_EQ(20u, queue.max_size());
}

TEST_F(ArrayQueueTest, ConstructorSetsCorrectSize) {
  ASSERT_EQ(0, default_queue.size());
  ASSERT_EQ(0, queue.size());
}

TEST_F(ArrayQueueTest, MaxSizeReturnCorrectValue) {
  ASSERT_EQ(20u, queue.max_size());
}

TEST_F(ArrayQueueTest, SizeReturnsCorrectValue) {
  ASSERT_EQ(0, queue.size());

  fill();
  ASSERT_EQ(20, queue.size());
}

TEST_F(ArrayQueueTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(queue.empty());
}

TEST_F(ArrayQueueTest, EmptyReturnsFalseWhenNotEmpty) {
  fill();
  ASSERT_FALSE(queue.empty());
}

TEST_F(ArrayQueueTest, FullReturnsTrueWhenFull) {
  fill();
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
  for (auto i = 0; i < queue.max_size(); i++) {
    queue.enqueue(i);
    ASSERT_EQ(i, queue.back());
  }
}

TEST_F(ArrayQueueTest, BackReturnCorrectElement) {
  for (auto i = 0; i < queue.max_size(); i++) {
    queue.enqueue(i);
    ASSERT_EQ(i, queue.back());
  }
}

TEST_F(ArrayQueueTest, BackThrowsErrorOnEmptyQueue) {
  ASSERT_THROW(queue.back(), std::out_of_range);
}

TEST_F(ArrayQueueTest, BackWorksAsLhs) {
  fill();
  queue.back() = -2;
  ASSERT_EQ(-2, queue.back());
}

TEST_F(ArrayQueueTest, ClearSetsSizeToMinusOne) {
  fill();
  queue.clear();
  ASSERT_EQ(0, queue.size());
}

TEST_F(ArrayQueueTest, DequeueDecreasesSize) {
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

  for (auto i = 0; i < queue.max_size(); i++) {
    ASSERT_EQ(i, queue.dequeue());
  }
}
