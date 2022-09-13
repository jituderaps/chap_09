#include <iostream>
#include "q.h"

int main() {
  try {
    q::Rational a = {2, 0};
    q::Rational b = {4, 3};

    std::cout << "hi" << '\n';
    q::Rational result = a * b;

    double d = result.q::Rational::RationalToDouble();

    std::cout << d << '\n';
  }
  catch (...) {
    std::cout << "Exeption : now you kill it" << '\n';
  }

  return 0;
}
