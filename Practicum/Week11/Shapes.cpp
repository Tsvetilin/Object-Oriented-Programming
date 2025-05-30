#include "Shapes.h"
#include <iostream>
#include <stdexcept>

double Shape::getSideLen(const Point& A, const Point& B) const
{
    return sqrt(pow(A.X - B.X,2) + pow(A.Y - B.Y,2));
}

Trianlge::Trianlge(Point A, Point B, Point C)
{
    A = A;
    B = B;
    C = C;
    shapeType = Type::T;
}

double Trianlge::getPerimeter()const {
    return getSideLen(A, B) + getSideLen(A, C) + getSideLen(B, C);
}

double Trianlge::getArea() const
{
    double p = getPerimeter();
    return sqrt(p * (p - getSideLen(A, B)) * (p - getSideLen(A, C)) * (p - getSideLen(B, C)));
}

bool Trianlge::isPointInside(const Point& P) const
{
    Trianlge t1(A, B, P);
    Trianlge t2(A, C, P);
    Trianlge t3(B, C, P);
    return t1.getArea() + t2.getArea() + t3.getArea() == getArea();
}


Rectangle::Rectangle(Point A, Point B)
{
    if (A.X == B.X || A.Y == B.Y) 
        throw std::invalid_argument("Cannot create rectangel with this 2 points");
    this->A = A;
    this->B = B;
    shapeType = Type::R;
}

double Rectangle::getPerimeter() const
{
    return 2.0 * (abs(A.X - B.X) + abs(A.Y - B.Y));
}

double Rectangle::getArea() const
{
    return (abs(A.X - B.X)) * (abs(A.Y - B.Y));
}

bool Rectangle::isPointInside(const Point& P) const
{
    Trianlge t1(A, {A.X,B.Y},P);
    Trianlge t2(B, { A.X,B.Y }, P);
    Trianlge t3(B, {B.X,A.Y},P);
    Trianlge t4(A, { B.X,A.Y }, P);
    return  t1.getArea() + t2.getArea() + t3.getArea() + t4.getArea() == getArea();
}

Circle::Circle(Point A, double r)
{
    center = A;
    radius = r;
    shapeType = Type::C;
}

double Circle::getPerimeter() const
{
    return 2 * 3, 14 * radius;
}

double Circle::getArea() const
{
    return 3,14 * radius * radius;
}

bool Circle::isPointInside(const Point& P) const
{
    return getSideLen(center,P) <= radius;
}
