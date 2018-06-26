#include <cassert>
#include <iostream>


class IntArray
{
	int *array = nullptr;
	int length = 0;

public:
	IntArray (int l)
		: length (l)
	{
		assert (length > 0 && "IntArra length should be a positive integer.");
		array = new int[length];
	}

	IntArray (const IntArray &arr)
		: length (arr.length)
	{
		array = new int[length];
		for (int i = 0; i < length; ++i)
			array[i] = arr.array[i];
	}

	~IntArray ()
	{
		delete[] array;
	}

	IntArray &operator= (const IntArray &arr)
	{
		if (this != &arr)
		{
			delete[] array;
			length = arr.length;
			array = new int[length];
			for (int i = 0; i < length; ++i)
				array[i] = arr.array[i];
		}
		return *this;
	}

	int &operator[] (const int idx)
	{
		assert (idx >= 0 && idx < length && "Indice must be between 0 and length-1.");
		return array[idx];
	}

	friend std::ostream &operator<< (std::ostream&, IntArray&);
};


std::ostream &operator<< (std::ostream &out, IntArray &arr)
{
	for (int i = 0; i < arr.length; ++i)
		out << arr[i] << " ";
	return out;
}


IntArray fillArray ()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}


int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}
