#include "../include/avl_tree.h"

template<typename T>
structures::AVLTree<T>::~AVLTree(void) {
  delete root;
}

template<typename T>
bool structures::AVLTree<T>::contains(const T& data) const {
  if (empty())
    return false;

  return root->contains(data);
}

template<typename T>
std::size_t structures::AVLTree<T>::size(void) const {
    return size_;
}

template<typename T>
bool structures::AVLTree<T>::empty(void) const {
  return size_ == 0u;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::pre_order(void) const {
  structures::ArrayList<T> array{size_};
  if (!empty())
    root->pre_order(array);

  return array;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::in_order(void) const {
  structures::ArrayList<T> array{size_};
  if (!empty())
    root->in_order(array);

  return array;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::post_order(void) const {
  structures::ArrayList<T> array{size_};
  if (!empty())
    root->post_order(array);

  return array;
}

template <typename T>
int structures::AVLTree<T>::height() const {
  return root->height();
}

template class structures::AVLTree<int>;
