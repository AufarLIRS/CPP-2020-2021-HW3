#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

struct Rational
{
    int numerator_;
    int denominator_;

public:
    int getNumerator() const;
    int getDenominator() const;
    Rational(int num1, int num2);
    operator double() const;
    friend Rational operator+(Rational const& num1, Rational const& num2);
    friend Rational operator-(Rational const& num1, Rational const& num2);
    friend Rational operator*(Rational const& num1, Rational const& num2);
    friend Rational operator/(Rational const& num1, Rational const& num2);
    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);
    bool operator>(Rational const& num1);
    bool operator<(Rational const& num1);
    bool operator==(Rational const& num1);
    bool operator!=(Rational const& num1);
    bool operator<=(Rational const& num1);
    bool operator>=(Rational const& num1);
};

#endif  // RATIONAL_H
