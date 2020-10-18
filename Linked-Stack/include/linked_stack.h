#ifndef STRUCTURES_LINKED_STACK_H_
#define STRUCTURES_LINKED_STACK_H_

#include <cstdint>

namespace structures {
template <typename T>
class LinkedStack {
 public:
  //! Construtor
  /*!
     Chamado na inicialização do objeto.
  */
  //LinkedStack(void);

  //! Destrutor
  /*!
     Destrói objeto quando esse sai de contexto.
  */
  ~LinkedStack(void);

  //! Limpa Pilha
  /*!
     Método Limpa Pilha. Remove todos os elementos da pilha.
  */
  void clear(void);

  //! Empilha Dado
  /*!
     Método Empilha Elemento. Recebe uma referência constante ao dado a ser
     empilhado e adiciona um nodo contendo o dado no topo da pilha.

     \param data: Referência constante ao dado a ser empilhado (const T&).
  */
  void push(const T& data);

  //! Desempilha Dado
  /*!
     Método Desempilha Dado. Desempilha o nodo no topo da pilha e retorna o dado
     de tipo genérico (T) que contém.

     \return Dado contido no nodo que foi desempilhado, de tipo genérico (T).
   */
  T pop(void);

  //! Topo da Pilha.
  /*!
     Método Topo da Pilha. Retorna uma referência ao dado de tipo genérico no
     topo da pilha. Pode ser usado como operador LHS.

     \return Referência ao dado de tipo genérico (T) contido no nodo no topo da
     estrutura.
   */
  T& top(void);

  //! Topo da Pilha (constante).
  /*!
     Método constante topo da pilha. Retorna uma referência ao dado de tipo
     genérico no topo da pilha. É um método constante, ou seja, não pode alterar
     o objeto que o chamou (enforçado pelo compilador).

     \return Referếncia ao dado de tipo genérico (T) contido no nodo do topo da
     pilha.
   */
  T& top(void) const;

  //! Pilha Vazia
  /*!
     Método constante Pilha Vazia. Retorna um valor booleano, verdadeiro se a
     pilha está vazia, falso se a pilha não está vazia.

     \return true: Pilha vazia.
     \return false: Pilha não vazia.
   */
  bool empty(void) const;

  //! Tamanho da Pilha
  /*!
     Método constante Tamanho da Pilha. Retorna o tamanho atual da pilha.

     \return Tamanho atual da pilha (size_t).
   */
  std::size_t size(void) const;

 private:
  //! Classe Node
  /*!
     Classe nodo, com tipo genérico. Elemento da lista encadeada simples. Possui
     um ponteiro que aponta para o próximo. Armazena dado de tipo genérico T.
  */
  class Node {
   public:
    //! Construtor explícito
    /*!
       Construtor explícito.

       \param data: Referência constante ao dado a ser armazenado (const T&).
     */
    explicit Node(const T& data) : data_{data} {}

    //! Construtor
    /*!
        Construtor com parâmetros de dado e próximo.

        \param data: Referência constante ao dado a ser armazenado (const T&).
        \param next: Próximo nodo da lista (Node*).
     */
    Node(const T& data, Node* next) : data_{data}, next_{next} {}

    //! Método dado
    /*!
       Getter do atributo privado data_. Dado armazenado no nodo.

       \return Referência ao dado armazenado no nodo, de tipo genérico T (T&).
     */
    T& data(void) { return data_; }

    //! Método dado
    /*!
       Getter const do atributo privado data_. Dado armazenado no nodo.

       \return Referência constante ao dado armazenado no nodo, de tipo genérico
       T (const T&).
     */
    const T& data(void) const { return data_; }

    //! Método próximo
    /*!
        Getter do próximo nodo da cadeia.

        \return Ponteiro para nodo.
     */
    Node* next(void) { return next_; }

    //! Método próximo
    /*!
       Getter const do próximo nodo da cadeia.

       \return Ponteiro constante para nodo
     */
    const Node* next(void) const { return next_; }

    //! Método próximo
    /*!
       Setter do atributo next_.

       \param node: Passagem por referência do nodo para configurar com próximo
       (Node *).
     */
    void next(Node* node) { next_ = node; }

    //! Dado
    /*!
      Dado a ser armazenado. Tipo genérico T.
    */
    T data_;

    //! Ponteiro para próximo
    /*!
      Ponteiro para o próximo nodo. De tipo ponteiro para Node. Quando é o
      último nodo da lista aponta para nullptr.
    */
    Node* next_{nullptr};
  };

  //! Topo da Pilha
  /*!
     Ponteiro para nodo. Aponta para o nodo no topo da pilha.
   */
  Node* top_{nullptr};

  //! Tamanho
  /*!
     Tamanho da lista. Tipo size_t.
   */
  std::size_t size_{0u};
};
}  // namespace structures

#endif  // STRUCTURES_LINKED_STACK_H_
