#ifndef _LOCATION_H
#define _LOCATION_H

#include<iostream>

class Location {
public:
	Location(int x, int y);
	Location();

	void setX(int x);
	void setY(int y);

	int getX() const;
	int getY() const;

	void printLocation() const;

private:
	int x, y;
};

#endif // !_LOCATION_H
