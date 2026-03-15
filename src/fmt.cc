#pragma once
#include <fmt/core.h>

#include "strings.cc"

namespace fmtlib = fmt;

namespace fmt {

void Println(strings::String format) { fmtlib::println(format.data); }

template <typename T0>
void Println(strings::String format, T0 arg0) {
  fmtlib::println(format.data, arg0);
}

void Println(strings::String format, strings::String arg0) {
  fmtlib::println(format.data, arg0.data);
}

template <typename T0, typename T1>
void Println(strings::String format, T0 arg0, T1 arg1) {
  fmtlib::println(format.data, arg0, arg1);
}

template <typename T0>
void Println(strings::String format, T0 arg0, strings::String arg1) {
  fmtlib::println(format.data, arg0, arg1.data);
}

template <typename T1>
void Println(strings::String format, strings::String arg0, T1 arg1) {
  fmtlib::println(format.data, arg0.data, arg1);
}

} // namespace fmt