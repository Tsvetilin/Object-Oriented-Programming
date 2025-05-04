#pragma once

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	Triangle(const Point& p1, const Point& p2, const Point& p3);

	double getArea() const override;
	bool isPointInside(int x, int y) const override;
};