#include<iostream>
#include<fstream>
#include<cstring>

#pragma warning(disable:4996)

//За решаването на задачите са използвани: https://github.com/Tsvetilin/Object-Oriented-Programming/blob/main/Practicum/Week03/Theory.md,
//https://github.com/Tsvetilin/Object-Oriented-Programming/blob/main/Practicum/Week03/sorting.cpp,
//https://github.com/Tsvetilin/Object-Oriented-Programming/blob/main/Practicum/Week03/Records.cpp

//Exercise 1
void writeDynamicArrInFile(int* arr, int size, const char* filename) {
	std::ofstream file(filename, std::ios::in | std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}

	for (size_t i = 0; i < size; ++i) {
		file.write((const char*)&arr[i], sizeof(int));
	}

	std::cout << "The array has been written successfully in the file!" << std::endl;

	file.close();
}

int* readDynamicArrFromFile(int& size, const char* filename) {
	std::ifstream file(filename, std::ios::out | std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "Couldn't open file!" << std::endl;
		return nullptr;
	}

	int* arrRes = new int[size];

	for (size_t i = 0; i < size; ++i) {
		file.read((char*)&arrRes[i], sizeof(int));
	}

	file.close();

	return arrRes;
}

//Exercise 2
namespace Constants {
	constexpr size_t MAX_NAME_SIZE = 50;
	constexpr double EPS = 1e-6;
}

namespace SchoolNS
{
	using namespace Constants;

	enum class Criteria : uint8_t {
		SortByName,
		SortByGrade
	};

	struct Student {
		char name[MAX_NAME_SIZE + 1];
		int id;
		double grade;
	};

	Student initStudent(int id, const char* name, double grade) {
		if (!name || strlen(name) > MAX_NAME_SIZE) {
			return {};
		}

		Student toReturn;
		strcpy(toReturn.name, name);
		toReturn.id = id;
		toReturn.grade = grade;

		return toReturn;
	}

	Student readStudent(std::ifstream& ifs) {
		Student toReturn;
		ifs.read((char*)&toReturn, sizeof(Student));
		return toReturn;
	}

	void writeStudent(std::ofstream& ofs, const Student& obj) {
		ofs.write((const char*)&obj, sizeof(Student));
	}

	void printStudent(const Student& obj) {
		std::cout << obj.id << " " << obj.name << " " << obj.grade << std::endl;
	}
}

namespace StudentDB
{
	using namespace SchoolNS;

	struct Students {
		Student* students;
		size_t size;
	};
	 
	Students initStudents(size_t size) {
		Students toReturn;
		toReturn.size = size;
		toReturn.students = new Student[toReturn.size];
		return toReturn;
	}

	void selectionSort(Students& students, bool (*compare)(const Student&, const Student&)) {
		if (!compare) return;

		for (size_t i = 0; i < students.size - 1; i++) {
			size_t idx = i;

			for (size_t j = i + 1; j < students.size; j++) {
				if (compare(students.students[j], students.students[idx])) {
					idx = j;
				}
			}

			if (idx != i){
				std::swap(students.students[i], students.students[idx]);
			}
		}
	}

	void sortData(Students& students, Criteria criteria) {
		switch (criteria) {
		case Criteria::SortByName:
			selectionSort(students, [](const Student& lhs, const Student& rhs) -> bool { return strcmp(lhs.name, rhs.name) < 0; });
			break;
		case Criteria::SortByGrade:
			selectionSort(students, [](const Student& lhs, const Student& rhs) -> bool { return lhs.grade < rhs.grade || std::abs(lhs.grade - rhs.grade) <= EPS; });
			break;
		default:
			return;
		}
	}

	void freeStudents(Students& obj) {
		delete[] obj.students;
	}
}

//Exercise 3
size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos);

	return size;
}

namespace ConstantsEx3 {
	constexpr size_t MAX_CLIENT_NAME_SIZE = 50;
	constexpr size_t MAX_PHONE_NUMBER_SIZE = 20;
	constexpr size_t MAX_ADDRESS_SIZE = 100;
}

namespace PizzaNS {
	enum class Type {
		Margarita,
		Capricciosa,
		QuattroStagioni,
		QuattroFormaggi,
		Calzone,
		Burrata,
		Hawaiian,
		Marinara,
		Neapolitan,
		Pepperoni
	};

	enum class Size {
		Small,
		Medium,
		Large
	};

	struct Pizza {
		Type type;
		Size size;
		double price;
	};

	Pizza initPizza(Type type, Size size, double price) {
		Pizza toReturn;
		toReturn.type = type;
		toReturn.size = size;
		toReturn.price = price;
		return toReturn;
	}

	Pizza readPizza(std::ifstream& ifs) {
		Pizza pizza;
		ifs.read((char*)&pizza, sizeof(Pizza));
		return pizza;
	}

