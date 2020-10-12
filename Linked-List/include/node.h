#ifndef LINKED_LIST_INCLUDE_NODE_H_
#define LINKED_LIST_INCLUDE_NODE_H_

namespace structures {
template <typename T>
class Node {
 public:
  explicit Node(const T& data);

  Node(const T& data, Node* next);

  T& data(void);

  const T& data(void) const;

  const Node* next(void);

  const Node* next(void) const;

  void next(Node* node);

  T data_;
  Node* next_{nullptr};
 private:

};
}  // namespace structures

#endif  // LINKED_LIST_INCLUDE_NODE_H_
