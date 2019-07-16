template <typename T>
void Stack<T>::push(const T item) {
  stack_.push_back(item);
}

template <typename T>
void Stack<T>::pop() {
  stack_.pop_back();
}

template <typename T>
T& Stack<T>::top() {
  return stack_.back();
}

template <typename T>
const T& Stack<T>::top() const {
  return stack_.back();
}

template <typename T>
bool Stack<T>::empty() const {
  return stack_.empty();
}