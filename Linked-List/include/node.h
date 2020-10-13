#ifndef LINKED_LIST_INCLUDE_NODE_H_
#define LINKED_LIST_INCLUDE_NODE_H_

namespace structures {
template <typename T>
class Node {
 public:
  explicit Node(T* data);

  Node(T* data, Node* next);

  T* data(void);

  const T* data(void) const;

  Node* next(void);

  const Node* next(void) const;

  void next(Node* node);


 private:
  T* data_ptr_;
  Node* next_ptr_;
};
}  // namespace structures

#endif  // LINKED_LIST_INCLUDE_NODE_H_
