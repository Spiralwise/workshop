#include <iostream>

int main()
{
	int min, max;
	std::cout << "Enter an integer: ";
	std::cin >> min;
	std::cout << "Enter a larger integer: ";
	std::cin >> max;

	if (min > max)
	{
		std::cout << "Swapping values." << std::endl;
		int swap(min); // swap defined and initialized here.
		min = max;
		max = swap;
	} // swap destromaxed there.

	std::cout << "The smaller value is " << min << std::endl;
	std::cout << "The larger value is " << max << std::endl;

	std::cin.clear();
	std::cin.get();

	return 0;
}
