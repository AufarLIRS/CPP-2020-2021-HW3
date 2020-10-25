#include <iostream>
#include <numeric>
struct Rational
{
private:
  int numerator_;
  int denominator_;

public:
  int getNumerator() const
  {
    return numerator_;
  }

  int getDenominator() const
  {
    return denominator_;
  }
  void Simplify()
  {
    auto a = std::gcd(getDenominator(), getNumerator());
    numerator_ /= a;
    denominator_ /= a;
  }

  Rational(int n, int m)
  {
    if (m < 0)
    {
      n *= -1;
      m *= -1;
    }

    numerator_ = n;
    denominator_ = m;
    Simplify();
  }
  Rational(int n)
  {
    numerator_ = n;
    denominator_ = 1;
  }

  operator double()
  {
    return (double)this->numerator_ / (double)this->denominator_;
  }

  Rational operator+(Rational const& b)
  {
    return Rational(this->numerator_ * b.denominator_ + b.numerator_ * this->denominator_,
                    this->denominator_ * b.denominator_);
  }

  Rational operator-(Rational const& b)
  {
    return Rational(this->numerator_ * b.denominator_ - b.numerator_ * this->denominator_,
                    this->denominator_ * b.denominator_);
  }

  Rational operator*(Rational& b)
  {
    return Rational(this->numerator_ * b.numerator_, this->denominator_ * b.denominator_);
  }

  Rational operator/(Rational const& b)
  {
    if (this->denominator_ == 0 || b.denominator_ == 0 || this->numerator_ == 0 || b.numerator_ == 0)
    {
      return Rational(1, 0);
    }
    else
    {
      return Rational(this->numerator_ * b.denominator_, this->denominator_ * b.numerator_);
    }
  }

  Rational& operator++()
  {
    this->numerator_ += this->denominator_;
    return *this;
  }

  Rational operator++(int)
  {
    Rational tmp(*this);
    ++(*this);
    return tmp;
  }

  Rational& operator--()
  {
    this->numerator_ += this->denominator_;
    return *this;
  }

  Rational operator--(int)
  {
    Rational tmp(*this);
    --(*this);
    return tmp;
  }

  bool operator>(Rational const& b)
  {
    if (this->getNumerator() * b.getDenominator() > b.getNumerator() * this->getDenominator())
      return true;
    else
      return false;
  }
  bool operator>=(Rational const& b)
  {
    if (this->getNumerator() * b.getDenominator() >= b.getNumerator() * this->getDenominator())
      return true;
    else
      return false;
  }
  bool operator==(Rational const& b)
  {
    if (this->getNumerator() * b.getDenominator() == b.getNumerator() * this->getDenominator())
      return true;
    else
      return false;
  }
  bool operator<=(Rational const& b)
  {
    if (this->getNumerator() * b.getDenominator() <= b.getNumerator() * this->getDenominator())
      return true;
    else
      return false;
  }
  bool operator<(Rational& b)
  {
    if (this->getNumerator() * b.getDenominator() < b.getNumerator() * this->getDenominator())
      return true;
    else
      return false;
  }
  bool operator!=(Rational const& b)
  {
    if (this->getNumerator() * b.getDenominator() != b.getNumerator() * this->getDenominator())
      return true;
    else
      return false;
  }
};
std::ostream& operator<<(std::ostream& out, const Rational& b)
{
  out << b.getNumerator() << "/" << b.getDenominator();

  return out;
}

int main()
{
  Rational a = Rational(1, 2);
  Rational b = Rational(2, 3);
  int c1 = 3;
  double c2 = 4.2;
  std::cout << a << std::endl;
  std::cout << a + b << std::endl;
  std::cout << a - b << std::endl;
  std::cout << a * b << std::endl;
  std::cout << a / b << std::endl;
  std::cout << a * c1 << std::endl;
  std::cout << a * c2 << std::endl;
  if (a < 4.2)
    std::cout << "sucess!" << std::endl;
  if (b > a)
    std::cout << "sucess!" << std::endl;
  if (b != a)
    std::cout << "sucess!" << std::endl;
}
