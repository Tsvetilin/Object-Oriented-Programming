#ifndef _SCHOOL_H
#define _SCHOOL_H

#include "Student.h"

class School {
private:
	size_t studentsCount;
	Student* students;

	void copyFrom(const School& other);
	void free();

public:
	School(size_t studentsCount, Student* students);
	School();
	School(const School& other);
	School& operator=(const School& other);
	~School();

	void setStudentsCount(size_t newStudentsCount);
	void setStudents(Student* newStudents, size_t newStudentsCount);

	void studentsCountSetterForObj(const School& other);
	void studentsSetterForObj(const School& other);

	size_t getStudentsCount() const;
	const Student* getStudent() const;

	School readSchool(std::ifstream& ifs);
	void writeSchool(std::ofstream& ofs, const School& other);

	School readSchool(const char* filename);
	void writeSchool(const char* filename, const School& other);

	const void printSchoolInfo();
};

#endif // !_SCHOOL_H
