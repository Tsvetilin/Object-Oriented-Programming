#include "String.h"

String::String(const char* str, size_t len) {
	setString(str, len);
}

String::String(const char* str) {
	setString(str, calcStrLen(str));
}

String::String() {
	this->len = 1;
	this->str = new char[this->len];
	this->str[0] = '\0';
}

String::String(const String& other) {
	this->copyFrom(other);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		this->free();
		this->copyFrom(other);
	}

	return *this;
}

String::String(String&& other) noexcept {
	this->moveFrom(std::move(other));
}

String& String::operator=(String&& other) noexcept {
	if (this != &other) {
		this->free();
		this->moveFrom(std::move(other));
	}

	return *this;
}

void String::setString(const char* str, size_t len) {
	if (str == nullptr) {
		throw std::invalid_argument("Your string cannot be null!");
	}
	this->len = len;
	this->str = new char[len + 1];
	myStrCpy(this->str, str);
}

const char* String::getString() const {
	return this->str;
}

size_t String::getLength(const char* str) const {
	return this->len;
}

size_t String::calcStrLen(const char* str) const {
	if (this->str == nullptr) {
		return -1;
	}

	int counter = 0;
	while (*str) {
		counter++;
		str++;
	}

	return counter;
}

void String::myStrCpy(char* dest, const char* src) {
	if (!src || !dest) {
		throw std::invalid_argument("Invalid input!");
	}

	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

void String::myStrCat(char* first, const char* second) {
	if (!first || second == nullptr) {
		throw std::invalid_argument("Invalid input!");
	}

	size_t firstLen = getLength(first);
	first += firstLen;
	myStrCpy(first, second);
}

int String::myStrCmp(const char* str1, const char* str2) const {
	if (!str1 || !str2) {
		return 128;
	}

	while ((*str1) == (*str2) && (*str1)) {
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

bool String::operator==(const String& str) const {
	return myStrCmp(this->str, str.getString()) == 0;
}

bool String::operator!=(const String& str) const {
	return myStrCmp(this->str, str.getString()) != 0;
}

void String::print() const {
	std::cout << this->str << std::endl;
}

void String::copyFrom(const String& other) {
	if (other.str == nullptr) {
		throw std::invalid_argument("Your string cannot be null!");
	}
	this->len = other.len;
	this->str = new char[other.len + 1];
	myStrCpy(this->str, other.str);
}

void String::moveFrom(String&& other) noexcept {
	this->len = other.len;
	this->str = other.str;

	other.len = 0;
	other.str = nullptr;
}

void String::free() {
	delete[] this->str;
	this->str = nullptr;
	this->len = 0;
}
