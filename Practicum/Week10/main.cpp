#include <iostream>
#include<stdexcept>
#include "CarPart.h"
#include "Tire.h"
#include "Engine.h"
#include "Battery.h"
#include "FuelTank.h"
#include "Car.h"

int main() {
    //check for class CarPart
    //try {
    //    CarPart part1(101, "Bosch", "Alternator");

    //    std::cout << part1 << std::endl;

    //    CarPart part2 = part1;
    //    std::cout << "Copied part: " << part2 << std::endl;

    //    CarPart part3;
    //    part3 = part1;
    //    std::cout << "Assigned part: " << part3 << std::endl;

    //    CarPart part4 = std::move(part1);
    //    std::cout << "Moved part (constructor): " << part4 << std::endl;

    //    CarPart part5;
    //    part5 = std::move(part2);
    //    std::cout << "Moved part (assignment): " << part5 << std::endl;
    //}
    //catch (const std::exception& e) {
    //    std::cerr << "Exception: " << e.what() << std::endl;
    //}

    //check after Tire class
    //try {
    //    Tire t1(1, "Michelin", "High-performance summer tire", 225, 45, 17);
    //    std::cout << "Tire t1: " << t1 << std::endl;

    //    Tire t2 = t1;
    //    std::cout << "Tire t2 (copy of t1): " << t2 << std::endl;

    //    t2.setWidth(245);
    //    t2.setProfile(40);
    //    std::cout << "Tire t2 (modified): " << t2 << std::endl;

    //    Tire t3;
    //    t3 = t2;
    //    std::cout << "Tire t3 (assigned from t2): " << t3 << std::endl;

    //    Tire t4 = std::move(t3);
    //    std::cout << "Tire t4 (moved from t3): " << t4 << std::endl;
    //    std::cout << "Tire t3 (after move): " << t3 << std::endl;

    //    Tire t5;
    //    t5 = std::move(t4);
    //    std::cout << "Tire t5 (moved from t4): " << t5 << std::endl;
    //    std::cout << "Tire t4 (after move): " << t4 << std::endl;

    //    Tire badTire(2, "Goodyear", "Invalid tire", 400, 50, 16); // width too big
    //    std::cout << "Bad tire (should not print): " << badTire << std::endl;
    //}
    //catch (const std::invalid_argument& ex) {
    //    std::cerr << "Exception caught: " << ex.what() << std::endl;
    //}

    //check for class Engine
    //try {
    //    Engine e1(1, "Ford", "V8 engine", 450);
    //    std::cout << e1 << std::endl;

    //    Engine e2 = e1;
    //    std::cout << e2 << std::endl;

    //    Engine e3 = std::move(e1);
    //    std::cout << e3 << std::endl;

    //    std::cout << e1 << std::endl;

    //    Engine e4;
    //    e4 = e2;
    //    std::cout << e4 << std::endl;

    //    Engine e5;
    //    e5 = std::move(e2);
    //    std::cout << e5 << std::endl;

    //    std::cout << e2 << std::endl;
    //}
    //catch (const std::exception& ex) {
    //    std::cerr << "Exception: " << ex.what() << std::endl;
    //}

    //check after class Battery
    //try {
    //    Battery b1(101, "Tesla", "Lithium-ion battery", 85, "BATT-12345");
    //    std::cout << b1 << std::endl;

    //    Battery b2 = b1;
    //    std::cout << b2 << std::endl;

    //    Battery b3 = std::move(b1);
    //    std::cout << b3 << std::endl;

    //    std::cout << b1 << std::endl;

    //    Battery b4;
    //    b4 = b2;
    //    std::cout << b4 << std::endl;

    //    Battery b5;
    //    b5 = std::move(b2);
    //    std::cout << b5 << std::endl;

    //    std::cout << b2 << std::endl;
    //}
    //catch (const std::exception& ex) {
    //    std::cerr << "Exception: " << ex.what() << std::endl;
    //}

    //check after class FuelTank
    //try {
    //    FuelTank tank(1, "Bosch", "Standard fuel tank", 60.0);

    //    std::cout << tank << std::endl;

    //    tank.useFuel(15.0);
    //    std::cout << "After using 15 liters:" << std::endl;
    //    std::cout << tank << std::endl;

    //    tank.refuel(10.0);
    //    std::cout << "After refueling 10 liters:" << std::endl;
    //    std::cout << tank << std::endl;

    //    tank.refuel(100.0);
    //    std::cout << "After attempting to over-refuel (100 liters):" << std::endl;
    //    std::cout << tank << std::endl;

    //    FuelTank copiedTank = tank;
    //    std::cout << "Copied tank:" << std::endl;
    //    std::cout << copiedTank << std::endl;


    //    FuelTank movedTank = std::move(tank);
    //    std::cout << std::endl;
    //    std::cout << "Moved tank:" << movedTank << std::endl;
    //}
    //catch (const std::exception& e) {
    //    std::cerr << "Exception: " << e.what() << std::endl;
    //}



    Battery battery1(1, "BatteryManufacturer1", "Standard car battery", 70, "BATT123");
    Battery battery2(2, "BatteryManufacturer2", "Heavy-duty car battery", 85, "BATT456");

    Engine engine1(1, "EngineManufacturer1", "V6 engine", 150);
    Engine engine2(2, "EngineManufacturer2", "V8 engine", 200);

    FuelTank fuelTank1(1, "FuelTankManufacturer1", "Standard fuel tank", 50.0);
    FuelTank fuelTank2(2, "FuelTankManufacturer2", "Sport fuel tank", 60.0);

    Tire tires1[4] = {
        Tire(1, "TireManufacturer1", "Standard tire", 205, 55, 16),
        Tire(2, "TireManufacturer1", "Standard tire", 205, 55, 16),
        Tire(3, "TireManufacturer1", "Standard tire", 205, 55, 16),
        Tire(4, "TireManufacturer1", "Standard tire", 205, 55, 16)
    };

    Tire tires2[4] = {
        Tire(1, "TireManufacturer2", "Sport tire", 225, 45, 17),
        Tire(2, "TireManufacturer2", "Sport tire", 225, 45, 17),
        Tire(3, "TireManufacturer2", "Sport tire", 225, 45, 17),
        Tire(4, "TireManufacturer2", "Sport tire", 225, 45, 17)
    };

    Car car1(fuelTank1, engine1, tires1, battery1, 1000.0, 1200.0);
    Car car2(fuelTank2, engine2, tires2, battery2, 1200.0, 1300.0);

    car1.getFuelTank().refuel(30.0);
    car2.getFuelTank().refuel(25.0);

    std::cout << "Car 1 Information: " << std::endl;
    car1.printCarInfo();
    std::cout << "Car 2 Information: " << std::endl;
    car2.printCarInfo();

    Car* winner = dragRace(&car1, &car2);

    if (winner) {
        std::cout << "The winner of the drag race is: " << std::endl;
        winner->printCarInfo();
    }
    else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}
