#ifndef STRUCTURES_CIRCULAR_ARRAY_QUEUE_H_
  #define STRUCTURES_CIRCULAR_ARRAY_QUEUE_H_

  #include <cstdint>
  #include <stdexcept>

namespace structures {
template <typename T>
//! Classe CircularArrayQueue
/* Classe fila em vetor com tipo genérico, sem movimentação de dados.
 *
 * Classe fila em vetor, com tipo génerico, sem movimentação de dados,
 * implementada utilizando um vetor estático.
 */
class CircularArrayQueue {
 public:
  //! Construtor padrão
  /* Cria uma fila utilizando o atributo DEFAULT_SIZE como max_size_
   */
  CircularArrayQueue(void);

  //! Construtor com parâmetro max_size
  /* \param max_size, tipo std::size_t, tamanho máximo da fila
   */
  explicit CircularArrayQueue(std::size_t max_size);

  //! Destrutor
  /* Usado para destruir o objeto quando não for mais utilizado
   */
  ~CircularArrayQueue(void);

  //! enqueue(data)
  /* Insere elemento no final da fila
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
  T* contents;            // Ponteiro para tipo genérico, armazena elementos
  std::size_t size_;      // Tamanho atual da fila
  std::size_t max_size_;  // Tamanho máximo da fila
  int begin_;             // Índice do início
  int end_;               // Índice do fim

  static const auto DEFAULT_SIZE = 10u;  // Tamanho padrão da fila
};
}  // namespace structures

#endif

template <typename T>
structures::CircularArrayQueue<T>::CircularArrayQueue(void) {
  max_size_ = DEFAULT_SIZE;
  begin_ = 0;
  end_ = -1;
  size_ = 0;
  contents = new T[max_size_];
}

template <typename T>
structures::CircularArrayQueue<T>::CircularArrayQueue(std::size_t max_size) {
  max_size_ = max_size;
  begin_ = 0;
  end_ = -1;
  size_ = 0;
  contents = new T[max_size_];
}

template <typename T>
structures::CircularArrayQueue<T>::~CircularArrayQueue(void) {
  delete[] contents;
}

template <typename T>
void structures::CircularArrayQueue<T>::enqueue(const T& data) {
  if (full()) {
    throw(std::out_of_range("Cannot enqueue on full queue"));
  } else {
    end_ = (end_ + 1) % max_size_;
    contents[end_] = data;
    size_++;
  }
}

template <typename T>
T structures::CircularArrayQueue<T>::dequeue(void) {
  if (empty()) {
    throw(std::out_of_range("Cannot dequeue from empty qeueu"));
  } else {
    T data = contents[begin_];
    begin_ = (begin_ + 1) % max_size_;
    size_--;
    return data;
  }
}

template <typename T>
T& structures::CircularArrayQueue<T>::back(void) {
  if (empty()) {
    throw(std::out_of_range("Queue is empty"));
  } else {
    return contents[end_];
  }
}

template <typename T>
void structures::CircularArrayQueue<T>::clear(void) {
  begin_ = 0;
  end_ = -1;
  size_ = 0;
}

template <typename T>
bool structures::CircularArrayQueue<T>::empty(void) {
  return (size_ == 0);
}

template <typename T>
bool structures::CircularArrayQueue<T>::full(void) {
  return (size_ == max_size_);
}

template <typename T>
std::size_t structures::CircularArrayQueue<T>::size(void) {
  return size_;
}

template <typename T>
std::size_t structures::CircularArrayQueue<T>::max_size(void) {
  return max_size_;
}
