#pragma once
#pragma once
#include <iostream>

class String
{
	char* str;
	size_t len;

	explicit String(size_t capacity);

public:
	String(const char*);

	String();
	String(const String&);
	String& operator=(const String&);
	~String();

	char& operator[](size_t x);
	const char& operator[](size_t x) const;

	String& operator+=(const String& other);

	size_t getLength() const;
	const char* c_str() const;
	bool empty() const;

	size_t hash() const;

	static String createEmpty();
	static String of(char c);
	static String of(size_t num);

private:
	void copyFrom(const String&);
	void free();
};

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);

String operator+(const String& lhs, const String& rhs);

std::ostream& operator<<(std::ostream& os, const String& rhs);
std::istream& operator>>(std::istream& is, String& rhs);