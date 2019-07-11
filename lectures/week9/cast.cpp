#include <iostream>
#include <string>
#include <functional>

#include "lectures/week9/animal.h"
#include "lectures/week9/cat.h"
#include "lectures/week9/dog.h"

int main() {
  Animal animal{5};
  Cat cat{"kitty", 9};
  Dog dog{"doggo", 10};

  // Up-casting is always safe (derived to base).
  [[maybe_unused]] Animal& animal_cat{cat};
  [[maybe_unused]] Animal& animal_dog{dog};

  // Casting works the same with references and pointers.
  [[maybe_unused]] Animal* animal_cat_ptr{&cat};
  [[maybe_unused]] Animal* animal_dog_ptr{&dog};

  // The compiler won't allow you to down cast.
  // Down-casting may make sense.
//  Cat& recast_cat{animal_cat};
  // But it may not.
//  Cat& recast_dog{animal_dog};
}
