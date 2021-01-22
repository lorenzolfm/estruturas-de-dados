#ifndef STRUCTURES_ARRAY_QUEUE_H_
#define STRUCTURES_ARRAY_QUEUE_H_

#include <cstdint>

namespace structures {
template <typename T>
//! Classe ArrayQueue
/*!
   Classe fila em vetor com tipo genérico, com movimentação de dados.
   Implementada utilizando um vetor estático.
 */
class ArrayQueue {
 public:
  //! Construtor padrão
  /*!
     Cria uma fila utilizando o atributo de tamanho padrão como tamanho máximo
     da fila.
   */
  ArrayQueue(void);

  //! Construtor com parâmetro de tamanho máximo
  /*!
     Cria a filha utilizando o parâmetro max_size como tamanho máximo da fila.

     \param max_size: Tamanho máximo da fila (size_t).
   */
  explicit ArrayQueue(std::size_t max_size);

  //! Destrutor
  /*!
     Usado para destruir o objeto quando não for mais utilizado
   */
  ~ArrayQueue(void);

  //! Método enfileira
  /*!
     Efileira elemento no final da fila, se houver espaço. Se não houver
     espaço, lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser enfileirado (const
     T&).
   */
  void enqueue(const T& data);

  //! Método desenfileira
  /*!
      Desenfilera o elemento no início da fila, se houver elementos. Se não
      houver elementos, lança exceção (out_of_range).

      \return Elemento removido (T).
   */
  T dequeue(void);

  //! Método final da fila
  /*!
     Retorna por referência o elemento no final da fila.

     \return Referência ao elemento do tipo genérico T (T&).
   */
  T& back(void);

  //! Método limpar
  /*!
     Limpa a fila. Atribui -1 para o tamanho da fila.
   */
  void clear(void);

  //! Método vazio
  /*!
     Verifica se a fila está vazia. Retorna verdadeiro se estiver vazia, caso
     contrário retorna falso.

     \return true: Fila vazia (bool).
     \return false: Fila contém elementos (bool).
   */
  bool empty(void) const;

  //! Método cheio
  /*!
     Verifica se a fila está cheia. Retorna verdadeiro se está cheia, caso
     contrário retorna falso.

     \return true: Fila cheia (bool).
     \return false: Fila não está cheia (bool).
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
     Getter do atributo max_size_, retorna o tamanho máximo da fila

     \return tamanho máximo da fila (size_t).
   */
  std::size_t max_size(void) const;

 private:
  //! Método move para frente
  /*!
     Move elementos da fila para frente. Copia elemento em [i + 1] para posição [i].
   */
  void move_forward(void);

  //! Conteúdo
  /*!
     Ponteiro para tipo genérico, armazena elementos.
  */
  T* contents;


  //! Tamanho
  /*!
     Tamanho atual da fila. Inicializado em -1.
  */
  std::size_t size_;

  //! Tamanho máximo
  /*!
     Capacidade máxima da fila
  */
  std::size_t max_size_;

  //! Tamanho máximo padrão
  /*!
     Capacidade máxima da fila, usado pelo construtor padrão
  */
  static const auto DEFAULT_SIZE = 10u;  // Tamanho padrão da fila
};
}  // namespace structures

#endif
