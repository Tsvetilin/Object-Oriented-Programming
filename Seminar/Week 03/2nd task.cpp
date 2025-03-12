#include <iostream>
#include <fstream>
#include <cstring>


namespace StudentNS {

    struct StudentC {
        int id;
        char name[50];
        double grade;
    };

    StudentC CreateStudent() {
        StudentC toReturn;
        toReturn.id = 10;
        strcpy_s(toReturn.name, sizeof(toReturn.name), "Sesko");
        return toReturn;
    }

    StudentC* CreateMultipleStudents(int size) {
        StudentC* sArr = new StudentC[size];
        for (size_t i = 0; i < size; i++) {
            sArr[i] = CreateStudent();
        }
        return sArr;
    }

    void writeStudentsInFile(StudentC* s, std::ofstream& ofs, const int size) {
        ofs.write((const char*)&size, sizeof(size));
        for (size_t i = 0; i < size; i++) {
            ofs.write((const char*)&s[i], sizeof(s[i]));
        }
        delete[] s;
    }

    void writeStudentsInFile(StudentC* s, const char* filename, const int size) {
        if (!s || !filename) return;
        std::ofstream ofs(filename, std::ios::binary | std::ios::out);
        if (!ofs.is_open()) return;
        writeStudentsInFile(s, ofs, size);
    }

    StudentC* readStudentsFromBinary(std::ifstream& ifs) {
        int size;
        ifs.read((char*)&size, sizeof(size));
        StudentC* students = new StudentC[size];
        for (size_t i = 0; i < size; i++) {
            ifs.read((char*)&students[i], sizeof(StudentC));
        }
        return students;
    }

    StudentC* readStudentsFromBinary(const char* filename) {
        if (!filename) return nullptr;
        std::ifstream ifs(filename, std::ios::binary | std::ios::in);
        if (!ifs.is_open()) return nullptr;
        return readStudentsFromBinary(ifs);
    }

    void selectionSortByCriteria(StudentC* c, int numberofStudents, bool (*delta) (StudentC s1, StudentC s2)) {
        for (size_t i = 0; i < numberofStudents; i++)
        {
            int minIdx = i;
            for (size_t j = i+1; j < numberofStudents; j++)
            {
                if (delta(c[minIdx], c[j]))
                {
                    minIdx = j;
                }
            }
            std::swap(c[i], c[minIdx]);
        }
    }

    bool (*compareByName)(StudentC, StudentC) = [](StudentC s1, StudentC s2) -> bool {
        return std::strcmp(s1.name, s2.name) < 0;
        };


    bool (*compareByGrade)(StudentC, StudentC) = [](StudentC s1, StudentC s2) -> bool {
        return (s1.grade<s2.grade);
        };


}
int main() {
    using namespace StudentNS;

    int numStudents = 5;
    StudentC* students = CreateMultipleStudents(numStudents);
    writeStudentsInFile(students, "students.dat", numStudents);

    StudentC* readStudents = readStudentsFromBinary("students.dat");
    for (int i = 0; i < numStudents; i++) {
        std::cout << "ID: " << readStudents[i].id << ", Name: " << readStudents[i].name << ", Grade: " << readStudents[i].grade << std::endl;
    }

    delete[] readStudents;
    return 0;
}
