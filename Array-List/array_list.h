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

  T * contents;
  std::size_t size_;      // Posição do último elemento da lista.
  std::size_t max_size_;  // Tamanho máximo da lista
  const static auto DEFAULT_MAX_SIZE = 10u;   // Tamanho máximo padrão
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

}
