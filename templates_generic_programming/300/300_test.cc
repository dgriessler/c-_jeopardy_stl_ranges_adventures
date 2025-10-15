#ifdef ANSWER
#include "templates_generic_programming/300/answer.hh"
#else
#include "templates_generic_programming/300/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Vec2, Addition) {
  Vec2<int> v1{2, 3};
  Vec2<int> v2{4, 5};
  Vec2<int> sum = v1 + v2;
  EXPECT_EQ(sum.x, 6);
  EXPECT_EQ(sum.y, 8);
}

TEST(Vec2, Multiplication) {
  Vec2<int> v1{2, 3};
  Vec2<int> sum = v1 * 5;
  EXPECT_EQ(sum.x, 10);
  EXPECT_EQ(sum.y, 15);
}
