#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

namespace structures {
template <typename T>
class LinkedList {
 public:
  LinkedList(void);

  ~LinkedList(void);

  void clear(void);

  void push_back(const T& data);

  void push_front(const T& data);

  void insert(const T& data, std::size_t index);

  void insert_sorted(const T& data, std::size_t index);

  T& at(std::size_t index);

  T pop(std::size_t index);

  T pop_back(void);

  T pop_front(void);

  void remove(const T& data);

  bool empty(void) const;

  bool contains(const T& data) const;

  std::size_t find(const T& data) const;

  std::size_t size(void) const;

 private:
  class Node {
   public:
    explicit Node(const T& data) : data_{data} {}

    Node(const T& data, Node* next) : data_{data}, next_{next} {}

    T& data(void) { return data_; }

    const T& data(void) const { return data_; }

    Node* next(void) { return next_; }

    const Node* next(void) const { return next_; }

    void next(Node* node) { next_ = node; }

   private:
    T data_;
    Node* next_{nullptr};
  };

  Node* end(void) {
    auto it = head;
    for (auto i = 1u; i < size(); i++) {
      it = it->next();
    }
  }

  Node* head{nullptr};
  std::size_t size_{nullptr};
};
}  // namespace structures

#endif  // STRUCTURES_LINKED_LIST_H
