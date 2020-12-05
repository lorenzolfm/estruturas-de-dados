#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "../include/avl_tree.h"
#include "../include/array_list.h"

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

class AVLTreeTest : public ::testing::Test {
 protected:
  structures::AVLTree<int> tree{};
};

// Test Initialization
TEST_F(AVLTreeTest, InitializesWithSizeZero) { ASSERT_EQ(tree.size(), 0u); }

//TEST_F(AVLTreeTest, InitializesWithNullptrRoot) {
  //ASSERT_EQ(tree.get_root(), nullptr);
//}

// Test Empty
TEST_F(AVLTreeTest, EmptyReturnsTrueWhenEmpty) { ASSERT_TRUE(tree.empty()); }

//TEST_F(AVLTreeTest, EmptyReturnsFalseWhenNotEmpty) {
  //tree.insert(1);
  //ASSERT_FALSE(tree.empty());
//}

//// Test Size Getter
//TEST_F(AVLTreeTest, SizeReturnsCorrectSize) {
  //ASSERT_EQ(tree.size(), 0u);
  //tree.insert(5);
  //ASSERT_EQ(tree.size(), 1u);
  //tree.insert(5);
  //ASSERT_EQ(tree.size(), 2u);
//}

//// Test Insert
//TEST_F(AVLTreeTest, InsertIncreasesSize) {
  //ASSERT_EQ(tree.size(), 0u);
  //tree.insert(5);
  //ASSERT_EQ(tree.size(), 1u);
  //tree.insert(3);
  //ASSERT_EQ(tree.size(), 2u);
  //tree.insert(7);
  //ASSERT_EQ(tree.size(), 3u);
//}

//// Contains
//TEST_F(AVLTreeTest, ContainsOnEmptyTreeReturnFalse) {
  //ASSERT_FALSE(tree.contains(0));

  //tree.insert(5);
  //tree.insert(3);
  //tree.insert(7);
  //tree.insert(2);
  //tree.insert(1);
  //tree.insert(6);
  //tree.insert(8);

  //ASSERT_TRUE(tree.contains(5));
  //ASSERT_TRUE(tree.contains(3));
  //ASSERT_TRUE(tree.contains(7));
  //ASSERT_TRUE(tree.contains(2));
  //ASSERT_TRUE(tree.contains(1));
  //ASSERT_TRUE(tree.contains(6));
  //ASSERT_TRUE(tree.contains(8));
//}

//// Test Pre Order
//TEST_F(AVLTreeTest, PreOrderTest) {
  //tree.insert(5);
  //tree.insert(3);
  //tree.insert(7);
  //tree.insert(2);
  //tree.insert(1);
  //tree.insert(6);
  //tree.insert(8);

  //// Double free detected
  //auto array = tree.pre_order();

  //ASSERT_EQ(array[0], 5);
  //ASSERT_EQ(array[1], 3);
  //ASSERT_EQ(array[2], 2);
  //ASSERT_EQ(array[3], 1);
  //ASSERT_EQ(array[4], 7);
  //ASSERT_EQ(array[5], 6);
  //ASSERT_EQ(array[6], 8);
//}

//// Test In Order
//TEST_F(AVLTreeTest, InOrderTest) {
  //tree.insert(5);
  //tree.insert(3);
  //tree.insert(7);
  //tree.insert(2);
  //tree.insert(1);
  //tree.insert(6);
  //tree.insert(8);

  //auto array = tree.in_order();

  //ASSERT_EQ(array[0], 1);
  //ASSERT_EQ(array[1], 2);
  //ASSERT_EQ(array[2], 3);
  //ASSERT_EQ(array[3], 5);
  //ASSERT_EQ(array[4], 6);
  //ASSERT_EQ(array[5], 7);
  //ASSERT_EQ(array[6], 8);
//}

//// Test Post Order
//TEST_F(AVLTreeTest, PostOrderTest) {
  //tree.insert(5);
  //tree.insert(3);
  //tree.insert(7);
  //tree.insert(2);
  //tree.insert(1);
  //tree.insert(6);
  //tree.insert(8);

  //auto array = tree.post_order();

  //ASSERT_EQ(array[0], 1);
  //ASSERT_EQ(array[1], 2);
  //ASSERT_EQ(array[2], 3);
  //ASSERT_EQ(array[3], 6);
  //ASSERT_EQ(array[4], 8);
  //ASSERT_EQ(array[5], 7);
  //ASSERT_EQ(array[6], 5);
//}

//// Test Remove
//TEST_F(AVLTreeTest, RemoveDecreasesSize) {
  //tree.insert(5);
  //tree.remove(5);
  //ASSERT_EQ(tree.size(), 0u);
//}

//TEST_F(AVLTreeTest, RemoveDeletesData) {
  //tree.insert(5);
  //tree.insert(3);
  //tree.insert(7);
  //tree.insert(2);
  //tree.insert(1);
  //tree.insert(6);
  //tree.insert(8);

  //tree.remove(5);
  //tree.remove(3);
  //tree.remove(7);
  //tree.remove(2);
  //tree.remove(1);
  //tree.remove(6);
  //tree.remove(8);

  //ASSERT_FALSE(tree.contains(5));
  //ASSERT_FALSE(tree.contains(3));
  //ASSERT_FALSE(tree.contains(7));
  //ASSERT_FALSE(tree.contains(2));
  //ASSERT_FALSE(tree.contains(1));
  //ASSERT_FALSE(tree.contains(6));
  //ASSERT_FALSE(tree.contains(8));
//}
