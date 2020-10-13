#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
#include "linked_list.h"
#include "node.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";
  return RUN_ALL_TESTS();
}

class NodeTest : public ::testing::Test {
 protected:
  int data = 1;
  int other_data = 1;
  int data_arr[10];
  void fill(int* arr) {
    for (int i = 0; i < 10; i++) {
      data_arr[i] = i;
    }
  }

  structures::Node<int> node{&data};
  structures::Node<int> other_node{&other_data};
  structures::Node<int> linked_node{&data, &other_node};
  structures::Node<int> node_arr_data{data_arr};
};

TEST_F(NodeTest, data_ptr_PointsToVar) {
  ASSERT_EQ(node.data(), &data);

  fill(data_arr);
  int* arr = node_arr_data.data();
  for (int i = 0; i < 10; i++) {
    ASSERT_EQ(arr[i], data_arr[i]);
    ASSERT_EQ(data_arr[i], i);
    ASSERT_EQ(arr[i], i);
  }

  int num = node_arr_data.data()[2];
  ASSERT_EQ(num, 2);
}

TEST_F(NodeTest, dataReturnsPointerToData_) {
  ASSERT_EQ(*node.data(), data);

  int* ret = node.data();
  ASSERT_EQ(*node.data(), *ret);
  *ret = 2;
  ASSERT_EQ(*node.data(), *ret);

  fill(data_arr);
  int* val = node_arr_data.data();
  for (int i = 0; i < 10; i++) {
    ASSERT_EQ(val[i], data_arr[i]);
    val[i] *= 10;
  }

  int* ten_time_each_val = node_arr_data.data();
  for (int i = 0; i < 10; i++) {
    ASSERT_EQ(ten_time_each_val[i], data_arr[i]);
  }
}

TEST_F(NodeTest, next_ptr_ReturnsPointerToNextNode) {
  ASSERT_EQ(linked_node.next(), &other_node);
}

TEST_F(NodeTest, nextAssignsNextNode) {

}
