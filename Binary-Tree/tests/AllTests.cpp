#include <string>

#include "gtest/gtest.h"
#include "../include/binary_tree.h"
#include "../include/array_list.h"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

class BinaryTreeTest : public ::testing::Test {
    protected:
        structures::BinaryTree<int> tree{};
};

// Test Initialization
TEST_F(BinaryTreeTest, InitializesWithSizeZero) {
    ASSERT_EQ(tree.size(), 0u);
}

TEST_F(BinaryTreeTest, InitializesWithNullptrRoot) {
    ASSERT_EQ(tree.get_root(), nullptr);
}

// Test Empty
TEST_F(BinaryTreeTest, EmptyReturnsTrueWhenEmpty) {
    ASSERT_TRUE(tree.empty());
}

TEST_F(BinaryTreeTest, EmptyReturnsFalseWhenNotEmpty) {
    tree.size_ = 1;
    ASSERT_FALSE(tree.empty());
}

// Contains
TEST_F(BinaryTreeTest, ContainsOnEmptyTreeReturnFalse) {
    ASSERT_FALSE(tree.contains(0));
}
