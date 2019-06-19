#include <iostream>

int main() {
  char a = 'a';
  int *b = static_cast<int *>&a;
  std::cout << *b << "n";
}
