#ifndef _MYSTRING_H
#define _MYSTRING_H

#include<stdexcept>
#include<iostream>

class MyString {
public:
	MyString(const char* str, size_t len);
	MyString(const char* str);
	MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;
	~MyString();

	void setString(const char* str, size_t len);
	const char* getString() const;
	size_t getLength() const;

	size_t calcStrLen(const char* str) const;
	void myStrCpy(char* dest, const char* src) const;
	void myStrCat(char* first, const char* second) const;
	int myStrCmp(const char* str1, const char* str2) const;

	bool contains(const MyString& substr) const;

	bool operator==(const MyString& str) const;
	bool operator!=(const MyString& str) const;

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	MyString operator+(const MyString& other) const;
	MyString& operator+=(const MyString& other);

	bool operator<(const MyString& other) const;
	bool operator>(const MyString& other) const;
	bool operator<=(const MyString& other) const;
	bool operator>=(const MyString& other) const;

	MyString substring(size_t start, size_t length) const;
	void swap(MyString& other);

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);

private:
	char* str;
	size_t len;

	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other) noexcept;
	void free();
};

#endif // !_MYSTRING_H