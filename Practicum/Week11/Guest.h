#pragma once
#include "Player.h"
	

class Guest : public Player
{
private:
	 size_t availableTime;
	 size_t currTime;
public:
	Guest(size_t availableTime);
	bool levelUp() override ;
	bool hasTime() const;
};