	Pizza readPizza(const char* filename) {
		if (!filename) {
			return {};
		}

		std::ifstream ifs(filename, std::ios::in | std::ios::app | std::ios::binary);
		if (!ifs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return {};
		}

		return readPizza(ifs);
	}

	void writePizza(std::ofstream& ofs, const Pizza& pizza) {
		ofs.write((const char*)&pizza, sizeof(Pizza));
	}

	void writePizza(const char* filename, const Pizza& pizza) {
		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::out | std::ios::binary);
		if (!ofs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return;
		}

		return writePizza(ofs, pizza);
	}

	void printPizza(const Pizza& pizza) {
		std::cout << (int)pizza.type << " " << (int)pizza.size << " " << pizza.price << " ";
	}
}

namespace OrderNS {
	using namespace ConstantsEx3;
	using namespace PizzaNS;

	struct Order {
		char clientName[MAX_CLIENT_NAME_SIZE + 1];
		char phoneNumber[MAX_PHONE_NUMBER_SIZE + 1];
		char adress[MAX_ADDRESS_SIZE + 1];
		double totalPrice;
		int pizzasCount;
		Pizza* pizzas;
	};

	Order initOrder(const char* _clientName, const char* _phoneNumber, const char* _adress, double _totalPrice, int _pizzasCount) {
		if (!_clientName || strlen(_clientName) > MAX_CLIENT_NAME_SIZE || !_phoneNumber || strlen(_phoneNumber) > MAX_PHONE_NUMBER_SIZE || !_adress || strlen(_adress) > MAX_ADDRESS_SIZE) {
			return {};
		}

		Order toReturn;

		strcpy(toReturn.clientName, _clientName);
		strcpy(toReturn.phoneNumber, _phoneNumber);
		strcpy(toReturn.adress, _adress);
		toReturn.totalPrice = _totalPrice;
		toReturn.pizzasCount = _pizzasCount;
		toReturn.pizzas = new Pizza[toReturn.pizzasCount];

		return toReturn;
	}

	Order readOrder(std::ifstream& ifs) {
		Order toReturn;
		ifs.read((char*)&toReturn, sizeof(Order));

		if (toReturn.pizzasCount > 0) {
			toReturn.pizzas = new Pizza[toReturn.pizzasCount];
			ifs.read((char*)toReturn.pizzas, sizeof(Pizza) * toReturn.pizzasCount);
		}
		else {
			toReturn.pizzas = nullptr;
		}

		return toReturn;
	}

	Order readOrder(const char* filename) {
		if (!filename) {
			return {};
		}

		std::ifstream ifs(filename, std::ios::in | std::ios::app | std::ios::binary);
		if (!ifs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return {};
		}

		return readOrder(ifs);
	}

	void writeOrder(std::ofstream& ofs, const Order& order) {
		ofs.write((const char*)&order, sizeof(Order));

		if (order.pizzasCount > 0 && order.pizzas) {
			ofs.write((const char*)order.pizzas, sizeof(Pizza) * order.pizzasCount);
		}
	}


	void writeOrder(const char* filename, const Order& order) {
		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return;
		}

		writeOrder(ofs, order);
	}

	void printOrder(const Order& order) {
		std::cout << order.clientName << " " << order.phoneNumber << " " << order.adress << " " << order.totalPrice << " " << order.pizzasCount << std::endl;

		for (size_t i = 0; i < order.pizzasCount; ++i) {
			printPizza(order.pizzas[i]);
		}
	}

	void freeOrder(Order& order) {
		delete[] order.pizzas;
	}
}

namespace PizzeriaOrdersNS {
	using namespace ConstantsEx3;
	using namespace PizzaNS;
	using namespace OrderNS;

	struct PizzeriaOrders {
		Order* orders;
		int count;
	};

	PizzeriaOrders initPizzeriaOrders(int _count) {
		PizzeriaOrders toReturn;
		toReturn.count = _count;
		toReturn.orders = new Order[toReturn.count];
		return toReturn;
	}

	PizzeriaOrders readPizzeriaOrders(std::ifstream& ifs) {
		PizzeriaOrders toReturn;
		
		toReturn.count = getFileSize(ifs) / sizeof(Order);
		toReturn.orders = new Order[toReturn.count];
		for (size_t i = 0; i < toReturn.count; ++i) {
			toReturn.orders[i] = readOrder(ifs);
		}

		ifs.close();
		return toReturn;
	}

	PizzeriaOrders readPizzeriaOrders(const char* filename) {
		if (!filename) {
			return {};
		}

		std::ifstream ifs(filename, std::ios::in | std::ios::app | std::ios::binary);

		if (!ifs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return {};
		}

		return readPizzeriaOrders(ifs);
	}

