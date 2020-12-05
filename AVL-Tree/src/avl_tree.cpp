#include "../include/avl_tree.h"

template<typename T>
std::size_t structures::AVLTree<T>::size(void) const {
    return size_;
}

template<typename T>
bool structures::AVLTree<T>::empty(void) const {

}

template <typename T>
int structures::AVLTree<T>::height() const {
  return root->height();
}
