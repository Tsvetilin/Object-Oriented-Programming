#include <iostream>
#include <cmath>

struct Point
{
    double x, y;
};

void readPoint (Point& p)
{
    std::cin >> p.x >> p.y;
}

void printPoint(const Point& p)
{
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
}

double distanceFromOrigin(const Point& p)
{
    return std::sqrt(p.x * p.x + p.y * p.y);
}

double distanceBetweenPoints(const Point& p1, const Point& p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main()
{
    Point p1, p2;
    
    readPoint(p1);
    printPoint(p1);   
    std::cout << distanceFromOrigin(p1) << std::endl;

    readPoint(p2);
    printPoint(p2);
    std::cout << distanceBetweenPoints(p1, p2) << std::endl;
}