#include "node.h"
#include <stdio.h>
//printf("Endereço de data_ antes = %p\n", data_ptr_);
//printf("Valor de data_ = %d\n", *data_ptr_);
//printf("Endereço de data_ depois = %p\n", data_ptr_);
//printf("Valor de data_ = %d\n", *data_ptr_);

template<typename T>
structures::Node<T>::Node(T* data) {
  data_ptr_ = data;
  next_ptr_ = nullptr;
}

template<typename T>
structures::Node<T>::Node(T* data, Node* next) {
  data_ptr_ = data;
  next_ptr_ = next;
}

template<typename T>
T* structures::Node<T>::data(void) {
  return data_ptr_;
}

template<typename T>
const T* structures::Node<T>::data(void) const {
  return data_ptr_;
}

template<typename T>
structures::Node<T>* structures::Node<T>::next(void) {
  return next_ptr_;
}

template<typename T>
void structures::Node<T>::next(Node* node) {
  next_ptr_ = node;
}

template class structures::Node<int>;
