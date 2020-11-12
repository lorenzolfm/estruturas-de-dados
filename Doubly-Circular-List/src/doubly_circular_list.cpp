#include "doubly_circular_list.h"

#include <stdexcept>

template <typename T>
structures::DoublyCircularList<T>::DoublyCircularList(void) {
  size_ = 0u;
  head_ = new Node((T)0);
  head_->next(head_);
  head_->previous(head_);
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
void structures::DoublyCircularList<T>::push_back(const T& data) {
  if (empty()) {
    push_front(data);
  } else {
    Node* new_node = new Node(data, head_->previous(), head_);
    if (new_node == nullptr) {
      throw std::out_of_range("Cannot push to full list");
    }
    head_->previous()->next(new_node);
    head_->previous(new_node);
    size_++;
  }
}

template <typename T>
void structures::DoublyCircularList<T>::push_front(const T& data) {
  Node* new_node = new Node(data, head_, head_->next());

  if (new_node == nullptr) {
    delete new_node;
    throw std::out_of_range("Cannot push front on full list");
  }

  head_->next()->previous(new_node);
  head_->next(new_node);

  size_++;
}

template <typename T>
void structures::DoublyCircularList<T>::insert(const T& data,
                                               std::size_t index) {
  if (index > size_) {
    throw std::out_of_range("Invalid index");
  }

  if (index == 0) {
    push_front(data);
  } else if (index == size_) {
    push_back(data);
  } else {
    Node* before = node(index - 1);
    Node* new_node = new Node(data, before, before->next());

    if (new_node == nullptr) {
      throw std::out_of_range("Cannot insert on full list");
    }

    before->next()->previous(new_node);
    before->next(new_node);

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
  if (empty()) {
    throw std::out_of_range("Cannot pop from empty list");
  }

  if (size_ == 1) {
    return pop_front();
  }

  Node* out = node(size_ - 1);
  T data = out->data();

  out->previous()->next(out->next());
  out->next()->previous(out->previous());
  size_--;
  delete out;

  return data;
}

template <typename T>
T structures::DoublyCircularList<T>::pop_front(void) {
  if (empty()) {
    throw std::out_of_range("Cannot pop from empty list");
  }

  Node* out = head_->next();
  T data = out->data();
  out->next()->previous(head_);
  head_->next(out->next());
  delete out;
  size_--;

  return data;
}

template <typename T>
T structures::DoublyCircularList<T>::pop(std::size_t index) {
  if (empty()) {
    throw std::out_of_range("Empty List");
  }

  if (index > size_ - 1) {
    throw std::out_of_range("Invalid Index");
  }

  if (index == 0) {
    return pop_front();
  }

  if (index == size_ - 1) {
    return pop_back();
  }

  Node* out = node(index);
  T data = out->data();
  out->previous()->next(out->next());
  out->next()->previous(out->previous());
  delete out;
  size_--;

  return data;
}

template <typename T>
void structures::DoublyCircularList<T>::remove(const T& data) {
  pop(find(data));
}

template <typename T>
bool structures::DoublyCircularList<T>::empty(void) const {
  return size_ == 0u;
}

template <typename T>
bool structures::DoublyCircularList<T>::contains(const T& data) const {
  return find(data) != size();
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

template <typename T>
T& structures::DoublyCircularList<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T>
const T& structures::DoublyCircularList<T>::operator[](
    std::size_t index) const {
  return const_cast<T&>(
      static_cast<const DoublyCircularList*>(this)->at(index));
}

template <typename T>
std::size_t structures::DoublyCircularList<T>::find(const T& data) const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  std::size_t index = 0u;
  Node* current = head_->next();

  while (index < size()) {
    if (current->data() == data) {
      break;
    }
    current = current->next();
    index++;
  }

  return index;
}

template <typename T>
std::size_t structures::DoublyCircularList<T>::size(void) const {
  return size_;
}

template class structures::DoublyCircularList<int>;
