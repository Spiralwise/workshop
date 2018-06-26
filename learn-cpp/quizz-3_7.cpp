#include <iostream>

/*int process(int x)
{
	if (x % 2)
		std::cout << '1';
	else
		std::cout << '0';
	return x / 2;
}*/

int process(int x, int power)
{
	if (x >= power)
	{
		std::cout << '1';
		return x - power;
	}
	else
	{
		std::cout << '0';
		return x;
	}
}

int main ()
{
	int x;

	std::cout << "Ennter a number between 0 and 255: ";
	std::cin >> x;

	for (int i = 128; i > 0; i/=2)
	{
		if (i == 8)
			std::cout << " ";
		x = process(x, i);
	}

	std::cout << std::endl;

	std::cin.clear();
	std::cin.get();

	return 0;
}
