#include <iostream>
#include <vector>

class Stack {
 public:
  // Stack() = default;
  // Why won't this work if we uncomment the line below?
  // Stack(int i) { stack_.push_back(i); }
  void push(int& i) { stack_.push_back(i); }
  void pop();
  int& top();
  const int& top() const;

 private:
  std::vector<int> stack_;
};

int main() {
  Stack s;
  int i = 3;
  s.push(i);
}

