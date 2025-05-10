#ifndef _STUDENTDB_H
#define _STUDENTDB_H

#include <iostream>
#include <stdexcept>
#include "Student.h"

class StudentDB {
public:
    StudentDB(const Student* students, size_t dbSize, size_t dbCapacity);
    StudentDB();
    StudentDB(const StudentDB& other);
    StudentDB& operator=(const StudentDB& other);
    StudentDB(StudentDB&& other) noexcept;
    StudentDB& operator=(StudentDB&& other) noexcept;
    ~StudentDB();
    
    void setStudentDBSize(size_t dbSize);
    void setStudentDB(const Student* students, size_t dbSize, size_t dbCapacity);

    const Student* getStudentDB() const;
    size_t getDBSize() const;
    size_t getDBCapacity() const;

    void add(const Student& student);
    void remove(unsigned studentFacultyNumber);
    Student* find(unsigned studentFacultyNumber) const;
    void display() const;

private:
    Student* students;
    size_t dbSize;
    size_t dbCapacity;

    void resizeDB();
    void copyFrom(const StudentDB& other);
    void moveFrom(StudentDB&& other) noexcept;
    void freeStudentDB();
};

#endif // !_STUDENTDB_H