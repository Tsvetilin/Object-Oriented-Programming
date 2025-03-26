#include<iostream>
#include<cstring>
#include<fstream>

#pragma warning(disable:4996)

//Exercise 1
constexpr int MAX_TEACHER_NAME = 500;
constexpr int MIN_TEACHER_AGE = 18;
constexpr int MAX_TEACHER_AGE = 70;
constexpr int MIN_TEACHER_SALARY = 500;

enum class SchoolSubjects {
	Mathematics,
	History,
	Physics,
	Chemistry,
	Philosophy,
	Biology,
	PE,
	EnglishLanguage,
	BulgarianLanguageAndLiterature,
	FrenchLanguage,
	GermanLanguage,
	RussianLanguage,
	SpanishLanguage,
	Arts,
	Music,
	HomeAndTechnology,
	ITC,
	Informatics,
	Geography
};

class Teacher {
private:
	char name[MAX_TEACHER_NAME + 1];
	int age;
	SchoolSubjects subject;
	double salary;

	void copy(const Teacher& other) {
		strcpy(this->name, other.name);
		this->age = other.age;
		this->subject = other.subject;
		this->salary = other.salary;

		if (!(other.age >= MIN_TEACHER_AGE && other.age <= MAX_TEACHER_AGE && other.salary >= MIN_TEACHER_SALARY)) {
			std::cerr << "Invalid input! The age of the teacher must be between " << MIN_TEACHER_AGE << " and " << MAX_TEACHER_AGE << " and their salary must be equal to or above " << MIN_TEACHER_SALARY << "lv.!" << std::endl;
			return;
		}
	}

public:
	//Constructors
	Teacher(const char* _name, int _age, SchoolSubjects _subject, double _salary) {
		strcpy(this->name, _name);
		this->age = _age;
		this->subject = _subject;
		this->salary = _salary;

		if (!(_age >= MIN_TEACHER_AGE && _age <= MAX_TEACHER_AGE && _salary >= MIN_TEACHER_SALARY)) {
			std::cerr << "Invalid input! The age of the teacher must be between " << MIN_TEACHER_AGE << " and " << MAX_TEACHER_AGE << " and their salary must be equal to or above 500 lv.!" << std::endl;
			return;
		}
	}

	Teacher() {
		strcpy(this->name, "");
		this->age = 18;
		this->subject = SchoolSubjects::Mathematics;
		this->salary = 500;
	}

	Teacher(char _name[MAX_TEACHER_NAME + 1]) {
		strcpy(this->name, _name);
		this->age = 18;
		this->subject = SchoolSubjects::Mathematics;
		this->salary = 500;
	}

	//Copy-constructor
	Teacher(const Teacher& other) {
		copy(other);
	}

	//Setters
	void setName(const char* newName) {
		strcpy(this->name, newName);
	}

	void setAge(int newAge) {
		if (newAge >= MIN_TEACHER_AGE && newAge <= MAX_TEACHER_AGE) {
			this->age = newAge;
		}
		else {
			std::cerr << "Invalid input! The age of the teacher must be between " << MIN_TEACHER_AGE << " and " << MAX_TEACHER_AGE << "!" << std::endl;
			return;
		}
	}

	void setSubject(SchoolSubjects newSubject) {
		this->subject = newSubject;
	}

	void setSalary(double newSalary) {
		if (newSalary >= MIN_TEACHER_SALARY) {
			this->salary = newSalary;
		}
		else {
			std::cerr << "Invalid input! The salary of the teachers must be above or equal to " << MIN_TEACHER_SALARY << "lv.!" << std::endl;
			return;
		}
	}

	//Getters
	char* getName() {
		return this->name;
	}

	int getAge() {
		return this->age;
	}

	SchoolSubjects getSubject() {
		return this->subject;
	}

	double getSalary() {
		return this->salary;
	}

