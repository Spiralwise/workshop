#ifndef _MONSTER_H
#define _MONSTER_H
#include "creature.h"


class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES,
	};

private:
	struct MonsterData
	{
		std::string name;
		char symbol;
		int health;
		int dpa;
		int gold;
	};

	static MonsterData monsterData[];

	static Monster::Type getRandomType ();

public:
	Monster (const Monster::Type);

	static Monster getRandomMonster ();
};

#endif
