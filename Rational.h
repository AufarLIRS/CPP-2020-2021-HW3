#ifndef _RATIONAL_H_
#define _RATIONAL_H_

#include <iostream>

using namespace std;

class Rational
{
private:
  int numerator_;
  int denominator_;

public:
  Rational();
  Rational(int p, int Q = 1);
  Rational(const Rational&);

  int getDenominator()
  {
    return (this->denominator_);
  }
  int getNumerator()
  {
    return (this->numerator_);
  }
  operator double()
  {
    return (double)this->numerator_ / (double)this->denominator_;
  }
  Rational operator++(int);
  Rational operator--(int);
  Rational& operator++();
  Rational& operator--();

  bool operator==(const Rational&) const;
  bool operator==(int) const;
  friend bool operator==(int, const Rational&);
  bool operator!=(const Rational&) const;
  bool operator!=(int) const;
  friend bool operator!=(int, const Rational&);
  bool operator>(const Rational&) const;
  bool operator>(int) const;
  friend bool operator>(int, const Rational&);
  bool operator<(const Rational&) const;
  bool operator<(int) const;
  friend bool operator<(int, const Rational&);
  bool operator>=(const Rational&) const;
  bool operator>=(int) const;
  friend bool operator>=(int, const Rational&);
  bool operator<=(const Rational&) const;
  bool operator<=(int) const;
  friend bool operator<=(int, const Rational&);

  Rational pow(unsigned exp) const;
  Rational inverse() const;
  void simplify();
};

#endif
