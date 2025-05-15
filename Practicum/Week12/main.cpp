#include "Pair.hpp"
#include <iostream>

int main() {
    Pair<int, double> p1(42, 3.14);
    std::cout << "Key: " << p1.getKey() << ", Value: " << p1.getValue() << std::endl;

    Pair<std::string, int> p2("age", 30);
    std::cout << "Key: " << p2.getKey() << ", Value: " << p2.getValue() << std::endl;

    return 0;
}