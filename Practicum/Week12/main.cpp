#include<iostream>
#include "Monster.h"
#include "Sphynx.h"
#include "Centaur.h"
#include "Minotaur.h"

Monster* generateMonsters(int i) {
    switch (i % 3) {
    case 0: return new Minotaur();
    case 1: return new Centaur();
    case 2: return new Sphynx();
    default: return nullptr;
    }
}

const int SIZE = 15;

int main() {
    Monster* monsters[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        monsters[i] = generateMonsters(i);
    }

    int i = 5;
    Monster* chosen = monsters[i];
    int wins = 0;

    for (int j = 0; j < SIZE; ++j) {
        if (j == i) {
            continue;
        }
        wins += chosen->canBeat(monsters[j]);
    }

    std::cout << "Monster at position " << i << " is a " << chosen->getTypeName() << std::endl;
    std::cout << "It will win against " << wins << " other monsters." << std::endl;

    for (int i = 0; i < SIZE; ++i) {
        delete monsters[i];
    }

    return 0;
}