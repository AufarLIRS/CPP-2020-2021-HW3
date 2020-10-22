#include <iostream>

using namespace std;

class Rational
{
private:
  int numerator_;
  int denominator_;

public:
  Rational()
  {
    numerator_ = 0;
    denominator_ = 1;
  }

  Rational(int n, int d)
  {
    numerator_ = n;
    denominator_ = d;
  }

  int getNumerator_()
  {
    return numerator_;
  }

  int getDenominator_()
  {
    return denominator_;
  }

  void setNumerator_(int numerator_)
  {
    this->numerator_ = numerator_;
  }

  void setDenominator_(int denominator_)
  {
    this->denominator_ = denominator_;
  }

  int gcf(int a, int b)
  {
    if (a % b == 0)
    {
      if (b > 0)
      {
        return b;
      }
      else
      {
        return -b;
      }
    }
    else
      return gcf(b, a % b);
  }

  void reduceFraction()
  {
    if (numerator_ == 0 || denominator_ == 0)
    {
      numerator_ = 0;
      denominator_ = 1;
    }

    if (denominator_ < 0)
    {
      numerator_ *= -1;
      denominator_ *= -1;
    }

    int n = gcf(numerator_, denominator_);
    numerator_ = numerator_ / n;
    denominator_ = denominator_ / n;
    ;
  }

  Rational(double in)
  {
    denominator_ = 1;
    numerator_ = in;
    while (numerator_ % denominator_ != 0)
    {
      denominator_ *= 10;
    }
    this->reduceFraction();
  }

  Rational operator+(Rational& in)
  {
    int nb = in.getNumerator_() * denominator_ + numerator_ * in.getDenominator_();
    int db = denominator_ * in.getDenominator_();
    Rational buf = { nb, db };
    buf.reduceFraction();
    return buf;
  }

  Rational operator+(double inp)
  {
    Rational in = { inp };
    int nb = in.getNumerator_() * denominator_ + numerator_ * in.getDenominator_();
    int db = denominator_ * in.getDenominator_();
    Rational buf = { nb, db };
    buf.reduceFraction();
    return buf;
  }

  Rational operator-(Rational& in)
  {
    int nb = numerator_ * in.getDenominator_() - in.getNumerator_() * denominator_;
    int db = denominator_ * in.getDenominator_();
    Rational buf = { nb, db };
    buf.reduceFraction();
    return buf;
  }

  Rational operator-(double inp)
  {
    Rational in = { inp };
    int nb = numerator_ * in.getDenominator_() - in.getNumerator_() * denominator_;
    int db = denominator_ * in.getDenominator_();
    Rational buf = { nb, db };
    buf.reduceFraction();
    return buf;
  }

  Rational operator*(Rational& in)
  {
    int nb = in.getNumerator_() * numerator_;
    int db = denominator_ * in.getDenominator_();
    Rational buf = { nb, db };
    buf.reduceFraction();
    return buf;
  }

  Rational operator*(double inp)
  {
    Rational in = { inp };
    int nb = in.getNumerator_() * numerator_;
    int db = denominator_ * in.getDenominator_();
    Rational buf = { nb, db };
    buf.reduceFraction();
    return buf;
  }

  Rational operator/(Rational& in)
  {
    int nb = in.getNumerator_() / numerator_;
    int db = in.getDenominator_() / denominator_;
    Rational buf = { nb, db };
    buf.reduceFraction();
    return buf;
  }

  Rational operator/(double inp)
  {
    Rational in = { inp };
    int nb = in.getNumerator_() / numerator_;
    int db = in.getDenominator_() / denominator_;
    Rational buf = { nb, db };
    buf.reduceFraction();
    return buf;
  }

  Rational& operator++()
  {
    numerator_ += denominator_;
    this->reduceFraction();
    return *this;
  }

  Rational& operator++(int)
  {
    Rational temp(*this);
    // Rational temp = {this->getNumerator_(), this->getDenominator_()};
    ++(*this);
    return temp;
  }

  bool operator>(Rational in)
  {
    if (numerator_ * in.getDenominator_() > in.getNumerator_() * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator>(int in)
  {
    if (numerator_ > in * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator<(Rational in)
  {
    if (numerator_ * in.getDenominator_() < in.getNumerator_() * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator<(int in)
  {
    if (numerator_ < in * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator==(Rational in)
  {
    in.reduceFraction();
    if (numerator_ == in.getNumerator_() && denominator_ == in.getDenominator_())
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator==(int in)
  {
    if (numerator_ == in * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator!=(Rational in)
  {
    in.reduceFraction();
    if (numerator_ == in.getNumerator_() && denominator_ == in.getDenominator_())
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  bool operator!=(int in)
  {
    if (numerator_ == in * denominator_)
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  bool operator>=(Rational in)
  {
    if (numerator_ * in.getDenominator_() >= in.getNumerator_() * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator>=(int in)
  {
    if (numerator_ >= in * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator<=(Rational in)
  {
    if (numerator_ * in.getDenominator_() <= in.getNumerator_() * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator<=(int in)
  {
    if (numerator_ <= in * denominator_)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
