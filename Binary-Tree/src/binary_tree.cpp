#include "../include/binary_tree.h"

template <typename T>
structures::BinaryTree<T>::~BinaryTree(void) {
  delete root_;
  size_ = 0u;
}

template <typename T>
void structures::BinaryTree<T>::insert(const T& data) {
  if (empty()) {
    root_ = new Node(data);
  } else {
    root_->insert(data);
  }
  size_++;
}

template <typename T>
void structures::BinaryTree<T>::remove(const T& data) {
  if (!empty()) {
    size_--;
    root_->remove(data);
  }
}

template <typename T>
bool structures::BinaryTree<T>::contains(const T& data) const {
  if (!empty()) {
    return root_->contains(data);
  }
  return false;
}

template <typename T>
bool structures::BinaryTree<T>::empty(void) const {
  return size_ == 0u;
}

template <typename T>
std::size_t structures::BinaryTree<T>::size(void) const {
  return size_;
}

template <typename T>
structures::ArrayList<T> structures::BinaryTree<T>::pre_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    root_->pre_order(array);
  }
  return array;
}

template <typename T>
structures::ArrayList<T> structures::BinaryTree<T>::in_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    root_->in_order(array);
  }
  return array;
}

template <typename T>
structures::ArrayList<T> structures::BinaryTree<T>::post_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    root_->post_order(array);
  }
  return array;
}
