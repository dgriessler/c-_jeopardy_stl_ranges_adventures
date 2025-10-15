#include "stl_ranges_adventures/200/200.hh"
#include <ranges>

// Transform all words to lowercase with ranges.
void normalize(std::vector<std::string> &words) {
  for (auto &w : words) {
    std::ranges::transform(w, w.begin(),
                           [](unsigned char c) { return std::tolower(c); });
  }
}
