#include "concurrency_multithreading/200/200.hh"
#include "concurrency_multithreading/400/400.hh"

using FreqMap = std::unordered_map<std::string, size_t>;

void parallel_count(const std::vector<std::vector<std::string>> &chunks,
                    FreqMap &global) {
  std::vector<std::jthread> threads;

} // jthreads auto-join at scope exit
