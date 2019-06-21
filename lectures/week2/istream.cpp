#include <iostream>
#include <fstream>

int main() {
  int i;
  std::ifstream fin{"data.in"};
  std::ofstream fout{"data.out"};
  while (fin >> i) {
    std::cout << i << "\n";
    fout << (i + 1) << "\n";
  }
  fin.close();
  fout.close();
}
