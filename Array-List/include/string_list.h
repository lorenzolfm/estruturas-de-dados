#ifndef STRUCTURES_STRING_LIST_H_
#define STRUCTURES_STRING_LIST_H_

#include "array_list.h"

namespace structures {
//! Classe ArrayListString
/*!
   Classe lista de strings. Derivada da classe ArrayList. Os elementos dessa
   classe são do tipo ponteiro para char.
 */
class ArrayListString : public ArrayList<char *> {
 public:
  //! Construtor padrão
  /*!
     Cria uma lista de ponteiros para char, usando o atributo de tamanho padrão
     como tamanho máximo da lista.
   */
  ArrayListString(void) : ArrayList() {}

  //! Construtor com parâmetro de tamanho máximo
  /*!
     Cria uma lista de ponteiros para char, usando o parâmetro max_size como
     tamanho máximo da lista.

     \param max_size: Tamanho máximo da lista (size_t).
   */
  explicit ArrayListString(std::size_t max_size) : ArrayList(max_size) {}

  //! Método limpa
  /*!
      Limpa a lista.
   */
  void clear(void);

  //! Método adiciona no fim
  /*!
     Adiciona elemento (data_ptr) no fim da lista, se houver espaço. Caso não há
     espaço, lança exceção (out_of_range).

     \param data_ptr: Ponteiro constante para char (const char *).
   */
  void push_back(const char *data_ptr);

  //! Método adiciona no início
  /*!
     Adiciona elemento (data_ptr) no início da lista, se houver espaço. Caso não
     haja espaço lança exceção (out_of_range).

     \param data_ptr: Ponteiro constante para char (const char *).
   */
  void push_front(const char *data_ptr);

  //! Método insere na posição
  /*!
     Insere elemento (data_ptr) em uma dada posição da lista (index), se houver
     espaço e se a posição passsada for uma posição válida. Se não houver espaço
     lança exceção (out_of_range). Se a posição não é válida lança exceção
     (out_of_range).

     \param data_ptr: Ponteiro constante para char (const char *).
     \param index: Posição para inserir o elemento (size_t).
   */
  void insert(const char *data_ptr, std::size_t index);

  //! Método insere em ordem
  /*!
     Insere elemento (data_ptr) em ordem (alfabética) na lista, caso a lista
     tenha espaço. Se não houver espaço lança exceção (out_of_range).

     \param data_ptr: Ponteiro constante para char (const char *).
   */
  void insert_sorted(const char *data_ptr);

  //! Método remove da posição
  /*!
     Remove elemento na posição (index), se houver elementos e se a posição for
     válida. Se não há elementos ou a posição não é válida lança exceção
     (out_of_range).

     \param index: Posição do elemento a ser removido (size_t).
     \return Ponteiro para elemento removido (char *).
   */
  char *pop(std::size_t index);

  //! Método remove na frente
  /*!
     Remove o elemento no início da lista, se houver elementos na lista. Se a
     lista estiver vazia, lança exceção (out_of_range).

     \return Ponteiro para elemento removido (char *).
   */
  char *pop_front(void);

  //! Método remove específico
  /*!
     Remove elemento (data_ptr) se estiver presente na lista. Se a lista estiver
     vazia lança exceção (out_of_range). Se o elemento não estiver na lista
     lança exceção (invalid_argument).

     \param data_ptr: Ponteiro constante para elemento a ser removido (const
     char *).
   */
  void remove(const char *data_ptr);

  //! Método contém
  /*!
     Retorna verdadeiro se o elemento (data_ptr) estiver na lista, caso
     contrário retorna falso.

     \param data_ptr: Ponteiro constante para elemento (const char *).
     \return true: Caso a lista contenha data_ptr.
     \return false: Caso a lista não contenha data_ptr.
   */
  bool contains(const char *data_ptr) const;

  //! Método achar
  /*!
     Acha a posição do elemento (data_ptr). Retorna o índice do elemento. Se o
     elemento não estiver presente, retorna o tamanho da lista.

     \param data_ptr: Ponteiro constante para char (const char *).
     \return índice do elemento (size_t), ou tamanho da lista.
   */
  std::size_t find(const char *data_ptr) const;

 private:
  //! Método aloca ponteiro data
  /*!
     Aloca memória e copia conteúdo de data_ptr
   */
  char * alloc_data_ptr(const char * data_ptr);
};
}  // namespace structures

#endif
