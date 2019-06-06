#include <iostream>

#include "assignments/wl/lexicon.h"
#include "assignments/wl/word_ladder.h"

int main() {
  auto lexicon = GetLexicon("assignments/wl/words.txt");

  // TODO(students): Replace this with your code
  for (const auto& word : lexicon) {
    std::cout << word << '\n';
  }
}
