#include "concurrency_multithreading/400/400.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;
using ::testing::Pair;

TEST(SortByFreq, Simple) {
  std::unordered_map<std::string, size_t> words = {
      {"This", 1}, {"this", 2}, {"teSt", 3}};
  EXPECT_THAT(sort_by_freq(words),
              ElementsAre(Pair("teSt", 3), Pair("this", 2), Pair("This", 1)));
}
