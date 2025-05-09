#pragma once
#include "MonsterCard.h"
#include "MagicCards.h"

namespace 
{
	size_t maxCards = 20;

}

class Deck
{
private:
	MonsterCard* monsters = nullptr;
	size_t monstersCnt = 0;
	MagicCards* magics = nullptr;
	size_t magicsCnt = 0;

	void copyFrom(const Deck& other);
	void free();
public:
	Deck();
	Deck(MonsterCard* monsterCards,size_t monstersCnt,MagicCards* magicCards,size_t magicsCnt);
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	~Deck();

	size_t getMonsterCardCount() const;
	size_t getMagicCardCount() const;
	void addMonsterCard(MonsterCard monster);
	void addMagicCard(MagicCards magic);
	void changeMonsterCard(size_t index, MonsterCard monster);
	void changeMagicCard(size_t index, MagicCards magic);
	void removeMonsterCard(size_t index);
	void removeMagicCard(size_t index);
};

