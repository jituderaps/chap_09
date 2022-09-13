#include <iostream>
#include "chrono.h"

namespace chrono {

Date::Date() 
    : day_(1), month_(Month::jan), year_(1970) { }

Date::Date(int day, Month month, int year)
    : day_(day), month_(month), year_(year) {
  if (!IsValid(day, month, year))
    throw Invalid {}; 
}

void Date::add_day(int n) { 
  if (n < 0) 
    return;
  
  switch(month_) {
    case Month::feb: 
      while (n--) {
        if (day_ < TotalDaysInMonth(month_, year_))
          day_ += 1;

        else if  (day_ == TotalDaysInMonth(month_, year_)) {
          day_ = 0;
          add_month(1);
          add_day(n + 1);
          return;
        }
      }
      return;

    case Month::jan:  
    case Month::mar:  
    case Month::may:  
    case Month::jul:  
    case Month::aug:  
    case Month::oct:  
    case Month::dec: 
      while (n--) {
        if (day_ < TotalDaysInMonth(month_, year_))
          day_ += 1;

        else if  (day_ == TotalDaysInMonth(month_, year_)) {
          if (month_ == Month::dec)
            add_year(1);
          
          day_ = 0;
          add_month(1);
          add_day(n + 1);
          return;
        }
      }
      return;

    default : 
      while (n--) {
        if (day_ < TotalDaysInMonth(month_, year_))
          day_ += 1;

        else if (day_ == TotalDaysInMonth(month_, year_)) {
          day_ = 0;
          add_month(1);
          add_day(n + 1);
          return;
        }
      }
  }
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
  else if (year < 1970)
    answer = false;
  
  switch (month) {
    case Month::feb:
      days_in_month = 28;
      
      if (LeapYear(year))
        days_in_month = 29;
      
      if (day > days_in_month) 
        answer = false;
      break;

    case Month::apr:  
    case Month::jun:  
    case Month::sep:  
    case Month::nov:  
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

int TotalDaysInMonth(const Month& m, const int y) {
  switch(m) {
    case Month::feb:
      if (LeapYear(y))
        return 29;
      else 
        return 28;
      
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
      return 30;
      
    default:
      return 31;
  }
}

bool LeapYear(int year) {
  if ( ( !(year % 4) && (year % 100) ) || !(year % 400) )
    return true;

  return false;
}

Day DayOfWeek(const Date& dd) {
  int d = dd.day();
  int m = dd.month();
  int y = dd.year();
  
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  
  y -= m < 3;

  return Day( (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7);
}

Date NextWorkDay(Date dd) {
  do {
    dd.add_day(1);
  } 
  while (DayOfWeek(dd) == Day::sunday || DayOfWeek(dd) == Day::saturday); 

  return dd;
} 

int WeekOfYear(const Date& kdd) {
  Date starting_date = {1, Month::jan, kdd.year()};
  
  int week = 0;
  while (starting_date < kdd) {
    if (DayOfWeek(starting_date) == Day::sunday)
      ++week;
    starting_date.add_day(1);
  }

  return week;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
  return os << '(' << d.day() 
            << ',' << d.month() 
            << ',' << d.year() << ')'; 
}

bool operator<(const Date& a, const Date& b) {
  if (a.year() < b.year() || a.month() < b.month() || a.day() < b.day())
    return true;
  
  return false;
}

} // chrono

