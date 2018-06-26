#include "creature.h"


Creature::Creature (const std::string& name, char symbol, int health, int dpa, int gold)
	: m_name (name)
	, m_symbol (symbol)
	, m_health (health)
	, m_dpa (dpa)
	, m_gold (gold)
{
	// Empty
}

void Creature::reduceHealth (int damage)
{
	m_health -= damage;
}


bool Creature::isDead () const
{
	return m_health <= 0;
}


void Creature::addGold (int gold)
{
	m_gold += gold;
}
