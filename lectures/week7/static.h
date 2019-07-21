#ifndef LECTURES_WEEK7_STATIC_H_
#define LECTURES_WEEK7_STATIC_H_

#include <vector>

template <typename T>
class Stack {
 public:
  Stack();
  ~Stack();
  void push(T&);
  void pop();
  T& top();
  const T& top() const;
  static int numStacks_;
 private:
  std::vector<T> stack_;
};

template <typename T>
int Stack<T>::numStacks_ = 0;

template <typename T>
Stack<T>::Stack() { numStacks_++; }

template <typename T>
Stack<T>:: ~Stack() { numStacks_--; }

#endif  // LECTURES_WEEK7_STATIC_H_
