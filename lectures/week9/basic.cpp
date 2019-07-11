#include <iostream>
#include <string>
#include <functional>

#include "lectures/week9/animal.h"
#include "lectures/week9/cat.h"
#include "lectures/week9/dog.h"

void DoThings(Animal animal) {
  std::cout << "animal has size " << sizeof(animal) << '\n';
  animal.PrintDetails(" is doing things");
}

int main() {
  // TODO(lecture): Does it make sense to be able to create animals on their own?
  // Fix after explaining the following two sections.
  Animal animal{5};
  Cat cat{"kitty", 9};
  Dog dog{"doggo", 10};
  std::cout << '\n';

  // TODO(lecture): What do we expect the answers here are when we uncomment this?
//  std::cout << "animal: size = " << sizeof(animal) << ", ptr = " << sizeof(&animal) << ", ref = "
//            << sizeof(std::ref(animal)) << '\n';
//  std::cout << "kitty: size = " << sizeof(cat) << ", ptr = " << sizeof(&cat) << ", ref = "
//            << sizeof(std::ref(cat)) << '\n';
//  std::cout << "doggo: size = " << sizeof(dog) << ", ptr = " << sizeof(&dog) << ", ref = "
//            << sizeof(std::ref(dog)) << '\n';
//  std::cout << '\n';
//
//  std::cout << "kitty age = " << cat.GetAge() << '\n';
//  std::cout << "doggo age = " << dog.GetAge() << '\n';
//  std::cout << '\n';

  // TODO(lecture): What do we expect to happen when we uncomment this?
//  DoThings(animal);
//  DoThings(cat);
//  DoThings(dog);
  std::cout << '\n';
}
