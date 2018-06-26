#include <iostream>


int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };


int GetArraySize ()
{
	return sizeof (array) / sizeof (array[0]);
}


int GetArrayIndex (int value)
{
	int max (GetArraySize());
	for (int i = 0; i < max; ++i)
		if (array[i] == value)
			return i;
	return -1;
}


int AskArrayTarget ()
{
	int target (0);
	while (target < 1 || target > 9)
	{
		std::cout << "Enter an array index: ";
		std::cin >> target;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore (32767, '\n');
			continue;
		}
	}
	return target;
}


void PrintArray ()
{
	int max (GetArraySize());
	for (int i = 0; i < max; ++i)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}


int main ()
{
	int target = AskArrayTarget();
	int index  = GetArrayIndex (target);
	PrintArray();
	if (index == -1)
		std::cout << "This value is not here." << std::endl;
	else
		std::cout << "The index is " << index << "." << std::endl;

	return 0;
}
