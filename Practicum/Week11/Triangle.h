#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Shape.h"
#include "Point.h"

#include<cmath>

class Triangle : public Shape {
public:
	Triangle(Point& A, Point& B, Point& C);
	Triangle();

	void setPointA(Point& A);
	void setPointB(Point& B);
	void setPointC(Point& C);

	Point getPointA() const;
	Point getPointB() const;
	Point getPointC() const;

	double getSideAB() const;
	double getSideBC() const;
	double getSideAC() const;

	double getPerimeter() const override;
	double getHalfPerimeter() const;
	double getArea() const override;
	bool isPointInside(const Point& P) const override;

private:
	Point A;
	Point B;
	Point C;
};

#endif // !_TRIANGLE_H