#ifndef _MONSTER_H
#define _MONSTER_H

enum MonsterType { MINOTAUR, CENTAUR, SPHYNX };

class Monster {
public:
    Monster(MonsterType t);
    virtual ~Monster();

    virtual MonsterType getType() const = 0;
    virtual bool canBeat(const Monster* other) const = 0;
    virtual const char* getTypeName() const = 0;

protected:
    MonsterType type;
};

#endif //!_MONSTER_H