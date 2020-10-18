#include <stdexcept>

#include "linked_queue.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class LinkedQueueTest : public ::testing::Test {
 protected:
  structures::LinkedQueue<int> queue{};

  void fill(void) {
    for (auto i = 0; i < 10; i++) {
      queue.enqueue(i);
    }
  }
};

TEST_F(LinkedQueueTest, SizeReturnsCorrectValue) {
  ASSERT_EQ(0, queue.size());

  fill();
  ASSERT_EQ(10, queue.size());
}

TEST_F(LinkedQueueTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(queue.empty());
}

TEST_F(LinkedQueueTest, EmptyReturnsFalseWhenNotEmpty) {
  fill();
  ASSERT_FALSE(queue.empty());
}

TEST_F(LinkedQueueTest, EnqueueIncreasesSize) {
  queue.enqueue(1);
  ASSERT_EQ(1, queue.size());
  queue.enqueue(1);
  ASSERT_EQ(2, queue.size());
}

TEST_F(LinkedQueueTest, EnqueuesData) {
  for (auto i = 0; i < 10; i++) {
    queue.enqueue(i);
    ASSERT_EQ(i, queue.back());
  }
}

TEST_F(LinkedQueueTest, BackReturnCorrectElement) {
  for (auto i = 0; i < 10; i++) {
    queue.enqueue(i);
    ASSERT_EQ(i, queue.back());
  }
}

TEST_F(LinkedQueueTest, BackThrowsErrorOnEmptyQueue) {
  ASSERT_THROW(queue.back(), std::out_of_range);
}

TEST_F(LinkedQueueTest, BackWorksAsLhs) {
  fill();
  queue.back() = -2;
  ASSERT_EQ(-2, queue.back());
}

TEST_F(LinkedQueueTest, ClearSetsSize0) {
  fill();
  queue.clear();
  ASSERT_EQ(0, queue.size());
}

TEST_F(LinkedQueueTest, DequeueDecreasesSize) {
  fill();
  for (auto i = 9; i >= 0; i--) {
    queue.dequeue();
    ASSERT_EQ(i, queue.size());
  }
}

TEST_F(LinkedQueueTest, DequeueThrowsErrorWhenEmpty) {
  ASSERT_THROW(queue.dequeue(), std::out_of_range);
}

TEST_F(LinkedQueueTest, DequeueReturnsCorrectElement) {
  fill();

  for (auto i = 0; i < 10; i++) {
    ASSERT_EQ(i, queue.dequeue());
  }
}
