#include <iostream>
#include "Optional.h"

int main() {
	Optional<int> opt1;
	std::cout << "opt1 has value: " << std::boolalpha << opt1.hasValue() << std::endl;

	opt1.setValue(42);
	std::cout << "opt1 has value: " << opt1.hasValue() << ", value: " << *opt1 << std::endl;

	Optional<int> opt2(opt1);
	std::cout << "opt2 has value: " << opt2.hasValue() << ", value: " << opt2.getValue() << std::endl;

	opt1.reset();
	std::cout << "opt1 has value after reset: " << opt1.hasValue() << std::endl;

	Optional<int> opt3;
	opt3 = opt2;
	std::cout << "opt3 has value after assignment: " << opt3.hasValue() << ", value: " << *opt3 << std::endl;

	Optional<std::string> optStr("Hello Optional!");
	if (optStr.hasValue()) {
		std::cout << "optStr: " << *optStr << std::endl;
	}

	try {
		opt1.getValue();
	}
	catch (const std::exception& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}