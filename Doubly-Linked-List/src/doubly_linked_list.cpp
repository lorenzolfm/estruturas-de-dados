#include "doubly_linked_list.h"

#include <stdexcept>

template<typename T>
structures::DoublyLinkedList<T>::DoublyLinkedList(void) {
  head_ = nullptr;
  size_ = 0u;
}

template<typename T>
structures::DoublyLinkedList<T>::~DoublyLinkedList(void) {
  clear();
}

template<typename T>
void structures::DoublyLinkedList<T>::clear(void) {
  while (!empty()) {
    pop_front();
  }
}

template <typename T>
void structures::DoublyLinkedList<T>::push_front(const T& data) {
  Node* new_node = new Node(data, head_);

  if (new_node == nullptr) {
    throw std::out_of_range("Cannot push front on full list");
  }

  if (head_ != nullptr) {
    head_->previous(new_node);
  }

  head_ = new_node;
  size_++;
}

template<typename T>
T structures::DoublyLinkedList<T>::pop_front(void) {
  if (empty()) {
    throw std::out_of_range("Cannot pop from empty list");
  }

  Node *out;
  out = head_;
  head_ = out->next();
  T data = out->data();
  delete out;
  size_--;
  return data;
}


template <typename T>
bool structures::DoublyLinkedList<T>::empty(void) const {
  return size_ == 0u;
}

template <typename T>
T& structures::DoublyLinkedList<T>::at(std::size_t index) {
  return const_cast<T&>(static_cast<const DoublyLinkedList*>(this)->at(index));
}

template <typename T>
const T& structures::DoublyLinkedList<T>::at(std::size_t index) const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  } else if (index >= size_) {
    throw std::out_of_range("Index out of bounds");
  }

  Node* current = head_;
  auto i = 0;
  while (i != index) {
    current = current->next();
    i++;
  }
  return current->data();
}

template <typename T>
T& structures::DoublyLinkedList<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T>
const T& structures::DoublyLinkedList<T>::operator[](std::size_t index) const {
  return const_cast<T&>(static_cast<const DoublyLinkedList*>(this)->at(index));
}

template <typename T>
std::size_t structures::DoublyLinkedList<T>::find(const T& data) const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  std::size_t index = 0u;
  Node* current = head_;

  while (index < size()) {
    if (current->data() == data) break;
    current = current->next();
    index++;
  }

  return index;
}

template <typename T>
std::size_t structures::DoublyLinkedList<T>::size(void) const {
  return size_;
}

template class structures::DoublyLinkedList<int>;
