#include "MagicCards.h"
#include <iostream>
#pragma warning(disable:4996)

MagicCards::MagicCards() = default;

MagicCards::MagicCards(const char* name, const char* effect, TypesOfCards type)
{
	if (strlen(name) > ::nameLen || strlen(effect) > ::effectLen || effect == "\0" || name == "\0")
	{
		name = nullptr;
		effect = nullptr;
		std::cout << "Wrong input";
		return;
	}
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->type = type;
}

const char* MagicCards::getName() const
{
	return name;
}

const char* MagicCards::getEffect() const
{
	return effect;
}

TypesOfCards MagicCards::getType() const
{
	return TypesOfCards(type);
}
