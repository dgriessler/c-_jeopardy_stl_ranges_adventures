#pragma once

#include "object_oriented_oddities/100/answer.hh"

// Implement Dog and Cat that override speak().

class Dog : public Animal {
public:
  std::string speak() const override;
};

class Cat : public Animal {
public:
  std::string speak() const override;
};
