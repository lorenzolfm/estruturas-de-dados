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
  ArrayList(std::size_t max_size);
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

  //! T pop_back(void)
  /* Remover e retorna elemento no final da lista
   *
   * \return tipo genérico T, ultimo elemento da lista
   */
  //! empty()
  T pop_back(void);

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

  //! size()
  /* Retorna tamanho atual da lista
   *
   * \return std::size_t, tamanho atual da lista
   */
  std::size_t size(void);

  //! max_size()
  /* Getter do atributo max_size_
   *
   * \return std::size_t, tamanho máximo da lista
   */
  std::size_t max_size(void);

  T* contents;
  std::size_t size_;      // Posição do último elemento da lista.
  std::size_t max_size_;  // Tamanho máximo da lista
  const static auto DEFAULT_MAX_SIZE = 10u;  // Tamanho máximo padrão
};
}  // namespace structures

#endif

template <typename T>
structures::ArrayList<T>::ArrayList(void) {
  max_size_ = DEFAULT_MAX_SIZE;
  size_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
  max_size_ = max_size;
  size_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayList<T>::~ArrayList(void) {
  delete[] contents;
}

template <typename T>
void structures::ArrayList<T>::clear(void) {
  size_ = -1;
}

template <typename T>
void structures::ArrayList<T>::push_back(const T& data) {
  if (full()) {
    throw(std::out_of_range("Cannot push back on full list"));
  }
  contents[++size_] = data;
}

template<typename T>
T structures::ArrayList<T>::pop_back(void) {
  if (empty()) {
    throw(std::out_of_range("Cannot pop back from empty list"));
  }
  return contents[size_--];
}

template <typename T>
bool structures::ArrayList<T>::empty(void) {
  return size_ == -1;
}

template <typename T>
bool structures::ArrayList<T>::full(void) {
  return size_ == max_size_ - 1;
}

template <typename T>
std::size_t structures::ArrayList<T>::size(void) {
  return size_ + 1;
}

template <typename T>
std::size_t structures::ArrayList<T>::max_size(void) {
  return max_size_;
}
