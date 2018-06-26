#include <algorithm>
#include <iostream>


const int length(9);
//int array[length] { 6, 1, 3, 2, 9, 7, 5, 4, 8 };
int array[length] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };


void PrintArray ()
{
	for (int i = 0; i < length; ++i)
		std::cout << array[i] << ' ';
	std::cout << std::endl;
}


int main ()
{
	int lastIndex = length - 1;
	for (int i = 0; i < length; ++i)
	{
		bool earlyExit = true;
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (array[j] > array[j+1])
			{
				std::swap (array[j], array[j+1]);
				earlyExit = false;
			}
		}
		if (earlyExit)
		{
			std::cout << "An early exit occurs at iteration " << i << "." << std::endl;
			break;
		}
	}
	PrintArray();
	return 0;
}