	const char* subjectToString(SchoolSubjects subject) {
		switch (subject) {
		case SchoolSubjects::Mathematics: return "Mathematics";
		case SchoolSubjects::Physics: return "Physics";
		case SchoolSubjects::Chemistry: return "Chemistry";
		case SchoolSubjects::Biology: return "Biology";
		case SchoolSubjects::History: return "History";
		case SchoolSubjects::Geography: return "Geography";
		case SchoolSubjects::BulgarianLanguageAndLiterature: return "Bulgarian Language and Literature";
		case SchoolSubjects::EnglishLanguage: return "English Language";
		case SchoolSubjects::PE: return "PE";
		case SchoolSubjects::Philosophy: return "Philosophy";
		case SchoolSubjects::FrenchLanguage: return "French Language";
		case SchoolSubjects::GermanLanguage: return "German Language";
		case SchoolSubjects::RussianLanguage: return "Russian Language";
		case SchoolSubjects::SpanishLanguage: return "Spanish Language";
		case SchoolSubjects::Arts: return "Arts";
		case SchoolSubjects::HomeAndTechnology: return "Home and Technology";
		case SchoolSubjects::Music: return "Music";
		case SchoolSubjects::Informatics: return "Informatics";
		case SchoolSubjects::ITC: return "ITC";
		default: return "Unknown";
		}
	}

	void printTeacherInfo() {
		std::cout << "Teacher name: " << this->name << std::endl;
		std::cout << "Teacher age: " << this->age << std::endl;
		std::cout << "Teacher subject: " << subjectToString(this->subject) << std::endl;
		std::cout << "Teacher salary: " << this->salary << std::endl;
		std::cout << std::endl;
	}
};

//Exercise 2
constexpr int MAX_PROBLEM_DESCRIPTION = 10000;
constexpr int MAX_NUMBER_OF_PROBLEMS = 16;

class Problem {
private:
	char problemDescription[MAX_PROBLEM_DESCRIPTION + 1];
	char correctAnswer;
	double points;
	char* password;

	void copy(const Problem& other) {
		strcpy(this->problemDescription, other.problemDescription);
		this->correctAnswer = other.correctAnswer;
		this->points = other.points;
		this->password = new char[strlen(other.password) + 1];
		strcpy(this->password, other.password);
	}

	void free() {
		delete[] this->password;
	}

public:
	//Setters
	void setProblemDescription(const char* _problemDescription) {
		strcpy(this->problemDescription, _problemDescription);
	}

	void setCorrectAnswer(char _correctAnswer) {
		this->correctAnswer = _correctAnswer;
	}

	void setPoints(int _points) {
		this->points = _points;
	}

	//Getters
	const char* getProblemDescription() {
		return this->problemDescription;
	}

	const char getCorrectAnswer() {
		return this->correctAnswer;
	}

	const int getPoints() {
		return this->points;
	}

	//Constructor
	Problem(const char* _problemDescription, char _correctAnswer, int _points, const char* _password) {
		setProblemDescription(_problemDescription);
		setCorrectAnswer(_correctAnswer);
		setPoints(_points);

		this->password = new char[strlen(_password) + 1];
		strcpy(this->password, _password);
	}

	//Default Constructor
	Problem() {
		setProblemDescription("");
		setCorrectAnswer(' ');
		setPoints(0);

		this->password = new char[1];
		strcpy(this->password, "");
	}

	//Copy Constructor
	Problem(const Problem& other) {
		copy(other);
	}

	//Operator=
	Problem& operator=(const Problem& other) {
		if (this != &other) {
			free();
			copy(other);
		}
		return *this;
	}

	//Destructor
	~Problem() {
		free();
	}

	//Print problem
	const void printProblem() {
		std::cout << "Problem Description: " << this->problemDescription << std::endl;
		std::cout << "Correct Answer: " << this->correctAnswer << std::endl;
		std::cout << "Points: " << this->points << std::endl;
		std::cout << std::endl;
	}
};

class Test {
private:
	Problem problems[MAX_NUMBER_OF_PROBLEMS];

	void copy(const Test& other) {
		for (size_t i = 0; i < MAX_NUMBER_OF_PROBLEMS; ++i) {
			problems[i] = other.problems[i];
		}
	}

public:
	//Setter
	void setProblems(Problem _problems[MAX_NUMBER_OF_PROBLEMS]) {
		for (int i = 0; i < MAX_NUMBER_OF_PROBLEMS; i++) {
			problems[i] = _problems[i];
		}
	}

	//Constructor
	Test(Problem _problems[MAX_NUMBER_OF_PROBLEMS]) {
		setProblems(_problems);
	}

	//Default Constructor
	Test() {
		for (int i = 0; i < MAX_NUMBER_OF_PROBLEMS; i++) {
			problems[i] = Problem();
		}
	}

