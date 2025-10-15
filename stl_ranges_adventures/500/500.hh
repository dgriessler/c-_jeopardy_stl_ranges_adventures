#pragma once

#include <string>
#include <unordered_set>
#include <vector>

// Filter out stopwords, take top N, and pretty-print with format.
void print_top(const std::vector<std::pair<std::string, std::size_t>> &sorted,
               std::size_t n, const std::unordered_set<std::string> &stopwords);
