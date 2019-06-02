#ifndef TUTORIALS_WEEK2_DICTIONARY_LIBRARY_H_
#define TUTORIALS_WEEK2_DICTIONARY_LIBRARY_H_

#include <istream>
#include <string>
#include <vector>

std::vector<std::string> to_word_list(std::istream& input);

void print_valid_words(const std::vector<std::string>& valid_words,
                       std::istream& input,
                       std::ostream& output);

#endif  // TUTORIALS_WEEK2_DICTIONARY_LIBRARY_H_
