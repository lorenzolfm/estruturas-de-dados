#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>

namespace structures {

template <typename T>
//! Classe DoubleCircularList
/*!
   Classe lista circular encadeada.
*/
class DoublyCircularList {
 public:
  //! Construtor
  /*!
     Construtor da classe lista encadeada dupla.
   */
  DoublyCircularList(void);

  //! Destrutor
  /*!
     Destrutor da lista encadeada.
   */
  ~DoublyCircularList(void);

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

  //! Método "em"
  /*!
     Retorna referência ao elemento na posição (index). Caso o índice
     seja inválido lança erro (out_of_range).
     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência ao elemento na posição (const T&).
   */
  T& at(std::size_t index);

  //! Método "em"
  /*!
     Retorna referência constante ao elemento na posição (index). Caso o índice
     seja inválido lança erro (out_of_range).
     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência constante ao elemento na posição (const T&).
   */
  const T& at(std::size_t index) const;

  //! Método remove da posição
  /*!
     Remove elemento na posição passada (index), se houver elementos e se a
     posição for válida. Se não há elementos ou a posição não é válida, lança
     exceção (out_of_range).
     \param index: Posição do elemento a ser removido (size_t).
     \return Elemento removido (T)
   */
  T pop(std::size_t index);

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

 private:
  class Node {
   public:
    explicit Node(const T& data)
        : data_{data}, previous_{nullptr}, next_{nullptr} {}

    Node(const T& data, Node* next)
        : data_{data}, previous_{nullptr}, next_{next} {}

    Node(const T& data, Node* previous, Node* next)
        : data_{data}, previous_{previous}, next_{next} {}

    T& data(void) { return data_; };

    const T& data(void) const { return data_; }

    Node* previous(void) { return previous_; }

    const Node* previous(void) const { return previous_; }

    void previous(Node* node) { previous_ = node; }

    Node* next(void) { return next_; }

    const Node* next(void) const { return next_; }

    void next(Node* node) { next_ = node; }

   private:
    T data_;
    Node* previous_;
    Node* next_;
  };

  Node* before_index(std::size_t index) {
    Node* before = head_->next();

    for (auto i = 1u; i < index; i++) {
      before = before->next();
    }

    return before;
  }

  Node* head_{nullptr};

  std::size_t size_{0u};
};

}  // namespace structures

#endif
