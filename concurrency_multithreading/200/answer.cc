#include "concurrency_multithreading/200/200.hh"

using FreqMap = std::unordered_map<std::string, size_t>;

void merge_freq(FreqMap &global, std::mutex &freq_mutex, const FreqMap &local) {
  std::scoped_lock lock(freq_mutex);
  for (auto &[word, count] : local) {
    global[word] += count;
  }
}
