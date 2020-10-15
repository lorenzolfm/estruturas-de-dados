#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

namespace structures {
template <typename T>
class LinkedList {
 public:
  //! Construtor
  /*!
     Construtor da classe lista encadeada.
   */
  LinkedList(void);

  //! Destrutor
  /*!
     Destrutor da lista encadeada.
   */
  ~LinkedList(void);

  //! Método Limpa.
  /*!
     Limpa a lista encadeada.
  */
  void clear(void);

  //! Método Insere no Fim
  /*!
      Método insere no fim. Recebe dado e insere novo novo no final da listas.

      \param data: Referência constante ao dado a ser encadeado.
   */
  void push_back(const T& data);

  //! Métod Insere No Início
  /*!
     Métod insere elemento no início da lista.

     \param data: referência constante a dado do tipo genérico T.
   */
  void push_front(const T& data);

  //! Método insere
  void insert(const T& data, std::size_t index);

  void insert_sorted(const T& data, std::size_t index);

  T& at(std::size_t index);

  T pop(std::size_t index);

  T pop_back(void);

  T pop_front(void);

  void remove(const T& data);

  bool empty(void) const;

  bool contains(const T& data) const;

  std::size_t find(const T& data) const;

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
        Construtor

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

   private:
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

  //! Fim
  /*!
     Método auxiliar fim. Segue os ponteiros até o último elemento da lista
     encadeada.

     \return Referência a Node. Último elemento da lista encadeada (Node *).
   */
  Node* end(void) {
    auto it = head;
    for (auto i = 1u; i < size(); i++) {
      it = it->next();
    }
  }

  //! Cabeça de Lista
  /*!
     Cabeça de lista. Ponteiro para node. Aponta para o primeiro elemento da
     lista. (Node *).
   */
  Node* head{nullptr};

  //! Tamano
  /*!
     Tamanho da lista. Tipo size_t.
  */
  std::size_t size_{0u};
};
}  // namespace structures

#endif  // STRUCTURES_LINKED_LIST_H
