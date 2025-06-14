#pragma once
class MyString
{
private:
	size_t size;
	char* str;

	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other);
	MyString& operator=(MyString&& other);
	~MyString();

	const char* getAsChar() const;
	size_t getLen() const;
	void setStr(const char* str);
};

