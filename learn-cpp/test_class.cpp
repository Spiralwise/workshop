#include <iostream>


class  Fraction
{
private:
    const int m_FOO;
    int m_numerator;
    int m_denominator;

public:
    Fraction()
        : m_FOO (5) // default constructor
    {
         m_numerator = 0;
         m_denominator = 1;
         char array[m_FOO];
         std::cout << sizeof (array) << std::endl;
    }

    Fraction(int n)
        : m_FOO (9)
        , m_numerator (n)
        , m_denominator (1)
    {
        char array[m_FOO];
        std::cout << sizeof (array) << std::endl;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};


int main ()
{
	Fraction f(1984);
	std::cout << sizeof(f) << std::endl;

	return 0;
}
