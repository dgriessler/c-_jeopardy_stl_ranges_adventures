#include "concurrency_multithreading/400/400.hh"

// Sort the frequencies descending by count, tie-breaking by lex order
std::vector<std::pair<std::string, std::size_t>>
sort_by_freq(const std::unordered_map<std::string, std::size_t> &freq) {
  std::vector<std::pair<std::string, std::size_t>> items(freq.begin(),
                                                         freq.end());
  std::ranges::sort(items, [](auto &a, auto &b) {
    if (a.second != b.second)
      return a.second > b.second;
    return a.first < b.first;
  });
  return items;
}
