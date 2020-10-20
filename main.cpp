#include <iostream>

struct Rational
{
private:
  int numerator_;
  int denominator_;

public:
  int getNumerator() const
  {
    return numerator_;
  };
  void setNumerator(int value)
  {
    numerator_ = value;
  }
  int getDenominator() const
  {
    return denominator_;
  }
  void setDenominator(int value)
  {
    if (getNumerator() == 0)
    {
      denominator_ = 1;
    }
    else
    {
      if (value < 0)
      {
        setNumerator(getNumerator() * -1);
        value *= -1;
      }
      for (int i = 2; i <= value; i++)
      {
        while ((getNumerator() % i == 0) && (value % i == 0))
        {
          setNumerator((getNumerator() / i));
          value /= i;
        }
      }
      denominator_ = std::abs(value);
    }
  }

public:
  Rational(int x, int y = 1)
  {
    setNumerator(x);
    setDenominator(y);
  }

public:
  Rational operator+(Rational x)
  {
    return Rational(this->getNumerator() * x.getDenominator() + x.getNumerator() * this->getDenominator(),
                    this->getDenominator() * x.getDenominator());
  }
  Rational operator-(Rational x)
  {
    return Rational(this->getNumerator() * x.getDenominator() - x.getNumerator() * this->getDenominator(),
                    this->getDenominator() * x.getDenominator());
  }
  Rational operator*(Rational x)
  {
    return Rational(this->getNumerator() * x.getNumerator(), this->getDenominator() * x.getDenominator());
  }
  Rational operator/(Rational x)
  {
    if (this->getDenominator() == 0 || x.getDenominator() == 0 || this->getNumerator() == 0 || x.getNumerator() == 0)
    {
      return Rational(1, 0);
    }
    else
    {
      return Rational(this->getNumerator() * x.getDenominator(), this->getDenominator() * x.getNumerator());
    }
  }
  Rational& operator++()
  {
    this->setNumerator(this->getNumerator() + this->getDenominator());
    return *this;
  }
  Rational operator++(int)
  {
    Rational tmp(*this);
    ++(*this);
    return tmp;
  }
  Rational& operator--()
  {
    this->setNumerator(this->getNumerator() - this->getDenominator());
    return *this;
  }
  Rational operator--(int)
  {
    Rational tmp(*this);
    --(*this);
    return tmp;
  }
  bool operator>(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() > x.getNumerator() * this->getDenominator());
  }
  bool operator<(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() < x.getNumerator() * this->getDenominator());
  }
  bool operator==(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() == x.getNumerator() * this->getDenominator());
  }
  bool operator!=(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() != x.getNumerator() * this->getDenominator());
  }
  bool operator<=(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() <= x.getNumerator() * this->getDenominator());
  }
  bool operator>=(Rational& x)
  {
    return (this->getNumerator() * x.getDenominator() >= x.getNumerator() * this->getDenominator());
  }
};
std::ostream& operator<<(std::ostream& out, const Rational& x)
{
  out << x.getNumerator() << "/" << x.getDenominator();

  return out;
}
double operator+(Rational& x, double& y)
{
  double a = x.getNumerator() / x.getDenominator();
  return a + y;
}
double operator+(double& y, Rational& x)
{
  double a = x.getNumerator() / x.getDenominator();
  return a + y;
}
double operator-(Rational& x, double& y)
{
  double a = x.getNumerator() / x.getDenominator();
  return a - y;
}
double operator-(double& y, Rational& x)
{
  double a = x.getNumerator() / x.getDenominator();
  return y - a;
}
double operator*(Rational& x, double& y)
{
  double a = x.getNumerator() / x.getDenominator();
  return a * y;
}
double operator*(double& y, Rational& x)
{
  double a = x.getNumerator() / x.getDenominator();
  return a * y;
}
double operator/(Rational& x, double& y)
{
  double a = x.getNumerator() / x.getDenominator();
  return a / y;
}
double operator/(double& y, Rational& x)
{
  double a = x.getNumerator() / x.getDenominator();
  return y / a;
}
bool operator>(Rational& x, int& y)
{
  return (x.getNumerator() > x.getDenominator() * y);
}
bool operator>(int& y, Rational& x)
{
  return (x.getDenominator() * y > x.getNumerator());
}
bool operator<(Rational& x, int& y)
{
  return (x.getNumerator() < x.getDenominator() * y);
}
bool operator<(int& y, Rational& x)
{
  return (x.getDenominator() * y < x.getNumerator());
}
bool operator==(Rational& x, int& y)
{
  return (x.getNumerator() == x.getDenominator() * y);
}
bool operator==(int& y, Rational& x)
{
  return (x.getNumerator() == x.getDenominator() * y);
}
bool operator!=(Rational& x, int& y)
{
  return (x.getNumerator() != x.getDenominator() * y);
}
bool operator!=(int& y, Rational& x)
{
  return (x.getNumerator() != x.getDenominator() * y);
}
bool operator<=(Rational& x, int& y)
{
  return (x.getNumerator() <= x.getDenominator() * y);
}
bool operator<=(int& y, Rational& x)
{
  return (x.getDenominator() * y <= x.getNumerator());
}
bool operator>=(Rational& x, int& y)
{
  return (x.getNumerator() >= x.getDenominator() * y);
}
bool operator>=(int& y, Rational& x)
{
  return (x.getDenominator() * y >= x.getNumerator());
}
int main()
{
  return 0;
}
