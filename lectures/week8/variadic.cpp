#include <iostream>
#include <typeinfo>

template <typename T>
void print(const T& msg) {
  std::cout << msg << " ";
}

template <typename A, typename... B>
void print(A head, B... tail) {
  print(head);
  print(tail...);
}

int main() {
  print(1, 2.0f);
  std::cout << std::endl;
  print(1, 2.0f, "Hello");
  std::cout << std::endl;
}
