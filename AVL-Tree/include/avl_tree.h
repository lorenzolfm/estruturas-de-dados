#ifndef STRUCTURES_AVL_TREE_H
#define STRUCTURES_AVL_TREE_H

#include "../../Array-List/include/array_list.h"

namespace structures {

template <typename T>
//! Árvore AVL
/*!
   Implementação da árvore binária semibalanceada AVL utilizando class
   templates.
 */
class AVLTree {
 public:
  //! Destrutor
  /*!
     Destrutor do objeto AVLTree.
   */
  ~AVLTree(void);

  //! Inserir Dado
  /*!
     Insere dado na árvore AVL.

     \param data: Referência constante a tipo genérico (const T&), dado a ser
     inserido.
   */
  void insert(const T& data);

  //! Remover Dado
  /*!
     Remove dado da árvore AVL.

     \param data: Referência constante a tipo genérico (const T&), dado a ser
     removido.
   */
  void remove(const T& data);

  //! Buscar Dado
  /*!
     Busca um dado na árvore AVL.

     \param data: Referência constante a tipo genérico (const T&), dado a ser
     buscado. \return true: Contém o dado. \return false: Não contém o dado.
   */
  bool contains(const T& data) const;

  //! Vazio
  /*!
     Retorna se a árvore está vazia ou não.

     \return true: Árvore está vazia.
     \return false: Árvore não está vazia.
   */
  bool empty(void) const;

  //! Tamanho
  /*!
     Retorna o tamanho da árvore. Getter do atributo size_.

     \return size: Tamanho da árvore (size_t)
   */
  std::size_t size(void) const;

  //! Altura
  /*!
     Retorna altura da raíz.

     \return altura: Altura da raíz.
   */
  int height(void) const;

  //! Pré-ordem
  /*!
     Percorre a árvore utilizando o algoritmo pré-ordem. Retorna uma lista com
     os elementos na ordem percorrida.

     \return lista: Lista (ArrayList<T>) com os elementos na ordem em que foram
     percorridos.
   */
  ArrayList<T> pre_order(void) const;

  //! Em-ordem
  /*!
     Percorre a árvore utilizando o algoritmo em-ordem. Retorna uma lista com os
     elementos na ordem percorrida.

     \return lista: Lista (ArrayList<T>) com os elementos na ordem em que foram
     percorridos.
   */
  ArrayList<T> in_order(void) const;

  //! Pós-ordem
  /*!
     Percorre a árvore utilizando o algoritmo pós-ordem. Retorna uma lista com
     os elementos na ordem percorrida.

     \return lista: Lista (ArrayList<T>) com os elementos na ordem em que foram
     percorridos.
   */
  ArrayList<T> post_order(void) const;

 private:
  struct Node {
    explicit Node(const T& data)
        : data_{data}, height_{0}, left_node{nullptr}, right_node{nullptr} {}

    T data_;
    int height_;
    Node* left_node;
    Node* right_node;

    void insert(const T& data) {
      Node* new_node;
      Node* tree_rotate;

      if (this == nullptr) {
        new_node = new Node(data);
        if (new_node == nullptr)
          throw std::out_of_range("AVL Tree is full");
      } else {
        if (data_ < data) {
          left_node->insert(data);
          if (left_node->height() - right_node->height() > 1) {
            if (data < left_node->data_)
              tree_rotate = simpleLeft();
            else
              tree_rotate = doubleLeft();

            if (left_node == this)
              left_node = tree_rotate;
            else
              right_node = tree_rotate;
          } else {
            new_node->updateHeight(max_height(left_node, right_node) + 1);
          }
        } else {
          if (data > data_) {
            right_node->insert(data);

            if (right_node->height() - left_node->height() > 1) {
              if (data < right_node->data_)
                tree_rotate = simpleRight();
              else
                tree_rotate = doubleRight();

              if (right_node == this)
                right_node = tree_rotate;
              else
                left_node = tree_rotate;
            } else {
              new_node->updateHeight(max_height(left_node, right_node) + 1);
            }
          } else {
            throw std::out_of_range("Key already on tree");
          }
        }
      }
    }

    bool remove(const T& data) {

    }

    bool contains(const T& data) const {
      if (data_ == data) {
        return true;
      } else {
        if (data_ < data) {
          if (right_node == nullptr) return false;

          return right_node->contains(data);
        } else {
          if (left_node == nullptr) return false;

          return left_node->contains(data);
        }
      }
    }

    void updateHeight(int height) { height_ = height; }

    Node* simpleLeft() {
      Node* new_root;

      new_root = left_node;
      left_node = new_root->left_node;
      new_root->right_node = this;

      updateHeight(max_height(left_node, right_node) + 1);
      new_root->updateHeight(max_height(new_root->left_node, right_node) + 1);

      return new_root;
    }

    Node* simpleRight(void) {
      Node* new_root;

      new_root = left_node;
      left_node = new_root->right_node;
      new_root->left_node = this;

      updateHeight(max_height(right_node, left_node) + 1);
      new_root->updateHeight(max_height(new_root->right_node, this) + 1);
    }

    Node* doubleLeft(void) {
      left_node = left_node->simpleRight();
      return simpleLeft();
    }

    Node* doubleRight(void) {
      right_node = right_node->simpleLeft();
      return simpleRight();
    }

    void pre_order(ArrayList<T>& array) const {
      if (this != nullptr) {
        array.push_back(data_);
        left_node->pre_order(array);
        right_node->post_order(array);
      }
    }

    void in_order(ArrayList<T>& array) const {
      if (this != nullptr) {
        left_node->in_order(array);
        array.push_back(data_);
        right_node->in_order(array);
      }
    }

    void post_order(ArrayList<T>& array) const {
      if (this != nullptr) {
        left_node->post_order(array);
        right_node->post_order(array);
        array.push_back(data_);
      }
    }

    int height() {
      if (this == nullptr) return -1;

      return height_;
    }

    int max_height(Node* sub_tree_a, Node* sub_tree_b) {
      int height_a, height_b;

      if (sub_tree_a == nullptr)
        height_a = -1;
      else
        height_a = sub_tree_a->height_;

      if (sub_tree_b == nullptr)
        height_b = -1;
      else
        height_b = sub_tree_b->height_;

      if (height_a > height_b)
        return height_a;
      else
        return height_b;
    }
  };

  Node* root;
  std::size_t size_;
};

}  // namespace structures

#endif
