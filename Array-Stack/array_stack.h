#ifndef STRUCTURES_ARRAY_STACK_H_
  #define STRUCTURES_ARRAY_STACK_H_

  #include <cstdint>    // std::size_t
  #include <stdexcept>  // C++ exceptions

namespace structures {
template <typename T>
//! Classe ArrayStack
/* Classe pilha em vetor com tipo genérico.
 *
 * Classe pilha em vetor, com tipo genérico, implementada utilizando um vetor
 * estático.
 */
class ArrayStack {
 public:
  //! Construtor padrão
  /* Cria uma pilha utilizando o atributo DEFAULT_SIZE como max_size_
   */
  ArrayStack(void);

  //! Construtor com parâmetro max_size
  /* \param max_size, tipo std::size_t, tamanho máximo da pilha
   */
  explicit ArrayStack(std::size_t max_size);

  //! Destrutor
  /* Usado para destruir o objeto quando não for mais utilizado
   */
  ~ArrayStack(void);

  //! Método push()
  /* Insere elemento no topo da pilha
   * \param  Constante local data, tipo genérico T. Elemento a ser inserido no
   * topo da pilha
   */
  void push(const T& data);

  //! Método pop()
  /* Remove dado no topo da pilha e retorna.
   * \return T
   */
  T pop(void);

  //! Método top()
  /* Retorna por referência o elemento no topo
   * \return T&
   */
  T& top(void);

  //! Método empty()
  /* Verifica se a pilha está vazia
   *
   * \return bool
   */
  bool empty(void);

  //! Método full()
  /* Verifica se pilha está cheia
   *
   * \return bool
   */
  bool full(void);

  //! Método clear()
  /* Limpa a pilha
   */
  void clear(void);

  //! Método size()
  /* Método getter. Retorna o tamanho atual da pilha
   * \return std::size_t
   */
  std::size_t size(void);

  //! Método max_size()
  /* Método retorna o tamanho máximo da pilha
   * \return std::size_t
   */
  std::size_t max_size(void);

 private:
  T* contents;    // Ponteiro para tipo genérico, armazena elementos
  int top_;       // Tamanho atual da pilha
  std::size_t max_size_;  // Tamanho máximo da pilha

  static const auto DEFAULT_SIZE = 10u;  // Tamanho padrão da pilha
};
}  // namespace structures

#endif

template <typename T>
structures::ArrayStack<T>::ArrayStack(void) {
  max_size_ = DEFAULT_SIZE;
  top_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayStack<T>::ArrayStack(size_t max_size) {
  max_size_ = max_size;
  top_ = -1;
  contents = new T[max_size_];
}

template <typename T>
structures::ArrayStack<T>::~ArrayStack(void) {
  delete[] contents;
}

template <typename T>
void structures::ArrayStack<T>::push(const T& data) {
  if (full()) {
    throw(std::out_of_range("Stack Overflow"));
  }
  contents[++top_] = data;
}

template <typename T>
T structures::ArrayStack<T>::pop(void) {
  if (empty()) {
    throw(std::out_of_range("Can't pop from empty stack"));
  }
  return contents[top_--];
}

template <typename T>
T& structures::ArrayStack<T>::top() {
  if (empty()) {
    throw(std::out_of_range("Can't pop from empty stack"));
  }
  return contents[top_];
}

template <typename T>
bool structures::ArrayStack<T>::empty(void) {
  return top_ == -1;
}

template <typename T>
bool structures::ArrayStack<T>::full(void) {
  return (size() == max_size_);
}

template <typename T>
void structures::ArrayStack<T>::clear(void) {
  top_ = -1;
}

template <typename T>
std::size_t structures::ArrayStack<T>::size(void) {
  return top_ + 1;
}

template <typename T>
std::size_t structures::ArrayStack<T>::max_size(void) {
  return max_size_;
}
