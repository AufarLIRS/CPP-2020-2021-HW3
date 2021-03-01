#include <iostream>

using namespace std;

class Rational {

    int numerator;
    int denominator;

    public:
    Rational(int numerator_ = 0, int denominator_ = 1) {
        this -> denominator = denominator_;
        this -> numerator = numerator_;
    }


    int getNumerator() {
        return(this -> numerator);
    }
    int getDenominator() {
        return(this -> denominator);
    }

    friend Rational operator+(const Rational& left, const Rational& right) {
        if (left.denominator == right.denominator)
            return Rational(right.numerator + left.numerator, left.denominator);
        else
            return Rational(left.numerator * right.denominator + right.numerator * left.denominator, right.denominator * left.denominator);
    }
    friend Rational operator-(const Rational& left, const Rational& right) {
        if (left.denominator == right.denominator)
            return Rational(right.numerator - left.numerator, left.denominator);
        else
            return Rational(left.numerator * right.denominator - right.numerator * left.denominator, right.denominator * left.denominator);
    }
    friend Rational operator*(const Rational& left, const Rational& right) {
        return (Rational(right.numerator * left.numerator, right.denominator * left.denominator));
    }
    friend Rational operator/(const Rational& left, const Rational& right) {
        return (Rational(right.numerator * left.denominator, left.numerator * right.denominator));
    }
     Rational& operator++() {
        this->numerator += this->denominator;
        return *this;

    }
    Rational& operator++(int) {
        Rational oldValue(this->numerator, this->denominator);
        this->numerator += this->denominator;
        return oldValue;
    }
    const Rational& operator--() {
        this->numerator -= this->denominator;
        return *this;

    }
    const Rational& operator--(int) {
        Rational oldValue(this->numerator, this->denominator);
        this->numerator -= this->denominator;
        return oldValue;
    }





    friend bool operator>(const Rational& left, const Rational& right) {

        if (left.numerator * right.denominator > right.numerator * left.denominator)
            return true;
        else
            return false;
    }
    friend bool operator>=(const Rational& left, const Rational& right) {
        if (left.numerator * right.denominator >= right.numerator * left.denominator)
            return true;
        else
            return false;
    }
    friend bool operator<(const Rational& left, const Rational& right) {
        if (left.numerator * right.denominator < right.numerator * left.denominator)
            return true;
        else
            return false;
    }
    friend bool operator<=(const Rational& left, const Rational& right) {
        if (left.numerator * right.denominator <= right.numerator * left.denominator)
            return true;
        else
            return false;
    }
    friend bool operator==(const Rational& left, const Rational& right) {
        if (left.denominator == right.denominator && left.numerator == right.numerator)
            return true;
        else
            return false;
    }
    friend bool operator!=(const Rational& left, const Rational& right) {
        if (left.denominator != right.denominator || left.numerator != right.numerator)
            return true;
        else
            return false;
    }
};

int main() {
    Rational a(3, 5), b(7, 5);
        Rational c /*= 5 + a*/;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = a + 5;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = a + 5.5;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = a + b;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());

        c = a - b;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = 5 - a;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = a - 5;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = a - 5.5;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());

        c = a * b;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = 5 * a;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = a * 5;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = a * 5.5;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());

        c = a / b;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = a / 5;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = 5 / a;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());
        c = 5.5 / a;
        printf("%d / %d\n", c.getNumerator(), c.getDenominator());

        printf("(>) %d\n", a > b);
        printf("(>) %d\n", a > 5);
        printf("(>) %d\n", 5 > a);

        printf("(<) %d\n", a < b);
        printf("(<) %d\n", a < 5);
        printf("(<) %d\n", 5 < a);

        printf("(==) %d\n", a == b);
        printf("(==) %d\n", 5 == a);
        printf("(==) %d\n", a == 5);

        printf("(!=) %d\n", a != b);
        printf("(!=) %d\n", 5 != a);
        printf("(!=) %d\n", a != 5);

        printf("(>=) %d\n", a >= b);
        printf("(>=) %d\n", a >= 5);
        printf("(>=) %d\n", 5 >= a);

        printf("(<=) %d\n", a <= b);
        printf("(<=) %d\n", a <= 5);
        printf("(<=) %d\n", 5 <= a);
    return 0;
}
