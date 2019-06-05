#include "assignments/wl/lexicon.h"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>

void Error(const std::string& message) {
  std::cout << message << std::endl;
  std::exit(1);
}

std::set<std::string> GetLexicon(const std::string& filename) {
  std::ifstream f{filename};
  if (!f) {
    Error("Failed to open file");
  }
  std::set<std::string> lexicon;
  std::copy(std::istream_iterator<std::string>(f), {},
            std::inserter(lexicon, lexicon.end()));
  if (f.bad()) {
    Error("I/O error while reading");
  }
  if (!f.eof()) {
    Error("Didn't reach end of file");
  }
  return lexicon;
}