	//Copy Constructor
	Test(const Test& other) {
		copy(other);
	}

	//Reading test from binary file
	//Reading a problem from the file
	Problem readProblem(std::ifstream& ifs) {
		Problem toReturn;
		ifs.read((char*)&toReturn, sizeof(Problem));
		return toReturn;
	}

	Problem readProblem(const char* filename) {
		if (!filename) {
			return Problem();
		}

		std::ifstream ifs(filename, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return Problem();
		}

		return readProblem(ifs);
	}

	//Reading all of the problems (the test) from the file
	Test readTest(std::ifstream& ifs) {
		Test toReturn;

		for (size_t i = 0; i < MAX_NUMBER_OF_PROBLEMS; ++i) {
			toReturn.problems[i] = readProblem(ifs);
		}

		ifs.close();
		return toReturn;
	}

	Test readTest(const char* filename) {
		if (!filename) {
			return Test();
		}

		std::ifstream ifs(filename, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return Test();
		}

		return readTest(ifs);
	}


	//Writing in file
	//Write each problem in the file
	void writeProblem(std::ofstream& ofs, const Problem& problem) {
		ofs.write((const char*)&problem, sizeof(Problem));
	}

	void writeProblem(const char* filename, const Problem& problem) {
		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return;
		}

		writeProblem(ofs, problem);
	}

	//Write all of the problems (the test) in the file
	void writeTest(std::ofstream& ofs, const Test& test) {
		for (size_t i = 0; i < MAX_NUMBER_OF_PROBLEMS; ++i) {
			writeProblem(ofs, test.problems[i]);
		}
	}

	void writeTest(const char* filename, const Test& test) {
		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return;
		}

		writeTest(ofs, test);
	}

	double getTestTotal() {
		double sum = 0;

		for (size_t i = 0; i < MAX_NUMBER_OF_PROBLEMS; ++i) {
			sum += problems[i].getPoints();
		}

		return sum;
	}

	const void displayTest() {
		std::cout << "Test: " << std::endl;
		for (int i = 0; i < MAX_NUMBER_OF_PROBLEMS; i++) {
			std::cout << "Problem " << i + 1 << ":" << std::endl;
			problems[i].printProblem();
		}
	}

};

//Exercise 3
constexpr int MAX_TITLE_LEN = 64;

class Game {
private:
	char title[MAX_TITLE_LEN + 1];
	double price;
	bool isAvailable;

	void copy(const Game& other) {
		strcpy(this->title, other.title);
		this->price = other.price;
		this->isAvailable = other.isAvailable;
	}

public:
	//Constructors
	Game(char* _title, double _price, bool _isAvailable) {
		strcpy(this->title, _title);
		this->price = _price;
		this->isAvailable = _isAvailable;
	}

	Game() {
		strcpy(this->title, "");
		this->price = 0;
		this->isAvailable = false;
	}

	//Copy constructor
	Game(const Game& other) {
		copy(other);
	}

	//Setters
	void setGameTitle(char* newTitle) {
		strcpy(this->title, newTitle);
	}

	void setGamePrice(double newPrice) {
		this->price = newPrice;
	}

	void setGameAvailability(bool newIsAvailable) {
		this->isAvailable = newIsAvailable;
	}

	//Getters
	char* getGameTitle() {
		return this->title;
	}

	double getGamePrice() {
		return this->price;
	}

	bool getGameAvailability() {
		return this->isAvailable;
	}

	bool isFree() {
		return this->price == 0;
	}

	void printGameInfo() {
		std::cout << "Game title: " << this->title << std::endl;
		std::cout << "Price: " << this->price << std::endl;
		std::cout << "Availability: " << (this->isAvailable ? "Yes" : "No") << std::endl;
		std::cout << std::endl;
	}
};

class GamePlatform {
private:
	Game* games;
	int capacity;

	void copy(const GamePlatform& other) {
		this->capacity = other.capacity;
		this->games = new Game[other.capacity];
		for (size_t i = 0; i < other.capacity; ++i) {
			this->games[i] = other.games[i];
		}
	}

	void free() {
		delete[] this->games;
	}
public:
	//Constructors
	GamePlatform(Game* _games, int _capacity) {
		this->capacity = _capacity;
		this->games = new Game[_capacity];
		for (size_t i = 0; i < _capacity; ++i) {
			this->games[i] = _games[i];
		}
	}

