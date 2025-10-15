#pragma once

#include <algorithm>
#include <cmath>
#include <concepts>
#include <numbers>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Extend Vec2 with dot(), norm(), and angle() (in radians), using <numbers>
// constants.
template <Arithmetic T> struct Vec2 {
  T x{}, y{};
  T dot(const Vec2 &other) const { return x * other.x + y * other.y; }
  auto norm() const { return std::sqrt(static_cast<long double>(dot(*this))); }

  // Angle between two vectors in radians
  auto angle(const Vec2 &other) const {
    auto cos_theta = dot(other) / (norm() * other.norm());
    return std::acos(std::clamp(cos_theta, -1.0L, 1.0L));
  }
};

// Convenience: convert radians → degrees
constexpr long double to_degrees(long double radians) {
  return radians * 180.0L / std::numbers::pi_v<long double>;
}
