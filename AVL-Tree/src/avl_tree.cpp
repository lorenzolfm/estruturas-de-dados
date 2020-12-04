#include "../include/avl_tree.h"

template<typename T>
structures::AVLTree<T>::~AVLTree(void) {
  delete this->root_;
}

template<typename T>
void structures::AVLTree<T>::insert(const T& data) {
  if (this->root_ == nullptr) {
    this->root_ = new Node(data);
  } else {
    this->root_->insert(data);
  }
  size_++;
}

template<typename T>
void structures::AVLTree<T>::remove(const T& data) {
  if (this->root_->remove(data)) {
    size_--;
  }
}

template<typename T>
bool structures::AVLTree<T>::contains(const T& data) const {
  if (this->root_ == nullptr) {
    return false;
  } else {
    return this->root_->contains(data);
  }
}

template<typename T>
bool structures::AVLTree<T>::empty(void) const {
  return size_ == 0u;
}

template<typename T>
std::size_t structures::AVLTree<T>::size(void) const {
  return size_;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::pre_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    this->root_->pre_order(array);
  }
  return array;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::in_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    this->root_->in_order(array);
  }
  return array;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::post_order(void) const {
  structures::ArrayList<T> array{};
  if (!empty()) {
    this->root_->post_order(array);
  }
  return array;
}

template<typename T>
int structures::AVLTree<T>::height(void) const {
  return this->root_->height();
}
