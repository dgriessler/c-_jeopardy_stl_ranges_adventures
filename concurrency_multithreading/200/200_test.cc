#include "concurrency_multithreading/200/200.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <thread>

using ::testing::Pair;
using ::testing::UnorderedElementsAre;

TEST(MergeFreq, Simple) {
  std::unordered_map<std::string, size_t> global;
  std::unordered_map<std::string, size_t> a{{"apple", 1}, {"banana", 2}};
  std::unordered_map<std::string, size_t> b{{"apple", 3}, {"banana", 4}};
  std::mutex mtx;

  auto workerA = [&]() { merge_freq(global, mtx, a); };
  auto workerB = [&]() { merge_freq(global, mtx, b); };

  std::vector<std::thread> threads;
  threads.emplace_back(workerA);
  threads.emplace_back(workerB);
  for (auto &t : threads)
    t.join();

  EXPECT_THAT(global,
              UnorderedElementsAre(Pair("apple", 4), Pair("banana", 6)));
}
