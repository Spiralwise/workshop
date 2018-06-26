#ifndef _PLAYER_H
#define _PLAYER_H
#include "creature.h"


class Player : public Creature
{
	int m_level = 1;

public:
	Player (const std::string& name);

	const int getLevel () const { return m_level; }

	void levelUp ();
	bool hasWon () const;
};

#endif
