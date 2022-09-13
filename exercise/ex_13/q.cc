#include <iostream>
#include "q.h"

namespace q {

Rational::Rational(double a, double b)
    : numerator_(a), denominator_(b) { 
  if (b == 0)
    throw InvalidRational {};
}

void Rational::set_numerator(double d) {
  numerator_ = d;
}

void Rational::set_denominator(double d) {
  denominator_ = d;
}

double Rational::RationalToDouble() {
  return numerator_ / denominator_;
}

double RationalToDouble(const Rational& r) {
  return r.Rational::get_numerator() / r.get_denominator();
}

std::ostream& operator<<(std::ostream& os, const Rational& r){
  return os << r.get_numerator() << "/" << r.get_denominator();
}

Rational operator+(const Rational& a, const Rational& b) {
  return Rational(a.get_numerator() * b.get_denominator() + b.get_numerator() * a.get_denominator(), 
          a.get_denominator() * b.get_denominator());
}

Rational operator-(const Rational& a, const Rational& b) {
  return Rational(a.get_numerator() * b.get_denominator() - b.get_numerator() * a.get_denominator(), 
          a.get_denominator() * b.get_denominator());
}

Rational operator*(const Rational& a, const Rational& b) {
  return {a.get_numerator() * b.get_numerator(),
         a.get_denominator() * b.get_denominator()};
}

Rational operator/(const Rational& a, const Rational& b) {
  return {a.get_numerator() * b.get_denominator(),
         a.get_denominator() * b.get_numerator()};
}

} // namespace q



