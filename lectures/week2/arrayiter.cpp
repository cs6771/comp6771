#include <array>
#include <iostream>

int main() {
  // C-style. Don't do this
  // int ages[3] = { 18, 19, 20 };
  // for (int i = 0; i < 3; ++i) {
  //   std::cout << ages[i] << "\n";
  // }

  // C++ style. This can be used like any other C++ container.
  // It has iterators, safe accesses, and it doesn't act like a pointer.
  std::array<int, 3> ages{ 18, 19, 20 };

  for (int i = 0; i < ages.size(); ++i) {
    std::cout << ages[i] << "\n";
  }
  for (auto it = ages.begin(); it != ages.end(); ++it) {
    std::cout << *it << "\n";
  }
  for (const auto& age : ages) {
    std::cout << age << "\n";
  }
}
