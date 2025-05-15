#include<iostream>
#include<cstring>

int myStrCmp(const char* str1, const char* str2) {
	while (*str1 && (*str1 == *str2)) {
		++str1;
		++str2;
	}
	return *str1 - *str2;
}

void myStrCpy(char* dest, const char* src) {
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}


//Exercise 1
namespace MatrixNS {
	int** createMatrix(int n, int m) {
		int** matrix = new int* [n];

		for (size_t i = 0; i < n; ++i) {
			matrix[i] = new int[m];
		}

		return matrix;
	}

	void readMatrix(int n, int m, int** matrix) {
		std::cout << "Enter elements in matrix: ";
		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				std::cin >> matrix[i][j];
			}
		}
	}

	void printMatrix(int n, int m, const int* const* matrix) {
		std::cout << "Matrix: " << std::endl;
		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	void deleteMatrix(int n, const int* const* matrix) {
		for (size_t i = 0; i < n; ++i) {
			delete[] matrix[i];
		}

		delete[] matrix;
	}

	int** transposeMatrix(int n, int m, const int* const* matrix) {
		int** transposedMatrix = createMatrix(m, n);

		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				transposedMatrix[j][i] = matrix[i][j];
			}
		}

		return transposedMatrix;
	}

	void swapRowPointers(int** matrix, int row1, int row2) {
		int* temp = matrix[row1];
		matrix[row1] = matrix[row2];
		matrix[row2] = temp;
	}
}

//Exercise 2
namespace ComplexNumbers {
	struct ComplexNumber {
		double realPart, imaginaryPart;
	};

	ComplexNumber complexAddition(const ComplexNumber& first, const ComplexNumber& second) {
		ComplexNumber result;

		result.realPart = first.realPart + second.realPart;
		result.imaginaryPart = first.imaginaryPart + second.imaginaryPart;

		return result;
	}

	ComplexNumber complexSubtraction(const ComplexNumber& first, const ComplexNumber& second) {
		ComplexNumber result;

		result.realPart = first.realPart - second.realPart;
		result.imaginaryPart = first.imaginaryPart - second.imaginaryPart;

		return result;
	}

	ComplexNumber complexMultiplication(const ComplexNumber& first, const ComplexNumber& second) {
		ComplexNumber result;

		result.realPart = first.realPart * second.realPart - first.imaginaryPart * second.imaginaryPart;
		result.imaginaryPart = first.realPart * second.imaginaryPart + first.imaginaryPart * second.realPart;

		return result;
	}

	ComplexNumber complexDivision(const ComplexNumber& first, const ComplexNumber& second) {
		ComplexNumber result;
		double denominator = second.realPart * second.realPart + second.imaginaryPart * second.imaginaryPart;

		if (denominator == 0) {
			result.realPart = result.imaginaryPart = 0;
			return result;
		}

		result.realPart = (first.realPart * second.realPart + first.imaginaryPart * second.imaginaryPart) / (second.realPart * second.realPart + second.imaginaryPart * second.imaginaryPart);
		result.imaginaryPart = (second.realPart * first.imaginaryPart - first.realPart * second.imaginaryPart) / (second.realPart * second.realPart + second.imaginaryPart * second.imaginaryPart);

		return result;
	}

	void printComplexNumber(const ComplexNumber& number) {
		std::cout << number.realPart << " " << (number.imaginaryPart > 0 ? "+ " : "- ") << abs(number.imaginaryPart) << "*i" << std::endl;
	}
}

//Exercise 3
namespace Triangles {
	const double EPSILON = 0.0001;

	struct Triangle {
		double a, b, c;
	};

	double calculateHalfPerimeter(const Triangle& triangle) {
		return (triangle.a + triangle.b + triangle.c) / 2;
	}

	double calculateSurfaceArea(const Triangle& triangle) {
		double hp = calculateHalfPerimeter(triangle);

		return sqrt(hp * (hp - triangle.a) * (hp - triangle.b) * (hp - triangle.c));
	}

	double* createTriangleSurfaceAreasArray(const Triangle* triangles, int n) {
		double* surfaceAreas = new double[n];

		for (size_t i = 0; i < n; ++i) {
			surfaceAreas[i] = calculateSurfaceArea(triangles[i]);
		}

		return surfaceAreas;
	}

