#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::ifstream in{"data.in"};
  std::istream_iterator<int> begin(in);
  std::istream_iterator<int> end;

  std::vector<int> v;
  std::back_insert_iterator<std::vector<int>> iter(v);

  while (begin != end) {
    *iter++ = *begin++;
  }
}
