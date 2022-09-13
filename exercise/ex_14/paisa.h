#include <vector>
#include <string>
#include <ostream>

namespace paisa {

enum class Currency { usd, eur, inr };

std::ostream& operator<<(std::ostream&, const Currency&);

class Money {
  public:
    Money() { }
    Money(double);
    Money(Currency, double);

    long int get_cent()     const { return cent_;     }
    Currency get_currency() const { return currency_; }
    
    void RoundUpDown();

  private:
    long int cent_;
    Currency currency_;
};

Money CurrencyExchange(const Money&);

Money operator+(const Money&, const Money&);
std::istream& operator>>(std::istream&, Money&);
std::ostream& operator<<(std::ostream&, const Money&);

} // namespace paisa
