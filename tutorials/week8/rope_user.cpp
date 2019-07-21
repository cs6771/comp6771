#include <iostream>

#include "tutorials/week8/rope.h"

int main() {
  Rope rope{{"hello", " ", "world"}};

  for (char letter : rope) {
    std::cout << letter << '\n';
  }
}
