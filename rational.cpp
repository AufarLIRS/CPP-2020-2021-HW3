#include "rational.h"
#include <numeric>

int Rational::getNumerator() const
{
  return numerator_;
}

int Rational::getDenominator() const
{
  return denominator_;
}

void Rational::Reduce()
{
  auto a = std::gcd(getNumerator(), getDenominator());
  numerator_ /= a;
  denominator_ /= a;
}
bool Rational::IsNan(Rational const& x)
{
  return (x.getDenominator() == 0);
}
Rational::Rational(int x, int y)
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
Rational::operator double() const
{
  return (double)this->getNumerator() / this->getDenominator();
}
Rational operator+(Rational const& x, Rational const& y)
{
  return Rational(x.getNumerator() * y.getDenominator() + y.getNumerator() * x.getDenominator(),
                  x.getDenominator() * y.getDenominator());
}
Rational operator-(Rational const& x, Rational const& y)
{
  return Rational(x.getNumerator() * y.getDenominator() - y.getNumerator() * x.getDenominator(),
                  x.getDenominator() * y.getDenominator());
}
Rational operator*(Rational const& x, Rational const& y)
{
  return Rational(x.getNumerator() * y.getNumerator(), x.getDenominator() * y.getDenominator());
}
Rational operator/(Rational const& x, Rational const& y)
{
  return Rational(x.getNumerator() * y.getDenominator(), x.getDenominator() * y.getNumerator());
}
Rational& Rational::operator++()
{
  this->numerator_ = (this->getNumerator() + this->getDenominator());
  return *this;
}
Rational Rational::operator++(int)
{
  Rational tmp(*this);
  ++(*this);
  return tmp;
}
Rational& Rational::operator--()
{
  this->numerator_ = (this->getNumerator() - this->getDenominator());
  return *this;
}
Rational Rational::operator--(int)
{
  Rational tmp(*this);
  --(*this);
  return tmp;
}
bool Rational::operator>(Rational const& x)
{
  return (this->getNumerator() * x.getDenominator() > x.getNumerator() * this->getDenominator());
}
bool Rational::operator<(Rational const& x)
{
  return (this->getNumerator() * x.getDenominator() < x.getNumerator() * this->getDenominator());
}
bool Rational::operator==(Rational const& x)
{
  return (this->getNumerator() * x.getDenominator() == x.getNumerator() * this->getDenominator());
}
bool Rational::operator!=(Rational const& x)
{
  return (this->getNumerator() * x.getDenominator() != x.getNumerator() * this->getDenominator());
}
bool Rational::operator<=(Rational const& x)
{
  return (this->getNumerator() * x.getDenominator() <= x.getNumerator() * this->getDenominator());
}
bool Rational::operator>=(Rational const& x)
{
  return (this->getNumerator() * x.getDenominator() >= x.getNumerator() * this->getDenominator());
}
std::ostream& operator<<(std::ostream& out, Rational const& x)
{
  out << x.getNumerator() << "/" << x.getDenominator();
  return out;
}
