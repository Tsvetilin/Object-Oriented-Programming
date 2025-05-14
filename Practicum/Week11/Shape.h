#ifndef _SHAPE_H
#define _SHAPE_H

#include "Point.h"

class Shape {
public:
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	virtual bool isPointInside(const Point& P) const = 0;

	virtual ~Shape() = default;
};

#endif // !_SHAPE_H