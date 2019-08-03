#include <iostream>

void print(std::string&& a) {
  std::cout << a << "\n";
}

const std::string goo() {
  return "C++";
}

int main() {
  std::string j = "C++";
  const std::string& k = "C++";
  print("C++");     // rvalue
  print(goo());     // const rvalue
  print(j);         // lvalue
  print(k);         // const lvalue
}