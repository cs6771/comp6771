#include <iostream>
#include <string>

template <typename T>
T myMin(T a, T b) {
  return a < b ? a : b;
}

template <>
const std::string& myMin(const std::string& a,
                       const std::string& b) {
  return a.size() < b.size() ? a : b;
}

int main() {
  std::string s1{"hey"};
  std::string s2{"apple"};
  std::cout << myMin(s1, s2) << "\n";
  std::cout << myMin(4, 3) << "\n";
}
