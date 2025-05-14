#ifndef _POINT_H
#define _POINT_H

#include<iostream>

class Point {
public:
	Point(double x, double y);
	Point();

	void setCoordX(double x);
	void setCoordY(double y);

	double getX() const;
	double getY() const;

	void printPoint() const;
private:
	double x;
	double y;
};

#endif // !_POINT_H