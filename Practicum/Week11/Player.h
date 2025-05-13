#pragma once


enum class Stars
{
	one,two,three,four,five
};

class Player
{
protected:
	static int id;
	size_t points;
	Stars stars;

	virtual size_t getPointsForNextStar() const;
    void addStar();
public:
	Player();
	void mission(size_t points);
	virtual bool levelUp();
};

