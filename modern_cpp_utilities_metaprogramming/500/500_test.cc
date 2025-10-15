#ifdef ANSWER
#include "modern_cpp_utilities_metaprogramming/500/answer.hh"
#else
#include "modern_cpp_utilities_metaprogramming/500/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Fixture : public ::testing::Test {
protected:
  std::vector<int> v_data = {3, 2, 1, 4, 5};
  std::span<const int> s_data = v_data;
  Stats<int> stats{.data = s_data};
};

TEST_F(Fixture, Sum) { EXPECT_EQ(stats.sum(), 3 + 2 + 1 + 4 + 5); }

TEST_F(Fixture, Average) {
  EXPECT_EQ(stats.average(), (3 + 2 + 1 + 4 + 5) / 5);
}
