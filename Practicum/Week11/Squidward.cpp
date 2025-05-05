#include "Squidward.h"

Squidward::Squidward(): Reward(1000) {
}

void Squidward::visualize() const {
	std::ifstream file("viz/squidward.txt");
	if (!file.is_open()) {
		throw std::runtime_error("Cannot open viz/squidward.txt");
	}

	char buffer[256];
	while (file.getline(buffer, sizeof(buffer))) {
		std::cout << buffer << std::endl;
	}

	file.close();
}