#include "Shape.h"
#include "Point.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

int main() {
    Point A(0, 0);
    Point B(4, 0);
    Point C(0, 3);
    Triangle t(A, B, C);

    std::cout << "--- Triangle ---" << std::endl;
    std::cout << "Perimeter: " << t.getPerimeter() << std::endl;
    std::cout << "Area: " << t.getArea() << std::endl;

    Point P_inside(1, 1);
    if (t.isPointInside(P_inside)) {
        std::cout << "Point (1,1) is inside the triangle." << std::endl;
    }
    else {
        std::cout << "Point (1,1) is NOT inside the triangle." << std::endl;
    }

    Point P_outside(5, 5);
    if (t.isPointInside(P_outside)) {
        std::cout << "Point (5,5) is inside the triangle." << std::endl;
    }
    else {
        std::cout << "Point (5,5) is NOT inside the triangle." << std::endl;
    }

    std::cout << std::endl;

    Point R1(0, 0);
    Point R2(4, 3);
	Point R3(4, 0);
	Point R4(0, 3);
    Rectangle r(R1, R2, R3, R4);

    std::cout << "--- Rectangle ---" << std::endl;
    std::cout << "Perimeter: " << r.getPerimeter() << std::endl;
    std::cout << "Area: " << r.getArea() << std::endl;

    Point R_inside(2, 2);
    if (r.isPointInside(R_inside)) {
        std::cout << "Point (2,2) is inside the rectangle." << std::endl;
    }
    else {
        std::cout << "Point (2,2) is NOT inside the rectangle." << std::endl;
    }

    Point R_outside(5, 5);
    if (r.isPointInside(R_outside)) {
        std::cout << "Point (5,5) is inside the rectangle." << std::endl;
    }
    else {
        std::cout << "Point (5,5) is NOT inside the rectangle." << std::endl;
    }

    std::cout << std::endl;

    Point center(0, 0);
    double radius = 5;
    Circle c(center, radius);

    std::cout << "--- Circle ---" << std::endl;
    std::cout << "Perimeter (Circumference): " << c.getPerimeter() << std::endl;
    std::cout << "Area: " << c.getArea() << std::endl;

    Point C_inside(3, 4);
    if (c.isPointInside(C_inside)) {
        std::cout << "Point (3,4) is inside the circle." << std::endl;
    }
    else {
        std::cout << "Point (3,4) is NOT inside the circle." << std::endl;
    }

    Point C_outside(6, 0);
    if (c.isPointInside(C_outside)) {
        std::cout << "Point (6,0) is inside the circle." << std::endl;
    }
    else {
        std::cout << "Point (6,0) is NOT inside the circle." << std::endl;
    }

    return 0;
}
