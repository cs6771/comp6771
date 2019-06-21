#ifndef TUTORIALS_WEEK3_DICTIONARY_LIBRARY_H_
#define TUTORIALS_WEEK3_DICTIONARY_LIBRARY_H_

#include <istream>
#include <string>
#include <vector>

std::vector<std::string> ToWordList(std::istream& input);

void PrintValidWords(const std::vector<std::string>& valid_words,
                     std::istream& input,
                     std::ostream& output);

#endif  // TUTORIALS_WEEK3_DICTIONARY_LIBRARY_H_