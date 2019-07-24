#include <array>
#include <iostream>
#include <limits>

template <typename T, auto size>
T findMax(const std::array<T, size>& arr) {
  T largest = std::numeric_limits<T>::min();
  for (const auto& i : arr) {
    if (i > largest)
      largest = i;
  }
  return largest;
}

int main() {
  std::array<int, 3> i{-1, -2, -3};
  std::cout << findMax(i) << "\n";
  std::array<double, 3> j{1.0, 1.1, 1.2};
  std::cout << findMax(j) << "\n";
}
