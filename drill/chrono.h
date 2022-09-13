namespace chrono {

enum class Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day {
  sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

class Date {
  public:
    class Invalid { };

    Date();
    Date(int day, Month month, int year);

    int day()   const { return day_;        }
    int month() const { return int(month_); }
    int year()  const { return year_;       } 

    void add_day(int);
    void add_month(int);
    void add_year(int);

  private:
    int day_;
    Month month_;
    int year_;
};

// helper function
bool IsValid(int, Month, int);
int  TotalDaysInMonth(const Month&, const int);
bool LeapYear(int);
Day  DayOfWeek(const Date&);
Date NextWorkDay(Date);
int  WeekOfYear(const Date&);

std::ostream& operator<<(std::ostream& os, const Date& d);
bool          operator<(const Date&, const Date&);
} // chrono

