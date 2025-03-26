#ifndef _STUDENT_H
#define _STUDENT_H
#include<fstream>

constexpr int MAX_MOTTO_LEN = 30;

class Student {
private:
	char* name;
	size_t gradesCount;
	int* grades;
	char motto[MAX_MOTTO_LEN + 1];

	void copyFrom(const Student& other);
	void freeName();
	void freeGrades();
	void free();

public:
	Student(const char* name, size_t gradesCount, int* grades, const char* motto);
	Student();
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	void setName(const char* newName);
	void setGrades(int* newGrades, size_t newGradesCount);
	void setMotto(const char* newMotto);

	void nameSetterForObj(const Student& other);
	void gradesSetterForObj(const Student& other);
	void mottoSetterForObj(const Student& other);

	const char* getName() const;
	const int* getGrades() const;
	int getGradesCount() const;
	const char* getMotto() const;

	Student readStudent(std::ifstream& ifs);
	void writeStudent(std::ofstream& ofs, const Student& student);

	Student readStudent(const char* filename);
	void writeStudent(const char* filename, const Student& student);

	const void printStudent();
};

#endif // !_STUDENT_H
