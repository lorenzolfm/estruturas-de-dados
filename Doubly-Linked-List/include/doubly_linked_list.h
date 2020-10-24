#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

namespace structures {
template <typename T>
class DoublyLinkedList {
 public:
 private:
  class Node {
   public:
    Node(const T& data);
    Node(const T& data, Node* next);
    Node(const T& data, Node* previous, Node* next);

    T& data(void);
    const T& data(void) const;

    Node* previous(void);
    const Node* previous(void) const;

    void previous(Node* node);

    Node* next(void);
    const Node* next(void) const;

    void next(Node* node);

   private:
    T& data_;
    Node* previous_;
    Node* next_;
  };
};
}  // namespace structures

#endif  // STRUCTURES_LINKED_LIST_H
