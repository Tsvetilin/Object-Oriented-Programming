#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

namespace HelperFuncsNS
{
    size_t getFileSize(std::ifstream& ifs)
    {
        size_t currPos = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        size_t size = ifs.tellg();
        ifs.seekg(currPos);
        return size;
    }
}


        //Ex.1
namespace IntArrNS
{
    const char fileName[] = "intArr.dat";
    const size_t strLen = 1024;
    const uint8_t radix = 10;

    struct Nums
    {
        int* nums;
        size_t size;
    };

    Nums readArr()
    {
        size_t n;
        std::cin >> n;
        int* info = new int[n];
        for (size_t i = 0; i < n; i++)
        {
            std::cin >> info[i];
        }
        Nums nums = { info,n };
        return nums;
    }

    void writeToFile(const Nums& nums)
    {
       std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
       ofs.write((const char*)&nums, sizeof(Nums));
       ofs.close();
       delete[] nums.nums;
    }
    
    Nums readFromFile()
    {
        std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
        Nums num;
        ifs.read((char*)&num, sizeof(Nums));
        return num;
    }

    void print(const Nums num)
    {
        std::cout << "size: " << num.size << ",nums:";
        for (size_t i = 0; i < num.size; i++)
        {
            std::cout << num.nums[i] << "  ";
        }
        delete[] num.nums;
    }
}


        //Ex.2
namespace StudentNS
{
    const uint8_t nameLen= 50;
    const char fileName[] = "students.dat";

    struct StudentC
    {
        int id;
        char name[nameLen + 1];
        double grade;
    };

    StudentC createStudent()
    {
        StudentC student;
        std::cout << "Student id: ";
        std::cin >> student.id;
        std::cin.ignore();
        std::cout << "Student name: ";
        std::cin.getline(student.name, nameLen,'\n');
        std::cout << "Student grade: ";
        std::cin >> student.grade;
        std::cin.ignore();
        return student;
    }

    void writeToFile(StudentC stud)
    {
        std::ofstream ofs(fileName, std::ios::app | std::ios::binary);
        ofs.write((const char*)&stud, sizeof(StudentC));
        ofs.close();
    }

    StudentC* readFromFile(size_t& numberOfStudents)
    {
        std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
        size_t fileSize = HelperFuncsNS::getFileSize(ifs);
        std::cout << fileSize << '\t';
        numberOfStudents = fileSize / sizeof(StudentC);
        std::cout << "studCnt = " << numberOfStudents << std::endl;
        StudentC* students = new StudentC[numberOfStudents];
        for (size_t i = 0; i < numberOfStudents; i++)
        {
            ifs.read((char*)&students[i], sizeof(StudentC));
        }
        ifs.clear();
        return students;
    }

    void print(StudentC* stds,size_t len)
    {
        for (size_t i = 0; i < len; i++)
        {
            std::cout << "id:" << stds[i].id;
            std::cout << " name:" << stds[i].name;
            std::cout << " grade:" << stds[i].grade << std::endl;
        }
    }

    void selectionSort(StudentC*& students, bool(*compare)(const StudentC& std1, const StudentC& std2), size_t size)
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                if (compare(students[i], students[j]))
                {
                    std::swap(students[i], students[j]);
                }
            }
        }
    }

    enum class Criteria: uint8_t
    {
        SortByGrade,SortById,SortByName
    };

    void sortData(StudentC*& students,Criteria criteria,size_t size)
    {
        switch (criteria)
        {
         case Criteria::SortByGrade:
             return selectionSort(students, [](const StudentC& lhs, const StudentC& rhs) -> bool {return lhs.grade < rhs.grade; }, size);
            break;
        case Criteria::SortById:
            return selectionSort(students, [](const StudentC& lhs, const StudentC& rhs) -> bool {return lhs.id < rhs.id; }, size);
            break;
        case Criteria::SortByName:
            return selectionSort(students, [](const StudentC& lhs, const StudentC& rhs) -> bool {return strcmp(lhs.name,rhs.name) <=0; }, size);
            break;
        default:
            break;
        }
    }
}


        //Ex.3
namespace PizzaNS
{
    const uint8_t clientNameLen = 50;
    const uint8_t telNumberLen= 20;
    const uint8_t addressLen = 50; 
    const char ordersFileName[] = "orders.dat";
    const char sortedOrdersFileName[] = "sortedOrders.dat";
    enum class PizzaType
    {
        Margherita,Peperoni,Burata,Calcone
    };
    enum class PizzaSize
    {
        S,M,L
    };

    struct Pizza
    {
        PizzaType type;
        PizzaSize size;
    };
    struct Order
    {
        char clientName[clientNameLen];
        char telNumber[telNumberLen];
        char address[addressLen];
        double total;
        size_t pizzasCnt;
        Pizza* pizzas;
    };


    void writeToFile(Order* orders, size_t ordersCnt)
    {
        std::ofstream ofs(ordersFileName, std::ios::out | std::ios::binary);
        for (size_t i = 0; i < ordersCnt; i++)
        {
            ofs.write((const char*)&orders[i], sizeof(Order));
        }
        ofs.close();
    }

    Order* readFromFile()
    {
        std::ifstream ifs(ordersFileName, std::ios::in | std::ios::binary);
        size_t fileSize = HelperFuncsNS::getFileSize(ifs);
        Order* orders = new Order[fileSize / sizeof(Order)];
        for (size_t i = 0; i < fileSize / sizeof(Order); i++)
        {
            ifs.read((char*)&orders[i], sizeof(Order));
        }
        return orders;
    }

    void sortByAddress(Order*& orders, size_t ordersCnt)
    {
        for (size_t i = 0; i < ordersCnt; i++)
        {
            for (size_t j = i + 1; j < ordersCnt; j++)
            {
                if (strcmp(orders[i].address, orders[j].address) < 0)
                    std::swap(orders[i], orders[j]);
            }
        }
    }

    void writeSortedFile(Order* orders, size_t ordersCnt)
    {
        sortByAddress(orders, ordersCnt);
        std::ofstream ofs(sortedOrdersFileName, std::ios::out | std::ios::binary);
        for (size_t i = 0; i < ordersCnt; i++)
        {
            ofs.write((const char*)&orders[i], sizeof(Order));
        }
        ofs.close();
    }
}


        //Ex.4
namespace CensoerNS
{
    const size_t userDatLen = 504;
    struct A
    {
        size_t next;
        char userData[504];
    };

    void print(A a)
    {
        std::cout << a.next << ",data: " << a.userData;
    }

    void getInfo(std::ifstream& ifs)
    {
        A curr;
        while (true)
        {
            ifs.read((char*)&curr, sizeof(A));
            if (curr.next == 0)
            {
                return;
            }
            print(curr);
            ifs.seekg(curr.next * sizeof(A), std::ios::beg);
        }
    }
}

int main()
{
}
