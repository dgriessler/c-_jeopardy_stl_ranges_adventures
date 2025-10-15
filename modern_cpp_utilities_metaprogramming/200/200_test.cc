#ifdef ANSWER
#include "modern_cpp_utilities_metaprogramming/200/answer.hh"
#else
#include "modern_cpp_utilities_metaprogramming/200/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

TEST(IsNumeric, Simple) {
  static_assert(is_numeric<int>);
  static_assert(is_numeric<float>);
}
