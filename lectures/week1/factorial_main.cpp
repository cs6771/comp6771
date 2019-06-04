#include <iostream>

#include "lectures/week1/factorial.h"

int main() {
  std::cout << "Enter a number: ";
  int n;
  std::cin >> n;
  std::cout << Factorial(n) << '\n';
}
