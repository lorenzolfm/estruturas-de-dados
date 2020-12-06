#include "../include/avl_tree.h"

template <typename T>
structures::AVLTree<T>::~AVLTree(void) {
  delete root;
}

template <typename T>
void structures::AVLTree<T>::insert(const T& data) {
  if (empty()) {
    root = new Node(data);
    if (root == nullptr) throw std::out_of_range("Full tree!");
  } else {
    root->insert(data);
  }
  ++size_;

  int h_left, h_right;
  root->updateHeight();
  switch (root->type_balance()) {
    case 0:  // balanceado
      h_left = root->left_child->height();
      h_right = root->right_child->height();
      root->height_ = std::max(h_left, h_right) + 1;
      break;
    case 1:  // Esquerda-esquerda
      root = root->simpleLeft();
      break;
    case 2:  // Esquerda-direita
      root = root->doubleLeft();
      break;
    case 3:  // Direita-direita
      root = root->simpleRight();
      break;
    case 4:  // Direita-esquerda
      root = root->doubleRight();
      break;
    default:
      break;
  }
}

template <typename T>
void structures::AVLTree<T>::remove(const T& data) {
  if (empty()) throw std::out_of_range("Empty tree!");

  if (size() != 1u) {
    if (root->remove(data)) {
      size_--;
      int height_left, height_right;
      root->updateHeight();
      switch (root->type_balance()) {
        case 0:
          height_left = root->left_child->height();
          height_right = root->right_child->height();
          root->height_ = std::max(height_left, height_right) + 1;
          break;
        case 1:
          root = root->simpleLeft();
          break;
        case 2:
          root = root->doubleLeft();
          break;
        case 3:
          root = root->simpleRight();
          break;
        case 4:
          root = root->doubleRight();
          break;
        default:
          break;
      }
    }
  } else {
    if (root->data_ == data) {
      delete root;
      root = nullptr;
      size_--;
    }
  }
}

template <typename T>
bool structures::AVLTree<T>::contains(const T& data) const {
  if (empty()) return false;

  return root->contains(data);
}

template <typename T>
std::size_t structures::AVLTree<T>::size(void) const {
  return size_;
}

template <typename T>
bool structures::AVLTree<T>::empty(void) const {
  return size_ == 0u;
}

template <typename T>
structures::ArrayList<T> structures::AVLTree<T>::pre_order(void) const {
  structures::ArrayList<T> array{size()};
  if (!empty()) root->pre_order(array);

  return array;
}

template <typename T>
structures::ArrayList<T> structures::AVLTree<T>::in_order(void) const {
  structures::ArrayList<T> array{size_};
  if (!empty()) root->in_order(array);

  return array;
}

template <typename T>
structures::ArrayList<T> structures::AVLTree<T>::post_order(void) const {
  structures::ArrayList<T> array{size_};
  if (!empty()) root->post_order(array);

  return array;
}

template <typename T>
int structures::AVLTree<T>::height() const {
  return root->height();
}

template class structures::AVLTree<int>;
