#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class Reader {
 public:
  explicit Reader(std::shared_ptr<std::string> text) : text_(text), location_{0} {}
  void advance() { ++location_; }
  bool atEnd() const { return location_ == text_->size(); }
  std::weak_ptr<std::string> getText() const { return text_; }
  std::string showLocation() const {
    std::stringstream ret;
    std::string& s = *(text_.get());
    std::copy(s.begin(), s.begin() + location_, std::ostream_iterator<char>(ret));
    ret << "|" << s[location_] << "|";
    std::copy(s.begin() + location_ + 1, s.end(), std::ostream_iterator<char>(ret));
    return ret.str();
  }

 private:
  int location_;
  std::shared_ptr<std::string> text_;
};

int main() {
  std::vector<Reader> readers;
  std::cout << "How many readers? ";
  int n_readers;
  std::cin >> n_readers;
  std::cout << "Creating " << n_readers << " readers\n";
  std::cout << "What are you reading? ";
  {
    std::shared_ptr<std::string> text = std::make_shared<std::string>();
    std::cin >> *text;
    for (int i = 0; i < n_readers; ++i) {
      Reader r = Reader(text);
      readers.push_back(r);
    }
  }

  int index;
  while (true) {
    std::cout << "\033c";
    std::cout << "================== (" << readers.size() << " readers)\n";
    for (auto i = 0; i < readers.size(); ++i) {
      std::cout << i << ": " << readers[i].showLocation() << "\n";
    }
    std::cout << "================== (Reference counts)\n";
    for (int i = 0; i < readers.size(); ++i) {
      std::cout << "Reader " << i << " count: ";
      auto text = readers[i].getText();
      {
        auto t = text.lock();
        if (t) {
          std::cout << t.use_count() - 1 << "\n";
        } else {
          std::cout << "Unknown\n";
        }
      }
    }
    std::cout << "Index to advance: ";
    std::cin >> index;
    readers[index].advance();
    if (readers[index].atEnd()) {
      readers.erase(readers.begin() + index);
    }
  }
}
