#pragma once

#include "object_oriented_oddities/200/attempt.hh"

// Add a make_animal<T>() constrained factory for clean creation.
template <typename T> std::unique_ptr<T> make_animal() {
  throw std::runtime_error("Unimplemented");
}