#include "ComputerBoy.h"

ComputerBoy::ComputerBoy() : Reward(500) {
}

void ComputerBoy::visualize() const {
	std::ifstream file("viz/computerboy.txt");
	if (!file.is_open()) {
		throw std::runtime_error("Cannot open viz/computerboy.txt");
	}

	char buffer[256];
	while (file.getline(buffer, sizeof(buffer))) {
		std::cout << buffer << std::endl;
	}

	file.close();
}