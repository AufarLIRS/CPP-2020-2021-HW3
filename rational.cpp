#include "rational.h"
#include <cmath>
#include <numeric>

Rational::Rational(int n, int d)
{
    if (n == 0)
    {
        numerator = 0;
        denominator = 1;
        return;
    }
    else
    {
        int k = std::gcd(n, d);
        n /= k;
        d /= k;
    }
    if (n < 0 && d < 0)
    {
        n *= -1;
        d *= -1;
    }
    numerator = n;
    denominator = d;
}
Rational::operator double() const
{
    return double(this->numerator) / this->denominator;
}

Rational& Rational::operator++()
{
    this->numerator += this->denominator;
    return *this;
}
Rational& Rational::operator--()
{
    this->numerator -= this->denominator;
    return *this;
}
Rational Rational::operator++(int)
{
    Rational tmp(*this);
    --(*this);
    return tmp;
}

Rational Rational::operator--(int)
{
    Rational tmp(*this);
    --(*this);
    return tmp;
};

Rational Rational::operator+(Rational const& s)
{
    return Rational(this->numerator * s.denominator + this->denominator * s.numerator,
                    this->denominator * s.denominator);
}
Rational Rational::operator-(Rational const& s)
{
    return Rational(this->numerator * s.denominator - this->denominator * s.numerator,
                    this->denominator * s.denominator);
}
Rational Rational::operator*(Rational const& s)
{
    return Rational(this->numerator * s.numerator, this->denominator * s.denominator);
}
Rational Rational::operator/(Rational const& s)
{
    return Rational(this->numerator * s.denominator, this->denominator * s.numerator);
}
bool Rational::operator>(Rational const& s)
{
    return (this->numerator * s.denominator > s.numerator * this->denominator);
}
bool Rational::operator<(Rational const& s)
{
    return (this->numerator * s.denominator < s.numerator * this->denominator);
}
bool Rational::operator==(Rational const& s)
{
    return (this->numerator * s.denominator == s.numerator * this->denominator);
}
bool Rational::operator!=(Rational const& s)
{
    return (this->numerator * s.denominator != s.numerator * this->denominator);
}
bool Rational::operator>=(Rational const& s)
{
    return (this->numerator * s.denominator >= s.numerator * this->denominator);
}
bool Rational::operator<=(Rational const& s)
{
    return (this->numerator * s.denominator <= s.numerator * this->denominator);
}
std::ostream& operator<<(std::ostream& out, const Rational& f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
};
