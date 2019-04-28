#include "lectures/week1/factorial_lib.h"

int factorial(int number) {
  return number <= 1 ? 1 : factorial(number-1)*number;
}
