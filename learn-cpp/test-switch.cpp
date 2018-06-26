#include <iostream>

int main ()
{
	int x;
	std::cout << "Enter a number: ";
	std::cin >> x;

	switch (x)
	{
		case 0:
			int t;
			t = 4;
			break;
		case 1:
			t = 3;
			break;
		case 2:
			t = 1;
			break;
		default:
			t = 0;
			break;
	}

	return 0;
}
