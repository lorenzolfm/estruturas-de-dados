#include "linked_queue.h"

#include <stdexcept>

template<typename T>
structures::LinkedQueue<T>::LinkedQueue(void) {
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0u;
}

template<typename T>
structures::LinkedQueue<T>::~LinkedQueue(void) {
  clear();
}

template<typename T>
void structures::LinkedQueue<T>::clear(void) {
  while(!empty()) {
    dequeue();
  }
}

template<typename T>
void structures::LinkedQueue<T>::enqueue(const T& data) {
  Node* new_node = new Node(data);
  if (new_node == nullptr) {
    throw std::out_of_range("Full queue");
  }

  if (empty()) {
    head_ = new_node;
  } else {
    tail_->next(new_node);
  }

  new_node->next(nullptr);
  tail_ = new_node;
  size_++;
}

template<typename T>
T structures::LinkedQueue<T>::dequeue(void) {
  if (empty()) {
    throw std::out_of_range("Empty queue");
  }

  Node* out = head_;
  T data = out->data();
  head_ = head_->next();

  if (size() == 1) {
    tail_ = nullptr;
  }

  size_--;
  delete out;

  return data;
}

template<typename T>
T& structures::LinkedQueue<T>::front(void) {
  return const_cast<T&>(static_cast<const LinkedQueue*>(this)->front());
}

template<typename T>
const T& structures::LinkedQueue<T>::front(void) const {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }

  return head_->data();
}

template<typename T>
T& structures::LinkedQueue<T>::back(void) {
  return const_cast<T&>(static_cast<const LinkedQueue*>(this)->back());
}

template<typename T>
const T& structures::LinkedQueue<T>::back(void) const {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }

  return tail_->data();
}

template<typename T>
bool structures::LinkedQueue<T>::empty(void) const {
  return size_ == 0;
}

template<typename T>
std::size_t structures::LinkedQueue<T>::size(void) const {
  return size_;
}

template class structures::LinkedQueue<int>;
