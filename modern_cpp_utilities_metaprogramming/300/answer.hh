#pragma once
#include <span>

// Write a function that sums numeric values in a std::span
template <typename T>
concept is_numeric = std::integral<T> || std::floating_point<T>;

template <is_numeric T> T sum(std::span<const T> data) {
  T total{};
  for (auto v : data)
    total += v;
  return total;
}
