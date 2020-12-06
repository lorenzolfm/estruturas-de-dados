#ifndef STRUCTURES_AVL_TREE_H
#define STRUCTURES_AVL_TREE_H

#include <algorithm>

#include "array_list.h"

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
    explicit Node(const T& data) : data_{data} {}

    T data_;
    int height_{0};
    Node* left_child{nullptr};
    Node* right_child{nullptr};

    ~Node(void) {
      delete left_child;
      delete right_child;
    }

    void insert(const T& data);

    bool remove(const T& data);

    bool contains(const T& data) const {
      if (data < data_) {
        if (left_child == nullptr)
          return false;
        else
          return left_child->contains(data);
      } else if (data > data_) {
        if (right_child == nullptr)
          return false;
        else
          return right_child->contains(data);
      } else {
        return true;
      }
    }

    void updateHeight(void);

    /* Rotações:
     *
     *     a    simpleLeft    b
     *    / \     ----->     / \
     *   x   b              a   z
     *      / \    right   / \
     *     y   z  <-----  x   y
     */
    Node* simpleLeft(void) {
      Node* new_root = left_child;
      left_child = new_root->right_child;
      new_root->right_child = this;

      height_ = std::max(height(left_child), height(right_child) + 1);
      new_root->height_ =
          std::max(height(new_root - left_child), height(this)) + 1;

      return new_root;
    }

    Node* simpleRight(void) {
      Node* new_root = right_child;
      right_child = new_root->left_child;
      new_root->left_child = this;

      height_ = std::max(height(right_child), height(left_child) + 1);
      new_root->height_ =
          std::max(height(new_root->right_child), height(this)) + 1;
    }

    Node* doubleLeft(void) {
      left_child = left_child->simpleRight();
      return simpleLeft();
    }

    Node* doubleRight(void) {
      right_child = right_child->simpleLeft();
      return simpleRight();
    }

    void pre_order(ArrayList<T>& array) const {
      if (this != nullptr) {
        array.push_back(data_);
        left_child->pre_order(array);
        right_child->pre_order(array);
      }
    }

    void in_order(ArrayList<T>& array) const {
      if (this != nullptr) {
        left_child->in_order(array);
        array.push_back(data_);
        right_child->in_order(array);
      }
    }

    void post_order(ArrayList<T>& array) const {
      if (this != nullptr) {
        left_child->post_order(array);
        right_child->post_order(array);
        array.push_back(data_);
      }
    }

    int height(void) {
      if (this == nullptr) return -1;

      return height_;
    }

    Node* minimum(void) {
      if (left_child == nullptr) return this;
      return left_child->minimum();
    }
  };

  Node* root{nullptr};
  std::size_t size_{0u};
};

}  // namespace structures

#endif
