#include <iostream>
#include "lectures/week1/factorial_lib.h"

int main() {
  std::cout << "Enter a number: ";
  int n;
  std::cin >> n;
  std::cout << factorial(n) << '\n';
}
