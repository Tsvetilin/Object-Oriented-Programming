#include "Computer.h"
#include "ComputerStore.h"
#include "ConsultantUtils.h"
#include<stdexcept>

int main() {
	try {
		ComputerStore store("Tech Haven");

		Computer comp1("Dell", "i7", 3080, 1000, 2.0, 8, 1500.0, 5);
		Computer comp2("HP", "i5", 3060, 512, 1.5, 10, 1200.0, 3);
		Computer comp3("Lenovo", "i7", 3090, 2000, 2.2, 12, 2000.0, 2);

		store.addComputer(comp1);
		store.addComputer(comp2);
		store.addComputer(comp3);

		std::cout << "All Computers:" << std::endl;
		store.printAll();

		std::cout << "Buying Dell for 1600:" << std::endl;
		store.buy("Dell", 1600.0);

		std::cout << "Available Travel Computers:" << std::endl;
		store.printAvailable(true, false);

	}
	catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}

	return 0;
}