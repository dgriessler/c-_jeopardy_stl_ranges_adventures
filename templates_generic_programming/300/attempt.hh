#pragma once

#include <concepts>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Add vector addition and scalar multiplication.
template <Arithmetic T> struct Vec2 {
  T x{}, y{};
};
