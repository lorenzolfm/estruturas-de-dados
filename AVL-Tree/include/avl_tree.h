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

    ~Node(void) {
      delete left_child;
      delete right_child;
    }

    T data_;
    int height_{0};
    Node* left_child{nullptr};
    Node* right_child{nullptr};

    void insert(const T& data) {
      if (data < data_) {
        if (left_child == nullptr) {
          left_child = new Node(data);
          if (left_child == nullptr)
            throw std::out_of_range("Cannot insert on full tree");
        } else {
          left_child->insert(data);
        }
      } else {
        if (right_child == nullptr) {
          right_child = new Node(data);
          if (right_child == nullptr)
            throw std::out_of_range("Cannot insert on full tree");
        } else {
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

      } else if (data == data_) {
        if (left_child != nullptr && right_child != nullptr) {
          Node* tmp = right_child->minimum();
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

    void updateHeight(void) {
      int height_left, height_right;
      if (left_child == nullptr && right_child == nullptr) {
        height_ = 0;
      } else {
        // Balança o filho da esquerda
        if (left_child != nullptr) {
          left_child->updateHeight();
          switch (left_child->type_balance()) {
            case 0:  // balanceado
              height_left = left_child->left_child->height();
              height_right = left_child->right_child->height();
              left_child->height_ = std::max(height_left, height_right) + 1;
              break;
            case 1:  // Esquerda-esquerda
              left_child = left_child->simpleLeft();
              break;
            case 2:  // Esquerda-direita
              left_child = left_child->doubleLeft();
              break;
            case 3:  // Direita-direita
              left_child = left_child->simpleRight();
              break;
            case 4:  // Direita-direita
              left_child = left_child->doubleRight();
              break;
            default:
              break;
          }
        }
        if (right_child != nullptr) {
          right_child->updateHeight();
          switch (right_child->type_balance()) {
            case 0:  // balanceado
              height_left = right_child->left_child->height();
              height_right = right_child->right_child->height();
              right_child->height_ = std::max(height_left, height_right) + 1;
              break;
            case 1:  // Esquerda-esquerda
              right_child = right_child->simpleLeft();
              break;
            case 2:  // Esquerda-direita
              right_child = right_child->doubleLeft();
              break;
            case 3:  // Direita-direita
              right_child = right_child->simpleRight();
              break;
            case 4:  // Direita-esquerda
              right_child = right_child->doubleRight();
              break;
            default:
              break;
          }
        }
      }
    }

    /* Rotações Simples:
       k1 e k2 são nodos. A, B e C são subárvores

           k2                 k1
          /  \  à esquerda   /  \
         k1   A ----------> B   k2
        /  \    <---------     /  \
       B    C   à direita     C    A

     */
    Node* simpleLeft(void) {
      Node* new_root = left_child;
      left_child = new_root->right_child;
      new_root->right_child = this;

      height_ = std::max(left_child->height(), right_child->height() + 1);
      new_root->height_ =
          std::max(new_root->left_child->height(), height()) + 1;

      return new_root;
    }

    Node* simpleRight(void) {
      Node* new_root = right_child;
      right_child = new_root->left_child;
      new_root->left_child = this;

      height_ = std::max(right_child->height(), left_child->height() + 1);
      new_root->height_ =
          std::max(new_root->right_child->height(), height()) + 1;

      return new_root;
    }

    /* Rotações Duplas:
      k1, k2 e k3 são nodos. A, B, C e D são subárvores
      k3 e k1 é a direção da onde ocorreu o desequilíbrio.

             k3                   k2
            /  \                 /  \
           A   k1   ------->    k3  k1
              /  \             / \  / \
             k2   D           A  B  C  D
            /  \
           B    C
    */
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

    std::size_t type_balance(void) {
      if (left_child->height() - right_child->height() > 1) {
        if (left_child->left_child->height() >
            left_child->right_child->height())
          return 1;
        else
          return 2;
      } else if (right_child->height() - left_child->height() > 1) {
        if (right_child->right_child->height() >
            right_child->left_child->height())
          return 3;
        else
          return 4;
      }
      return 0;
    }

   private:
    Node* minimum(void) {
      if (left_child == nullptr) return this;
      return left_child->minimum();
    }

    Node* remove(const T& data, Node* tree, bool& removed) {
      removed = false;
      if (tree == nullptr) return tree;

      if (data < data_) {
        tree->left_child = remove(data, tree->left_child, removed);
        return tree;
      }

      if (data > data_) {
        tree->right_child = remove(data, tree->right_child, removed);
      }

      if (tree->left_child != nullptr && tree->right_child != nullptr) {
        Node* tmp = tree->right_child->minimum();
        tree->data_ = tmp->data_;
        tree->right_child = remove(data, tree->right_child, removed);
      }

      Node* tmp;
      if (tree->right_child == nullptr)
        tmp = tree->right_child;
      else
        tmp = tree->left_child;

      tree->left_child = nullptr;
      tree->right_child = nullptr;

      delete tree;
      removed = true;
      return tmp;
    }
  };

  Node* root{nullptr};
  std::size_t size_{0u};
};

}  // namespace structures

#endif
