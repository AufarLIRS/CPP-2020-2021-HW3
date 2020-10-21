#include <iostream>
#include <algorithm>

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

public:
  void Reduce()
  {
    auto a = std::abs(std::__gcd(getDenominator(), getNumerator()));
    numerator_ /= a;
    denominator_ /= a;
  }

public:
  Rational(int x, int y = 1)
  {
    if (y < 0)
    {
      x *= -1;
      y *= -1;
    }

    numerator_ = x;
    denominator_ = y;
    Reduce();
  }

public:
  operator double()
  {
    return (double)this->getNumerator() / this->getDenominator();
  }
  Rational operator+(Rational& x)
  {
    return Rational(this->getNumerator() * x.getDenominator() + x.getNumerator() * this->getDenominator(),
                    this->getDenominator() * x.getDenominator());
  }
  Rational operator-(Rational& x)
  {
    return Rational(this->getNumerator() * x.getDenominator() - x.getNumerator() * this->getDenominator(),
                    this->getDenominator() * x.getDenominator());
  }
  Rational operator*(Rational& x)
  {
    return Rational(this->getNumerator() * x.getNumerator(), this->getDenominator() * x.getDenominator());
  }
  Rational operator/(Rational& x)
  {
    if (this->getDenominator() == 0 || x.getDenominator() == 0 || this->getNumerator() == 0 || x.getNumerator() == 0)
    {
      return Rational(1, 0);
    }
    else
    {
      return Rational(this->getNumerator() * x.getDenominator(), this->getDenominator() * x.getNumerator());
    }
  }
  Rational& operator++()
  {
    this->numerator_ = (this->getNumerator() + this->getDenominator());
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
    this->numerator_ = (this->getNumerator() - this->getDenominator());
    return *this;
  }
  Rational operator--(int)
  {
    Rational tmp(*this);
    --(*this);
    return tmp;
  }
  bool operator>(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() > x.getNumerator() * this->getDenominator());
  }
  bool operator<(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() < x.getNumerator() * this->getDenominator());
  }
  bool operator==(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() == x.getNumerator() * this->getDenominator());
  }
  bool operator!=(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() != x.getNumerator() * this->getDenominator());
  }
  bool operator<=(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() <= x.getNumerator() * this->getDenominator());
  }
  bool operator>=(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() >= x.getNumerator() * this->getDenominator());
  }
};
std::ostream& operator<<(std::ostream& out, const Rational& x)
{
  out << x.getNumerator() << "/" << x.getDenominator();

  return out;
}

int main()
{
  Rational a(2, -4);
  Rational b(6, 3);
  if (a < b)
    std::cout << "a<b" << std::endl;
  int c = 5;
  std::cout << a << std::endl;
  std::cout << a / c << std::endl;
  if (a <= c)
  {
    std::cout << ++a << std::endl;
  }
  double d = 8.2;
  if (a <= d)
  {
    std::cout << a + b << std::endl;
  }

  std::cout << a - b << std::endl;
  std::cout << a * b << std::endl;
  std::cout << a / b << std::endl;
}
