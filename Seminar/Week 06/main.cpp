#include "Deck.h"
#include "MagicCard.h"
#include "MonsterCard.h"
#include "Duelist.h"
#include<iostream>

int main() {
	/// Create some Monster Cards
    MonsterCard dragon("Red Dragon", 3000, 2500);
    MonsterCard warrior("Dark Warrior", 2000, 1800);

    // Create some Magic Cards
    MagicCard fireball("Fireball", CardType::spell, "Deals 500 damage");
    MagicCard healing("Healing Light", CardType::spell,"Restores 1000 HP");

    // Create a deck
    Deck myDeck;

    // Add Monster Cards
    myDeck.changeMonsterCard(0, dragon);
    myDeck.changeMonsterCard(1, warrior);

    // Add Magic Cards
    myDeck.changeMagicCard(0, fireball);
    myDeck.changeMagicCard(1, healing);

    // Print deck information
    std::cout << "Deck Information:";
    myDeck.printDeckInfo();

    return 0;
}