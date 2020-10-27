#include <iostream>
#include "rational.h"

int main()
{
  int z = 10;
  double f = 15.0;
  Rational x(5, -10);
  Rational y(-8, -7);
  std::cout << x - y << std::endl;
  std::cout << x * y << std::endl;
  std::cout << x + y << std::endl;
  std::cout << x / y << std::endl;
  if (x < y)
    std::cout << "x < y" << std::endl;
  if (x == y)
    std::cout << "x == y" << std::endl;
  if (x != y)
    std::cout << "x != y" << std::endl;
  if (x > y)
    std::cout << "x > y" << std::endl;
  if (x <= y)
    std::cout << "x <= y" << std::endl;
  if (x >= y)
    std::cout << "x >= y" << std::endl;
  std::cout << x * z << std::endl;
  std::cout << x * f << std::endl;
}
