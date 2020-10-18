#include "linked_stack.h"

#include <stdexcept>

template<typename T>
structures::LinkedStack<T>::LinkedStack(void) {
  top_ = nullptr;
  size_ = 0u;
}

template <typename T>
structures::LinkedStack<T>::~LinkedStack(void) {
  clear();
}

template <typename T>
void structures::LinkedStack<T>::clear(void) {
  while (!empty()) {
    pop();
  }
}

template <typename T>
void structures::LinkedStack<T>::push(const T& data) {
  Node* new_node = new Node(data);
  if (new_node == nullptr) {
    throw std::out_of_range("Full stack");
  }

  new_node->next(top_);
  top_ = new_node;
  size_++;
}

template <typename T>
T structures::LinkedStack<T>::pop(void) {
  if (empty()) {
    throw std::out_of_range("Cannot pop from empty stack");
  }

  Node* out = top_;
  T data = out->data();

  top_ = top_->next();
  size_--;
  delete out;

  return data;
}

template <typename T>
T& structures::LinkedStack<T>::top(void) {
  return const_cast<T&>(static_cast<const LinkedStack*>(this)->top());
}

template <typename T>
const T& structures::LinkedStack<T>::top(void) const {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }

  return top_->data();
}

template <typename T>
bool structures::LinkedStack<T>::empty(void) const {
  return size() == 0;
}

template <typename T>
std::size_t structures::LinkedStack<T>::size(void) const {
  return size_;
}

template class structures::LinkedStack<int>;
