#include <iostream>
#include "rational.h"
#include <algorithm>
#include <numeric>



Rational::Rational(int numerator, int denominator)
{

    numerator_ = numerator / std::gcd(numerator, denominator);
    denominator_ = denominator/ std::gcd(numerator, denominator);
}

Rational::Rational(const Rational& rational)
{
    numerator_ = rational.numerator_;
    denominator_ = rational.denominator_;
}

Rational operator+(const Rational& l, const Rational& r)
{
    int numerator = l.numerator_ * r.denominator_ + r.numerator_ * l.denominator_;
    int denominator = l.denominator_ * r.denominator_;
    int gcd = std::gcd(numerator, denominator);
    return Rational(numerator / gcd, denominator / gcd);
}

Rational operator-(const Rational& l, const Rational& r)
{
    int numerator = l.numerator_ * r.denominator_ - r.numerator_ * l.denominator_;
    int denominator = l.denominator_ * r.denominator_;
    int gcd = std::gcd(numerator, denominator);
    return Rational(numerator / gcd, denominator / gcd);
}

Rational operator*(const Rational& l, const Rational& r)
{
    int numerator = l.numerator_ * r.numerator_;
    int denominator = l.denominator_ * r.denominator_;
    int gcd = std::gcd(numerator, denominator);
    return Rational(numerator / gcd, denominator / gcd);

}

Rational operator/(const Rational& l, const Rational& r)
 {
    int numerator = l.numerator_ * r.denominator_;
    int denominator = l.denominator_ * r.numerator_;
    int gcd = std::gcd(numerator, denominator);
    return Rational(numerator / gcd, denominator / gcd);
 }

Rational& Rational::operator++()
{
    numerator_ += denominator_;
    return *this;
}

Rational Rational::operator++(int)
{
    Rational temp(*this);
    ++*this;
    return temp;
}

Rational& Rational::operator--()
{
    numerator_ -= denominator_;
    return *this;
}

Rational Rational::operator--(int)
{
    Rational temp(*this);
    --*this;
    return temp;
}

bool Rational::operator==(Rational const& right)
{
    return (this->numerator_ * right.denominator_ == right.numerator_ * this->denominator_);
}

bool Rational::operator!=(Rational const& right)
{
    return !(this->numerator_ * right.denominator_ == right.numerator_ * this->denominator_);

}

bool Rational::operator<=(Rational const &right) const
{
    return !(*this > right);
}

bool Rational::operator<=(int num) const
{
    Rational temp(num, 1);
    return (*this <= num);
}

bool operator<=(int num, Rational& rational)
{
    return (rational >= num);
}

bool Rational::operator>=(const Rational  &right) const
{
    return !(*this < right);
}

bool Rational::operator>=(int num) const
{
    Rational temp(num, 1);
    return (*this >= temp);
}

bool operator>=(int num,const Rational& rational)
{
    return (rational <= num);
}

bool Rational::operator<(const Rational & right) const
{
    if ((this->numerator_ / this->denominator_) < (right.numerator_ / right.denominator_))
       {
        return true;
       }
    return false;
}

bool Rational::operator<(int right) const
{
    Rational temp(right, 1);

    return (*this < temp);
}

bool operator<(int num, const Rational& rational)
{
    return (rational > num);
}


bool Rational::operator>(const Rational & right) const
{
    if ((this->numerator_ / this->denominator_) > (right.numerator_ / right.denominator_))
       {
        return true;
       }
    return false;
}

bool Rational::operator>(int right) const
{
    Rational temp(right, 1);

    return (*this > temp);
}

bool operator>(int num, const Rational& rational)
{
    return (rational < num);
}

std::ostream& operator<<(std::ostream& out, const Rational& rational)
{
    out << rational.numerator_ << "/" << rational.denominator_;
    return out;
}


int main()
{
       Rational x(-5, -10);
       Rational y(-8, -7);
       std::cout << x - y << std::endl;
       std::cout << x * y << std::endl;
       std::cout << x + y << std::endl;
       std::cout << x / y << std::endl;
       if (x < y)
         std::cout << "x < y" << std::endl;
       if (x == y)
         std::cout << "x == y" << std::endl;
       if (x != y)
         std::cout << "x != y" << std::endl;
       if (x > y)
         std::cout << "x > y" << std::endl;

       Rational z(x);
       std::cout << z << std::endl;
       Rational f(1, 100);
       if(z < f)
           std::cout << "z < f" << std::endl;
       f++;
       std::cout << f << std::endl;


    return 0;
}
