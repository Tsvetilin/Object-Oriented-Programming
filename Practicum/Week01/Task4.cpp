#include <iostream>

const int MAX_LENGTH = 50;
const int NUM_STUDENTS = 3;

enum class Major
{
    SE,
    IS,
    CS,
    AM,
    M,
    Inf
};

struct Student 
{
    double grade;
    int fn;
    char name[MAX_LENGTH];
    Major major;
};

struct Group
{
    Student students[NUM_STUDENTS];
    double average;
};

double calculateAverage (Group& group)
{
    double tempGrade = 0;
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        tempGrade += group.students[i].grade;
    }

    return tempGrade / NUM_STUDENTS;
}

void createGroup (Group& group)
{
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        std::cout << "Enter name, fn and average grade for student " << i + 1 << " :";
        std::cin >> group.students[i].name;
        std::cin >> group.students[i].fn;
        std::cin >> group.students[i].grade;

        int majorChoice;
        std::cout << "Enter major (0 - SE, 1 - IS, 2 - CS, 3 - AM, 4 - M, 5 - Inf): ";
        std::cin >> majorChoice;

        switch(majorChoice)
        {
            case 0: group.students[i].major = Major::SE;
            break;
            case 1: group.students[i].major = Major::IS;
            break;
            case 2: group.students[i].major = Major::CS; 
            break;
            case 3: group.students[i].major = Major::AM; 
            break;
            case 4: group.students[i].major = Major::M; 
            break;
            case 5: group.students[i].major = Major::Inf; 
            break;
            default:
                std::cout << "Invalid major choice\n";
                return;
        }
    }

    group.average = calculateAverage (group);
}

int countScholarshipStudents(const Group& group, double minGrade)
{
    int countStudents = 0;
    double eps = 1e-9;

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        if (group.students[i].grade + eps >= minGrade)
        {
            countStudents++;
        }
    }

    return countStudents;
}

void swapStudents(Student& s1, Student& s2)
{
    Student temp = s1;
    s1 = s2;
    s2 = temp;
}

void sortStudentsByGrades(Group& group)
{
    for (int i = 0; i < NUM_STUDENTS - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < NUM_STUDENTS; j++)
        {
            if (group.students[j].grade > group.students[maxIndex].grade)
            {
                maxIndex = j;
            }
        }

        if (maxIndex != i)
        {
            swapStudents(group.students[i], group.students[maxIndex]);
        }
    }
}

void printScholarshipStudentsSorted(Group& group, double minGrade)
{
    sortStudentsByGrades(group);

    std::cout << "Students receiving a scholarship (sorted by grade):" << std::endl;;
    bool found = false;
    double eps = 1e-9;

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        if (group.students[i].grade + eps >= minGrade)
        {
            std::cout << "Faculty Number: " << group.students[i].fn
                      << " | Grade: " << group.students[i].grade << std::endl;
            found = true;
        }
    }

    if (!found)
        std::cout << "No students qualify for a scholarship." << std::endl;;
}

int main()
{
    Group group;
    createGroup(group);
    std::cout << "Group average grade: " << group.average << std::endl;

    double minGrade;
    std::cout << "Enter minimum grade for scholarship: ";
    std::cin >> minGrade;
    printScholarshipStudentsSorted(group, minGrade);

}