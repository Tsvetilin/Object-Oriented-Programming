#include "MyString.h"

void MyString::setString(const char* str, size_t len) {
    if (!str) {
        throw std::invalid_argument("String cannot be null!");
    }

    this->free();

    this->len = len;
    this->str = new char[len + 1];

    for (size_t i = 0; i < len; ++i) {
        this->str[i] = str[i];
    }
    this->str[len] = '\0';
}

const char* MyString::getString() const {
    return this->str;
}

size_t MyString::getLength() const {
    return this->len;
}

size_t MyString::calcStrLen(const char* str) const {
    if (!str) {
        return 0;
    }

    size_t counter = 0;

    while (*str++) {
        counter++;
    }

    return counter;
}

void MyString::myStrCpy(char* dest, const char* src) const {
    if (!src) {
        throw std::invalid_argument("myStrCpy: source string is null");
    }
    if (!dest) {
        throw std::invalid_argument("myStrCpy: destination string is null");
    }

    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void MyString::myStrCat(char* first, const char* second) const {
    if (!first || !second) {
        throw std::invalid_argument("myStrCat: one of the strings is null");
    }

    while (*first) {
        ++first;
    }

    while (*second) {
        *first++ = *second++;
    }

    *first = '\0';
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

bool MyString::contains(const MyString& substr) const {
    if (substr.getLength() == 0 || substr.getLength() > this->getLength()) {
        return false;
    }

    for (size_t i = 0; i <= this->getLength() - substr.getLength(); ++i) {
        size_t j = 0;
        while (j < substr.getLength() && this->str[i + j] == substr[j]) {
            ++j;
        }
        if (j == substr.getLength()) {
            return true;
        }
    }

    return false;
}

bool MyString::operator==(const MyString& str) const {
    return myStrCmp(this->str, str.getString()) == 0;
}

bool MyString::operator!=(const MyString& str) const {
    return myStrCmp(this->str, str.getString()) != 0;
}

char& MyString::operator[](size_t index) {
    if (index >= this->len ) {
        throw std::out_of_range("Index out of bounds");
    }

    return this->str[index];
}

const char& MyString::operator[](size_t index) const {
    if (index >= this->len) {
        throw std::out_of_range("Index out of bounds");
    }

    return this->str[index];
}

MyString MyString::operator+(const MyString& other) const {
    size_t newLen = this->len + other.len;
    char* newStr = new char[newLen + 1];

    myStrCpy(newStr, this->str);
    myStrCat(newStr, other.str);

    MyString result(newStr, newLen);
    delete[] newStr;

    return result;
}

MyString& MyString::operator+=(const MyString& other) {
    size_t newLen = len + other.len;
    char* newStr = new char[newLen + 1];

    myStrCpy(newStr, str);

    myStrCat(newStr, other.str);

    delete[] str;

    str = newStr;
    len = newLen;

    return *this;
}

bool MyString::operator<(const MyString& other) const {
    return myStrCmp(str, other.str) < 0;
}

bool MyString::operator>(const MyString& other) const {
    return myStrCmp(str, other.str) > 0;
}

bool MyString::operator<=(const MyString& other) const {
    return myStrCmp(str, other.str) <= 0;
}

bool MyString::operator>=(const MyString& other) const {
    return myStrCmp(str, other.str) >= 0;
}

MyString MyString::substring(size_t start, size_t length) const {
    if (start > len) {
        throw std::out_of_range("Start index out of range");
    }

    if (start + length > len) {
        length = len - start;
    }

    char* subStr = new char[length + 1];

    for (size_t i = 0; i < length; ++i) {
        subStr[i] = str[start + i];
    }
    subStr[length] = '\0';

    MyString result(subStr);
    delete[] subStr;

    return result;
}

void MyString::swap(MyString& other) {
    char* tempStr = str;
    str = other.str;
    other.str = tempStr;

    size_t tempLen = len;
    len = other.len;
    other.len = tempLen;
}

void MyString::copyFrom(const MyString& other) {
    if (other.str == nullptr) {
        throw std::invalid_argument("String cannot be null!");
    }

    this->free();

    if (other.len < 0) {
        throw std::invalid_argument("The length of your string cannot be 0!");
    }

    if (other.len == 0) {
        this->str = new char[1];
        this->str[0] = '\0';
        this->len = 0;
        return;
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

MyString::MyString(const char* str, size_t len) {
    setString(str, len);
}

MyString::MyString(const char* str) {
    setString(str, calcStrLen(str));
}

MyString::MyString() {
    this->len = 0;
    this->str = new char[1];
    this->str[0] = '\0';
}

MyString::MyString(const MyString& other) {
    this->copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

MyString::MyString(MyString&& other) noexcept {
    this->moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveFrom(std::move(other));
    }

    return *this;
}

MyString::~MyString() {
    this->free();
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    if (str.str != nullptr) {
        os << str.str;
    }
    else {
        os << "";
    }
    return os;
}
