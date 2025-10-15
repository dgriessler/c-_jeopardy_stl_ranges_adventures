#pragma once

#include <iostream>
#include <string>

// Create a base class Animal with a virtual speak().
class Animal {
public:
  virtual ~Animal() = default;           // modern: always virtual dtor
  virtual std::string speak() const = 0; // pure virtual
};
