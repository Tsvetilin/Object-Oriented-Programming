#ifndef _DUELIST_H
#define _DUELIST_H

#include "Deck.h"

class Duelist {
public:
	Duelist(const char* newName, Deck newDeck);
	Duelist(const char* newName);
	Duelist();
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);
	~Duelist();

	void setName(const char* newName);
	void setDeck(Deck newDeck);

	const char* getName() const;
	Deck getDeck() const;

	void addMagicCardToDeck(const MagicCard& newCard);
	void addMonsterCardToDeck(const MonsterCard& newCard);
	void changeMagicCardFromDeck(size_t index, const MagicCard& newCard);
	void changeMonsterCardFromDeck(size_t index, const MonsterCard& newCard);
	void removeMagicCardFromDeck(size_t index);
	void removeMonsterCardFromDeck(size_t index);

private:
	char* name;
	Deck deck;

	void copyFrom(const Duelist& other);
	void freeName();
	void free();
};

#endif // !_DUELIST_H
