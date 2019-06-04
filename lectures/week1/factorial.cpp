#include "lectures/week1/factorial.h"

int Factorial(int number) {
  return number <= 1 ? 1 : Factorial(number - 1) * number;
}