	GamePlatform() {
		this->capacity = 0;
		this->games = nullptr;
	}

	//Copy constructor
	GamePlatform(const GamePlatform& other) {
		this->copy(other);
	}

	//Operator=
	GamePlatform& operator=(const GamePlatform& other) {
		if (this != &other) {
			this->free();
			this->copy(other);
		}

		return *this;
	}

	//Destructor
	~GamePlatform() {
		delete[] this->games;
	}

	//We use this function to find if there is at least one free space in our game platform
	bool hasSpace() {
		for (size_t i = 0; i < this->capacity; ++i) {
			if (this->games[i].getGameTitle() == "") {
				return true;
			}
		}
		return false;
	}

	//Add a new game if there is space. If there isn't space, the game won't be added.
	void addGameToPlatform(Game newGame) {
		if (hasSpace()) {
			this->games[this->capacity] = newGame;
		}
		else {
			std::cerr << "There is not enough space in the game platform!" << std::endl;
			return;
		}
	}

	//Bonus: Add game by resizing
	/*void resizeGamePlatform(GamePlatform& gamePlatform) {
		if (gamePlatform.hasSpace()) {
			return;
		}

		size_t newCapacity = (gamePlatform.capacity == 0) ? 1 : gamePlatform.capacity * 2;

		Game* newGames = new Game[newCapacity];

		for (size_t i = 0; i < gamePlatform.capacity; ++i) {
			newGames[i] = gamePlatform.games[i];
		}

		for (size_t i = gamePlatform.capacity; i < newCapacity; ++i) {
			newGames[i] = Game();
		}

		delete[] gamePlatform.games;
		gamePlatform.games = newGames;
		gamePlatform.capacity = newCapacity;
	}

	void addGameWithResizing(GamePlatform& gamePlatform, const Game& newGame) {
		if (!gamePlatform.hasSpace()) {
			resizeGamePlatform(gamePlatform);
		}

		for (size_t i = 0; i < gamePlatform.capacity; ++i) {
			if (gamePlatform.games[i].getGameTitle() == "") {
				gamePlatform.games[i] = newGame;
				return;
			}
		}
	}*/

	//Find a game by its index.
	Game findGameAt(int index) {
		if (index > this->capacity) {
			std::cerr << "Invalid input! There aren't any games at such index!" << std::endl;
			return Game();
		}

		for (size_t i = 0; i < this->capacity; ++i) {
			if (i == index) {
				return this->games[i];
			}
		}
	}

	//Print the database.
	void printAllGamesInPlatform() {
		for (size_t i = 0; i < this->capacity; ++i) {
			std::cout << "Game " << i + 1 << ": " << std::endl;
			games[i].printGameInfo();
		}
	}

	//Find the cheapest game
	Game findCheapestGameInPlatform() {
		Game cheapest = games[0];

		for (size_t i = 0; i < this->capacity; ++i) {
			if (this->games[i].getGamePrice() < cheapest.getGamePrice()) {
				cheapest = this->games[i];
			}
		}

		return cheapest;
	}

	//Find the most expensive game
	Game findMostExpensiveGameInPlatform() {
		Game mostExpensive = games[0];

		for (size_t i = 0; i < this->capacity; ++i) {
			if (this->games[i].getGamePrice() > mostExpensive.getGamePrice()) {
				mostExpensive = this->games[i];
			}
		}

		return mostExpensive;
	}

	//Print all of the free games
	void printAllFreeGames() {
		std::cout << "Free games: " << std::endl;

		for (size_t i = 0; i < this->capacity; ++i) {
			if (this->games[i].isFree()) {
				games[i].printGameInfo();
			}
		}
	}

	//Remove game by its index
	void removeGameAt(int index) {
		if (index < 0 || index >= this->capacity) {
			std::cerr << "Invalid input! There are no games at this index!" << std::endl;
			return;
		}

		for (int i = index; i < this->capacity - 1; ++i) {
			this->games[i] = this->games[i + 1];
		}

		this->capacity--;
	}

	//Read from the file
	Game readGame(std::ifstream& ifs) {
		Game toReturn;
		ifs.read((char*)&toReturn, sizeof(Game));
		return toReturn;
	}

	Game readGame(const char* filename) {
		if (!filename) {
			return {};
		}

		std::ifstream ifs(filename, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return{};
		}

		return readGame(ifs);
	}

