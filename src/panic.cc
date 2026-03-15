#pragma once
#include <cstdio>
#include <cstdlib>

#include "core.cc"

[[noreturn]] void panic(const char* s) noexcept {
  std::fputs(s, stderr);
  std::abort();
}