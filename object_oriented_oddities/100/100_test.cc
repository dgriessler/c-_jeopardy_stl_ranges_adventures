#ifdef ANSWER
#include "object_oriented_oddities/100/answer.hh"
#else
#include "object_oriented_oddities/100/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

class AnimalTest : public Animal {
public:
  std::string speak() const override { return "AnimalTest"; }
};

TEST(Animal, Simple) {
  AnimalTest animal_test;
  EXPECT_EQ(animal_test.speak(), "AnimalTest");
}
