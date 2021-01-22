#ifndef STRUCTURES_BINARY_TREE_H
#define STRUCTURES_BINARY_TREE_H

#include "array_list.h"

namespace structures {
template <typename T>
//! Árvore Binária
/*!
   Implementação da árvore binária de busca com percussos.
 */
class BinaryTree {
 private:
  struct Node {
    explicit Node(const T& data) : data_{data} {}

    ~Node(void) {
      delete left_child;
      delete right_child;
    }

    T data_;
    Node* left_child{nullptr};
    Node* right_child{nullptr};

    void insert(const T& data) {
      if (data < data_) {
        // Inserção à esquerda.
        if (left_child == nullptr) {
          // Se não houver filho à esquerda, penduramos o novo dado em um novo
          // filho da esquerda.
          left_child = new Node(data);
          if (left_child == nullptr) throw std::out_of_range("Tree is full!");
        } else {
          // Se houver filho à esquerda, descemos nele e chamamos insert
          // novamente.
          left_child->insert(data);
        }
      } else {
        // Inserção à direita.
        if (right_child == nullptr) {
          // Se não houver filho à direita, penduramos o novo dado em um novo
          // filho da direita.
          right_child = new Node(data);
          if (right_child == nullptr) throw std::out_of_range("Tree is full!");
        } else {
          // Se houver filho à direita, descemos nele e chamamos insert
          // novamente.
          right_child->insert(data);
        }
      }
    }

    bool remove(const T& data) {
      bool removed = false;

      if (data < data_ && left_child != nullptr) {
        left_child = remove(data, left_child, removed);

      } else if (data > data_ && right_child != nullptr) {
        right_child = remove(data, right_child, removed);

      } else {
        if (left_child != nullptr && right_child != nullptr) {
          Node* tmp = right_child->minimun();
          data_ = tmp->data_;
          right_child = remove(data_, right_child, removed);

        } else if (left_child != nullptr) {
          Node* tmp = left_child;

          data_ = tmp->data_;
          left_child = tmp->left_child;
          right_child = tmp->right_child;

          tmp->left_child = nullptr;
          tmp->right_child = nullptr;

          delete tmp;

          removed = true;
        } else if (right_child != nullptr) {
          Node* tmp = right_child;

          data_ = tmp->data_;
          left_child = tmp->left_child;
          right_child = tmp->right_child;

          tmp->left_child = nullptr;
          tmp->right_child = nullptr;

          delete tmp;

          removed = true;
        }
      }
      return removed;
    }

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

   private:

    Node* minimun() {
      if (left_child == nullptr) return this;

      return left_child->minimun();
    }

    Node* remove(const T& data, Node* tree, bool& removed) {
      removed = false;
      if (tree == nullptr)
        return tree;

      if (data < tree->data_) {
        tree->left_child = remove(data, tree->left_child, removed);
        return tree;
      }

      if (data > tree->data_) {
        tree->right_child = remove(data, tree->right_child, removed);
        return tree;
      }

      if (tree->left_child != nullptr && tree->right_child) {
        Node* tmp = tree->right_child->minimun();
        tree->data_ = tmp->data_;
        tree->right_child = remove(data, tree->right_child, removed);
        return tree;
      }

      Node* tmp;
      if (tree->right_child != nullptr)
        tmp = tree->right_child;
      else
        tmp = tree->left_child;

      tree->right_child = nullptr;
      tree->left_child = nullptr;
      delete tree;
      removed = true;
      return tmp;
    }

  };

  Node* root{nullptr};
  std::size_t size_{0u};

 public:
  ~BinaryTree(void);

  //! Inserir Dado
  /*!
     Insere dado na árvore binária.

     \param data: Referência constante de tipo genérico T. Dado a ser inserido.
   */
  void insert(const T& data);

  //! Remover Dado
  /*!
     Remove (se existir) dado da árvore binária.

     \param data: Referência constante de tipo genérico T. Dado a ser removido.
   */
   void remove(const T& data);

  //! Contém Dado
  /*!
     Busca binária por dado na árvore.

     \param data: Referência constante de tipo genérico T. Dado que deseja-se
     buscar. \return true: Dado está contido na árvore. \return false: Dado não
     está contido na árvore.
   */
  bool contains(const T& data) const;

  //! Árvore Vazia
  /*!
     Retorna verdadeiro se a árvore está vazia. Caso contrário retorna falso.

     \return true: Árvore vazia.
     \return false: Árvore não está vazia.
   */
  bool empty(void) const;

  //! Tamanho da Árvore
  /*!
     Retorna o tamanho da árvore (número de nodos). Getter do atributo size_

     \return tamanho: Tamanho da árvore (size_t).
   */
  std::size_t size(void) const;

  //! Pré-ordem
  /*!
     Percorre a árvore utilizando o algoritmo pré-ordem. Retorna uma lista com
     os elementos na ordem percorrida.

     \return lista: Lista (ArrayList<T>) com os elementos na ordem em que foram
     percorridos.
   */
  ArrayList<T> pre_order(void) const;

  //! Pós-ordem
  /*!
     Percorre a árvore utilizando o algoritmo pós-ordem. Retorna uma lista com
     os elementos na ordem percorrida.

     \return lista: Lista (ArrayList<T>) com os elementos na ordem em que foram
     percorridos.
   */
  ArrayList<T> post_order(void) const;

  //! Em-ordem
  /*!
     Percorre a árvore utilizando o algoritmo em-ordem. Retorna uma lista com os
     elementos na ordem percorrida.

     \return lista: Lista (ArrayList<T>) com os elementos na ordem em que foram
     percorridos.
   */
  ArrayList<T> in_order(void) const;

  // Aux method for testing
  Node* get_root(void) const { return root; }
};
}  // namespace structures

#endif
