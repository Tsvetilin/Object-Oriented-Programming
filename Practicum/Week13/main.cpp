#include "SharedPtr.h"

int main() {
	try {
		SharedPtr<int, 2> p1(new int(42));
		SharedPtr<int, 2> p2 = p1;
		SharedPtr<int, 2> p3 = p1;

		std::cout << *p1 << std::endl;

	}
	catch (const std::exception& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}
}