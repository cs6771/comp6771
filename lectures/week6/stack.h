// stack.h
#ifndef LECTURES_WEEK6_STACK_H_
#define LECTURES_WEEK6_STACK_H_

#include <iostream>
#include <vector>

template <typename T>
class Stack {
 public:
  friend std::ostream& operator<<(std::ostream& os, const Stack& s) {
    for (const auto& i : s.stack_)
      os << i << " ";
    return os;
  }
  void push(T);
  void pop();
  T& top();
  const T& top() const;
  bool empty() const;

 private:
  std::vector<T> stack_;
};

// stack.h (continued)

#include "lectures/week6/stack.tpp"

#endif  // LECTURES_WEEK6_STACK_H_
