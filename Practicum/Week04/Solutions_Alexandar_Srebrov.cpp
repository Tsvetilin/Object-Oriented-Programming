#include <iostream>
#include <fstream>
#pragma warning (disable:4996)


                //Ex.1
namespace TecherNS
{

    const size_t nameLen = 1024;
    const uint8_t minAge = 17;
    const uint8_t maxAge = 70;
    enum class Subjects
    {
        MAT,BEL,BIO,CHE,PE,PHY
    };
   
    class Teacher
    {
    private:
        char name[nameLen+1];
        unsigned age;
        Subjects subject;
        size_t salary;

    public:
         
        Teacher() 
        {
            strcpy(this->name, "");
            this->age = 0;
            this->subject = Subjects(0);
            this->salary = 0;
        };
        Teacher(char* input)
        {
            strcpy(this->name, input);
            this->age = 0;
            this->subject = Subjects(0);
            this->salary = 0;
        }
        Teacher(unsigned num)
        {
            this->age = num;
            strcpy(this->name, "");
            this->subject = Subjects(0);
            this->salary = 0;
        }

        const char* getName() const
        {
            return this->name;
        }
        unsigned getAge() const
        {
            return this->age;
        }
        Subjects getSub() const
        {
            return this->subject;
        }
        size_t getSalary() const
        {
            return this->salary;
        }

        void setName(char* str)
        {
            if (strlen(str) > nameLen)
            {
                std::cout << "Too long!";
                return;
            }
            strcpy(this->name, str);
        }
        void setAge(short n)
        {
            if (n<minAge || n > maxAge)
            {
                std::cout << "Invalid age!";
                return;
            }
            this->age = n;
        }
        void setSubj(Subjects subj)
        {
            this->subject = subj;
        }
        void setSalary(size_t sal)
        {
            if (sal < 500)
            {
                std::cout << "Too low salary!";
                return;
            }
            this->salary = sal;
        }
    };

}


                //Ex.2
namespace ExerciseNS
{
    const size_t taskLen = 1024;
    const uint8_t passwordLen = 16;
    const char fileName[] = "exercises.dat";

    enum class Answers
    {
        a,b,c,d
    };

    class Exercise
    {
    private:
        char task[taskLen + 1];
        Answers rightAnswer;
        size_t points;
        char pass[passwordLen +1];
        bool checkPass(const char* str) const
        {
            return !strcmp(this->pass, str);
        }

    public:
        char* getTask() const
        {
            return (char*)this->task;
        }
        Answers getRightAnswer() const { return this->rightAnswer; };
        size_t getPoints() const { return this->points; };

        Exercise() 
        {
            this->points = 0;
            strcpy(this->pass, "");
            strcpy(this->task, "");
            this->rightAnswer = Answers(0);
        };
        Exercise(const char* str, Answers ans, size_t points, const char* pass)
        {
            if (!str || !pass) { std::cout << "Wrong input"; Exercise(); return; };
            strcpy(this->task, str);
            this->rightAnswer = ans;
            this->points = points;
            strcpy(this->pass, pass);
        }
        void changeTask(Exercise exercise, const char* newTask, const char* pass)
        {
            if (!checkPass(pass)) { std::cout << "Wrong pass!"; return; }
            if (newTask != nullptr) { strcpy(exercise.task, newTask); };
        }
        void changeRightAnswer(Exercise exercise, Answers ans,const char* pass) 
        { 
            if (!checkPass(pass))
            { 
                std::cout << "Wrong pass!"; return; 
            } 
            exercise.rightAnswer = ans; 
        }
        void changePoints(Exercise exercise, size_t points, const char* pass) 
        { 
            if (!checkPass(pass)) 
            {
                std::cout << "Wrong pass!"; return; 
            } 
            exercise.points = points; 
        }
    };

    class Exam
    {
    public:
        void writeToFile() 
        {
            std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
            if (!ofs.is_open())
            {
                std::cout << "Couldnt open file!";
                return;
            }
            ofs.write((const char*)&this->exercisesCnt, sizeof(size_t));
            for (size_t i = 0; i < this->exercisesCnt; i++)
            {
                ofs.write((const char*)&this->exercises[i], sizeof(Exercise));
            }
            ofs.close();
        }
        void readFromFile()
        {
            std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
            if (!ifs.is_open())
            {
                std::cout << "Couldnt open file!";
                return;
            }
            ifs.read((char*)&this->exercisesCnt, sizeof(size_t));
            for (size_t i = 0; i < this->exercisesCnt; i++)
            {
                ifs.read((char*)&this->exercises[i], sizeof(Exercise));
            }
            ifs.close();
        }
        size_t getMaxPoints()
        {
            size_t res = 0;
            for (size_t i = 0; i < this->exercisesCnt; i++)
            {
                res += this->exercises[i].getPoints();
            }
            return res;
        }
        void setExs(Exercise* ex)
        {
            this->exercises = ex;
        }
        void setCnt(size_t a)
        {
            this->exercisesCnt = a;
        }
    private:
        Exercise* exercises;
        size_t exercisesCnt;
    };
}     


                //Ex.3
