#include "doubly_circular_list.h"

#include <stdexcept>

template <typename T>
structures::DoublyCircularList<T>::DoublyCircularList() {
  size_ = 0u;
  head_ = new Node((T)0, nullptr);
  head_->next(head_);
}

template <typename T>
structures::DoublyCircularList<T>::~DoublyCircularList(void) {
  clear();
}

template <typename T>
void structures::DoublyCircularList<T>::clear(void) {
  while (!empty()) {
    pop_front();
  }
}

template <typename T>
std::size_t structures::DoublyCircularList<T>::size(void) const {
  return size_;
}

template <typename T>
bool structures::DoublyCircularList<T>::empty(void) const {
  return size_ == 0;
}

template <typename T>
void structures::DoublyCircularList<T>::push_back(const T& data) {
  insert(data, size_);
}

template <typename T>
void structures::DoublyCircularList<T>::push_front(const T& data) {
  Node* new_node = new Node(data, head_->next());

  if (new_node == nullptr) {
    throw std::out_of_range("Full list");
  }

  if (empty()) {
    head_ = new_node;
    head_->next(head_);
    head_->previous(head_);
  } else {
    new_node->next(head_);
    new_node->previous(head_->previous());
    head_->previous()->next(new_node);
    head_->previous(new_node);
  }
  size_++;
}

template <typename T>
void structures::DoublyCircularList<T>::insert(const T& data,
                                               std::size_t index) {
  if (index > size_) throw std::out_of_range("Invalid index");

  if (index == 0) {
    push_front(data);
  } else {
    Node* new_node = new Node(data);
    if (new_node == nullptr) throw std::out_of_range("List is full");

    Node* current = before_index(index);
    new_node->next(current);
    new_node->previous(current->previous());
    current->previous()->next(new_node);
    current->previous(new_node);
    size_++;
  }
}

template <typename T>
void structures::DoublyCircularList<T>::insert_sorted(const T& data) {
  if (empty()) {
    push_front(data);
  } else {
    Node* current = head_->next();
    std::size_t position = size_;

    for (auto index = 0; index < size_; index++) {
      if (!(data > current->data())) {
        position = index;
        break;
      }

      current = current->next();
    }
    insert(data, position);
  }
}

template <typename T>
T structures::DoublyCircularList<T>::pop_back(void) {
  return pop(size_ - 1u);
}

template <typename T>
T structures::DoublyCircularList<T>::pop_front(void) {
  if (empty()) {
    throw std::out_of_range("Cannot pop from empty list");
  }

  Node* out = head_;
  T data = head_->data();
  head_->previous()->next(head_->next());
  head_->next()->previous(head_->previous());
  head_ = head_->next();
  size_--;

  delete out;

  if (empty()) {
    head_ = nullptr;
  }
  return data;
}

template <typename T>
T structures::DoublyCircularList<T>::pop(std::size_t index) {
  if (empty()) {
    throw std::out_of_range("Empty list");
  }
  if (index >= size()) {
    throw std::out_of_range("Invalid index!");
  }

  if (index == 0) {
    return pop_front();
  }

  Node* out = before_index(index);
  T data = out->data();
  out->previous()->next(out->next());
  out->next()->previous(out->previous());
  size_--;
  delete out;

  return data;
}

template <typename T>
void structures::DoublyCircularList<T>::remove(const T& data) {
  pop(find(data));
}

template <typename T>
bool structures::DoublyCircularList<T>::contains(const T& data) const {
  return find(data) != size();
}

template <typename T>
std::size_t structures::DoublyCircularList<T>::find(const T& data) const {
  if (empty()) {
    throw std::out_of_range("Empty List");
  }

  std::size_t index = 0u;
  Node* current = head_->next();

  while (index < size()) {
    if (current->data() == data) break;
    current = current->next();
    index++;
  }
  return index;
}

template <typename T>
T& structures::DoublyCircularList<T>::at(std::size_t index) {
  return const_cast<T&>(
      static_cast<const DoublyCircularList*>(this)->at(index));
}

template <typename T>
const T& structures::DoublyCircularList<T>::at(std::size_t index) const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  } else if (index >= size_) {
    throw std::out_of_range("Index out of bounds");
  }

  Node* current = head_->next();
  auto i = 0;
  while (i != index) {
    current = current->next();
    i++;
  }
  return current->data();
}

template class structures::DoublyCircularList<int>;
