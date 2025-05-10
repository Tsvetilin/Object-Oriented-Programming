#include "SortedStudentDB.h"

SortedStudentDB::SortedStudentDB() : StudentDB() {}

SortedStudentDB::SortedStudentDB(const Student* students, size_t dbSize, size_t dbCapacity): StudentDB(students, dbSize, dbCapacity) {}

bool compareByName(const Student& a, const Student& b) {
    return a.getStudentName() < b.getStudentName();
}

bool compareByFacultyNumber(const Student& a, const Student& b) {
    return a.getFacultyNumber() < b.getFacultyNumber();
}

bool compareByYear(const Student& a, const Student& b) {
    return a.getYear() < b.getYear();
}

void SortedStudentDB::sortBy(SortCriteria criteria) {
    Student* students = const_cast<Student*>(getStudentDB());
    size_t size = getDBSize();

    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            bool shouldSwap = false;
            if (criteria == SortCriteria::NAME) {
                shouldSwap = compareByName(students[j], students[i]);
            }
            else if (criteria == SortCriteria::FACULTY_NUMBER) {
                shouldSwap = compareByFacultyNumber(students[j], students[i]);
            }
            else if (criteria == SortCriteria::YEAR) {
                shouldSwap = compareByYear(students[j], students[i]);
            }

            if (shouldSwap) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}