#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
  int numerator_;
  int denominator_;

private:
  void Reduce();

public:
  int getNumerator() const;
  int getDenominator() const;
  Rational(int x, int y);
  operator double() const;
  bool operator!=(const Rational& x);
  bool operator<=(const Rational& x);
  bool operator>=(const Rational& x);
  bool operator>(const Rational& x);
  bool operator<(const Rational& x);
  bool operator==(const Rational& x);
  friend Rational operator+(const Rational& x, const Rational& y);
  friend Rational operator-(const Rational& x, const Rational& y);
  friend Rational operator*(const Rational& x, const Rational& y);
  friend Rational operator/(const Rational& x, const Rational& y);
  Rational& operator++();
  Rational operator++(int);
  Rational& operator--();
  Rational operator--(int);
  friend std::ostream& operator<<(std::ostream& out, Rational const& x);
};

#endif  // RATIONAL_H
