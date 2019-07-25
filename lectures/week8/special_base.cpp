#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
class Stack {
 public:
  void push(T t) { stack_.push_back(t); }
  T& top() { return stack_.back(); }
  void pop() { stack_.pop_back(); }
  int size() const { return stack_.size(); }
  int sum() { return std::accumulate(stack_.begin(), stack_.end(), 0); }

 private:
  std::vector<T> stack_;
};

int main() {
  int i1 = 6771;
  int i2 = 1917;

  Stack<int*> s1;
  s1.push(&i1);
  s1.push(&i2);
  std::cout << s1.size() << " ";
  std::cout << s1.top() << " ";
  std::cout << s1.sum() << "\n";
}
