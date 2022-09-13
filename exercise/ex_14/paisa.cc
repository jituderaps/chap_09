#include <iostream>
#include "paisa.h"

namespace paisa {

std::vector<std::string> currency_string = {"USD", "EUR", "INR"};

std::ostream& operator<<(std::ostream& os, const Currency& curr) {
  return os << currency_string[int(curr)];
}

Money::Money(double amount) 
    : cent_(amount * 100), currency_(Currency::usd) {
  RoundUpDown();   
}

Money::Money(Currency curr, double amount)
    : cent_(amount * 100), currency_(curr) { 
  RoundUpDown();
}

void Money::RoundUpDown() {
  int last_digit_cent = cent_ % 100;
  double after_decimal = last_digit_cent / 100.0;

  if (after_decimal >= 0.5) {
    cent_ /= 100;
    ++cent_;
    cent_ *= 100;
  }
  else {
    cent_ /= 100;
    cent_ *= 100;
  }
}

Money CurrencyExchange(const Money& money) {
  switch(money.get_currency()) {
    case Currency::usd:
      return {Currency::usd, (money.get_cent() / 100.0) * 1};

    case Currency::eur:
      return {Currency::usd, (money.get_cent() / 100.0) * 1.11};

    case Currency::inr:
      return {Currency::usd, (money.get_cent() / 100.0) * 0.013};

    default:
      std::cerr << "this currency is not available to us" << '\n';
  }

  return money;
}

Money operator+(const Money& a, const Money& b) {
  return (CurrencyExchange(a).get_cent() + CurrencyExchange(b).get_cent()) / 100;
}

std::istream& operator>>(std::istream& is, Money& amount) {
  char ch1, ch2, ch3;
  double d;
  std::string curr;

  is >> ch1 >> ch2 >> ch3 >> d;

  curr = (curr + ch1) + ch2 + ch3;

  if (curr == "usd" || curr == "USD")
    amount = {Currency::usd, d};
 
  else if (curr == "eur" || curr == "EUR")
    amount = {Currency::eur, d}; 
 
  else if (curr == "inr" || curr == "INR")
    amount = {Currency::inr, d};

  return is;
}

std::ostream& operator<<(std::ostream& os, const Money& amount) {
  return os << amount.get_currency() << ' ' << double(amount.get_cent()) / 100;
}

} // namespace paisa


