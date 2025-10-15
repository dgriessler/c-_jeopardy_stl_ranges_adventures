#ifdef ANSWER
#include "object_oriented_oddities/500/answer.hh"
#else
#include "object_oriented_oddities/500/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Factory, Simple) {
  if (auto maybe_dog = AnimalFactory::create("Dog")) {
    EXPECT_EQ((*maybe_dog)->name(), "Dog");
    EXPECT_EQ((*maybe_dog)->speak(), "Woof");
  } else {
    FAIL() << "Failed to create Dog!";
  }

  if (auto maybe_dragon = AnimalFactory::create("Dragon")) {
    FAIL() << "Succeeded in creating a Dragon!!";
  }
}
