#include <iostream>
#include <vector>

template <typename T, typename CONT = std::vector<T>>
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
  CONT stack_;
};

template <typename T, typename CONT>
int Stack<T, CONT>::numStacks_ = 0;

template <typename T, typename CONT>
Stack<T, CONT>::Stack() { numStacks_++; }

template <typename T, typename CONT>
Stack<T, CONT>:: ~Stack() { numStacks_--; }

int main() {
  Stack<float> fs;
  Stack<int> is1, is2, is3;
  std::cout << Stack<float>::numStacks_ << "\n";
  std::cout << Stack<int>::numStacks_ << "\n";
}