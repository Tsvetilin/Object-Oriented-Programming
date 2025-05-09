#pragma once

struct Point {
	double X;
	double Y;
};

enum class Type
{
	T,R,C
};


class Shape{
public:
	Type shapeType;

	virtual double getPerimeter()const = 0;
	virtual double getArea()const = 0;
	virtual bool isPointInside(const Point& P) const = 0;

	double getSideLen(const Point& A,const Point& B) const;
};

class Trianlge : public Shape {
private:
	Point A = {0,0};
	Point B = { 0,0 };
	Point C = { 0,0 };
public:
	Trianlge(Point A, Point B, Point C);
	double getPerimeter()const override;
	double getArea()const override;
	bool isPointInside(const Point& P)const override;
};


class Rectangle : public Shape {
private:
	Point A = { 0,0 };
	Point B = { 0,0 };
public:
	Rectangle(Point A, Point B);
	double getPerimeter()const override;
	double getArea()const override;
	bool isPointInside(const Point& P)const override;
};


class Circle : public Shape
{
private:
	Point center = { 0,0 };
	double radius = 0;
public:
	Circle(Point A, double r);
	double getPerimeter()const override;
	double getArea()const override;
	bool isPointInside(const Point& P)const override;

};



