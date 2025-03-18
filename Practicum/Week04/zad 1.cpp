#include <iostream>
#pragma warning(disable : 4996) 

constexpr size_t MAX_NAME_SIZE = 100;
constexpr size_t MIN_AGE = 18;
constexpr size_t MAX_AGE = 70;
constexpr size_t MIN_SALARY = 500;

enum Subject {
	Maths,English,Literature,History,Geography
};

class Teacher {
	char name[MAX_NAME_SIZE] ="";
	size_t age = 0;
	Subject subj=Maths;
	size_t salary =500;
public:
	Teacher(const char* name,const size_t age, const Subject subj, const size_t salary) {
		if (strlen(name) > MAX_NAME_SIZE) {
			std::cout << "err";
			return;
		}
		strcpy(this->name, name);
		this->age = age;
		this->subj = subj;
		this->salary = salary;
	}
	size_t getAge() const{
		return age;
	}
	size_t getSalary() const{
		return salary;
	}
	const char* getName() const{
		return name;
	}
	Subject getSubj() const{
		return subj;
	}
	void setAge(const size_t age) {
		if (age<MIN_AGE || age>MAX_AGE) {
			std::cout << "Invalid age" << std::endl;
			return;
		}
		this->age = age;
	}
	void setName(const char* name) {

		strcpy(this->name, name);
	}

	void setSalary(const size_t salary) {

		if (salary < MIN_SALARY) {
			std::cout << "Invalid salary" << std::endl;
			return;
		}
		this->salary = salary;
	}

	void setSubj(const Subject subj) {
		this->subj = subj;
	}
};
