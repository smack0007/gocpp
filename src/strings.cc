#pragma once
#include <fmt/core.h>
#include <strings.h>

#include "allocator.cc"
#include "panic.cc"
#include "types.cc"

namespace strings {

struct String {
  const char* data;
  uint64 length;

  inline const char& operator[](uint64 index) const {
    if (index >= length) {
      panic("Index out of range.");
    }

    return data[index];
  }

  inline operator const char*() const { return data; }
};

String Join(allocator::Allocator allocator, String str1, String str2) {
  char* data = (char*)allocator.Alloc(str1.length + str2.length + 1);
  data[str1.length + str2.length] = '\0';

  memcpy(data, str1.data, str1.length);
  memcpy(&data[str1.length], str2.data, str2.length);

  return (strings::String){data, str1.length};
}

} // namespace strings

#define STR(x)                                                                 \
  (strings::String) { x, strlen(x) }

uint64 len(strings::String string) { return string.length; }
