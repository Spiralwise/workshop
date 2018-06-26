#include <iostream>

int calculate (int x, int y, char op)
{
	switch (op)
	{
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/': return x / y;
		case '%': return x % y;
		default:
			std::cout << "Invalid operator" << std::endl;
			return 0;
	}
}

int main ()
{
	int x, y;
	char op;
	std::cout << "Enter the first number: ";
	std::cin >> x;
	std::cout << "Enter the second number: ";
	std::cin >> y;
	std::cout << "Enter an operator: ";
	std::cin >> op;

	int r = calculate (x, y, op);
	if (r != 0)
		std::cout << "The result is " << r << std::endl;

	return 0;
}
