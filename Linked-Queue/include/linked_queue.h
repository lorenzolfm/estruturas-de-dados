#ifndef STRUCTURES_LINKED_QUEUE_H_
#define STRUCTURES_LINKED_QUEUE_H_

#include <cstdint>

namespace structures {
template <typename T>
class LinkedQueue {
 public:
  //! Construtor
  /*!
     Chamado na inicialização do objeto.
  */
  LinkedQueue(void);

  //! Destrutor
  /*!
     Destrói objeto quando esse sai de contexto.
  */
  ~LinkedQueue(void);

  //! Limpa Pilha
  /*!
     Método Limpa Pilha. Remove todos os elementos da pilha.
  */
  void clear(void);

  //! Enfileira
  /*!
     Método Enfileira Elemento. Recebe uma referência constante ao dado a ser
     empilhado e adiciona um nodo contendo o dado no final da fila.

     \param data: Referência constante ao dado a ser enfileirado (const T&).
  */
  void enqueue(const T& data);

  //! Desenfileira
  /*!
     Método Desenfileira Dado. Desenfileira o nodo no início da fila e retorna o
     dado de tipo genérico (T) que contém.

     \return Dado contido no nodo que foi desenfileirado, de tipo genérico (T).
   */
  T dequeue(void);

  //! Início da Fila
  /*!
     Método Início da Fila. Retorna uma referência ao dado de tipo genérico no
     início da fila. Pode ser usado como operador LHS.

     \return Referência ao dado de tipo genérico (T) contido no nodo no início
     da fila.
   */
  T& front(void);

  //! Início da Fila (constante).
  /*!
     Método constante início da fila. Retorna uma referência ao dado de tipo
     genérico no início da fila. É um método constante, ou seja, não pode
     alterar o objeto que o chamou (enforçado pelo compilador).

     \return Referếncia ao dado de tipo genérico (T) contido no nodo do início
     da fila.
   */
  const T& front(void) const;

  //! Fim da Fila
  /*!
     Método Fim da Fila. Retorna uma referência ao dado de tipo genérico no
     fim da fila. Pode ser usado como operador LHS.

     \return Referência ao dado de tipo genérico (T) contido no nodo no fim da
     fila.
   */
  T& back(void);

  //! Fim da Fila (constante).
  /*!
     Método constante fim da fila. Retorna uma referência ao dado de tipo
     genérico no fim da fila. É um método constante, ou seja, não pode alterar
     o objeto que o chamou (enforçado pelo compilador).

     \return Referếncia ao dado de tipo genérico (T) contido no nodo do fim da
     fim.
   */
  const T& back(void) const;

  //! Fila Vazia
  /*!
     Método constante Fila Vazia. Retorna um valor booleano, verdadeiro se a
     fila está vazia, falso se a fila não está vazia.

     \return true: Fila vazia.
     \return false: Fila não vazia.
   */
  bool empty(void) const;

  //! Tamanho da Fila
  /*!
     Método constante Tamanho da Fila. Retorna o tamanho atual da Fila.

     \return Tamanho atual da fila (size_t).
   */
  std::size_t size(void) const;

 private:
  //! Classe Node
  /*!
     Classe nodo, com tipo genérico. Elemento da fila encadeada simples. Possui
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
        \param next: Próximo nodo da fila (Node*).
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
      último nodo da fila aponta para nullptr.
    */
    Node* next_{nullptr};
  };

  //! Início da Fila
  /*!
     Ponteiro para nodo. Aponta para o nodo no início da fila.
   */
  Node* head_;

  //! Fim da Fila
  /*!
     Ponteiro para nodo. Aponta para o nodo no fim da fila.
   */
  Node* tail_;

  //! Tamanho
  /*!
     Tamanho da pilha. Tipo size_t.
   */
  std::size_t size_;
};
}  // namespace structures

#endif
