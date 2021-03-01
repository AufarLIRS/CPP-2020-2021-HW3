#include <iostream>

using namespace std;

template<typename T>
class Rational
{
private:
    T numerator;
    T denominator;
public:
    Rational(T num = 0, T den = 1)
    {
        if (std::is_integral<T>::value == 1)
        {
            T numer(evclidAlgNOD(num, den));

            if (numer != 1)
            {
                num = num / numer;
                den = den / numer;
            }
            this->denominator = den;
            this->numerator = num;
        }
    }
    static T evclidAlgNOD(T a, T b)
    {
        a = abs(a);
        b = abs(b);
        if (a == 1 || b == 1)
            return (1);
        if (a == b)
            return (a);
        while (a != 0 && b != 0)
        {
            if (a > b)
                a = (a % b);
            else
                b = (b % a);
        }
        return (a + b);
    }
    static T abs(T x)
    {
        if (x < 0)
            return (-x);
        else
            return (x);
    }
    static T evclidAlgNOK(T a, T b)
    {
        return (a / evclidAlgNOD(a, b) * b);
    }
    T getNumerator() const
    {
        return (this->numerator);
    }
    T getDenominator() const
    {
        return (this->denominator);
    }
    friend const Rational<T> operator+(const Rational<T>& left, const Rational<T>& right)
    {
        if (left.denominator == right.denominator)
            return Rational<T>(left.numerator + right.numerator, left.denominator);
        else
            return Rational<T>(left.numerator * right.denominator + right.numerator * left.denominator, left.denominator * right.denominator);
    }
    friend const Rational<T> operator-(const Rational<T>& left, const Rational<T>& right)
    {
        if (left.denominator == right.denominator)
            return Rational<T>(left.numerator - right.numerator, left.denominator);
        else
            return Rational<T>(left.numerator * right.denominator - right.numerator * left.denominator, left.denominator * right.denominator);
    }
    friend const Rational<T> operator*(const Rational<T>& left, const Rational<T>& right)
    {
        return (Rational(left.numerator * right.numerator, left.denominator * right.denominator));
    }
    friend const Rational<T> operator/(const Rational<T>& left, const Rational<T>& right)
    {
        return (Rational(left.numerator * right.denominator, left.denominator * right.numerator));
    }
    friend bool operator>(const Rational<T>& left, const Rational<T>& right)
    {
        if (left.denominator == right.denominator)
            return (left.numerator > right.numerator);
        else
            return (left.numerator * right.denominator > right.numerator * left.denominator);
    }
    friend bool operator>=(const Rational<T>& left, const Rational<T>& right)
    {
        if (left.denominator == right.denominator)
            return (left.numerator >= right.numerator);
        else
            return (left.numerator * right.denominator >= right.numerator * left.denominator);
    }
    friend bool operator<(const Rational<T>& left, const Rational<T>& right)
    {
        if (left.denominator == right.denominator)
            return (left.numerator < right.numerator);
        else
            return (left.numerator * right.denominator < right.numerator * left.denominator);
    }
    friend bool operator<=(const Rational<T>& left, const Rational<T>& right)
    {
        if (left.denominator == right.denominator)
            return (left.numerator <= right.numerator);
        else
            return (left.numerator * right.denominator <= right.numerator * left.denominator);
    }
    friend bool operator==(const Rational<T>& left, const Rational<T>& right)
    {
        if (left.denominator == right.denominator)
            return (left.numerator == right.numerator);
        else
            return (left.numerator * right.denominator == right.numerator * left.denominator);
    }
    friend bool operator!=(const Rational<T>& left, const Rational<T>& right)
    {
        if (left.denominator == right.denominator)
            return (left.numerator != right.numerator);
        else
            return (left.numerator * right.denominator != right.numerator * left.denominator);
    }
};

int main()
{
    Rational<int> a(3, 5), b(7, 5);
    Rational<int> c /*= 5 + a*/;
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
