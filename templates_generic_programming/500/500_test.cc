#ifdef ANSWER
#include "templates_generic_programming/500/answer.hh"
#else
#include "templates_generic_programming/500/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Vec2, Normalize) {
  Vec2<long double> y{7, 1};
  Vec2<long double> normalized = y.normalize();
  EXPECT_DOUBLE_EQ(normalized.x, 7.0 / std::sqrt(50));
  EXPECT_DOUBLE_EQ(normalized.y, 1.0 / std::sqrt(50));
}

TEST(Vec2, Format) {
  Vec2<long double> y{7, 1};
  EXPECT_EQ(std::format("{}", y), "(7, 1)");
}
