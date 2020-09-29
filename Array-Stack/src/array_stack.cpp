#include "array_stack.h"

template <typename T>
structures::ArrayStack<T>::ArrayStack(void) {
  max_size_ = DEFAULT_SIZE;
  top_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayStack<T>::ArrayStack(size_t max_size) {
  max_size_ = max_size;
  top_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayStack<T>::~ArrayStack(void) {
  delete[] contents;
}

//template <typename T>
//void structures::ArrayStack<T>::push(const T& data) {
  //if (full()) {
    //throw(std::out_of_range("Stack Overflow"));
  //}
  //contents[++top_] = data;
//}

//template <typename T>
//T structures::ArrayStack<T>::pop(void) {
  //if (empty()) {
    //throw(std::out_of_range("Can't pop from empty stack"));
  //}
  //return contents[top_--];
//}

//template <typename T>
//T& structures::ArrayStack<T>::top() {
  //if (empty()) {
    //throw(std::out_of_range("Can't pop from empty stack"));
  //}
  //return contents[top_];
//}

//template <typename T>
//bool structures::ArrayStack<T>::empty(void) {
  //return top_ == -1;
//}

//template <typename T>
//bool structures::ArrayStack<T>::full(void) {
  //return (size() == max_size_);
//}

//template <typename T>
//void structures::ArrayStack<T>::clear(void) {
  //top_ = -1;
//}

//template <typename T>
//std::size_t structures::ArrayStack<T>::size(void) {
  //return top_ + 1;
//}

template <typename T>
std::size_t structures::ArrayStack<T>::max_size(void) {
  return max_size_;
}

template class structures::ArrayStack<int>;
