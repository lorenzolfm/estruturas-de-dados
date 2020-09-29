#include "array_queue.h"


template <typename T>
structures::ArrayQueue<T>::ArrayQueue(void) {
  max_size_ = DEFAULT_SIZE;
  size_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max_size) {
  max_size_ = max_size;
  size_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayQueue<T>::~ArrayQueue(void) {
  delete[] contents;
}

template <typename T>
void structures::ArrayQueue<T>::enqueue(const T& data) {
  if (full()) {
    throw(std::out_of_range("Cannot enqueue on full queue"));
  } else {
    contents[++size_] = data;
  }
}

template <typename T>
T structures::ArrayQueue<T>::dequeue(void) {
  if (empty()) {
    throw(std::out_of_range("Cannot dequeue an empty queue"));
  }
  T data = contents[0];
  size_--;
  move_forward();
  return data;
}

template <typename T>
T& structures::ArrayQueue<T>::back(void) {
  if (empty()) {
    throw(std::out_of_range("Empty queue"));
  }
  return contents[size_];
}

template <typename T>
void structures::ArrayQueue<T>::clear(void) {
  size_ = -1;
}

template <typename T>
bool structures::ArrayQueue<T>::empty(void) {
  return (size_ == -1);
}

template <typename T>
bool structures::ArrayQueue<T>::full(void) {
  return (size() == max_size_);
}

template <typename T>
std::size_t structures::ArrayQueue<T>::size(void) {
  return (size_ + 1);
}

template <typename T>
std::size_t structures::ArrayQueue<T>::max_size(void) {
  return max_size_;
}

template <typename T>
void structures::ArrayQueue<T>::move_forward(void) {
  for (auto i = 0; i != size(); i++) {
    contents[i] = contents[i + 1];
  }
}

template class structures::ArrayQueue<int>;
