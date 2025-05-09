#pragma once
class MonsterCard
{
private:
	char* name = nullptr;
	size_t attackPoints;
	size_t defencePoints;

	void copyFrom(const MonsterCard& other);
	void free();
public:
	MonsterCard();
	MonsterCard(const char* name,size_t attackPoints,size_t defencePoints);
	MonsterCard(const MonsterCard& other);
	MonsterCard& operator=(const MonsterCard& other);
	~MonsterCard();

	const char* getName() const;
	size_t getAttackPoints() const;
	size_t  getDefencePoints() const;
};

