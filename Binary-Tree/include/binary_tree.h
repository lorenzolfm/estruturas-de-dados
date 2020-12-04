#ifndef STRUCTURES_BINARY_TREE_H
#define STRUCTURES_BINARY_TREE_H

#include "../../Array-List/include/array_list.h"

namespace structures {
   template<typename T>
   class BinaryTree {
      ~BinaryTree(void);

      void insert(const T& data);

      void remove(const T& data);

      bool contains(const T& data) const;

      bool empty(void) const;

      std::size_t size(void) const;

      ArrayList<T> pre_order(void) const;

      ArrayList<T> post_order(void) const;

      ArrayList<T> in_order(void) const;

      private:
      struct Node {
         Node(const T& data);

         void insert(const T& data);

         bool remove(const T& data);

         bool contains(const T& data) const;

         void pre_order(ArrayList<T>& array) const;

         void in_order(ArrayList<T>& array) const;

         void post_order(ArrayList<T>& array) const;

         T data_;
         Node* left_node_;
         Node* right_node;
      };

      Node* root_{nullptr};
      std::size_t size_{0};
   };
}
#endif