	void writePizzeriaOrders(std::ofstream& ofs, const PizzeriaOrders& pizzeriaOrders) {
		for (size_t i = 0; i < pizzeriaOrders.count; ++i) {
			writeOrder(ofs, pizzeriaOrders.orders[i]);
		}
		ofs.close();
	}

	void writePizzeriaOrders(const char* filename, const PizzeriaOrders& pizzeriaOrders) {
		if (!filename) {
			return;
		}

		std::ofstream ofs(filename, std::ios::out | std::ios::binary);

		if (!ofs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return;
		}

		return writePizzeriaOrders(ofs, pizzeriaOrders);
	}
	
	void printPizzeriaOrders(const PizzeriaOrders& pizzeriaOrders) {
		std::cout << pizzeriaOrders.count << std::endl;

		for (size_t i = 0; i < pizzeriaOrders.count; ++i) {
			printOrder(pizzeriaOrders.orders[i]);
		}
	}

	void freePizzeriaOrders(PizzeriaOrders& obj) {
		for (size_t i = 0; i < obj.count; ++i) {
			freeOrder(obj.orders[i]);
		}
		delete[] obj.orders;
	}

	void selectionSort(PizzeriaOrders& pizzeriaOrders) {
		for (size_t i = 0; i < pizzeriaOrders.count - 1; ++i) {
			size_t index = i;
			for (size_t j = i + 1; j < pizzeriaOrders.count; ++j) {
				if (strcmp(pizzeriaOrders.orders[j].adress, pizzeriaOrders.orders[index].adress) < 0) {
					index = j;
				}
			}
			if (index != i) {
				std::swap(pizzeriaOrders.orders[i], pizzeriaOrders.orders[index]);
			}
		}
	}

	void sortData(PizzeriaOrders& pizzeriaOrders) {
		selectionSort(pizzeriaOrders);

		std::ifstream ofs("SortedOrders.txt", std::ios::out | std::ios::binary);
		if (!ofs.is_open()) {
			std::cerr << "Couldn't open file!" << std::endl;
			return;
		}

		writePizzeriaOrders("SortedOrders.txt", pizzeriaOrders);
		ofs.close();
	}
}

//Exercise 4
//namespace ConstantsEx4 {
//	constexpr size_t MAX_RECORD_SIZE = 512;
//	constexpr size_t MAX_NEXT_SIZE = 8;
//	constexpr size_t BLOCK_SIZE = 504;
//	const char CENSOR_SIGN[] = "*";
//};
//
//namespace Exercise4 {
//	size_t getFileSizeEx4(std::ifstream& ifs) {
//		size_t currPos = ifs.tellg();
//		ifs.seekg(0, std::ios::end);
//		size_t size = ifs.tellg();
//		ifs.seekg(currPos);
//
//		return size;
//	}
//
//	struct Record {
//		uint64_t next;
//		char data[ConstantsEx4::BLOCK_SIZE];
//	};
//
//	void printRecord(int index, const Record& record, std::ostream& os) {
//		os << index << " " << "next: " << record.next << " " << record.data << std::endl;
//	}
//
//	void print(std::ostream& os, const char* fileName) {
//
//		std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
//
//		if (!ifs.is_open()) {
//			return;
//		}
//
//		int currentIndex = 0;
//
//		while (true) {
//			Record currentRecord;
//
//			ifs.seekg(currentIndex * sizeof(Record), std::ios::beg);
//			ifs.read((char*)&currentRecord, sizeof(Record));
//
//			printRecord(currentIndex, currentRecord, os);
//
//			if (currentRecord.next == 0) {
//				break;
//			}
//
//			currentIndex = currentRecord.next;
//		}
//
//		ifs.close();
//	}
//
//	void censorWordInData(char* db, const char* word) {
//		int wordLen = strlen(word);
//
//		for (size_t i = 0; i < ConstantsEx4::BLOCK_SIZE - wordLen; ++i) {
//			bool wordIsFound = true;
//
//			for (size_t j = 0; j < wordLen; ++j) {
//				if (db[i + j] != word[j]) {
//					wordIsFound = false;
//					break;
//				}
//			}
//
//			if (wordIsFound) {
//				for (size_t j = 0; j < wordLen; ++j) {
//					db[i + j] = ConstantsEx4::CENSOR_SIGN[0];
//				}
//			}
//		}
//	}
//}

