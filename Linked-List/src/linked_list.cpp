#include "linked_list.h"

#include <stdio.h>

#include <stdexcept>

// template <typename T>
// structures::LinkedList<T>::LinkedList(void) {}

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
const T& structures::LinkedList<T>::at(std::size_t index) const {
  return at(index);
}

template <typename T>
T& structures::LinkedList<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T>
const T& structures::LinkedList<T>::operator[](std::size_t index) const {
  return at(index);
}

template <typename T>
void structures::LinkedList<T>::invert(void) {
  for (auto i = 0; i < size(); i++) {
    insert(pop_back(), i);
  }
}

template <typename T>
structures::LinkedList<T> structures::LinkedList<T>::clone(void) {
  LinkedList<T> list_clone;

  for (auto i = 0; i < size(); i++) {
    list_clone.insert(at(i), i);
  }

  return list_clone;
}

// template <typename T>
// structures::LinkedList<T> structures::LinkedList<T>::slicing(int start,
// if (start < 0 || start >= size_) {
// throw std::out_of_range("Invalid start");
//}
// if (stop > size_ || stop < 0) {
// throw std::out_of_range("Invalid stop");
//}
// LinkedList<T> list_slice;

// for (auto index = start; index <= stop; index += step) {
// list_slice.push_back(index);
//}

// return list_slice;
//}

template <typename T>
void structures::LinkedList<T>::append(structures::LinkedList<T>& list_add) {
  Node* begin = list_add.head_;
  for (auto i = 0; i < list_add.size(); i++) {
    push_back(list_add[i]);
  }
}

template <typename T>
structures::LinkedList<structures::LinkedList<T>*>
structures::LinkedList<T>::halve(void) {
  LinkedList<LinkedList<T>*> list_halve;

  LinkedList<T>* par_list = new LinkedList();
  LinkedList<T>* impar_list = new LinkedList();

  Node* current = head_;

  for (auto i = 0; i < size(); i++) {
    T current_data = current->data();
    if (i % 2 == 0) {
      par_list->push_back(current_data);
    } else {
      impar_list->push_back(current_data);
    }
    current = current->next();
  }

  list_halve.push_back(par_list);
  list_halve.push_back(impar_list);

  return list_halve;
}

template class structures::LinkedList<int>;
template class structures::LinkedList<structures::LinkedList<int>*>;
