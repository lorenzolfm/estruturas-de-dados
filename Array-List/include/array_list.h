#ifndef STRUCTURES_ARRAY_LIST_H_
#define STRUCTURES_ARRAY_LIST_H_

#include <cstdint>
#include <stdexcept>

namespace structures {
template <typename T>
//! Classe ArrayList
/*!
   Classe lista em vetor com tipo genérico, implementada usando um vetor
   estático.
*/
class ArrayList {
 public:
  //! Construtor padrão
  /*!
     Cria uma lista utilizando o atributo de tamanho padrão (DEFAULT_MAX_SIZE)
     como tamanho máximo da lista.
  */
  ArrayList(void);

  //! Construtor com parâmetro de tamanho máximo
  /*!
     Cria uma lista utilizando o parâmetro max_size como tamanho máximo da lista

     \param max_size: Tamanho máximo da pilha.
  */
  explicit ArrayList(std::size_t max_size);

  //! Destrutor
  /*!
     Usado para destruir o objeto do tipo lista.
   */
  ~ArrayList(void);

  //! Método limpa
  /*!
     Limpa a lista.
   */
  void clear(void);

  //! Método adiciona no fim da lista
  /*!
     Adiciona elemento (data) no fim da lista, se houver espaço. Se não houver
     espaço, lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser adicionado na lista
     (const T&).
   */
  void push_back(const T& data);

  //! Método adiciona no início da lista
  /*!
     Adiciona elemento (data) no início da lista, se houver espaço. Se não
     houver espaço lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser adicionado na lista
     (const T&).
   */
  void push_front(const T& data);

  //! Método insere na posição
  /*!
     Insere elemento (data) em uma dada posição da lista (index), se houver
     espaço e se a posição passada for uma posição válida. Caso não há espaço,
     ou a posição não é válida, lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser inserido (const
     T&). \param index: Posição para inserir o elemento (size_t).
   */
  void insert(const T& data, std::size_t index);

  //! Método insere ordenado
  /*!
     Insere elemento (data) em ordem na lista (caso a lista possua ordem). Se
     não houver mais espaço na lista, lança exceção (out_of_range).

     \param data: Referência constante para o elemento a ser inserido (const
     T&).
   */
  void insert_sorted(const T& data);

  //! Método remove do final
  /*!
     Remove elemento no final da lista, se houver elementos. Se não houver
     elementos, lança exceção (out_of_range).

     \return Elemento removido (T).
   */
  T pop_back(void);

  //! Método remove do início
  /*!
     Remove elemento no início da lista e move os elementos restantes "um passo
     para frente", se houver elementos. Se não houver elementos, lança exceção
     (out_of_range).

     \return Elemento removido (T)
   */
  T pop_front(void);

  //! Método remove da posição
  /*!
     Remove elemento na posição passada (index), se houver elementos e se a
     posição for válida. Se não há elementos ou a posição não é válida, lança
     exceção (out_of_range).

     \param index: Posição do elemento a ser removido (size_t).
     \return Elemento removido (T)
   */
  T pop(std::size_t index);

  //! Método remove específico
  /*!
     Remove elemento (data) se este estiver presente na lista. Caso não esteja
     presente lança exceção (invalid_argument). Se não houver elementos na lista
     lança exceção (out_of_range). Quando o elemento está presente, invoca o
     método pop com a posição de data como parâmetro.

     \param data: Referência constante a elemento a ser removido (const T&).
   */
  void remove(const T& data);

  //! Método vazio
  /*!
     Verifica se a lista está vazia. Retorna verdadeiro se estiver vazia, caso
     contrário retorna falso.

     \return true: Lista vazia (bool).
     \return false: Lista contém elementos (bool).
   */
  bool empty(void) const;

  //! Método cheio
  /*!
     Verifica se a lista está cheia. Retorna verdadeiro se está cheia, caso
     contrário retorna falso.

     \return true: Lista cheia (bool).
     \return false: Lista não está cheia (bool).
   */
  bool full(void) const;

  //! Método contém
  /*!
     Verifica se a lista contém o elemento (data). Retorna verdadeiro se contém,
     caso contrário retorna falso.

     \return true: Lista contém o elemento (bool).
     \return false: Lista não contém o elemento (bool).
   */
  bool contains(const T& data) const;

  //! Método achar
  /*!
     Acha a posição do elemento (data). Retorna o índice do elemento. Se o
     elemento não estiver presente, retorna o tamanho da lista.

     \param data: Referência constante ao elemento (const T&).
     \return Posição do elemento, ou tamanho da lista, caso o elemento não está
     presente (size_t).
   */
  std::size_t find(const T& data) const;

  //! Método tamanho
  /*!
     Getter do atributo size_, retorna o tamanho atual da lista.

     \return tamanho máximo da lista (size_t)
   */
  std::size_t size(void) const;

  //! Método tamanho máximo
  /*!
     Getter do atributo max_size_, retorna o tamanho máximo da lista.

     \return tamanho máximo da lista (size_t).
   */
  std::size_t max_size(void) const;

  //! Método "em"
  /*!
     Retorna referência ao elemento na posição (index). Caso o índice seja
     inválido lança exceção (out_of_range).

     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência ao elemento na posição (const T&).
   */
  T& at(std::size_t index);

  //! Sobrecarga do operador []
  /*!
     Retorna referência ao elemento na posição (index). Caso o índice seja
     inválido lança exceção (out_of_range).

     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência ao elemento na posição (const T&).
   */
  T& operator[](std::size_t index);

  //! Método "em"
  /*!
     Retorna referência constante ao elemento na posição (index). Caso o índice
     seja inválido lança erro (out_of_range).

     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência constante ao elemento na posição (const T&).
   */
  const T& at(std::size_t index) const;

  //! Sobrecarga do operador []
  /*!
     Retorna referência constante ao elemento na posição (index). Caso o índice
     seja inválido lança exceção (out_of_range).

     \param index: Posição do elemento a ser retornado (size_t).
     \return Referência constante ao elemento na posição (const T&).
   */
  const T& operator[](std::size_t index) const;

 private:
  //! Conteúdo
  /*!
     Ponteiro para tipo genérico, armazena elementos.
   */
  T* contents;

  //! Tamanho
  /*!
     Tamanho atual da lista.
   */
  std::size_t size_;

  //! Tamanho máximo
  /*!
     Tamanho máximo da lista
   */
  std::size_t max_size_;

  //! Tamanho máximo padrão
  /*!
     Capacidade máxima padrão da lista, utilizada pelo construtor sem parâmetros.
   */
  static const auto DEFAULT_MAX_SIZE = 10u;

  //! Método privado mover para frente
  /*!
     Move os elementos da lista "para frente". Copia elemento em [i + 1] para posição [i].

     \param index: indíce para iniciar a movimentação dos dados (size_t).
   */
  void move_forward(std::size_t index);

  //! Método privado mover para trás
  /*!
     Move os elementos da lista "para trás". Copia elemento em [i] para posição [i + 1].

     \param index: indíce para iniciar a movimentação dos dados (size_t).
   */
  void move_backward(std::size_t index);
};
}  // namespace structures

#endif
