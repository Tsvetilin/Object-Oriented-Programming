#include "Player.h"


int Player::id = 1;

size_t Player::getPointsForNextStar() const
{
	switch (stars)
	{
	case Stars::one:
		return 256;
		break;
	case Stars::two:
		return 512;
		break;
	case Stars::three:
		return 1024;
		break;
	case Stars::four:
		return 2048;
		break;
	default:
		return 0;
		break;
	}
}

void Player::addStar()
{
	switch (stars)
	{
	case Stars::one:
		stars = Stars::two;
		break;
	case Stars::two:
		stars = Stars::three;
		break;
	case Stars::three:
		stars = Stars::four;
		break;
	case Stars::four:
		stars = Stars::five;
		break;
	default:
		break;
	}
}

Player::Player()
{
	id++;
	stars = Stars::one;
	points = 1;
}

void Player::mission(size_t points)
{
	this->points += points;
}

bool Player::levelUp()
{
	if (stars == Stars::five) return false;
	size_t neededPointsForLevelUp = getPointsForNextStar();
	if (points < neededPointsForLevelUp)
	{
		return false;
	}
	addStar();
	points -= neededPointsForLevelUp;
	return true;
}
