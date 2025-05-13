#include "Guest.h"

Guest::Guest(size_t availableTime) : Player()
{
	this->availableTime = availableTime;
	currTime = 0;
}

bool Guest::levelUp()
{
	return false;
}

bool Guest::hasTime() const
{
	return currTime <= availableTime;
}
