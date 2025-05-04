#include "Rectangle.h"

Rectangle::Rectangle(Point& A, Point& B, Point& C, Point& D) {
	setPointA(A);
	setPointB(B);
	setPointC(C);
	setPointD(D);
}

Rectangle::Rectangle() {
	this->A = Point();
	this->B = Point();
	this->C = Point();
	this->D = Point();
}

void Rectangle::setPointA(Point& A) {
	this->A = A;
}

void Rectangle::setPointB(Point& B) {
	this->B = B;
}

void Rectangle::setPointC(Point& C) {
	this->C = C;
}

void Rectangle::setPointD(Point& D) {
	this->D = D;
}

Point Rectangle::getPointA() const {
	return this->A;
}

Point Rectangle::getPointB() const {
	return this->B;
}

Point Rectangle::getPointC() const {
	return this->C;
}

Point Rectangle::getPointD() const {
	return this->D;
}

double Rectangle::getSideAB() const {
	return sqrt(pow(this->B.getX() - this->A.getX(), 2) + pow(this->B.getY() - this->A.getY(), 2));
}

double Rectangle::getSideBC() const {
	return sqrt(pow(this->C.getX() - this->B.getX(), 2) + pow(this->C.getY() - this->B.getY(), 2));
}

double Rectangle::getSideCD() const {
	return sqrt(pow(this->D.getX() - this->C.getX(), 2) + pow(this->D.getY() - this->C.getY(), 2));
}

double Rectangle::getSideDA() const {
	return sqrt(pow(this->A.getX() - this->D.getX(), 2) + pow(this->A.getY() - this->D.getY(), 2));
}

double Rectangle::getPerimeter() const {
	return this->getSideAB() + this->getSideBC() + this->getSideCD() + this->getSideDA();
}

double Rectangle::getArea() const {
	return this->getSideAB() * this->getSideBC();
}

bool Rectangle::isPointInside(const Point& P) const {
	double minX = (A.getX() < C.getX()) ? A.getX() : C.getX();
	double maxX = (A.getX() > C.getX()) ? A.getX() : C.getX();
	double minY = (A.getY() < C.getY()) ? A.getY() : C.getY();
	double maxY = (A.getY() > C.getY()) ? A.getY() : C.getY();

	return (P.getX() > minX && P.getX() < maxX && P.getY() > minY && P.getY() < maxY);
}