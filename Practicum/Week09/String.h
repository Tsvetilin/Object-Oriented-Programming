#ifndef _STRING_H
#define _STRING_H

#include<stdexcept>
#include<iostream>

class String {
public:
	String(const char* str, size_t len);
	String(const char* str);
	String();
	String(const String& other);
	String& operator=(const String& other);
	String(String&& other) noexcept;
	String& operator=(String&& other) noexcept;

	void setString(const char* str, size_t len);
	const char* getString() const;

	size_t getLength(const char* str) const;
	size_t calcStrLen(const char* str) const;
	void myStrCpy(char* dest, const char* src);
	void myStrCat(char* first, const char* second);
	int myStrCmp(const char* str1, const char* str2) const;

	bool operator==(const String& str) const;
	bool operator!=(const String& str) const;

	void print() const;

private:
	char* str;
	size_t len;

	void copyFrom(const String& other);
	void moveFrom(String&& other) noexcept;
	void free();
};

#endif // !_STRING_H
