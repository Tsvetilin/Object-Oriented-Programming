#include <iostream>

namespace Tri
{
    const int MAX_LENGTH = 50;

    struct Coordinates
    {
        double x, y;
    };

    struct Triangle
    {
        char identifier[MAX_LENGTH];
        Coordinates a, b, c;
    };

        double calculateArea(const Triangle& t)
    {
        return 0.5 * std::abs(t.a.x * (t.b.y - t.c.y) +
                            t.b.x * (t.c.y - t.a.y) +
                            t.c.x * (t.a.y - t.b.y));
    }

    void swapTriangles(Triangle& t1, Triangle& t2)
    {
        Triangle temp = t1;
        t1 = t2;
        t2 = temp;
    }

    void sortTriangles(Triangle triangles[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (calculateArea(triangles[j]) < calculateArea(triangles[minIndex]))
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                swapTriangles(triangles[i], triangles[minIndex]);
            }
        }
    }

    void inputTriangles(Triangle triangles[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << "Enter identifier for triangle " << i + 1 << ": ";
            std::cin >> triangles[i].identifier;

            std::cout << "Enter coordinates of three vertices (x y): \n";
            std::cin >> triangles[i].a.x >> triangles[i].a.y;
            std::cin >> triangles[i].b.x >> triangles[i].b.y;
            std::cin >> triangles[i].c.x >> triangles[i].c.y;
        }
    }

    void printTriangles(const Triangle triangles[], int n)
    {
        std::cout << "\nSorted triangles by area:\n";
        for (int i = 0; i < n; i++)
        {
            std::cout << triangles[i].identifier << std::endl;
        }
    }
}

int main()
{
    int n;
    std::cout << "Enter number of triangles: ";
    std::cin >> n;

    Tri::Triangle triangles[n];

    Tri::inputTriangles(triangles, n);
    Tri::sortTriangles(triangles, n);
    Tri::printTriangles(triangles, n);
}