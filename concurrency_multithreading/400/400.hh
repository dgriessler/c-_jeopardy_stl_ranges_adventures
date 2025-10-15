#pragma once

#include <string>
#include <thread>
#include <vector>

// Process each chunk from 100 on a separate jthread with automatic joining
// calculating word occurrence count.
void parallel_count(const std::vector<std::vector<std::string>> &chunks,
                    std::unordered_map<std::string, size_t> &global);
