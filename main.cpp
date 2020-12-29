#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    int c1 = 2;
    double c2 = 1.1;
    Rational num1(1, 2);
    Rational num2(3, 4);


    if (num1 > num2)
        std::cout << "num1 > num2" << std::endl;
    if (num1 < num2)
        std::cout << "num1 < num2" << std::endl;
    if (num1 == num2)
        std::cout << "num1 == num2" << std::endl;
    if (num1 != num2)
        std::cout << "num1 != num2" << std::endl;
    if (num1 <= num2)
        std::cout << "num1 <= num2" << std::endl;
    if (num1 >= num2)
        std::cout << "num1 >= num2" << std::endl;

    std::cout << num1 * c1 << std::endl;
    std::cout << num1 * c2 << std::endl;
}
