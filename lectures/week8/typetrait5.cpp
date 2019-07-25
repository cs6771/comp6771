#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
void testIfNumberType(T i) {
  if (std::is_integral<T>::value || std::is_floating_point<T>::value) {
    std::cout << i << " is a number"
              << "\n";
  } else {
    std::cout << i << " is not a number"
              << "\n";
  }
}

int main() {
  int i = 6;
  uint64_t l = 7;
  double d = 3.14;
  testIfNumberType(i);
  testIfNumberType(l);
  testIfNumberType(d);
  testIfNumberType(123);
  testIfNumberType("Hello");
  std::string s = "World";
  testIfNumberType(s);
}
