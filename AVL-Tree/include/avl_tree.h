#ifndef STRUCTURES_AVL_TREE_H
#define STRUCTURES_AVL_TREE_H

#include "../../Array-List/include/array_list.h"

namespace structures {
template <typename T>
class AVLTree {
 public:
  ~AVLTree(void);

  void insert(const T& data);

  void remove(const T& data);

  bool contains(const T& data) const;

  bool empty(void) const;

  std::size_t size(void) const;

  int height(void) const;

  ArrayList<T> pre_order(void) const;

  ArrayList<T> in_order(void) const;

  ArrayList<T> post_order(void) const;

 private:
  struct Node {
    explicit Node(const T& data)
        : data_{data}, height_{0}, left_node_{nullptr}, right_node_{nullptr} {}

    T data_;
    int height_;
    Node* left_node_;
    Node* right_node_;

    void insert(const T& data) {
      Node* new_node;
      Node* tree_rotate;

      if (data < data_) {
        if (left_node_ == nullptr) {
          new_node = new Node(data);
          left_node_ = new_node;

          if (left_node_->height() - right_node_->height() > 1) {
            if (data_ < left_node_->data_)
              tree_rotate = simpleLeft(this);
            else
              tree_rotate = doubleLeft(this);

            if (left_node_ == this)
              left_node_ = tree_rotate;
            else
              right_node_ = tree_rotate;
          } else {
            updateHeight(max_height(left_node_, right_node_) + 1);
          }
        } else {
          left_node_->insert(data);
        }
        // (data > data_)
      } else {
        if (right_node_ == nullptr) {
          new_node = new Node(data);
          right_node_ = new_node;

          if (right_node_->height() - left_node_->height() > 1) {
            if (data_ < right_node_->data_)
              tree_rotate = simpleRight(this);
            else
              tree_rotate = doubleRight(this);

            if (right_node_ == this)
              right_node_ = tree_rotate;
            else
              left_node_ = tree_rotate;
          } else {
            updateHeight(max_height(left_node_, right_node_) + 1);
          }
        } else {
          right_node_->insert(data);
        }
      }
    }

    bool remove(const T& data) {
      Node* node;

      if (this == nullptr) {
        return false;

      } else {
        if (data < data_) {
          return left_node_->remove(data);

        } else {
          if (data > data_) {
            return right_node_->remove(data);

          } else {
            if (right_node_ != nullptr && left_node_ != nullptr) {
              node = right_node_->left_node_;
              data_ = node->data_;

              return right_node_->remove(data_);
            } else {
              node = this;
              if (right_node_ != nullptr) {
                node = right_node_;
                data_ = node->data_;

                return right_node_->remove(data_);
              } else {
                if (left_node_ != nullptr) {
                  node = left_node_;
                  data_ = node->data_;

                  return left_node_->remove(node->data_);
                } else {
                  delete this;
                  return true;
                }
              }
            }
          }
        }
      }
    }

    bool contains(const T& data) const {
      if (data_ == data) {
        return true;
      } else {
        if (data_ < data) {
          if (right_node_ == nullptr) return false;

          return right_node_->contains(data);
        } else {
          if (left_node_ == nullptr) return false;
        }

        return left_node_->contains(data);
      }
    }

    void updateHeight(std::size_t height) { height_ = height; }

    Node* simpleLeft(Node* node) {
      Node* new_root;

      new_root = node->left_node_;
      node->left_node_ = new_root->left_node_;
      new_root->right_node_ = node;

      node->updateHeight(max_height(node->left_node_, node->right_node_) + 1);
      new_root->updateHeight(
          max_height(new_root->left_node_, node->right_node_) + 1);

      return new_root;
    }

    Node* simpleRight(Node* node) {
      Node* new_root;

      new_root = node->left_node_;
      node->left_node_ = new_root->right_node_;
      new_root->left_node_ = node;

      node->updateHeight(max_height(node->right_node_, node->left_node_) + 1);
      new_root->updateHeight(max_height(new_root->right_node_, node) + 1);

      return new_root;
    }

    Node* doubleLeft(Node* node_rotate) {
      node_rotate->left_node_ = simpleRight(node_rotate->left_node_);
      return simpleLeft(node_rotate);
    }

    Node* doubleRight(Node* node_rotate) {
      node_rotate->right_node_ = simpleLeft(node_rotate->right_node_);
      return simpleRight(node_rotate);
    }

    int max_height(Node* sub_tree_a, Node* sub_tree_b) {
      int height_sub_tree_a, height_sub_tree_b;

      if (sub_tree_a == nullptr) {
        height_sub_tree_a = -1;
      } else {
        height_sub_tree_a = sub_tree_a->height_;
      }

      if (sub_tree_b == nullptr) {
        height_sub_tree_b = -1;
      } else {
        height_sub_tree_b = sub_tree_b->height_;
      }

      if (height_sub_tree_a > height_sub_tree_b) {
        return height_sub_tree_a;
      }
      return height_sub_tree_b;
    }

    void pre_order(ArrayList<T>& array) const {
      array.push_back(data_);
      if (left_node_ != nullptr) {
        left_node_->pre_order(array);
      }
      if (right_node_ != nullptr) {
        left_node_->pre_order(array);
      }
    }

    void in_order(ArrayList<T>& array) const {
      if (left_node_ != nullptr) {
        left_node_->pre_order(array);
      }
      array.push_back(data_);
      if (right_node_ != nullptr) {
        left_node_->pre_order(array);
      }
    }

    void post_order(ArrayList<T>& array) const {
      if (left_node_ != nullptr) {
        left_node_->pre_order(array);
      }
      if (right_node_ != nullptr) {
        left_node_->pre_order(array);
      }
      array.push_back(data_);
    }

    int height(void) { return height_; };

    Node* root_;
    std::size_t size_{0u};
  };
}  // namespace structures

#endif
