#include "object_oriented_oddities/300/300.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Zoo, Simple) {
  std::stringstream buffer;
  // Save the original streambuf of std::cout
  std::streambuf *oldCoutBuf = std::cout.rdbuf();

  // Redirect std::cout to the stringstream's streambuf
  std::cout.rdbuf(buffer.rdbuf());

  EXPECT_EQ(zoo(), 0);

  // Restore the original streambuf of std::cout
  std::cout.rdbuf(oldCoutBuf);

  EXPECT_EQ(buffer.str(), "Woof\nMeow\n");
}
