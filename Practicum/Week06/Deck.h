#ifndef _DECK_H
#define _DECK_H

#include "MonsterCard.h"
#include "MagicCard.h"

constexpr size_t MAX_MONSTER_CARDS_IN_DECK = 20;
constexpr size_t MAX_MAGIC_CARDS_IN_DECK = 20;

class Deck {
public:
	Deck(MonsterCard* newMonsterCards, size_t newMonsterCardsSize, MagicCard* newMagicCards, size_t newMagicCardsSize);
	Deck();
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	~Deck();

	void setMonsterCards(MonsterCard* newMonsterCards, size_t newMonsterCardsSize);
	void setMagicCards(MagicCard* newMagicCards, size_t newMagicCardsSize);

	void monsterCardsSetterForObj(const Deck& other);
	void magicCardsSetterForObj(const Deck& other);

	const MonsterCard* getMonsterCards() const;
	const MagicCard* getMagicCards() const;
	size_t getMonsterCardsSize() const;
	size_t getMagicCardsSize();

	void addMagicCard(const MagicCard& newCard);
	void addMonsterCard(const MonsterCard& newCard);
	void changeMagicCard(size_t index, const MagicCard& newCard);
	void changeMonsterCard(size_t index, const MonsterCard& newCard);
	void removeMagicCardAt(size_t index);
	void removeMonsterCardAt(size_t index);

	void printDeckInfo() const;

private:
	size_t monsterCardsSize, magicCardsSize;
	MonsterCard monsterCards[MAX_MONSTER_CARDS_IN_DECK];
	MagicCard magicCards[MAX_MAGIC_CARDS_IN_DECK];

	void copyFrom(const Deck& other);
	void free();
};

#endif // !_DECK_H
