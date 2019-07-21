#include <iostream>

#include "tutorials/week8/rope.h"

int main() {
  std::vector<Rope> ropes{
      Rope{{"a"}},
      Rope{{"abc"}},
      Rope{{"abc"}},
      Rope{{"abc", "def"}},
      Rope{{"abc", "", "def"}},
      Rope{{""}},
      Rope{{"", "abc", "def", ""}}
  };

  // TODO(tutorial): make this support const auto& rope, if you have time.
  for (auto& rope : ropes) {
    std::cout << "Rope: \"";
    for (char letter : rope) {
      std::cout << letter;
    }
    std::cout << "\"\n";
  }
}

