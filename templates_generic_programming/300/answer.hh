#pragma once

#include <concepts>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Add vector addition and scalar multiplication.
template <Arithmetic T> struct Vec2 {
  T x{}, y{};
  Vec2 operator+(const Vec2 &other) const { return {x + other.x, y + other.y}; }
  Vec2 operator*(T scalar) const { return {x * scalar, y * scalar}; }
};
