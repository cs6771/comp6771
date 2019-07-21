#ifndef LECTURES_WEEK3_INTARRAY_H_
#define LECTURES_WEEK3_INTARRAY_H_

#include <cassert>

// A std::vector style type that can't be resized.
class IntArray {
 public:
  explicit IntArray(int size);
  explicit IntArray(const IntArray&);
  IntArray& operator=(const IntArray&);
  IntArray(IntArray&&) noexcept;
  IntArray& operator=(IntArray&&) noexcept;
  ~IntArray() noexcept;

  int& At(int i);
  const int& At(int i) const;
  int size() const;

 private:
  // Don't do this at home.
  // We use in int pointer as an array (which is C style).
  // This is to show you how a shitty std::vector might
  // be implemented under the hood.
  int* values_;
  int size_;
};

#endif  // LECTURES_WEEK3_INTARRAY_H_
