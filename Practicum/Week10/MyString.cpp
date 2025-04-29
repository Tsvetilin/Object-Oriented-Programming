#include "MyString.h"
#include <iostream>
#include <stdexcept>

void MyString::setString(const char* str, size_t len) {
    if (str == nullptr) {
        throw std::invalid_argument("Your string cannot be null!");
    }

    if (len == 0) {
        this->str = new char[1];
        this->str[0] = '\0';
        this->len = 0;
        return;
    }

    this->len = len;
    this->str = new char[len + 1];
    myStrCpy(this->str, str);
}


const char* MyString::getString() const {
    return this->str;
}

size_t MyString::getLength() const {
    return this->len;
}

size_t MyString::calcStrLen(const char* str) const {
    if (!str) return 0;

    size_t counter = 0;
    while (*str++) counter++;

    return counter;
}

void MyString::myStrCpy(char* dest, const char* src) {
    if (!src) throw std::invalid_argument("myStrCpy: source string is null");
    if (!dest) throw std::invalid_argument("myStrCpy: destination string is null");

    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void MyString::myStrCat(char* first, const char* second) {
    if (!first || !second) {
        throw std::invalid_argument("myStrCat: one or both inputs are null");
    }

    size_t firstLen = calcStrLen(first);
    myStrCpy(first + firstLen, second);
}

int MyString::myStrCmp(const char* str1, const char* str2) const {
    if (!str1 || !str2) {
        return 128;
    }

    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

bool MyString::operator==(const MyString& other) const {
    return myStrCmp(this->str, other.getString()) == 0;
}

bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

void MyString::print() const {
    std::cout << (str ? str : "[null]") << std::endl;
}

MyString::MyString(const char* str, size_t len) {
    setString(str, len);
}

MyString::MyString(const char* str) {
    setString(str, calcStrLen(str));
}

MyString::MyString() {
    this->len = 1;
    this->str = new char[this->len + 1];
    this->str[0] = ' ';
    this->str[1] = '\0';
}

MyString::MyString(const MyString& other) {
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString::MyString(MyString&& other) noexcept {
    moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void MyString::copyFrom(const MyString& other) {
    if (!other.str) {
        throw std::invalid_argument("copyFrom: other string is null");
    }

    this->len = other.len;
    this->str = new char[other.len + 1];
    myStrCpy(this->str, other.str);
}

void MyString::moveFrom(MyString&& other) noexcept {
    this->len = other.len;
    this->str = other.str;

    other.len = 0;
    other.str = nullptr;
}

void MyString::free() {
    delete[] this->str;
    this->str = nullptr;
    this->len = 0;
}