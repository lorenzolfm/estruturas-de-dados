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
    explicit Node(const T& data) : data_{data} {}

    T data_;
    int height_{0};
    Node* left_child{nullptr};
    Node* right_child{nullptr};

    void insert(const T& data);

    bool remove(const T& data);

    bool contains(const T& data) const;

    void updateHeight(void) {}

    Node* simpleLeft(void);

    Node* simpleRight(void);

    Node* doubleLeft(void);

    Node* doubleRight(void);

    void pre_order(ArrayList<T>& array) const;

    void in_order(ArrayList<T>& array) const;

    void post_order(ArrayList<T>& array) const;

    int height() { return height_; }
  };

  Node* root{nullptr};
  std::size_t size_{0u};
};

}  // namespace structures

#endif
