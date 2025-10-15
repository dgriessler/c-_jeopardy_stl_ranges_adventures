#include "stl_ranges_adventures/100/100.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

TEST(SplitToWords, Simple) {
  std::string sentence = "This is a test";
  EXPECT_THAT(split_to_words(sentence), ElementsAre("This", "is", "a", "test"));
}

TEST(SplitToWords, Long) {
  std::string long_sentence = "This is another 2933 sentence that $*#(#$*) has "
                              "31inoi more stuff ,./.,klsd in it";
  EXPECT_THAT(split_to_words(long_sentence),
              ElementsAre("This", "is", "another", "2933", "sentence", "that",
                          "$*#(#$*)", "has", "31inoi", "more", "stuff",
                          ",./.,klsd", "in", "it"));
}
