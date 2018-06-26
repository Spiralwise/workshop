#include <exception>
#include <iostream>


class Fraction
{
	int m_numerator;
	int m_denominator;

public:
	Fraction (int n, int d)
		: m_numerator (n)
		, m_denominator (d)
	{
		if (m_denominator == 0)
			throw std::runtime_error ("Your fraction has an invalid denominator.");
	}
};


int read_input (const std::string& prompt)
{
	int result;
	do
	{
		if (std::cin.fail ())
		{
			std::cin.clear ();
			std::cin.ignore (32768, '\n');
		}
		std::cout << prompt;
		std::cin >> result;
	}
	while (std::cin.fail ());
	return result;
}


int main ()
{
	int a, b;
	a = read_input ("Enter the numerator: ");
	b = read_input ("Enter the denominator: ");
	try
	{
		Fraction (a, b);
		std::cout << "OK." << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what () << std::endl;
	}
}
