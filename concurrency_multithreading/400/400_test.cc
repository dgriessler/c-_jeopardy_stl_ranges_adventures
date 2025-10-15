#include "concurrency_multithreading/400/400.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Pair;
using ::testing::UnorderedElementsAre;

using FreqMap = std::unordered_map<std::string, size_t>;

TEST(ParallelCount, Simple) {
  std::vector<std::vector<std::string>> chunks = {
      {"a", "b", "a", "d"},
      {"a", "a", "c", "d"},
      {"a", "b", "b", "b"},
  };
  FreqMap global;
  parallel_count(chunks, global);
  EXPECT_THAT(global, UnorderedElementsAre(Pair("a", 5), Pair("b", 4),
                                           Pair("c", 1), Pair("d", 2)));
}
