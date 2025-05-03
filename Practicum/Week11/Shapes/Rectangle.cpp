#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : Shape(4)
{
	setPoint(x1, y1, 0);
	setPoint(x2, y2, 2);

	setPoint(x2, y1, 1);
	setPoint(x1, y2, 3);
}

Rectangle::Rectangle(const Point& p1, const Point& p2) : Shape(4)
{
	setPoint(p1, 0);
	setPoint(p2, 2);

	setPoint(p2.x, p1.y, 1);
	setPoint(p1.x, p2.y, 3);
}

double Rectangle::getArea() const
{
	return getPointAtIndex(0).getDistance(getPointAtIndex(1)) * getPointAtIndex(0).getDistance(getPointAtIndex(3));
}

bool Rectangle::isPointInside(int x, int y) const
{
	Shape::Point p(x, y);
	return p.x >= getPointAtIndex(0).x && p.x <= getPointAtIndex(1).x && p.y >= getPointAtIndex(0).y && p.y <= getPointAtIndex(3).y;
}
