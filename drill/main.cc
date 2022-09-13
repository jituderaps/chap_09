#include <iostream>
#include "chrono.h"

int main() {
  try {
    chrono::Date today1 = {8, chrono::Month::jan, 1969}; 
    
    int week = WeekOfYear(today1);
    std::cout << "today is " << week << "th week of the year" << '\n';
  } 
  catch(chrono::Date::Invalid) {
    std::cerr << "Exception: invalid date\n";
  }
}


