#include <iostream>

#include "ShapesCollection.h"

int main()
{
	ShapesCollection collection;

	collection.addFigure(ShapeType::TRIANGLE); // 0 0 3 0 3 4
	collection.addFigure(ShapeType::RECTANGLE); // 0 0 4 4
	collection.addFigure(ShapeType::CIRCLE); // 0 0 2

	std::cout << collection.getAreaByIndex(0) << std::endl;

	std::cout << collection.getIsPointInByIndex(0, 1, 1) << std::endl;
	std::cout << collection.getIsPointInByIndex(0, 2, 1) << std::endl;

	bool areIntersect = collection[0]->intersect(collection[1]);

	return 0;
}