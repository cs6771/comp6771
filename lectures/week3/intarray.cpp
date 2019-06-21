#include "lectures/week3/intarray.h"

IntArray::IntArray(int size) : values_{new int[size]}, size_{size} {
  for (auto i = 0; i < size; ++i) {
    values_[i] = 0;
  }
}

IntArray::~IntArray() noexcept {
  delete[] values_;
}

int& IntArray::At(int i) {
  return values_[i];
}
int IntArray::size() const {
  // size_ is shorthand for this->size_.
  return size_;
}

