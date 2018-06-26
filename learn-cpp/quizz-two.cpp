#include <iostream>

int main ()
{
	double x, y;
	char symbol;

	std::cout << "Enter a double value: ";
	std::cin >> x;
	std::cout << "Enter a double value: ";
	std::cin >> y;
	std::cout << "Enter one of the following: +, -, *, or /: ";
	std::cin >> symbol;

	double z;
	if (symbol == '+')
		z = x + y;
	else if (symbol == '-')
		z = x - y;
	else if (symbol == '*')
		z = x * y;
	else if (symbol == '/')
		z = x / y;
	else
	{
		std::cout << "Error: Unknown symbol." << std::endl;
		return 1;
	}

	std::cout << x << " " << symbol << " " << y << " = " << z << std::endl;

	std::cin.clear();
	std::cin.get();

	return 0;
}
