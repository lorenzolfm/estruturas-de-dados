#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>

namespace structures {
template <typename T>
class DoublyLinkedList {
 public:
  DoublyLinkedList(void);

  ~DoublyLinkedList(void);

  void clear(void);

  void push_back(const T& data);

  void push_front(const T& data);

  void insert(const T& data, std::size_t index);

  void insert_sorted(const T& data);

  T pop(std::size_t index);

  T pop_back(void);

  T pop_front(void);

  void remove(const T& data);

  bool empty(void) const;

  bool contains(void) const;

  T& at(std::size_t index);

  const T& at(std::size_t index) const;

  T& operator[](std::size_t index);

  const T& operator[](std::size_t index) const;

  std::size_t find(const T& data) const;

  std::size_t size(void) const;

 private:
  class Node {
   public:
    explicit Node(const T& data) : data_{data}, previous_{nullptr}, next_{nullptr} {}

    Node(const T& data, Node* next)
        : data_{data}, previous_{nullptr}, next_{next} {}

    Node(const T& data, Node* previous, Node* next)
        : data_{data}, previous_{previous}, next_{next} {}

    T& data(void) { return data_; };

    const T& data(void) const { return data_; }

    Node* previous(void) { return previous_; }

    const Node* previous(void) const { return previous_; }

    void previous(Node* node) { previous_ = node; }

    Node* next(void) { return next_; }

    const Node* next(void) const { return next_; }

    void next(Node* node) { next_ = node; }

   private:
    T data_;
    Node* previous_;
    Node* next_;
  };

  Node* head_;

  std::size_t size_;
};
}  // namespace structures

#endif  // STRUCTURES_LINKED_LIST_H
