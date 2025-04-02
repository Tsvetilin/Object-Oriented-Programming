#ifndef _MONSTER_CARD_H
#define _MONSTER_CARD_H

class MonsterCard {
public:
	MonsterCard(const char* newName, unsigned int newAttackPoints, unsigned int newProtectPoints);
	MonsterCard();
	MonsterCard(const MonsterCard& other);
	MonsterCard& operator=(const MonsterCard& other);
	~MonsterCard();

	void setName(const char* newName);
	void setAttackPoints(unsigned int newAttackPoints);
	void setProtectPoints(unsigned int newProtectPoints);

	void nameSetterForObj(const MonsterCard& other);
	void attackPointsSetterForObj(const MonsterCard& other);
	void protectPointsSetterForObj(const MonsterCard& other);

	const char* getName() const;
	unsigned int getAttackPoints() const;
	unsigned int getProtectPoints() const;

	void printMonsterCardInfo() const;

private:
	char* name;
	unsigned int attackPoints;
	unsigned int protectPoints;

	void copyFrom(const MonsterCard& other);
	void freeName();
	void free();
};

#endif // !_MONSTER_CARD_H
