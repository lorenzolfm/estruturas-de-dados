#ifndef STRUCTURES_ARRAY_LIST_H_
#define STRUCTURES_ARRAY_LIST_H_

#include <cstdint>
#include <stdexcept>

namespace structures {
template <typename T>
class ArrayList {
 public:
  ArrayList(void);

  explicit ArrayList(std::size_t max_size);

  ~ArrayList(void);

  void clear(void);

  void push_back(const T& data);

  void push_front(const T& data);

  void insert(const T& data, std::size_t index);

  void insert_sorted(const T& data);

  T pop_back(void);

  T pop_front(void);

  T pop(std::size_t index);

  void remove(const T& data);

  bool empty(void);

  bool full(void);

  bool contains(const T& data) const;

  std::size_t find(const T& data) const;

  std::size_t size(void) const;

  std::size_t max_size(void) const;

  T& at(std::size_t index);

  T& operator[](std::size_t index);

  const T& at(std::size_t index) const;

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
