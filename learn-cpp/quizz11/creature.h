#ifndef _CREATURE_H
#define _CREATURE_H
#include <iostream>


class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int  m_health;
	int  m_dpa;
	int  m_gold;

public:
	Creature (const std::string& name, char symbol, int health, int dpa, int gold);

	const std::string& getName () const { return m_name; }
	const char getSymbol () const { return m_symbol; }
	const int getHealth () const { return m_health; }
	const int getDamage () const { return m_dpa; }
	const int getGold () const { return m_gold; }

	void reduceHealth (int);
	bool isDead () const;
	void addGold (int);
};

#endif
