#ifndef LECTURES_WEEK2_STRING_VIEW_H_
#define LECTURES_WEEK2_STRING_VIEW_H_

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using StringView = std::pair<std::string::const_iterator, std::string::const_iterator>;
using RopeView = std::vector<StringView>;

RopeView Split(const std::string& s, char delimiter);

RopeView& Merge(RopeView& lhs, const RopeView& rhs);
std::string Join(const RopeView& rope, const std::string& delimiter);

#endif  // LECTURES_WEEK2_STRING_VIEW_H_
