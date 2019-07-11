#ifndef LECTURES_WEEK9_ANIMAL_H_
#define LECTURES_WEEK9_ANIMAL_H_

#include <iostream>
#include <string>

class Animal {
 public:
  explicit Animal(int age): age_{age} {
    PrintDetails("is being born");
  }

  int GetAge() { return age_; }

  ~Animal() {
    PrintDetails("is dying");
  }

  void PrintDetails(const std::string& suffix) {
    std::cout << "Unknown animal of age " << age_ << ' ' << suffix << '\n';
  }

 private:
  int age_;
};

#endif  // LECTURES_WEEK9_ANIMAL_H_