	void selectionSort(double* surfaceAreas, int n) {
		double minEl;
		int minIndex;

		for (size_t i = 0; i < n - 1; ++i) {
			minIndex = i;
			minEl = surfaceAreas[minIndex];

			for (size_t j = i + 1; j < n; ++j) {
				if (surfaceAreas[j] < minEl - EPSILON) {
					minIndex = j;
					minEl = surfaceAreas[minIndex];
				}
			}

			surfaceAreas[minIndex] = surfaceAreas[i];
			surfaceAreas[i] = minEl;
		}
	}

	void printAreas(const double* surfaceAreas, int n) {
		for (size_t i = 0; i < n; ++i) {
			std::cout << surfaceAreas[i] << " ";
		}
	}

}

//Exercise 4
namespace School {
	const int FACULTY_NUMBER_MAX_LENGTH = 10;
	const int NAME_MAX_LENGTH = 1000;
	const int MAJOR_MAX_LENGTH = 60;

	enum class Majors { SoftwareEngineering, InformationSystems, ComputerScience, AppliedMathematics, Mathematics, Informatics };

	Majors convertStringToMajor(const char* majorStr) {
		if (myStrCmp(majorStr, "SoftwareEngineering") == 0) {
			return Majors::SoftwareEngineering;
		}
		else if (myStrCmp(majorStr, "InformationSystems") == 0) {
			return Majors::InformationSystems;
		}
		else if (myStrCmp(majorStr, "ComputerScience") == 0) {
			return Majors::ComputerScience;
		}
		else if (myStrCmp(majorStr, "AppliedMathematics") == 0) {
			return Majors::AppliedMathematics;
		}
		else if (myStrCmp(majorStr, "Mathematics") == 0) {
			return Majors::Mathematics;
		}
		else if (myStrCmp(majorStr, "Informatics") == 0) {
			return Majors::Informatics;
		} 
	}

	struct Student {
		double grade;
		char facultyNumber[FACULTY_NUMBER_MAX_LENGTH + 1];
		char name[NAME_MAX_LENGTH + 1];
		Majors major;
	};

	struct Group {
		int studentsCount;
		Student* students;
		double groupAverageGrade;
	};

	Group createGroup() {
		Group group;

		std::cout << "Enter the number of students in the group: ";
		std::cin >> group.studentsCount;
		if (!std::cin || group.studentsCount <= 0) {
			std::cerr << "Invalid input! The number of students must be a positive number!" << std::endl;
			return group;
		}

		group.students = new Student[group.studentsCount];

		double totalGrade = 0.0;

		for (size_t i = 0; i < group.studentsCount; ++i) {
			char majorStr[MAJOR_MAX_LENGTH + 1];
			std::cout << "Enter student " << i + 1 << " (Name, Faculty Number, Major, Grade): ";
			std::cin >> group.students[i].name >> group.students[i].facultyNumber >> majorStr >> group.students[i].grade;

			group.students[i].major = convertStringToMajor(majorStr);

			if (group.students[i].grade < 2.0 || group.students[i].grade > 6.0) {
				std::cerr << "Invalid grade! Must be between 2.0 and 6.0!" << std::endl;
				return group;
			}

			totalGrade += group.students[i].grade;
		}

		group.groupAverageGrade = totalGrade / group.studentsCount;

		return group;
	}

	int countLegibleStudentsForScholarship(const Group& group, double minGrade) {
		int count = 0;

		for (size_t i = 0; i < group.studentsCount; ++i) {
			if (group.students[i].grade >= minGrade) {
				++count;
			}
		}

		return count;
	}

	void selectionSortByGrade(Student* students, int n) {
		for (size_t i = 0; i < n - 1; ++i) {
			int maxIndex = i;
			for (size_t j = i + 1; j < n; ++j) {
				if (students[j].grade > students[maxIndex].grade) {
					maxIndex = j;
				}
			}
			if (maxIndex != i) {
				std::swap(students[i], students[maxIndex]);
			}
		}
	}


	void legibleStudentsForScholarshipSorted(Group& group, double minGrade) {
		if (group.studentsCount <= 0) {
			std::cerr << "Invalid number of students!" << std::endl;
			return;
		}

		selectionSortByGrade(group.students, group.studentsCount);

		bool found = false;
		std::cout << "Students eligible for the scholarship (sorted by grade): " << std::endl;

		for (size_t i = 0; i < group.studentsCount; ++i) {
			if (group.students[i].grade >= minGrade) {
				found = true;
				std::cout << group.students[i].name << " (" << group.students[i].facultyNumber << ") - Grade: " << group.students[i].grade << std::endl;
			}
			else {
				break;
			}
		}

		if (!found) {
			std::cout << "No students qualify for the scholarship!" << std::endl;
		}
	}
}

