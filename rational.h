#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

struct Rational
{
  int numerator_;
  int denominator_;

private:
  void Reduce();

public:
  Rational(int x, int y);
  operator double() const;
  int getNumerator() const;
  int getDenominator() const;
  friend Rational operator+(Rational const& x, Rational const& y);
  friend Rational operator-(Rational const& x, Rational const& y);
  friend Rational operator*(Rational const& x, Rational const& y);
  friend Rational operator/(Rational const& x, Rational const& y);
  Rational& operator++();
  Rational operator++(int);
  Rational& operator--();
  Rational operator--(int);
  bool operator>(Rational const& x);
  bool operator<(Rational const& x);
  bool operator==(Rational const& x);
  bool operator!=(Rational const& x);
  bool operator<=(Rational const& x);
  bool operator>=(Rational const& x);
  friend std::ostream& operator<<(std::ostream& out, Rational const& x);
};

#endif  // RATIONAL_H
