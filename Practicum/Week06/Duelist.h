#pragma once
#include "Deck.h"

class Duelist
{
private:
	char* name = nullptr;
	Deck deck;

	void free();
	void copyfrom(const Duelist& other);
public:
	Duelist();
	Duelist(const char* name);
	Duelist(const char* name, Deck d);
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);
	~Duelist();
};

