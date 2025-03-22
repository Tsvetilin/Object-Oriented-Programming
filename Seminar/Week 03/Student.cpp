#include <iostream>
#include <fstream>
#include <cstring>

class Student
{
    int age;
    char *name;

public:
    Student(int age, const char *name) : age(0), name(nullptr)
    {
        setAge(age);
        setName(name);
    }

    Student() : Student(0, nullptr)
    {
    }

    void setName(const char *name)
    {
        if (!isValidName(name))
            return;

        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setAge(int age)
    {
        if (age < 18 || age > 100)
        {
            return;
        }

        this->age = age;
    }

    int getAge() const
    {
        return this->age;
    }

    const char *getName() const
    {
        return this->name;
    }

    void print(std::ostream &o)
    {
        o << "{ \"name\": \"" << name << "\", \"age\": " << age << " }";
    }

    ~Student()
    {
        delete[] name;
    }

private:
    bool isValidName(const char *name)
    {
        if (name == nullptr)
        {
            return false;
        }

        bool isEmpty = true;
        bool hasOnlyAlphaChars = true;

        while (*name)
        {
            if ('a' <= *name <= 'z' || 'A' <= *name <= 'Z')
            {
                isEmpty = false;
            }
            else if (*name != ' ')
            {
                hasOnlyAlphaChars = false;
            }

            name++;
        }

        return !isEmpty && hasOnlyAlphaChars;
    }
};

int main()
{
    Student s(20, "Ivan Ivanov");
    s.print(std::cout);
    std::cout << std::endl;

    s.setName("Pesho");
    s.print(std::cout);
    std::cout << std::endl;

    s.setAge(21);
    s.print(std::cout);
    std::cout << std::endl;

    s.setAge(-25);
    s.print(std::cout);
    std::cout << std::endl;

    std::ofstream file("student.json");
    if (file.is_open())
    {
        s.print(file);
        file.close();
    }

    return 0;
}