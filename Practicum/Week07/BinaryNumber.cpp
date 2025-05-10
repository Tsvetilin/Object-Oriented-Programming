#include "BinaryNumber.h"
#pragma warning(disable:4996)

BinaryNumber::BinaryNumber() {
	this->size = 1;
	this->binaryNumber = new char[this->size + 1];
	this->binaryNumber[0] = '0';
	this->binaryNumber[1] = '\0';
}

BinaryNumber::BinaryNumber(const char* binary) {
	setBinaryNumber(binary);
}

BinaryNumber::BinaryNumber(const BinaryNumber& other) {
	this->copyFrom(other);
}

BinaryNumber& BinaryNumber::operator=(const BinaryNumber& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

BinaryNumber::~BinaryNumber() {
	this->free();
}

void BinaryNumber::setBinaryNumber(const char* binaryNumber) {
	if (binaryNumber == nullptr) {
		std::cerr << "Invalid binary number!" << std::endl;
		return;
	}

	if (this->binaryNumber == binaryNumber) {
		std::cerr << "Binary number already set!" << std::endl;
		return;
	}

	if (this->binaryNumber != nullptr) {
		this->free();
	}

	int beg = -1;
	size_t len = strlen(binaryNumber);

	for (size_t i = 0; i < len; ++i) {
		if (binaryNumber[i] == '1') {
			beg = i;
			break;
		}
	}

	if (beg == -1) {
		this->size = 1;
		this->binaryNumber = new char[2];
		this->binaryNumber[0] = '0';
		this->binaryNumber[1] = '\0';
		return;
	}

	this->size = len - beg;
	this->binaryNumber = new char[this->size + 1];
	strcpy(this->binaryNumber, binaryNumber + beg);
}

const char* BinaryNumber::getBinaryNumber() const {
	return this->binaryNumber;
}

size_t BinaryNumber::getBinaryNumberSize() const {
	return this->size;
}

void BinaryNumber::printBinaryNumber() const {
	std::cout << this->binaryNumber << std::endl;
}

void BinaryNumber::copyFrom(const BinaryNumber& other) {
	if (other.binaryNumber == nullptr) {
		std::cerr << "Invalid binary number!" << std::endl;
		return;
	}

	int beg = -1;
	size_t len = strlen(other.binaryNumber);

	for (size_t i = 0; i < len; ++i) {
		if (other.binaryNumber[i] == '1') {
			beg = i;
			break;
		}
	}

	if (beg == -1) {
		this->size = 1;
		this->binaryNumber = new char[2];
		this->binaryNumber[0] = '0';
		this->binaryNumber[1] = '\0';
		return;
	}

	this->size = len - beg;
	this->binaryNumber = new char[this->size + 1];
	strcpy(this->binaryNumber, other.binaryNumber + beg);
}

void BinaryNumber::free() {
	delete[] this->binaryNumber;
	this->binaryNumber = nullptr;
	this->size = 0;
}

bool operator==(const BinaryNumber& bn1, const BinaryNumber& bn2) {
	if (bn1.size != bn2.size) {
		return false;
	}

	for (size_t i = 0; i < bn1.size; ++i) {
		if (bn1.binaryNumber[i] != bn2.binaryNumber[i]) {
			return false;
		}
	}

	return true;
}

bool operator!=(const BinaryNumber& bn1, const BinaryNumber& bn2) {
	return !(bn1 == bn2);
}

BinaryNumber operator&(const BinaryNumber& bn1, const BinaryNumber& bn2) {
	size_t size1 = bn1.size;
	size_t size2 = bn2.size;
	size_t maxSize = size1 > size2 ? size1 : size2;

	BinaryNumber result;
	result.free();
	result.size = maxSize;
	result.binaryNumber = new char[maxSize + 1];

	for (size_t i = 0; i < maxSize; ++i) {
		char bit1 = (i < maxSize - size1) ? '0' : bn1.binaryNumber[i - (maxSize - size1)];
		char bit2 = (i < maxSize - size2) ? '0' : bn2.binaryNumber[i - (maxSize - size2)];

		result.binaryNumber[i] = (bit1 == '1' && bit2 == '1') ? '1' : '0';
	}

	result.binaryNumber[maxSize] = '\0';
	return result;
}

BinaryNumber operator|(const BinaryNumber& bn1, const BinaryNumber& bn2) {
	size_t size1 = bn1.size;
	size_t size2 = bn2.size;
	size_t maxSize = size1 > size2 ? size1 : size2;

	BinaryNumber result;
	result.free();
	result.size = maxSize;
	result.binaryNumber = new char[maxSize + 1];

	for (size_t i = 0; i < maxSize; ++i) {
		char bit1 = (i < maxSize - size1) ? '0' : bn1.binaryNumber[i - (maxSize - size1)];
		char bit2 = (i < maxSize - size2) ? '0' : bn2.binaryNumber[i - (maxSize - size2)];

		result.binaryNumber[i] = (bit1 == '1' || bit2 == '1')  ? '1' : '0';
	}

	result.binaryNumber[maxSize] = '\0';
	return result;
}

BinaryNumber operator^(const BinaryNumber& bn1, const BinaryNumber& bn2) {
	size_t size1 = bn1.size;
	size_t size2 = bn2.size;
	size_t maxSize = size1 > size2 ? size1 : size2;

	BinaryNumber result;
	result.free();
	result.size = maxSize;
	result.binaryNumber = new char[maxSize + 1];

	for (size_t i = 0; i < maxSize; ++i) {
		char bit1 = (i < maxSize - size1) ? '0' : bn1.binaryNumber[i - (maxSize - size1)];
		char bit2 = (i < maxSize - size2) ? '0' : bn2.binaryNumber[i - (maxSize - size2)];

		result.binaryNumber[i] = ((bit1 == '1' && bit2 == '0') || (bit1 == '0' && bit2 == '1')) ? '1' : '0';
	}

	result.binaryNumber[maxSize] = '\0';
	return result;
}

BinaryNumber operator+(const BinaryNumber& bn1, const BinaryNumber& bn2) {
	const char* a = bn1.getBinaryNumber();
	const char* b = bn2.getBinaryNumber();

	int len1 = bn1.getBinaryNumberSize();
	int len2 = bn2.getBinaryNumberSize();

	int maxLen = len1 > len2 ? len1 : len2;
	char* result = new char[maxLen + 2];
	result[maxLen + 1] = '\0';

	int i = len1 - 1;
	int j = len2 - 1;
	int k = maxLen;

	int carry = 0;

	while (k > 0) {
		int bitA = (i >= 0) ? a[i] - '0' : 0;
		int bitB = (j >= 0) ? b[j] - '0' : 0;

		int sum = bitA + bitB + carry;

		result[k] = (sum % 2) + '0';
		carry = sum / 2;

		i--;
		j--;
		k--;
	}

	if (carry == 1) {
		result[0] = '1';
	}
	else {
		for (int m = 0; m <= maxLen; ++m) {
			result[m] = result[m + 1];
		}
	}

	BinaryNumber res(result);
	delete[] result;
	return res;
}

BinaryNumber operator<<(const BinaryNumber& bn, int shift) {
	if (shift < 0) {
		std::cerr << "Invalid shift value!" << std::endl;
		return bn;
	}

	const char* original = bn.getBinaryNumber();
	int len = bn.getBinaryNumberSize();

	if (shift >= len) {
		char* result = new char[len + 1];
		for (int i = 0; i < len; ++i) {
			result[i] = '0';
		}
		result[len] = '\0';
		BinaryNumber shifted(result);
		delete[] result;
		return shifted;
	}

	char* result = new char[len + 1];

	for (int i = 0; i < len - shift; ++i) {
		result[i] = original[i + shift];
	}

	for (int i = len - shift; i < len; ++i) {
		result[i] = '0';
	}

	result[len] = '\0';

	BinaryNumber shifted(result);
	delete[] result;
	return shifted;
}

BinaryNumber operator>>(const BinaryNumber& bn, int shift) {
	if (shift < 0) {
		std::cerr << "Invalid shift value!" << std::endl;
		return bn;
	}

	const char* original = bn.getBinaryNumber();
	int len = bn.getBinaryNumberSize();

	char* result = new char[len + 1];

	if (shift >= len) {
		for (int i = 0; i < len; ++i) {
			result[i] = '0';
		}
	}
	else {
		for (int i = 0; i < shift; ++i) {
			result[i] = '0';
		}
		for (int i = shift; i < len; ++i) {
			result[i] = original[i - shift];
		}
	}

	result[len] = '\0';

	BinaryNumber shifted(result);
	delete[] result;
	return shifted;
}

std::ostream& operator<<(std::ostream& os, const BinaryNumber& bn) {
	os << bn.getBinaryNumber();
	return os;
}

std::istream& operator>>(std::istream& is, BinaryNumber& bn) {
	const int MAX_LEN = 1024;
	char buffer[MAX_LEN];

	is >> buffer;

	for (int i = 0; buffer[i] != '\0'; ++i) {
		if (buffer[i] != '0' && buffer[i] != '1') {
			std::cerr << "Invalid binary number input!" << std::endl;
			bn = BinaryNumber("0");
			return is;
		}
	}

	bn = BinaryNumber(buffer);
	return is;
}