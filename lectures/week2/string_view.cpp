#include "lectures/week2/string_view.h"

RopeView Split([[maybe_unused]] const std::string& s, [[maybe_unused]] char delimiter) {
  return {};
}

std::string Join([[maybe_unused]] const RopeView& rope,
                 [[maybe_unused]] const std::string& delimiter) {
  return {};
}

RopeView& Merge(RopeView& lhs, [[maybe_unused]] const RopeView& rhs) {
  return lhs;
}
