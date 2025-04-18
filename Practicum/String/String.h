#pragma once
#pragma warning (disable: 4996)

#include <iostream>

namespace Constants
{
	constexpr size_t MAX_SIZE = 1024;
}

class String
{
private:
	char* data;
	size_t size;
	size_t capacity;

	explicit String(size_t newSize);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int size) const;

	void resize(size_t newCapacity);

	void copyFrom(const String& other);
	void free();

public:
	String();
	String(const char* data);

	String(const String& other);
	String& operator=(const String& other);

	const char* c_str() const;

	size_t getSize() const;
	size_t getCapacity() const;

	const char& operator[](size_t idx) const;
	char& operator[](size_t idx);

	String& operator+=(const String& other);
	friend String operator+(const String& lhs, const String& rhs);

	String substr(size_t begin, size_t howMany) const;

	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);

	friend bool operator<=(const String& lhs, const String& rhs);
	friend bool operator>=(const String& lhs, const String& rhs);

	friend bool operator<(const String& lhs, const String& rhs);
	friend bool operator>(const String& lhs, const String& rhs);

	friend std::istream& operator>>(std::istream& is, String& other);
	friend std::ostream& operator<<(std::ostream& os, const String& other);

	~String();
};
