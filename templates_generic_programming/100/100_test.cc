#ifdef ANSWER
#include "templates_generic_programming/100/answer.hh"
#else
#include "templates_generic_programming/100/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

TEST(Vec2, Simple) {
  Vec2<int> v{1, 2};
  EXPECT_EQ(v.x, 1);
  EXPECT_EQ(v.y, 2);
}
