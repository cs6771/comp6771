#include "lectures/week1/factorial.h"

int factorial(int number) {
  return number <= 1 ? 1 : factorial(number - 1) * number;
}
