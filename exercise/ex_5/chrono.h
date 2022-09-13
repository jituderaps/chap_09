namespace chrono {

enum class Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec
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
std::ostream& operator<<(std::ostream& os, const Date& d);

} // chrono

