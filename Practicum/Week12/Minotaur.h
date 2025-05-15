#ifndef _MINOTAUR_H
#define _MINOTAUR_H

#include "Monster.h"

class Minotaur : public Monster {
public:
    Minotaur();
    MonsterType getType() const override;
    bool canBeat(const Monster* other) const override;
    const char* getTypeName() const override;
};

#endif //!_MINOTAUR_H