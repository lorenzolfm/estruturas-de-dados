#include <cstring>
#include "string_list.h"

void structures::ArrayListString::clear(void) {
  ArrayList::clear();
}

void structures::ArrayListString::push_back(const char * data_ptr) {
  ArrayList::push_back(alloc_data_ptr(data_ptr));
}

void structures::ArrayListString::push_front(const char * data_ptr) {
  ArrayList::push_front(alloc_data_ptr(data_ptr));
}

void structures::ArrayListString::insert(const char * data_ptr, std::size_t index) {
  ArrayList::insert(alloc_data_ptr(data_ptr), index);
}

void structures::ArrayListString::insert_sorted(const char * data_ptr) {
  if (full()) {
    throw(std::out_of_range("Cannot insert in full list"));
  } else if (empty()) {
    push_back(data_ptr);
  } else {
    std::size_t index = 0;
    while (index <= size() - 1 && strcmp(data_ptr, at(index)) > 0){
      index++;
    }
    insert(data_ptr, index);
  }

}

char * structures::ArrayListString::pop(std::size_t index) {
  return ArrayList::pop(index);
}

char * structures::ArrayListString::pop_front(void) {
  return ArrayList::pop_front();
}

void structures::ArrayListString::remove(const char * data_ptr) {
  if (empty()) {
    throw(std::out_of_range("Cannot remove from empty list"));
  } else {
    std::size_t index = find(data_ptr);
    if (index == size()) {
      throw(std::invalid_argument("List does not contain the argument"));
    } else {
      pop(index);
    }
  }
}

std::size_t structures::ArrayListString::find(const char * data_ptr) const {
  if (empty()) {
    throw(std::out_of_range("Cannot find an element on an empty list"));
  }
  std::size_t index = 0;
  while (index <= size() - 1 && !(strcmp(data_ptr, at(index)) == 0)) {
    index++;
  }
  if (index > size() - 1) {
    return size();
  } else {
    return index;
  }
}

bool structures::ArrayListString::contains(const char * data_ptr) const {
  for (std::size_t index = 0; index < size(); index++) {
    if (strcmp(data_ptr, at(index)) == 0) {
      return true;
    }
  }
  return false;
}

char * structures::ArrayListString::alloc_data_ptr(const char * data_ptr) {
  char * new_data_ptr = new char[strlen(data_ptr) + 1];
  snprintf(new_data_ptr, strlen(data_ptr)+1, "%s", data_ptr);

  return new_data_ptr;
}
