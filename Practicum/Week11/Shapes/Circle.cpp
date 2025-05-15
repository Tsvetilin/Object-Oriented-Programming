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

Intersection Circle::intersect(const Shape* shape) const
{
	return shape->intersectWith(this);
}

Intersection Circle::intersectWith(const Triangle* shape) const
{
	return Intersection{ ShapeType::CIRCLE, ShapeType::TRIANGLE };
}

Intersection Circle::intersectWith(const Rectangle* shape) const
{
	return Intersection{ ShapeType::CIRCLE, ShapeType::RECTANGLE };
}

Intersection Circle::intersectWith(const Circle* shape) const
{
	return Intersection{ ShapeType::CIRCLE, ShapeType::CIRCLE };
}
