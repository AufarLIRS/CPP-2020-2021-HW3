#include "rational.h"
#include "gcd.h"
#include <limits>

Rational::Rational(int numerator, int denominator)
{
  bool minus = 0;
  if (numerator < 0 && denominator < 0)
  {
    numerator = -numerator;
    denominator = -denominator;
  }
  else if (numerator < 0)
  {
    numerator = -numerator;
    minus = 1;
  }
  else if (denominator < 0)
  {
    denominator = -denominator;
    minus = 1;
  }
  if (numerator == denominator)
  {
    numerator = 1;
    denominator = 1;
  }
  else if (numerator == 0)
    denominator = 1;
  int gcd = GCD::gcd(numerator, denominator);
  numerator_ = minus ? -numerator / gcd : numerator / gcd;
  denominator_ = denominator / gcd;
}
Rational::Rational(double d)
{
  int numerator = (int)d > std::numeric_limits<int>::max() ? 0 : (int)d;
  double denominator = 1;
  d -= (int)d;
  d *= 10;
  while ((int)denominator <= std::numeric_limits<int>::max() / 10 &&
         numerator <= std::numeric_limits<int>::max() / 10 - (int)d)
  {
    denominator *= 10;
    numerator = numerator * 10 + (int)d % 10;
    d *= 10;
  }
  *this = Rational(numerator, denominator);
}
Rational::operator double() const
{
  return (double)numerator_ / denominator_;
}
Rational& Rational::operator++()
{
  numerator_++;
  return *this;
}
Rational& Rational::operator--()
{
  numerator_--;
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
double operator+(const Rational& a, double b)
{
  return (double)a + b;
}
double operator+(double a, const Rational& b)
{
  return a + (double)b;
}
Rational operator-(const Rational& a, const Rational& b)
{
  int gcd = GCD::gcd(a.denominator_, b.denominator_);
  return Rational(a.numerator_ * (b.denominator_ / gcd) - b.numerator_ * (a.denominator_ / gcd),
                  a.denominator_ * (b.denominator_ / gcd));
}
double operator-(const Rational& a, double b)
{
  return (double)a - b;
}
double operator-(double a, const Rational& b)
{
  return a - (double)b;
}
Rational operator*(const Rational& a, const Rational& b)
{
  int gcd1 = GCD::gcd(a.numerator_, b.denominator_);
  int gcd2 = GCD::gcd(b.numerator_, a.denominator_);
  return Rational((a.numerator_ / gcd1) * (b.numerator_ / gcd2), (a.denominator_ / gcd2) * (b.denominator_ / gcd1));
}
double operator*(const Rational& a, double b)
{
  return (double)a * b;
}
double operator*(double a, const Rational& b)
{
  return a * (double)b;
}
Rational operator/(const Rational& a, const Rational& b)
{
  int gcd1 = GCD::gcd(a.numerator_, b.numerator_);
  int gcd2 = GCD::gcd(b.denominator_, a.denominator_);
  return Rational((a.numerator_ / gcd1) * (b.denominator_ / gcd2), (a.denominator_ / gcd2) * (b.numerator_ / gcd1));
}
double operator/(const Rational& a, double b)
{
  return (double)a / b;
}
double operator/(double a, const Rational& b)
{
  return a / (double)b;
}
bool operator==(const Rational& a, const Rational& b)
{
  return a.numerator_ == b.numerator_ && a.denominator_ == b.denominator_;
}
bool operator==(const Rational& a, int b)
{
  return a.denominator_ == 1 && a.numerator_ == b;
}
bool operator==(int a, const Rational& b)
{
  return b == a;
}
bool operator!=(const Rational& a, const Rational& b)
{
  return !(a == b);
}
bool operator!=(const Rational& a, int b)
{
  return !(a == b);
}
bool operator!=(int a, const Rational& b)
{
  return !(a == b);
}
bool operator<(const Rational& a, const Rational& b)
{
  int gcd1 = GCD::gcd(a.numerator_, b.numerator_);
  int gcd2 = GCD::gcd(a.denominator_, b.denominator_);
  return (a.numerator_ / gcd1) * (b.denominator_ / gcd2) < (b.numerator_ / gcd1) * (a.denominator_ / gcd2);
}
bool operator<(const Rational& a, int b)
{
  return a.numerator_ < b * a.denominator_;
}
bool operator<(int a, const Rational& b)
{
  return a * b.denominator_ < b.numerator_;
}
bool operator>(const Rational& a, const Rational& b)
{
  return b < a && a != b;
}
bool operator>(const Rational& a, int b)
{
  return a < b && a != b;
}
bool operator>(int a, const Rational& b)
{
  return a < b && a != b;
}
bool operator<=(const Rational& a, const Rational& b)
{
  return a < b && a == b;
}
bool operator<=(const Rational& a, int b)
{
  return a < b && a == b;
}
bool operator<=(int a, const Rational& b)
{
  return a < b && a == b;
}
bool operator>=(const Rational& a, const Rational& b)
{
  return !(a < b);
}
bool operator>=(const Rational& a, int b)
{
  return !(a < b);
}
bool operator>=(int a, const Rational& b)
{
  return !(a < b);
}