//Exercise 5
struct Point {
	double x, y;
};

int readPoint(Point& point) {
	std::cout << "Enter the coordinates of your point: ";
	std::cin >> point.x >> point.y;
	if (!std::cin) {
		std::cerr << "Invalid input! The coordinates of the point must be numbers!" << std::endl;
		return 1;
	}
}

void printPoint(const Point& point) {
	std::cout << "Point: (" << point.x << ", " << point.y << ")" << std::endl;
}

double findDistanceFromCenter(const Point& point) {
	return sqrt(pow(point.x, 2) + pow(point.y, 2));
}

double findDistanceBetweenTwoPoints(const Point& first, const Point& second) {
	return sqrt(pow(second.x - first.x, 2) + pow(second.y - first.y, 2));
}

void findQuadrant(const Point& point) {
	if (point.x > 0 && point.y > 0) {
		std::cout << "Quadrant: I" << std::endl;
	}
	else if (point.x < 0 && point.y > 0) {
		std::cout << "Quadrant: II" << std::endl;
	}
	else if (point.x < 0 && point.y < 0) {
		std::cout << "Quadrant: III" << std::endl;
	}
	else {
		std::cout << "Quadrant: IV" << std::endl;
	}
}

void isPointInCircle(double radius, const Point& point) {
	double distance = findDistanceFromCenter(point);

	if (distance < radius) {
		std::cout << "The point is inside the circle!" << std::endl;
	}
	else if (distance == radius) {
		std::cout << "The point is on the circle!" << std::endl;
	}
	else {
		std::cout << "The point is outside the circle!" << std::endl;
	}
}

//Exercise 6
namespace IT {
	const int NAME_EMPLOYEE_MAX_LENGTH = 100;
	const int POSITION_MAX_LENGTH = 100;
	const int MAX_EMPLOYEES = 100;

	enum class Positions{SoftwareEngineer, SeniorSoftwareEngineer, EngineerManager, LeadSoftwareEngineer};

	struct Worker {
		char name[NAME_EMPLOYEE_MAX_LENGTH + 1];
		Positions position;
		double salary;
		int skillLevel;
	};

	Positions convertStringToPosition(const char* positionStr) {
		if (myStrCmp(positionStr, "SoftwareEngineer") == 0) {
			return Positions::SoftwareEngineer;
		}
		else if (myStrCmp(positionStr, "SeniorSoftwareEngineer") == 0) {
			return Positions::SeniorSoftwareEngineer;
		}
		else if (myStrCmp(positionStr, "EngineerManager") == 0) {
			return Positions::EngineerManager;
		}
		else if (myStrCmp(positionStr, "LeadSoftwareEngineer") == 0) {
			return Positions::LeadSoftwareEngineer;
		}
	}

	const char* convertPositionToString(Positions position) {
		switch (position) {
		case Positions::SoftwareEngineer:
			return "SoftwareEngineer";
		case Positions::SeniorSoftwareEngineer:
			return "SeniorSoftwareEngineer";
		case Positions::EngineerManager:
			return "EngineerManager";
		case Positions::LeadSoftwareEngineer:
			return "LeadSoftwareEngineer";
		default:
			return "UnknownPosition";
		}
	}

	Worker createWorker() {
		Worker employee;

		char positionStr[POSITION_MAX_LENGTH + 1];

		std::cout << "Enter worker's name, position, salary and skill level: ";
		std::cin >> employee.name >> positionStr >> employee.salary >> employee.skillLevel;
		if (!std::cin || employee.salary <= 0 || employee.skillLevel < 0) {
			std::cerr << "Invalid input! Salary and skill level must be positive numbers!" << std::endl;
			return employee;
		}

		employee.position = convertStringToPosition(positionStr);

		return employee;
	}

	void printWorkerInfo(const Worker& worker) {
		std::cout << "Employee: " << std::endl;
		std::cout << "Name: " << worker.name << std::endl;
		std::cout << "Position: " << convertPositionToString(worker.position) << std::endl;
		std::cout << "Salary: " << worker.salary << std::endl;
		std::cout << "Skill level: " << worker.skillLevel << std::endl;
		std::cout << std::endl;
	}

	struct ITCompany {
		Worker workers[MAX_EMPLOYEES];
		int numberOfEmployees;
		double averageSalary;
	};

