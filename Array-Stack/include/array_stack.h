#ifndef STRUCTURES_ARRAY_STACK_H_
#define STRUCTURES_ARRAY_STACK_H_

#include <cstdint>    // std::size_t
#include <stdexcept>  // C++ exceptions

namespace structures {
template <typename T>
//! Classe ArrayStack
/*!
    Classe pilha em vetor, com tipo genérico, implementada utilizando um vetor
    estático.
 */
class ArrayStack {
 public:
  //! Construtor padrão
  /*!
      Cria uma pilha utilizando o atributo de tamanho padrão como tamanho máximo
     da pilha
   */
  ArrayStack(void);

  //! Construtor com parâmetro de tamanho máximo
  /*!
      Cria uma pilha utilizando o parâmetro max_size como tamanho máximo da
      pilha.

     \param max_size: Tamanho máximo da pilha (size_t)
   */
  explicit ArrayStack(std::size_t max_size);

  //! Destrutor
  /*!
    Usado para destruir o objeto quando não for mais utilizado
   */
  ~ArrayStack(void);

  //! Método empilha
  /*!
     Empilha elemento no topo da pilha, se houver espaço. Se não houver espaço,
     lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser empilhado (const
     T&)
   */
  void push(const T& data);

  //! Método desempilha.
  /*!
     Remove dado no topo da pilha o retorna, se houver elementos na pilha. Se
     não houver elementos, lança exceção (out_of_range).

     \return Elemento removido (T).
   */
  T pop(void);

  //! Método topo.
  /*!
    Retorna por referência o elemento no topo.

    \return Referência ao elemento no topo (T&).
   */
  T& top(void);

  //! Método vazio
  /*!
    Verifica se a pilha está vazia. Retorna verdadeiro se a pilha estiver vazia,
    caso contrário retorna falso.

    \return true: Pilha vazia (bool).
    \return false: Pilha contém elementos (bool).
   */
  bool empty(void);

  //! Método cheio
  /*!
    Verifica se pilha está cheia. Retorna verdadeiro se a pilha estiver cheia,
    caso contrário retorna falso.

    \return true: Pilha cheia (bool)
    \return false: Pilha não está cheia (bool).
   */
  bool full(void);

  //! Método limpar.
  /*!
     Limpa a pilha. Atribui -1 para o tamanho da pilha.
   */
  void clear(void);

  //! Método tamanho
  /*!
    Getter do atributo size_, retorna o tamanho atual da pilha.

    \return Tamanho da pilha (size_t).
   */
  std::size_t size(void);

  //! Método tamanho máximo.
  /*!
    Getter do atributo max_size_, retorna tamanho máximo da pilha.

    \return tamanho máximo da pilha (size_t)
   */
  std::size_t max_size(void);

 private:
  //! Conteúdo
  /*!
     Ponteiro para tipo genérico, armazena elementos.
  */
  T* contents;

  //! Topo
  /*!
     Tamanho atual da pilha. Inicializado em -1.
  */
  int top_;

  //! Tamanho máximo
  /*!
     Capacidade máxima da pilha.
  */
  std::size_t max_size_;

  //! Tamanho máximo padrão
  /*!
     Capacida máxima da pilha, usada pelo construtor padrão.
  */
  static const auto DEFAULT_SIZE = 10u;
};
}  // namespace structures

#endif
