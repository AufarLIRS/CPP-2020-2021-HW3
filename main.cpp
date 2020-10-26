#include <iostream>
#include "rational.h"
using namespace std;

int main()
{
  cout << "Hello World!" << endl;

  Rational s = Rational(10, 5);
  Rational d = Rational(3, 2);
  double w = 21.2;
  cout << s << endl;
  cout << s << "+" << d << "=" << s + d << endl;
  cout << d << "+" << w << "=" << d + w << endl;
  cout << d << ">" << 2 << " = " << bool(d > 2) << endl;
  cout << d << "<=" << 2 << " = " << bool(d <= 2) << endl;
  cout << s++ << endl;
  cout << s << endl;
  cout << s-- << endl;
  cout << d + 2 << endl;
  Rational g = Rational(33, 11);
  cout << "33/11 = " << g << endl;
  Rational c = Rational(0, 5);
  cout << "0/5 = " << c << endl;
  Rational f = Rational(13, 13);
  cout << "13/13 = " << f << endl;
  Rational t = Rational(-1, -5);
  cout << "-1/-5 = " << t << endl;
  Rational l = Rational(1, -5);
  cout << "1/-5 = " << l << endl;
  cout << "0/5*(1/-5)==" << c * l << endl;
}
