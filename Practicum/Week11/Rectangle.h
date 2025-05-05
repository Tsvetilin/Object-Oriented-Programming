#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape {
public:
	Rectangle(Point& A, Point& B, Point& C, Point& D);
	Rectangle();

	void setPointA(Point& A);
	void setPointB(Point& B);
	void setPointC(Point& C);
	void setPointD(Point& D);

	Point getPointA() const;
	Point getPointB() const;
	Point getPointC() const;
	Point getPointD() const;

	double getSideAB() const;
	double getSideBC() const;
	double getSideCD() const;
	double getSideDA() const;

	double getPerimeter() const override;
	double getArea() const override;
	bool isPointInside(const Point& P) const override;

private:
	Point A;
	Point B;
	Point C;
	Point D;
};

#endif // !_RECTANGLE_H