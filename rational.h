#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>


class Rational
{
private:
    int numerator_;
    int denominator_;
public:
    Rational(const Rational&);
    Rational(int numerator, int denominator);

    operator double() const;
    Rational& operator++();
    Rational& operator--();
    Rational operator++(int);
    Rational operator--(int);

    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&);

    friend bool operator>(int, const Rational&);
    bool operator>(const Rational&) const;
    bool operator>(int) const;
    friend bool operator<(int, const Rational&);
    bool operator<(const Rational&) const;
    bool operator<(int) const;
    bool operator==(Rational const& right);
    bool operator!=(Rational const& right);
    bool operator>=(Rational const&) const;
    bool operator>=(int) const;
    friend bool operator>=(int, const Rational&);
    bool operator<=(Rational const&) const;
    bool operator<=(int) const;
    friend bool operator<=(int, const Rational&);

    friend std::ostream& operator<<(std::ostream& out, const Rational&);

    int getDenominator()
    {
        return this->denominator_;
    }
    int getNumerator()
    {
        return this->numerator_;
    }
};

#endif // RATIONAL_H
