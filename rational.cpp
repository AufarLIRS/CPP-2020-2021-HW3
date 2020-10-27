#include "rational.h"
#include <iostream>
#include <numeric>

int numerator_, denominator_;

/* reduce - сокращение дроби с помощью функции встроенной
 * функции gcd, которая работает только на 17 стандарте. */
void reduce()
{
  int rez_ = std::gcd(numerator_, denominator_);
  numerator_ /= rez_;
  denominator_ /= rez_;
}

int Rational::getNumerator() const
{
  return numerator_;
}

int Rational::getDenominator() const
{
  return denominator_;
}

Rational::Rational(int numerator, int denominator)
{
  if (denominator < 0)
  {
    numerator *= -1;
    denominator *= -1;
  }
  numerator_ = numerator;
  denominator_ = denominator;
  reduce();
}

Rational::operator double() const
{
  return (double)getNumerator() / getDenominator();
}

//сложения (+)
Rational operator+(const Rational& count1, const Rational& count2)
{
  return Rational(count1.getNumerator() * count2.getDenominator() + count2.getNumerator() * count1.getDenominator(),
                  count1.getDenominator() * count2.getDenominator());
}

//вычитания (-)
Rational operator-(const Rational& count1, const Rational& count2)
{
  return Rational(count1.getNumerator() * count2.getDenominator() - count2.getNumerator() * count1.getDenominator(),
                  count1.getDenominator() * count2.getDenominator());
}

//умножения (*)
Rational operator*(const Rational& count1, const Rational& count2)
{
  return Rational(count1.getNumerator() * count2.getNumerator(), count1.getDenominator() * count2.getDenominator());
}

//деления (/)
Rational operator/(const Rational& count1, const Rational& count2)
{
  return Rational(count1.getNumerator() * count2.getDenominator(), count1.getDenominator() * count2.getNumerator());
}

//инкремент (префиксный и постфиксный)
Rational& Rational::operator++()
{
  numerator_ += denominator_;
  return *this;
}

Rational Rational::operator++(int)
{
  Rational k(*this);
  ++*this;
  return k;
}

//декремент (префиксный и постфиксный)
Rational& Rational::operator--()
{
  numerator_ -= denominator_;
  return *this;
}

Rational Rational::operator--(int)
{
  Rational k(*this);
  --(*this);
  return k;
}

//сравнения (>)
bool Rational::operator>(const Rational& count)
{
  return (getNumerator() * count.getDenominator() > count.getNumerator() * getDenominator());
}

//сравнения (<)
bool Rational::operator<(const Rational& count)
{
  return (getNumerator() * count.getDenominator() < count.getNumerator() * getDenominator());
}

//сравнения (==)
bool Rational::operator==(const Rational& count)
{
  return (getNumerator() * count.getDenominator() == count.getNumerator() * getDenominator());
}

//сравнения (!=)
bool Rational::operator!=(const Rational& count)
{
  return (getNumerator() * count.getDenominator() != count.getNumerator() * getDenominator());
}

//сравнения (<=)
bool Rational::operator<=(const Rational& count)
{
  return (getNumerator() * count.getDenominator() <= count.getNumerator() * getDenominator());
}

//сравнения (=>)
bool Rational::operator>=(const Rational& count)
{
  return (getNumerator() * count.getDenominator() >= count.getNumerator() * getDenominator());
}

std::ostream& operator<<(std::ostream& out, const Rational& count)
{
  out << count.getNumerator() << "/" << count.getDenominator();
  return out;
};
