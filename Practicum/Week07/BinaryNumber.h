#ifndef _BINARY_NUMBER_H
#define _BINARY_NUMBER_H

#include <iostream>
#include <cstring>

class BinaryNumber {
public:
	BinaryNumber();
	BinaryNumber(const char* binary);
	BinaryNumber(const BinaryNumber& other);
	BinaryNumber& operator=(const BinaryNumber& other);
	~BinaryNumber();

	void setBinaryNumber(const char* binary);

	const char* getBinaryNumber() const;
	size_t getBinaryNumberSize() const;

	void printBinaryNumber() const;


	friend bool operator==(const BinaryNumber& bn1, const BinaryNumber& bn2);
	friend bool operator!=(const BinaryNumber& bn1, const BinaryNumber& bn2);
	friend BinaryNumber operator&(const BinaryNumber& bn1, const BinaryNumber& bn2);
	friend BinaryNumber operator|(const BinaryNumber& bn1, const BinaryNumber& bn2);
	friend BinaryNumber operator^(const BinaryNumber& bn1, const BinaryNumber& bn2);
	friend BinaryNumber operator+(const BinaryNumber& bn1, const BinaryNumber& bn2);
	friend BinaryNumber operator<<(const BinaryNumber& bn, int shift);
	friend BinaryNumber operator>>(const BinaryNumber& bn, int shift);
	friend std::ostream& operator<<(std::ostream& os, const BinaryNumber& bn);
	friend std::istream& operator>>(std::istream& is, BinaryNumber& bn);

private:
	char* binaryNumber;
	int size;

	void copyFrom(const BinaryNumber& other);
	void free();
};

#endif // !_BINARY_NUMBER_H
