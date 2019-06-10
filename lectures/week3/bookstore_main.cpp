#include <iostream>

#include "lectures/week3/bookstore.h"

int main() {
  BookSale cur_book;
  if (read(std::cin, cur_book)) {
    BookSale new_book;
    while (read(std::cin, new_book)) {
      if (cur_book.getBookName() == new_book.getBookName()) {
        cur_book.combine(new_book);
      } else {
        print(std::cout, cur_book) << '\n';
        cur_book = new_book;
      }
    }
    print(std::cout, cur_book) << '\n';
  } else {
    std::cerr << "No data?!\n";
  }
}
