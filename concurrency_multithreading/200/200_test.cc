#include "concurrency_multithreading/200/200.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

TEST(Normalize, Simple) {
  std::vector<std::string> words = {"This", "IS", "a", "teSt"};
  normalize(words);
  EXPECT_THAT(words, ElementsAre("this", "is", "a", "test"));
}