	ITCompany createCompany() {
		ITCompany company;

		std::cout << "Enter the number of employees in the company: ";
		int n;
		std::cin >> n;
		if (!std::cin || n <= 0 || n > MAX_EMPLOYEES) {
			std::cerr << "Invalid input! The number of employees must be a positive number!" << std::endl;
			return company;
		}

		double totalSalary = 0.0;

		for (size_t i = 0; i < n; ++i) {
			company.workers[i] = createWorker();
			totalSalary += company.workers[i].salary;
		}

		company.averageSalary = totalSalary / n;
		company.numberOfEmployees = n;

		return company;
	}


	void selectionSort(char arr[][NAME_EMPLOYEE_MAX_LENGTH + 1], int n) {
		for (int i = 0; i < n - 1; ++i) {
			int minIndex = i;
			for (int j = i + 1; j < n; ++j) {
				if (myStrCmp(arr[j], arr[minIndex]) < 0) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				char temp[NAME_EMPLOYEE_MAX_LENGTH + 1];
				myStrCpy(temp, arr[i]);
				myStrCpy(arr[i], arr[minIndex]);
				myStrCpy(arr[minIndex], temp);
			}
		}
	}

	void printHighSalaryEmployees(const ITCompany& company) {
		std::cout << "Average Salary: " << company.averageSalary << std::endl;

		char highSalaryEmployees[MAX_EMPLOYEES][NAME_EMPLOYEE_MAX_LENGTH + 1];
		int count = 0;

		for (int i = 0; i < company.numberOfEmployees; ++i) {
			if (company.workers[i].salary > company.averageSalary) {
				myStrCpy(highSalaryEmployees[count++], company.workers[i].name);
			}
		}

		selectionSort(highSalaryEmployees, count);

		std::cout << "Employees with salary above average (sorted): " << std::endl;
		for (int i = 0; i < count; ++i) {
			std::cout << highSalaryEmployees[i] << std::endl;
		}
	}

	void printSkillRangePerPosition(const ITCompany& company) {
		int minSkillLevel[4] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX };
		int maxSkillLevel[4] = { INT_MIN, INT_MIN, INT_MIN, INT_MIN };
		bool positionExists[4] = { false, false, false, false };

		for (int i = 0; i < company.numberOfEmployees; ++i) {
			Positions pos = company.workers[i].position;
			int index = -1;

			if (pos == Positions::SoftwareEngineer) {
				index = 0;
			}
			else if (pos == Positions::SeniorSoftwareEngineer) {
				index = 1;
			}
			else if (pos == Positions::EngineerManager) {
				index = 2;
			}
			else if (pos == Positions::LeadSoftwareEngineer) {
				index = 3;
			}

			if (index != -1) {
				positionExists[index] = true;
				if (company.workers[i].skillLevel < minSkillLevel[index]) {
					minSkillLevel[index] = company.workers[i].skillLevel;
				}
				if (company.workers[i].skillLevel > maxSkillLevel[index]) {
					maxSkillLevel[index] = company.workers[i].skillLevel;
				}
			}
		}

		std::cout << "Skill Range Per Position:" << std::endl;
		const char* positionNames[] = { "Software Engineer", "Senior Software Engineer", "Engineer Manager", "Lead Software Engineer" };

		for (int i = 0; i < 4; ++i) {
			if (positionExists[i]) {
				std::cout << positionNames[i] << ": Min Skill Level = " << minSkillLevel[i] << ", Max Skill Level = " << maxSkillLevel[i] << std::endl;
			}
		}
	}
}

//Exercise 7
namespace Graphs {
	const int MAX_LABEL_LENGTH = 10;

	struct Edge {
		char from[MAX_LABEL_LENGTH + 1];
		char to[MAX_LABEL_LENGTH + 1];
	};

	struct Graph {
		Edge* edges;
		int v;
		int e;
	};

	Graph initializeGraph(int edgesCount) {
		Graph g;
		g.e = edgesCount;
		g.edges = new Edge[g.e];
		g.v = 0;

		for (int i = 0; i < g.e; i++) {
			std::cout << "Enter edge " << i + 1 << " (from to): ";
			std::cin >> g.edges[i].from >> g.edges[i].to;
		}

		return g;
	}

	void deleteGraph(Graph& g) {
		delete[] g.edges;
		g.e = 0;
	}

