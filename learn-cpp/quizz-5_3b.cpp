#include <iostream>

enum class Animal
{
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH,
};

std::string GetAnimalName (Animal animal)
{
	switch (animal)
	{
		case Animal::PIG: return "Pig";
		case Animal::CHICKEN: return "Chicken";
		case Animal::GOAT: return "Goat";
		case Animal::CAT: return "Cat";
		case Animal::DOG: return "Dog";
		case Animal::OSTRICH: return "Ostrich";
		default: return "Unknown";
	}
}

int GetNumberOfLegs (Animal animal)
{
	switch (animal)
	{
		case Animal::PIG:
		case Animal::GOAT:
		case Animal::CAT:
		case Animal::DOG:
			return 4;
		case Animal::CHICKEN:
		case Animal::OSTRICH:
			return 2;
		default:
			return 0;
	}
}

int main ()
{
	Animal pig (Animal::PIG);
	Animal chicken (Animal::CHICKEN);

	std::cout << "The first animal is " << GetAnimalName (pig) << " and has " << GetNumberOfLegs (pig) << " legs." << std::endl;
	std::cout << "The second animal is " << GetAnimalName (chicken) << " and has " << GetNumberOfLegs (chicken) << " legs." << std::endl;
	std::cout << "The third animal is " << GetAnimalName (static_cast<Animal>(255)) << "." << std::endl;

	return 0;
}
