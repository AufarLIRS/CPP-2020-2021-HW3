#include <stdio.h>
#include <iostream>
#include "Rational.h"
#include <algorithm>
#include <numeric>

Rational::Rational()
{
  numerator_ = 0;
  denominator_ = 1;
}

Rational::Rational(int numer, int denom)
{
  numerator_ = numer;
  denominator_ = denom;
}
void Rational::simplify()
{
  if (numerator_ < 0)
  {
    denominator_ *= -1;
    numerator_ *= -1;
  }
  int denom = std::gcd(denominator_, numerator_);
  denominator_ /= denom;
  numerator_ /= denom;
}

Rational::Rational(const Rational& rat)
{
  this->numerator_ = rat.numerator_;
  this->denominator_ = rat.denominator_;
}

Rational operator+(Rational left, Rational right)
{
  Rational result(left.getNumerator() * right.getDenominator() + right.getNumerator() * left.getDenominator(),
                  left.getDenominator() * right.getDenominator());
  result.simplify();

  return result;
}

Rational operator-(Rational left, Rational right)
{
  Rational result(left.getNumerator() * right.getDenominator() - right.getNumerator() * left.getDenominator(),
                  left.getDenominator() * right.getDenominator());
  result.simplify();
  return result;
}

Rational operator*(Rational left, Rational right)
{
  Rational result(left.getNumerator() * right.getNumerator(), left.getDenominator() * right.getDenominator());
  result.simplify();
  return result;
}

Rational operator/(Rational left, Rational right)
{
  Rational result(left.getNumerator() * right.getDenominator(), left.getDenominator() * right.getNumerator());
  result.simplify();
  return result;
}

Rational Rational::operator++(int)  // Postfix
{
  Rational temp(*this);

  this->numerator_++;
  this->denominator_++;

  return temp;
}

Rational Rational::operator--(int)  // Postfix
{
  Rational temp(*this);

  this->numerator_--;
  this->denominator_--;

  return temp;
}

Rational& Rational::operator++()
{
  this->numerator_++;
  this->denominator_++;

  return *this;
}

Rational& Rational::operator--()
{
  this->numerator_--;
  this->denominator_--;

  return *this;
}

bool Rational::operator==(const Rational& rat) const
{
  bool result;

  if ((this->numerator_ == rat.numerator_) && (this->denominator_ == rat.denominator_))
  {
    result = true;
  }
  else
  {
    result = false;
  }

  return result;
}

bool Rational::operator==(int num) const
{
  bool result;
  Rational temp(num);

  result = (*this == temp);

  return result;
}

bool operator==(int num, const Rational& rat)
{
  bool result;

  result = (rat == num);

  return result;
}

bool Rational::operator!=(const Rational& rat) const
{
  return !(*this == rat);
}

bool Rational::operator!=(int num) const
{
  return !(*this == num);
}

bool operator!=(int num, const Rational& rat)
{
  return !(num == rat);
}

bool Rational::operator>(const Rational& rat) const
{
  bool result;

  if ((this->numerator_ / this->denominator_) > (rat.numerator_ / rat.denominator_))
  {
    result = true;
  }
  else
  {
    result = false;
  }

  return result;
}

bool Rational::operator>(int num) const
{
  bool result;
  Rational temp(num);

  result = (*this > temp);

  return result;
}

bool operator>(int num, const Rational& rat)
{
  bool result;

  result = (rat < num);

  return result;
}

bool Rational::operator<(const Rational& rat) const
{
  bool result;

  if (!(*this > rat) && !(*this == rat))
  {
    result = true;
  }
  else
  {
    result = false;
  }

  return result;
}

bool Rational::operator<(int num) const
{
  bool result;
  Rational temp(num);

  result = (*this < temp);

  return result;
}

bool operator<(int num, const Rational& rat)
{
  bool result;

  result = (rat > num);

  return result;
}

bool Rational::operator>=(const Rational& rat) const
{
  bool result;

  if (!(*this < rat))
  {
    result = true;
  }
  else
  {
    result = false;
  }

  return result;
}

bool Rational::operator>=(int num) const
{
  bool result;
  Rational temp(num);

  result = (*this >= temp);

  return result;
}

bool operator>=(int num, const Rational& rat)
{
  bool result;

  result = (rat <= num);

  return result;
}

bool Rational::operator<=(const Rational& rat) const
{
  bool result;

  if (!(*this > rat))
  {
    result = true;
  }
  else
  {
    result = false;
  }

  return result;
}

bool Rational::operator<=(int num) const
{
  bool result;
  Rational temp(num);

  result = (*this <= temp);

  return result;
}

bool operator<=(int num, const Rational& rat)
{
  bool result;

  result = (rat >= num);

  return result;
}

Rational Rational::inverse() const
{
  Rational temp(this->denominator_, this->numerator_);

  return temp;
}

int main()
{
  return 0;
}
