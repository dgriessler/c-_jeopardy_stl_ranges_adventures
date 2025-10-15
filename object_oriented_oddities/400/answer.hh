#pragma once

#include "object_oriented_oddities/200/answer.hh"
#include <concepts>

// Add a make_animal<T>() constrained factory for clean creation.
template <typename T>
  requires std::derived_from<T, Animal>
std::unique_ptr<T> make_animal() {
  return std::make_unique<T>();
}
