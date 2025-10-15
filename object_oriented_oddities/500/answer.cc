#include "object_oriented_oddities/500/answer.hh"

void AnimalFactory::register_creator(const std::string &key, Creator c) {
  get_registry()[key] = std::move(c);
}

std::optional<AnimalPtr> AnimalFactory::create(const std::string &key) {
  auto &reg = get_registry();
  auto it = reg.find(key);
  if (it == reg.end())
    return std::nullopt; // no such animal
  return it->second();
}

std::unordered_map<std::string, AnimalFactory::Creator> &
AnimalFactory::get_registry() {
  static std::unordered_map<std::string, Creator> reg;
  return reg;
}

std::string Dog::name() const { return "Dog"; }
std::string Dog::speak() const { return "Woof"; }

std::string Cat::name() const { return "Cat"; }
std::string Cat::speak() const { return "Meow"; }
