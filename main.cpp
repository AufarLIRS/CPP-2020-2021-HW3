#include <iostream>
#include <numeric>

class Rational
{
private:
  int numerator_, denominator_;

  /* reduce - сокращение дроби с помощью функции встроенной
   * функции gcd, которая работает только на 17 стандарте. */
  void reduce()
  {
    int rez_ = std::gcd(numerator_, denominator_);
    numerator_ /= rez_;
    denominator_ /= rez_;
  }

  Rational(int numerator = 0, int denominator = 1)
  {
    numerator_ = numerator;
    denominator_ = denominator;
    reduce();
  }

  int getNumerator() const
  {
    return numerator_;
  }

  int getDenominator() const
  {
    return denominator_;
  }

  operator double() const
  {
    return (double)getNumerator() / getDenominator();
  }

  //сложения (+)
  Rational operator+(const Rational& count) const
  {
    return Rational(getNumerator() * count.getDenominator() + count.getNumerator() * getDenominator(),
                    getDenominator() * count.getDenominator());
  }

  //вычитания (-)
  Rational operator-(const Rational& count) const
  {
    return Rational(getNumerator() * count.getDenominator() - count.getNumerator() * getDenominator(),
                    getDenominator() * count.getDenominator());
  }

  //умножения (*)
  Rational operator*(const Rational& count) const
  {
    return Rational(getNumerator() * count.getNumerator(), getDenominator() * count.getDenominator());
  }

  //деления (/)
  Rational operator/(const Rational& count) const
  {
    return Rational(getNumerator() * count.getDenominator(), getDenominator() * count.getNumerator());
  }

  //инкремент (префиксный и постфиксный)
  Rational& operator++()
  {
    numerator_ += denominator_;
    return *this;
  }

  Rational operator++(int)
  {
    Rational k(*this);
    ++*this;
    return k;
  }

  //декремент (префиксный и постфиксный)
  Rational& operator--()
  {
    numerator_ -= denominator_;
    return *this;
  }

  Rational operator--(int)
  {
    Rational k(*this);
    --(*this);
    return k;
  }

  //сравнения (>)
  bool operator>(const Rational& count) const
  {
    return (getNumerator() * count.getDenominator() > count.getNumerator() * getDenominator());
  }

  //сравнения (<)
  bool operator<(const Rational& count) const
  {
    return (getNumerator() * count.getDenominator() < count.getNumerator() * getDenominator());
  }

  //сравнения (==)
  bool operator==(const Rational& count) const
  {
    return (getNumerator() * count.getDenominator() == count.getNumerator() * getDenominator());
  }

  //сравнения (!=)
  bool operator!=(const Rational& count) const
  {
    return (getNumerator() * count.getDenominator() != count.getNumerator() * getDenominator());
  }

  //сравнения (<=)
  bool operator<=(const Rational& count) const
  {
    return (getNumerator() * count.getDenominator() <= count.getNumerator() * getDenominator());
  }

  //сравнения (=>)
  bool operator>=(const Rational& count) const
  {
    return (getNumerator() * count.getDenominator() >= count.getNumerator() * getDenominator());
  }
};

int main()
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
