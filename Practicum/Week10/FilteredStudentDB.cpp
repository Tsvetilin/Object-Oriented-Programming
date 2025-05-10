#include "FilteredStudentDB.h"

unsigned FilteredStudentDB::strToUnsigned(const MyString& str) const {
    unsigned result = 0;
    for (size_t i = 0; i < str.getLength(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            throw std::invalid_argument("Invalid number format in string!");
        }
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

void FilteredStudentDB::filter(FilterCriteria criteria, const MyString& value) {
    Student* filtered = new Student[getDBCapacity()];
    size_t newSize = 0;

    for (size_t i = 0; i < getDBSize(); ++i) {
        const Student& current = getStudentDB()[i];
        bool keep = false;

        switch (criteria) {
        case FilterCriteria::YEAR_EQUALS:
            keep = (current.getYear() == strToUnsigned(value));
            break;
        case FilterCriteria::FACULTY_NUMBER_LESS_THAN:
            keep = (current.getFacultyNumber() < strToUnsigned(value));
            break;
        case FilterCriteria::NAME_CONTAINS:
            keep = current.getStudentName().contains(value);
            break;
        }

        if (keep) {
            filtered[newSize++] = current;
        }
    }

    setStudentDB(filtered, newSize, newSize);
    delete[] filtered;
}

void FilteredStudentDB::limit(size_t N) {
    if (N < getDBSize()) {
        setStudentDBSize(N);
    }
}