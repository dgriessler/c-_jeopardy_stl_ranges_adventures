#include "concurrency_multithreading/200/200.hh"
#include "concurrency_multithreading/400/400.hh"

using FreqMap = std::unordered_map<std::string, size_t>;

void parallel_count(const std::vector<std::vector<std::string>> &chunks,
                    FreqMap &global) {
  std::vector<std::jthread> threads;
  std::mutex mtx;
  for (auto &chunk : chunks) {
    threads.emplace_back([&](std::stop_token st) {
      FreqMap local;
      for (const auto &word : chunk) {
        local.try_emplace(word, 0);
        local[word]++;
      }
      merge_freq(global, mtx, local);
    });
  }
} // jthreads auto-join at scope exit
