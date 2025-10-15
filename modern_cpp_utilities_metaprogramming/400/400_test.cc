#ifdef ANSWER
#include "modern_cpp_utilities_metaprogramming/400/answer.hh"
#else
#include "modern_cpp_utilities_metaprogramming/400/attempt.hh"
#endif
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(FloatToBits, Simple) { EXPECT_EQ(float_to_bits(1.0), 0x3f800000); }
