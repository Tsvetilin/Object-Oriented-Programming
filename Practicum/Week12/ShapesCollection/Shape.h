#pragma once

#include <iostream>
#include <cassert>

enum class ShapeType
{
	TRIANGLE,
	RECTANGLE,
	CIRCLE
};

class Triangle;
class Rectangle;
class Circle;

class Shape
{
protected:
	struct Point
	{
		int x = 0;
		int y = 0;

		Point() : x(0), y(0)
		{
		}

		Point(int x, int y) : x(x), y(y)
		{
		}

		double getDistance(const Point& other) const
		{
			double dx = x - other.x;
			double dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}
	};

	const Point& getPointAtIndex(size_t index) const;

private:
	Point* points = nullptr;
	size_t size = 0;

	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other) noexcept;
	void free();

public:
	Shape(size_t size);

	Shape(const Shape& other);
	Shape& operator=(const Shape& other);

	Shape(Shape&& other) noexcept;
	Shape& operator=(Shape&& other) noexcept;

	size_t getSize() const;

	void setPoint(int x, int y, size_t index);
	void setPoint(const Point& p, size_t index);

	virtual double getArea() const = 0;

	virtual double getPerimeter() const;

	virtual bool isPointInside(int x, int y) const = 0;

	virtual Shape* clone() const = 0;

	virtual bool intersect(const Shape* shape) const = 0;

	virtual bool intersectWith(const Triangle* shape) const = 0;
	virtual bool intersectWith(const Rectangle* shape) const = 0;
	virtual bool intersectWith(const Circle* shape) const = 0;

	virtual ~Shape() noexcept;
};