#include "Shape.h"

Shape::Shape(size_t size) : size(size)
{
	this->points = new Point[this->size];
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Shape::Shape(Shape&& other) noexcept
{
	moveFrom(std::move(other));
}

Shape& Shape::operator=(Shape&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

size_t Shape::getSize() const
{
	return this->size;
}

void Shape::setPoint(int x, int y, size_t index)
{
	if (index >= getSize()) return;

	this->points[index].x = x;
	this->points[index].y = y;
}

void Shape::setPoint(const Point& p, size_t index)
{
	if (index >= getSize()) return;

	this->points[index] = p;
}

double Shape::getPerimeter() const
{
	assert(size >= 3);

	double perimeter = 0;
	for (size_t i = 0; i < getSize(); i++)
		perimeter += this->points[i].getDistance(this->points[i + 1]);

	return perimeter + this->points[0].getDistance(this->points[getSize() - 1]);
}

Shape::~Shape() noexcept
{
	free();
}

const Shape::Point& Shape::getPointAtIndex(size_t index) const
{
	return this->points[index];
}

void Shape::copyFrom(const Shape& other)
{
	this->size = other.size;

	this->points = new Point[this->size];
	for (size_t i = 0; i < this->size; i++)
		this->points[i] = other.points[i];
}

void Shape::moveFrom(Shape&& other) noexcept
{
	this->points = other.points;
	this->size = other.size;

	other.points = nullptr;
	other.size = 0;
}

void Shape::free()
{
	delete[] this->points;

	this->points = nullptr;
	this->size = 0;
}
