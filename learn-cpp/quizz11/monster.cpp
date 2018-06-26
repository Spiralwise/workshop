#include <cstdlib>
#include "monster.h"


Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};


Monster::Type Monster::getRandomType ()
{
	static const double fraction = 1.0 / (static_cast<double> (RAND_MAX) + 1.0);
	return static_cast<Monster::Type> (rand() * fraction * MAX_TYPES);
}


Monster::Monster (const Monster::Type type)
	: Creature (Monster::monsterData[type].name
		, Monster::monsterData[type].symbol
		, Monster::monsterData[type].health
		, Monster::monsterData[type].dpa
		, Monster::monsterData[type].gold)
{
	// Empty
}


Monster Monster::getRandomMonster ()
{
	return Monster (Monster::getRandomType ());
}
