#include "StudentDB.h"

void StudentDB::setStudentDB(const Student* students, size_t dbSize, size_t dbCapacity) {
    if (students == nullptr) {
        throw std::invalid_argument("StudentDB cannot be null!");
    }

    if (dbSize > dbCapacity) {
        throw std::invalid_argument("The size of the database cannot be greater than the capacity!");
    }

    this->freeStudentDB();

    this->dbCapacity = dbCapacity;
    this->dbSize = dbSize;
    this->students = new Student[dbCapacity];
    for (size_t i = 0; i < dbSize; ++i) {
        this->students[i] = students[i];
    }
}

const Student* StudentDB::getStudentDB() const {
    return this->students;
}

size_t StudentDB::getDBSize() const {
    return this->dbSize;
}

size_t StudentDB::getDBCapacity() const {
    return this->dbCapacity;
}

void StudentDB::add(const Student& student) {
    if (this->dbSize >= this->dbCapacity) {
        this->resizeDB();
    }

    this->students[this->dbSize] = student;
    ++this->dbSize;
}

void StudentDB::remove(unsigned studentFacultyNumber) {
    for (size_t i = 0; i < this->dbSize; ++i) {
        if (this->students[i].getFacultyNumber() == studentFacultyNumber) {
            for (size_t j = i; j < this->dbSize - 1; ++j) {
                this->students[j] = this->students[j + 1];
            }
            --this->dbSize;
            return;
        }
    }

    throw std::invalid_argument("Student not found!");
}

Student* StudentDB::find(unsigned studentFacultyNumber) const {
    for (size_t i = 0; i < this->dbSize; ++i) {
        if (this->students[i].getFacultyNumber() == studentFacultyNumber) {
            return &this->students[i];
        }
    }

    throw std::invalid_argument("Student not found!");
}

void StudentDB::display() const {
    for (size_t i = 0; i < this->dbSize; ++i) {
        std::cout << "Student Name: " << this->students[i].getStudentName().getString() << ", Faculty Number: " << this->students[i].getFacultyNumber() << ", Year: " << this->students[i].getYear()
            << std::endl;
    }
}

StudentDB::StudentDB(const Student* students, size_t dbSize, size_t dbCapacity) {
    setStudentDB(students, dbSize, dbCapacity);
}

StudentDB::StudentDB() {
    this->dbSize = 0;
    this->dbCapacity = 1;
    this->students = new Student[this->dbCapacity];
}

StudentDB::StudentDB(const StudentDB& other) {
    this->copyFrom(other);
}

StudentDB& StudentDB::operator=(const StudentDB& other) {
    if (this != &other) {
        this->freeStudentDB();
        this->copyFrom(other);
    }

    return *this;
}

StudentDB::StudentDB(StudentDB&& other) noexcept {
    this->moveFrom(std::move(other));
}

StudentDB& StudentDB::operator=(StudentDB&& other) noexcept {
    if (this != &other) {
        this->freeStudentDB();
        this->moveFrom(std::move(other));
    }

    return *this;
}

StudentDB::~StudentDB() {
    this->freeStudentDB();
}

void StudentDB::setStudentDBSize(size_t dbSize) {
    this->dbSize = dbSize;
}

void StudentDB::resizeDB() {
    size_t newCapacity = this->dbCapacity * 2;
    Student* newStudents = new Student[newCapacity];

    for (size_t i = 0; i < this->dbSize; ++i) {
        newStudents[i] = this->students[i];
    }

    delete[] this->students;
    this->dbCapacity = newCapacity;
    this->students = newStudents;
}

void StudentDB::copyFrom(const StudentDB& other) {
    if (other.students == nullptr) {
        throw std::invalid_argument("StudentDB cannot be null!");
    }

    this->freeStudentDB();

    this->dbCapacity = other.dbCapacity;
    this->dbSize = other.dbSize;
    this->students = new Student[other.dbCapacity];
    for (size_t i = 0; i < other.dbSize; ++i) {
        this->students[i] = other.students[i];
    }
}

void StudentDB::moveFrom(StudentDB&& other) noexcept {
    this->students = other.students;
    this->dbSize = other.dbSize;
    this->dbCapacity = other.dbCapacity;

    other.students = nullptr;
    other.dbSize = 0;
    other.dbCapacity = 0;
}

void StudentDB::freeStudentDB() {
    delete[] this->students;
    this->students = nullptr;
    this->dbSize = 0;
    this->dbCapacity = 0;
}