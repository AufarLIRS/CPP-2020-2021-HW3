#include <iostream>
#include <numeric>
#include <cassert>

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
    assert(denominator != 0);
    numerator_ = numerator;
    denominator_ = denominator;
    reduce();
  }

  int getNumerator()
  {
    return numerator_;
  }

  int getDenominator()
  {
    return denominator_;
  }

  /* Сначала получаем numerator_ и denominator_, потом
    проверяем denominator на 0 и в конце сокращаем дробь на НОД.
    getRez - выводит конечный результат.*/
  double getRez()
  {
    return static_cast<double>(getNumerator()) / getDenominator();
  }

  operator double()
  {
    return (double)getRez();
  }

  //сложения (+)
  Rational operator+(Rational& count)
  {
    return Rational(getNumerator() * count.getDenominator() + count.getNumerator() * getDenominator(),
                    getDenominator() * count.getDenominator());
  }

  //вычитания (-)
  Rational operator-(Rational& count)
  {
    return Rational(getNumerator() * count.getDenominator() - count.getNumerator() * getDenominator(),
                    getDenominator() * count.getDenominator());
  }

  //умножения (*)
  Rational operator*(Rational& count)
  {
    return Rational(getNumerator() * count.getNumerator(), getDenominator() * count.getDenominator());
  }

  //деления (/)
  Rational operator/(Rational& count)
  {
    return Rational(getNumerator() * count.getDenominator(), getDenominator() * count.getNumerator());
  }

  //инкремент (префиксный и постфиксный)
  Rational& operator++()
  {
    this->numerator_ = (getNumerator() + getDenominator());
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
    this->numerator_ = (getNumerator() - getDenominator());
    return *this;
  }
  Rational operator--(int)
  {
    Rational k(*this);
    --(*this);
    return k;
  }

  //сравнения (>)
  bool operator>(Rational& count)
  {
    return (getNumerator() * count.getDenominator() > count.getNumerator() * getDenominator());
  }

  //сравнения (<)
  bool operator<(Rational& count)
  {
    return (getNumerator() * count.getDenominator() < count.getNumerator() * getDenominator());
  }

  //сравнения (==)
  bool operator==(Rational& count)
  {
    return (getNumerator() * count.getDenominator() == count.getNumerator() * getDenominator());
  }

  //сравнения (!=)
  bool operator!=(Rational& count)
  {
    return (getNumerator() * count.getDenominator() != count.getNumerator() * getDenominator());
  }

  //сравнения (<=)
  bool operator<=(Rational& count)
  {
    return (getNumerator() * count.getDenominator() <= count.getNumerator() * getDenominator());
  }

  //сравнения (=>)
  bool operator>=(Rational& count)
  {
    return (getNumerator() * count.getDenominator() >= count.getNumerator() * getDenominator());
  }
};

int main()
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
