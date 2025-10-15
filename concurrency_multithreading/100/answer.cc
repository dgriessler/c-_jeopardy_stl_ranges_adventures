#include "concurrency_multithreading/100/100.hh"

// Split a text vector into N roughly equal chunks for threads.
std::vector<std::vector<std::string>>
chunk_words(const std::vector<std::string> &words, size_t n_chunks) {
  std::vector<std::vector<std::string>> chunks;
  size_t chunk_size = (words.size() + n_chunks - 1) / n_chunks;
  for (size_t i = 0; i < words.size(); i += chunk_size) {
    auto start = i;
    auto end = std::min(i + chunk_size, words.size());
    chunks.emplace_back(words.begin() + start, words.begin() + end);
  }
  return chunks;
}
