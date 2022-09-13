#include <ostream>

namespace q {

class Rational {
  struct InvalidRational { }; 
  
  public:
    Rational() { }
    Rational(double, double);

    double get_numerator()   const { return numerator_;   }
    double get_denominator() const { return denominator_; }

    void set_numerator(double);
    void set_denominator(double);

    double RationalToDouble();

  private:
    double numerator_;
    double denominator_;
};

std::ostream& operator<<(std::ostream&, const Rational&);

Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

} // namespace q
