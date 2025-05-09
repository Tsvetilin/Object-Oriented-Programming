#include "Duelist.h"
#include <iostream>
#pragma warning(disable:4996)

void Duelist::free()
{
	delete[] name;
	name = nullptr;
}

void Duelist::copyfrom(const Duelist& other)
{
	deck = other.deck;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

Duelist::Duelist() = default;

Duelist::Duelist(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Duelist::Duelist(const char* name, Deck d)
{
	this->deck = deck;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Duelist::Duelist(const Duelist& other)
{
	copyfrom(other);
}

Duelist& Duelist::operator=(const Duelist& other)
{
	if (this != &other)
	{
		free();
		copyfrom(other);
	}
	return *this;
}

Duelist::~Duelist()
{
	free();
}

