#include "Sylvester.h"

Sylvester::Sylvester(): Reward(1500) {
}

void Sylvester::visualize() const {
	std::ifstream file("viz/sylvester.txt");
	if (!file.is_open()) {
		throw std::runtime_error("Cannot open viz/sylvester.txt");
	}

	char buffer[256];
	while (file.getline(buffer, sizeof(buffer))) {
		std::cout << buffer << std::endl;
	}

	file.close();
}