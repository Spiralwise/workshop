#include <iostream>
#include "Fraction.h"


int main()
{
	Fraction f1(2, 5);
    f1.Print();

    Fraction f2(3, 8);
    f2.Print();

    Fraction f3 = f1 * f2;
    f3.Print();
 
    Fraction f4 = f1 * 2;
    f4.Print();

    Fraction f5 = 2 * f2;
    f5.Print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.Print();

	return 0;
}
