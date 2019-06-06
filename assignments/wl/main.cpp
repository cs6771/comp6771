#include <iostream>

#include "assignments/wl/lexicon.h"
#include "assignments/wl/word_ladder.h"

int main() {
  const auto lexicon = GetLexicon("data/words.txt");

  // TODO(students): Replace this with your code
  for (const auto& word : lexicon) {
    std::cout << word << '\n';
  }
}
