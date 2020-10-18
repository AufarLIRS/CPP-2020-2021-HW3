#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
  int numerator_;
  int denominator_;

public:
  Rational(int numerator, int denominator);
  Rational(double);
  friend std::ostream& operator<<(std::ostream& out, const Rational&);
  operator double() const;
  Rational& operator++();
  Rational& operator--();
  Rational operator++(int);
  Rational operator--(int);
  friend Rational operator+(const Rational&, const Rational&);
  friend double operator+(const Rational&, double);
  friend double operator+(double, const Rational&);
  friend Rational operator-(const Rational&, const Rational&);
  friend double operator-(const Rational&, double);
  friend double operator-(double, const Rational&);
  friend Rational operator*(const Rational&, const Rational&);
  friend double operator*(const Rational&, double);
  friend double operator*(double, const Rational&);
  friend Rational operator/(const Rational&, const Rational&);
  friend double operator/(const Rational&, double);
  friend double operator/(double, const Rational&);
  friend bool operator==(const Rational&, const Rational&);
  friend bool operator==(const Rational&, int);
  friend bool operator==(int, const Rational&);
  friend bool operator!=(const Rational&, const Rational&);
  friend bool operator!=(const Rational&, int);
  friend bool operator!=(int, const Rational&);
  friend bool operator<(const Rational&, const Rational&);
  friend bool operator<(const Rational&, int);
  friend bool operator<(int, const Rational&);
  friend bool operator>(const Rational&, const Rational&);
  friend bool operator>(const Rational&, int);
  friend bool operator>(int, const Rational&);
  friend bool operator<=(const Rational&, const Rational&);
  friend bool operator<=(const Rational&, int);
  friend bool operator<=(int, const Rational&);
  friend bool operator>=(const Rational&, const Rational&);
  friend bool operator>=(const Rational&, int);
  friend bool operator>=(int, const Rational&);
};

#endif  // RATIONAL_H
