#ifdef ANSWER
#include "templates_generic_programming/200/answer.hh"
#else
#include "templates_generic_programming/200/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

TEST(Vec2, Arthemetic) {
  static_assert(std::is_arithmetic_v<int>);
  Vec2<int> v{3, 4};
  EXPECT_EQ(v.x, 3);
  EXPECT_EQ(v.y, 4);
}

TEST(Vec2, NonArthemetic) {
  // lines below should not compile. Comment them out once it doesn't compile!

  static_assert(!std::is_arithmetic_v<std::string>);
  Vec2<std::string> v{"a", "b"};
  EXPECT_EQ(v.x, "a");
  EXPECT_EQ(v.y, "b");
}
