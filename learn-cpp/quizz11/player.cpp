#include "player.h"


Player::Player (const std::string& name)
	: Creature (name, '@', 10, 1, 0)
{
	// Empty
}


void Player::levelUp ()
{
	++m_level;
	++m_dpa;
}


bool Player::hasWon () const
{
	return m_level >= 20;
}
