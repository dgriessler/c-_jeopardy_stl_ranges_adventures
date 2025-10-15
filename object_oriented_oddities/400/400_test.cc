#ifdef ANSWER
#include "object_oriented_oddities/400/answer.hh"
#else
#include "object_oriented_oddities/400/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(MakeAnimal, Simple) {
  std::unique_ptr<Animal> dog = make_animal<Dog>();
  EXPECT_EQ(dog->speak(), "Woof");
  std::unique_ptr<Animal> cat = make_animal<Cat>();
  EXPECT_EQ(cat->speak(), "Meow");
}
