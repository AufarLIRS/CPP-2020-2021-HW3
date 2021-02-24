#include <iostream>
#include <algorithm>
#include <numeric>
#include "rational.h"

using namespace std;

int main()
{
  Rational test(1, -2);
  Rational test1(-5, -25);
  cout << test / test1 << endl;
  cout << test * test1 << endl;
  Rational a(2, -4);
  cout << a << endl;
  Rational b(6, 3);
  if (a < b)
    cout << "a<b" << endl;
  int c = 5;
  cout << a << endl;
  cout << a / c << endl;
  if (a <= c)
  {
    cout << ++a << endl;
  }
  double d = 8.2;
  if (a <= d)
  {
    cout << a + b << endl;
  }
  cout << a - b << endl;
  cout << a * b << endl;
  cout << a / b << endl;
  return 0;
}
