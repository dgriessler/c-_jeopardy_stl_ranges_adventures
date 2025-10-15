#pragma once

#include <format>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Add normalize() and std::format support.
template <Arithmetic T> struct Vec2 {
  T x{}, y{};
  Vec2 operator+(const Vec2 &other) const { return {x + other.x, y + other.y}; }
  Vec2 operator*(T scalar) const { return {x * scalar, y * scalar}; }
  T dot(const Vec2 &other) const { return x * other.x + y * other.y; }
  auto norm() const { return std::sqrt(static_cast<long double>(dot(*this))); }
  Vec2 normalize() const { return *this; }
};
// Formatter specialization (C++20)
