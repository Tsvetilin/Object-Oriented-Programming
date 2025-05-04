#include "PC.h"
#include "Laptop.h"
#include "GamingConsole.h"
#include<iostream>

int main() {
    PC myPC(3.5, "NVIDIA RTX 3080", 750, 16);
    std::cout << "PC Details: " << std::endl;
    myPC.printType();
    const char* const* pcPeripherals = myPC.getPeripherals();
    std::cout << "Peripherals: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << pcPeripherals[i] << (i < 3 ? ", " : "\n");
    }

    Laptop myLaptop(2.8, "AMD Radeon RX 5700", 60, 8);
    std::cout << "\nLaptop Details: " << std::endl;
    myLaptop.printType();
    const char* const* laptopPeripherals = myLaptop.getPeripherals();
    std::cout << "Peripherals: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << laptopPeripherals[i] << (i < 2 ? ", " : "\n");
    }

    GamingConsole myConsole(2.3, "AMD Ryzen", 120, 16);
    std::cout << "\nGaming Console Details: " << std::endl;
    myConsole.printType();
    const char* const* consolePeripherals = myConsole.getPeripherals();
    std::cout << "Peripherals: ";
    for (int i = 0; i < 2; ++i) {
        std::cout << consolePeripherals[i] << (i < 1 ? ", " : "\n");
    }

    return 0;
}