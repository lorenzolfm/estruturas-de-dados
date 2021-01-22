#ifndef INCLUDE_CIRCULAR_ARRAY_QUEUE_H_
#define INCLUDE_CIRCULAR_ARRAY_QUEUE_H_

#include <cstdint>
#include <stdexcept>

#include "array_queue.h"

namespace structures {
template <typename T>
//! Classe CircularArrayQueue
/*!
   Classe fila circular em vetor de tipo genérico. Sem movimentação de dados.
   Implementado utilizando um vetor estático.
*/
class CircularArrayQueue : public ArrayQueue<T> {
 public:
  //! Construtor padrão
  /*!
     Cria uma fila circular utilizando o atributo privado de tamanho padrão como
     tamanho máximo.
  */
  CircularArrayQueue(void);

  //! Construtor com parâmetro de tamanho máximo
  /*!
     Cria a fila circular, atribuindo ao tamanho máximo o parâmetro max_size.
     \param max_size: Tamanho máximo da fila circular (size_t)
  */
  explicit CircularArrayQueue(std::size_t max_size);

  //! Destrutor
  /*!
     Usado para destruir o objeto quando não for mais utilizado.
  */
  ~CircularArrayQueue(void);

  //! Método enfileira
  /*!
     Enfileira elemento no final da fila, se houver espaço. Se não houver
     espaço, lança exceção (out_of_range).
     \param data: Referência constante para o elemento a ser enfileirado (const
     T&).
  */
  void enqueue(const T& data);

  //! Método desenfileira
  /*!
     Desenfileira o elemento no início da fila, se houver elementos. Se não
     houver elementos, lança exceção (out_of_range).
     \return Elemento removido (T).
  */
  T dequeue(void);

  //! Método final da fila
  /*!
     Retorna por referência o elemento no final da fila circular.
     \return Referência ao elemento do tipo genérico T (T&).
   */
  T& back(void);

  //! Método limpar
  /*!
     Limpa a fila circular.
   */
  void clear(void);

  //! Método vazio
  /*!
     Verifica se a fila circular está vazia. Retorna verdadeiro se estiver
     vazia, caso contrário retorna falso.
     \return true: Fila circular vazia (bool).
     \return false: Fila circular contém elementos (bool).
   */
  bool empty(void) const;

  //! Método cheio
  /*!
     Verifica se a fila circular está cheia. Retorna verdadeiro se está cheia,
     caso contrário retorna falso.
     \return true: Fila circular cheia (bool).
     \return false: Fila circular não está cheia (bool).
   */
  bool full(void) const;

  //! Método tamanho
  /*!
     Getter do atributo size_, retorna o tamanho atual da fila.
     \return tamanho máximo da fila (size_t)
   */
  std::size_t size(void) const;

  //! Método tamanho máximo
  /*!
     Getter do atributo max_size_, retorna o tamanho máximo da fila circular.
     \return tamanho máximo da fila (size_t).
   */
  std::size_t max_size(void) const;

 private:
  //! Conteúdo
  /*!
     Ponteiro para tipo genérico, armazena elementos.
  */
  T* contents;

  //! Tamanho
  /*!
     Tamanho atual da fila circular. Inicializado em -1.
  */
  std::size_t size_;

  //! Tamanho máximo
  /*!
     Capacidade máxima da fila circular.
  */
  std::size_t max_size_;

  //! Início
  /*!
     Indíce do elemento no ínicio da fila circular.
  */
  int begin_;

  //! Fim
  /*!
     Índice do elemento no final da fila circular.
  */
  int end_;


  //! Tamanho máximo padrão
  /*!
     Capacidade máxima da fila circular, usado pelo construtor padrão
  */
  static const auto DEFAULT_SIZE = 10u;  // Tamanho padrão da fila
};
}  // namespace structures

#endif  // INCLUDE_CIRCULAR_ARRAY_QUEUE_H_
