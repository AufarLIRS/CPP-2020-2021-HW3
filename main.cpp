#include <iostream>
#include "rational.h"
#include "rational.cpp"

using namespace std;

int main()
{
    Rational g = Rational(33, 11);
    cout << g << endl;
    Rational c = Rational(0, 5);
    cout << c << endl;
    Rational f = Rational(13, 13);
    cout << f << endl;
    Rational t = Rational(-1, -5);
    cout << t << endl;
    Rational l = Rational(1, -5);
    cout << l << endl;
    cout << c * l << endl;
    return 1;
}
