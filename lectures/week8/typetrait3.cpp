#include <iostream>
#include <limits>

template <typename T>
struct is_void {
  static const bool val = false;
};

template <>
struct is_void<void> {
  static const bool val = true;
};

int main() {
  std::cout << is_void<int>::val << "\n";
  std::cout << is_void<void>::val << "\n";
}
