#include "MonsterCard.h"
#include <iostream>
#pragma warning(disable:4996)

void MonsterCard::copyFrom(const MonsterCard& other)
{
	attackPoints = other.attackPoints;
	defencePoints = other.defencePoints;
	name = new char[strlen(other.name)+1];
	strcpy(name, other.name);
}

void MonsterCard::free()
{
	delete[] name;
	attackPoints = 0;
	defencePoints = 0;
}

MonsterCard::MonsterCard()
{
	name = nullptr;
	attackPoints = 0;
	defencePoints = 0;
}

MonsterCard::MonsterCard(const char* name, size_t attackPoints, size_t defencePoints)
{

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->attackPoints = attackPoints;
	this->defencePoints = defencePoints;
}

MonsterCard::MonsterCard(const MonsterCard& other)
{
	copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MonsterCard::~MonsterCard()
{
	free();
}

const char* MonsterCard::getName() const
{
	return name;
}

size_t MonsterCard::getAttackPoints() const
{
	return attackPoints;
}

size_t MonsterCard::getDefencePoints() const
{
	return defencePoints;
}
