#ifndef ASSIGNMENTS_WL_LEXICON_H_
#define ASSIGNMENTS_WL_LEXICON_H_

#include <unordered_set>
#include <string>

// Later on in semester we will learn about exceptions. But for now, we just exit on failure.
void Error(const std::string& message);

std::unordered_set<std::string> GetLexicon(const std::string& filename);

#endif  // ASSIGNMENTS_WL_LEXICON_H_
