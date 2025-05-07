#pragma once

#include "ShapeFactory.h"

class ShapesCollection
{
private:
	Shape** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	explicit ShapesCollection(size_t size);

	void resize(size_t newCapacity);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int n) const;

	void copyFrom(const ShapesCollection& other);
	void moveFrom(ShapesCollection&& other) noexcept;
	void free() noexcept;

public:
	ShapesCollection();

	ShapesCollection(const ShapesCollection& other);
	ShapesCollection& operator=(const ShapesCollection& other);

	ShapesCollection(ShapesCollection&& other) noexcept;
	ShapesCollection& operator=(ShapesCollection&& other) noexcept;

	size_t getSize() const;
	size_t getCapacity() const;

	void addFigure(ShapeType shapeType);
	void addFigure(const Shape& shape);

	double getAreaByIndex(size_t idx) const;
	double getPerimeterByIndex(size_t idx) const;
	bool getIsPointInByIndex(size_t idx, int x, int y) const;

	Shape* operator[](size_t idx);
	const Shape* operator[](size_t idx) const;

	~ShapesCollection() noexcept;
};
