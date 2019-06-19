#include <iostream>
#include <vector>

int main() {
  std::vector<int> ages;
  ages.push_back(18);
  ages.push_back(19);
  ages.push_back(20);

  // type of iter would be std::vector<int>::iterator
  for (auto iter = ages.begin(); iter != ages.end(); ++iter) {
    (*iter)++;  // OK
  }

  // type of iter would be std::vector<int>::const_iterator
  for (auto iter = ages.cbegin(); iter != ages.cend(); ++iter) {
    // (*iter)++;  // NOT OK
  }

  // type of iter would be std::vector<int>::const_iterator
  for (auto iter = ages.rbegin(); iter != ages.rend(); ++iter) {
    std::cout << *iter << "\n";  // prints 20, 19, 18
  }

  // Can also use crstart and crend
}
