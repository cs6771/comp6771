#include "lectures/week6/iwyu.h"

#include <fstream>
#include <iostream>
#include <string>

void PrintFile(const std::string& filename) {
  std::ifstream file{filename};
  std::string s;
  file >> s;
  std::cout << s << '\n';
}

int main() {
  // PrintFile here
}
