#include "rational.h"
#include <iostream>
#include <numeric>

int numerator_;
int denominator_;

int Rational::getNumerator() const
{
    return numerator_;
}

int Rational::getDenominator() const
{
    return denominator_;
}

unsigned int gcd(int n1, int n2)
{
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}

void reduce()
{
    int num_ = gcd(numerator_, denominator_);
    numerator_ /= num_;
    denominator_ /= num_;
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

Rational operator+(const Rational& num1, const Rational& num2)
{
    return Rational(num1.getNumerator() * num2.getDenominator() + num2.getNumerator() * num1.getDenominator(),
                    num1.getDenominator() * num2.getDenominator());
}

Rational operator-(const Rational& num1, const Rational& num2)
{
    return Rational(num1.getNumerator() * num2.getDenominator() - num2.getNumerator() * num1.getDenominator(),
                    num1.getDenominator() * num2.getDenominator());
}

Rational operator*(const Rational& num1, const Rational& num2)
{
    return Rational(num1.getNumerator() * num2.getNumerator(), num1.getDenominator() * num2.getDenominator());
}

Rational operator/(const Rational& num1, const Rational& num2)
{
    return Rational(num1.getNumerator() * num2.getDenominator(), num1.getDenominator() * num2.getNumerator());
}

Rational& Rational::operator++()
{
    numerator_ += denominator_;
    return *this;
}

Rational Rational::operator++(int)
{
    Rational num(*this);
    ++*this;
    return num;
}

Rational& Rational::operator--()
{
    numerator_ -= denominator_;
    return *this;
}

Rational Rational::operator--(int)
{
    Rational num(*this);
    --(*this);
    return num;
}

bool Rational::operator>(const Rational& num)
{
    return (getNumerator() * num.getDenominator() > num.getNumerator() * getDenominator());
}

bool Rational::operator<(const Rational& num)
{
    return (getNumerator() * num.getDenominator() < num.getNumerator() * getDenominator());
}

bool Rational::operator==(const Rational& num)
{
    return (getNumerator() * num.getDenominator() == num.getNumerator() * getDenominator());
}

bool Rational::operator!=(const Rational& num)
{
    return (getNumerator() * num.getDenominator() != num.getNumerator() * getDenominator());
}

bool Rational::operator<=(const Rational& num)
{
    return (getNumerator() * num.getDenominator() <= num.getNumerator() * getDenominator());
}

bool Rational::operator>=(const Rational& num)
{
    return (getNumerator() * num.getDenominator() >= num.getNumerator() * getDenominator());
};

