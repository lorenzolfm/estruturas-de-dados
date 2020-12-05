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

TEST_F(BinaryTreeTest, Check) {
    ASSERT_EQ(0, 1);
}
