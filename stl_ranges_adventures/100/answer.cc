#include "stl_ranges_adventures/100/100.hh"
#include <sstream>

// Split a sentence into words and store them in a std::vector<std::string>.
std::vector<std::string> split_to_words(const std::string &text) {
  std::istringstream iss(text);
  std::vector<std::string> words;
  std::string w;
  while (iss >> w)
    words.push_back(w);
  return words;
}
