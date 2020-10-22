#include <iostream>
#include <algorithm>

class Rational
{

private:
    int numerator_;
    int denominator_;

    int getNumerator()
    {
        return numerator_;
    }

    int getDenominator()
    {
        return denominator_;
    }

    unsigned int gcd(int n1, int n2) {
        return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
    }

    void reduce()
    {
        int num_ = gcd(getNumerator(), getDenominator());
        numerator_ /= num_;
        denominator_ /= num_;
    }

    Rational(int numerator = 0, int denominator = 1)
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

    operator double()
    {
        return (double)(this -> numerator_ / this -> denominator_);
    }

    Rational operator+(Rational& num)
    {
        return Rational(this -> numerator_ * num.denominator_ + num.numerator_ * this -> denominator_, this->denominator_ * num.denominator_);
    }

    Rational operator-(Rational& num)
    {
        return Rational(this->numerator_ * num.denominator_ - num.numerator_ * this->denominator_, this->denominator_ * num.denominator_);
    }

    Rational operator*(Rational& num)
    {
        return Rational(this->numerator_ * num.numerator_, this->denominator_ * num.denominator_);
    }

    Rational operator/(Rational& num)
    {
        if (this->denominator_ == 0 || num.denominator_ == 0 || this->numerator_ == 0 || num.numerator_ == 0)
        {
            return Rational(1, 0);
        }

        else
        {
            return Rational(this->numerator_ * num.denominator_, this->denominator_ * num.numerator_);
        }
    }

    Rational& operator++()
    {
        this->numerator_ = (this-> numerator_ + this -> denominator_);
        return *this;
    }

    Rational operator++(int)
    {
        Rational num(*this);
        ++*this;
        return num;
    }

    Rational& operator--()
    {
        this->numerator_ = (this-> numerator_ - this -> denominator_);
        return *this;
    }

    Rational operator--(int)
    {
        Rational num(*this);
        --*this;
        return num;
    }

    bool operator>(Rational& num)
    {
        return (this->getNumerator() * num.getDenominator() > num.getNumerator() * this->getDenominator());
    }

    bool operator<(Rational& num)
    {
        return (this->getNumerator() * num.getDenominator() < num.getNumerator() * this->getDenominator());
    }

    bool operator>=(Rational& num)
    {
        return (this->getNumerator() * num.getDenominator() >= num.getNumerator() * this->getDenominator());
    }

    bool operator==(Rational& num)
    {
        return (this->getNumerator() * num.getDenominator() == num.getNumerator() * this->getDenominator());
    }

    bool operator<=(Rational& num)
    {
        return (this->getNumerator() * num.getDenominator() <= num.getNumerator() * this->getDenominator());
    }

    bool operator!=(Rational& num)
    {
        return (this->getNumerator() * num.getDenominator() != num.getNumerator() * this->getDenominator());
    }
};

using namespace std;
int main()
{
    std:: cout << "Enter num1 and num2: " << std::endl;

}
