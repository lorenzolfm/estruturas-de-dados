#include <stdexcept>
#include "linked_list.h"

template <typename T>
structures::LinkedList<T>::~LinkedList(void) {
  clear();
}

template <typename T>
void structures::LinkedList<T>::clear(void) {
  while (!empty()) {
    pop_front();
  }
}

template <typename T>
std::size_t structures::LinkedList<T>::size(void) const {
  return size_;
}

template <typename T>
bool structures::LinkedList<T>::empty(void) const {
  return size_ == 0;
}

template <typename T>
void structures::LinkedList<T>::push_back(const T& data) {
  insert(data, size_);
}

template <typename T>
void structures::LinkedList<T>::push_front(const T& data) {
  Node* new_node = new Node(data);

  if (new_node == nullptr) {
    throw std::out_of_range("Full list");
  }

  new_node->next(head_);
  head_ = new_node;
  size_++;
}

template <typename T>
void structures::LinkedList<T>::insert(const T& data, std::size_t index) {
  if (index > size_) {
    throw std::out_of_range("Invalid index");
  }

  if (index == 0) {
    push_front(data);
  } else {
    Node* new_node = new Node(data);
    if (new_node == nullptr) {
      throw std::out_of_range("Full list");
    }

    Node* before = before_index(index);
    Node* next = before->next();

    new_node->next(next);
    before->next(new_node);

    size_++;
  }
}

template <typename T>
void structures::LinkedList<T>::insert_sorted(const T& data) {
  if (empty()) {
    push_front(data);
  } else {
    Node* current = head_;
    Node* before = head_;
    std::size_t position = size_;

    for (auto index = 0; index < size_; index++) {
      if (!(data > current->data())) {
        position = index;
        break;
      }

      before = current;
      current = current->next();
    }
    insert(data, position);
  }
}

template <typename T>
T structures::LinkedList<T>::pop_back(void) {
  return pop(size_ - 1u);
}

template <typename T>
T structures::LinkedList<T>::pop_front(void) {
  if (empty()) {
    throw std::out_of_range("Cannot pop_front from empty list");
  }

  Node* out = head_;
  T data = out->data();

  head_ = head_->next();
  size_--;
  delete out;

  return data;
}

template <typename T>
T structures::LinkedList<T>::pop(std::size_t index) {
  if (empty()) {
    throw std::out_of_range("Empty list");
  }
  if (index >= size()) {
    throw std::out_of_range("Invalid index!");
  }

  if (index == 0) {
    return pop_front();
  }

  Node* before_out = before_index(index);
  Node* out = before_out->next();
  T data = out->data();

  before_out->next(out->next());
  size_--;
  delete out;

  return data;
}

template <typename T>
void structures::LinkedList<T>::remove(const T& data) {
  pop(find(data));
}

template <typename T>
bool structures::LinkedList<T>::contains(const T& data) const {
  return find(data) != size();
}

template <typename T>
std::size_t structures::LinkedList<T>::find(const T& data) const {
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
T& structures::LinkedList<T>::at(std::size_t index) {
  return const_cast<T&>(static_cast<const LinkedList*>(this)->at(index));
}

template <typename T>
const T& structures::LinkedList<T>::at(std::size_t index) const {
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
T& structures::LinkedList<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T>
const T& structures::LinkedList<T>::operator[](std::size_t index) const {
  return const_cast<T&>(static_cast<const LinkedList*>(this)->at(index));
}

template class structures::LinkedList<int>;
