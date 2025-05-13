#include "MyString.h"
#include <iostream>
#pragma warning(disable:4996)

void MyString::free()
{
	delete[] str;
	size = 0;
}

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	str = new char[size + 1];
	strcpy(str, other.str);
}

void MyString::moveFrom(MyString&& other)
{
	size = other.size;
	str = other.str;
	other.str = nullptr;
	other.size = 0;
}

MyString::MyString()
{
	str = nullptr;
	size = 0;
}

MyString::MyString(const char* str)
{
	size = strlen(str);
	this->str = new char[size + 1];
	strcpy(this->str, str);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::MyString(MyString&& other)
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

const char* MyString::getAsChar() const
{
	return str;
}

size_t MyString::getLen() const
{
	return size;
}

void MyString::setStr(const char* str)
{
	size = strlen(str);
	delete[] this->str;
	this->str = new char[size + 1];
	strcpy(this->str, str);
}
