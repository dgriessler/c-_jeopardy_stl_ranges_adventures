#ifdef ANSWER
#include "modern_cpp_utilities_metaprogramming/100/answer.hh"
#else
#include "modern_cpp_utilities_metaprogramming/100/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Factorial, Simple) { EXPECT_EQ(factorial(5), 5 * 4 * 3 * 2 * 1); }
