#include "concurrency_multithreading/300/300.hh"

// Count word frequencies in an unordered_map.
std::unordered_map<std::string, std::size_t>
count_freqs(const std::vector<std::string> &words) {
  std::unordered_map<std::string, std::size_t> freq;
  for (auto &w : words) {
    ++freq[w];
  }
  return freq;
}
