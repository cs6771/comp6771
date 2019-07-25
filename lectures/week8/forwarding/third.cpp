#include "lectures/week8/forwarding/types.h"

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

// This is approximately what std::forward looks like internally.
template <typename T>
T& forward(T& value) {
  return static_cast<T&>(value);
}

template <typename T>
T&& forward(T&& value) {
  return static_cast<T&&>(value);
}

// This way we only need one definition. But what's the problem here?
template <typename T, typename ArgT>
// Note that this needs to be T&& because of reference collapsing.
// If you used const T&, it would be const T& inside the function always.
auto my_make_unique(ArgT&& arg) {
  return std::unique_ptr<T>{new T{std::forward<ArgT>(arg)}};
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
//  std::cout << my_make_unique<std::vector<MyClass>>(6U, myClass)->size() << "\n";
}
