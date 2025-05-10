#pragma once
#include "Student.h"


class StudentDB 
{
protected:
	Student* students;
	size_t size;

	void free();
	void copyFrom(const StudentDB& other);
	void moveFrom(StudentDB&& other);
public:
	StudentDB(Student* students,size_t size);
	StudentDB(const StudentDB& other);
	StudentDB& operator=(const StudentDB& other);
	StudentDB(StudentDB&& other) noexcept;
	StudentDB& operator=(StudentDB&& other) noexcept;
	~StudentDB();

	void add(Student student);
	void remove(unsigned fn);
	Student find(unsigned fn) const;
	void display() const;
};

