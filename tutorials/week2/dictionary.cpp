#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "tutorials/week2/dictionary_library.h"

int main() {
  std::ifstream word_list_file = std::ifstream{"data/words.txt"};
  print_valid_words(to_word_list(word_list_file), std::cin, std::cout);
}
