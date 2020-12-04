#include "../include/binary_tree.h"

template<typename T>
structures::BinaryTree<T>::~BinaryTree(void) {}

template<typename T>
void structures::BinaryTree<T>::insert(const T& data) {}

template<typename T>
void structures::BinaryTree<T>::remove(const T& data) {}

template<typename T>
bool structures::BinaryTree<T>::contains(const T& data) const {}

template<typename T>
bool structures::BinaryTree<T>::empty(void) const {}

template<typename T>
std::size_t structures::BinaryTree<T>::size(void) const {}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::pre_order(void) const {}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::in_order(void) const {}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::post_order(void) const {}
