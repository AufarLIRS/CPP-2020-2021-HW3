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
}
