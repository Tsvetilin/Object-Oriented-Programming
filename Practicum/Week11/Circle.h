#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"
#include "Point.h"
#include <cmath>
#include <stdexcept>

const double PI = 3.1415;

class Circle : public Shape {
public:
	Circle(Point& center, double radius);
	Circle();

	void setCenter(Point& center);
	void setRadius(double radius);

	Point getCenter() const;
	double getRadius() const;

	double getPerimeter() const override;
	double getArea() const override;
	bool isPointInside(const Point& P) const override;

private:
	Point center;
	double radius;
};


#endif // !_CIRCLE_H