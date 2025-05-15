#include "ShapesCollection.h"

ShapesCollection::ShapesCollection() : ShapesCollection(8)
{
}

ShapesCollection::ShapesCollection(size_t size) : size(0)
{
	this->capacity = allocateCapacity(size);
	this->data = new Shape * [this->capacity] { nullptr };
}

ShapesCollection::ShapesCollection(const ShapesCollection& other)
{
	copyFrom(other);
}

ShapesCollection& ShapesCollection::operator=(const ShapesCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ShapesCollection::ShapesCollection(ShapesCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

ShapesCollection& ShapesCollection::operator=(ShapesCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void ShapesCollection::addFigure(ShapeType shapeType)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[this->size++] = ShapeFactory::shapeFactory(shapeType);
}

void ShapesCollection::addFigure(const Shape& shape)
{
	if (getSize() >= getCapacity())
	{
		resize(getCapacity() * 2);
	}

	this->data[this->size++] = shape.clone();
}

double ShapesCollection::getAreaByIndex(size_t idx) const
{
	return idx < getSize() ? this->data[idx]->getArea() : -1;
}

double ShapesCollection::getPerimeterByIndex(size_t idx) const
{
	return idx < getSize() ? this->data[idx]->getPerimeter() : -1;
}

bool ShapesCollection::getIsPointInByIndex(size_t idx, int x, int y) const
{
	return idx < getSize() ? this->data[idx]->isPointInside(x, y) : false;
}

Shape* ShapesCollection::operator[](size_t idx)
{
	return this->data[idx];
}

const Shape* ShapesCollection::operator[](size_t idx) const
{
	return this->data[idx];
}

size_t ShapesCollection::getSize() const
{
	return this->size;
}

size_t ShapesCollection::getCapacity() const
{
	return this->capacity;
}

ShapesCollection::~ShapesCollection() noexcept
{
	free();
}

void ShapesCollection::resize(size_t newCapacity)
{
	Shape** newShapes = new Shape * [newCapacity];

	for (size_t i = 0; i < getSize(); i++)
	{
		newShapes[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newShapes;
	this->capacity = newCapacity;
}

unsigned int ShapesCollection::getNextPowerOfTwo(unsigned int n) const
{
	if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

unsigned int ShapesCollection::allocateCapacity(unsigned int n) const
{
	return std::max(getNextPowerOfTwo(n + 1), 8u);
}

void ShapesCollection::copyFrom(const ShapesCollection& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new Shape * [this->capacity];

	for (size_t i = 0; i < this->capacity; i++)
	{
		this->data[i] = other.data[i]->clone();
	}
}

void ShapesCollection::moveFrom(ShapesCollection&& other) noexcept
{
	this->data = other.data;
	this->size = other.size;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

void ShapesCollection::free() noexcept
{
	for (size_t i = 0; i < getSize(); i++)
	{
		delete this->data[i];
	}

	delete[] this->data;

	this->data = nullptr;
	this->size = this->capacity = 0;
}
