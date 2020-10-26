#include <iostream>
#include <algorithm>
#include <numeric>
#include "rational.h"

int main()
{
  Rational test(1, -2);
  Rational test1(-5, -25);
  std::cout << test / test1 << std::endl;
  Rational a(2, -4);
  std::cout << a << std::endl;
  Rational b(6, 3);
  if (a < b)
    std::cout << "a<b" << std::endl;
  int c = 5;
  std::cout << a << std::endl;
  std::cout << a / c << std::endl;
  if (a <= c)
  {
    std::cout << ++a << std::endl;
  }
  double d = 8.2;
  if (a <= d)
  {
    std::cout << a + b << std::endl;
  }
  std::cout << a - b << std::endl;
  std::cout << a * b << std::endl;
  std::cout << a / b << std::endl;
}
