#include "rational.h"
#include "gcd.h"

Rational::Rational(int numerator, int denominator)
{
  if (numerator == 0)
    denominator = 1;
  int gcd = GCD::gcd(std::abs(numerator), std::abs(denominator));
  if (numerator < 0 && denominator < 0)
  {
    numerator_ = -numerator / gcd;
    denominator_ = -denominator / gcd;
  }
  else if (numerator < 0 || denominator < 0)
  {
    numerator_ = numerator < 0 ? numerator / gcd : -numerator / gcd;
    denominator_ = denominator < 0 ? -denominator / gcd : denominator / gcd;
  }
  else
  {
    numerator_ = numerator / gcd;
    denominator_ = denominator / gcd;
  }
}
Rational::operator double() const
{
  return (double)numerator_ / denominator_;
}
Rational& Rational::operator++()
{
  numerator_ += denominator_;
  return *this;
}
Rational& Rational::operator--()
{
  numerator_ -= denominator_;
  return *this;
}
Rational Rational::operator++(int)
{
  Rational tmp(*this);
  ++*this;
  return tmp;
}
Rational Rational::operator--(int)
{
  Rational tmp(*this);
  --*this;
  return tmp;
};

std::ostream& operator<<(std::ostream& out, const Rational& a)
{
  out << a.numerator_ << "/" << a.denominator_;
  return out;
}

Rational operator+(const Rational& a, const Rational& b)
{
  int gcd = GCD::gcd(a.denominator_, b.denominator_);
  return Rational(a.numerator_ * (b.denominator_ / gcd) + b.numerator_ * (a.denominator_ / gcd),
                  a.denominator_ * (b.denominator_ / gcd));
}
Rational operator-(const Rational& a, const Rational& b)
{
  int gcd = GCD::gcd(a.denominator_, b.denominator_);
  return Rational(a.numerator_ * (b.denominator_ / gcd) - b.numerator_ * (a.denominator_ / gcd),
                  a.denominator_ * (b.denominator_ / gcd));
}
Rational operator*(const Rational& a, const Rational& b)
{
  int gcd1 = GCD::gcd(a.numerator_, b.denominator_);
  int gcd2 = GCD::gcd(b.numerator_, a.denominator_);
  return Rational((a.numerator_ / gcd1) * (b.numerator_ / gcd2), (a.denominator_ / gcd2) * (b.denominator_ / gcd1));
}
Rational operator/(const Rational& a, const Rational& b)
{
  int gcd1 = GCD::gcd(a.numerator_, b.numerator_);
  int gcd2 = GCD::gcd(b.denominator_, a.denominator_);
  return Rational((a.numerator_ / gcd1) * (b.denominator_ / gcd2), (a.denominator_ / gcd2) * (b.numerator_ / gcd1));
}
