#include <iostream>
#include "constants.h"

double computeRemainingDistance(double initial, double time_sec)
{
	return initial - myConstants::gravity * (time_sec * time_sec) / 2;
}

void displayRemainingDistance(double distance, double time_sec)
{
	if (distance > 0.0)
		std::cout << "At " << time_sec << " seconds, the ball is at height: " << distance << " meters." << std::endl;
	else
		std::cout << "At " << time_sec << " seconds, the ball is on the ground." << std::endl;
}

int main()
{
	double height;
	std::cout << "Enter the initial height of the tower in meters: ";
	std::cin >> height;

	for (double t = 0.0; t < 6.0; t+=1.0)
	{
		double distance = computeRemainingDistance(height, t);
		displayRemainingDistance(distance, t);
	}

	std::cin.clear();
	std::cin.get();

	return 0;
}
