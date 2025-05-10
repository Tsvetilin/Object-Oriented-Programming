#ifndef _FILTEREDSTUDENTDB_H
#define _FILTEREDSTUDENTDB_H

#include "StudentDB.h"
#include "MyString.h"

enum class FilterCriteria {
    YEAR_EQUALS,
    FACULTY_NUMBER_LESS_THAN,
    NAME_CONTAINS
};

class FilteredStudentDB : public StudentDB {
public:
    void filter(FilterCriteria criteria, const MyString& value);
    void limit(size_t N);

private:
    unsigned strToUnsigned(const MyString& str) const;
};

#endif // !_FILTEREDSTUDENTDB_H