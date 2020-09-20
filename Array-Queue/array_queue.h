#ifndef STRUCTURES_ARRAY_QUEUE_H_
  #define STRUCTURES_ARRAY_QUEUE_H_

  #include <cstdint>
  #include <stdexcept>

namespace structures {
template <typename T>
//! Classe ArrayQueue
/* Classe fila em vetor com tipo genérico, com movimentação de dados.
 *
 * Classe fila em vetor, com tipo génerico, com movimentação de dados,
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

  //! enqueue(data)
  /* final da fila Insere elemento no topo da fila
   *
   * \param  Constante local data, tipo genérico T. Elemento a ser inserido no
   */
  void enqueue(const T& data);

  //! dequeue()
  /* Desenfilera o elemento no início da fila
   *
   * \return elemento de tipo genérico T
   */
  T dequeue(void);

  //! back()
  /* Retorna por referência o elemento no final da fila
   *
   * \return referência ao elemento do tipo genérico T.
   */
  T& back(void);

  //! clear()
  /* Limpa a fila
   */
  void clear(void);

  //! empty()
  /* Retorna true caso fila esteja vazia, caso contrário retorna false.
   *
   * \return bool
   */
  bool empty(void);

  //! full()
  /* Retorna true quando a fila está cheia, caso contrário retorna falso.
   *
   * \return bool
   */
  bool full(void);

  //! size()
  /* Getter do atributo size_
   *
   * \return std::size_t, tamanho atual da fila.
   */
  std::size_t size(void);

  //! max_size()
  /* Getter do atributo max_size_
   *
   * \return std::size_t, tamanho máximo da fila
   */
  std::size_t max_size(void);

 private:
  //! move_forward()
  /* Copies data at contents[i + i] to contents[i]
   */
  void move_forward(void);

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

template <typename T>
void structures::ArrayQueue<T>::enqueue(const T& data) {
  if (full()) {
    throw(std::out_of_range("Cannot enqueue on full queue"));
  } else {
    contents[++size_] = data;
  }
}

template <typename T>
T structures::ArrayQueue<T>::dequeue(void) {
  if (empty()) {
    throw(std::out_of_range("Cannot dequeue an empty queue"));
  }
  T data = contents[0];
  size_--;
  move_forward();
  return data;
}

template <typename T>
T& structures::ArrayQueue<T>::back(void) {
  if (empty()) {
    throw(std::out_of_range("Empty queue"));
  }
  return contents[size_];
}

template <typename T>
void structures::ArrayQueue<T>::clear(void) {
  size_ = -1;
}

template <typename T>
bool structures::ArrayQueue<T>::empty(void) {
  return (size_ == -1);
}

template <typename T>
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

template <typename T>
void structures::ArrayQueue<T>::move_forward(void) {
  for (auto i = 0; i != size(); i++) {
    contents[i] = contents[i + 1];
  }
}
