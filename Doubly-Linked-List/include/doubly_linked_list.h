#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

namespace structures {
template <typename T>
class DoublyLinkedList {
 public:
 private:
  class Node {
   public:
    Node(const T& data) : data_{data}, previous_{nullptr}, next_{nullptr} {}

    Node(const T& data, Node* next)
        : data_{data}, previous_{nullptr}, next_{next} {}

    Node(const T& data, Node* previous, Node* next)
        : data_{data}, previous_{previous}, next_{next} {}

    T& data(void) {
      return const_cast<T&>(static_cast<const Node*>(this)->data());
    };

    const T& data(void) const { return data_; }

    Node* previous(void) {
      return const_cast<Node*>(static_cast<const Node*>(this)->previous());
    }
    const Node* previous(void) const { return previous_; }

    void previous(Node* node) { previous_ = node; }

    Node* next(void) {
      return const_cast<Node*>(static_cast<const Node*>(this)->next());
    }

    const Node* next(void) const { return next_; }

    void next(Node* node) { next_ = node; }

   private:
    T& data_;
    Node* previous_;
    Node* next_;
  };
};
}  // namespace structures

#endif  // STRUCTURES_LINKED_LIST_H
