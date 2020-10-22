#include "rational.h"
#include <cmath>

int Rational::NOD(int n, int d)
{
  n = abs(n);
  d = abs(d);
  while (n != d)
  {
    if (n > d)
    {
      n -= d;
    }
    else
      d -= n;
  }
  return n;
}

Rational::Rational(int n, int d)
{
  if (n == 0)
  {
    numerator_ = 0;
    denominator_ = 1;
  }
  else
  {
    if (n % d == 0)
    {
      n = n / d;
      d = 1;
    }
    else
    {
      int k = NOD(n, d);
      n /= k;
      d /= k;
    }
    if (n < 0 && d < 0)
    {
      n *= -1;
      d *= -1;
    }
    numerator_ = n;
    denominator_ = d;
  }
};
Rational::operator double() const
{
  return double(this->numerator_) / this->denominator_;
}

Rational Rational::operator++()
{
  this->numerator_ += this->denominator_;
  return *this;
}
Rational Rational::operator--()
{
  this->numerator_ -= this->denominator_;
  return *this;
}
Rational Rational::operator++(int)
{
  Rational tmp(*this);
  --(*this);
  return tmp;
}

Rational Rational::operator--(int)
{
  Rational tmp(*this);
  --(*this);
  return tmp;
};

Rational Rational::operator+(const Rational& s)
{
  return Rational(this->numerator_ * s.denominator_ + this->denominator_ * s.numerator_,
                  this->denominator_ * s.denominator_);
}
Rational Rational::operator-(Rational s)
{
  return Rational(this->numerator_ * s.denominator_ - this->denominator_ * s.numerator_,
                  this->denominator_ * s.denominator_);
}
Rational Rational::operator*(Rational s)
{
  return Rational(this->numerator_ * s.numerator_, this->denominator_ * s.denominator_);
}
Rational Rational::operator/(Rational s)
{
  return Rational(this->numerator_ * s.denominator_, this->denominator_ * s.numerator_);
}
bool Rational::operator>(Rational const& s)
{
  return (this->numerator_ * s.denominator_ > s.numerator_ * this->denominator_);
}

bool Rational::operator<(Rational const& s)
{
  //не совсем понимаю почему нельзя (this>s) использовать
  return (this->numerator_ * s.denominator_ < s.numerator_ * this->denominator_);
}
bool Rational::operator==(Rational const& s)
{
  return (this->numerator_ * s.denominator_ == s.numerator_ * this->denominator_);
}
bool Rational::operator!=(Rational const& s)
{
  return (this->numerator_ * s.denominator_ != s.numerator_ * this->denominator_);
}
bool Rational::operator>=(Rational const& s)
{
  return (this->numerator_ * s.denominator_ >= s.numerator_ * this->denominator_);
}
bool Rational::operator<=(Rational const& s)
{
  return (this->numerator_ * s.denominator_ <= s.numerator_ * this->denominator_);
}

std::ostream& operator<<(std::ostream& out, const Rational& f)
{
  out << f.numerator_ << "/" << f.denominator_;
  return out;
};
