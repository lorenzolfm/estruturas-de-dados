#ifndef STRUCTURES_CIRCULAR_ARRAY_QUEUE_H_
#define STRUCTURES_CIRCULAR_ARRAY_QUEUE_H_

#include "array_queue.h"
#include <cstdint>
#include <stdexcept>

namespace structures {
template <typename T>

class CircularArrayQueue : public ArrayQueue<T> {
 public:

  CircularArrayQueue(void);

  explicit CircularArrayQueue(std::size_t max_size);

  ~CircularArrayQueue(void);

  void enqueue(const T& data);

  T dequeue(void);

  T& back(void);

  void clear(void);

  bool empty(void);

  bool full(void);

  std::size_t size(void);

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
