#include <iostream>
#include <vector>

template <typename T, template <typename> class Cont>
class Stack {
 public:
  void push(T& t) { stack_.push_back(t); }
  void pop() { stack_.pop_back(); }
  T& top() { return stack_.back(); }
  bool empty() const { return stack_.empty(); }

 private:
  Cont<T> stack_;
};

int main(void) {
  Stack<int, std::vector> s1;
  int i1 = 1;
  int i2 = 2;
  s1.push(i1);
  s1.push(i2);
  while (!s1.empty()) {
    std::cout << s1.top() << " ";
    s1.pop();
  }
  std::cout << "\n";
}
