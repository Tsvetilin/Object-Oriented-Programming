#include <iostream>
#include "SpecialCustomFunction.h"

int squarePlusOne(int x) {
    return x * x + 1;
}

int main() {
    int (*func)(int) = squarePlusOne;
    const int specialSymbols[] = { 1, 2, 3 };
    size_t specialSymbolsSize = sizeof(specialSymbols) / sizeof(specialSymbols[0]);

    try {
        SpecialCustomFunction customFunc(func, specialSymbols, specialSymbolsSize);

        std::cout << "customFunc(2): " << customFunc(2) << std::endl;
        std::cout << "customFunc(4): " << customFunc(4) << std::endl;

        ++customFunc;
        std::cout << "customFunc(3) after ++: " << customFunc(3) << std::endl;

        SpecialCustomFunction negatedFunc = !customFunc;
        std::cout << "negatedFunc(-4): " << negatedFunc(-4) << std::endl;

        std::cout << "getFunction(5): " << customFunc.getFunction(5) << std::endl;

        std::cout << "Special symbols in customFunc: ";
        for (size_t i = 0; i < customFunc.getSpecialSymbolsSize(); ++i) {
            std::cout << customFunc.getSpecialSymbols()[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
