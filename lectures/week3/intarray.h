#ifndef LECTURES_WEEK3_INTARRAY_H
#define LECTURES_WEEK3_INTARRAY_H

#include <cassert>

// A std::vector style type that can't be resized.
class IntArray {
 public:
  IntArray(int size);
  IntArray(const IntArray&) = default;
  IntArray& operator=(const IntArray&) = default;
  IntArray(IntArray&&) = default;
  IntArray& operator=(IntArray&&) = default;
  ~IntArray() noexcept;

  int& At(int i);
  int size() const;

 private:
  // Don't do this at home.
  // We use in int pointer as an array (which is C style).
  // This is to show you how a shitty std::vector might
  // be implemented under the hood.
  int* values_;
  int size_;
};

#endif  // LECTURES_WEEK3_INTARRAY_H
