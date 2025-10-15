#include "object_oriented_oddities/200/answer.hh"
#include "object_oriented_oddities/300/300.hh"
#include <vector>

using AnimalPtr = std::unique_ptr<Animal>;
int zoo() {
  std::vector<AnimalPtr> zoo;
  zoo.push_back(std::make_unique<Dog>());
  zoo.push_back(std::make_unique<Cat>());
  for (const auto &animal : zoo) {
    std::cout << animal->speak() << '\n';
  }
  return 0;
}
