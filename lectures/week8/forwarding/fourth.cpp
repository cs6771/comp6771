#include "lectures/week8/forwarding/types.h"

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

template <typename T, typename... Args>
auto my_make_unique(Args&&... args) {
  return std::unique_ptr<T>{new T{std::forward<Args>(args)...}};
}

int main() {
  MyClass myClass{"MyClass"};
  std::cout << *my_make_unique<MyClass>(myClass) << "\n";
  std::cout << *my_make_unique<MyClass>(std::move(myClass)) << "\n";
  NonCopyable nonCopyable{"NonCopyable"};
  std::cout << *my_make_unique<NonCopyable>(std::move(nonCopyable)) << "\n\n";

  // Use the size constructor.
  std::cout << my_make_unique<std::vector<MyClass>>(5U)->size() << "\n";

  // Use the size-and-value constructor.
  MyClass base{"hello"};
  std::cout << my_make_unique<std::vector<MyClass>>(6U, base)->size() << "\n";
}