int main() {
	//Exercise 1
	/*int size;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	if (!std::cin || size < 0) {
		std::cerr << "Invalid input!" << std::endl;
		return 1;
	}
	int* arr = new int[size];
	std::cout << "Enter the elements of the array: ";
	for (size_t i = 0; i < size; ++i) {
		std::cin >> arr[i];
		if (!std::cin) {
			std::cerr << "Invalid input!" << std::endl;
			return 1;
		}
	}

	char filename[] = "Exercise1.txt";

	writeDynamicArrInFile(arr, size, filename);
	delete[] arr;

	int* arrRes = readDynamicArrFromFile(size, filename);
	if (arrRes == nullptr) {
		return 1;
	}
	for (size_t i = 0; i < size; ++i) {
		std::cout << arrRes[i] << " ";
	}*/

	//Exercise 2
	/*using namespace StudentDB;
	using namespace SchoolNS;
	using namespace Constants;

	int number;
	std::cout << "Enter how many students you want to include: ";
	std::cin >> number;

	if (!std::cin || number <= 0) {
		std::cerr << "Invalid input!" << std::endl;
		return 1;
	}

	Students db = initStudents(number);

	int id;
	char name[MAX_NAME_SIZE + 1];
	double grade;

	for (size_t i = 0; i < number; ++i) {
		std::cout << "Student " << (i + 1) << ": " << std::endl;

		std::cout << "Enter student's id: ";
		std::cin >> id;
		if (!std::cin || id < 0) {
			std::cerr << "Invalid input!" << std::endl;
			freeStudents(db);
			return 1;
		}
		std::cin.ignore();

		std::cout << "Enter student's name: ";
		std::cin.getline(name, MAX_NAME_SIZE + 1);

		std::cout << "Enter student's grade: ";
		std::cin >> grade;
		if (!std::cin || grade < 2 || grade > 6) {
			std::cerr << "Invalid grade!" << std::endl;
			freeStudents(db);
			return 1;
		}

		db.students[i] = initStudent(id, name, grade);
	}

	std::ofstream outFile("Exercise2.txt", std::ios::binary);
	for (size_t i = 0; i < db.size; ++i) {
		writeStudent(outFile, db.students[i]);
	}
	outFile.close();

	std::ifstream inFile("Exercise2.txt", std::ios::binary);
	std::cout << "\nAll students in the binary file before sorting:" << std::endl;
	for (size_t i = 0; i < db.size; ++i) {
		Student temp = readStudent(inFile);
		printStudent(temp);
	}
	inFile.close();

	int sortChoice;
	std::cout << "Choose sorting criteria (0 - Name, 1 - Grade): ";
	std::cin >> sortChoice;

	if (sortChoice == 0) {
		sortData(db, Criteria::SortByName);
	}
	else if (sortChoice == 1) {
		sortData(db, Criteria::SortByGrade);
	}
	else {
		std::cerr << "Invalid sorting choice!" << std::endl;
		freeStudents(db);
		return 1;
	}

	std::cout << "\nSorted students:" << std::endl;
	for (size_t i = 0; i < db.size; ++i) {
		printStudent(db.students[i]);
	}

	freeStudents(db);*/

	//Exercise3
	using namespace PizzeriaOrdersNS;
	PizzeriaOrders pizzeriaOrders = initPizzeriaOrders(3);

	Pizza pizza1 = initPizza(Type::Margarita, Size::Large, 12.5);
	Pizza pizza2 = initPizza(Type::Pepperoni, Size::Medium, 15.0);
	Pizza pizza3 = initPizza(Type::Calzone, Size::Small, 10.0);
	Pizza pizza4 = initPizza(Type::Hawaiian, Size::Large, 13.0);
	Pizza pizza5 = initPizza(Type::QuattroFormaggi, Size::Medium, 14.5);
	Pizza pizza6 = initPizza(Type::Neapolitan, Size::Small, 9.0);

	pizzeriaOrders.orders[0] = initOrder("Maria", "123456789", "C Street", 25.0, 2);
	pizzeriaOrders.orders[0].pizzas[0] = pizza1;
	pizzeriaOrders.orders[0].pizzas[1] = pizza2;

	pizzeriaOrders.orders[1] = initOrder("Valeri", "987654321", "A Street", 30.5, 1);
	pizzeriaOrders.orders[1].pizzas[0] = pizza3;

	pizzeriaOrders.orders[2] = initOrder("Ivana", "555666777", "B Street", 20.0, 3);
	pizzeriaOrders.orders[2].pizzas[0] = pizza4;
	pizzeriaOrders.orders[2].pizzas[1] = pizza5;
	pizzeriaOrders.orders[2].pizzas[2] = pizza6;

	selectionSort(pizzeriaOrders);
	writePizzeriaOrders("Sorted.txt", pizzeriaOrders);

	PizzeriaOrders sortedOrders = readPizzeriaOrders("Sorted.txt");

	std::cout << "Sorted Orders:" << std::endl;;
	printPizzeriaOrders(sortedOrders);

	freePizzeriaOrders(pizzeriaOrders);
	freePizzeriaOrders(sortedOrders);

	//Exericse 4

	return 0;
}
