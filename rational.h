#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
  int numerator_;
  int denominator_;

public:
  Rational(int numerator, int denominator);
  friend std::ostream& operator<<(std::ostream& out, const Rational&);
  operator double() const;
  Rational& operator++();
  Rational& operator--();
  Rational operator++(int);
  Rational operator--(int);
  friend Rational operator+(const Rational&, const Rational&);
  friend Rational operator-(const Rational&, const Rational&);
  friend Rational operator*(const Rational&, const Rational&);
  friend Rational operator/(const Rational&, const Rational&);
};

#endif  // RATIONAL_H
