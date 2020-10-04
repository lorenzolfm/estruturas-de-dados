#include "circular_array_queue.h"

template <typename T>
structures::CircularArrayQueue<T>::CircularArrayQueue(void) {
  max_size_ = DEFAULT_SIZE;
  begin_ = 0;
  end_ = -1;
  size_ = 0;
  contents = new T[max_size_];
}

template <typename T>
structures::CircularArrayQueue<T>::CircularArrayQueue(std::size_t max_size) {
  max_size_ = max_size;
  begin_ = 0;
  end_ = -1;
  size_ = 0;
  contents = new T[max_size_];
}

template <typename T>
structures::CircularArrayQueue<T>::~CircularArrayQueue(void) {
  delete[] contents;
}

template <typename T>
void structures::CircularArrayQueue<T>::enqueue(const T& data) {
  if (full()) {
    throw std::out_of_range("Cannot enqueue on full queue");
  } else {
    end_ = (end_ + 1) % max_size_;
    contents[end_] = data;
    size_++;
  }
}

template <typename T>
T structures::CircularArrayQueue<T>::dequeue(void) {
  if (empty()) {
    throw std::out_of_range("Cannot dequeue from empty queue");
  } else {
    T data = contents[begin_];
    begin_ = (begin_ + 1) % max_size_;
    size_--;
    return data;
  }
}

template <typename T>
T& structures::CircularArrayQueue<T>::back(void) {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  } else {
    return contents[end_];
  }
}

template <typename T>
void structures::CircularArrayQueue<T>::clear(void) {
  begin_ = 0;
  end_ = -1;
  size_ = 0;
}

template <typename T>
bool structures::CircularArrayQueue<T>::empty(void) {
  return (size_ == 0);
}

template <typename T>
bool structures::CircularArrayQueue<T>::full(void) {
  return (size_ == max_size_);
}

template <typename T>
std::size_t structures::CircularArrayQueue<T>::size(void) {
  return size_;
}

template <typename T>
std::size_t structures::CircularArrayQueue<T>::max_size(void) {
  return max_size_;
}

template class structures::CircularArrayQueue<int>;
