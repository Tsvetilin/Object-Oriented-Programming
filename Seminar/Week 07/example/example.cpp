#include "Car.h"
#include <iostream>

int main()
{
    Car* car1 = Car::getOrCreate("myCustomId");
    Car* car2 = Car::getOrCreate();

    std::cout << Car::getCreatedInstances() << std::endl; // 2
    std::cout << Car::getLiveInstances() << std::endl; // 2

    std::cout << car1->getId() << std::endl;
    std::cout << car2->getId() << std::endl;

    delete car1; //deletes car1 from cache as well
    Car::freeCache(); // calls delete for car2 as well

    std::cout << Car::getDestroyedInstances() << std::endl; // 2
    std::cout << Car::getLiveInstances() << std::endl; // 0
}