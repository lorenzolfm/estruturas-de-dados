// Copyright [2020] <Lorenzo Lima Franco Maturano>
#ifndef STRUCTURES_ARRAY_LIST_H_
#define STRUCTURES_ARRAY_LIST_H_

#include <cstdint>
#include <stdexcept>

namespace structures {
template <typename T>
//! Classe ArrayList
/* Classe Lista em vetor com tipo genérico.
 *
 * Classe lista em vetor, com tipo genérico, implementada utilizado um vetor
 * estático
 */
class ArrayList {
 public:
  //! Construtor padrão
  /* Cria uma lista utilizando o atributo DEFAULT_SIZE como
   * max_size_
   */
  ArrayList(void);

  //! Construtor com parâmetro max_size
  /*
   * \param max_size, tipo std::size_t, tamanho máximo da fila
   */
  explicit ArrayList(std::size_t max_size);

  //! ~ArrayList()
  /* Destrutor padrão
   */
  ~ArrayList(void);

  //! clear()
  /* Limpa a lista
   */
  void clear(void);

  //! void push_back(const T& data)
  /* Adiciona data no final da lista
   *
   * \param const T& data, parâmetro constante, referência a T, data
   */
  void push_back(const T& data);

  //! void push_front(const T& data);
  /* Adiciona data no início da lista
   *
   * \param const T& data, referência a data de tipo genérico T constante
   */
  void push_front(const T& data);

  //! void insert(const T& data, std::size_t index);
  /* Insere data na posição index.
   * \param const T& data: parâmetro data constante, de tipo genérico. Dado a
   * ser inserido \param std::size_t index: parâmetro index de tipo size_t,
   * posição para inserir data.
   */
  void insert(const T& data, std::size_t index);

  //! void insert_sorted(const T& data)
  /* Insere data em ordem
   *
   * \param const T& data: referência a elemento de tipo genérico data a ser
   * inserido
   */
  void insert_sorted(const T& data);

  //! T pop_back(void)
  /* Remover e retorna elemento no final da lista
   *
   * \return tipo genérico T, ultimo elemento da lista
   */
  //! empty()
  T pop_back(void);

  //! T pop_front(void);
  /* Retorna e retira elemento no início da lista
   *
   * \return T, elemento de tipo genérico T
   */
  T pop_front(void);

  //! T pop(std::size_t index)
  /* Retorna e retirna elemento na posição index
   *
   * \param size_t index: posição do elemento a ser removido
   */
  T pop(std::size_t index);

  //! void remove(const T& data);
  /* Remove elemento data específico, se estiver presente na lista
   *
   * \param const T& data: Elemento a ser removido
   */
  void remove(const T& data);

  //! bool empty(void);
  /* Retorna true se lista estiver vazia, caso contrário retorna false
   *
   * \return bool
   */
  bool empty(void);

  //! full()
  /* Retorna true caso a lista esteja cheia, caso contrário retorna false
   *
   * \return bool
   */
  bool full(void);

  //! bool contains(const T& data) const
  /* Retorna true se data estiver presente, caso contrário retorna false
   *
   * \param const T& data: referência a elemento de tipo genérico data
   * \return bool: true se data pertencer a lista, caso contrário false
   */
  bool contains(const T& data) const;

  //! std::size_t find(const T& data) const
  /* Retorna índice de data, se estiver na lista
   * \param const T& data: parâmetro de tipo genérico constante.
   * \return std::size_t: Índice de data, retorna -1 se não estiver presente
   */
  std::size_t find(const T& data) const;

  //! size()
  /* Retorna tamanho atual da lista
   *
   * \return std::size_t, tamanho atual da lista
   */
  std::size_t size(void) const;

  //! max_size()
  /* Getter do atributo max_size_
   *
   * \return std::size_t, tamanho máximo da lista
   */
  std::size_t max_size(void) const;

  //! T& at(std::size_ index)
  /* Retorna referência a elemento em index
   *
   * \param std::size_t index: índice do elemento a ser retornado
   * \return T&: referência à elemento de tipo genérico
   */
  T& at(std::size_t index);

  //! T& operator[](std::size_ index)
  /*  Overload do operador []
   *
   * \param std::size_t index: índice do elemento a ser retornado
   * \return T&: referência à elemento de tipo genérico
   */
  T& operator[](std::size_t index);

  //! const T& operator[](std::size_ index)
  /*  Retorna referência constante a elemento em index
   *
   * \param std::size_t index: índice do elemento a ser retornado
   * \return T&: referência à elemento de tipo genérico
   */
  const T& at(std::size_t index) const;

  //! const T& operator[](std::size_ index)
  /*  Overload do operador []
   *
   * \param std::size_t index: índice do elemento a ser retornado
   * \return const t&: referência constante à elemento de tipo genérico
   */
  const T& operator[](std::size_t index) const;

 private:
  T* contents;
  std::size_t size_;      // Posição do último elemento da lista.
  std::size_t max_size_;  // Tamanho máximo da lista
  static const auto DEFAULT_MAX_SIZE = 10u;  // Tamanho máximo padrão

  void move_forward(std::size_t index);
  void move_backward(std::size_t index);
};
}  // namespace structures

#endif
