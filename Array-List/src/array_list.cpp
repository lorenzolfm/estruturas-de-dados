#include "array_list.h"

template <typename T>
structures::ArrayList<T>::ArrayList(void) {
  max_size_ = DEFAULT_MAX_SIZE;
  size_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
  max_size_ = max_size;
  size_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayList<T>::~ArrayList(void) {
  delete[] contents;
}

template <typename T>
void structures::ArrayList<T>::clear(void) {
  size_ = -1;
}

template <typename T>
void structures::ArrayList<T>::push_back(const T& data) {
  if (full()) {
    throw(std::out_of_range("Cannot push back on full list"));
  }
  contents[++size_] = data;
}

template <typename T>
void structures::ArrayList<T>::push_front(const T& data) {
  if (full()) {
    throw(std::out_of_range("Cannot push front to a full list"));
  } else if (empty()) {
    contents[++size_] = data;
  } else {
    move_backward(0);
    size_++;
    contents[0] = data;
  }
}

template <typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
  if (full()) {
    throw(std::out_of_range("Cannot insert on full list"));
  } else if ((index < 0) || (index > size_ + 1)) {
    throw(std::out_of_range("Invalid index"));
  } else {
    move_backward(index);
    size_++;
    contents[index] = data;
  }
}

template <typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
  if (full()) {
    throw(std::out_of_range("Cannot insert in full list"));
  } else if (empty()) {
    contents[++size_] = data;
  } else {
    std::size_t i = 0;
    while (i != size() && contents[i] < data) {
      i++;
    }
    if (i == size()) {
      push_back(data);
    } else {
      insert(data, i);
    }
  }
}

template <typename T>
T structures::ArrayList<T>::pop_back(void) {
  if (empty()) {
    throw(std::out_of_range("Cannot pop back from empty list"));
  }
  return contents[size_--];
}

template <typename T>
T structures::ArrayList<T>::pop_front(void) {
  if (empty()) {
    throw(std::out_of_range("Cannot pop front from empty list"));
  } else {
    T data = contents[0];
    size_--;
    move_forward(0);
    return data;
  }
}

template <typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
  if ((index < 0) || (index > size_)) {
    throw(std::out_of_range("Invalid index"));
  } else if (empty()) {
    throw(std::out_of_range("Cannot pop from empty list"));
  } else {
    T data = contents[index];
    size_--;
    move_forward(index);
    return data;
  }
}

template <typename T>
void structures::ArrayList<T>::remove(const T& data) {
  if (empty()) {
    throw(std::out_of_range("Cannot remove from empty list"));
  } else {
    std::size_t index = find(data);
    if (index == size()) {
      throw(std::invalid_argument("List does not contain the argument"));
    } else {
      pop(index);
    }
  }
}

template <typename T>
bool structures::ArrayList<T>::empty(void) {
  return size_ == -1;
}

template <typename T>
bool structures::ArrayList<T>::full(void) {
  return size_ == max_size_ - 1;
}

template <typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
  for (std::size_t index = 0; index < size_ + 1; index++) {
    if (data == contents[index]) {
      return true;
    }
  }
  return false;
}

template <typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const {
  std::size_t index = 0;
  while (index <= size_ && !(data == contents[index])) {
    index++;
  }
  if (index > size_) {
    return size_ + 1;
  } else {
    return index;
  }
}

template <typename T>
std::size_t structures::ArrayList<T>::size(void) const {
  return size_ + 1;
}

template <typename T>
std::size_t structures::ArrayList<T>::max_size(void) const {
  return max_size_;
}

template <typename T>
T& structures::ArrayList<T>::at(std::size_t index) {
  if (index < 0 || index >= size_ + 1) {
    throw(std::out_of_range("Error: invalid index"));
  }
  return contents[index];
}

template <typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
  if (index < 0 || index >= size_ + 1) {
    throw(std::out_of_range("Error: invalid index"));
  }
  return contents[index];
}

template <typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
  if (index < 0 || index >= size_ + 1) {
    throw(std::out_of_range("Error: invalid index"));
  }
  return contents[index];
}

template <typename T>
const T& structures::ArrayList<T>::operator[](std::size_t index) const {
  if (index < 0 || index >= size_ + 1) {
    throw(std::out_of_range("Error: invalid index"));
  }
  return contents[index];
}

template <typename T>
void structures::ArrayList<T>::move_forward(std::size_t index) {
  for (std::size_t i = index; i != size_ + 1; i++) {
    contents[i] = contents[i + 1];
  }
}

template <typename T>
void structures::ArrayList<T>::move_backward(std::size_t index) {
  for (std::size_t i = size_ + 1; i != index; i--) {
    contents[i] = contents[i - 1];
  }
}

template class structures::ArrayList<int>;