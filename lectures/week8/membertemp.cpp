#include <vector>

template <typename T>
class Stack {
 public:
  Stack() {}
  template <typename T2>
  Stack(Stack<T2>&);
  void push(T t) { stack_.push_back(t); }
  T pop();
  bool empty() const { return stack_.empty(); }

 private:
  std::vector<T> stack_;
};

template <typename T>
T Stack<T>::pop() {
  T t = stack_.back();
  stack_.pop_back();
  return t;
}

template <typename T>
template <typename T2>
Stack<T>::Stack(Stack<T2>& s) {
  while (!s.empty()) {
    stack_.push_back(static_cast<T>(s.pop()));
  }
}

int main() {
  Stack<int> is1;
  is1.push(2);
  is1.push(3);
  Stack<int> is2{is1};     // this works
  Stack<double> ds1{is1};  // this does not
}
