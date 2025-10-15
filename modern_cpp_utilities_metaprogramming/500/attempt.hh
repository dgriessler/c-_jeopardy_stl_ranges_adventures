#pragma once

#include <span>

#include "modern_cpp_utilities_metaprogramming/300/answer.hh"

// Use sum and span to compute numeric statistics
template <is_numeric T> struct Stats {
  std::span<const T> data;
  T sum() const { return T(); }
  auto average() const {}
};
