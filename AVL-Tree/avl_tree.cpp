#include "../include/avl_tree.h"

template<typename T>
structures::AVLTree<T>::~AVLTree(void) {
  delete root_;
  size_ = 0u;
}

template<typename T>
void structures::AVLTree<T>::insert(const T& data) {}

template<typename T>
void structures::AVLTree<T>::remove(const T& data) {}

template<typename T>
bool structures::AVLTree<T>::contains(const T& data) const {}

template<typename T>
bool structures::AVLTree<T>::empty(void) const {
  return size_ == 0u;
}

template<typename T>
std::size_t structures::AVLTree<T>::size(void) const {
  return size_;
}

template<typename T>
int structures::AVLTree<T>::height(void) const {}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::pre_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    root_->pre_order(array);
  }
  return array;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::in_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    root_->in_order(array);
  }
  return array;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::post_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    root_->post_order(array);
  }
  return array;
}
