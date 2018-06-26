#include <iostream>


int main ()
{
	char text[255];
	//std::string text;
	std::cout << "Enter text: ";
	std::cin.getline(text, 255);
	std::cout << "You've written : " << text << std::endl;
	return 0;
}
