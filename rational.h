#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
private:
    int numerator;
    int denominator;

public:
    static int NOD(int n, int d);
    Rational(int n, int d);
    operator double() const;
    Rational operator ++();
    Rational operator --();
    Rational operator ++(int);
    Rational operator --(int);
    Rational operator +(const Rational& s);
    Rational operator -(Rational s);
    Rational operator *(Rational s);
    Rational operator /(Rational s);
    bool operator >(Rational const& s);
    bool operator <(Rational const& s);
    bool operator ==(Rational const& s);
    bool operator !=(Rational const& s);
    bool operator >=(Rational const& s);
    bool operator <=(Rational const& s);
    friend std::ostream& operator <<(std::ostream& out, const Rational& f);
};

#endif
