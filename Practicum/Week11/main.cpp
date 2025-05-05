#include <iostream>
#include "Penguin.h"
#include "Pacman.h"
#include "ComputerBoy.h"
#include "Squidward.h"
#include "Sylvester.h"

int main() {
    Penguin penguin;
    Pacman pacman;
    ComputerBoy computerBoy;
    Squidward squidward;
    Sylvester sylvester;

    std::cout << "Penguin (Price: " << penguin.getPrice() << "):" << std::endl;
    penguin.visualize();

    std::cout << "\nPacman (Price: " << pacman.getPrice() << "):" << std::endl;
    pacman.visualize();

    std::cout << "\nComputerBoy (Price: " << computerBoy.getPrice() << "):" << std::endl;
    computerBoy.visualize();

    std::cout << "\nSquidward (Price: " << squidward.getPrice() << "):" << std::endl;
    squidward.visualize();

    std::cout << "\nSylvester (Price: " << sylvester.getPrice() << "):" << std::endl;
    sylvester.visualize();

    return 0;
}