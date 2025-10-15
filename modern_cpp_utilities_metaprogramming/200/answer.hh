#pragma once

#include <concepts>

// Add a helper is_numeric concept to constrain templates.

template <typename T>
concept is_numeric = std::integral<T> || std::floating_point<T>;