namespace GameNS
{
    const size_t titleLen = 64;
    const size_t libraryLen = 128;
    const size_t lineLen =  1024;
    const char fileName[] = "games.txt";

    class Game
    {
    public:
        void setTitle(const char* str)
        {
            if (!str) { std::cout << "Error"; return; };
            strcpy(this->title, str);
        }
        void setPrice(double price) { this->price = price; }
        void setAvailability(bool availability) { this->isAvailable = availability; }

        Game()
        {
            setTitle("");
            setPrice(0);
            setAvailability(false);
        }
        Game(const char* str)
        {
            if (!str) { std::cout << "nullptr given"; return; }
            setTitle(str);
            setPrice(0);
            setAvailability(false);
        }
        Game(double price)
        {
            setTitle("");
            setPrice(price);
            setAvailability(false);
        }
        Game(const char* str, double price)  
        {
            if (!str) { std::cout << "nullptr given"; return; }
            setTitle(str);
            setPrice(price);
            setAvailability(false);
        }
        Game(const char* str, double price, bool available)
        {
            if (!str) { std::cout << "nullptr given"; return; }
            setTitle(str);
            setPrice(price);
            setAvailability(available);
        }

        char* getTitle() const{ return (char*)this->title; }
        double getPrice() const{ return this->price; }
        double getAvailability() const{ return this->isAvailable; }

        bool isFree() { return !this->price; }
        void print()
        {

            std::cout << "Game title:" << this->title << ", price:" << this->price << ", availability:";
            if (this->isAvailable)  std::cout << "yes";
            else std::cout << "no";
            std::cout << std::endl;
        }

    private:
        char title[titleLen + 1];
        double price;
        bool isAvailable;
    };

    class GamePlatform
    {
    public:
        void addGame(Game game) 
        {
            if (gamesCnt >= libraryLen)
            {
                std::cout << "Limit of library reached";
                return;
            }
            this->libarary[this->gamesCnt++] = game; 
        }
        Game getGame(size_t index)
        {
            if(index >= this->gamesCnt)
            {
                std::cout << "Index exceeds games count!";
                return nullptr;
            }
            return this->libarary[index];
        }
        void printAllGames()
        {
            for (size_t i = 0; i < this->gamesCnt; i++)
            {
                this->libarary[i].print();
            }
        }
        void specificGame(bool(*compare)(double lhs, double rhs))
        {
            size_t index = 0;
            for (size_t i = 0; i < this->gamesCnt; i++)
            {
                if (compare(this->libarary[i].getPrice(), this->libarary[index].getPrice()))
                    index = i;
            }
            this->libarary[index].print();
        }
        enum class Criteria
        {
            getMostExpensive,getCheapest
        };
        void getSpecificGame(Criteria info)
        {
            switch (info)
            {
            case GameNS::GamePlatform::Criteria::getMostExpensive:
                return specificGame([](double a, double b) {return a > b; });
                break;
            case GameNS::GamePlatform::Criteria::getCheapest:
                return specificGame([](double a, double b) {return a < b; });
                break;
            default:
                break;
            }
        }
        void getAllFreeGames()
        {
            for (size_t i = 0; i < this->gamesCnt; i++)
            {
                if (this->libarary[i].isFree()) this->libarary[i].print();
            }
        }
        void removeGame(size_t index)
        {
            size_t counter = 0;
            for (size_t i = 0; i < this->gamesCnt; i++)
            {
                if (i == index) continue;
                this->libarary[counter++] = this->libarary[i];
            }
            this->gamesCnt--;
        }
        void addToTxtFile()
        {
            std::ofstream ofs(fileName, std::ios::app);
            if (!ofs.is_open()) { std::cout << "Couldnt open file!"; return; }
            for (size_t i = 0; i < this->gamesCnt; i++)
            {
                ofs << "Game title:" << this->libarary[i].getTitle() << ",price:" << this->libarary[i].getPrice() << ",availability:";
                if (this->libarary[i].getAvailability())  ofs << "yes";
                else ofs << "no";
                ofs << std::endl;
            }
            ofs.close();
        }
        size_t getFileLines(std::ifstream& ifs)
        {
            size_t cnt = 0;
            while (!ifs.eof())
            {
                ifs.ignore(lineLen,'\n');
                cnt++;
            }

            return cnt;
        }
        void getFromTxtFile()
        {
            std::ifstream ifs(fileName);
            this->gamesCnt = getFileLines(ifs);
            ifs.seekg(0, std::ios::beg);
            char ignore[lineLen];
            char title[lineLen];
            double price;
            char availability[lineLen];
            for (size_t i = 0; i < this->gamesCnt; i++)
            {
                ifs.getline(ignore, lineLen, ':');
                ifs.getline(title, lineLen, ',');
                ifs.getline(ignore, lineLen, ':');
                ifs >> price;
                ifs.getline(ignore, lineLen, ':');
                ifs.getline(availability, lineLen, '\n');
                this->libarary[i].setTitle(title);
                this->libarary[i].setPrice(price);
                this->libarary[i].setAvailability(strcmp(availability,"yes") == 0);
            }
            ifs.close();
        }

    private:
        Game libarary[libraryLen];
        size_t gamesCnt = 0;
    };
}

int main() {

}