	//Write in the file
	void writeGame(std::ofstream& ofs, const Game& game) {
		ofs.write((const char*)&game, sizeof(Game));
	}

	void writeGame(const char* filename, const Game& game) {
		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return;
		}

		return writeGame(ofs, game);
	}

	//Read all games from the file
	GamePlatform readGamePlatform(std::ifstream& ifs) {
		GamePlatform toReturn;

		toReturn.capacity = this->capacity;
		toReturn.games = new Game[this->capacity];
		for (size_t i = 0; i < this->capacity; ++i) {
			toReturn.games[i] = readGame(ifs);
		}

		ifs.close();
		return toReturn;
	}

	GamePlatform readGamePlatform(const char* filename) {
		if (!filename) {
			return{};
		}

		std::ifstream ifs(filename, std::ios::in | std::ios::binary);
		if (!ifs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return{};
		}

		return readGamePlatform(ifs);
	}

	//Write all games in the file
	void writeGamePlatform(std::ofstream& ofs, const GamePlatform& gamePlatform) {
		for (size_t i = 0; i < gamePlatform.capacity; ++i) {
			writeGame(ofs, gamePlatform.games[i]);
		}
	}

	void writeGamePlatform(const char* filename, const GamePlatform& gamePlatform) {
		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::out | std::ios::binary);
		if (!ofs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return;
		}

		return writeGamePlatform(ofs, gamePlatform);
	}
};

int main() {
	//Exercise 1
	/*Teacher t1("Velina Ivanova", 27, SchoolSubjects::BulgarianLanguageAndLiterature, 1100);
	Teacher t2("Georgi Pavlov", 48, SchoolSubjects::Chemistry, 1500);

	t2.setAge(50);
	t2.setSubject(SchoolSubjects::Geography);

	t1.printTeacherInfo();
	t2.printTeacherInfo();*/

	//Exercise 2
	/*Problem problem1("What is 2 + 2?", '4', 5, "abcd1234");
	Problem problem2("What is the capital of France?", 'P', 10, "efgh5678");
	Problem problem3("Solve 3x + 5 = 14. What is x?", '3', 7, "ijkl91011");

	Problem problems[MAX_NUMBER_OF_PROBLEMS] = { problem1, problem2, problem3 };

	Test test(problems);

	test.writeTest("testfile.txt", test);

	Test readTest = test.readTest("testfile.txt");

	test.displayTest();

	double totalPoints = readTest.getTestTotal();
	std::cout << "Total points for the test: " << totalPoints << std::endl;*/

	//Exericse 3
	Game game1((char*)"The Witcher", 29.99, true);
	Game game2((char*)"Hollow Knight", 14.99, true);
	Game game3((char*)"Outlast 2", 0.0, true);
	Game game4((char*)"Resident Evil 7", 100.99, false);
	Game game5((char*)"Detroit: Become Human", 60.99, false);

	std::cout << "Game details:" << std::endl;
	game1.printGameInfo();
	game2.printGameInfo();
	game3.printGameInfo();
	game4.printGameInfo();
	game5.printGameInfo();

	Game gamesArray[] = { game1, game2, game3, game4, game5 };

	GamePlatform platform(gamesArray, 5);

	platform.printAllGamesInPlatform();

	Game cheapest = platform.findCheapestGameInPlatform();
	std::cout << "Cheapest game: " << std::endl;
	cheapest.printGameInfo();

	Game mostExpensive = platform.findMostExpensiveGameInPlatform();
	std::cout << "Most expensive game:" << std::endl;
	mostExpensive.printGameInfo();

	platform.printAllFreeGames();

	const char* filename = "games.txt";
	platform.writeGamePlatform(filename, platform);
	std::cout << "Games written to file successfully." << std::endl;

	GamePlatform loadedPlatform = platform.readGamePlatform(filename);
	std::cout << "Games read from file:" << std::endl;
	loadedPlatform.printAllGamesInPlatform();

	std::cout << "Removing game at index 2: " << std::endl;
	loadedPlatform.removeGameAt(2);
	std::cout << "Updated game list:" << std::endl;
	loadedPlatform.printAllGamesInPlatform();

	loadedPlatform.writeGamePlatform(filename, loadedPlatform);
	std::cout << "Updated game list written to file." << std::endl;

	return 0;
}
