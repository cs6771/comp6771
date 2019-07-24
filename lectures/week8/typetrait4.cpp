#include <iostream>
#include <limits>

template <typename T>
struct is_pointer {
  static const bool val = false;
};

template <typename T>
struct is_pointer<T*> {
  static const bool val = true;
};

int main() {
  std::cout << is_pointer<int*>::val << "\n";
  std::cout << is_pointer<int>::val << "\n";
}
