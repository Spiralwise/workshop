#include <iostream>


enum Items
{
	ITEM_HEALTH,
	ITEM_TORCH,
	ITEM_ARROW,
	MAX_ITEM
};

int inventory[3];


int countTotalItems (const int inv[])
{
	int total (0);
	for (int i = 0; i < MAX_ITEM; ++i)
		total += inv[i];
	return total;
}


void DisplayItems ()
{
	std::cout << "Inventory content:" << std::endl;
	std::cout << "\t" << inventory[ITEM_HEALTH] << " health potions" << std::endl;
	std::cout << "\t" << inventory[ITEM_TORCH] << " torches" << std::endl;
	std::cout << "\t" << inventory[ITEM_ARROW] << " arrows" << std::endl;
}


int main ()
{
	inventory[ITEM_HEALTH] = 2;
	inventory[ITEM_TORCH] = 5;
	inventory[ITEM_ARROW] = 10;
	std::cout << "You have " << countTotalItems (inventory) << " items." << std::endl;
	DisplayItems ();

	return 0;
}
