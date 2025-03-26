#include<iostream>
#include "Student.h"
#include "School.h"

int main() {
	Student* studentsArray = new Student[5]{
	Student("Alice Johnson", 5, new int[5] {5, 6, 4, 6, 5}, "Dream big!"),
	Student("Bob Smith", 4, new int[4] {3, 4, 5, 6}, "Keep going."),
	Student("Charlie Brown", 6, new int[6] {6, 6, 5, 6, 6, 4}, "Success is earned."),
	Student("Diana Prince", 3, new int[3] {4, 5, 6}, "Justice and knowledge."),
	Student("Ethan Carter", 5, new int[5] {5, 4, 4, 3, 5}, "Stay curious.")
	};

	School mySchool(5, studentsArray);

    std::ofstream outFile("school.txt", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing!\n";
        return 1;
    }
    mySchool.writeSchool(outFile, mySchool);
    outFile.close();

    std::cout << "Data written to file successfully!\n";

    std::ifstream inFile("school.txt", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading!\n";
        return 1;
    }

    School loadedSchool = mySchool.readSchool(inFile);
    inFile.close();

    mySchool.printSchoolInfo();
}
