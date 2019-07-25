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

template <typename T>
class Stack<T*> {
 public:
  void push(T* t) { stack_.push_back(t); }
  T* top() { return stack_.back(); }
  void pop() { stack_.pop_back(); }
  int size() const { return stack_.size(); }
  int sum() {
    return std::accumulate(stack_.begin(), stack_.end(), 0,
      [](int a, T* b) { return a + *b; });
  }

 private:
  std::vector<T*> stack_;
};

int main() {
  int i1 = 6771; // 0x800ffeffef
  int i2 = 1917; // 0x800ffeffef
  Stack<int*> s2;
  s2.push(&i1);
  s2.push(&i2);
  std::cout << s2.size() << " ";
  std::cout << *(s2.top()) << " ";
  std::cout << s2.sum() << "\n";
}
