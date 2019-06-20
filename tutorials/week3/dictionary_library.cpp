#include "tutorials/week3/dictionary_library.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

// TODO(tutors): Discuss how the use of istream instead of ifstream improves ease of testing.
std::vector<std::string> ToWordList(std::istream& input) {
  std::vector<std::string> word_list;
  return word_list;
}

// We only ever pass std::cin and std::cout to input and output respectively.
// TODO(tutors): Discuss why we don't just use std::cin and std::cout with respect to testing.
void PrintValidWords(const std::vector<std::string>& valid_words,
                     std::istream& input,
                     std::ostream& output) {
}
