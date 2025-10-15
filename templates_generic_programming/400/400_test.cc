#ifdef ANSWER
#include "templates_generic_programming/400/answer.hh"
#else
#include "templates_generic_programming/400/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Vec2, Dot) {
  Vec2<int> x{3, 4};
  Vec2<int> y{7, 1};
  EXPECT_EQ(x.dot(y), 25);
}

TEST(Vec2, Norm) {
  Vec2<int> y{7, 1};
  EXPECT_DOUBLE_EQ(y.norm(), std::sqrt(50));
}

TEST(Vec2, Angle) {
  Vec2<int> x{0, 3};
  Vec2<int> y{3, 0};
  EXPECT_DOUBLE_EQ(x.angle(y), std::numbers::pi_v<long double> / 2);
}

TEST(Global, ToDegrees) {
  EXPECT_DOUBLE_EQ(to_degrees(std::numbers::pi_v<long double>), 180);
}
