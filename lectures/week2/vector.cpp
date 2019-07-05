#include <iostream>
#include <vector>

// Begin with numbers 1, 2, 3 in the list already
int main() {
  // In C++17 we can omit the int if the compiler can determine the type.
  std::vector<int> numbers{1, 2, 3};
  int input;
  while (std::cin >> input) {
    numbers.push_back(input);
  }
  std::cout << "1st element: " << numbers.at(0) << "\n";  // slower, safer
  std::cout << "2nd element: " << numbers[1] << "\n";     // faster, less safe
  std::cout << "Max size before realloc: " << numbers.capacity() << "\n";
  for (int n : numbers) {
    std::cout << n << "\n";
  }
}
