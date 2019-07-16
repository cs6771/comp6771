#include "lectures/week6/stack.h"

#include <iostream>
#include <string>

int main() {
  Stack<int> s1;  // int: template argument
  s1.push(1);
  s1.push(2);
  Stack<int> s2 = s1;
  std::cout << s1 << s2 << '\n';
  s1.pop();
  s1.push(3);
  std::cout << s1 << s2 << '\n';
  // s1.push("hello"); // Fails to compile.

  Stack<std::string> string_stack;
  string_stack.push("hello");
  // string_stack.push(1); // Fails to compile.
}
