#include <cstring>
#include "string_list.h"

structures::ArrayListString::~ArrayListString(void) {

}

void structures::ArrayListString::clear(void) {
  ArrayList<char *>::clear();
}

void structures::ArrayListString::push_back(const char * data) {
  char * new_data = new char[strlen(data) + 1];
  snprintf(new_data, strlen(data)+1, "%s", data);

  ArrayList::push_back(new_data);
}

void structures::ArrayListString::push_front(const char * data) {
  char * new_data = new char[strlen(data) + 1];
  snprintf(new_data, strlen(data) + 1, "%s", data);

  ArrayList::push_front(new_data);
}

void structures::ArrayListString::insert(const char * data, std::size_t index) {
  char * new_data = new char[strlen(data) + 1];
  snprintf(new_data, strlen(data) + 1, "%s", data);

  ArrayList::insert(new_data, index);
}

void structures::ArrayListString::insert_sorted(const char * data) {
  if (full()) {
    throw(std::out_of_range("Cannot insert in full list"));
  } else if (empty()) {
    push_back(data);
  } else {
    std::size_t i = 0;
    while (i <= size() - 1 && strcmp(data, at(i)) > 0){
      i++;
    }
    insert(data, i);
  }

}

char * structures::ArrayListString::pop(std::size_t index) {
  return ArrayList::pop(index);
}

char * structures::ArrayListString::pop_front(void) {
  return ArrayList::pop_front();
}

void structures::ArrayListString::remove(const char * data) {
  if (empty()) {
    throw(std::out_of_range("Cannot remove from empty list"));
  } else {
    std::size_t index = find(data);
    if (index == size()) {
      throw(std::invalid_argument("List does not contain the argument"));
    } else {
      pop(index);
    }
  }
}

std::size_t structures::ArrayListString::find(const char * data) const {
  if (empty()) {
    throw(std::out_of_range("Cannot find an element on an empty list"));
  }
  std::size_t index = 0;
  while (index <= size() - 1 && !(strcmp(data, at(index)) == 0)) {
    index++;
  }
  if (index > size() - 1) {
    return size();
  } else {
    return index;
  }
}

bool structures::ArrayListString::contains(const char * data) const {
  for (std::size_t index = 0; index < size(); index++) {
    if (strcmp(data, at(index)) == 0) {
      return true;
    }
  }
  return false;
}
