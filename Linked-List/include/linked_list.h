#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>

namespace structures {
template <typename T>
class LinkedList {
 public:
  //! Construtor
  /*!
     Construtor da classe lista encadeada.
   */
  LinkedList(void) = default;

  //! Destrutor
  /*!
     Destrutor da lista encadeada.
   */
  ~LinkedList(void);

  //! Método limpa
  /*!
     Limpa a lista.
   */
  void clear(void);

  //! Método adiciona no fim da lista
  /*!
     Adiciona elemento (data) no fim da lista, se houver espaço. Se não houver
     espaço, lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser adicionado na lista
     (const T&).
   */
  void push_back(const T& data);

  //! Método adiciona no início da lista
  /*!
     Adiciona elemento (data) no início da lista, se houver espaço. Se não
     houver espaço lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser adicionado na lista
     (const T&).
   */
  void push_front(const T& data);

  //! Método insere na posição
  /*!
     Insere elemento (data) em uma dada posição da lista (index), se houver
     espaço e se a posição passada for uma posição válida. Caso não há espaço,
     ou a posição não é válida, lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser inserido (const
     T&). \param index: Posição para inserir o elemento (size_t).
   */
  void insert(const T& data, std::size_t index);

  //! Método insere ordenado
  /*!
     Insere elemento (data) em ordem na lista (caso a lista possua ordem). Se
     não houver mais espaço na lista, lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser inserido (const
     T&).
   */
  void insert_sorted(const T& data);

  //! Método remove do final
  /*!
     Remove elemento no final da lista, se houver elementos. Se não houver
     elementos, lança exceção (out_of_range).

     \return Elemento removido (T).
   */
  T pop_back(void);

  //! Método remove do início
  /*!
     Remove elemento no início da lista e move os elementos restantes "um passo
     para frente", se houver elementos. Se não houver elementos, lança exceção
     (out_of_range).

     \return Elemento removido (T)
   */
  T pop_front(void);

  //! Método remove da posição
  /*!
     Remove elemento na posição passada (index), se houver elementos e se a
     posição for válida. Se não há elementos ou a posição não é válida, lança
     exceção (out_of_range).

     \param index: Posição do elemento a ser removido (size_t).
     \return Elemento removido (T)
   */
  T pop(std::size_t index);

  //! Método remove específico
  /*!
     Remove elemento (data) se este estiver presente na lista. Caso não esteja
     presente lança exceção (invalid_argument). Se não houver elementos na lista
     lança exceção (out_of_range). Quando o elemento está presente, invoca o
     método pop com a posição de data como parâmetro.

     \param data: Referência constante a elemento a ser removido (const T&).
   */
  void remove(const T& data);

  //! Método vazio
  /*!
     Verifica se a lista está vazia. Retorna verdadeiro se estiver vazia, caso
     contrário retorna falso.

     \return true: Lista vazia (bool).
     \return false: Lista contém elementos (bool).
   */
  bool empty(void) const;

  //! Método contém
  /*!
     Verifica se a lista contém o elemento (data). Retorna verdadeiro se contém,
     caso contrário retorna falso.

     \return true: Lista contém o elemento (bool).
     \return false: Lista não contém o elemento (bool).
   */
  bool contains(const T& data) const;

  //! Método achar
  /*!
     Acha a posição do elemento (data). Retorna o índice do elemento. Se o
     elemento não estiver presente, retorna o tamanho da lista.

     \param data: Referência constante ao elemento (const T&).
     \return Posição do elemento, ou tamanho da lista, caso o elemento não está
     presente (size_t).
   */
  std::size_t find(const T& data) const;

  //! Método tamanho
  /*!
     Getter do atributo size_, retorna o tamanho atual da lista.

     \return tamanho máximo da lista (size_t)
   */
  std::size_t size(void) const;

  //! Método "em"
  /*!
     Retorna referência ao elemento na posição (index). Caso o índice seja
     inválido lança exceção (out_of_range).

     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência ao elemento na posição (const T&).
   */
  T& at(std::size_t index);

  //! Sobrecarga do operador []
  /*!
     Retorna referência ao elemento na posição (index). Caso o índice seja
     inválido lança exceção (out_of_range).

     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência ao elemento na posição (const T&).
   */
  T& operator[](std::size_t index);

  //! Método "em"
  /*!
     Retorna referência constante ao elemento na posição (index). Caso o índice
     seja inválido lança erro (out_of_range).

     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência constante ao elemento na posição (const T&).
   */
  const T& at(std::size_t index) const;

  //! Sobrecarga do operador []
  /*!
     Retorna referência constante ao elemento na posição (index). Caso o índice
     seja inválido lança exceção (out_of_range).

     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência constante ao elemento na posição (const T&).
   */
  const T& operator[](std::size_t index) const;

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

  //! Fim
  /*!
     Método auxiliar fim. Segue os ponteiros até o último elemento da lista
     encadeada.

     \return Referência a Node. Último elemento da lista encadeada (Node *).
   */
  Node* end(void) {
    Node * last = head_;

    for (auto i = 1u; i < size(); i++) {
      last = last->next();
    }

    return last;
  }

  //! Método antes do índice
  /*!
      Retorna nodo anterior a um dado índice.

      \param index: Índice para percorer até o anterior (size_t).
      \return Retorna um ponteiro para o nodo anterior ao índice.
   */
  Node* before_index(std::size_t index) {
    Node * before = head_;

    for (auto i = 1u; i < index; i++) {
      before = before->next();
    }

    return before;
  }

 private:
  //! Cabeça de Lista
  /*!
     Cabeça de lista. Ponteiro para node. Aponta para o primeiro elemento da
     lista. (Node *).
   */
  Node* head_{nullptr};

  //! Tamanho
  /*!
     Tamanho da lista. Tipo size_t.
  */
  std::size_t size_{0u};
};
}  // namespace structures

#endif  // STRUCTURES_LINKED_LIST_H
