#pragma once

#include <concepts>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Constrain Vec2<T> so T must be arithmetic.
template <Arithmetic T> struct Vec2 {
  T x{}, y{};
};
