#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle(const Point& p1, const Point& p2);

	double getArea() const override;
	bool isPointInside(int x, int y) const override;
};