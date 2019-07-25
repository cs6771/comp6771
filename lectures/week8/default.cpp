#include <iostream>
#include <vector>

template <typename T, typename Cont = std::vector<T>>
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
  Cont stack_;
};

template <typename T, typename Cont>
int Stack<T, Cont>::numStacks_ = 0;

template <typename T, typename Cont>
Stack<T, Cont>::Stack() {
  numStacks_++;
}

template <typename T, typename Cont>
Stack<T, Cont>::~Stack() {
  numStacks_--;
}

int main() {
  Stack<float> fs;
  Stack<int> is1, is2, is3;
  std::cout << Stack<float>::numStacks_ << "\n";
  std::cout << Stack<int>::numStacks_ << "\n";
}
