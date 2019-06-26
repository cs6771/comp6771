#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<double[]> cactus = std::make_unique<double[]>(2);
  cactus[0] = 1;
  std::cout << cactus[0] << "\n";
}
