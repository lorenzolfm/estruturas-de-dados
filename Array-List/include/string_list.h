#ifndef STRUCTURES_STRING_LIST_H_
#define STRUCTURES_STRING_LIST_H_

#include "array_list.h"

namespace structures {
class ArrayListString : public ArrayList<char *> {
 public:
  ArrayListString(void) : ArrayList() {}

  explicit ArrayListString(std::size_t max_size) : ArrayList(max_size) {}

  ~ArrayListString(void);

  void clear(void);

  void push_back(const char *data);

  void push_front(const char *data);

  void insert(const char *data, std::size_t index);

  void insert_sorted(const char *data);

  char *pop(std::size_t index);

  char *pop_front(void);

  void remove(const char *data);

  bool contains(const char *data) const;

  std::size_t find(const char *data) const;

};
}  // namespace structures

#endif
