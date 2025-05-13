#pragma once
#include "Player.h"

class PremiumPlayer : public Player
{
private:
	char* name;

	void free();
	void copyFrom(const PremiumPlayer& other);
	void moveFrom(PremiumPlayer&& other);
public:
	PremiumPlayer();
	PremiumPlayer(const char* name);
	PremiumPlayer(const PremiumPlayer& other);
	PremiumPlayer& operator=(const PremiumPlayer& other);
	PremiumPlayer(PremiumPlayer&& other);
	PremiumPlayer& operator=(PremiumPlayer&& other);
	~PremiumPlayer();

	size_t getPointsForNextStar()const override;
};

