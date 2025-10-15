#ifdef ANSWER
#include "modern_cpp_utilities_metaprogramming/300/answer.hh"
#else
#include "modern_cpp_utilities_metaprogramming/300/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Sum, Simple) {
  std::vector<int> is{0, 1, 2, 3, 4, 5};
  std::span<const int> s = is;
  EXPECT_EQ(sum(s), 0 + 1 + 2 + 3 + 4 + 5);
}
