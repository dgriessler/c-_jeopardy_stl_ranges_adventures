#ifdef ANSWER
#include "object_oriented_oddities/200/answer.hh"
#else
#include "object_oriented_oddities/200/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

TEST(Dog, Simple) {
  Dog dog;
  EXPECT_EQ(dog.speak(), "Woof");
}

TEST(Cat, Simple) {
  Cat cat;
  EXPECT_EQ(cat.speak(), "Meow");
}
