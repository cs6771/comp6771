#include "lectures/week8/forwarding/types.h"

#include <iostream>
#include <memory>

// Our second attempt might look like this
template <typename T, typename ArgT>
auto my_make_unique(const ArgT& arg) {
  return std::unique_ptr<T>{new T{arg}};
}

// We then realise that we need this when our non-copyable type fails to compile.
template <typename T, typename ArgT>
auto my_make_unique(ArgT&& arg) {
  return std::unique_ptr<T>{new T{std::forward<ArgT>(arg)}};
}

// What if the function was more complex? We don't want to rewrite every function we write for the copy and the move seperately.

int main() {
  MyClass myClass{"MyClass"};
  std::cout << *my_make_unique<MyClass>(myClass) << "\n";
  std::cout << *my_make_unique<MyClass>(std::move(myClass)) << "\n";
  NonCopyable nonCopyable{"NonCopyable"};
  std::cout << *my_make_unique<NonCopyable>(std::move(nonCopyable)) << "\n\n";
}
