#include "Pacman.h"

Pacman::Pacman() : Reward(150) {
}

void Pacman::visualize() const {
	std::ifstream file("viz/pacman.txt");
	if (!file.is_open()) {
		throw std::runtime_error("Cannot open viz/pacman.txt");
	}

	char buffer[256];
	while (file.getline(buffer, sizeof(buffer))) {
		std::cout << buffer << std::endl;
	}

	file.close();
}
