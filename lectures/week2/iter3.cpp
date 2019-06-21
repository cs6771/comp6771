#include <fstream>
#include <iostream>
#include <iterator>

int main() {
  std::ifstream in("data.in");

  std::istream_iterator<int>begin(in);
  std::istream_iterator<int> end;
  std::cout << *begin++ << "\n";  // read the first int

  ++begin;  // skip the 2nd int
  std::cout << *begin++ << "\n";  // read the third int
  while (begin != end) {
    std::cout << *begin++ << "\n";  // read and print the rest
  }
}
