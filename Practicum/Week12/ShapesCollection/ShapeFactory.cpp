#include "ShapeFactory.h"

Shape* ShapeFactory::shapeFactory(ShapeType shapeType)
{
	switch (shapeType)
	{
	case ShapeType::TRIANGLE:
	{
		int x1, y1, x2, y2, x3, y3;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		return new Triangle(x1, y1, x2, y2, x3, y3);
	}
	case ShapeType::RECTANGLE:
	{
		int x1, y1, x3, y3;
		std::cin >> x1 >> y1 >> x3 >> y3;
		return new Rectangle(x1, y1, x3, y3);
	}
	case ShapeType::CIRCLE:
	{
		int x, y;
		double radius;

		std::cin >> x >> y >> radius;
		return new Circle(x, y, radius);
	}
	}

	return nullptr;
}
