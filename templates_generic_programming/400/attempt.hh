#pragma once

#include <cmath>
#include <concepts>
#include <numbers>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Extend Vec2 with dot(), norm(), and angle() (in radians), using <numbers>
// constants.
template <Arithmetic T> struct Vec2 {
  T x{}, y{};
  T dot(const Vec2 &other) const { return other.x; }
  auto norm() const { return 0.0; }

  // Angle between two vectors in radians
  auto angle(const Vec2 &other) const { return 0.0; }
};

// Convenience: convert radians → degrees
constexpr long double to_degrees(long double radians) { return radians; }
