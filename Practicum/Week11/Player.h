#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>

enum class Stars {
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5
};

class Player {
public:
	Player(size_t points, Stars stars);
	Player();
	virtual ~Player() = default;

	int getId() const;
	size_t getPoints() const;
	Stars getStars() const;

	void setPoints(size_t points);
	void setStars(Stars stars);

	void completeMission(unsigned earnedPoints);
	virtual bool levelUp();

private:
	static int id;
	size_t points;
	Stars stars;
};
#endif // !_PLAYER_H