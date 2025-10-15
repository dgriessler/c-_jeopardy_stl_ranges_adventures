#pragma once

#include <mutex>
#include <unordered_map>

// Aggregate word counts from multiple threads safely using std::mutex.
void merge_freq(std::unordered_map<std::string, size_t> &global,
                std::mutex &freq_mutex,
                const std::unordered_map<std::string, size_t> &local);
