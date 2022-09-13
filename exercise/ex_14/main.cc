#include <iostream>
#include "paisa.h"

int main() {
  paisa::Money x;
  paisa::Money y;
  paisa::Money z;

  std::cout << "please enter curreny..eg. usd 34.3, inr 23.5, eur 23.5" << '\n';
  std::cin >> x >> y >> z;

  std::cout << "the sum of above amount in USD is : ";
  std::cout << x + y + z << '\n';
}
