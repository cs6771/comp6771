#include "tutorials/week2/dictionary_library.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

std::vector<std::string> to_word_list(std::istream& input) {
  std::vector<std::string> word_list;
  std::copy(std::istream_iterator<std::string>{input}, std::istream_iterator<std::string>{},
            std::back_inserter(word_list));
  return word_list;
}

void print_valid_words(const std::vector<std::string>& valid_words,
                       std::istream& input,
                       std::ostream& output) {
  std::copy_if(std::istream_iterator<std::string>{input}, std::istream_iterator<std::string>{},
               std::ostream_iterator<std::string>{output, " "}, [&](const auto& word) {
                 return std::find(valid_words.begin(), valid_words.end(), word) !=
                        valid_words.end();
               });
}
