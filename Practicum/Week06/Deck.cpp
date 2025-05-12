#include "Deck.h"
#include <iostream>

void Deck::copyFrom(const Deck& other)
{
	monstersCnt = other.monstersCnt;
	magicsCnt = other.magicsCnt;
	monsters = new MonsterCard[monstersCnt];
	magics = new MagicCards[magicsCnt];
	for (size_t i = 0; i < monstersCnt; i++)
	{
		monsters[i] = other.monsters[i];
	}
	for (size_t i = 0; i < magicsCnt; i++)
	{
		magics[i] = other.magics[i];
	}
}

void Deck::free()
{
	delete[] magics;
	delete[] monsters;
}

Deck::Deck() = default;

Deck::Deck(MonsterCard* monsterCards, size_t monstersCnt, MagicCards* magicCards, size_t magicsCnt)
{
	this->monstersCnt = monstersCnt;
	this->magicsCnt = magicsCnt;
	monsters = new MonsterCard[monstersCnt];
	magics = new MagicCards[magicsCnt];
	for (size_t i = 0; i < monstersCnt; i++)
	{
		this->monsters[i] = monsters[i];
	}
	for (size_t i = 0; i < magicsCnt; i++)
	{
		this->magics[i] = magics[i];
	}
}

Deck::Deck(const Deck& other)
{
	copyFrom(other);
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Deck::~Deck()
{
	free();
}

size_t Deck::getMonsterCardCount() const
{
	return monstersCnt;
}

size_t Deck::getMagicCardCount() const
{
	return magicsCnt;
}

void Deck::addMonsterCard(MonsterCard monster)
{
	if (monstersCnt + 1 > ::maxCards)
	{
		std::cout << "Limit reached";
		return;
	}
	MonsterCard* res = new MonsterCard[++monstersCnt];
	for (size_t i = 0; i < monstersCnt-1; i++)
	{
		res[i] = monsters[i];
	}
	res[monstersCnt-1] = monster;
	delete[] monsters;
	monsters = res;
}

void Deck::addMagicCard(MagicCards magic)
{
	if (magicsCnt + 1 > ::maxCards)
	{
		std::cout << "Limit reached";
		return;
	}
	MagicCards* res = new MagicCards[++magicsCnt];
	for (size_t i = 0; i < magicsCnt - 1; i++)
	{
		res[i] = magics[i];
	}
	res[magicsCnt - 1] = magic;
	delete[] magics;
	magics = res;
}

void Deck::changeMonsterCard(size_t index, MonsterCard monster)
{
	if (index >= monstersCnt)
	{
		std::cout << "Invalid index";
		return;
	}
	monsters[index] = monster;
}

void Deck::changeMagicCard(size_t index, MagicCards magic)
{
	if (index >= magicsCnt)
	{
		std::cout << "Invalid index";
		return;
	}
	magics[index] = magic;
}

void Deck::removeMonsterCard(size_t index)
{
	if (index >= monstersCnt)
	{
		std::cout << "Invalid index";
	}
	std::swap(monsters[index], monsters[monstersCnt - 1]);
	MonsterCard* res = new MonsterCard[--monstersCnt];
	for (size_t i = 0; i < monstersCnt; i++)
	{
		res[i] = monsters[i];
	}
	delete[] monsters;
	monsters = res;
}

void Deck::removeMagicCard(size_t index)
{
	if (index >= magicsCnt)
	{
		std::cout << "Invalid index";
	}
	std::swap(magics[index], magics[magicsCnt - 1]);
	MagicCards* res = new MagicCards[--magicsCnt];
	for (size_t i = 0; i < magicsCnt; i++)
	{
		res[i] = magics[i];
	}
	delete[] magics;
	magics = res;
}







