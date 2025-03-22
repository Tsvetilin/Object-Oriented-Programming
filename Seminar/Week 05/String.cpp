#include "String.h"
#include <cstring>
#include <iostream>

#pragma warning(disable:4996)

String::String(const char* str) : str(nullptr), len(0)
{
	if (str == nullptr)
	{
        str = "";
	}

	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
}

String::String() : String("") {}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

String::~String()
{
	free();
}

char& String::at(size_t index)
{
	// TODO: Fix this
	if (index >= this->len)
	{
		return this->str[len-1];
	}

	return this->str[index];
}

size_t String::getLength() const
{
	return this->len;
}

void String::copyFrom(const String& other)
{
	this->str = new char[other.len + 1];
	strcpy(this->str, other.str);
}

void String::free()
{
	delete[] str;
	str = nullptr;
	len = 0;
}

const char* String::c_str() const
{
	return str;
}

void String::print(std::ostream& out) const
{
	out << str;
}