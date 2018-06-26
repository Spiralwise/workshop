#include <iostream>

static int s_id(999);

int generateID()
{
	static int s_id = 0; // This variable has a local scope.
	return s_id++;
}

void showID()
{
	std::cout << s_id << std::endl;
}

int main()
{
	for (int i = 0; i < 5; i++)
		std::cout << "Generate ID: " << generateID() << std::endl;

	showID();

	return 0;
}
