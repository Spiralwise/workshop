#include <cstdlib>
#include <ctime>
#include <iostream>
#include "player.h"
#include "monster.h"


void TestA ()
{
	Creature o("orc", 'o', 4, 2, 10);
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n.";
}


void TestB ()
{
	std::string username;
	std::cout << "Enter your name: ";
	std::cin >> username;

	Player player (username);

	std::cout << "Welcome, " << player.getName () << "." << std::endl;
	std::cout << "You have " << player.getHealth ();
	std::cout << " health and are carrying " << player.getGold ();
	std::cout << " gold." << std::endl;
}


void TestC ()
{
	Monster m(Monster::ORC);
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
}


void TestD ()
{
	for (int i = 0; i < 10; ++i)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}
}


void attackMonster (Player& player, Monster& monster)
{
	int damage (player.getDamage ());
	monster.reduceHealth (damage);
	std::cout << "You hit the " << monster.getName () << " for ";
	std::cout << damage << "." << std::endl;
	if (monster.isDead ())
	{
		std::cout << "You killed the " << monster.getName () << "." << std::endl;
		player.levelUp ();
		std::cout << "You are now level " << player.getLevel () << "!" << std::endl;
		int gold (monster.getGold ());
		player.addGold (gold);
		std::cout << "You found " << gold << " gold." << std::endl;
	}
}


void attackPlayer (Monster& monster, Player& player)
{
	int damage (monster.getDamage ());
	player.reduceHealth (damage);
	std::cout << "The " << monster.getName () << " hit you for ";
	std::cout << damage << " damage." << std::endl;
}


void fightMonster (Player& player, Monster& monster)
{
	char action;
	while (!player.isDead () && !monster.isDead () )
	{
		std::cout << "Your HP: " << player.getHealth ();
		std::cout << ", Enemy HP: " << monster.getHealth ();
		do
		{
			if (std::cin.fail ())
			{
				std::cout << "Command error!" << std::endl;
				std::cin.clear();
				std::cin.ignore (32000, '\n');
			}
			std::cout << "(R)un or (F)ight: ";
			std::cin >> action;
		}
		while (std::cin.fail () || (action != 'r' && action != 'f'));
		if (action == 'r')
		{
			if (rand () % 2)
			{
				std::cout << "You successfully flee!" << std::endl;
			}
			else
			{
				std::cout << "You failed to flee." << std::endl;
				attackPlayer (monster, player);
			}
		}
		else if (action == 'f')
		{
			attackMonster (player, monster);
			if (!monster.isDead ())
				attackPlayer  (monster, player);
		}
	}
}


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	std::string username;
	std::cout << "Enter your name: ";
	std::cin >> username;

	Player player (username);

	std::cout << "Welcome, " << player.getName () << "." << std::endl;

	while (!player.isDead () && !player.hasWon ())
	{
		Monster enemy (Monster::getRandomMonster ());
		std::cout << "You have encountered a " << enemy.getName ();
		std::cout << "(" << enemy.getSymbol () << ")." << std::endl;

		fightMonster (player, enemy);
	}

	if (player.isDead ())
	{
		std::cout << "You died at level " << player.getLevel ();
		std::cout << " and with " << player.getGold () << " gold." << std::endl;
		std::cout << "Too bad you can't take it with you!" << std::endl;
	}
	else
	{
		std::cout << "You won with " << player.getGold () << "gold!" << std::endl;
		std::cout << "Enjoy!" << std::endl;
	}

	return 0;
}
