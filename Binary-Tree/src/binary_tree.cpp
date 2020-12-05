#include "../include/binary_tree.h"

template<typename T>
structures::BinaryTree<T>::~BinaryTree(void) {
  delete root;
}

template<typename T>
bool structures::BinaryTree<T>::contains(const T& data) const {
  Node* node = root;

  while ((node != nullptr) && (node->data_ != data)) {
    if (data > root->data_)
      node = node->right_node;
    else
      node = node->left_node;
  }

  if (node == nullptr) return false;

  return true;
}

template<typename T>
bool structures::BinaryTree<T>::empty(void) const {
  return size_ == 0u;
}

template<typename T>
std::size_t structures::BinaryTree<T>::size(void) const {
  return size_;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::pre_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty())
    root->pre_order(array);

  return array;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::in_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty())
    root->in_order(array);

  return array;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::post_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty())
    root->post_order(array);

  return array;
}

template class structures::BinaryTree<int>;
