#pragma once

#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

class ShapeFactory
{
public:
	static Shape* shapeFactory(ShapeType shapeType);
};
