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
    explicit Node(const T& data)
        : data_{data}, left_node{nullptr}, right_node{nullptr} {}

    T data_;
    Node* left_node;
    Node* right_node;

    void insert(const T& data);

    bool remove(const T& data);

    bool contains(const T& data) const;

    void pre_order(ArrayList<T> array) const {
      if (this != nullptr) {
        array.push_back(data_);
        left_node->pre_order(array);
        right_node->pre_order(array);
      }
    }

    void in_order(ArrayList<T> array) const {
      if (this != nullptr) {
        left_node->in_order(array);
        array.push_back(data_);
        right_node->in_order(array);
      }
    }

    void post_order(ArrayList<T> array) const {
      if (this != nullptr) { left_node->post_order(array);
        right_node->post_order(array);
        array.push_back(data_);
      }
    }

  };

  Node* root{nullptr};

 public:
  ~BinaryTree(void);

  //! Inserir Dado
  /*!
     Insere dado na árvore binária.

     \param data: Referência constante de tipo genérico T. Dado a ser inserido.
   */
  //void insert(const T& data);

  //! Remover Dado
  /*!
     Remove (se existir) dado da árvore binária.

     \param data: Referência constante de tipo genérico T. Dado a ser removido.
   */
  //void remove(const T& data);

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
  // Público por causa do teste (alterar no final)
  std::size_t size_{0u};
};
}  // namespace structures

#endif
