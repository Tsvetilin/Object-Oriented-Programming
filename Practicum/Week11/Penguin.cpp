#include "Penguin.h"

Penguin::Penguin(): Reward(50) {
}

void Penguin::visualize() const {
    std::ifstream file("viz/penguin.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open viz/penguin.txt");
    }

    char buffer[256];
    while (file.getline(buffer, sizeof(buffer))) {
        std::cout << buffer << std::endl;
    }

    file.close();
}