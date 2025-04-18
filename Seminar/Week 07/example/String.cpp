#include "String.h"
#include <cstring>
#include <iostream>

#pragma warning(disable:4996)

namespace {
	const size_t BUFFER_LENGTH = 1024;
	const char NUM_TO_CHAR_CONVERTION = -0 + '0';

	size_t getNumLength(size_t num)
	{
		if (num == 0)
		{
			return 1;
		}

		size_t count = 0;

		while (num > 0)
		{
			count++;
			num /= 10;
		}

		return count;
	}
}

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


size_t String::getLength() const
{
	return this->len;
}

void String::copyFrom(const String& other)
{
	this->str = new char[other.len + 1];
	this->len = other.len;
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

char& String::operator[](size_t index)
{
	// TODO: Fix this
	if (index >= this->len)
	{
		return this->str[len - 1];
	}

	return this->str[index];
}

const char& String::operator[](size_t index) const
{
	// TODO: Fix this
	if (index >= this->len)
	{
		return this->str[len - 1];
	}

	return this->str[index];
}


std::ostream& operator<<(std::ostream& os, const String& rhs)
{
	os << rhs.c_str();
	return os;
}

std::istream& operator>>(std::istream& is, String& rhs)
{
	char buffer[BUFFER_LENGTH];
	is.getline(buffer, BUFFER_LENGTH);

	if (!is)
	{
		// TODO: Handle
	}

	// TODO: This way we make unnecessary conversion to String and then invoke the operator=,
	// so an overload of operator= with const char* would be nice to have or make this friend function
	rhs = buffer;

	return is;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	// could use strcmp in this case, but generally this is a viable approach
	return lhs < rhs || lhs == rhs;
}

bool operator>=(const String& lhs, const String& rhs)
{
	return !(lhs < rhs);
}

bool operator>(const String& lhs, const String& rhs)
{
	return !(lhs <= rhs);
}


String& String::operator+=(const String& other)
{
	size_t newLen = this->len + other.len;
	char* result = new char[newLen + 1];

	strcpy(result, this->str);
	strcat(result, other.str);

	free();

	this->str = result;
	this->len = newLen;

	return *this;
}


String operator+(const String& lhs, const String& rhs)
{
	// not so optimal, could make it better with a friend function (to avoid allocations)
	String result = lhs;
	result += rhs;
	return result;
}

String::String(size_t len) : len(len), str(new char[len + 1]) { str[len] = '\0'; }

String String::of(char c)
{
	String result(2);
	result.len = 1;
	result.str[0] = c;
	return result;
}

String String::of(size_t num)
{
	if (num == 0)
	{
		return "0";
	}

	size_t index = getNumLength(num);
	String result(index);
	index--;
	while (num > 0)
	{
		result.str[index--] = num%10 + NUM_TO_CHAR_CONVERTION;
		num /= 10;
	}

	return result;
}

bool String::empty() const
{
	return len == 0;
}

String String::createEmpty()
{
	return String();
}

size_t String::hash() const
{
	return std::hash<std::string>{}(this->str);
}