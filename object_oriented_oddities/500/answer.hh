#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

// Implement a runtime-registrable factory that creates Animal subclasses by
// name (e.g. "Dog", "Cat". The factory should handle unknown types gracefully
// without exceptions. Demonstrate self-registration, creation by name, and
// error reporting.

// ---------- Base ----------
class Animal {
public:
  virtual ~Animal() = default;
  virtual std::string name() const = 0;
  virtual std::string speak() const = 0;
};

using AnimalPtr = std::unique_ptr<Animal>;

// ---------- Factory ----------
class AnimalFactory {
public:
  using Creator = std::function<AnimalPtr()>;

  static void register_creator(const std::string &key, Creator c);

  static std::optional<AnimalPtr> create(const std::string &key);

private:
  static std::unordered_map<std::string, Creator> &get_registry();
};

// ---------- Derived Types ----------
class Dog : public Animal {
public:
  std::string name() const override;
  std::string speak() const override;

private:
  static inline const bool registered = [] {
    AnimalFactory::register_creator("Dog",
                                    [] { return std::make_unique<Dog>(); });
    return true;
  }();
};

class Cat : public Animal {
public:
  std::string name() const override;
  std::string speak() const override;

private:
  static inline const bool registered = [] {
    AnimalFactory::register_creator("Cat",
                                    [] { return std::make_unique<Cat>(); });
    return true;
  }();
};
