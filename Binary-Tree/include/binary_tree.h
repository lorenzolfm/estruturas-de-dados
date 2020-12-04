#ifndef STRUCTURES_BINARY_TREE_H
#define STRUCTURES_BINARY_TREE_H

#include "../../Array-List/include/array_list.h"

namespace structures {
template <typename T>
//! Árvore Binária
/*!
   Implementação da árvore binária de busca com percussos.
 */
class BinaryTree {
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

 private:
  struct Node {
    explicit Node(const T& data)
        : data_{data}, left_node_{nullptr}, right_node_{nullptr} {}

    T data_;
    Node* left_node_;
    Node* right_node_;

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
              data_ = left_node_->data_;
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
      array.push_back(data_);
    }
  };

  Node* root_{nullptr};
  std::size_t size_{0u};
};
}  // namespace structures
#endif
