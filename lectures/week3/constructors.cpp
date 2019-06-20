#include <iostream>

void Uninitialised() {
  [[maybe_unused]] int* n;
  // Try uncommenting the 4 lines below after removing Werror from bazelrc.
  //  if (n != nullptr) {
  //    std::cout << "uninitialised n is not null (" << n << ")\n";
  //  } else {
  //    std::cout << "uninitialised n is null\n";
  //  }
}

void InitialisedNull() {
  int* n{};
  std::cout << "initialised null n = " << n << '\n';
}

void InitialisedNonNull() {
  // Why can't we use static cast?
  // Why is reinterpret_cast dangerous?
  int* n{reinterpret_cast<int*>(0xDEADBEEF)};
  std::cout << "initialised non-null n = " << n << '\n';
}

int main() {
  // What will this print out (assume no optimisations by the compiler).
  // Note that we can only guess.
  Uninitialised();
  InitialisedNull();
  Uninitialised();
  InitialisedNonNull();
  Uninitialised();
}
