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
  //! move_forward()
  /* Copies data at contents[i + i] to contents[i]
   */
  void move_forward(void);

  T* contents;            // Ponteiro para tipo genérico, armazena elementos
  std::size_t size_;      // Tamanho atual da fila
  std::size_t max_size_;  // Tamanho máximo da fila

  static const auto DEFAULT_SIZE = 10u;  // Tamanho padrão da fila
};
}  // namespace structures

#endif
