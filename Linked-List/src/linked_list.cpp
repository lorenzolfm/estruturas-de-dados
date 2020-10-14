#include "linked_list.h"

template<typename T>
structures::LinkedList<T>::LinkedList(void) {}

template<typename T>
structures::LinkedList<T>::~LinkedList(void) {
  clear();
}

template<typename T>
void structures::LinkedList<T>::clear(void) {
  while(!empty()) {
    pop_front();
  }
}

template<typename T>
void structures::LinkedList<T>::push_back(const T& data) {
  insert(data, size_);
}

template<typename T>
void structures::LinkedList<T>::push_front(const T& data) {
  Node* new_node = new Node(data);
  if (new_node == nullptr) {
    delete new_node;
    throw std::out_of_range("Full list");
  } else {
    novo->next(head);
    head = novo;
    size_++;
  }
}
