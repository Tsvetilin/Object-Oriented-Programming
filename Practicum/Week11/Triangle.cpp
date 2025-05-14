#include "Triangle.h"

Triangle::Triangle(Point& A, Point& B, Point& C) {
	setPointA(A);
	setPointB(B);
	setPointC(C);
}

Triangle::Triangle() {
	this->A = Point();
	this->B = Point();
	this->C = Point();
}

void Triangle::setPointA(Point& A) {
	this->A = A;
}

void Triangle::setPointB(Point& B) {
	this->B = B;
}

void Triangle::setPointC(Point& C) {
	this->C = C;
}

Point Triangle::getPointA() const {
	return this->A;
}

Point Triangle::getPointB() const {
	return this->B;
}

Point Triangle::getPointC() const {
	return this->C;
}

double Triangle::getSideAB() const {
	return sqrt(pow(this->B.getX() - this->A.getX(), 2) + pow(this->B.getY() - this->A.getY(), 2));
}

double Triangle::getSideBC() const {
	return sqrt(pow(this->C.getX() - this->B.getX(), 2) + pow(this->C.getY() - this->B.getY(), 2));
}

double Triangle::getSideAC() const {
	return sqrt(pow(this->C.getX() - this->A.getX(), 2) + pow(this->C.getY() - this->A.getY(), 2));
}

double Triangle::getPerimeter() const {
	return getSideAB() + getSideBC() + getSideAC();
}

double Triangle::getHalfPerimeter() const {
	return getPerimeter() / 2;
}

double Triangle::getArea() const {
	double a = this->getSideAB();
	double b = this->getSideBC();
	double c = this->getSideAC();
	double s = (a + b + c) / 2;

	return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool Triangle::isPointInside(const Point& P) const {
	double sidePA = sqrt(pow(this->A.getX() - P.getX(), 2) + pow(this->A.getY() - P.getY(), 2));
	double sidePB = sqrt(pow(this->B.getX() - P.getX(), 2) + pow(this->B.getY() - P.getY(), 2));
	double sidePC = sqrt(pow(this->C.getX() - P.getX(), 2) + pow(this->C.getY() - P.getY(), 2));
	
	double perimeterPAB = sidePA + sidePB + this->getSideAB();
	double halfPerimeterPAB = perimeterPAB / 2;

	double perimeterPAC = sidePA + sidePC + this->getSideAC();
	double halfPerimeterPAC = perimeterPAC / 2;

	double perimeterPBC = sidePB + sidePC + this->getSideBC();
	double halfPerimeterPBC = perimeterPBC / 2;

	double areaPAB = sqrt(halfPerimeterPAB * (halfPerimeterPAB - sidePA) * (halfPerimeterPAB - sidePB) * (halfPerimeterPAB - this->getSideAB()));
	double areaPAC = sqrt(halfPerimeterPAC * (halfPerimeterPAC - sidePA) * (halfPerimeterPAC - sidePC) * (halfPerimeterPAC - this->getSideAC()));
	double areaPBC = sqrt(halfPerimeterPBC * (halfPerimeterPBC - sidePB) * (halfPerimeterPBC - sidePC) * (halfPerimeterPBC - this->getSideBC()));

	return (areaPAB + areaPAC + areaPBC) == this->getArea();
}