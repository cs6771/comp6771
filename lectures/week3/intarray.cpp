#include <utility>
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

const int& IntArray::At(int i) const {
  return values_[i];
}

int IntArray::size() const {
  // size_ is shorthand for this->size_.
  return size_;
}
IntArray::IntArray(const IntArray& orig): values_{new int[orig.size_]}, size_{orig.size_} {
  for (int i = 0; i < size_; ++i) {
    values_[i] = orig.values_[i];
  }
}
IntArray::IntArray(IntArray&& orig) noexcept: values_{orig.values_}, size_{orig.size_} {
  orig.values_ = nullptr;
  orig.size_ = 0;
}
IntArray& IntArray::operator=(const IntArray& orig) {
  IntArray tmp{orig};
  std::swap(tmp, *this);
  return *this;
}
IntArray& IntArray::operator=(IntArray&& orig) noexcept {
  delete[] values_;
  values_ = orig.values_;
  size_ = orig.size_;
  orig.values_ = nullptr;
  orig.size_ = 0;
  return *this;
}

