#pragma once

// Constrain Vec2<T> so T must be arithmetic.
template <typename T> struct Vec2 {
  T x{}, y{};
};
