#include "BinaryNumber.h"
#include<iostream>

int main() {
	BinaryNumber bn1("1101");
	BinaryNumber bn2("1000");

	std::cout << "Binary Number 1: ";
	bn1.printBinaryNumber();
	std::cout << "Binary Number 2: ";
	bn2.printBinaryNumber();

	BinaryNumber bn3 = bn1 + bn2;
	std::cout << "Sum: ";
	bn3.printBinaryNumber();

	BinaryNumber bn4 = bn1 & bn2;
	std::cout << "AND: ";
	bn4.printBinaryNumber();

	BinaryNumber bn5 = bn1 | bn2;
	std::cout << "OR: ";
	bn5.printBinaryNumber();

	BinaryNumber bn6 = bn1 ^ bn2;
	std::cout << "XOR: ";
	bn6.printBinaryNumber();

	BinaryNumber bn7 = bn1 << 2;
	std::cout << "Left Shift: ";
	bn7.printBinaryNumber();

	BinaryNumber bn8 = bn2 >> 2;
	std::cout << "Right Shift: ";
	bn8.printBinaryNumber();

	std::cout << "Binary Number 1 == Binary Number 2: " << (bn1 == bn2) << std::endl;
	std::cout << "Binary Number 1 != Binary Number 2: " << (bn1 != bn2) << std::endl;



	return 0;
}