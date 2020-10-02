#ifndef STRUCTURES_STRING_LIST_H_
#define STRUCTURES_STRING_LIST_H_

#include <cstring>

#include "array_list.h"

namespace structures {
class ArrayListString : public ArrayList<char *> {
 public:
   ArrayListString() : ArrayList() {}

   explicit ArrayListString(std::size_t max_size) : ArrayList(max_size) {}
};
}  // namespace structures

#endif
