#ifndef LECTURES_WEEK9_DOG_H_
#define LECTURES_WEEK9_DOG_H_

#include <iostream>
#include <string>
#include <utility>

#include "lectures/week9/animal.h"

class Dog: public Animal {
 public:
  // This is very similar to delegating constructors. Each subclass constructor must always make
  // sure a constructor is called for the base class subobject.
  Dog(std::string name, int age): Animal{age}, name_{std::move(name)} {
    PrintDetails("Is being born");
  }

  void PrintDetails(const std::string& suffix) {
    std::cout << "Dog " << name_ << " of age " << GetAge() << ' ' << suffix << '\n';
  }

  ~Dog() {
    PrintDetails("is dying");
  }

 private:
  std::string name_;
};

#endif  // LECTURES_WEEK9_DOG_H_