	bool edgeExists(const Graph& g, const char* from, const char* to) {
		for (int i = 0; i < g.e; i++) {
			if (strcmp(g.edges[i].from, from) == 0 && myStrCmp(g.edges[i].to, to) == 0) {
				return true;
			}
		}
		return false;
	}

	void addEdge(Graph& g, const char* from, const char* to) {
		if (edgeExists(g, from, to) || strcmp(from, to) == 0) {
			std::cout << "Invalid edge!" << std::endl;
			return;
		}

		Edge* newEdges = new Edge[g.e + 1];
		for (int i = 0; i < g.e; i++) {
			newEdges[i] = g.edges[i];
		}
		myStrCpy(newEdges[g.e].from, from);
		myStrCpy(newEdges[g.e].to, to);
		delete[] g.edges;
		g.edges = newEdges;
		g.e++;
	}

	void removeEdge(Graph& g, const char* from, const char* to) {
		if (!edgeExists(g, from, to)) {
			std::cout << "Edge does not exist!" << std::endl;
			return;
		}

		Edge* newEdges = new Edge[g.e - 1];
		int index = 0;
		for (int i = 0; i < g.e; i++) {
			if (!(myStrCmp(g.edges[i].from, from) == 0 && myStrCmp(g.edges[i].to, to) == 0)) {
				newEdges[index++] = g.edges[i];
			}
		}
		delete[] g.edges;
		g.edges = newEdges;
		g.e--;
	}

	void calculateDegrees(const Graph& g, const char* vertex, int& inDegree, int& outDegree) {
		inDegree = 0;
		outDegree = 0;
		for (size_t i = 0; i < g.e; i++) {
			if (myStrCmp(g.edges[i].from, vertex) == 0) {
				outDegree++;
			}
			if (myStrCmp(g.edges[i].to, vertex) == 0) {
				inDegree++;
			}
		}
	}

	bool isCompleteGraph(const Graph& g) {
		return g.e == g.v * (g.v - 1);
	}
}

