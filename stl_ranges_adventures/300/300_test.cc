#include "stl_ranges_adventures/300/300.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Pair;
using ::testing::UnorderedElementsAre;

TEST(CountFreq, Simple) {
  std::vector<std::string> words = {"This", "This", "this", "teSt"};
  EXPECT_THAT(
      count_freqs(words),
      UnorderedElementsAre(Pair("This", 2), Pair("this", 1), Pair("teSt", 1)));
}
