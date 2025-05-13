#ifndef _SORTEDSTUDENTDB_H
#define _SORTEDSTUDENTDB_H

#include "StudentDB.h"

enum class SortCriteria {
    NAME,
    FACULTY_NUMBER,
    YEAR
};

class SortedStudentDB : public StudentDB {
public:
    SortedStudentDB();
    SortedStudentDB(const Student* students, size_t dbSize, size_t dbCapacity);
    void sortBy(SortCriteria criteria);
};

#endif // !_SORTEDSTUDENTDB_H