int main() {
	//Exercise 1
	//using namespace MatrixNS;

	//int n, m;

	//std::cout << "Enter number of rows and columns: ";
	//std::cin >> n >> m;
	//if (!std::cin || n < 0 || m < 0) {
	//	std::cerr << "Invalid input! The rows and columns of your matrix must be positive numbers!" << std::endl;
	//	return 1;
	//}

	//int** matrix = createMatrix(n, m);
	//readMatrix(n, m, matrix);
	//printMatrix(n, m, matrix);

	//int** transposedMatrix = transposeMatrix(n, m, matrix);
	//printMatrix(m, n, transposedMatrix);

	//std::cout << "Enter two rows to swap: ";
	//int row1, row2;
	//std::cin >> row1 >> row2;
	//if (!std::cin || row1 < 0 || row1 > n || row2 < 0 || row2 > n) {
	//	std::cerr << "Invalid input! You have entered invalid rows!" << std::endl;
	//	return 1;
	//}
	//swapRowPointers(matrix, row1 - 1, row2 - 1); //rows are 1-indexed
	//printMatrix(n, m, matrix);

	//deleteMatrix(n, matrix);
	//deleteMatrix(m, transposedMatrix);

	//Exercise 2
	/*using namespace ComplexNumbers;

	ComplexNumber first, second;

	std::cout << "Enter real and imaginary part of the first complex number: ";
	std::cin >> first.realPart >> first.imaginaryPart;
	if (!std::cin) {
		std::cerr << "Invalid input!" << std::endl;
		return 1;
	}

	std::cout << "Enter real and imaginary part of the second complex number: ";
	std::cin >> second.realPart >> second.imaginaryPart;
	if (!std::cin) {
		std::cerr << "Invalid input!" << std::endl;
		return 1;
	}

	std::cout << "Addition: ";
	ComplexNumber additionResult = complexAddition(first, second);
	printComplexNumber(additionResult);

	std::cout << "Subtraction: ";
	ComplexNumber subtractionResult = complexSubtraction(first, second);
	printComplexNumber(subtractionResult);

	std::cout << "Multiplication: ";
	ComplexNumber multiplicationResult = complexMultiplication(first, second);
	printComplexNumber(multiplicationResult);

	std::cout << "Division: ";
	ComplexNumber divisionResult = complexDivision(first, second);
	printComplexNumber(divisionResult);*/

	//Exercise 3
	/*using namespace Triangles;
	std::cout << "Enter a number of triangles: ";
	int n;
	std::cin >> n;

	if (!std::cin || n <= 0) {
		std::cerr << "Invalid input! The number of triangles must be a positive number!" << std::endl;
		return 1;
	}

	Triangle* triangles = new Triangle[n];

	for (size_t i = 0; i < n; ++i) {
		std::cout << "Enter the sides of triangle " << i + 1 << ": ";
		std::cin >> triangles[i].a >> triangles[i].b >> triangles[i].c;

		if (!std::cin || triangles[i].a <= 0 || triangles[i].b <= 0 || triangles[i].c <= 0) {
			std::cerr << "Invalid input! The sides of the triangle must be positive numbers!" << std::endl;
			delete[] triangles;
			return 1;
		}
		if (triangles[i].a + triangles[i].b <= triangles[i].c || triangles[i].a + triangles[i].c <= triangles[i].b || triangles[i].b + triangles[i].c <= triangles[i].a) {
			std::cerr << "Invalid input! You have entered an invalid triangle!" << std::endl;
			delete[] triangles;
			return 1;
		}
	}

	double* surfaceAreas = createTriangleSurfaceAreasArray(triangles, n);
	selectionSort(surfaceAreas, n);

	std::cout << "Sorted triangle surface areas: ";
	printAreas(surfaceAreas, n);
	std::cout << std::endl;

	delete[] triangles;
	delete[] surfaceAreas;*/

	//Exercise 4
	/*using namespace School;

	Group group = createGroup();
	if (group.studentsCount == 0) {
		std::cerr << "Group creation failed!" << std::endl;
		return 1;
	}

	std::cout << "Group average grade: " << group.groupAverageGrade << std::endl;

	double minGrade;
	std::cout << "Enter the minimum grade for a scholarship: ";
	std::cin >> minGrade;

	int scholarshipCount = countLegibleStudentsForScholarship(group, minGrade);
	std::cout << "Number of students eligible for a scholarship: " << scholarshipCount << std::endl;

	legibleStudentsForScholarshipSorted(group, minGrade);

	delete[] group.students;*/

	//Exercise 5
    /*Point point1;

	readPoint(point1);
	printPoint(point1);

	std::cout << "Distance from center: " << findDistanceFromCenter(point1) << std::endl;

	Point point2;
	readPoint(point2);
	printPoint(point2);
	std::cout << "Distance between the two points: " << findDistanceBetweenTwoPoints(point1, point2) << std::endl;

	findQuadrant(point1);

	double radius;
	std::cout << "Enter the radius of a circle: ";
	std::cin >> radius;
	if (!std::cin || radius <= 0) {
		std::cerr << "Invalid input! The radius of the circle must be a positive number!" << std::endl;
		return 1;
	}
	isPointInCircle(radius, point1);*/

	//Exercise 6
	/*using namespace IT;
	ITCompany company = createCompany();
	printHighSalaryEmployees(company);
	printSkillRangePerPosition(company);*/

	//Exercise 7
    using namespace Graphs;
	int edgesCount;
	std::cout << "Enter number of edges: ";
	std::cin >> edgesCount;
	if (!std::cin || edgesCount < 0) {
		std::cerr << "Invalid input! The number of edges must be a positive number!" << std::endl;
		return 1;
	}

	Graph g = initializeGraph(edgesCount);

	char v1[MAX_LABEL_LENGTH + 1], v2[MAX_LABEL_LENGTH + 1];
	std::cout << "Enter two vertices to add edge: ";
	std::cin >> v1 >> v2;
	if (!std::cin) {
		std::cerr << "Invalid input! You have entered invalid vertices!" << std::endl;
		return 1;
	}
	addEdge(g, v1, v2);

	std::cout << "Enter vertex to check degrees: ";
	std::cin >> v1;
	if (!std::cin) {
		std::cerr << "Invalid input! You have entered an invalid vertex!" << std::endl;
		return 1;
	}
	int inD, outD;
	calculateDegrees(g, v1, inD, outD);
	std::cout << "In-degree: " << inD << ", Out-degree: " << outD << std::endl;

	std::cout << "Graph is " << (isCompleteGraph(g) ? "complete" : "not complete") << std::endl;

	std::cout << "Enter edge to remove (from to): ";
	std::cin >> v1 >> v2;
	if (!std::cin) {
		std::cerr << "Invalid input! You have entered an invalid edge!" << std::endl;
		return 1;
	}
	removeEdge(g, v1, v2);

	deleteGraph(g);

	return 0;
}