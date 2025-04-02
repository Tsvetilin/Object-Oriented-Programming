#include "Town.h"
#include "Path.h"
#include<iostream>

int main() {
    Town towns[] = { Town(1), Town(2), Town(3), Town(4) };

    Path path1(4, 10, towns);

    std::cout << "Towns in Path 1:" << std::endl;
    path1.printPath();

    Town towns2[] = { Town(2), Town(3), Town(5) };
    Path path2(3, 10, towns);

    std::cout << std::endl;
    std::cout << "Towns in Path 2:" << std::endl;
    path2.printPath();

    Path unitedPath = path1.unite(path2);
    std::cout << "Union of Path 1 and Path 2:" << std::endl;
    unitedPath.printPath();

    std::cout << std::endl;
    Path intersectedPath = path1.intersect(path2);
    std::cout << "Intersection of Path 1 and Path 2:" << std::endl;
    intersectedPath.printPath();

    std::cout << "Path 1 has towns: " << (path1.isPathEmpty(path1) ? "Yes" : "No") << std::endl;

    std::cout << std::endl;
    size_t townIdToCheck = 3;
    std::cout << "Path 1 contains town with ID " << townIdToCheck << ": " << (path1.containsTown(townIdToCheck) ? "Yes" : "No") << std::endl;

    return 0;
}