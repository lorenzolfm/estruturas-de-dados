#ifndef STRUCTURES_BINARY_TREE_H
#define STRUCTURES_BINARY_TREE_H

#include "../../Array-List/include/array_list.h"

namespace structures {
template <typename T>
class BinaryTree {
  ~BinaryTree(void);

  void insert(const T& data);

  void remove(const T& data);

  bool contains(const T& data) const;

  bool empty(void) const;

  std::size_t size(void) const;

  ArrayList<T> pre_order(void) const;

  ArrayList<T> post_order(void) const;

  ArrayList<T> in_order(void) const;

 private:
  struct Node {
    Node(const T& data)
        : data_{data}, left_node_{nullptr}, right_node_{nullptr} {}

    void insert(const T& data) {
      Node* new_node;
      if (data < data_) {
        if (left_node_ == nullptr) {
          new_node = new Node(data);
          left_node_ = new_node;
        } else {
          left_node_->insert(data);
        }
      } else {
        if (right_node_ == nullptr) {
          new_node = new Node(data);
          right_node_ = new_node;
        } else {
          right_node_->insert(data);
        }
      }
    }

    bool remove(const T& data) {
      if (data == data_) {
        if ((left_node_ != nullptr) && (right_node_ != nullptr)) {
          Node* node = right_node_;
          while (node->left_node_ != nullptr) {
            node = node->left_node_;
          }
          data_ = node->data_;
          return right_node_->remove(data_);
        } else {
          if (right_node_ != nullptr) {
            data_ = right_node_->data_;
            return right_node_->remove(data_);
          } else {
            if (left_node_ != nullptr) {
              data_ = left_node_->data;
              return left_node_->remove(data_);
            } else {
              delete this;
              return true;
            }
          }
        }
      } else {
        if ((right_node_ != nullptr) && (data_ < data)) {
          return right_node_->remove(data);
        }
        if ((left_node_ != nullptr) && (data_ > data)) {
          return left_node_->remove(data);
        }
      }
      return false;
    }

    bool contains(const T& data) const {
      if (data == data_) {
        return true;
      } else {
        if ((left_node_ != nullptr) && (data_ > data)) {
          return left_node_->contains(data);
        } else if ((right_node_ != nullptr) && (data_ < data)) {
          return right_node_->contains(data);
        }
      }
      return false;
    }

    void pre_order(ArrayList<T>& array) const {
      array.push_back(data_);
      if (left_node_ != nullptr) {
        left_node_->pre_order(array);
      }
      if (right_node_ != nullptr) {
        right_node_->pre_order(array);
      }
    }

    void in_order(ArrayList<T>& array) const {
      if (left_node_ != nullptr) {
        left_node_->in_order(array);
      }
      array.push_back(data_);
      if (right_node_ != nullptr) {
        right_node_->in_order(array);
      }
    }

    void post_order(ArrayList<T>& array) const {
       if (left_node_ != nullptr) {
          left_node_->post_order(array);
       }
       if (right_node_ != nullptr) {
          right_node_->post_order(array);
       }
       array.pop_back(data_);
    }

    T data_;
    Node* left_node_;
    Node* right_node_;
  };

  Node* root_{nullptr};
  std::size_t size_{0};
};
}  // namespace structures
#endif
