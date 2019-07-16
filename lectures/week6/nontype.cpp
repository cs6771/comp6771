#include <array>
#include <iostream>

template <typename T, uint64_t size>
T findmin(const std::array<T, size>& a) {
  T min = a[0];
  for (uint64_t i = 1; i < size; ++i) {
    if (a[i] < min)
      min = a[i];
  }
  return min;
}

int main() {
  std::array<int, 3> x{3, 1, 2};
  std::array<double, 4> y{3.3, 1.1, 2.2, 4.4};
  std::array<double, 5> z{3.3, 1.1, 2.2, 4.4, 5.5};
  std::cout << "min of x = " << findmin(x) << "\n";
  std::cout << "min of x = " << findmin(y) << "\n";
  std::cout << "min of x = " << findmin(z) << "\n";
}
