#include "concurrency_multithreading/500/500.hh"
#include <format>
#include <iostream>
#include <ranges>

// Filter out stopwords, take top N, and pretty-print with format.
void print_top(const std::vector<std::pair<std::string, std::size_t>> &sorted,
               std::size_t n,
               const std::unordered_set<std::string> &stopwords) {
  auto view = sorted | std::views::filter([&](auto &p) {
                return !stopwords.contains(p.first);
              }) |
              std::views::take(n);
  int rank = 1;
  for (auto &p : view) {
    std::cout << std::format("{:2}. {:>4} {:<}\n", rank++, p.second, p.first);
  }
}
