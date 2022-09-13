#include <ostream>
#include "chrono.h"

namespace chrono {

Date::Date() 
    : day_(15), month_(Month::jan), year_(1990) { }

Date::Date(int day, Month month, int year)
    : day_(day), month_(month), year_(year) {
  if (!IsValid(day, month, year))
    throw Invalid {}; 
}

inline void Date::add_day(int n) { 
  day_ += n; 
}

void Date::add_month(int n) { 
  month_ = (month_ == Month::dec) ? Month::jan : Month(int(month_) + n); 
}

inline void Date::add_year(int n) { 
  year_ += n; 
}

bool IsValid(int day, Month month, int year) {
  bool answer = true;
  int days_in_month = 31;

  if (day <= 0) 
    answer = false;
  else if (month < Month::jan || month > Month::dec) 
    answer = false;
  
  switch (month) {
    case Month::feb:
      days_in_month = 28;
      if (day > days_in_month) 
        answer = false;
      break;

    case Month::apr:  
    case Month::jun:  
    case Month::aug:  
    case Month::oct:  
    case Month::dec:
      days_in_month = 30;
      if (day > days_in_month) 
        answer = false;
      break;

    default:
      if (day > days_in_month) 
        answer = false;
  }
  
  return answer;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
  return os << '(' << d.day() 
            << ',' << d.month() 
            << ',' << d.year() << ')'; 
}

} // chrono

