#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Sort the frequencies descending by count, tie-breaking by lex order
std::vector<std::pair<std::string, std::size_t>>
sort_by_freq(const std::unordered_map<std::string, std::size_t> &freq);
