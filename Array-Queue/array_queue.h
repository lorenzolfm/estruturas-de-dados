#ifndef STRUCTURES_ARRAY_QUEUE_H_
  #define STRUCTURES_ARRAY_QUEUE_H_

  #include <cstdint>
  #include <stdexcept>

namespace structures {
template <typename T>
//! Classe ArrayQueue
/* Classe fila em vetor com tipo genérico, sem movimentação de dados.
 *
 * Classe fila em vetor, com tipo génerico, sem movimentação de dados,
 * implementada utilizando um vetor estático.
 */
class ArrayQueue {
 public:
  //! Construtor padrão
  /* Cria uma fila utilizando o atributo DEFAULT_SIZE como max_size_
   */
  ArrayQueue(void);

  //! Construtor com parâmetro max_size
  /* \param max_size, tipo std::size_t, tamanho máximo da fila
   */
  explicit ArrayQueue(std::size_t max_size);

  //! Destrutor
  /* Usado para destruir o objeto quando não for mais utilizado
   */
  ~ArrayQueue(void);

  //! empty()
  /* \return bool
   * retorna true caso fila esteja vazia, caso contrário retorna false.
   */
  bool empty(void);

  //! full()
  /* \return bool
   *
   * Retorna true quando a fila está cheia, caso contrário retorna falso.
   */
  bool full(void);

  //! size()
  /* \return std::size_t, tamanho atual da fila.
   *
   * Getter do atributo size_
   */
  std::size_t size(void);

  //! max_size()
  /* \return std::size_t, tamanho máximo da fila
   *
   * Getter do atributo max_size_
   */
  std::size_t max_size(void);

  T* contents;    // Ponteiro para tipo genérico, armazena elementos
  int size_;      // Tamanho atual da fila
  int max_size_;  // Tamanho máximo da fila

  static const auto DEFAULT_SIZE = 10u;  // Tamanho padrão da fila
};
}  // namespace structures

#endif

template <typename T>
structures::ArrayQueue<T>::ArrayQueue(void) {
  max_size_ = DEFAULT_SIZE;
  size_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max_size) {
  max_size_ = max_size;
  size_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayQueue<T>::~ArrayQueue(void) {
  delete[] contents;
}

template<typename T>
bool structures::ArrayQueue<T>::empty(void) {
   return (size_ == -1);
}

template<typename T>
bool structures::ArrayQueue<T>::full(void) {
   return (size() == max_size_);
}

template <typename T>
std::size_t structures::ArrayQueue<T>::size(void) {
  return (size_ + 1);
}

template <typename T>
std::size_t structures::ArrayQueue<T>::max_size(void) {
  return max_size_;
}
