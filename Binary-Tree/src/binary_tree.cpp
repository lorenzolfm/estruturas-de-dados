#include "../include/binary_tree.h"

template<typename T>
structures::BinaryTree<T>::~BinaryTree(void) {
  delete root;
}

template<typename T>
void structures::BinaryTree<T>::insert(const T& data) {
  if (empty())
    root = new Node(data);
  else
    root->insert(data);

  size_++;
}

template<typename T>
void structures::BinaryTree<T>::remove(const T& data) {
  if (empty())
    throw std::out_of_range("Cannot remove from empty tree");

  if (size() != 1u) {
    if (root->remove(data))
      size_--;
  } else {
    if (root->data_ == data) {
      delete root;
      root = nullptr;
      size_--;
    }
  }
}

template<typename T>
bool structures::BinaryTree<T>::contains(const T& data) const {
  if (empty())
    return false;

  return root->contains(data);
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
  structures::ArrayList<T> array{size_};
  if (!empty())
    root->pre_order(array);

  return array;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::in_order(void) const {
  structures::ArrayList<T> array{size_};
  if (!empty())
    root->in_order(array);

  return array;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::post_order(void) const {
  structures::ArrayList<T> array{size_};
  if (!empty())
    root->post_order(array);

  return array;
}

template class structures::BinaryTree<int>;
