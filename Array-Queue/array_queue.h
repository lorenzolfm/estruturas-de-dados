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

  int size_;      // Tamanho atual da fila
  int max_size_;  // Tamanho máximo da fila

  static const auto DEFAULT_SIZE = 10u;  // Tamanho padrão da fila
};
}  // namespace structures

#endif

template <typename T>
structures::ArrayQueue<T>::ArrayQueue(void) {
   ArrayQueue<T>(DEFAULT_SIZE);
}

template <typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max_size) {
  max_size_ = DEFAULT_SIZE;
  size_ = -1;
}

template <typename T>
structures::ArrayQueue<T>::~ArrayQueue(void) {

}
