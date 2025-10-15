#include "concurrency_multithreading/500/500.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;
using ::testing::Pair;

TEST(PrintTop, Simple) {
  std::stringstream buffer;
  // Save the original streambuf of std::cout
  std::streambuf *oldCoutBuf = std::cout.rdbuf();

  // Redirect std::cout to the stringstream's streambuf
  std::cout.rdbuf(buffer.rdbuf());

  print_top({{"aba", 3}, {"exempted", 2}, {"send", 1}, {"zulu", 1}}, 2,
            {"exempted"});

  // Restore the original streambuf of std::cout
  std::cout.rdbuf(oldCoutBuf);

  EXPECT_EQ(buffer.str(), " 1.    3 aba\n 2.    1 send\n");
}
