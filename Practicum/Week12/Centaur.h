#ifndef CENTAUR_H
#define CENTAUR_H

#include "Monster.h"

class Centaur : public Monster {
public:
    Centaur();
    MonsterType getType() const override;
    bool canBeat(const Monster* other) const override;
    const char* getTypeName() const override;
};

#endif //!_CENTAUR_H