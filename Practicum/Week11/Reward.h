#ifndef _REWARD_H
#define _REWARD_H

#include <iostream>
#include<stdexcept>

class Reward {
public:
	Reward(double price, size_t points);
	Reward(size_t points);
	Reward();
	virtual ~Reward() = default;

	void setPrice(double price);
	void setPoints(size_t points);

	double getPrice() const;
	size_t getPoints() const;

	virtual void visualize() const = 0;


private:
	double price;
	size_t points;
};
#endif // !_REWARD_H
