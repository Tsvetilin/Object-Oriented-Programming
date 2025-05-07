#include "Circle.h"

Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius)
{
	setPoint(x, y, 0);
}

Circle::Circle(const Point& p, double radius) : Shape(1), radius(radius)
{
	setPoint(p, 0);
}

const double Circle::getRadius() const
{
	return this->radius;
}

double Circle::getArea() const
{
	return M_PI * getRadius() * getRadius();
}

double Circle::getPerimeter() const
{
	return 2 * M_PI * getRadius();
}

bool Circle::isPointInside(int x, int y) const
{
	Shape::Point p(x, y);
	return getPointAtIndex(0).getDistance(p) < getRadius();
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}

bool Circle::intersect(const Shape* shape) const
{
	return shape->intersectWith(this);
}

bool Circle::intersectWith(const Triangle* shape) const
{
	std::cout << "Circle + Triangle" << std::endl;
	return true;
}

bool Circle::intersectWith(const Rectangle* shape) const
{
	std::cout << "Circle + Rectangle" << std::endl;
	return true;
}

bool Circle::intersectWith(const Circle* shape) const
{
	std::cout << "Circle + Circle" << std::endl;
	return true;
}
