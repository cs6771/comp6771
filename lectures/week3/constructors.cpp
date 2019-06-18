#include <iostream>

// A std::vector style type that can't be resized.
class IntArray {
 public:
  int& At(int i) { return values_[i]; }

 private:
  // Don't do this at home.
  // We use in int pointer as an array (which is C style).
  // This is to show you how a shitty std::vector might
  // be implemented under the hood.
  int* values_;
};

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

  // How do we initialise it to have a specific length?
  //  IntArray intArray;
  //  intArray.values_ = new int[5];
  //  intArray.values_[0]++;
  //  std::cout << intArray.At(0) << '\n';
  //  intArray.At(0)++;
  //  std::cout << intArray.At(0) << '\n';

  //  {
  //    const auto& constIntArray{intArray};
  //    std::cout << constIntArray.At(0) << '\n';
  //  }
}
