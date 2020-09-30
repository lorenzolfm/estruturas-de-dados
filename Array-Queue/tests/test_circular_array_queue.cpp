#include "circular_array_queue.h"
#include <stdexcept>
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class CircularArrayQueueTest : public ::testing::Test {
 protected:
  structures::CircularArrayQueue<int> circular_queue{20};
  structures::CircularArrayQueue<int> default_circular_queue{};

  void fill(void) {
    for (auto i = 0; i < circular_queue.max_size(); i++) {
      circular_queue.enqueue(i);
    }
  }
};

TEST_F(CircularArrayQueueTest, ConstructorSetsCorrectMaxSize) {
  ASSERT_EQ(10u, default_circular_queue.max_size());
  ASSERT_EQ(20u, circular_queue.max_size());
}

TEST_F(CircularArrayQueueTest, ConstructorSetsCorrectSize) {
  ASSERT_EQ(0, default_circular_queue.size());
  ASSERT_EQ(0, circular_queue.size());
}

TEST_F(CircularArrayQueueTest, MaxSizeReturnCorrectValue) {
  ASSERT_EQ(20u, circular_queue.max_size());
}

TEST_F(CircularArrayQueueTest, SizeReturnsCorrectValue) {
  ASSERT_EQ(0, circular_queue.size());

  fill();
  ASSERT_EQ(20, circular_queue.size());
}

TEST_F(CircularArrayQueueTest, EmptyReturnsTrueWhenEmpty) {
  ASSERT_TRUE(circular_queue.empty());
}

TEST_F(CircularArrayQueueTest, EmptyReturnsFalseWhenNotEmpty) {
  fill();
  ASSERT_FALSE(circular_queue.empty());
}

TEST_F(CircularArrayQueueTest, FullReturnsTrueWhenFull) {
  fill();
  ASSERT_TRUE(circular_queue.full());
}

TEST_F(CircularArrayQueueTest, FullReturnsFalseWhenNotFull) {
  ASSERT_FALSE(circular_queue.full());
}

TEST_F(CircularArrayQueueTest, EnqueueIncreasesSize) {
  circular_queue.enqueue(1);
  ASSERT_EQ(1, circular_queue.size());
  circular_queue.enqueue(1);
  ASSERT_EQ(2, circular_queue.size());
}

TEST_F(CircularArrayQueueTest, EnqueueThrowsErrorWhenFull) {
  fill();

  ASSERT_THROW(circular_queue.enqueue(5), std::out_of_range);
}

TEST_F(CircularArrayQueueTest, EnqueuesDataOnContents) {
  for (auto i = 0; i < circular_queue.max_size(); i++) {
    circular_queue.enqueue(i);
    ASSERT_EQ(i, circular_queue.back());
  }
}

TEST_F(CircularArrayQueueTest, BackReturnCorrectElement) {
  for (auto i = 0; i < circular_queue.max_size(); i++) {
    circular_queue.enqueue(i);
    ASSERT_EQ(i, circular_queue.back());
  }
}

TEST_F(CircularArrayQueueTest, BackThrowsErrorOnEmptyQueue) {
  ASSERT_THROW(circular_queue.back(), std::out_of_range);
}

TEST_F(CircularArrayQueueTest, BackWorksAsLhs) {
  fill();
  circular_queue.back() = -2;
  ASSERT_EQ(-2, circular_queue.back());
}

TEST_F(CircularArrayQueueTest, ClearSetsSizeToMinusOne) {
  fill();
  circular_queue.clear();
  ASSERT_EQ(0, circular_queue.size());
}

TEST_F(CircularArrayQueueTest, DequeueDecreasesSize) {
  fill();
  for (auto i = 19; i >= 0; i--) {
    circular_queue.dequeue();
    ASSERT_EQ(i, circular_queue.size());
  }
}

TEST_F(CircularArrayQueueTest, DequeueThrowsErrorWhenEmpty) {
  ASSERT_THROW(circular_queue.dequeue(), std::out_of_range);
}

TEST_F(CircularArrayQueueTest, DequeueReturnsCorrectElement) {
  fill();

  for (auto i = 0; i < circular_queue.max_size(); i++) {
    ASSERT_EQ(i, circular_queue.dequeue());
  }
}
