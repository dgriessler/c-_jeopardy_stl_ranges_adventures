#include "concurrency_multithreading/100/100.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

TEST(ChunkWords, Simple) {
  std::vector<std::string> words = {"these", "are",     "some",
                                    "test",  "strings", "here"};
  EXPECT_THAT(chunk_words(words, 2),
              ElementsAre(ElementsAre("these", "are", "some"),
                          ElementsAre("test", "strings", "here")));
}
