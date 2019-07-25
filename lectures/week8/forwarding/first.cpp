#include "lectures/week8/forwarding/types.h"

#include <iostream>
#include <memory>

template <typename T, typename ArgT>
auto my_make_unique(ArgT arg) {
  return std::unique_ptr<T>{new T{arg}};
}

int main() {
  MyClass myClass{"MyClass"};
  // What do we want to see here? What do we actually see?
  std::cout << *my_make_unique<MyClass>(myClass) << "\n";
  std::cout << *my_make_unique<MyClass>(std::move(myClass)) << "\n";
  // Try adding these lines.
  //  NonCopyable nonCopyable{"NonCopyable"};
  //  std::cout << *my_make_unique<NonCopyable>(std::move(nonCopyable)) << "\n\n";
}
