#pragma once
#include <iostream>

class String
{
	char* str;
	size_t len;

public:
	String(const char*);

	String();
	String(const String&);
	String& operator=(const String&);
	~String();

	char& at(size_t);
	size_t getLength() const;
	const char* c_str() const;

	void print(std::ostream&) const;

private:
	void copyFrom(const String&);
	void free();
};